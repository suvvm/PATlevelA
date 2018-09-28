#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string id, time1, time2, in, out;
    string maxout = "00:00:00";
    string minin = "24:00:00";
    for(int i = 0; i < n; i++){
        cin >> id >> time1 >> time2;
        if(time1 < minin){
            minin = time1;
            in = id;
        }
        if(time2 > maxout){
            maxout = time2;
            out = id;
        }
    }
    cout << in << " " <<out;
    return 0;
}
