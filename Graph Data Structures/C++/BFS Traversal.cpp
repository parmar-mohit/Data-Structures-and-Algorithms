#include <iostream>

using namespace std;

void push( int x, int qp[], int &start, int &end );

int main()
{
    int N;

    cout << "Enter No of Vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int q[N];
    int start = -1;
    int end = -1;
    int flag[N+1];
    int x;
    int ptr;

    cout << endl << "Enter Value of edges in Matrix" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        flag[i] = -1;
    }

    cout << endl << "Enter the vertex to start from : ";
    cin >> x;

    push( x, q, start, end );
    flag[x]++;
    ptr = 0;

    while( ptr != N )
    {
        cout << x << " ";

        for( int i = 1; i <= N; i++ )
        {
            if( graph[x][i] > 0 && flag[i] == -1 )
            {
                push( i, q, start, end );
                flag[i]++;
            }
        }
        ptr++;
        x = q[ptr];
    }

    return 0;
}

void push( int x, int q[], int &start, int &end )
{
    if( start == end )
    {
        start++;
    }
    end++;
    q[end] = x;
}
