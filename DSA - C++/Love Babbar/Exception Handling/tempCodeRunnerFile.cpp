#include <iostream>
#include <stdexcept>
using namespace std;

class WebServer {
public:
    void processRequest(const std::string& url) {
        if (url == "/bad-request") {
            throw runtime_error("Bad Request: Invalid URL format.");
        } else if (url == "/timeout") {
            throw runtime_error("Network Timeout: Unable to connect.");
        }
    cout << "Processing request for " << url << std::endl;
    }
};

int main() {
    WebServer server;

    try {
        server.processRequest("/bad-request");  // Malformed URL
    } catch (const runtime_error& e) {
        cerr << "Server Error: " << e.what() << std::endl;  // Handling bad request
    }

    try {
        server.processRequest("/timeout");  // Network timeout
    } catch (const runtime_error& e) {
        cerr << "Server Error: " << e.what() << std::endl;  // Handling timeout error
    }

    return 0;
}