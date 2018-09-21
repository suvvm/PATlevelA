#include <bits/stdc++.h>    //本题要求输出最短路径条数而不是最短路径距离
using namespace std;
const int Maxn = 510;
const int INF = 0x7ffffff;
//n顶点数 m边数 st 起点 ed终点
//g为邻接矩阵 weight为点权（救援队数量）
//d[]记录最短距离 w[]记录最大点权和， num[]记录最短路径条数
int n, m, st, ed, G[Maxn][Maxn], weight[Maxn];
int d[Maxn], w[Maxn], num[Maxn];
bool vis[Maxn] = {false};   //vis[i] == true 表示i点已经访问 初始化为false
void Dijkstra(int s){
    fill(d, d + Maxn, INF); //将起点到所有点的距离先初始化为无穷大
    memset(num, 0, sizeof(num));    //起点到所有点的最短路初始化为0
    memset(w, 0, sizeof(w));    //起点到所有点的最大点权和初始化为0
    d[s] = 0;   //起点到自己的最短距离为0
    w[s] = weight[s];   //起点到自己的最短权值为起点权值
    num[s] = 1; //起点到自己的最短路径条数为1
    for(int i = 0; i < n; i++){ //n次循环处理所有顶点
        int u = -1, Mindu = INF;    //u使得du最小 Mindu记录最小的du
        for(int j = 0; j < n; j++){ //寻找未访问顶点中d[]最小的
            if(vis[j] == false && d[j] < Mindu){
                u = j;
                Mindu = d[j];
            }
        }
        //若找不到小于INF的d[]说明剩下的点和起点s不连通
        if(u == -1) return; //结束运算
        vis[u] = true;  //标记顶点v为已处理顶点

        //如果v未访问 && u能达到v && 以u为中介点可以使起点到v点的最短距离更优
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){  //可以更优
                    d[v] = d[u] + G[u][v];  //用以u为中介点的新距离覆盖曾经的距离
                    w[v] = w[u] + weight[v];    //新的点权值覆盖曾经的点权值
                    num[v] = num[u];    //新的最短路径条数覆盖曾经的条数
                }else if(d[u] + G[u][v] == d[v]){   //如果长度相同
                    if(w[u] + weight[v] > w[v]){    //如果以u为中介的新路径权值更大
                        w[v] = w[u] + weight[v];    //新的权值覆盖旧权值
                    }
                num[v] += num[u];   //最短路条数加一
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);    //记录点权值
    }
    int u, v;
    fill(G[0], G[0] + Maxn * Maxn, INF);    //初始化矩阵
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    cout << num[ed] << " " <<w[ed] << endl;
    return 0;
}
