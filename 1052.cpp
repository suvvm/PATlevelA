#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef int Execlelem;
struct node{    //���徲̬����
    Execlelem data;
    int add;
    int next;
    bool flag = false;  //�жϽ���Ƿ���������
}node_list[maxn];
bool cmp(node a, node b){
    return a.data < b.data;
}
vector<node> v; //������v��װ�������ϵĽ��
int main()
{
    int h1, n;
    cin >> n >> h1; //�����������ͷ�ڵ��ַ
    int tempAdd, tempNext;
    Execlelem tempData;
    if(n == 1){ //ֻ��һ�����
        scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //������
        cout << 1 <<" " << h1 << endl;
        cout << tempAdd << " " <<tempData << " " << -1 << endl;
    }
    else if(n == 0){    //�޽��
       cout << "0 -1" << endl;
    }
    else if(h1 == -1)   //ͷ�ڵ��ַΪ��
      {
        cout<<0<<' '<<-1;
        return 0;
      }
    else{
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //����������
            if(tempAdd < 100000){
                node_list[tempAdd].next = tempNext;
                node_list[tempAdd].data = tempData;
                node_list[tempAdd].add = tempAdd;
            }
        }
        int countn = 0, p = h1;
        while(p != -1){ //ö�������ǽ��ͳ�ƽ������������push������
            node_list[p].flag = true;
            countn++;
            v.push_back(node_list[p]);
            p = node_list[p].next;
        }
        sort(v.begin(), v.end(), cmp);  //�Է���Ҫ��Ľ������
         for(int i = 0; i < countn; i++){   //���Ľ�����ӹ�ϵ
            if(i != countn-1)
                v[i].next = v[i+1].add;
        }
        v[countn-1].next = -1;
        printf("%d %05d\n", countn, v[0].add);
        for(int i = 0; i < countn; i++){
            if(i != countn - 1)
                printf("%05d %d %05d\n", v[i].add, v[i].data, v[i].next);
            else
                printf("%05d %d -1\n", v[i].add, v[i].data);
        }
    }
    return 0;
}
