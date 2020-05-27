#include <iostream>

using namespace std;

void quickSort( int A[], int start, int end );
int partition( int A[], int start, int end );

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

    quickSort( arr, 0, N);

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void quickSort( int A[], int start, int end )
{
    int pivot;
    if( start < end )
    {
        pivot = partition( A, start, end);
        quickSort( A, start, pivot - 1 );
        quickSort( A, pivot + 1, end );
    }
}

int partition( int A[], int ll, int ul )
{
    int pivot = A[ll];

    int start = ll;
    int end = ul;

    while( start < end )
    {
        while( A[start] <= pivot )
        {
            start++;
        }
        while( A[end] > pivot )
        {
           end--;
        }

        if ( start < end )
        {
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }

    int temp = A[end];
    A[end] = A[ll];
    A[ll] = temp;

    return end;
}
