#include<iostream>
using namespace std;

class node 
{
  public:
  int data;
  node * next;
  node * prev;

  node()
  {
    data = 0;
    next = nullptr;
    prev = nullptr;
  }

  node(int no)
  {
    data = no;
    next = nullptr;
    prev = nullptr;
  }
};

typedef node NODE;
typedef node * PNODE;

class DoublyCLL
{
  private:
  PNODE first;
  PNODE last ;
  int iCount ;

  public:
  DoublyCLL()
  {
    first = nullptr;
    last = nullptr;
    iCount = 0;
  }

  void InsertFirst(int no)
  {
    PNODE newn = new NODE(no);
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
    PNODE temp = nullptr;
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
  void InsertLast(int no)
  {
    PNODE newn = new NODE(no);

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

  void InsertAtPos(int no,int pos)
  {
    PNODE newn = new NODE(no);
    PNODE temp = nullptr;
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
    PNODE temp = nullptr;
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
  DoublyCLL dcobj;
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