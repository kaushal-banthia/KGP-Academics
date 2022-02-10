#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    struct node *left, *right;
}
node;

node* newnode(int num)
{
    node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->key = num;
    return temp;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}

node *insert(node *trav, int key)
{
    if (trav == NULL)
    {
        return newnode(key);
    }

    if (key < trav->key)
    {
        trav->left = insert(trav->left, key);
    }

    if (key > trav->key)
    {
        trav->right = insert(trav->right, key);
    }

    return trav;
}

node *del(node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->key > k)
    {
        root->left = del(root->left, k);
        return root;
    }

    else if (root->key < k)
    {
        root->right = del(root->right, k);
        return root;
    }

    //now delete this node that we got
    if (root->left == NULL)
    {
        node *temp = root->right;
        delete root;
        return temp;
    }

    else if (root->right == NULL)
    {
        node *temp = root->left;
        delete root;
        return temp;
    }

    //both children exists
    else
    {
        node *parent = root;
        node *successor = root->right;
        while(successor->left != NULL)
        {
            parent = successor;
            successor = successor->left;
        }

        if (parent != root)
            parent->left = successor->right;
        else
            parent->right = successor->right;

        root->key = successor->key;
        delete successor;
        return root;
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = del(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = del(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = del(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}
