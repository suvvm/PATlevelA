#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main()
{
    string v;
    cin >> v;
    int len = v.size();
    int leftP[len + 1] = {0};
    for(int i = 0; i < len; i++){
        if(i > 0)
            leftP[i] = leftP[i - 1];
        if(v[i] == 'P')
            leftP[i]++;
    }
    int ans = 0, rightT = 0;
    for(int i = len - 1; i >= 0; i--){
        if(v[i] == 'T')
            rightT ++;
        else if(v[i] == 'A')
            ans = (ans + rightT * leftP[i]) % mod;
    }
    cout << ans;
    return 0;
}
