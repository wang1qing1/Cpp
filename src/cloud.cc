

#include "util.hpp"
#include "config.hpp"
void testfileUtil(int argc, char *argv[])
{
    Cloud::FileUtil fileutil(argv[1]);
    // cout << fileutil.GetSize() << endl;
    // cout << fileutil.FileName() << endl;
    // cout << fileutil.LastATime() << endl;
    // cout << fileutil.LastMTime() << endl;

    // string body;
    // fileutil.GetContent(&body);
    // cout << body << endl;
    // FileUtil fileutil("util.hpp");
    // fileutil.Compress("util.hpp.zip");

    // FileUtil futil("util.hpp.zip");
    // futil.UnCompress("util.hpp_tmp");

    // fileutil.CreateDirectory();
    // vector<string> ArryDir;
    // fileutil.ScanDirectory(&ArryDir);
    // for (auto &e : ArryDir)
    // {
    //     cout << e << endl;
    // }
}

void testJsonUtil()
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

    string rootstr;
    Cloud::JsonUtil::Serialize(root, &rootstr);
    cout << rootstr << endl;

    Json::Value val;
    Cloud::JsonUtil::UnSerialize(rootstr, &val);
    cout << val["姓名"] << endl;
    cout << val["年龄"] << endl;
    cout << val["成绩"][0].asInt() << endl;
    cout << val["成绩"][1].asInt() << endl;
    cout << val["成绩"][2].asInt() << endl;
}
int main(int argc, char *argv[])
{
    // testJsonUtil();
    Cloud::Config *config = Cloud::Config::GetInstance();
    cout << config->GetHotTime() << endl;
    cout << config->GetBackDir() << endl;
    cout << config->GetBackupFile() << endl;
    cout << config->GetDownloadPrefix() << endl;
    cout << config->GetPackDir() << endl;
    cout << config->GetServerIp() << endl;
    cout << config->GetServerPort() << endl;
    return 0;
}
