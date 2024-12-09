#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> stack;
    vector<char> operations; // +, - 기호

    int num = 1; // 스택에 넣을 숫자
    for (int i = 0; i < N; i++)
    {
        int targetNum = A[i];

        // 스택에 숫자를 넣는 과정, +로 표시 => Push
        while (num <= targetNum)
        {
            stack.push(num);
            operations.push_back('+');
            num++;
        }

        // 스택에서 숫자를 빼는 과정, -로 표시 => Pop
        if (!stack.empty() && stack.top() == targetNum)
        {
            stack.pop();
            operations.push_back('-');
        }
        else
        {
            cout << "NO" << "\n";
            return 0;
        }
    }

    // 기호 출력
    for (char operation : operations)
    {
        cout << operation << "\n";
    }
}
