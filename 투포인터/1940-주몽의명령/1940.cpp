//주몽의 명령(투 포인터)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> array(N,0);

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end()); // 입력받은 수를 정렬

    int count = 0;
    int start = 0;
    int end = N - 1;
    
    while (start < end)
    {
        if (array[start] + array[end] < M)
        {
            start++;
        }
        else if (array[start] + array[end] > M)
        {
            end--;
        }
        else if (array[start] + array[end] == M)
        {
            count++;
            start++;
            end--;
        }
    }

    cout << count << "\n";
}