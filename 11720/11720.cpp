// 숫자의 합

#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    string nums;
    cin >> N;
    cin >> nums;

    int sum = 0;
    for (int i = 0; i < nums.length(); i++)
    {
        sum += nums[i] -'0';
    }
    
    cout << sum << "\n";
}