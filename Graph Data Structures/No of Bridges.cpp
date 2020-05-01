/* This Program Finds the no of Bridges and their Location in given Graph.
It is built for Undirected graph.It may or may not work for Directed Graph */

#include <iostream>
#include <mem.h>
#include <limits>

using namespace std;

struct node
{
    int x,y;
    node* next;
}*head;


void stackPush( int x, int stack[], int &ptr );
void listPush( node a );
int stackPop( int stack[], int &ptr );
node listPop();

int main()
{
    int N;

    cout << "Enter no of vertices in Graph : ";
    cin >> N;

    int graph[N+1][N+1];
    int time[N+1][2];
    int minTime[N+1];
    int flag[N+1];
    int stack[N+1];
    int ptr = -1;
    int timer = 0;
    int x;
    int countBridge = 0;

    cout << endl << "Enter value of edged in graph" << endl;
    for( int i = 1; i <= N; i++ )
    {
        for( int j = 1; j <= N; j++ )
        {
            cin >> graph[i][j];
        }
    }

    memset( flag, -1 , sizeof( flag ) );

    for( int i = 1; i <= N; i++ )
    {
        minTime[i] = numeric_limits<int>::max();
        time[i][1] = numeric_limits<int>::max();
    }

    cout << endl << "Enter the Vertex to start from : ";
    cin >> x;

    stackPush( x, stack, ptr );
    flag[x]++;
    timer++;
    time[x][0] = timer;
    time[x][1] = 1;

    while( ptr != -1 )
    {
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
            timer++;
            time[stack[ptr]][1] = timer;
            minTime[stack[ptr]] = timer;
            for( int i = 1; i <= N; i++ )
            {
                if( flag[i] >= 0 && graph[i][stack[ptr]] > 0 && i != stack[ptr -1] )
                {
                    if( minTime[stack[ptr]] > time[i][0]  )
                    {
                        minTime[stack[ptr]] = time[i][0];
                    }
                    if( minTime[stack[ptr]] > time[i][1] )
                    {
                        minTime[stack[ptr]] = time[i][1];
                    }
                    if( minTime[stack[ptr]] > minTime[i] )
                    {
                        minTime[stack[ptr]] = minTime[i];
                    }
                }
            }
            int temp;
            temp = stackPop( stack , ptr );

            if( ptr != -1 )
            {
                if( minTime[temp] > time[stack[ptr]][0] )
                {
                    node a;
                    a.x = temp;
                    a.y = stack[ptr];
                    listPush( a );
                    countBridge++;
                }       
            }
        }else
        {
            stackPush( i, stack, ptr );
            flag[i]++;
            timer++;
            time[i][0] = timer;
        }

        x = stack[ptr];
    }

    cout << endl << "There are " << countBridge << " Bridges in the given Graph" << endl;
    int index = 1;
    while( head != NULL )
    {
        node a = listPop();
        cout << "Bridge " << index << " Between Vertices " << a.x << " and " << a.y << endl;
        index++;
    }

    return 0;
}

void stackPush( int x, int stack[], int &ptr )
{
    ptr++;
    stack[ptr] = x;
}

int stackPop( int stack[], int &ptr )
{
    int x = stack[ptr];
    ptr--;
    return x;
}

void listPush( node a )
{
    node* abc = new node;
    (*abc).x = a.x;
    (*abc).y = a.y;
    (*abc).next = NULL;

    if( head == NULL )
    {
        head = abc;
    }else
    {
        node* ptr = head;
        while( (*ptr).next != NULL )
        {
            ptr = (*ptr).next;
        }
        (*ptr).next = abc;
    }
}

node listPop()
{
    node a;
    a.x = (*head).x;
    a.y = (*head).y;
    a.next = NULL;
    node* temp =  head;
    head = (*head).next;
    delete temp;
    return a;
}
