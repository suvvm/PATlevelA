#include<bits/stdc++.h>
using namespace std;
struct student{
    char id[15];
    int score;
    int loactaionNumber;
    int localRank;
}stu[30005];
bool cmp(student a, student b){
    if(a.score != b.score)
        return a.score > b. score;
    else
        return strcmp(a.id,b.id) < 0;
}
int main(){
    int n, k, num = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            scanf("%s %d",&stu[num].id,&stu[num].score);
            stu[num].loactaionNumber = i;
            num++;
        }
        sort(stu + num - k, stu + num, cmp);
        stu[num - k].localRank = 1 ;
        for(int j = num - k + 1; j < num; j++){
            if(stu[j].score == stu[j -1].score)
                stu[j].localRank = stu[j - 1].localRank;
            else
                stu[j].localRank = j + 1 - (num - k);
        }
    }
    printf("%d\n", num);
    sort(stu,stu + num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++){
        if(i > 0 && stu[i].score != stu[i - 1].score)
            r = i + 1;
        printf("%s ",stu[i].id);
        printf("%d %d %d\n", r, stu[i].loactaionNumber,stu[i].localRank);
    }
    return 0;
}
