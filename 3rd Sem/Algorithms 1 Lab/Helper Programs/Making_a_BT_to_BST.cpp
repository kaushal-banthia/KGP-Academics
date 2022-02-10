#include <bits/stdc++.h>
using namespace std;

int c = 0;

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

node* buildTreeUtil(node **arr, int start, int e)
{
    // base case
    if (start > e)
        return NULL;

    /* Get the middle element and make it root */
    int mid = (start + e)/2;
    node *root = arr[mid];

    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(arr, start, mid-1);
    root->right = buildTreeUtil(arr, mid+1, e);

    return root;
}

void stores_nodes(node *root, node* arr[])
{
    if (root == NULL)
        return;
    stores_nodes(root->left, arr);
    arr[c] = root;
    c++;
    stores_nodes(root->right, arr);
}

node* bt_to_bst(node *root)
{
    int n = 5;
    node* arr[n];
    stores_nodes(root, arr);
    return buildTreeUtil(arr, 0, n-1);
}

void preOrder(node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->key);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);

    root = bt_to_bst(root);

    printf("In order traversal of the given tree \n");
    preOrder(root);

    return 0;
}
