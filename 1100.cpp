#include <bits/stdc++.h>
using namespace std;
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};    //0 - 12 ������
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}; //��λ��0 -12������
string numToStr[170];   //����->������
map<string, int> strToNum;  //������->����

void init(){
    for(int i = 0; i < 13; i++){    //��λ��ʮ��λΪ0�������ģ�
        numToStr[i] = unitDigit[i]; //ʮ��λΪ0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];//��λΪ0
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++){    //ʮ��λ
        for(int j = 1; j < 13; j++){    //��λ
            string str = tenDigit[i] + " " + unitDigit[j];  //��¼������
            numToStr[i * 13 + j] = str; //����->������
            strToNum[str] = i * 13 + j; //������->����
        }
    }
}
int main()
{
    init();
    int T;
    cin >> T;
    getchar();  //���ջس�   ����scanf("%D%*c",&T);��������
    while(T--){
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9'){ //������
            int num = 0;
            for(auto i : str){
                num = num * 10 +(i - '0');  //�������
            }
            cout << numToStr[num] << endl;  //���
        }
        else{
            cout << strToNum[str] << endl;  //���ַ�ֱ�Ӳ��
        }
    }
    return 0;
}
