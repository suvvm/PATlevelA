#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];  //��Ŀ�����ĳ�ջ����
stack<int> st;
int main()
{
    int m, n, k;    //ջ����������� �������ݳ��� ����������
    cin >> m >> n >> k;
    while(k--){
        while(!st.empty()){
            st.pop();   //���ջ
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        int current = 1;    //��¼��ջ����λ��
        bool flag = true;
        for(int i = 1; i <= n; i++){
            st.push(i);
            if(st.size() > m){  //�����ʱջ�е�Ԫ�ظ�����������m���зǷ�
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == arr[current]){ //ջ��Ԫ�����ջ���е�ǰλ��Ԫ����ͬʱ��ջ�����ջλ�ú���
                st.pop();
                current++;
            }
        }
        if(st.empty()&& flag == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
