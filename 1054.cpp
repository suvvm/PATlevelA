#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int temp,ans,flag = 0;
    for(int i = 0; i < m * n; i++){
        scanf("%d", &temp);
        if(flag == 0){
            ans = temp;
            flag++;
        }
        else if(temp == ans){
            flag++;
        }
        else
            flag--;
    }
    cout << ans;
    return 0;
}
