#include <bits/stdc++.h>
using namespace std;
typedef char Execlelem;
struct node{    //静态链表
    Execlelem data;
    int next;
    bool flag = false;  //判断结点是否在第一条链表中出现过
}word[100010];

int main()
{
    int h1, h2, n;  //h1,h2为两单词首地址n为输入字母数
    cin >> h1 >> h2 >>n;
    int tempAdd, tempNext;
    Execlelem tempData;
    for(int i = 0; i < n; i++){ //依次输入每个结点
        scanf("%d %c %d", &tempAdd, &tempData, &tempNext);
        word[tempAdd].next = tempNext;
        word[tempAdd].data = tempData;
    }
    int p;
    for(p = h1; p != -1; p = word[p].next){ //将第一个单词字母标记为true
        word[p].flag = true;
    }
    for(p = h2; p != -1; p = word[p].next){ //找到第一个出现的结点
        if(word[p].flag == true){
            break;
        }
    }
    if(p != -1)
        printf("%05d\n", p);
    else
        printf("%d\n", p);
    return 0;
}
