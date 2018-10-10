#include <bits/stdc++.h>
using namespace std;
vector<int> ans, temp, fac; //ans为最优底数序列 temp为深搜时的临时序列 fac为p次方小于n的正整数序列
int n, k, p;    //数字n个数k次方数p
int maxFacSum = -1; //maxFacSum记录最大底数和
int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void init(){    //初始化fac序列
    int t = 0, i = 0;
    while(t <= n){  //i的p次方小于n时不断将i的p次方加入fac中
        fac.push_back(t);
        t = power(++i, p);
    }
}
void DFS(int index, int nowK, int sum, int facSum){ //搜索fac[index] 当前选中了nowK个数
    if(nowK == k && sum == n){  //当选择的数的数量达到k 其总和刚好为n时有答案
        if(maxFacSum < facSum){ //比较底数和 如果当前答案底数和更大则更新最大底数和与ans序列
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if(nowK > k || sum > n)  //选择个数或总和越界不返回答案
        return;
    if(index - 1 >= 0){    //fac[0] = 0 不需要选择
        temp.push_back(index);  //把底数index加入临时答案序列temp
        DFS(index, nowK + 1, sum + fac[index], facSum + index);  //选index
        temp.pop_back();    //选择结束后将刚进入的index pop掉
        DFS(index - 1, nowK, sum, facSum); //不选index
    }
}
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    DFS(fac.size() - 1, 0, 0, 0);   //从fac最后一位开始搜索
    if(maxFacSum == -1)
        printf("Impossible\n");
    else{
        printf("%d = ", n);
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
            if(it != ans.begin())
                printf(" + ");
            printf("%d^%d", *it, p);
        }
    }
    return 0;
}
