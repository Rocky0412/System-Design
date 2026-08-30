/*
1. Classic Builder – a nested builder for HttpRequest BuilderPattern
2. Builder with Director – encapsulating common configurations BuilderWithDirector
3. Step Builder – enforcing build steps via interfaces StepBuilder
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

// ======================================================
// Product
// ======================================================

class HttpRequest {

private:
    string url;
    string method;
    map<string, string> headers;
    map<string, string> queryParams;
    string body;
    int timeout;

    // Only Builder can create HttpRequest
    HttpRequest()
        : timeout(30) {}

    friend class HttpRequestBuilder;

public:

    void execute() const {

        cout << "Executing "
             << method
             << " request to "
             << url << endl;

        // Query Parameters
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

        // Headers
        if (!headers.empty()) {

            cout << "Headers:" << endl;

            for (const auto& header : headers) {
                cout << "  "
                     << header.first
                     << ": "
                     << header.second
                     << endl;
            }
        }

        // Body
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

        cout << "-----------------------------"
             << endl;
    }
};


// ======================================================
// Builder
// ======================================================

class HttpRequestBuilder {

private:
    HttpRequest request;

public:

    HttpRequestBuilder& setUrl(const string& url) {

        request.url = url;

        return *this;
    }

    HttpRequestBuilder& setMethod(const string& method) {

        request.method = method;

        return *this;
    }

    HttpRequestBuilder& setHeader(
        const string& key,
        const string& value) {

        request.headers[key] = value;

        return *this;
    }

    HttpRequestBuilder& setQueryParam(
        const string& key,
        const string& value) {

        request.queryParams[key] = value;

        return *this;
    }

    HttpRequestBuilder& setBody(const string& body) {

        request.body = body;

        return *this;
    }

    HttpRequestBuilder& setTimeout(int timeout) {

        request.timeout = timeout;

        return *this;
    }

    HttpRequest build() {

        if (request.url.empty()) {
            throw invalid_argument("URL is required");
        }

        if (request.method.empty()) {
            throw invalid_argument("HTTP method is required");
        }

        return request;
    }
};


// ======================================================
// Director
// ======================================================

class HttpRequestDirector {

public:

    // Predefined GET configuration
    HttpRequest createGoogleGetRequest() {

        HttpRequestBuilder builder;

        return builder
            .setUrl("https://google.com")
            .setMethod("GET")
            .setTimeout(5000)
            .setHeader("Accept", "application/json")
            .build();
    }


    // Predefined POST configuration
    HttpRequest createJsonPostRequest() {

        HttpRequestBuilder builder;

        return builder
            .setUrl("https://api.example.com/users")
            .setMethod("POST")
            .setTimeout(10000)
            .setHeader("Content-Type", "application/json")
            .setHeader("Accept", "application/json")
            .setBody(R"({"name":"Rocky"})")
            .build();
    }
};


// ======================================================
// Client
// ======================================================

int main() {

    HttpRequestDirector director;


    // ------------------------------------------
    // Using Director
    // ------------------------------------------

    HttpRequest googleRequest =
        director.createGoogleGetRequest();

    googleRequest.execute();


    HttpRequest jsonRequest =
        director.createJsonPostRequest();

    jsonRequest.execute();


    // ------------------------------------------
    // Using Builder directly
    // ------------------------------------------

    HttpRequestBuilder builder;

    HttpRequest customRequest = builder
        .setUrl("https://api.example.com/products")
        .setMethod("GET")
        .setQueryParam("page", "1")
        .setQueryParam("limit", "10")
        .setHeader("Accept", "application/json")
        .setTimeout(3000)
        .build();

    customRequest.execute();


    return 0;
}