#include <iostream>

using namespace std;

int linearSearch( int A[], int N,int n );

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

    int pos = linearSearch( arr, N ,n );

    if( pos > 0 )
    {
        cout << "Elements is found at position " << pos << endl;
    }else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}

int linearSearch( int A[], int N, int n )
{
    int loc = -1;

    for ( int i = 0; i < N; i++ )
    {
        if ( A[i] == n )
        {
            loc = i;
            break;
        }
    }

    return loc;
}
