#include "util.hpp"

int main(int argc, char const *argv[])
{
    FileUtil fileutil(argv[1]);
    cout << fileutil.GetSize() << endl;
    cout << fileutil.FileName() << endl;
    cout << fileutil.LastATime() << endl;
    cout << fileutil.LastMTime() << endl;

    return 0;
}
