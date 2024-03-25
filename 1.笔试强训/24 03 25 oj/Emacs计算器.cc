#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        stack<int> st;
        string ch;
        while (n--)
        {
            cin >> ch;
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if (ch == "+")st.push(num1 + num2);
                if (ch == "-")st.push(num2 - num1);
                if (ch == "*")st.push(num1 * num2);
                if (ch == "/")st.push(num2 / num1);
            }
            else
            {
                st.push(atoi(ch.c_str()));
            }
        }
        cout << st.top() << endl;

    }
}
// 64 位输出请用 printf(\"%lld\")