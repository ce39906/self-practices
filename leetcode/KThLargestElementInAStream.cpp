/*************************************************************************
    > File Name: KThLargestElementInAStream.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 15:35:10
 ************************************************************************/
class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
       k_ = k;
       for (const int num : nums)
       {
           if (pq_.size() < k)
           {
               pq_.push(num);
           }
           else
           {
               if (pq_.top() < num)
               {
                   pq_.pop();
                   pq_.push(num);
               }
           }
       }
    }
    
    int add(int val) {
        if (pq_.size() < k_)
        {
            pq_.push(val);
            return pq_.top();
        }
        if (pq_.top() < val)
        {
            pq_.pop();
            pq_.push(val);
        }

        return pq_.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq_;
    int k_;
};
