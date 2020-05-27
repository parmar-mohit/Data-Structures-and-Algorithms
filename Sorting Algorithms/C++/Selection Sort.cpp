#include <iostream>

using namespace std;

void selectionSort( int A[], int N );

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

    selectionSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void selectionSort( int A[], int N )
{

    for( int i = 0; i < N-1; i++ )
    {
        int min = i;
        for( int j = i+1; j < N; j++)
        {
            if ( A[j] < A[min] )
            {
                min = j;
            }
        }

        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}
