#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // ע�� while ������ case
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
// 64 λ������� printf(\"%lld\")