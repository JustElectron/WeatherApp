#include <memory>

#include "httpclient.h"

HttpClient::HttpClient(const std::string& base_url) {
    RestClient::init(); // Initialize RestClient
    connection_ = new RestClient::Connection(base_url); // Create a connection
    connection_->SetTimeout(10); // Set timeout (optional)
}

HttpClient::~HttpClient() {
    delete connection_; // Clean up the connection
    RestClient::disable(); // Disable RestClient
}

RestClient::Response HttpClient::Get(const std::string& path) {
    return connection_->get(path);
}

RestClient::Response HttpClient::Post(const std::string& path, const std::string& data) {
    return connection_->post(path, data);
}

RestClient::Response HttpClient::Put(const std::string& path, const std::string& data) {
    return connection_->put(path, data);
}

RestClient::Response HttpClient::Delete(const std::string& path) {
    return connection_->del(path);
}