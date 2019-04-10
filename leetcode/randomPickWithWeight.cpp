/*************************************************************************
    > File Name: randomPickWithWeight.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-10 15:19:51
 ************************************************************************/
class Solution {
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++)
        {
            num_and_idxs.push_back(std::make_pair(w[i], i));
        }
        sort(num_and_idxs.begin(), num_and_idxs.end());
        int milestone = num_and_idxs.begin()->first;
        milestones.push_back(milestone);
        for (int i = 1; i < num_and_idxs.size(); i++)
        {
            milestone += num_and_idxs[i].first;
            milestones.push_back(milestone);
        }
    }
    
    int pickIndex() {
        const int max_milestone = milestones.back();
        int num = rand() % max_milestone;
        int idx = find_first_greater(num);
        return num_and_idxs[idx].second;
    }
private:
    vector<pair<int, int>> num_and_idxs;
    vector<int> milestones;
    
    int find_first_greater(int num) const
    {
        int low = 0;
        int high = milestones.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low >> 1);
            if (milestones[mid] == num)
            {
                return mid + 1;
            }
            else if (milestones[mid] < num)
            {
                low = mid + 1;
            }
            else
            {
                if (mid >= 1 && milestones[mid - 1] <= num)
                {
                    return mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return low;
    }
};
