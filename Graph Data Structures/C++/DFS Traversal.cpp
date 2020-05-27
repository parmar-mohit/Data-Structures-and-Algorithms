#include <iostream>

using namespace std;

void push( int x, int stack[], int &ptr );
int pop( int stack[] , int &ptr );

int main()
{
    int N;

    cout << "Enter No vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int flag[N+1];
    int stack[N];
    int ptr = -1;
    int x;

    for( int i = 1; i <= N; i++ )
    {
        flag[i] = -1;
    }

    cout << endl << "Enter Values of edges in Matrix" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    cout << endl << "Enter the vertex to start from : ";
    cin >> x;

    push( x, stack, ptr );
    flag[x]++;

    cout << "DFS Traversal is : ";
    while( ptr != -1 )
    {
        if( flag[x] == 0 )
        {
            cout << x << " ";
            flag[x]++;
        }

        int i = 1;
        while( i < N+1 )
        {
            if( graph[x][i] > 0 && flag[i] == -1 && i <= N )
            {
                break;
            }
            i++;
        }

        if( i == N + 1 )
        {
            pop( stack, ptr );
        }else
        {
            push( i, stack, ptr );
            flag[i]++;
        }

        x = stack[ptr];
    }


    /*cout << "The given matrix is" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}

void push( int x, int stack[], int &ptr )
{
    ptr++;
    stack[ptr] = x;
}

int pop( int stack[] , int &ptr )
{
    int x = stack[ptr];
    ptr--;
    return x;
}
