#include <bits/stdc++.h>
using namespace std;
int n;  //��Чλ��
string deal(string s, int &e){
    int k = 0;  //��¼s���±�
    while(s.size() > 0 && s[0] == '0')  //ȥ��ǰ��0
        s.erase(s.begin());
    if(s[0] == '.'){    //����λΪ0
        s.erase(s.begin()); //ȥ��С����
        while(s.size() > 0 && s[0] == '0'){
            s.erase(s.begin()); //ȥ��С�����ֱ����һλ��Ч����ǰ��0
            e--;    //ÿȥ��һ��0ָ����һ
        }
    }
    else{   //����λ��Ϊ��
        while(k < s.size() && s[k] != '.'){ //�ҵ������е�С����
            k++;    //��¼С�����±�
            e++;    //С����ǰÿ��һλָ����һ
        }
        if(k < s.size()){   //С�����±�ȳ���С֤����С����
            s.erase(s.begin() + k); //ɾȥС����
        }
    }
    if(s.size() == 0)   //ɾ������������ַ�������Ϊ0֤������Ϊ0
        e = 0;
    int num = 0;
    k = 0;
    string ans;
    while(num < n){ //��Чû�дﵽn
        if(k < s.size())    //�����ǰ�±���ֵ����Ӧֵ���ڴ��ַ�����
            ans += s[k++];
        else
            ans += '0'; //��ǰ�±�û��ֵ�Ͳ�0
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
