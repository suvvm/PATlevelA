#include <bits/stdc++.h>    //����Ҫ��������·���������������·������
using namespace std;
const int Maxn = 510;
const int INF = 0x7ffffff;
//n������ m���� st ��� ed�յ�
//gΪ�ڽӾ��� weightΪ��Ȩ����Ԯ��������
//d[]��¼��̾��� w[]��¼����Ȩ�ͣ� num[]��¼���·������
int n, m, st, ed, G[Maxn][Maxn], weight[Maxn];
int d[Maxn], w[Maxn], num[Maxn];
bool vis[Maxn] = {false};   //vis[i] == true ��ʾi���Ѿ����� ��ʼ��Ϊfalse
void Dijkstra(int s){
    fill(d, d + Maxn, INF); //����㵽���е�ľ����ȳ�ʼ��Ϊ�����
    memset(num, 0, sizeof(num));    //��㵽���е�����·��ʼ��Ϊ0
    memset(w, 0, sizeof(w));    //��㵽���е������Ȩ�ͳ�ʼ��Ϊ0
    d[s] = 0;   //��㵽�Լ�����̾���Ϊ0
    w[s] = weight[s];   //��㵽�Լ������ȨֵΪ���Ȩֵ
    num[s] = 1; //��㵽�Լ������·������Ϊ1
    for(int i = 0; i < n; i++){ //n��ѭ���������ж���
        int u = -1, Mindu = INF;    //uʹ��du��С Mindu��¼��С��du
        for(int j = 0; j < n; j++){ //Ѱ��δ���ʶ�����d[]��С��
            if(vis[j] == false && d[j] < Mindu){
                u = j;
                Mindu = d[j];
            }
        }
        //���Ҳ���С��INF��d[]˵��ʣ�µĵ�����s����ͨ
        if(u == -1) return; //��������
        vis[u] = true;  //��Ƕ���vΪ�Ѵ�����

        //���vδ���� && u�ܴﵽv && ��uΪ�н�����ʹ��㵽v�����̾������
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){  //���Ը���
                    d[v] = d[u] + G[u][v];  //����uΪ�н����¾��븲�������ľ���
                    w[v] = w[u] + weight[v];    //�µĵ�Ȩֵ���������ĵ�Ȩֵ
                    num[v] = num[u];    //�µ����·��������������������
                }else if(d[u] + G[u][v] == d[v]){   //���������ͬ
                    if(w[u] + weight[v] > w[v]){    //�����uΪ�н����·��Ȩֵ����
                        w[v] = w[u] + weight[v];    //�µ�Ȩֵ���Ǿ�Ȩֵ
                    }
                num[v] += num[u];   //���·������һ
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> st >> ed;
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);    //��¼��Ȩֵ
    }
    int u, v;
    fill(G[0], G[0] + Maxn * Maxn, INF);    //��ʼ������
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    cout << num[ed] << " " <<w[ed] << endl;
    return 0;
}
