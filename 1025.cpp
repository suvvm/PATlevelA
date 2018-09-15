#include<bits/stdc++.h>
using namespace std;
struct student{
    long long stdID;
    int score;
    int allrank;
    int locationNumber;
    int locationRank;
};
bool cmp(student a, student b){
    if(a.score != b.score)
        return (a.score > b.score);
    else
        return (a.stdID < b.stdID);
}
int main()
{
    student tempstd;

    long long tempID;
    int tempscore;
    int N, K,num = 1,ans = 0;
    vector<student> v,v1;
    cin >> N;
    for(int j = 1; j <= N; j++){
        int flag = 1;
        cin >> K;
        for(int h = 0; h < K; h++){
            cin >>tempID >> tempscore;
            tempstd.stdID = tempID;
            tempstd.score = tempscore;
            tempstd.locationNumber = j;
            v1.push_back(tempstd);
        }
        sort(v1.begin(),v1.end(),cmp);
        for(int i = 0;i < v1.size(); i++){
            v1[i].locationRank = flag;
            if(v1[i].score == v1[i-1].score)
                v1[i].locationRank = v1[i-1].locationRank;
            v.push_back(v1[i]);
            flag++;
        }
        v1.clear();
        ans += K;
    }
    cout << ans <<endl;
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < v.size(); i++){
        v[i].allrank = num;
        if(v[i].score == v[i-1].score)
            v[i].allrank =  v[i -1].allrank;
        cout << v[i].stdID << " " << v[i].allrank << " " << v[i].locationNumber << " " << v[i].locationRank << " " << v[i].score;
        if(i != v.size() -1)
            cout << endl;
        num++;
    }
    return 0;
}
