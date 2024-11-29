// 구간 합 구하기

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // iostream의 동기화 비활성화, 독립 버퍼 사용 -> 수행 속도 증가
    cin.tie(NULL); 
    cout.tie(NULL);

    int noCount, sumCount;
    cin >> noCount >> sumCount;
    int S[100001];

    // 구간 합 구하기
    for (int i = 1; i <= noCount; i++)
    {
        int num;
        cin >> num;
        S[i] = S[i-1] + num;
    }

    // 범위 내에서 구간 합 구하기
    for (int i = 0; i < sumCount; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << "\n";
    }
}