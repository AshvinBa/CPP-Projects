#include<bits/stdc++.h>
using namespace std;


void display()
{
    cout<<"\t1. Add Books."<<endl;
    cout<<"\t2. Search Books."<<endl;
    cout<<"\t3. Borrow Books."<<endl;
    cout<<"\t4. Check out Books."<<endl;
    cout<<"\t5. Return Books."<<endl;
    cout<<"\t6. Exit"<<endl;

}

int main()
{
    int choose;
    string auther, title, keyword, ISBN, borrowerName;

    cout<<"\n\t***Library Management***\n";
    display();

    cout<<"\tEnter Your Choise: ";
    cin>>choose;

    while(choose<6)
    {
        switch(choose)
        {
            case 1:
            {

            }
            break;
            case 2:
            {

            }
            break;
            case 3:
            {

            }
            break;
            case 4:
            {

            }
            break;
            case 5:
            {

            }
            break;
            case 6:
            {
                cout<<"Exit";
            }
            break;

        }
    }



    return 0;
}