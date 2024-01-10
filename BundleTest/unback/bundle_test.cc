#include <iostream>
#include <string>
#include <fstream>
#include "bundle.h"

using namespace std;
int main(int argc, char *argv[])
{
    string zipname = argv[1];
    string unzipname = argv[2];
    cout << "带解压的文件:" << argv[1] << endl;
    cout << "解压后的文件:" << argv[2] << endl;

    ifstream ifs;
    // 1.打开文件
    ifs.open(zipname, ios::binary);
    // 2.计算文件大小
    ifs.seekg(0, ios::end);
    size_t filelen = ifs.tellg();
    ifs.seekg(0, ios::beg);

    // 3.将压缩文件读取到内存string中
    string filestr;
    filestr.resize(filelen);
    ifs.read(&filestr[0], filelen);
    ifs.close();

    // 4.使用bundle::unpack解压
    string unpackedstr = bundle::unpack(filestr);

    // 4.打开解压后的文件,将filestr写入unzipname
    ofstream ofs;
    ofs.open(unzipname, ios::binary);
    ofs.write(unpackedstr.c_str(), unpackedstr.size());
    ofs.close();

    return 0;
}
