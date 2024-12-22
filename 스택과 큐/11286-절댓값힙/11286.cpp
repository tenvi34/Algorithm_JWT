#include <iostream>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int o1, int o2)
    {
        int first_abs = abs(o1);
        int secont_abs = abs(o2);

        // 만약 절댓값이 같으면 음수 우선
        if (first_abs == secont_abs)
        {
            return o1 > o2;
        }
        else
        {
            return first_abs > secont_abs;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // 우선순위 큐 선언 방식: <자료형, 구현체, 비교 함수명>
    priority_queue<int, vector<int>, compare> queue;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        // x가 0일 때
        if (x == 0)
        {
            if (queue.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << queue.top() << "\n";
                queue.pop();
            }
        }
        // x가 0이 아닌 숫자일 때
        else
        {
            queue.push(x);
        }
    }
}