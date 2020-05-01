#include <iostream>

using namespace std;

void heapSort( int A[], int N );
void pushHeap( int heap[], int data, int N );
int popHeap( int heap[], int N );

int main()
{
    int N;

    cout << "Enter No of Elements in array : ";
    cin >> N;

    int arr[N];

    cout << "Enter Elements of array : ";
    for ( int  i = 0; i < N; i++ )
    {
        cin >> arr[i];
    }

    heapSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void heapSort( int A[], int N )
{
    int heap[N];
    int heapEnd =  -1;

    for( heapEnd; heapEnd < N; heapEnd++ )
    {
        pushHeap( heap, A[heapEnd], heapEnd );
    }


    while( heapEnd >= 0 )
    {
        A[heapEnd] = popHeap ( heap, heapEnd );
        heapEnd--;
    }
}

void pushHeap( int heap[], int data, int N )
{
    N++;
    heap[N] = data;

    while( N > 0 )
    {
        int parent = ( N - 1 ) / 2;
        if( heap[parent] < heap[N] )
        {
            int temp = heap[parent];
            heap[parent] = heap[N];
            heap[N] = temp;
            N = parent;
        }else
        {
            break;
        }
    }

}

int popHeap( int heap[], int N )
{
    int max = heap[0];

    heap[0] = heap[N];
    N--;

    int i  = 0, leftchild, rightchild;

    while( i < N )
    {
        leftchild = ( 2 * i ) + 1;
        rightchild = ( 2 * i ) + 2;

        if( heap[leftchild] > heap[i] && heap[leftchild] > heap[rightchild] && leftchild <= N )
        {
            int temp = heap[leftchild];
            heap[leftchild] = heap[i];
            heap[i] = temp;
            i = leftchild;
        }else if ( heap[rightchild] > heap[i] && rightchild <= N )
        {
            int temp = heap[rightchild];
            heap[rightchild] = heap[i];
            heap[i] = temp;
            i = rightchild;
        }else
        {
            break;
        }
    }

    return max;
}
