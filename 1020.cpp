#include <bits/stdc++.h>
using namespace std;
typedef int typeData;
const int maxn = 35;
int post[maxn];
int in[maxn];
struct node{
    typeData data;
    int layer;
    node* lchild;
    node* rchild;
};
void LayerOrderBFS(node* root, int n){  //���Ѳ������
    int num = 0;
    queue<node*> Q;
    root->layer = 1;    //���������Ų�Ӱ����
    Q.push(root);   //��������
    while(!Q.empty()){
        node* top = Q.front();
        Q.pop();
        printf("%d", top->data);    //��������Ȩֵ
        num++;  //��¼�Ѿ�������Ľ����
        if(num < n) //�����С��n������ո�
            printf(" ");
        if(top->lchild != NULL){    //�������ǿ�
            top->lchild->layer = top->layer + 1;
            Q.push(top->lchild);
        }
        if(top->rchild != NULL){    //�������ǿ�
            top->rchild->layer = top->layer + 1;
            Q.push(top->rchild);
        }
    }
}
node* create(int postL, int postR, int inL, int inR){   //����
    if(postL > postR)   //������������С����ֱ�ӷ���
        return NULL;
    node* root = new node;  //����һ����㱣�浱ǰ�����
    root->data = post[postR];   //�����ȨֵΪ�������е����һλ
    int k;
    for(k = inL; k < inR; k++){
        if(post[postR] == in[k])    //������������ҵ�����������ȷ���ĸ����
            break;
    }
    int numLeft = k - inL;  //��¼�������н������
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    //����������������Ϊ[postL, postL + numLeft - 1], ��������Ϊ[inL, k-1]
    //����������������ַ����ֵ��root��ָ��
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    //����������������Ϊ[postL + numLeft, postR - 1], ��������Ϊ[k+1, inR]
    //����������������ַ����ֵ��root��ָ��
    return root;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    LayerOrderBFS(root, n);
    return 0;
}
