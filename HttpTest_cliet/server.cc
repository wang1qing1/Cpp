#include <iostream>
#include <string>
#include <vector>
#include "httplib.h"

void Hello(const httplib::Request &requ, httplib::Response &resp)
{
    std::string local_ip = requ.local_addr;
    int local_port = requ.local_port;
    std::string body = "hello,Welcome to ->" + local_ip + " ::" + std::to_string(local_port);
    resp.set_content(body, "text/plain");
    resp.status = 200;
}

void Number(const httplib::Request &requ, httplib::Response &resp)
{
    auto numbers = requ.matches[1];
    resp.set_content(numbers, "text/plain");
    resp.status = 200;
}

void Postfile(const httplib::Request &req, httplib::Response &res)
{
    bool ret = req.has_file("file");
    if (!ret)
    {
        res.set_content("no this file", "text/plain");
        res.status = 404;
        return;
    }
    const auto &file = req.get_file_value("file");
    std::cout << file.filename << std::endl;
    std::cout << file.content_type << std::endl;
    std::cout << file.content << std::endl;
    res.status = 200;
    res.set_content("this file name is :" + file.filename, "text/plain");
}
int main()
{
    httplib::Server server;
    server.Get("/hi", Hello);
    // R"()"包含的字符串不再转义
    server.Get(R"(/numbers/(\d+))", Number);
    server.Post("/upload", Postfile);
    server.listen("0.0.0.0", 8080);

    return 0;
}