#include<iostream>
using namespace std;

int firstOccurence(int arr[],int s,int e,int k){
    //base case
    int ans = -1;
    if(s > e){
    return -1;
    }

    int mid = s + ( e - s )/2;
    
    if( arr[mid] == k ){
        ans = mid;
    } 

    ans = firstOccurence(arr,s,mid-1,k);
    
    if(arr[mid] < k) {
        ans = firstOccurence(arr,mid+1,e,k);
    }

    return ans;
    


}

int lastOccurence(int arr[],int s,int e,int k){
    int ans = -1;
    //base case
    if(s > e){
    return -1;
    }

    int mid = s + ( e - s )/2;
    
    if( arr[mid] == k ){
        int ans = mid;
    }
    else if(1){
        int remainingPart = firstOccurence(arr,mid+1,e,k);
        return remainingPart;
    }
}


int main(){
int arr[5] ={1,3,3,3,4};
int ans1 = firstOccurence(arr,0,5,3);
int ans2 = lastOccurence(arr,0,5,3);
cout<<"First and last occurence  of 1 are " <<ans1<<" and "<<ans2<<" respectively"<<endl; 

}