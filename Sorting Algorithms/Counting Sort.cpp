/* ***This Algorithm Works only for Postive value or whole numbers program crashes if negative integers are used*** */

#include <iostream>

using namespace std;

void countingSort( int A[], int N );

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

    countingSort( arr, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void countingSort( int A[], int N )
{
    int max = A[0];

    for( int i = 1; i < N; i++ )
    {
        if( A[i] > max )
        {
            max = A[i];
        }
    }

    int count[max + 1] = {0};

    for( int i = 0; i < N; i++ )
    {
        count[A[i]]++;
    }

    int k = 0;
    for ( int i = 0; i <= max; i++ )
    {   while( count[i] > 0 )
        {
            A[k] = i;
            count[i]--;
            k++;
        }
    }
}
