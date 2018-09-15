#include <bits/stdc++.h>
using namespace std;
int n;  //有效位数
string deal(string s, int &e){
    int k = 0;  //记录s的下标
    while(s.size() > 0 && s[0] == '0')  //去掉前导0
        s.erase(s.begin());
    if(s[0] == '.'){    //整数位为0
        s.erase(s.begin()); //去掉小数点
        while(s.size() > 0 && s[0] == '0'){
            s.erase(s.begin()); //去掉小数点后直到第一位有效数字前的0
            e--;    //每去掉一个0指数减一
        }
    }
    else{   //整数位不为零
        while(k < s.size() && s[k] != '.'){ //找到整数中的小数点
            k++;    //记录小数点下标
            e++;    //小数点前每有一位指数加一
        }
        if(k < s.size()){   //小数点下标比长度小证明有小数点
            s.erase(s.begin() + k); //删去小数点
        }
    }
    if(s.size() == 0)   //删除结束后如果字符串长度为0证明该数为0
        e = 0;
    int num = 0;
    k = 0;
    string ans;
    while(num < n){ //有效没有达到n
        if(k < s.size())    //如果当前下标有值将对应值加在答案字符串后
            ans += s[k++];
        else
            ans += '0'; //当前下标没有值就补0
        num++;
    }
    return ans;
}
int main()
{
    string s1, s2, rs1, rs2;
    int e1 = 0, e2 = 0;
    cin >> n >> s1 >> s2;
    rs1 = deal(s1, e1);
    rs2 = deal(s2, e2);
    if(rs1 == rs2 && e1 == e2){
        cout << "YES 0." << rs1 << "*10^" << e1 << endl;
    }
    else{
        cout << "NO 0." << rs1 << "*10^" << e1 << " 0." << rs2 << "*10^" << e2 << endl;
    }
    return 0;
}
