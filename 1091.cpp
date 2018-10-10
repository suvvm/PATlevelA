#include <bits/stdc++.h>
using namespace std;
struct node{
    int x, y, z;
    int step;
}Node;
int matrix[1300][140][100]; //��¼��ά����
int x, y, z, n;
//��¼6������
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};
bool inq[1300][140][100] = {false};     //��¼λ��(x,y,z)�Ƿ���ӹ�
bool judge(int tx, int ty, int tz){ //�ж�λ��(tx,ty,tz)�Ƿ���Ҫ����
    if(tx < 0 || tx >= x || ty < 0 || ty >= y || tz < 0 || tz >= z) //tx,ty,tzû��Խ��
        return false;
    if(matrix[tx][ty][tz] == 0 || inq[tx][ty][tz] == true)  //λ��(tx,ty,tz)Ϊ0���Ѿ����ʹ����λ�ò���Ҫ����
        return false;
    return true;
}
int BFS(int tx, int ty, int tz){
    int ans = 0;    //��¼��ǰ����1������
    queue<node> Q;
    Node.x = tx;
    Node.y = ty;
    Node.z = tz;
    inq[tx][ty][tz] = true; //λ�ñ��Ϊ�ѷ���
    Q.push(Node);   //��λ�����
    while(!Q.empty()){
        node top = Q.front();
        Q.pop();
        ans++;  //1������һ
        for(int i = 0; i < 6; i++){ //��ǰλ�ÿ��Ե����6��λ��
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ)){    //�ж���λ�ã�newX,newY,newZ���Ƿ���Ҫ����
                Node.x = newX;
                Node.y = newY;
                Node.z = newZ;
                Q.push(Node);   //����Node�����겢���
                inq[newX][newY][newZ] = true;   //��ǵ�ǰλ���ѷ���
            }
        }
    }
    return ans;
}
int main()
{
    int ans = 0, tans = 0;
    scanf("%d%d%d%d", &x, &y, &z, &n);
    for(int i = 0; i < z; i++){ //��ö����Ƭ����
        for(int j = 0; j < x; j++){
            for(int k = 0; k < y; k++)
                scanf("%d", &matrix[j][k][i]);
        }
    }
    for(int i = 0; i < z; i++){
        for(int j = 0; j < x; j++){
            for(int k = 0; k < y; k++){
                if(matrix[j][k][i] == 1 && inq[j][k][i] == false){  //�ҵ�û�з��ʵĿ�
                    tans = BFS(j, k, i);    //��ȡ����1������
                    if(tans >= n)   //������ֵ���¼
                        ans += tans;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
