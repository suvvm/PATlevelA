#include <bits/stdc++.h>
using namespace std;
const int n = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'}; //�Ƶı���뻨ɫ�Ķ�Ӧ��ϵ
int startn[n + 1], endn[n + 1], nextn[n + 1];   //next������ÿ��λ���ϵ����ڲ������λ��
int main()
{
    int k;
    cin >> k;  //ִ�в�����
    for(int i = 1; i <= n; i++){    //��ʼ���Ʊ��
        startn[i] = i;
    }
    for(int i = 1; i <= n; i++){    //����ÿ�����ڲ������λ��
        cin >> nextn[i];
    }
    for(int step = 0; step < k; step++){    //ִ��k�β���
        for(int i = 1; i <= n; i++){
            endn[nextn[i]] = startn[i]; //endnΪ���β�����ɺ����λ
        }
        for(int i = 1; i <= n; i++){
            startn[i] = endn[i];    //��endn����startn
        }
    }
    for(int i = 1; i <= n; i++){
        if(i != 1)
            cout << " ";
        startn[i]--;
        cout << mp[startn[i] / 13] << startn[i] % 13 + 1;
    }
    return 0;
}
