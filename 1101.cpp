#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a < b;
}
int main()
{
    int N, temp;
    vector<int> num, nsort, nans;
    cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%d",&temp);
        num.push_back(temp);
        nsort.push_back(temp);
    }
    sort(nsort.begin(), nsort.end(), cmp);
    int Maxn = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(Maxn < num[i])
            Maxn = num[i];
        if(Maxn == num[i] && num[i] == nsort[i]){
            nans.push_back(num[i]);
            ans++;
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++)
        if(i != 0)
            printf(" %d", nans[i]);
        else
            printf("%d", nans[i]);
    cout << endl;
    return 0;
}
