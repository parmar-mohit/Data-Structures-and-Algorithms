#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int N;

    cout << "Enter No of Vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int path[N+1];
    int x;

    cout << endl << "Enter Value of Edges in Graph" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }

        path[i] = numeric_limits<int>::max();
    }

    cout << endl << "Enter the vertex to start from : ";
    cin >> x;
    int start  = x;

    path[x] = 0;

    for( int i = 1; i < N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            for( int k = 1; k <= N; k++ )
            {
                if( graph[j][k] != 0 )
                {
                    if( path[j] + graph[j][k] < path[k] )
                    {
                        path[k] = path[j] + graph[j][k];
                    }
                }
            }
        }
    }

    cout << endl << endl;
    for( int i = 1; i <= N; i++ )
    {
        if( i != x )
        {
            cout << "Shortest Distance from " << start << " to " << i  << " is " << path[i] << endl;
        }
    }

    return 0;
}
