#include <iostream>

using namespace std;

void mergeSort( int A[], int start, int end );
void merge( int A[], int start,int mid, int end );

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

    mergeSort( arr, 0, N );

    cout << "Elements in Sorted order are " << endl;
    for ( int i = 0; i < N; ++i )
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void mergeSort( int A[], int start, int end )
{
    if ( start < end )
    {
        int mid =  ( start + ( end - 1 ) ) / 2;

        mergeSort( A, start, mid );
        mergeSort( A, mid+1, end );
        merge( A, start, mid, end );
    }
}

void merge( int A[], int start,int mid, int end )
{
    int nl = mid - start + 1;
    int nr = end - mid;

    int leftArr[nl];
    int rightArr[nr];

    for ( int i = 0; i < nl; i++ )
    {
        leftArr[i] = A[start + i];
    }

    for ( int i = 0; i < nr; i++ )
    {
        rightArr[i] = A[mid + i + 1];
    }

   int i = 0, j = 0, k = start;

   while(i < nl && j<nr)
   {
      if( leftArr[i] <= rightArr[j] )
      {
        A[k] = leftArr[i];
        i++;
      }else
      {
        A[k] = rightArr[j];
        j++;
      }
      k++;
   }
   while( i < nl )
   {
        A[k] = leftArr[i];
        i++;
        k++;
   }
   while(j<nr)
   {
        A[k] = rightArr[j];
        j++;
        k++;
   }
}
