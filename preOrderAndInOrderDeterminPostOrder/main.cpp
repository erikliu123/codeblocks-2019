#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*用C++的字符串string相关的方法后，比第一次快了很多倍！！*/
string pre,in,post;
struct tree{
    tree *left, *right;
    char data;
};
tree *root;
int constructTree(string qian,string zh, tree **now){
    if(qian.size()==0){
        *now=NULL;
        return 0;
    }

    tree *newtree=new tree();
    newtree->left=newtree->right=NULL;
    newtree->data=qian[0];

    char temp=qian[0];
    int prelen=zh.find_first_of(temp);
    int index=prelen;
    int afterlen=zh.size()-1-prelen;
     *now=newtree;
     constructTree(qian.substr(1,index),zh.substr(0,prelen),&(newtree->left));
     constructTree(qian.substr(1+index,afterlen),zh.substr(1+index,afterlen),&(newtree->right));
     return 0;

}
void output(tree *T){
    if(T){
        output(T->left);
        output(T->right);
        putchar(T->data);
    }
}
int main()
{
    while(cin>>pre>>in){
    constructTree(pre,in,&root);
    output(root);
    cout<<endl;
    }
    return 0;
}
