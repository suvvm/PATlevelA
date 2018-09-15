#include <bits/stdc++.h>
using namespace std;
map<string,set<int>> title, author, keyWord, publisher, year;
                    //����  ����    �ؼ���    ������   �������
void query(map<string, set<int>> &mp, string str){
    if(mp.find(str) == mp.end())
        cout << "Not Found" << endl;
    else{
        for(auto it : mp[str]){
            printf("%07d\n", it);//����0000000
        }
    }
}
int main()
{
    int n, m, id, type;
    string titleT, authorT, keyWordT, publisherT, yearT;
    cin >> n;
     //�����Ŀ
    for(int i = 0; i < n; i++){
          //����ID
        //cout << "!!!!!!!!!!!!!!!!! " << i << endl;
        cin >> id;
        //cout << "############ " << id << endl;
        char c = getchar();
        getline(cin, titleT);   //���ջ��ж�������
        //cout << "@@@@@@@@@@@ " << titleT << endl;
        title[titleT].insert(id);   //��ID����title��Ӧ�ļ�����ȥ
        getline(cin, authorT);     //��������
        //cout << "************* " << authorT << endl;
        author[authorT].insert(id); //��ID�����Ӧ���ߵļ�����ȥ
        while(cin >> keyWordT){ //���ζ���ÿ���ؼ���
            keyWord[keyWordT].insert(id);   //��ID����ÿ���ؼ��ֶ�Ӧ�ļ�����ȥ
            //cout << "FFFFFFFFFFFFF " << keyWordT << endl;
            c = getchar(); //����ÿ���ؼ��ֺ���ַ�
            if(c == '\n')  //����Ϊ�ؼ����������
                break;
        }
        getline(cin, publisherT);   //���������
        //cout << "gggggggggggggggggg " << publisherT << endl;
        publisher[publisherT].insert(id);   //��ID����������Ӧ�ļ�����ȥ
        getline(cin, yearT);    //����������
        //cout << "HHHHHHHHHHHHHHH " << yearT << endl;
        year[yearT].insert(id); //��ID������ݶ�Ӧ�ļ�����ȥ
    }
    string temp;
    cin >> m;
    //��ѯ����
    for(int i = 0; i < m; i++){
        cin >> type;
        getchar();  //����:
        getchar();  //���տո�
        //��ѯ����
        getline(cin, temp); //��ѯ�Ĺؼ���
        cout << type << ": " << temp << endl;
        if(type == 1)   //��ѯ����
            query(title, temp);
        else if(type == 2)  //��ѯ����
            query(author, temp);
        else if(type == 3)  //��ѯ�ؼ���
            query(keyWord, temp);
        else if(type == 4)  //��ѯ������
            query(publisher, temp);
        else    //��ѯ���
            query(year, temp);
    }
    return 0;
}
