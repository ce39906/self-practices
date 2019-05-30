/*************************************************************************
    > File Name: distantBarcodes.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-28 16:09:51
 ************************************************************************/
struct Barcode
{
    Barcode(int code, int freq) : code(code), freq(freq)
    {
    }

    int code;
    int freq;
};

struct Cmp
{
    bool operator()(const Barcode& lhs, const Barcode& rhs)
    {
        return lhs.freq < rhs.freq;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> code_freqs;
        for (const int barcode : barcodes)
        {
            code_freqs[barcode]++;
        }
        priority_queue<Barcode, vector<Barcode>, Cmp> pq;
        // init pq
        for (auto cit = code_freqs.cbegin(); cit != code_freqs.cend(); ++cit)
        {
            pq.emplace(cit->first, cit->second);
        }

        vector<int> res;
        while (!pq.empty())
        {
            Barcode first = pq.top();
            pq.pop();
            if (res.empty() || res.back() != first.code)
            {
                res.push_back(first.code);
                first.freq--;
                if (first.freq)
                {
                    pq.push(first);
                }
            }
            else
            {
                Barcode second = pq.top();
                pq.pop();
                res.push_back(second.code);
                second.freq--;
                if (second.freq)
                {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return res;
    }
};
