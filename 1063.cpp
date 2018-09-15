#include <bits/stdc++.h>
using namespace std;
vector<set<int> > s1;   //储存N个集合的容器
void compare(int x, int y){
    int totalnum = s1[y].size();    //假设一开始全部不同，无相同
    int sameNum = 0;
    for(auto i : s1[x]){
        if(s1[y].find(i) != s1[y].end())    //如果在另一个集合中可以找到这个元素
            sameNum++;
        else
            totalnum++;
    }
    printf("%.1f%%\n",sameNum * 100.0 / totalnum);
}
int main()
{
    int n, m, k, v, st1, st2;
    cin >> n;   //集合数量
    for(int i = 0; i < n; i++){
        scanf("%d", &m);    //集合元素数量
        set<int> temp;
        for(int j = 0; j < m; j++){
            scanf("%d", &v);    //输入元素
            temp.insert(v); //将元素加入集合中
        }
        s1.push_back(temp); //将集合加入集合集中
    }
    cin >> k;   //k个查询
    for(int i = 0; i < k; i++){
        scanf("%d%d",&st1, &st2);   //容器下标是从0开始所以减一
        compare(st1 - 1, st2 - 1);  //比较两个集合
    }
    return 0;
}
