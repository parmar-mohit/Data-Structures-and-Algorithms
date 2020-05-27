/* This Program Works Fine Only for Undirected Graph.For Directed Graph Few Changes
Would be required */ 

#include <iostream>

using namespace std;

struct node
{
    int x, y, data;
    node* next;
};
node* head = NULL;

void push ( node a );
node pop();

int main()
{
    int N;

    cout << "Enter No of Vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int mst[N+1][N+1];
    int flag[N+1];

    cout << endl << "Enter value of Edges in Martrix" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            mst[i][j] = 0;
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        flag[i] = -1;
    }

    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            if( graph[i][j] > 0 )
            {
                node a;
                a.x = i;
                a.y = j;
                a.data = graph[i][j];
                push( a );
                graph[j][i] = 0;
            }
        }
    }

    node *ptr = head;
    cout << endl;

    while( head != NULL )
    {
        node a = pop();
        if( flag[a.x] == -1 || flag[a.y] == -1)
        {
            mst[a.x][a.y] = a.data;
            mst[a.y][a.x] = a.data;
            flag[a.x]++;
            flag[a.y]++;
        }
    }

    cout << endl << "MST of given graph is Given by Matrix  below" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cout << mst[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void push( node a )
{
    node* abc = new node;
    (*abc).x = a.x;
    (*abc).y = a.y;
    (*abc).data = a.data;
    (*abc).next =  NULL;

    if( head == NULL )
    {
        head = abc;
    }else
    {
        node* ptr = head;
        node* parent = NULL;

        while( (*ptr).data < (*abc).data && (*ptr).next != NULL )
        {
            parent = ptr;
            ptr = (*ptr).next;
        }

        if( parent == NULL )
        {
            (*abc).next = ptr;
            head = abc;
        }else if( (*ptr).next == NULL && (*ptr).data < (*abc).data )
        {
            (*ptr).next =  abc;
        }else
        {
            (*abc).next = (*parent).next;
            (*parent).next = abc;
        }
    }
}

node pop()
{
    node a;
    a.x = (*head).x;
    a.y = (*head).y;
    a.data = (*head).data;
    node* temp =  head;
    head = (*head).next;
    delete temp;
    return a;
}