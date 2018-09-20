#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    vector<char> v;
    LL a, b, c, cnt = 0;
    char temp;
    cin >> a >> b;
    c = a + b;
    if(c < 0){
        cout << "-";
        c = -c;
    }
    if(c == 0)
        cout << 0;
    while(c){

        temp = c % 10 + '0';
        v.push_back(temp);
        c /= 10;
        cnt++;
        if(cnt == 3 && c != 0){
            v.push_back(',');
            cnt = 0;
        }
    }
    reverse(v.begin(), v.end());
    for(auto it : v){
        cout << it;
    }
    return 0;
}
