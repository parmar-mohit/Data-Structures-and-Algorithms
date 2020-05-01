#include <iostream>

using namespace std;

struct min_data
{
    int x;
    int y;
    int data;
};

bool isUnvisited( int flag[], int N );

int main()
{
    int N;

    cout << "Enter No of edges in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int mst[N+1][N+1];
    int flag[N+1];
    int v;

    cout << endl << "Enter Value of Edges In Matrix" << endl;
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
        flag[i] = 0;
    }

    cout << endl << "Enter the vertex to start from : ";
    cin >> v;

    flag[v]++;

    while( isUnvisited( flag, N ) )
    {
        min_data val;
        val.data = -1;
        int count = 1;

        for( int i = 1; i <= N; i++ )
        {
            if( flag[i] > 0 )
            {
                for( int j = 1; j <= N; j++ )
                {
                    if( graph[i][j] > 0 && count  == 1 && mst[i][j] == 0 )
                    {
                        val.data = graph[i][j];
                        val.x = i;
                        val.y = j;
                        count++;
                    }else if( graph[i][j] > 0 && graph[i][j] <= val.data )
                    {
                        if( mst[i][j] == 0 )
                        {
                            val.data = graph[i][j];
                            val.x = i;
                            val.y = j;
                        }
                    }
                }
            }
        }

        flag[val.y]++;
        mst[val.x][val.y] = val.data;
        mst[val.y][val.x] = val.data;
    }

    cout << endl << "MST for given graph is given by matrix" << endl;
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

bool isUnvisited( int flag[], int N )
{
    bool val = false;

    for( int i = 1; i <= N; i++ )
    {
        if( flag[i] == 0 )
        {
            val = true;
        }
    }

    return val;
}
