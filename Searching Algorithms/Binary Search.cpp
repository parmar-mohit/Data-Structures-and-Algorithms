#include <iostream>

using namespace std;

int binarySearch( int A[], int N,int n );

int main()
{
    int N;

    cout << "Enter No of Elements in array : ";
    cin >> N;

    int arr[N];
    int n;

    cout << "Enter elements of array : ";
    for ( int i = 0; i < N; i++ )
    {
        cin >> arr[i];
    }

    cout << "Enter the number to be searched : ";
    cin >> n;

    int pos = binarySearch( arr, N ,n );

    if( pos > 0 )
    {
        cout << "Elements is found at position " << pos << endl;
    }else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}

int binarySearch( int A[], int N, int n )
{
    int ll = 0;
    int ul = N-1;

    int mid = (ll + ul) / 2;

    while ( ll < ul && A[mid] != n )
    {
        if ( A[mid] < n )
        {
            ll = mid + 1;
        }else
        {
            ul = mid - 1;
        }

        mid = (ll + ul) /2;
    }

    if ( A[mid] == n )
    {
        return mid;
    }else
    {
        return -1;
    }
}
