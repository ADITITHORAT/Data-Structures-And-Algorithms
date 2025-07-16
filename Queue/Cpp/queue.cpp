#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node * next;

  node()
  {
    this ->data = 0;
    this ->next = nullptr;
  }

  node(int no)
  {
    this ->data = no;
    this ->next = nullptr;
  }
};



class QueueX
{
  private:
  int iCount;
  node * first;

  public:
  QueueX()
  {
    this ->iCount = 0;
    this ->first = nullptr;
  }

  void Enqueue(int no)
  {
    node* newn = new node(no);
    node * temp = first;
    if(first == nullptr)
    {
      first = newn;
    }
    else
    {
      while(temp ->next != nullptr)
      {
        temp = temp ->next;
      }
      temp -> next = newn;

    }
    iCount++;
  }

  int Dequeue()
  {
    node * temp = first;
    if(first == nullptr)
    {
      cout<<"Queue is empty"<<endl;
      return  -1;
    }
    else
    {
      first = first ->next;
      iCount--;
      return  temp ->data;
    }
  }

  void Display()
  {
    node * temp = first;
    while(temp != nullptr)
    {
      cout<<"| "<<temp ->data <<" | - ";
      temp = temp ->next;
    }
    cout<<endl;
    
  }

  int Count()
  {
    return  iCount;
  }
};

int main()
{
  QueueX qobj ;
  qobj.Enqueue(11);
  qobj.Enqueue(21);
  qobj.Enqueue(31);
  qobj.Display();
  int iRet = qobj.Dequeue();
  cout<<"Dequed: "<<iRet<<endl;
  qobj.Display();
  return 0;
}
