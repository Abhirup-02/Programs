#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }
    int isEmpty();
    Node *getRoot();
    void insert(int);
    void inOrder(Node *);
    void preOrder(Node *);
    void postOrder(Node *);
    void search(int);
    void smallest();
    void largest();
    void del(int);
    int totalNodes(Node *);
    int externalNodes(Node *);
    int internalNodes(Node *);
    int height(Node *);
    void deleteTree(Node *);
};

int Tree::isEmpty()
{
    if (root == NULL)
        return 1;
    return 0;
}

Node *Tree::getRoot()
{
    return root;
}

Node *createNode(int item)
{
    Node *ptr = new Node;
    ptr->lchild = NULL;
    ptr->data = item;
    ptr->rchild = NULL;
    return ptr;
}

void Tree::insert(int key)
{
    Node *curr = createNode(key);
    if (isEmpty())
    {
        root = curr;
        return;
    }
    Node *temp = root, *parent;
    while (temp != NULL)
    {
        parent = temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    if (key > parent->data)
        parent->rchild = curr;
    else
        parent->lchild = curr;
}

void Tree::inOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    inOrder(r->lchild);
    cout << r->data << " ";
    inOrder(r->rchild);
}

void Tree::preOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    cout << r->data << " ";
    preOrder(r->lchild);
    preOrder(r->rchild);
}

void Tree::postOrder(Node *r)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (r == NULL)
        return;
    postOrder(r->lchild);
    postOrder(r->rchild);
    cout << r->data << " ";
}

void Tree::search(int key)
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Item Found" << endl;
            return;
        }
        else if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    cout << "Item not Found" << endl;
}

void Tree::smallest()
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp->lchild != NULL)
        temp = temp->lchild;
    cout << "Smallest Element -> " << temp->data;
}

void Tree::largest()
{
    if (isEmpty())
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp->rchild != NULL)
        temp = temp->rchild;
    cout << "Largest Element -> " << temp->data;
}

int Tree::totalNodes(Node *r)
{
    if (r == NULL)
        return 0;
    else
        return totalNodes(r->lchild) + totalNodes(r->rchild) + 1;
}

void Tree::del(int key)
{
    Node *temp = root, *parent = NULL;
    while (temp != NULL && key != temp->data)
    {
        parent = temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    if (temp == NULL)
    {
        cout << "Item not found" << endl;
        return;
    }
    if (temp->lchild == NULL || temp->rchild == NULL)
    {
        Node *ptr;
        if (temp->lchild == NULL)
            ptr = temp->rchild;
        else
            ptr = temp->lchild;

        if (parent == NULL)
        {
            root = ptr;
            return;
        }
        if (parent->lchild == temp)
            parent->lchild = ptr;
        else
            parent->rchild = ptr;

        delete temp;
        temp = NULL;
    }

    // When both of the children node is present of node is to be deleted
    else
    {
        Node *succ = temp->rchild, *psucc = NULL;
        while (succ->lchild != NULL)
        {
            psucc = succ;
            succ = succ->lchild;
        }
        temp->data = succ->data;
        if (psucc == NULL)
            temp->rchild = succ->rchild;
        else
            psucc->lchild = succ->rchild;

        delete succ;
        succ = NULL;
    }
    cout << "Item deleted successfully" << endl;
}

int Tree::externalNodes(Node *r)
{
    if (r == NULL)
        return 0;
    if (r->lchild == NULL && r->rchild == NULL)
        return 1;
    else
        return externalNodes(r->lchild) + externalNodes(r->rchild);
}

int Tree::internalNodes(Node *r)
{
    return totalNodes(r) - externalNodes(r);
}

int Tree::height(Node *r)
{
    int LTheight, RTheight;
    if (r == NULL)
        return 0;
    LTheight = height(r->lchild);
    RTheight = height(r->rchild);
    return max(LTheight, RTheight) + 1;
}

void Tree::deleteTree(Node *r)
{
    if (r == NULL)
        return;
    deleteTree(r->lchild);
    deleteTree(r->rchild);

    cout << "\n  Deleting Node... " << r->data;
    delete r;
    root = NULL;
}

int main()
{
    Tree t;
    int item, choice;
    while (true)
    {
        cout << "\n\n";
        cout << "1.INSERT" << endl;
        cout << "2.INORDER" << endl;
        cout << "3.PREORDER" << endl;
        cout << "4.POSTORDER" << endl;
        cout << "5.SEARCH" << endl;
        cout << "6.SMALLEST ELEMENT" << endl;
        cout << "7.LARGEST ELEMENT" << endl;
        cout << "8.TOTAL NODES" << endl;
        cout << "9.DELETE" << endl;
        cout << "10.INTERNAL NODES" << endl;
        cout << "11.EXTERNAL NODES" << endl;
        cout << "12.HEIGHT" << endl;
        cout << "13.DELETE TREE" << endl;
        cout << "Enter Choice ->";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a item :";
            cin >> item;
            t.insert(item);
            break;

        case 2:
            t.inOrder(t.getRoot());
            break;

        case 3:
            t.preOrder(t.getRoot());
            break;

        case 4:
            t.postOrder(t.getRoot());
            break;

        case 5:
            cout << "Enter a item to search in BST :";
            cin >> item;
            t.search(item);
            break;

        case 6:
            t.smallest();
            break;

        case 7:
            t.largest();
            break;

        case 8:
            cout << "Total Nodes in BST ->" << t.totalNodes(t.getRoot());
            break;

        case 9:
            if (!t.isEmpty())
            {
                cout << "Enter an item to delete :";
                cin >> item;
                t.del(item);
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        case 10:
            if (!t.isEmpty())
            {
                cout << "Internal Nodes ->" << t.internalNodes(t.getRoot());
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        case 11:
            if (!t.isEmpty())
            {
                cout << "External Nodes ->" << t.externalNodes(t.getRoot());
            }
            else
            {
                cout << "Tree is empty" << endl;
            }
            break;

        case 12:
            cout << "The Height of the BST is " << t.height(t.getRoot());
            break;

        case 13:
            t.deleteTree(t.getRoot());
            break;

        default:
            cout << "Invalid Choice" << endl;
            exit(0);
        }
    }
}