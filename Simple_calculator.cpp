#include<bits/stdc++.h>
#include<iostream>
using namespace std;

float ADDITION(float A,float B)
{
    return A+B;
}

float SUBSTRACTION(float A,float B)
{
    return A-B;
}

float MULTIPLICATION(float A,float B)
{
    return A*B;
}

float DIVIDETION(float A,float B)
{
    return A/B;
}

int main()
{
    int key;
    float n,m;
    while(key!=5)
    {
    cout<<"\n\n**********************************************************";
    cout<<"\n\t\t***The Simple Calculator***\t\n";
    cout<<"\n";
    cout<<"\tThere are following Operations\n";
    
    cout<<"\t   Press - 1) Addition Operation.\n\t   Press - 2) Substraction Operation.\n\t   Press - 3) Multiplication Operation.\n\t   Press - 4) Dividetion Operation.\n\t   Press - 5) Exit.";
    cout<<"\n\t   Enter the value: ";
    cin>>key;

    switch(key)
    {
        case 1:
        {
            cout<<"\n\t   Enter the two values: ";
            cin>>n>>m;
            float ans=ADDITION(n,m);
            cout<<"\n\t   The Addition is: "<<ans;
        }
        break;
        case 2:
        {
            cout<<"\n\t   Enter the two values: ";
            cin>>n>>m;
            float ans=SUBSTRACTION(n,m);
            cout<<"\n\t   The Substraction is: "<<ans;

        }
        break;
        case 3:
        {
            cout<<"\n\t   Enter the two values: ";
            cin>>n>>m;
            float ans=MULTIPLICATION(n,m);
            cout<<"\n\t   The Multiplication is: "<<ans;
        }
        break;
        case 4:
        {
            cout<<"\n\t   Enter the two values: ";
            cin>>n>>m;
            float ans=DIVIDETION(n,m);
            cout<<"\n\t   The Dividation is: "<<ans;
        }
        break;
        case 5:
        {
            cout<<"\n\t   Exit.";
        }
        break;
    }
    }
    cout<<"\n";
    return 0;
}