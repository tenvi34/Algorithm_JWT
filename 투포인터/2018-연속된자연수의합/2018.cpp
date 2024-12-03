// 연속된 자연수의 합 구하기

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 목표 숫자
    cin >> N;
    int count = 1;
    int start_idx = 1;
    int end_idx = 1;
    int sum = 1;

    while (end_idx != N)
    {
        if (sum == N)
        {
            count++;
            end_idx++;
            sum += end_idx;
        }
        else if (sum > N)
        {
            sum -= start_idx;
            start_idx++;
        }
        else if (sum < N)
        {
            end_idx++;
            sum += end_idx;
        }
    }

    cout << count << "\n";
    
}