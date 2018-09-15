#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int dis[maxn], a[maxn]; //dis为一号结点到达第i号结点的距离u
int main()
{
    int sum = 0, query, n, left, right;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        dis[i] = sum;
    }
    cin >> query;
    for(int i = 0; i < query; i++){
        scanf("%d%d", &left, &right);
        if(left > right)
            swap(left, right);
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n",min(temp,sum - temp));
    }
    return 0;
}
