#include <bits/stdc++.h>
using namespace std;
map<string,set<int>> title, author, keyWord, publisher, year;
                    //书名  作者    关键词    出版社   出版年份
void query(map<string, set<int>> &mp, string str){
    if(mp.find(str) == mp.end())
        cout << "Not Found" << endl;
    else{
        for(auto it : mp[str]){
            printf("%07d\n", it);//考虑0000000
        }
    }
}
int main()
{
    int n, m, id, type;
    string titleT, authorT, keyWordT, publisherT, yearT;
    cin >> n;
     //书的数目
    for(int i = 0; i < n; i++){
          //输入ID
        //cout << "!!!!!!!!!!!!!!!!! " << i << endl;
        cin >> id;
        //cout << "############ " << id << endl;
        char c = getchar();
        getline(cin, titleT);   //吸收换行读入书名
        //cout << "@@@@@@@@@@@ " << titleT << endl;
        title[titleT].insert(id);   //将ID插入title对应的集合中去
        getline(cin, authorT);     //读入作者
        //cout << "************* " << authorT << endl;
        author[authorT].insert(id); //将ID插入对应作者的集合中去
        while(cin >> keyWordT){ //依次读入每个关键字
            keyWord[keyWordT].insert(id);   //将ID插入每个关键字对应的集合中去
            //cout << "FFFFFFFFFFFFF " << keyWordT << endl;
            c = getchar(); //接受每个关键字后的字符
            if(c == '\n')  //换行为关键字输入结束
                break;
        }
        getline(cin, publisherT);   //读入出版社
        //cout << "gggggggggggggggggg " << publisherT << endl;
        publisher[publisherT].insert(id);   //将ID插入出版社对应的集合中去
        getline(cin, yearT);    //读入出版年份
        //cout << "HHHHHHHHHHHHHHH " << yearT << endl;
        year[yearT].insert(id); //将ID插入年份对应的集合中去
    }
    string temp;
    cin >> m;
    //查询次数
    for(int i = 0; i < m; i++){
        cin >> type;
        getchar();  //吸收:
        getchar();  //吸收空格
        //查询类型
        getline(cin, temp); //查询的关键字
        cout << type << ": " << temp << endl;
        if(type == 1)   //查询书名
            query(title, temp);
        else if(type == 2)  //查询作者
            query(author, temp);
        else if(type == 3)  //查询关键字
            query(keyWord, temp);
        else if(type == 4)  //查询出版社
            query(publisher, temp);
        else    //查询年份
            query(year, temp);
    }
    return 0;
}
