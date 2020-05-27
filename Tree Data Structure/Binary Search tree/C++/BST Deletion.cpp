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
    tree* node = root;
    tree* parent = NULL;

    while( (*node).data != x )
    {
        parent = node;
        if( (*node).data < x )
        {
            node = (*node).right;
        }
        else
        {
            node = (*node).left;
        }
    }

    if( (*node).left == NULL && (*node).right == NULL )
    {
        if( x < (*parent).data )
        {
            (*parent).left = NULL;
        }else
        {
            (*parent).right = NULL;
        }
        
        delete node;
        return;
    }else if ( (*node).left != NULL )
    {
        tree* change;
        tree* nparent = node;

        change = (*node).left;

        while( (*change).right != NULL )
        {
            nparent = change;
            change = (*change).right;
        }

        (*nparent).left = (*change).left;

        (*node).data = (*change).data;

        delete change;
        return;
    }else
    {
        tree* change;
        tree* nparent = node;

        change = (*node).right;

        while( (*change).left != NULL )
        {
            nparent = change;
            change = (*change).left;
        }

        (*nparent).right = (*change).right;

        (*node).data = (*change).data;

        delete change;
        return;
    }
}
