#include <bits/stdc++.h>
using namespace std;
typedef char Execlelem;
struct node{    //��̬����
    Execlelem data;
    int next;
    bool flag = false;  //�жϽ���Ƿ��ڵ�һ�������г��ֹ�
}word[100010];

int main()
{
    int h1, h2, n;  //h1,h2Ϊ�������׵�ַnΪ������ĸ��
    cin >> h1 >> h2 >>n;
    int tempAdd, tempNext;
    Execlelem tempData;
    for(int i = 0; i < n; i++){ //��������ÿ�����
        scanf("%d %c %d", &tempAdd, &tempData, &tempNext);
        word[tempAdd].next = tempNext;
        word[tempAdd].data = tempData;
    }
    int p;
    for(p = h1; p != -1; p = word[p].next){ //����һ��������ĸ���Ϊtrue
        word[p].flag = true;
    }
    for(p = h2; p != -1; p = word[p].next){ //�ҵ���һ�����ֵĽ��
        if(word[p].flag == true){
            break;
        }
    }
    if(p != -1)
        printf("%05d\n", p);
    else
        printf("%d\n", p);
    return 0;
}
