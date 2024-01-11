#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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
    bool GetContent(std::string *content)
    {
        size_t filelen = GetSize();
        return GetPosLen(content, 0, filelen);
    }
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
        return true;
    }

    ~FileUtil(){};
};
