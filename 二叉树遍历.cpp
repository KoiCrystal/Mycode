#include<iostream>
using namespace std;
struct tree
{
    tree *leftnode;
    char data;
    tree *rightnode;
}*root;                  //声明一个对象，根节点


void createtree(tree *&t)//指针的引用，t的类型是指针
{
    char d=getchar();
    if (d==' ')
    {
        t=NULL;     //这个子树没有数据，没有左右子树
        return;
    }
    else
    {
        t=new tree;     //声明t，不然没有分配空间
        t->data=d;
        if (root==NULL)
        {
            root=t;             //root此时还没被声明。但直接把t的合法地址给了root
        }
        createtree(t->leftnode);
        createtree(t->rightnode);
    }
}


void qianxu(tree *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<' ';
        qianxu(root->leftnode);             //此时的左节点就成了新的根
        qianxu(root->rightnode);
    }
}


void zhongxu(tree *root)
{
    if (root!=NULL)
    {
        zhongxu(root->leftnode);
        cout<<root->data<<' ';
        zhongxu(root->rightnode);
    }
}


void houxu (tree *root)
{
    if (root!=NULL)
    {
        houxu(root->leftnode);
        houxu(root->rightnode);
        cout<<root->data<<' ';
    }
}


int main()
{
    tree *t=new tree;       //t和root都是指针
    createtree(t);
    qianxu(root);       //从根节点开始遍历
    cout<<endl;
    zhongxu(root);
    cout<<endl;
    houxu(root);
    cout<<endl;
}

//测试数据
//ABC  DE G  F   
//注意最后有空格
// 输出前序中序后序：
// A B C D E G F 
// C B E G D F A 
// C B E G D F A 
