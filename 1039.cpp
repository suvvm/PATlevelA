#include <bits/stdc++.h>
using namespace std;
const int MaxM = 26 * 26 * 26 * 10 + 10;
vector<int> studentCourse[MaxM];

int getId(string name){
    int id = 0;
    for(int i = 0; i < 3; i++){
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}
int main()
{
    string name;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int course, num;
        cin >> course >> num;
        for(int j = 0;j < num; j++){
            cin >> name;
            int id = getId(name);
            studentCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; i++){
        cin >> name;
        int id = getId(name);
        sort(studentCourse[id].begin(), studentCourse[id].end());
        cout << name << " " << studentCourse[id].size();
        for(int j = 0; j < studentCourse[id].size(); j++){
            cout << " " << studentCourse[id][j];
        }
        cout << endl;
    }
    return 0;
}
