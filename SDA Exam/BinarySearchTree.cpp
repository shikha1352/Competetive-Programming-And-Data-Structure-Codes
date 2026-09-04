#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct treeNode
{
    int data;
    treeNode *left; 
    treeNode *right;
};
treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(data>(node->data))
    {
        node->right=Insert(node->right,data);
    }
    else if(data<(node->data))
    {
        node->left=Insert(node->left,data);
    }
    return node;
}
treeNode *FindMin(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->left)
    {
        return FindMin(node->left);
    }
    else
    {
        return node;
    }
}
treeNode *FindMax(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->right)
    {
        return FindMax(node->right);
    }
    else
    {
        return node;
    }
}
treeNode *Delete(treeNode *node,int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element not found"<<endl;
    }
    else if(data<node->data)
    {
        node->left=Delete(node->left,data);
    }
     else if(data>node->data)
    {
        node->right=Delete(node->right,data);
    }
    else
    {
        if(node->right && node->left)
        {
            temp=FindMin(node->right);
            node->data=temp->data;
            node->right=Delete(node->right,temp->data);
        }
        else
        {
            temp=node;
            if(node->left==NULL)
            {
                node=node->right;
            }
            else if(node->right==NULL)
            {
                node=node->left;
            }
        free(temp);
        }
    }

    return node;
}


void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }

        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);

}
void Preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }

        cout<<node->data<<" ";
        Preorder(node->left);
        Preorder(node->right);

}
void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }

        Postorder(node->left);
        Postorder(node->right);
        cout<<node->data<<" ";


}
int main()
{
    treeNode *root=NULL,*temp;
    int choice;
    while(1)
    {
          cout << "\nEnter choice: \n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Inorder Traversal\n"
             << "4. Preorder Traversal\n"
             << "5. Postorder Traversal\n";
             cin>>choice;
        if(choice==1)
        {
            cout<<"Enter element to be inserted:"<<endl;
            int data;
            cin>>data;
            root=Insert(root,data);
            cout<<"After insertion elements in BST are:"<<endl;
            Inorder(root);
        }
        else if(choice==2)
        {
            cout<<"Enter elements to be deleted:"<<endl;
            int data;
            cin>>data;
            root=Delete(root,data);
            cout<<"After deletion elements in BST are:"<<endl;
            Inorder(root);
        }
        else if(choice==3)
        {
            cout<<"Inorder traversal is:"<<endl;
            Inorder(root);
        }
        else if(choice==4)
        {
            cout<<"preorder traversal is:"<<endl;
            Preorder(root);
        }
         else if(choice==5)
        {
            cout<<"postorder traversal is:"<<endl;
            Postorder(root);
        }
        else
        {
            break;
        }
    }

}
