/*************************************************************************
    > File Name: twoSumII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 19:39:54
 ************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(right > left)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            
            if(sum < target)
            {
                int l = left;
                while(l < right && sum < target)
                {
                    sum = numbers[l] + numbers[right];
                    if (sum == target)
                    {
                        return {l + 1, right + 1};
                    }
                    l++;
                }
                if (l > left)
                {
                    left = l - 1;
                }
            }
            else
            {
                int r = right;
                while(left < r && sum > target)
                {
                    sum = numbers[left] + numbers[r];
                    if (sum == target)
                    {
                        return {left + 1, r + 1};
                    }
                    r--;
                }
                if (r < right) 
                {
                    right = r + 1;
                }
            }
        }
        return {left + 1,right + 1};
    }
};
