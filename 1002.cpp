#include <bits/stdc++.h>
using namespace std;
map<int, double> m;
int main()
{
    int k, index, cnt = 0;
    double coe;
    cin >> k;
    while(k--){
        cin >> index >> coe;
        m[index] = coe;
    }
    cin >> k;
    while(k--){
        cin >> index >> coe;
        if(m.find(index) == m.end())
            m[index] = coe;
        else
            m[index] += coe;
    }
    for(auto it: m){
        if(it.second != 0.0){
                //cout << it->second <<"**";
            cnt++;
        }

    }
    cout << cnt;
    for(map<int,double>::reverse_iterator it=m.rbegin(); it != m.rend(); it++)
	{
		if(it->second != 0.0){
            printf(" %d %.1f", it->first, it->second);
		}
	}
    cout <<endl;
    return 0;
}
