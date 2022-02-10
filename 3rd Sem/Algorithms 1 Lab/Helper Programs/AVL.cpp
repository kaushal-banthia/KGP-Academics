#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
}
node;

node* newnode(int num)
{
    node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->key = num;
    temp->height = 1;
    return temp;
}

int maxi(int a, int b)
{
    return (a > b)? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maxi(height(y->left), height(y->right))+1;
    x->height = maxi(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    x->right = T2;
    y->left = x;

    // Update heights
    y->height = maxi(height(y->left), height(y->right))+1;
    x->height = maxi(height(x->left), height(x->right))+1;

    // Return new root
    return y;
}

int balance_factor(node *root)
{
    if (root == NULL)
        return 0;
    else
        return height(root->left) - height(root->right);
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

    if (key == trav->key)
    {
        return trav;
    }

    trav->height = maxi(height(trav->left), height(trav->right)) + 1;
    int b = balance_factor(trav);

    if (b < -1 && key > (trav->right)->key)
    {
        return leftRotate(trav);
    }
    else if (b > 1 && key < (trav->left)->key)
    {
        return rightRotate(trav);
    }
    else if (b > 1 && key > (trav->left)->key)
    {
        trav->left = leftRotate(trav->left);
        return rightRotate(trav);
    }
    else if (b < -1 && key < (trav->right)->key)
    {
        trav->right = rightRotate(trav->right);
        return rightRotate(trav);
    }

     return trav;
}

node *minimum(node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *del(node *root, int k)
{
    if (root == NULL)
    {return root;}
    if (root->key > k)
    {root->left = del(root->left, k);}
    else if (root->key < k)
    {root->right = del(root->right, k);}

    //now delete this node that we got
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }

        else if (root->right == NULL)
        {
            node *temp = root->left;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }

        //both children exists
        else
        {
            node *temp = minimum(root->right);
            root->key = temp->key;
            root->right = del(root->right, root->key);
        }
    }

    if (root == NULL)
    {return root;}

    root->height = maxi(height(root->left), height(root->right)) + 1;
    int balance = balance_factor(root);

    if (balance > 1 && balance_factor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && balance_factor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && balance_factor(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && balance_factor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(node* node)
{
    if (node == NULL)
        return;
    cout<<node->key<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    cout<<"PreOrder"<<endl;
    preOrder(root);
    cout<<endl;
    root = del(root, 10);
    cout<<"PreOrder"<<endl;
    preOrder(root);
    cout<<endl;
    root = del(root, 9);
    cout<<"PreOrder"<<endl;
    preOrder(root);
    cout<<endl;
    return 0;
}
