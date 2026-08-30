#include <iostream>
#include <string>
#include <map>

using namespace std;


/*
Builder Pattern solves the problem of constructing 
complex objects where direct constructors become difficult 
to use because of many parameters, optional parameters, or 
multiple construction steps. It separates object construction from the final 
object and provides a readable and flexible way to create different configurations.

*/

class HttpRequest {

private:
    string method;
    string url;
    map<string, string> headers;
    string body;
    /*
      In the Builder Pattern, the private 
      constructor is mainly used to force clients to 
      create the object through the Builder.
    */
    // Private constructor
    HttpRequest(
        string method,
        string url,
        map<string, string> headers,
        string body
    )
        : method(method),
          url(url),
          headers(headers),
          body(body) {}

public:

    void print() {

        cout << "Method: " << method << endl;
        cout << "URL: " << url << endl;

        cout << "Headers:" << endl;

        for (auto &[key, value] : headers) {
            cout << key << " : " << value << endl;
        }

        cout << "Body: " << body << endl;
    }


    // Nested Builder class
    class Builder {

    private:
        string method;
        string url;
        map<string, string> headers;
        string body;

    public:

        Builder& setMethod(string method) {
            this->method = method;
            return *this;
        }

        Builder& setUrl(string url) {
            this->url = url;
            return *this;
        }

        Builder& addHeader(string key, string value) {
            headers[key] = value;
            return *this;
        }

        Builder& setBody(string body) {
            this->body = body;
            return *this;
        }

        HttpRequest build() {

            return HttpRequest(
                method,
                url,
                headers,
                body
            );
        }
    };
};


int main() {

    HttpRequest request =
        HttpRequest::Builder()
            .setMethod("POST")
            .setUrl("/api/users")
            .addHeader("Content-Type", "application/json")
            .addHeader("Authorization", "Bearer xyz")
            .setBody("{\"name\":\"Rocky\"}")
            .build();

    request.print();

    return 0;
}