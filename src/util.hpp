#ifndef _MY_UTIL
#define _MY_UTIL
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iostream>
#include <memory>
#include <experimental/filesystem>          //文件系统库/C++17 or C++14
#include </usr/include/jsoncpp/json/json.h> //Json头文件
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <bundle.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
namespace Cloud
{
    namespace fs = std::experimental::filesystem;
    class FileUtil
    {
    private:
        std::string _filename;

    public:
        FileUtil(const string &filename)
            : _filename(filename)
        {
        }
        // 获取文件大小
        size_t GetSize()
        {
            //
            struct stat filest;
            if (stat(_filename.c_str(), &filest) == -1)
            {
                cout << "errno:" << errno << "," << strerror(errno) << endl;
                return 0;
            }
            return filest.st_size;
        }

        // c  最后一次修改时间
        // a  最后一次访问时间
        time_t LastATime()
        {
            //
            struct stat filest;
            if (stat(_filename.c_str(), &filest) == -1)
            {
                cout << "errno:" << errno << "," << strerror(errno) << endl;
                return 0;
            }
            return filest.st_atime;
        }

        // m  最后一次状态更改的时间
        time_t LastMTime()
        {
            //
            struct stat filest;
            if (stat(_filename.c_str(), &filest) == -1)
            {
                cout << "errno:" << errno << "," << strerror(errno) << endl;
                return 0;
            }
            return filest.st_mtime;
        }

        string FileName()
        {
            size_t pos = _filename.rfind('/');
            if (pos = string::npos)
                return _filename;
            return _filename.substr(pos + 1);
        }
        // 获取文件按指定位置，指定长度的字符串
        bool GetPosLen(std::string *content, size_t pos, size_t len)
        {
            size_t filelen = GetSize();
            if (pos + len > filelen)
            {
                cout << "GetPoslen is too long" << endl;
                return false;
            }
            std::ifstream ifs;
            ifs.open(_filename, std::ios::binary);
            if (!ifs.is_open())
            {
                cout << "open file is faild" << endl;
                ifs.close();
                return false;
            }
            ifs.seekg(pos, std::ios::beg); // 设置读取位置
            content->resize(len);
            ifs.read(&(content->operator[](0)), len);
            if (!ifs.good())
            {
                cout << "read file is faild" << endl;
                ifs.close();
                return false;
            }
            ifs.close();
            return true;
        }
        // 获取全文
        bool GetContent(std::string *content)
        {
            size_t filelen = GetSize();
            return GetPosLen(content, 0, filelen);
        }
        // 向文件中写入数据
        bool SetContent(std::string *content)
        {
            std::ofstream ofs;
            ofs.open(_filename, std::ios::binary);
            if (!ofs.is_open())
            {
                cout << "open file is faild" << endl;
                ofs.close();
                return false;
            }
            ofs.write(content->c_str(), content->size());
            if (!ofs.good())
            {
                cout << "write file is faild" << endl;
                ofs.close();
                return false;
            }
            ofs.close();
            return true;
        }
        // 文件压缩
        bool Compress(const std::string &packname)
        {
            // 1.读取文件
            string body;
            if (GetContent(&body) == false)
            {
                cout << "file GetContent is faild" << endl;
                return false;
            }
            // 2.压缩
            string filepacked = bundle::pack(bundle::LZIP, body);

            // 3.写入压缩包文件
            FileUtil futil(packname);
            futil.SetContent(&filepacked);
            return true;
        }
        // 文件解压缩
        bool UnCompress(const std::string &filename)
        {
            // 1.读取文件
            string body;
            if (GetContent(&body) == false)
            {
                cout << "file GetContent is faild" << endl;
                return false;
            }
            // 2.解压缩
            std::string unfilepacked = bundle::unpack(body);

            // 3.写入压缩包文件
            FileUtil futil(filename);
            futil.SetContent(&unfilepacked);
            return true;
        }

        // 判断文件是否存在
        bool Exists()
        {
            return fs::exists(_filename);
        }
        // 创建目录
        bool CreateDirectory()
        {
            if (Exists())
                return true;
            return fs::create_directories(_filename);
        }
        // 读取目录下的文件
        bool ScanDirectory(std::vector<std::string> *arry)
        {
            // 迭代器遍历目录下的文件
            for (auto &p : fs::directory_iterator(_filename))
            {
                if (!fs::is_directory(p))
                {
                    // relative_path带有文件名的相对路径
                    arry->push_back(fs::path(p).relative_path().string());
                }
            }
            return true;
        }

        ~FileUtil(){};
    };

    class JsonUtil
    {
    public:
        static bool Serialize(const Json::Value &root, std::string *str)
        {
            // 使用StreamWriterBuilder,创建StreamWriter
            // 使用StreamWriter的成员方法write实现序列化
            // write方法,第一个参数是Json::Value对象,第二个参数是ostream流对象
            Json::StreamWriterBuilder swb;
            std::unique_ptr<Json::StreamWriter> streamwrite(swb.newStreamWriter());
            std::stringstream ssm;
            streamwrite->write(root, &ssm);
            *str = ssm.str();
            return true;
        }
        static bool UnSerialize(const std::string &str, Json::Value *root)
        {
            Json::CharReaderBuilder crb;
            std::unique_ptr<Json::CharReader> cr(crb.newCharReader());
            string error_str;
            bool ret = cr->parse(str.c_str(), str.c_str() + str.size(), root, &error_str);
            if (ret == false)
            {
                cout << "Unserialize is faild :" << error_str << endl;
                return false;
            }
            return true;
        }
    };
}
#endif //_MY_UTIL