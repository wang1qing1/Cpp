#include <iostream>
#include <string>
#include <fstream>
#include "bundle.h"

using namespace std;
int main(int argc, char *argv[])
{
    cout << "源文件名：" << argv[1] << endl;
    cout << "压缩包名称：" << argv[2] << endl;
    string filename = argv[1];
    string zipname = argv[2];

    // 1.打开文件
    ifstream fs;
    fs.open(filename, ios::binary); // 1.1 二进制方式打开

    // 2.获取文件大小,单位：字节
    fs.seekg(0, ios::end);       // 2.1将文件读写位置调整到文件末尾
    size_t filelen = fs.tellg(); // 2.2获取文件末尾的偏移量,即文件长度
    fs.seekg(0, std::ios::beg);  // 2.3跳转到文件起始

    cout << "文件长度:" << filelen << endl;
    // 3.读取文件内容存储到string中
    string filestr;                // 3.1用来存储文件内容
    filestr.resize(filelen);       // 3.2调整string的空间
    fs.read(&filestr[0], filelen); // 3.3读取文件内容存储到filestr中
    // 4.使用bundle::pack()压缩文件,压缩方式:LZIP
    string file_packed_str = bundle::pack(bundle::LZIP, filestr);
    cout << "压缩文件长度：" << file_packed_str.size() << endl;
    // 5.将压缩好的文件字符串写入压缩包文件
    ofstream zipfs;
    zipfs.open(zipname, ios::binary);
    zipfs.write(file_packed_str.c_str(), file_packed_str.size());

    fs.close();
    zipfs.close();
    return 0;
}
