/*************************************************************************
    > File Name: mergeSortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-26 19:45:56
 ************************************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(nums1);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                nums[k++] = nums1[i++];
            }
            else
            {
                nums[k++] = nums2[j++];
            }
        }
        
        while (i < m)
        {
            nums[k++] = nums1[i++];
        }
        
        while (j < n)
        {
            nums[k++] = nums2[j++];
        }
        
        nums1.swap(nums);
    }
};
