#include <bits/stdc++.h>
using namespace std;
struct node{
    int x, y, z;
    int step;
}Node;
int matrix[1300][140][100]; //记录三维数组
int x, y, z, n;
//记录6个方向
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
bool inq[1300][140][100] = {false};     //记录位置(x,y,z)是否入队过
bool judge(int tx, int ty, int tz){ //判断位置(tx,ty,tz)是否需要访问
    if(tx < 0 || tx >= x || ty < 0 || ty >= y || tz < 0 || tz >= z) //tx,ty,tz没有越界
        return false;
    if(matrix[tx][ty][tz] == 0 || inq[tx][ty][tz] == true)  //位置(tx,ty,tz)为0或已经访问过则该位置不需要访问
        return false;
    return true;
}
int BFS(int tx, int ty, int tz){
    int ans = 0;    //记录当前块中1的数量
    queue<node> Q;
    Node.x = tx;
    Node.y = ty;
    Node.z = tz;
    inq[tx][ty][tz] = true; //位置标记为已访问
    Q.push(Node);   //该位置入队
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        ans++;  //1数量加一
        for(int i = 0; i < 6; i++){ //当前位置可以到达的6个位置
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ)){    //判断新位置（newX,newY,newZ）是否需要访问
                Node.x = newX;
                Node.y = newY;
                Node.z = newZ;
                Q.push(Node);   //设置Node新坐标并入队
                inq[newX][newY][newZ] = true;   //标记当前位置已访问
            }
        }
    }
    return ans;
}
int main()
{
    int ans = 0, tans = 0;
    scanf("%d%d%d%d", &x, &y, &z, &n);
    for(int i = 0; i < z; i++){ //先枚举切片层数
        for(int j = 0; j < x; j++){
            for(int k = 0; k < y; k++)
                scanf("%d", &matrix[j][k][i]);
        }
    }
    for(int i = 0; i < z; i++){
        for(int j = 0; j < x; j++){
            for(int k = 0; k < y; k++){
                if(matrix[j][k][i] == 1 && inq[j][k][i] == false){  //找到没有访问的块
                    tans = BFS(j, k, i);    //获取块中1的数量
                    if(tans >= n)   //超过阈值则记录
                        ans += tans;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
