// EXP 12: URL Splitting Experiment
#include <iostream>
#include <string>
using namespace std;

int main() {
    string url;
    cout << "Enter URL: ";
    getline(cin, url);

    string protocol, domain, path, query;
    size_t pos = 0, found;

    // Find protocol
    found = url.find("://");
    if (found != string::npos) {
        protocol = url.substr(0, found);
        pos = found + 3;  // Move past "://"
    }

    // Find domain
    found = url.find("/", pos);
    if (found != string::npos) {
        domain = url.substr(pos, found - pos);
        pos = found;  // Position to start of path
    } else {
        domain = url.substr(pos);
        pos = url.length();
    }

    // Find path
    found = url.find("?", pos);
    if (found != string::npos) {
        path = url.substr(pos, found - pos);
        pos = found + 1;  // Move past "?"
    } else {
        path = url.substr(pos);
        pos = url.length();
    }

    // Remaining part is query
    query = url.substr(pos);

    // Display the components
    cout << "Protocol: " << (protocol.empty() ? "None" : protocol) << endl;
    cout << "Domain: " << (domain.empty() ? "None" : domain) << endl;
    cout << "Path: " << (path.empty() ? "/" : path) << endl;
    cout << "Query: " << (query.empty() ? "None" : query) << endl;

    return 0;
}


//url: https://www.example.com/path/to/page?search=query
//url: http://example.org/path
