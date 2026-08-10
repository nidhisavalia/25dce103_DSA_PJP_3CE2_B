#include<iostream>
using namespace std;
int main(){
    int car[6]={10,20,30,40,50,60};
    int target;
    cout<<"enter target element:";
    cin>>target;
    int found=0;
    for(int i=0;i<=6;i++){
        if(car[i]==target){
            found=1;
            cout<<"car found :"<<i+1;
            break;
        }
        
    }
    if (found==0){
        cout<<"car not found";
    }
}