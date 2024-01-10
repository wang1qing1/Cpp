#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <cstring>

#include </usr/include/jsoncpp/json/json.h>
using namespace std;

int main()
{
    // 待序列化的数据
    string name = "韩信";
    int age = 18;
    vector<int> acore{100, 80, 90};

    // 1.定义json::value 对象
    Json::Value root;
    // 2.将数据放入root中
    root["姓名"] = name;
    root["年龄"] = age;
    for (auto e : acore)
        root["成绩"].append(e);

    // 3.root序列化
    // 使用StreamWriterBuilder,创建StreamWriter
    // 使用StreamWriter的成员方法write实现序列化
    // write方法,第一个参数是Json::Value对象,第二个参数是ostream流对象
    Json::StreamWriterBuilder swb;
    unique_ptr<Json::StreamWriter> streamwrite(swb.newStreamWriter());
    stringstream ssm;
    streamwrite->write(root, &ssm);
    cout << ssm.str() << endl;

    // 1.创建Json::value对象，接受反序列化的信息
    Json::Value mess;
    // 使用CharReaderBuilder创建CharReader
    // 使用CharReader的成员方法parse反序列化
    Json::CharReaderBuilder crb;
    unique_ptr<Json::CharReader> cr(crb.newCharReader());
    string str = ssm.str();
    string error_str;
    cr->parse(str.c_str(), str.c_str() + str.size(), &mess, &error_str);
    cout << "姓名:" << mess["姓名"] << endl;
    cout << "年纪:" << mess["年纪"] << endl;
    cout << "成绩:" << mess["成绩"][0] << "," << mess["成绩"][1] << "," << mess["成绩"][2] << endl;

    return 0;
}