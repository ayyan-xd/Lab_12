#include<iostream>
using namespace std;
int maxSum(int arr[],int n,int index, int &maxSoFar){
    int current=0;
    if(index==n) return 0;
    int sum=maxSum(arr , n , index+1 , maxSoFar);
    if(sum>0) current=arr[index]+sum;
    else current=arr[index];
    if(current>maxSoFar) maxSoFar=current;
    return current;
}
int main(){
int size;
cout<<"Enter size of array : ";
cin>>size;
int arr[size];
cout<<"Enter elements of array : ";
for(int i=0;i<size;i++) cin>>arr[i];
int maxSoFar=arr[0];
maxSum(arr , size , 0 , maxSoFar);
cout<<"Maximum Sum is : "<<maxSoFar; 
return 0;
}