#include <iostream>

using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;
}*root;

tree* create( int i );
tree* createTree();
void inorder_disp( tree* root );

int main()
{
    root = createTree();
    inorder_disp( root );
    return 0;
}

tree* create( int i )
{
    tree* x = new tree;

    (*x).data = i;

    if( (*x). data == -1 )
    {
        return NULL;
    }

    (*x).left = NULL;
    (*x).right = NULL;

    return x;
}

tree* createTree()
{
    tree* head = new tree;

    int x;

    cout << "Enter data : ";
    cin >> x;

    head = create( x );
    if( head != NULL )
    {
        cout << "Left Child of " << x << " ";
        (*head).left = createTree();

        cout << "Right Child of " << x << " ";
        (*head).right = createTree();
    }

    return head;
}

void inorder_disp(tree* root )
{
    if( (*root).left != NULL )
    {
        inorder_disp( (*root).left );
    }

    cout << (*root).data << " ";

    if( (*root).right != NULL )
    {
        inorder_disp( (*root).right );
    }
}
