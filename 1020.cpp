#include <bits/stdc++.h>
using namespace std;
typedef int typeData;
const int maxn = 35;
int post[maxn];
int in[maxn];
struct node{
    typeData data;
    int layer;
    node* lchild;
    node* rchild;
};
void LayerOrderBFS(node* root, int n){  //广搜层序遍历
    int num = 0;
    queue<node*> Q;
    root->layer = 1;    //保不保存层号不影响结果
    Q.push(root);   //根结点入队
    while(!Q.empty()){
        node* top = Q.front();
        Q.pop();
        printf("%d", top->data);    //输出根结点权值
        num++;  //记录已经输出过的结点数
        if(num < n) //输出数小于n则输出空格
            printf(" ");
        if(top->lchild != NULL){    //左子树非空
            top->lchild->layer = top->layer + 1;
            Q.push(top->lchild);
        }
        if(top->rchild != NULL){    //右子树非空
            top->rchild->layer = top->layer + 1;
            Q.push(top->rchild);
        }
    }
}
node* create(int postL, int postR, int inL, int inR){   //建树
    if(postL > postR)   //后续遍历长度小于零直接返回
        return NULL;
    node* root = new node;  //创建一个结点保存当前根结点
    root->data = post[postR];   //根结点权值为后续序列的最后一位
    int k;
    for(k = inL; k < inR; k++){
        if(post[postR] == in[k])    //在中序遍历中找到后续遍历中确定的根结点
            break;
    }
    int numLeft = k - inL;  //记录左子树中结点数量
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    //左子树的先序区间为[postL, postL + numLeft - 1], 中序区间为[inL, k-1]
    //返回左子树根结点地址，赋值给root左指针
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    //右子树的先序区间为[postL + numLeft, postR - 1], 中序区间为[k+1, inR]
    //返回右子树根结点地址，赋值给root右指针
    return root;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    LayerOrderBFS(root, n);
    return 0;
}
