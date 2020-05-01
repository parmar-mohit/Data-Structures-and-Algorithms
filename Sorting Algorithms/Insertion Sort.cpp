#include <iostream>

using namespace std;

void insertionSort( int A[], int N );

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

    insertionSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void insertionSort( int A[], int N )
{
    for ( int i = 1; i < N ; i++ )
    {
        int temp = A[i];

        int j = i-1;

        for( j; j >= 0; j--)
        {
            if( temp < A[j] )
            {
                A[j+1] = A[j];
            }
        }

        A[j+1] = temp;
    }
}
