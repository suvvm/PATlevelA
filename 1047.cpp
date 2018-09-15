/*#include <bits/stdc++.h>
using namespace std;
const int MaxM = 2510;
vector<string> CourseStudent[MaxM];

int main()
{
    string name;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
            int num;
            cin >> name >> num;
            for(int j = 0; j < num; j++){
                int id;
                cin >> id;
                CourseStudent[id].push_back(name);
            }
        }
    for(int i = 1; i < k + 1; i++){
        sort(CourseStudent[i].begin(),CourseStudent[i].end());
        cout << i << " " << CourseStudent[i].size() << endl;
        for(auto j : CourseStudent[i])
            cout << j << endl;
    }
    return 0;
}*/
//最后节点超时
#include <bits/stdc++.h>    //偷鸡过了
#include<cstring>
using namespace std;
const int MaxM = 2510;
vector<string> CourseStudent[MaxM];
int main()
{
    string name;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
            int num;
            cin >> name >> num;
            for(int j = 0; j < num; j++){
                int id;
                scanf("%d", &id);
                CourseStudent[id].push_back(name);
            }
        }
    for(int i = 1; i < k + 1; i++){
        sort(CourseStudent[i].begin(),CourseStudent[i].end());
        printf("%d %d\n", i, CourseStudent[i].size());
        for(int j = 0; j < CourseStudent[i].size(); j++){
            printf("%s\n",CourseStudent[i][j].c_str());
        }

    }
    return 0;
}
