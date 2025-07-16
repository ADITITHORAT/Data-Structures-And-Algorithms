#include<iostream>
using namespace std;

template <class T>
class node 
{
  public:
  T data;
  node<T> * next;
  node<T> * prev;

  node()
  {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

  node(T no)
  {
    data = no;
    next = nullptr;
    prev = nullptr;
  }
};


template <class T>
class DoublyCLL
{
  private:
  node <T>* first;
  node <T>* last ;
  int iCount ;

  public:
  DoublyCLL()
  {
    first = nullptr;
    last = nullptr;
    iCount = 0;
  }

  void InsertFirst(T no)
  {
    node <T>* newn = new node<T>(no);
    if(first == nullptr  && last == nullptr)
    {
      first = newn;
      last = newn;
    }
    else 
    {
      newn -> next = first;
      first -> prev = newn;
      first = newn;
    }
    last -> next = first;
    first ->prev = last;
    iCount++;

  }
  void Display()
  {
    node<T>* temp = nullptr;
    temp = first;
    if(first == nullptr && last == nullptr)
    {
      cout<<"Empty LinkedList"<<endl;
      return;
    }

    do
    {
      cout<<"| "<<temp->data<<" | <=> ";
      temp = temp -> next ;
    } while (temp != first);
    cout<<endl;
    
  }
  void InsertLast(T no)
  {
    node<T>* newn = new node<T>(no);

    if(first == nullptr && last == nullptr)
    {
      first = newn;
      last = newn;
    }
    else
    {
      newn -> prev = last;
      last -> next = newn;
      last = newn;
    }
    last -> next = first;
    first -> prev = newn;
    iCount++;
  }

  void InsertAtPos(T no,int pos)
  {
    node<T>* newn = new node<T>(no);
    node<T>* temp = nullptr;
    if(pos < 1 || pos > iCount+1)
    {
      cout<<"Invalid Position"<<endl;
      return;
    }
    if(pos == 1)
    {
      InsertFirst(no);
    }
    else if ( pos == iCount+1)
    {
      InsertLast(no);
    }
    else
    {
      temp = first;
      for(int iCnt = 1; iCnt < pos -1;iCnt++)
      {
        temp = temp->next;
      }
      newn -> next = temp ->next;
      newn -> prev = temp ;
      temp -> next ->prev = newn;
      temp -> next = newn;
      iCount++;
    }
  }


  void DeleteFirst()
  {
    if(first == nullptr && last == nullptr)
    {
      return;
    }
    else if (first == last)
    {
      delete first ;
      first = nullptr;
      last = nullptr;
    }
    else 
    {
      last -> next = last -> next -> next;
      delete first;
      first = last -> next;
      last -> next = first;
      first -> prev = last;
    }
    iCount--;
  }

  void DeleteLast()
  {
    if(first == nullptr && last == nullptr)
    {
      return;
    }
    else if ( first == last )
    {
      delete last ;
      first = nullptr;
      last = nullptr;
    }
    else
    {
      last = last -> prev;
      delete last -> next;
      last ->next = first;
      first ->prev = last;
    }
  }

  void DeleteAtPos(int pos)
  {
    node<T>* temp = nullptr;
    if(pos < 1 || pos > iCount)
    {
      cout<<"Invalid Position"<<endl;
      return;
    }

    if(pos == 1)
    {
      DeleteFirst();
    }
    else if ( pos == iCount)
    {
      DeleteLast();
    }
    else 
    {
      temp = first;

      for(int iCnt = 1; iCnt < pos -1 ; iCnt++)
      {
        temp = temp->next;
      }
      temp -> next = temp -> next -> next;
      delete temp -> next -> prev;
      temp -> next ->prev = temp;
      iCount--;
    }
  }
};



int main()
{
  DoublyCLL<int> dcobj;
  dcobj.InsertFirst(21);
  dcobj.InsertLast(31);
  dcobj.InsertFirst(21);
  dcobj.InsertLast(31);
  dcobj.InsertAtPos(14,3);
  dcobj.Display();
  // dcobj.DeleteFirst();
  // dcobj.Display();
  // dcobj.DeleteLast();
  // dcobj.Display();
  dcobj.DeleteAtPos(3);
  dcobj.Display();
  return 0;
}