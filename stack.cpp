#include <iostream>
using namespace std;
int top = -1;

bool isfull()
{
    if (top == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int push(int &digit, int arr[])
{
    if (isfull())
    {
        cout << "stack overflow";
    }
    else
    {
        arr[++top] = digit;
    }
}
int pop(int arr[])
{
    if(isempty()){
        cout<<"not possible";
    }
    
    else{

    arr[top] = NULL;
    top--;
    }
}

int main()
{

    cout << "Use below operations to push or pop in the stack :" << endl;
    int m, digit, arr[10];
    do
    {
        cout << " 1) Push 2) POP" << endl;
        cin >> m;

        switch (m)
        {
        case 1:
            cout << "Enter the digit :";
            cin >> digit;
            push(digit, arr);
            break;

        case 2:
            cout << "Popping the top:";
            pop(arr);
            break;

        default:
            cout << "Wrong input";
            break;
        }
    } while (1);
    return 0;
}