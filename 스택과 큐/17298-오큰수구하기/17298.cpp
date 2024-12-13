#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N); // 배열 생성
    vector<int> result(N, -1); // 결과 배열

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    stack<int> stack; // 스택 생성
    
    for (int i = 0; i < N; i++)
    {
        // 현재 숫자가 스택의 인덱스에 해당하는 숫자보다 큰 경우
        while(!stack.empty() && A[stack.top()] < A[i])
        {
            result[stack.top()] = A[i]; // 현재 숫자가 오큰수
            stack.pop();
        }
        stack.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << result[i] << " ";
    }
}