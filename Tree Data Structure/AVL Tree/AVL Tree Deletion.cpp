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
void remove( int x );
tree* right_rotation( tree* root );
tree* left_rotation( tree* root );
void inorder_disp( tree* root );
void preorder_disp( tree* root );
int heightTree( tree *root );
tree* balance( tree* root );

int main()
{
    int N;
    int x;

    cout << "Enter No of nodes in tree : ";
    cin >> N;

    int A[N];

    cout << "Enter value of nodes of tree : ";
    for( int i = 0; i < N; i++ )
    {
        cin >> A[i];
    }

    create_tree( A, N );

    cout << "Binary Tree Created Sucessfully" << endl;
    cout << endl;


    cout << "Inorder Traversal is ";
    inorder_disp( root );
    cout << endl;

    cout << "Preorder Travesal is ";
    preorder_disp( root );
    cout << endl;

    cout << "Enter No you want to remove from tree : ";
    cin >> x;

    remove( x );
    cout << x << " Removed From Tree" << endl;

    cout << endl;
    cout << "Inorder Traversal is ";
    inorder_disp( root );
    cout << endl;

    cout << "Preorder Travesal is ";
    preorder_disp( root );
    cout << endl;

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
    for( int i = 0; i < N; i++ )
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
        root = balance( root );
    }
}

int heightTree( tree* root )
{
    if( (*root).left == NULL && (*root).right == NULL )
    {
        return 1;
    }else if( (*root).left == NULL )
    {
        return 1 + heightTree((*root).right);
    }else if( (*root).right == NULL )
    {
        return 1 + heightTree((*root).left);
    }else
    {
        int heightLeftTree = 1 + heightTree((*root).left);
        int heightRightTree = 1 + heightTree((*root).right);
        if( heightLeftTree > heightRightTree )
        {
            return heightLeftTree;
        }else
        {
            return heightRightTree;
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

tree* balance( tree* root )
{
    if((*root).left == NULL && (*root).right == NULL )
    {
        return root;
    }

    if( (*root).left != NULL )
    {
        (*root).left = balance((*root).left);
    }

    if( (*root).right != NULL )
    {
        (*root).right = balance( (*root).right );
    }

    if( (*root).left != NULL && (*root).right != NULL )
    {
        int balance = heightTree( (*root).left ) - heightTree( (*root).right );
        while(  balance <= -2 || balance >= 2 )
        {
            if (balance > 1 && (*root).data < (*(*root).left).data )
            {
                root =  right_rotation(root);
            }

            if (balance < -1 && (*root).data > (*(*root).right).data )
            {
                root = left_rotation(root);
            }

            if (balance > 1 && (*root).data > (*(*root).left).data )
            {
                (*root).left = left_rotation((*root).left);
                root = right_rotation(root);
            }

            if (balance < -1 && (*root).data < (*(*root).right).data )
            {
                (*root).right = right_rotation( (*root).right );
                root = left_rotation(root);
            }
            balance = heightTree( (*root).left ) - heightTree( (*root).right );
        }
    }

    return root;
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
    }

    root = balance( root );
}
