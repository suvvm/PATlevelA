#include <bits/stdc++.h>
using namespace std;
typedef int dataType;
vector<dataType> data;
struct node{
    dataType data;
    int height;
    node *leftChild;
    node * rightChild;
    node(){
        height = 1;
        leftChild = NULL;
        rightChild = NULL;
    }
};
int getHeight(node *root){
    if(root == NULL)
        return 0;
    else
        return root->height;
}
int getBalanceFactor(node *root){
    return getHeight(root->leftChild) - getHeight(root->rightChild);
}
int updateHeight(node *root){
    root->height = max(getHeight(root->leftChild),getHeight(root->rightChild)) + 1;
}
void leftRotation(node *&root){
    node *temp = root->rightChild;
    root->rightChild = temp->leftChild;
    temp->leftChild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void rightRotation(node *&root){
    node *temp = root->leftChild;
    root->leftChild = temp->rightChild;
    temp->rightChild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insertAVLTree(node *&root, int x){
    if(root == NULL){
        root = new node();
        root->data = x;
        return;
    }
    if(root->data == x){
        return;
    }else if(root->data > x){
        insertAVLTree(root->leftChild, x);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->leftChild) == 1){
                rightRotation(root);
            }else if(getBalanceFactor(root->leftChild) == -1){
                leftRotation(root->leftChild);
                rightRotation(root);
            }
        }
    }else if(root->data < x){
        insertAVLTree(root->rightChild, x);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rightChild) == -1){
                leftRotation(root);
            }else if(getBalanceFactor(root->rightChild) == 1){
                rightRotation(root->rightChild);
                leftRotation(root);
            }
        }
    }
}
node *createAVLTree(){
    node *root = NULL;
    for(vector<dataType>::iterator it = data.begin(); it != data.end(); it++){
        insertAVLTree(root, *it);
    }
    return root;
}
/*void preorder(node *root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preorder(root -> leftChild);
    preorder(root -> rightChild);
}*/
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        data.clear();
        for(int i = 0; i < n; i++){
            dataType temp;
            scanf("%d", &temp);
            data.push_back(temp);
        }
        node *root = createAVLTree();
        //preorder(root);
        //cout << endl;
        printf("%d\n", root->data);
    }
    return 0;
}
