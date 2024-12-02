// 배열에서 연속 합이 K인 구간을 찾기

#include <iostream>
#include <vector>
using namespace std;

bool FindSubarrayWithSum(vector<int>& nums, int target)
{
    int left = 0, sum = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right]; // 오른쪽 포인터를 확장하면서 합 계산

        while (sum > target)
        {
            sum -= nums[left]; // 합이 특정 조건을 초과하면 왼쪽 포인터를 줄여서 합 조정
            left++;
        }

        if (sum == target)
        {
            cout << "찾음: [" << left << ", " << right << "]" << endl;
            return true;
        }
    }

    cout << "못 찾음" << endl;
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 7, 5};
    int target = 12;
    FindSubarrayWithSum(nums, target);
    return 0;
}