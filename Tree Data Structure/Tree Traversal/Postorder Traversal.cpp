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
void postorder_disp( tree* root );

int main()
{
    root = createTree();
    postorder_disp( root );
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

void postorder_disp(tree* root )
{ 
    if( (*root).left != NULL )
    {
        postorder_disp( (*root).left );
    }
    
    if( (*root).right != NULL )
    {
        postorder_disp( (*root).right );
    }

    cout << (*root).data << " ";
}
