#include "util.hpp"

int main(int argc, char *argv[])
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

    fileutil.CreateDirectory();
    vector<string> ArryDir;
    fileutil.ScanDirectory(&ArryDir);
    for (auto &e : ArryDir)
    {
        cout << e << endl;
    }
    return 0;
}
