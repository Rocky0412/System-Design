#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

using namespace std;

class HttpRequestStepBuilder;

// Forward declarations
class UrlStep;
class MethodStep;
class OptionalStep;


// =======================
// Product
// =======================

class HttpRequest {

private:
    string url;
    string method;
    map<string, string> headers;
    map<string, string> queryParams;
    string body;
    int timeout;

    HttpRequest()
        : timeout(30) {}

public:

    friend class HttpRequestStepBuilder;

    void execute() {

        cout << "Executing "
             << method
             << " request to "
             << url << endl;

        if (!queryParams.empty()) {

            cout << "Query Parameters:" << endl;

            for (const auto& param : queryParams) {
                cout << "  "
                     << param.first
                     << "="
                     << param.second
                     << endl;
            }
        }

        cout << "Headers:" << endl;

        for (const auto& header : headers) {
            cout << "  "
                 << header.first
                 << ": "
                 << header.second
                 << endl;
        }

        if (!body.empty()) {
            cout << "Body: "
                 << body
                 << endl;
        }

        cout << "Timeout: "
             << timeout
             << " seconds"
             << endl;

        cout << "Request executed successfully!"
             << endl;
    }
};


// =======================
// Step 1: URL
// =======================

class UrlStep {

public:

    virtual ~UrlStep() = default;

    virtual MethodStep& withUrl(
        const string& url
    ) = 0;
};


// =======================
// Step 2: METHOD
// =======================

class MethodStep {

public:

    virtual ~MethodStep() = default;

    virtual OptionalStep& withMethod(
        const string& method
    ) = 0;
};


// =======================
// Step 3: OPTIONAL
// =======================

class OptionalStep {

public:

    virtual ~OptionalStep() = default;

    virtual OptionalStep& withHeader(
        const string& key,
        const string& value
    ) = 0;

    virtual OptionalStep& withBody(
        const string& body
    ) = 0;

    virtual OptionalStep& withTimeout(
        int timeout
    ) = 0;

    virtual HttpRequest build() = 0;
};


// =======================
// Concrete Builder
// =======================

class HttpRequestStepBuilder
    : public UrlStep,
      public MethodStep,
      public OptionalStep {

private:

    HttpRequest req;

public:

    // Step 1
    MethodStep& withUrl(
        const string& url
    ) override {

        req.url = url;

        return *this;
    }


    // Step 2
    OptionalStep& withMethod(
        const string& method
    ) override {

        req.method = method;

        return *this;
    }


    // Optional fields
    OptionalStep& withHeader(
        const string& key,
        const string& value
    ) override {

        req.headers[key] = value;

        return *this;
    }


    OptionalStep& withBody(
        const string& body
    ) override {

        req.body = body;

        return *this;
    }


    OptionalStep& withTimeout(
        int timeout
    ) override {

        if (timeout <= 0) {
            throw invalid_argument(
                "Timeout must be greater than 0"
            );
        }

        req.timeout = timeout;

        return *this;
    }


    HttpRequest build() override {

        if (req.url.empty()) {
            throw runtime_error(
                "URL cannot be empty"
            );
        }

        if (req.method.empty()) {
            throw runtime_error(
                "Method cannot be empty"
            );
        }

        return req;
    }
    
    static UrlStep& getBuilder() {
        return *(new HttpRequestStepBuilder());
   }

    // Start building
    /*static HttpRequestStepBuilder getBuilder() {
        return HttpRequestStepBuilder();
    }*/
};


// =======================
// Main
// =======================

int main() {

    HttpRequest request =
        HttpRequestStepBuilder::getBuilder()
            .withUrl("https://example.com")
            .withMethod("POST")
            .withHeader(
                "Content-Type",
                "application/json"
            )
            .withHeader(
                "Authorization",
                "Bearer XYZ"
            )
            .withBody(
                R"({"name":"Rocky"})"
            )
            .withTimeout(10)
            .build();

    request.execute();

    return 0;
}