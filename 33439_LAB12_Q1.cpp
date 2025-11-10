#include<iostream>
#include<string>
using namespace std;
bool subSeq(string s1 ,string s2 , int i=0 , int j=0){
if(i==s1.length()) return true;
if(j==s2.length()) return false;
if(s1[i]==s2[j]) return subSeq(s1 , s2 , i+1 , j+1);
else return subSeq(s1 , s2 , i , j+1);
}
int main(){
string s1=" " ; string s2=" ";
cout<<"First String : ";
cin>>s1;
cout<<"Second String : ";
cin>>s2;
if(subSeq(s1 , s2)) cout<<"First string is subset of other. ";
else cout<<"First string is not subset of other. ";
return 0; 
}