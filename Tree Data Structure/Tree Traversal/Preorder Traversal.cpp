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
void preorder_disp( tree* root );

int main()
{
    root = createTree();
    preorder_disp( root );
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

void preorder_disp(tree* root )
{
    cout << (*root).data << " ";
    
    if( (*root).left != NULL )
    {
        preorder_disp( (*root).left );
    }
    

    if( (*root).right != NULL )
    {
        preorder_disp( (*root).right );
    }
}
