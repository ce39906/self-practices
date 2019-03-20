/*************************************************************************
    > File Name: quadTreeIntersection.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-20 19:38:36
 ************************************************************************/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf && quadTree1->val) return quadTree1;
        if (quadTree2->isLeaf && quadTree2->val) return quadTree2;
        if (quadTree1->isLeaf && !quadTree1->val) return quadTree2;
        if (quadTree2->isLeaf && !quadTree2->val) return quadTree1;

        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (    tl->val == tr->val
             && tr->val == bl->val 
             && bl->val == br->val
             && tl->isLeaf
             && tr->isLeaf
             && bl->isLeaf
             && br->isLeaf)
        {
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        else
        {
            return new Node(false, false, tl, tr, bl, br);
        }
    }
};
