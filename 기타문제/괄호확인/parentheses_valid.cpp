#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str)
{
    stack<char> st; // 스택으로 괄호 저장

    for (char c : str)
    {
        // 열린 괄호는 스택에 넣는다.
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        // 짝이 맞지 않거나 스택이 비어있으면 false 반환
        else
        {
            if (c == ')' && st.top() != '(' ||
                c == '}' && st.top() != '{' ||
                c == ']' && st.top() != '[' ||
                st.empty())
            {
                return false;
            }
            // 짝이 맞으면 스택에서 제거
            st.pop();
        }
    }

    // 순회 결과 스택이 비어있으면 true, 아니면 false
    return st.empty();
}

int main()
{
    string str;
    cin >> str;

    if (isValid(str))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}