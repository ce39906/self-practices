#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>& nums, int l, int r)
{
    int location = l;
    int privot = nums[l];
    for (int i = l+1; i <= r; i++)
    {
        if(nums[i] < privot)
        {
            swap(nums[++location], nums[i]);
        }
    }
    swap(nums[location],nums[l]);
    return location;
}

void quicksort(vector<int>& nums,int l,int r)
{
    if(l < r)
    {
        int mid = partion(nums, l, r);
        quicksort(nums, l, mid - 1);
        quicksort(nums, mid + 1, r);
    }
}

int main()
{
    int a[] = {1,2,0,5,3,4};
    vector<int> nums(a, a + 5);

    quicksort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] ;
        cout << " ";
    }
    cout << endl;
    
    return 0;
}
