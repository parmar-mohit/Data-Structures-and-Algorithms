// This Splay tree Deletion Code is written with Top DOwn approach 

#include <iostream>

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

tree *root = NULL;

tree* create( int x );
void create_tree( int A[], int N );
void inorder_disp( tree* root );
void remove( int x );
tree* splay( tree* root, int x );
tree* right_rotation( tree* root );
tree* left_rotation( tree* root );

int main()
{
    int N;
    int num;

    cout << "Enter No of nodes in tree : ";
    cin >> N;

    int A[N];

    cout << "Enter value of nodes of tree : ";
    for( int i = 0; i < N; i++ )
    {
        cin >> A[i];
    }

    create_tree( A, N);

    cout << "Binary Search Tree Created Sucessfully" << endl;
    cout << endl << endl;


    cout << "Inorder Traversal is ";
    inorder_disp( root );

    cout << "Enter No to be deleted : ";
    cin >> num;
    remove( num );
    cout << endl << endl;

    cout << "Inorder Traversal is ";
    inorder_disp( root );

    return 0;
}

tree* create( int x )
{
    tree* a = new tree;
    (*a).data = x;
    (*a).left = NULL;
    (*a).right = NULL;

    return a;
}

void create_tree( int A[], int N )
{
    for( int i = 0; i < N ; i++ )
    {
        tree* node = create( A[i] );

        tree* temp = root;
        tree* parent;

        if( temp == NULL )
        {
            root = node;
        }else
        {
            while( temp != NULL )
            {
                parent = temp;
                if( (*node).data < (*temp).data )
                {
                    temp = (*temp).left;
                }else
                {
                    temp = (*temp).right;
                }
            }

            if( (*node).data < (*parent).data )
            {
                (*parent).left = node;
            }else
            {
                (*parent).right = node;
            }
        }
    }
}

void inorder_disp( tree* root )
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

void remove( int x )
{
    root = splay( root, x );

    tree* change;

    change = (*root).left;

    while( (*change).right != NULL )
    {
        change = (*change).right;
    }

    (*root).left = splay( (*root).left, (*change).data );

    tree *temp = root;
    root = (*root).left;
    (*root).right = (*temp).right;

    delete temp;
}

tree* splay( tree* root, int x )
{
    if( (*root).data != x )
    {
        if( x < (*root).data )
        {
            (*root).left = splay( (*root).left , x );
            root = right_rotation( root );
        }else
        {
            (*root).right = splay( (*root).right , x );
            root = left_rotation( root );
        }
    }
    return root;
}

tree* right_rotation( tree* root )
{
    tree* temp = root;
    root = (*root).left;
    (*temp).left = (*root).right;
    (*root).right = temp;
    return root;

}

tree* left_rotation( tree* root )
{
    tree* temp = root;
    root = (*root).right;
    (*temp).right = (*root).left;
    (*root).left = temp;
    return root;
}
