#include <iostream>

using namespace std;

bool isUnvisited( int flag[], int N );

int main()
{
    int N;

    cout << "Enter no of Vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
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
        flag[i] = -1;
    }

    cout << endl << "Topological Sort : ";

    while( isUnvisited( flag, N ) )
    {
        int x;

        for( int i = 1; i <= N; i++ )
        {
            int count = 0;

            if( flag[i] == -1)
            {
                for( int j = 1; j <= N; j++ )
                {
                    if( graph[j][i] > 0 )
                    {
                        count++;
                    }
                }  

                if( count == 0 )
                {
                    x = i;
                    break;
                }  
            }      
        }

        cout << x << " ";

        for( int i = 1; i <= N; i++ )
        {
            if( graph[x][i] > 0 )
            {
                graph[x][i] = 0;
            }
        }

        flag[x]++;

    }

    return 0;
}

bool isUnvisited( int flag[], int N )
{
    bool val = false;

    for( int i = 1; i <= N; i++ )
    {
        if( flag[i] == -1 )
        {
            val = true;
            break;
        }
    }
    return val;
}
