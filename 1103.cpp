#include <bits/stdc++.h>
using namespace std;
vector<int> ans, temp, fac; //ansΪ���ŵ������� tempΪ����ʱ����ʱ���� facΪp�η�С��n������������
int n, k, p;    //����n����k�η���p
int maxFacSum = -1; //maxFacSum��¼��������
int power(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void init(){    //��ʼ��fac����
    int t = 0, i = 0;
    while(t <= n){  //i��p�η�С��nʱ���Ͻ�i��p�η�����fac��
        fac.push_back(t);
        t = power(++i, p);
    }
}
void DFS(int index, int nowK, int sum, int facSum){ //����fac[index] ��ǰѡ����nowK����
    if(nowK == k && sum == n){  //��ѡ������������ﵽk ���ܺ͸պ�Ϊnʱ�д�
        if(maxFacSum < facSum){ //�Ƚϵ����� �����ǰ�𰸵����͸������������������ans����
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if(nowK > k || sum > n)  //ѡ��������ܺ�Խ�粻���ش�
        return;
    if(index - 1 >= 0){    //fac[0] = 0 ����Ҫѡ��
        temp.push_back(index);  //�ѵ���index������ʱ������temp
        DFS(index, nowK + 1, sum + fac[index], facSum + index);  //ѡindex
        temp.pop_back();    //ѡ������󽫸ս����index pop��
        DFS(index - 1, nowK, sum, facSum); //��ѡindex
    }
}
int main()
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    DFS(fac.size() - 1, 0, 0, 0);   //��fac���һλ��ʼ����
    if(maxFacSum == -1)
        printf("Impossible\n");
    else{
        printf("%d = ", n);
        for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
            if(it != ans.begin())
                printf(" + ");
            printf("%d^%d", *it, p);
        }
    }
    return 0;
}
