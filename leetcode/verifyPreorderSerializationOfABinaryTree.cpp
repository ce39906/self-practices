/*************************************************************************
    > File Name: verifyPreorderSerializationOfABinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-24 19:34:34
 ************************************************************************/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        stringstream ss(preorder);
        string word;
        while (getline(ss, word, ','))
        {
            degree--;
            if (degree < 0)
            {
                return false;
            }
            
            if (word.front() != '#')
            {
                degree += 2;
            }
        }
        
        return degree == 0;
    }
};
