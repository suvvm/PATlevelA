#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef int Execlelem;
struct node{    //���徲̬����
    Execlelem data;
    int add;
    int next;
}node_list[maxn];
bool cmp(node a, node b){
    return a.data < b.data;
}
vector<node> v; //������v��װ�������ϵĽ��
int main()
{
    int h1, n, k;
    cin >> h1 >> n >> k; //����ͷ�ڵ��ַ�������벽��
    int tempAdd, tempNext;
    Execlelem tempData;
    if(h1 == -1)   //ͷ�ڵ��ַΪ��
      {
        cout<<0<<' '<<-1;
        return 0;
      }
    else if(n == 0){    //�޽��
       cout << "0 -1" << endl;
    }
    else if(n == 1){ //ֻ��һ�����
        scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //������
        cout << tempAdd << " " <<tempData << " " << -1 << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &tempAdd, &tempData, &tempNext);  //����������
            node_list[tempAdd].next = tempNext;
            node_list[tempAdd].data = tempData;
            node_list[tempAdd].add = tempAdd;
        }
        int countn = 0, p = h1;
        while(p != -1){ //ö�������ǽ��ͳ�ƽ������������push������
            countn++;
            v.push_back(node_list[p]);
            p = node_list[p].next;
        }
        n = countn; //Ϊ����д������n��¼��Ч�ڵ���
        for(int i = 0; i < n / k; i++){ //ö���������߹��Ķ��� ����Ϊn/k��
            for(int j = (i + 1) * k - 1; j > i * k; j--){   //���������i��
                printf("%05d %d %05d\n", v[j].add, v[j].data, v[j - 1].add);
            }
            //���ÿһ������һ����㣨ÿһ������ֵ��С��㣩
            printf("%05d %d ", v[i * k].add, v[i * k].data);
            if(i < n / k - 1){  //����������һ�飬��ָ����һ������һ�����
                printf("%05d\n", v[(i + 2) * k - 1].add);
            }else{
                if(n % k == 0){ //��������һ����ǡ�ý���
                    printf("-1\n"); //ָ��-1
                }else{  //�����һ�鵫��֮���н��
                    printf("%05d\n", v[(i + 1) * k].add);   //ָ�򱾿���������һ���
                    for(int i = n / k * k; i < n; i++){ //�����п������ĵ�һ��㿪ʼ˳�����
                        printf("%05d %d ", v[i].add, v[i].data);
                        if(i < n - 1){
                            printf("%05d\n", v[i + 1].add); //�����������㣬�����һ������ַ
                        }else{
                            printf("-1\n"); //��β�ڵ����-1
                        }
                    }
                }
            }
        }
    }
    return 0;
}
