#include <bits/stdc++.h>
using namespace std;
vector<set<int> > s1;   //����N�����ϵ�����
void compare(int x, int y){
    int totalnum = s1[y].size();    //����һ��ʼȫ����ͬ������ͬ
    int sameNum = 0;
    for(auto i : s1[x]){
        if(s1[y].find(i) != s1[y].end())    //�������һ�������п����ҵ����Ԫ��
            sameNum++;
        else
            totalnum++;
    }
    printf("%.1f%%\n",sameNum * 100.0 / totalnum);
}
int main()
{
    int n, m, k, v, st1, st2;
    cin >> n;   //��������
    for(int i = 0; i < n; i++){
        scanf("%d", &m);    //����Ԫ������
        set<int> temp;
        for(int j = 0; j < m; j++){
            scanf("%d", &v);    //����Ԫ��
            temp.insert(v); //��Ԫ�ؼ��뼯����
        }
        s1.push_back(temp); //�����ϼ��뼯�ϼ���
    }
    cin >> k;   //k����ѯ
    for(int i = 0; i < k; i++){
        scanf("%d%d",&st1, &st2);   //�����±��Ǵ�0��ʼ���Լ�һ
        compare(st1 - 1, st2 - 1);  //�Ƚ���������
    }
    return 0;
}
