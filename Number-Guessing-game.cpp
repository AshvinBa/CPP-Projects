#include<bits/stdc++.h>
using namespace std;

void Guessing (int digit)
{
    int guess;
    cout<<"\n\tLet's Play."<<endl;

    while(digit)
    {
        cout<<endl<<"\tEnter Your Guess value: ";
        cin>>guess;

        if(digit == guess)
        {
            cout<<"\n\tYour Guess is Correct."<<endl;
            cout<<"\tCongratulation's You won the Game.\n";
            return;
        }
        else if(digit > guess)
        {
            cout<<"\tOpp! Its Smaller than Original."<<endl;
        }
        else
        {
            cout<<"\tOpp! Its Bigger than Original."<<endl;
        }
    }
    return;
}

int main()
{
    int digit,choise;
    srand(static_cast<unsigned int>(time(0)));
    
    int random_number = rand();
    int min = 1;
    int max = 100;
    digit = min + (rand() % (max - min + 1));
    
    do
    {
    cout<<"\n\t***Number Guessing Game***\n";
    cout<<"\tPress-1 To Play Game."<<endl;
    cout<<"\tPress-2 To Exit."<<endl;
    cout<<"\tEnter Your Choise: ";
    cin>>choise;

    switch(choise)
        {
            case 1:
            {
                Guessing (digit);                
                return 0;
            }
            break;
            case 2:
            {
                cout<<"\tExit.";
            }
            break;
        }
    }

    while (choise<2);
    return 0;
}