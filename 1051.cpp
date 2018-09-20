#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int arr[maxn];  //题目给定的出栈序列
stack<int> st;
int main()
{
    int m, n, k;    //栈最大数据容量 测试数据长度 测试数据量
    cin >> m >> n >> k;
    while(k--){
        while(!st.empty()){
            st.pop();   //清空栈
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
        int current = 1;    //记录出栈序列位置
        bool flag = true;
        for(int i = 1; i <= n; i++){
            st.push(i);
            if(st.size() > m){  //如果此时栈中的元素个数大于容量m序列非法
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == arr[current]){ //栈顶元素与出栈序列当前位置元素相同时出栈并令出栈位置后移
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
