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
    string str; //str储存整个字符串
    getline(cin, str);
    int i = 0;
    while(i < str.length()){
        string word;    //储存单词
        while(i < str.length() && check(str[i]) == true){   //如果字符合法将字符转为小写添加至word
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = tolower(str[i]);
            word += str[i];
            i++;
        }
        if(word != ""){ //单词非空次数加一
            if(countn.find(word) == countn.end())   //从此单词第一次出现的位置开始寻找如果一直到结尾则只有一个
                countn[word] = 1;
            else    //否则记录出现数
                countn[word]++;
        }
        while(i < str.length() && check(str[i]) == false){  //跳过非法字符
            i++;
        }
    }
    string ans;
    int maxn = 0;
    for(auto it : countn){  //输出最大值
        if(it.second > maxn){
            maxn = it.second;
            ans = it.first;
        }
    }
    cout << ans << " " << maxn << endl;
    return 0;
}
