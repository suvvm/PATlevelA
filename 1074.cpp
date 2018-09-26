#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef int Execlelem;
struct node{    //定义静态链表
    Execlelem data;
    int add;
    int next;
}node_list[maxn];
bool cmp(node a, node b){
    return a.data < b.data;
}
vector<node> v; //用容器v来装载链表上的结点
int main()
{
    int h1, n, k;
    cin >> h1 >> n >> k; //出入头节点地址结点个数与步长
    int tempAdd, tempNext;
    Execlelem tempData;
    if(h1 == -1)   //头节点地址为空
      {
        cout<<0<<' '<<-1;
        return 0;
      }
    else if(n == 0){    //无结点
       cout << "0 -1" << endl;
    }
    else if(n == 1){ //只有一个结点
        scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //输入结点
        cout << tempAdd << " " <<tempData << " " << -1 << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //依次输入结点
            node_list[tempAdd].next = tempNext;
            node_list[tempAdd].data = tempData;
            node_list[tempAdd].add = tempAdd;
        }
        int countn = 0, p = h1;
        while(p != -1){ //枚举链表标记结点统计结点个数并将结点push入容器
            countn++;
            v.push_back(node_list[p]);
            p = node_list[p].next;
        }
        n = countn; //为了书写方便用n记录有效节点数
        for(int i = 0; i < n / k; i++){ //枚举能完整走过的段数 段数为n/k段
            for(int j = (i + 1) * k - 1; j > i * k; j--){   //倒序输出第i段
                printf("%05d %d %05d\n", v[j].add, v[j].data, v[j - 1].add);
            }
            //输出每一块的最后一个结点（每一块中面值最小结点）
            printf("%05d %d ", v[i * k].add, v[i * k].data);
            if(i < n / k - 1){  //如果不是最后一块，就指向下一块的最后一个结点
                printf("%05d\n", v[(i + 2) * k - 1].add);
            }else{
                if(n % k == 0){ //如果是最后一块且恰好结束
                    printf("-1\n"); //指向-1
                }else{  //是最后一块但是之后还有结点
                    printf("%05d\n", v[(i + 1) * k].add);   //指向本块结束后的下一结点
                    for(int i = n / k * k; i < n; i++){ //从所有块结束后的第一结点开始顺序输出
                        printf("%05d %d ", v[i].add, v[i].data);
                        if(i < n - 1){
                            printf("%05d\n", v[i + 1].add); //如果不是最后结点，输出下一个结点地址
                        }else{
                            printf("-1\n"); //是尾节点输出-1
                        }
                    }
                }
            }
        }
    }
    return 0;
}
