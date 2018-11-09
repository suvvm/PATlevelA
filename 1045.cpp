#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
int favoriteColor[maxn];
int stripeColor[maxn];
int dp[maxn];
int main()
{
    int n,m;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &m);
        memset(favoriteColor, -1, sizeof(favoriteColor));
        for(int i = 0; i < m; i++){
            int color;
            scanf("%d", &color);
            favoriteColor[color] = i;
        }
        int l;
        scanf("%d", &l);
        int num = 0;
        for(int i = 0; i < l; i++){
            int color;
            scanf("%d", &color);
            if(favoriteColor[color] >= 0){
                stripeColor[num++] = favoriteColor[color];
            }
        }
        int ans = -1;
        for(int i = 0; i < num; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(stripeColor[j] <= stripeColor[i] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
