#include<bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

struct Work
{
    string task;
    bool isComplete;

    Work(const string& desc) : task(desc), isComplete(false){}  
};

vector<Work>tasks;

void addTask(const string &taskDesc)
{
    tasks.emplace_back(taskDesc);
    cout<<"\t\nThe task is added sucessfuly.";
    return;
}

void DisplayTask()
{
    if(tasks.size()<=0)
    {
        cout<<"\t\nThere is no task added here.";
        return;
    }
    cout<<"\n";
    for(int i=0;i<tasks.size();i++)
    {
        cout<<"\t"<<tasks[i].task<<" ["<<(tasks[i].isComplete? "Completed" : "Not Completed")<<"] "<<endl;
    }
    cout<<"\n";
}

void MarkAsComplete(int taskNumber)
{
    if(taskNumber == 0 || taskNumber > tasks.size())
    {
        cout<<"\tInvalid Task Number.";
        return;
    }
    else if(tasks[taskNumber-1].isComplete)
    {
        cout<<"\tThe task is already Completed.";
    }
    tasks[taskNumber-1].isComplete=true; 
}

void RemoveTask(int taskNumber)
{
    if(taskNumber==0 || taskNumber>tasks.size())
    {
        cout<<"\tInvalid Task Number. ";
        return;
    }
    tasks.erase(tasks.begin() + (taskNumber-1));
    cout<<"\tThe Task is removed.";
}

void ToDoList()
{
    cout<<"\n\n\t---*** TO-DO-LIST***---\n"<<endl;

    cout<<"\t1) Add Task."<<endl;
    cout<<"\t2) Display Task."<<endl;
    cout<<"\t3) Mark as Complete."<<endl;
    cout<<"\t4) Remove Task."<<endl;
    cout<<"\t5) Exit."<<endl;
    return;
}

int main()
{
    int choice , taskNumber;
    string taskDesc;
    while(true)
    {
    ToDoList();
    cout<<"\n\tEnter Your Choise: ";
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        {
            cout<<"\tEnter the Task: ";
            getline(cin,taskDesc);
            addTask(taskDesc);
        }
        break;
        case 2:
        {
            DisplayTask();
        }
        break;
        case 3:
        {
            cout<<"\tEnter the Task Number: ";
            cin>>taskNumber;
            MarkAsComplete(taskNumber);
        }
        break;
        case 4:
        {
            cout<<"\tEnter the Task Number: ";
            cin>>taskNumber;
            RemoveTask(taskNumber);
        }
        break;
        case 5:
        {
            cout<<"\n\tExit.";
            return 0;
        }
        break;
    }
    }
    return 0;
}