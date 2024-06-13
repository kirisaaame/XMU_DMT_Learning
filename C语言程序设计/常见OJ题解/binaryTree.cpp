#include <bits/stdc++.h>
using namespace std;
//节点定义
struct treeNode
{
    int data;
    treeNode* LChild;
    treeNode* RChild;
} TNode,*Tree;
//构造一个带头节点的空二叉链表T
int treeInit()
{
    Tree t;
     = new Tree;
    if (!t) return 0;
    t->Lchild = T->Rchild = nullptr;
    return 1;
}
int main()
{

}