#include<iostream>
using namespace std;
int main(){
int arr[5]={10,20,30,40,50};
int start=0;
int end=4;
int target=10;
while(start<=end){
     int mid=(start+end)/2;
   if (arr[mid]==target){
    cout<<"element found at position:"<<mid+1;
    break;
   }
   else if(target<arr[mid]){
    end =mid-1;
   }
   else {
    start=mid+1;
   }
}
}


