#include <iostream>

using namespace std;

void radixSort( int A[], int N );

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

    radixSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void radixSort( int A[], int N )
{
    int max = A[0];

    for( int i = 1; i < N; i++ )
    {
        if( A[i] > max )
        {
            max = A[i];
        }
    }

    int maxval = 0;
    while( max > 0 )
    {
        max = max/10;
        maxval++;
    }

    int bucket[10][N+1];

    for( int i = 0;  i < 10; i++ )
    {
        bucket[i][N] = 0;
    }

    for( int i = 1; i <= maxval; i++ )
    {
        int div = 1;

        for( int k = 0; k < i; k++ )
        {
            div *= 10;
        }

        for(int j = 0; j < N ; j++ )
        {
            int val = A[j] % div;

            if ( val > 10 || A[j] < 10 )
            {
                val = val / ( div / 10 );
            }

            bucket[val][bucket[val][N]] = A[j];
            bucket[val][N]++;
        }

        int k = 0;
        for(int i = 0; i < 10; i++ )
        {
            for ( int j = 0; j < bucket[i][N]; j++ )
            {
                A[k] = bucket[i][j];
                k++;
            }
        }

        for( int i = 0;  i < 10; i++ )
        {
        bucket[i][N] = 0;
        }
    }
}
