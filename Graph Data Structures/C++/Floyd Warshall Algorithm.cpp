/* Change the INF(infinity) macro definition according to your given edge weights.
INF Should be much larger than maximum edge weight in given graph */

#include <iostream>
#include <limits>
#include <iomanip>

#define INF 100000;

using namespace std;

int main()
{
    int N;

    cout << "Enter No of Vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int path[N+1][N+1][N+1];

    cout << endl << "Enter Value of Edges In Matrix" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
            path[0][i][j] = graph[i][j];
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            if( path[0][i][j] == 0  && i != j )
            {
                path[0][i][j] = INF;
            }
        }
    }

    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            for( int k = 1; k <= N; k++ )
            {
                if( ( j == i || k == i ) || j == k  )
                {
                    path[i][j][k] = path[i-1][j][k];
                }else
                {
                    if( path[i-1][j][i] + path[i-1][i][k] < path[i-1][j][k] )
                    {
                        path[i][j][k] = path[i-1][j][i] + path[i-1][i][k];
                    }else
                    {
                        path[i][j][k] = path[i-1][j][k];
                    }
                }
            }
        }
    }

    cout << endl << "Shortest Distance Between Vertices is Given in Matrix Below" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cout << setw( 3 ) << path[N][i][j] << " ";
        }
        cout << endl;
    }
}
