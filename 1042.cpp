#include <bits/stdc++.h>
using namespace std;
const int n = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'}; //牌的编号与花色的对应关系
int startn[n + 1], endn[n + 1], nextn[n + 1];   //next数组存放每个位置上的牌在操作后的位置
int main()
{
    int k;
    cin >> k;  //执行操作数
    for(int i = 1; i <= n; i++){    //初始化牌编号
        startn[i] = i;
    }
    for(int i = 1; i <= n; i++){    //输入每张牌在操作后的位置
        cin >> nextn[i];
    }
    for(int step = 0; step < k; step++){    //执行k次操作
        for(int i = 1; i <= n; i++){
            endn[nextn[i]] = startn[i]; //endn为本次操作完成后的牌位
        }
        for(int i = 1; i <= n; i++){
            startn[i] = endn[i];    //用endn覆盖startn
        }
    }
    for(int i = 1; i <= n; i++){
        if(i != 1)
            cout << " ";
        startn[i]--;
        cout << mp[startn[i] / 13] << startn[i] % 13 + 1;
    }
    return 0;
}
