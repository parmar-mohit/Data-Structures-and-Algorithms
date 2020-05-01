#include <iostream>
#include <mem.h>
#include <limits>

using namespace std;

bool isUnvisited(int flag[], int N );

int main()
{
    int N;

    cout << "Enter No of Vertices In Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int path[N+1];
    int flag[N+1];
    int x;

    cout << endl << "Enter value of Edges In Graph" << endl;
    for( int  i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        path[i] = numeric_limits<int>::max();
    }

    memset( flag, -1, sizeof( flag ) );

    cout << endl << "Enter the Vertex to Start from : ";
    cin >> x;
    int start  = x;

    path[x] = 0;
    flag[x]++;

    while( isUnvisited( flag, N ) )
    {
        for( int  i = 1; i <= N; i++ )
        {
            if( graph[x][i] > 0 && flag[i] == -1  )
            {
                if( path[x] + graph[x][i] < path[i] )
                {
                    path[i] = path[x] + graph[x][i];
                }
            }
        }

        int min = numeric_limits<int>::max();
        for( int i = 2; i <= N; i++ )
        {
            if( path[i] < path[min] && flag[i] == -1 )
            {
                min = i;
            }
        }

        x = min;
        flag[x]++;
    }

    cout << endl << endl;
    for( int i = 1; i <= N; i++ )
    {
        if( i != start)
        {
            cout << "Shortest Distance Form " << start << " to " << i << " is " << path[i] << endl;
        }
    }
}

bool isUnvisited(int flag[], int N )
{
    bool val = false;
    for( int i = 1; i <= N; i++ )
    {
        if( flag[i] == -1 )
        {
            val = true;
        }
    }
    return val;
}
