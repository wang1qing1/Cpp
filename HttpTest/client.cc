#include "httplib.h"
const std::string serverip = "118.178.232.144";
const std::uint64_t serverport = 8080;

int main()
{
    httplib::Client cli(serverip, serverport);

    auto res = cli.Get("/hi");
    std::cout << "hi:" << res->status << "->" << res->body << std::endl;

    httplib::MultipartFormData item;
    item.name = "file";
    item.filename = "hello.txt";
    item.content_type = "text/plain";
    item.content = "hello this is a file";
    httplib::MultipartFormDataItems items;
    items.push_back(item);
    auto resmulit = cli.Post("/upload", items);
    std::cout << resmulit->status << std::endl;
    std::cout << resmulit->body << std::endl;

    return 0;
}