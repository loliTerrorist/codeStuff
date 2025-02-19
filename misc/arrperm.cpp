#include <iostream>
using namespace std;

int* findInvArr(int* A, int size);
int* findPermArr(int* B, int size);

int main()
{
    int N, size; //lines
    int* arr;
    char letterCode; //letterCode = A or B
    //int *arrA = findInvArr;
    cin >> N;
    for (int i = 0; i < N; i++)
    {   
        cin >> letterCode >>size;
        arr = new int[size];
        for(int j=0; j<size; j++)
        {
            cin >> arr[j];
        }
        if(letterCode == 'A')
        {
            arr = findInvArr(arr, size);
            for(int j=0; j<size; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
        else if(letterCode == 'B')
        {
            arr = findPermArr(arr, size);
            for(int j=0; j<size; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
    delete arr;
    return 0;
}

int* findInvArr(int* A, int size)
{
    int* arrA;
    arrA = new int[size];
    for(int i=0; i<size; i++)
    {
        arrA[i] = 0;
        for(int j=0; j<i; j++)
        {
            if(A[j] < A[i])
            {
                arrA[i]++;
            }
        }    
    }

    return arrA;
}

int* findPermArr(int* B, int size)
{
    int* arrB;
    arrB = new int[size];
    int* use;
    use = new int[size];
    for(int i=0; i<size; i++)
    {
        use[i]=1;
    }
    for(int i=size-1; i>=0; i--)
    {
        arrB[i] = 0;
        int k=0;
        int idx;
        for(int j=0; j<size; j++)
        {
            while(use[j]==0) j++;
            idx = j;
            if(k == B[i])
            {
                break;
            }
            k = k + use[j];
        }
        use[idx]=0;
        arrB[i]=idx;
    }

    return arrB;
}
