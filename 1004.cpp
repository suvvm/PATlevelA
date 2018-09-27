#include <bits/stdc++.h>//本题思路借鉴http://www.cnblogs.com/linkstar/p/5674895.html
using namespace std;
struct node{    //建立树记录每个结点的父节点等级与是否有子节点
    int father = 0;
    int level = 0;
    bool nochild = true;
}tree[100];
int level[101]; //level用来记录每层没有子结点的结点个数
int maxL = 1;   //maxL用来记录最高层
int main()
{
    fill(level, level + 100,0);
    int n, m, id, k, child;
    cin >> n >> m;  //输入总结点数 非叶结点数
    for(int i = 0; i < m; i++){
        cin >> id >> k; //输入非叶结点与其子结点数
        tree[id].nochild = false;   //将该非叶结点标记为有子结点
        for(int j = 0; j < k; j++){
            scanf("%d", &child);    //输入子结点
            tree[child].father = id;    //将其父结点记录为id
        }
    }
    tree[1].level = 1;  //记录根节点层数为1
    //遍历所有结点获取每个结点的层数
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tree[j].father == i){
                tree[j].level = tree[i].level + 1;
                if(tree[j].level > maxL){
                    maxL = tree[j].level;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){    //记录每层没有子结点的结点数
        if(tree[i].nochild == true)
            level[tree[i].level]++;
    }
    for(int i = 1; i < maxL; i++){
        printf("%d ",level[i]);
    }
    printf("%d\n",level[maxL]);
    return 0;
}
