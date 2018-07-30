#include<stdio.h>
#include<iostream>
#include<vector>
#include<sys/time.h>
using namespace std;
void bubble_sort(vector<int>& nums)
{
    struct timeval start, end;
    gettimeofday( &start, NULL );
    int size = nums.size();
    cout << "size:"<<size<<endl;
    for(int i=1;i<size;i++)
    {
        for (int j=size-1;j>=i;j--)
        {
            //cout<<"i:"<<i<<",j:"<<j<<endl;
            if (nums[j]<nums[j-1])
            {
                int tmp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("bubble sort time: %d us\n", timeuse);
}

void quick_bubble_sort(vector<int>& nums)
{
    struct timeval start, end;
    gettimeofday( &start, NULL );
    int size = nums.size();
    bool exange = false;
    for (int i=1;i<size;i++)
    {
        if (!exange && i!=1)
        {
            cout << i <<",exange is false"<<endl;
            gettimeofday( &end, NULL );
            int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
            printf("quick bubble sort time: %d us\n", timeuse);
            return;
        }
        exange = false;
        for (int j=size-1;j>=i;j--)
        {
            //cout<<"i:"<<i<<",j:"<<j<<endl;
            if (nums[j]<nums[j-1])
            {
                exange = true;
                int tmp = nums[j-1];
                nums[j-1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("quick bubble sort time: %d us\n", timeuse);
}
void print(const vector<int>& nums)
{
    for (size_t i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //int a[] = {2,3,1,5,4};
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(8);
    
    vector<int> line = nums;
    vector<int> nums2(nums);
    for (int i = 0;i<1000;i++)
    {
        nums.insert(nums.begin(),line.begin(),line.end());
        nums2.insert(nums2.begin(),line.begin(),line.end());
        
    }
    bubble_sort(nums);
    //print(nums);
    cout<<"quick_bubble_sort"<<endl;
    quick_bubble_sort(nums2);
    //print(nums2);
    return 0;
    
}
