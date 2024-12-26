#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    // 배열에 숫자(first)와 초기 인덱스(second)를 같이 저장해준다.
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    // 배열에 저장된 숫자를 오름차순으로 정렬한다.
    sort(A.begin(), A.end());

    // 정렬되기까지 이동한 횟수 중 최대 이동 횟수
    int Max = 0;

    for (int i = 0; i < N; i++)
    {
        // 이동 거리 계산: 초기 인덱스(A[i].second) - 정렬 후 인덱스(i)
        if (Max < A[i].second - i)
        {
            Max = A[i].second - i; // 최대 이동 거리 갱신
        }
    }

    // 정렬이 완료되기 위한 최소 회전전 수 출력 (최대 이동 거리 + 1)
    cout << Max + 1;
    
}