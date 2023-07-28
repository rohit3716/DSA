#include<iostream>
using namespace std;

int partition(int arr[],int s,int e)
 {
    int pivot = arr[s];
    int count = 0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot ){
            count++;
        }
    }
    
    //place pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    //left and right wala part sambhal lete hai
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot) 
        {
            j--;
        }
        
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pivotIndex;
 }

void quickSort(int* arr,int s,int e){
    //base case
    if(s >= e){
        return;
    }

    //partition karenge
    int p = partition(arr,s,e);

    //left part sort kro
    quickSort(arr,s,p-1);

    //right part sort kro
    quickSort(arr,p+1,e);
}

int main() {
    int arr[10] = {3,2,5,1,5,5,7,8,9,0};
    int n = 10;

    quickSort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}