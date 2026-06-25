#include <bits/stdc++.h>
using namespace std;

typedef char DataType;

//二叉树数据结构 
struct node
{
	DataType info ; //存放结点数据 
	struct node *lchild , *rchild ; //指向左右孩子的指针 
};

typedef struct node *BiTree ;
using np = BiTree;
/*创建二叉树
  函数名：createBiTree
  参数：无
  返回值：二叉树根结点指针
  */
BiTree createBiTree(void)
{
	auto init = [&]() {
        np res = new node;
        res->lchild = res->rchild = nullptr;
        return res;
    };

    np root = init();

    string s;cin >> s;
    s = ' ' + s;
    int n = s.size();

    int idx = 1;
    auto build = [&](np u, auto self) ->void {
        u->info = s[idx];
        idx++;
        if (idx <= n && s[idx] != '#') {
            np& L = u->lchild;
            L = init();
            L->info = s[idx];
            self(L, self);
        }
        idx++;
        if (idx <= n && s[idx] != '#') {
            np& R = u->rchild;
            R = init();
            R->info = s[idx];
            self(R, self);
        }
    };

    build(root, build);
    return root;
}

void visit(BiTree T)
{
	cout<<T->info ;
}

int countLeaf(BiTree root)
{
    //请在此处填写代码， 计算二叉树中树叶的个数
    /********** Begin **********/
    int res = 0;
    if (root->lchild == nullptr && root->rchild == nullptr) return 1;
    if (root->lchild) res += countLeaf(root->lchild);
    if (root->rchild) res += countLeaf(root->rchild);
    return res;
    /********** End **********/
}

int main(void)
{
	BiTree root = createBiTree();
	cout<<countLeaf(root);
}
