#include <bits/stdc++.h>
using namespace std;
bool check(char c){
    if(c >= '0' && c <= '9')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    if(c >= 'a' && c <= 'z')
        return true;
    return false;
}
int main()
{
    map<string, int> countn;
    string str; //str���������ַ���
    getline(cin, str);
    int i = 0;
    while(i < str.length()){
        string word;    //���浥��
        while(i < str.length() && check(str[i]) == true){   //����ַ��Ϸ����ַ�תΪСд�����word
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = tolower(str[i]);
            word += str[i];
            i++;
        }
        if(word != ""){ //���ʷǿմ�����һ
            if(countn.find(word) == countn.end())   //�Ӵ˵��ʵ�һ�γ��ֵ�λ�ÿ�ʼѰ�����һֱ����β��ֻ��һ��
                countn[word] = 1;
            else    //�����¼������
                countn[word]++;
        }
        while(i < str.length() && check(str[i]) == false){  //�����Ƿ��ַ�
            i++;
        }
    }
    string ans;
    int maxn = 0;
    for(auto it : countn){  //������ֵ
        if(it.second > maxn){
            maxn = it.second;
            ans = it.first;
        }
    }
    cout << ans << " " << maxn << endl;
    return 0;
}
