#include <restclient-cpp/restclient.h>
#include <restclient-cpp/connection.h>
#include <string>

class HttpClient {
    public:
        // Constructors
        HttpClient(const std::string& base_url);
        ~HttpClient();

        // HTTP methods
        RestClient::Response Get(const std::string& path);
        RestClient::Response Post(const std::string& path, const std::string& data);
        RestClient::Response Put(const std::string& path, const std::string& data);
        RestClient::Response Delete(const std::string& path);

    private:
        RestClient::Connection* connection_; // Connection object for restclient-cpp
};