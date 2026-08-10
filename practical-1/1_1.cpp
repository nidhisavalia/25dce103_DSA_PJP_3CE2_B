#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int n;
    int k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<"Enter the number of rotations: ";
    cin>>k;

    k=k%n;
    for(int i=0;i<k;i++){
        int first=arr[0];
        for(int j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=first;
    }
    cout<<"The array after left rotation is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

