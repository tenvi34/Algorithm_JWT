#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    string DNA;
    cin >> DNA;

    int minA, minC, minG, minT;
	cin >> minA >> minC >> minG >> minT;

    vector<int> minCount = {minA, minC, minG, minT};
    vector<int> currentCount(4, 0);

    int result = 0;

    for (int i = 0; i < P; i++)
    {
        if (DNA[i] == 'A') currentCount[0]++;
        else if (DNA[i] == 'C') currentCount[1]++;
        else if (DNA[i] == 'G') currentCount[2]++;
        else if (DNA[i] == 'T') currentCount[3]++;
    }

    bool isOk = true;
    for (int i = 0; i < 4; i++)
    {
        // A,C,G,T 가 최소 갯수를 만족하는지 확인
        if (currentCount[i] < minCount[i])
        {
            isOk = false;
            break;
        }
    }

    if (isOk) result++;

    for (int i = P; i < S; i++)
    {
        char leftChar = DNA[i - P];
        if (leftChar == 'A') currentCount[0]--;
        else if (leftChar == 'C') currentCount[1]--;
        else if (leftChar == 'G') currentCount[2]--;
        else if (leftChar == 'T') currentCount[3]--;

        char rightChar = DNA[i];
        if (rightChar == 'A') currentCount[0]++;
        else if (rightChar == 'C') currentCount[1]++;
        else if (rightChar == 'G') currentCount[2]++;
        else if (rightChar == 'T') currentCount[3]++;

        isOk = true;
        for (int j = 0; j < 4; j++)
        {
            if (currentCount[j] < minCount[j])
            {
                isOk = false;
                break;
            }
        }

        if (isOk) result++;
    }

    cout << result << "\n";
}