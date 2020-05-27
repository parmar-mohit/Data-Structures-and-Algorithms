#include <iostream>

using namespace std;

void bubbleSort( int A[], int N );

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

    bubbleSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void bubbleSort( int A[], int N )
{
    for ( int i = 1; i < N; i++ )
    {
        for ( int j = 0; j < (N - i) ; j++ )
        {
            if ( A[j] > A[j+1] )
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}