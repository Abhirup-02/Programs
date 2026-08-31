#include <iostream>
using namespace std;
#define size 5

class CQueue
{
    int front, rear;
    int arr[size];

public:
    CQueue()
    {
        front = rear = 0;
    }
    bool isFull();
    bool isEmpty();
    void insert(int);
    void del();
    void display();
};

bool CQueue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    return false;
}
bool CQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

void CQueue::insert(int x)
{
    if (isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    rear = (rear + 1) % size;
    arr[rear] = x;
}

void CQueue::del()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    front = (front + 1) % size;
}

void CQueue::display()
{
    if (!isEmpty())
    {
        int i;
        for (i = (front + 1) % size; i != rear; i = (i + 1) % size)
        {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
    }
    cout << "\n";
}

int main()
{
    CQueue q;
    int item;

    while (true)
    {
        cout << "\n\n\n";
        cout << "1.FULL" << endl;
        cout << "2.EMPTY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.DISPLAY" << endl;
        cout << "Choose an operation ->";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (q.isFull())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 2:
            if (q.isEmpty())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 3:
            cout << "Enter an item to push :";
            cin >> item;
            q.insert(item);
            break;

        case 4:
            q.del();
            break;

        case 5:
            cout << "The Queue ->";
            q.display();
            break;

        default:
            cout << "Invalid Operation" << endl;
            exit(0);
        }
    }
}