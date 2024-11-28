// 평균 구하기

#include <iostream>
using namespace std;

int main()
{
    int N = 0; // 과목 수
    int A[1000]; // 점수 보관
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long sum = 0; // 과목 모든 점수 합
    long max = 0; // 과목 최댓값

    for (int i = 0; i< N; i++)
    {
        if (max < A[i]) max = A[i]; // 최댓값 찾기
        sum += A[i];
    }

    float result = sum * 100.0f / max / N;

    cout << result << "\n";
}