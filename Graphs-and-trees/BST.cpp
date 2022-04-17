// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Create BST

#include <iostream>
using namespace std;
class BST
{
    int data;
    BST* left, * right;
public:
    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
    BST* insert(BST*, int);
    BST* Delete(BST*, int);
    BST* minvalroot(BST*);
    void preorder(BST*);
    void inorder(BST*);
    void postorder(BST*);
    int height(BST*);
    void givenlevel(BST*, int);
    void levelorder(BST*);
};
int BST::height(BST* root)
{
    if (!root)
        return 0;
    else
    {
        int lht = height(root->left);
        int rht = height(root->right);
        if (lht > rht)
            return lht + 1;
        else
            return rht + 1;
    }
}
void BST::givenlevel(BST* root, int level)
{
    if (!root)
        return;
    if (level == 1)
        cout << root->data << " ";
    else
    {
        givenlevel(root->left, level - 1);
        givenlevel(root->right, level - 1);
    }
}
void BST::levelorder(BST* root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        givenlevel(root, i);
}
BST* BST::insert(BST* root, int val)
{
    if (!root)
        return new BST(val);
    if (val > root->data)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);
    return root;
}
void BST::preorder(BST* root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void BST::inorder(BST* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void BST::postorder(BST* root)
{
    if (!root)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}
BST* BST::minvalroot(BST* root)
{
    BST* curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}
BST* BST::Delete(BST* root, int val)
{
    if (!root)
        return root;
    if (val < root->data)
        root->left = Delete(root->left, val);
    else if (val > root->data)
        root->right = Delete(root->right, val);
    else
    {
        if (!root->left)
        {
            BST* temp = root->right;
            delete(root);
            return temp;
        }
        else if (!root->right)
        {
            BST* temp = root->left;
            delete(root);
            return temp;
        }
        BST* temp = minvalroot(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, root->data);
    }
    return root;
}
int main()
{
    BST b(0), * root = NULL;
    root = b.insert(root, 38);
    b.insert(root, 13);
    b.insert(root, 51);
    b.insert(root, 10);
    b.insert(root, 12);
    b.insert(root, 40);
    b.insert(root, 84);
    b.insert(root, 25);
    b.insert(root, 89);
    b.insert(root, 37);
    b.insert(root, 66);
    b.insert(root, 95);
    cout << "Preorder Traversal : ";
    b.preorder(root);
    cout << "\nInorder Traversal : ";
    b.inorder(root);
    cout << "\nPostorder Traversal : ";
    b.postorder(root);
    cout << "\nLevelorder Traversal : ";
    b.levelorder(root);
    b.insert(root, 67);
    b.insert(root, 35);
    b.insert(root, 11);
    b.Delete(root, 95);
    b.Delete(root, 51);
    b.Delete(root, 38);
    cout << "\n\nAfter deletion\n\n";
    cout << "Preorder Traversal : ";
    b.preorder(root);
    cout << "\nInorder Traversal : ";
    b.inorder(root);
    cout << "\nPostorder Traversal : ";
    b.postorder(root);
    cout << "\nLevelorder Traversal : ";
    b.levelorder(root);
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
