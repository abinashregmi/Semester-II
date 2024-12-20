//Scientific Calculator in c++
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout<<"\n\t -----------------------------------\n";
    cout<<"\t             Calculator               \n";
    cout<<"\t -----------------------------------\n";
    cout<<"\t1:Addition\t\t" <<" 8:Sin" <<endl;
    cout<<"\t2:Subtraction\t\t"<<" 9:Cos" <<endl;
    cout<<"\t3:Multiplication\t" <<"10:Tan"<<endl;
    cout<<"\t4:Division\t\t" <<"11:Inverse of Sin" <<endl;
    cout<<"\t5:Exponent\t\t" <<"12:Inverse of Cos" <<endl;
    cout<<"\t6:Square\t\t" <<"13:Inverse of Tan" <<endl;
    cout<<"\t7:Log\t\t\t" <<"14:Exist" <<endl;

    float x,y;
    float PI=3.14159265;
    int choice;
    do{
        cout<<"\n\t Enter the function that you want to perform :";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\n Enter 1st number : ";
                cin>>x;
                cout<<"\nEnter 2nd number : ";
                cin>>y;
                cout<<"\n Result = " <<x+y<<endl;
                break;
            case 2:
                cout<<"\n Enter 1st number : ";
                cin>>x;
                cout<<"\nEnter 2nd number : ";
                cin>>y;
                cout<<"\n Result = " <<x-y<<endl;
                break;
            case 3:
                cout<<"\n Enter 1st number : ";
                cin>>x;
                cout<<"\nEnter 2nd number : ";
                cin>>y;
                cout<<"\n Result = " <<x*y<<endl;
                break;
            case 4:
                cout<<"\n Enter 1st number : ";
                cin>>x;
                cout<<"\nEnter 2nd number : ";
                cin>>y;
                cout<<"\n Result = " <<x/y<<endl;
                break;
            case 5:
                cout<<"\n Enter 1st number : ";
                cin>>x;
                cout<<"\nEnter the Exponent : ";
                cin>>y;
                cout<<"\n Result = " <<pow(x,y)<<endl;
                break;
            case 6:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<sqrt(x)<<endl;
                break;
            case 7:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<log10(x)<<endl;
                break;
            case 8:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<sin(x)<<endl;
                break;
            case 9:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<cos(x)<<endl;
                break;
            case 10:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<tan(x)<<endl;
                break;
            case 11:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<asin(x)*180.0/PI<<endl;
                break;
            case 12:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<acos(x)*180.0/PI<<endl;
                break;
            case 13:
                cout<<"\n Enter the number : ";
                cin>>x;
                cout<<"\n Result = "<<atan(x)*180.0/PI<<endl;
                break;
            case 14:
                break;
                default:
                cout <<"\nWrong Input\t";
                break;
        }
    }while(choice !=14);

}
