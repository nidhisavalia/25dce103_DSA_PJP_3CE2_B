

#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cout<<"enter no. of books in library: ";
    cin>>n;
    int bookID[n];
    int borrow[n];
    cout<<"enter book ID:";
    for(i=0;i<n;i++)
    {
        cin>>bookID[i];
    }
    for(i=0;i<n;i++)
    {
        borrow[i]=0;
    }
    cout<<"enter your choice:"<<endl;
    cout<<"1.boorow book"<<endl;
    cout<<"2.display book that were borrowed more than once"<<endl;
    cout<<"3.exit"<<endl;
    int choose,id;
    do{
        cout<<"enter your choice: ";
        cin>>choose;
        switch(choose)
        {
        case 1:
            {
                cout<<"enter ID no. of book that you want to borrow: ";
                cin>>id;
                for(i=0;i<n;i++)
                {
                    if(id == bookID[i])
                    {
                        borrow[i]++;
                    }
                }
                break;
            }
        case 2:
            {
                for(i=0;i<n;i++)
                {
                    if(borrow[i]>1)
                    cout<<"ID= "<<bookID[i]<<" borrow= "<<borrow[i]<<endl;
                }
                break;
            }
        case 3:
            {
                break;
            }
        default:
            {
                cout<<"you enter wrong choice";
            }
        }
    }while(choose!=3);
    return 0;
}