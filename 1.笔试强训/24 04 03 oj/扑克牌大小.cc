#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string, int> hash;
    string str;
    hash["JOKER"] = 15;
    hash["joker"] = 14;
    hash["2"] = 13;
    hash["A"] = 12;
    hash["K"] = 11;
    hash["Q"] = 10;
    hash["J"] = 9;
    hash["10"] = 8;
    hash["9"] = 7;
    hash["8"] = 6;
    hash["7"] = 5;
    hash["6"] = 4;
    hash["5"] = 3;
    hash["4"] = 2;
    hash["3"] = 1;
    while (getline(cin, str)) { // 注意 while 处理多个 case
        int pos = str.find('-');
        string left(str.begin(), str.begin() + pos);
        string right(str.begin() + pos + 1, str.end());
        int len1 = 0;
        for (auto e : left)if (e == ' ')len1++;
        len1++;
        int len2 = 0;
        for (auto e : right)if (e == ' ')len2++;
        len2++;
        if (left == "joker JOKER" || right == "joker JOKER") {
            cout << "joker JOKER" << endl;
            continue;
        } else if (len1 == len2) {
            int pos = left.find(' ');
            int num1=hash[left.substr(0, pos)];
            pos = right.find(' ');
            int num2=hash[right.substr(0, pos)];
            if (num1 < num2)cout << right << endl;
            else cout << left << endl;
        } else if (len1 == 4)
            cout << left << endl;
        else if (len2 == 4)
            cout << right << endl;
        else cout << "ERROR" << endl;
    }
}
// 64 位输出请用 printf("%lld")