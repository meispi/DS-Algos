// AVL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
using namespace std;
class AVL
{
public:
    int data, h;
    AVL* left, * right;
};
void printAVL(AVL* root)
{
    if (root)
    {
        cout << root->data << "->";
        printAVL(root->left);
        printAVL(root->right);
    }
}
int height(AVL* node) //calculates the height of the further tree (1 + no. of nodes beaneath it)
{
    if (node == NULL)
        return 0;
    return node->h;
}
int bf(AVL* node) //calculates the balancing factor of a node
{
    if (!node)
        return 0;
    return height(node->left) - height(node->right);
}
AVL* RightRotate(AVL* node) 
{
    AVL* n1 = node->left;
    AVL* n2 = n1->right;
    n1->right = node;
    node->left = n2;
    node->h = 1 + max(height(node->left), height(node->right));
    n1->h = 1 + max(height(n1->left), height(n1->right));
    return n1;
}
AVL* LeftRotate(AVL* node)
{
    AVL* n1 = node->right;
    AVL* n2 = n1->left;
    n1->left = node;
    node->right = n2;
    node->h = 1 + max(height(node->left), height(node->right));
    n1->h = 1 + max(height(n1->left), height(n1->right));
    return n1;
}
AVL* Insert(AVL* root, int val)
{
    if (!root)
    {
        AVL* node = new AVL();
        node->data = val;
        node->left = node->right = NULL;
        node->h = 1;
        return node;
    }
    if (root->data > val)
        root->left = Insert(root->left, val);
    else
        root->right = Insert(root->right, val);

    root->h = 1 + max(height(root->left), height(root->right));

    if (bf(root) > 1 && val < root->left->data)
        return RightRotate(root);
    if (bf(root) < -1 && val > root->right->data)
        return LeftRotate(root);
    if (bf(root) > 1 && val > root->left->data)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (bf(root) < -1 && val < root->right->data)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
AVL* predecessor(AVL* node)
{
    AVL* ptr = node;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}
AVL* Delete(AVL* root, int val)
{
    if (!root)
        return root;
    if (val < root->data)
        root->left = Delete(root->left, val);
    else if (val > root->data)
        root->right = Delete(root->right, val);
    else
    {
        if (!root->left || !root->right)
        {
            AVL* ptr = root->right ? root->right : root->left;
            if (!ptr)
            {
                ptr = root;
                root = NULL;
            }
            else
                *root = *ptr;
            delete(ptr);
        }
        else
        {
            AVL* ptr = predecessor(root->right);
            root->data = ptr->data;
            root->right = Delete(root->right, ptr->data);
        }
    }
    if (!root)
        return root;

    root->h = 1 + max(height(root->left), height(root->right));

    if (bf(root) > 1 && bf(root->left) >= 0)
        return RightRotate(root);
    if (bf(root) > 1 && bf(root->left) < 0)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (bf(root) < -1 && bf(root->right) <= 0)
        return LeftRotate(root);
    if (bf(root) < -1 && bf(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
int main()
{
    AVL* root = NULL;
    root = Insert(root, 11);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 4);
    root = Insert(root, 16);
    root = Insert(root, 88);
    root = Insert(root, 19);
    root = Insert(root, 77);
    root = Insert(root, 100);
    root = Insert(root, 205);
    root = Insert(root, 20);
    
    cout << "\nAVL TREE:\n";
    printAVL(root);

    root = Delete(root, 19);
    root = Delete(root, 88);
    root = Delete(root, 20);
    root = Delete(root, 11);
    root = Delete(root, 205);

    cout << "\nAVL TREE AFTER DELETION:\n";
    printAVL(root);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
