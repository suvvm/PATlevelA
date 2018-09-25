#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef int Execlelem;
struct node{    //定义静态链表
    Execlelem data;
    int add;
    int next;
    bool flag = false;  //判断结点是否在链表上
}node_list[maxn];
bool cmp(node a, node b){
    return a.data < b.data;
}
vector<node> v; //用容器v来装载链表上的结点
int main()
{
    int h1, n;
    cin >> n >> h1; //出入结点个数与头节点地址
    int tempAdd, tempNext;
    Execlelem tempData;
    if(n == 1){ //只有一个结点
        scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //输入结点
        cout << 1 <<" " << h1 << endl;
        cout << tempAdd << " " <<tempData << " " << -1 << endl;
    }
    else if(n == 0){    //无结点
       cout << "0 -1" << endl;
    }
    else if(h1 == -1)   //头节点地址为空
      {
        cout<<0<<' '<<-1;
        return 0;
      }
    else{
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //依次输入结点
            if(tempAdd < 100000){
                node_list[tempAdd].next = tempNext;
                node_list[tempAdd].data = tempData;
                node_list[tempAdd].add = tempAdd;
            }
        }
        int countn = 0, p = h1;
        while(p != -1){ //枚举链表标记结点统计结点个数并将结点push入容器
            node_list[p].flag = true;
            countn++;
            v.push_back(node_list[p]);
            p = node_list[p].next;
        }
        sort(v.begin(), v.end(), cmp);  //对符合要求的结点排序
         for(int i = 0; i < countn; i++){   //更改结点连接关系
            if(i != countn-1)
                v[i].next = v[i+1].add;
        }
        v[countn-1].next = -1;
        printf("%d %05d\n", countn, v[0].add);
        for(int i = 0; i < countn; i++){    //格式化输出
            if(i != countn - 1)
                printf("%05d %d %05d\n", v[i].add, v[i].data, v[i].next);
            else
                printf("%05d %d -1\n", v[i].add, v[i].data);
        }
    }
    return 0;
}
