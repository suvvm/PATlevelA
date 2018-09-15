#include <bits/stdc++.h>
using namespace std;
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};    //0 - 12 火星文
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; //进位后0 -12火星文
string numToStr[170];   //数字->火星文
map<string, int> strToNum;  //火星文->数字

void init(){
    for(int i = 0; i < 13; i++){    //个位或十三位为0（火星文）
        numToStr[i] = unitDigit[i]; //十三位为0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];//个位为0
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++){    //十三位
        for(int j = 1; j < 13; j++){    //个位
            string str = tenDigit[i] + " " + unitDigit[j];  //记录火星文
            numToStr[i * 13 + j] = str; //数字->火星文
            strToNum[str] = i * 13 + j; //火星文->数字
        }
    }
}
int main()
{
    init();
    int T;
    cin >> T;
    getchar();  //吸收回车   可用scanf("%D%*c",&T);代替两句
    while(T--){
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9'){ //是数字
            int num = 0;
            for(auto i : str){
                num = num * 10 +(i - '0');  //获得数字
            }
            cout << numToStr[num] << endl;  //查表
        }
        else{
            cout << strToNum[str] << endl;  //是字符直接查表
        }
    }
    return 0;
}
