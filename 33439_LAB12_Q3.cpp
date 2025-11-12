#include<iostream>
using namespace std;
bool arrayEq(int arr1[] , int arr2[] , int sz1 , int sz2 , int current){

    if(sz1!=sz2) return false;
    if(current==sz1) return true;
    if(arr1[current]!=arr2[current]) return false;
    return arrayEq(arr1 , arr2 , sz1 , sz2 , current+1);
}
int main(){
    int sz1, sz2;
    cout<<"Enter size of first array : ";
    cin>>sz1;
    int arr1[sz1]; 
    cout<<"Enter elements for first array : ";
    for(int i=0 ; i<sz1 ; i++){
        cin>>arr1[i];
    }
    cout<<"Enter size of second array : ";
    cin>>sz2;
    int arr2[sz2]; 
    cout<<"Enter elements for second array : ";
    for(int i=0 ; i<sz2 ; i++){
        cin>>arr2[i];
    }
    cout<<boolalpha;
    cout<<arrayEq(arr1 , arr2 , sz1 , sz2 , 0);
    return 0;
}