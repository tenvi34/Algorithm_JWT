#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> array(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    int count = 0;

    for (int k = 0; k < N; k++)
    {
        int goodNum = array[k];
        int start = 0;
        int end = N - 1;

        while (start < end)
        {
            if (start == k)
            {
                start++;
                continue;
            }
            if (end == k)
            {
                end--;
                continue;
            }

            if (array[start] + array[end] < goodNum)
            {
                start++;
            }
            else if (array[start] + array[end] > goodNum)
            {
                end--;
            }
            else
            {
                count++;
                break;
            }
        }
    }

    cout << count << "\n";

    return 0;
}