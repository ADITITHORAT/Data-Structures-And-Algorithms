#include<iostream>
using namespace std;

template < class T>
class node
{
  public:
  T data;
  node<T> * next;
  node(T no)
  {
    data = no;
    next = nullptr;
  }

  node ()
  {
    data = 0;
    next = nullptr;
  }
};


template <class T>
class SinglyLL
{
    private:
    int iCount = 0;
    node<T> * first = nullptr;

    public:

    void Display()
    {
      node<T>  * temp = first;
      while(temp != nullptr)
      {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
      }
      cout<<"NULL"<<endl;
    }


    void InsertFirst(T no)
    {
      node<T>  * newn = new node<T>  (no);
      
      if(first == nullptr)
      {
        first = newn;
      }
      else
      {
        newn -> next = first;
        first = newn;
      }
      iCount++;
    }


    void InsertLast(T no)
    {
      node<T>  * newn = new node<T> (no);
      node<T>  * temp = nullptr;
      if(first == nullptr)
      {
        first = newn;
      }
      else 
      {
        temp = first;
        while(temp -> next != nullptr)
        {
          temp = temp -> next;
        }
        temp -> next = newn;
        newn -> next = nullptr; 
      }
      iCount++;
    }


    void InsertAtPos(T no,int pos)
    {
      node<T>  * newn = new node<T>  (no);
      node<T>  * temp = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount +1))
      {
        cout<<"Invalid Position"<<endl;
        return;
      }

      if(pos == 1)
      {
        InsertFirst(no);
      }
      else if (pos == iCount + 1)
      {
        InsertLast(no);
      }
      else
      {
        temp = first;
        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
          temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
      }
    }
    


    void DeleteFirst()
    {
      node<T>  * temp = nullptr;
      if(first == nullptr)
      {
        return;
      }
      else
      {
        temp = first;
        first = first -> next;
        delete temp;
      }
      iCount--;
    }
    void DeleteLast()
    {
      node<T>  * temp = nullptr;
      node<T>  * target = nullptr;
      if(first == nullptr)
      {
        return;
      }
      else if (first -> next == nullptr)
      {
        first  = nullptr;
        delete first;
      }
      else 
      {
        temp = first;
        while (temp -> next -> next != nullptr)
        {
          temp = temp->next;
        }
        temp -> next = target;
        temp -> next = nullptr;
        delete target;
      }
      iCount--;
    }


    void DeleteAtPos(int pos)
    {
      node<T>  * temp = nullptr;
      node<T>  * target = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount))
      {
        cout<<"Invalid Position"<<endl;
        return;
      }
      if(pos == 1)
      {
        DeleteFirst();
      }
      else if (pos == iCount)
      {
        DeleteLast();
      }
      else 
      {
        temp = first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
          temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = temp -> next-> next;
        delete target;
        iCount--;
      }

    }
    int Count()
    {
      return iCount;
    }
};
int main()
{
  SinglyLL<int> sobj;
  int iRet = 0;
  sobj.InsertFirst(12);
  sobj.InsertFirst(11);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  sobj.InsertLast(13);
  sobj.InsertLast(14);
  sobj.InsertLast(16);
  sobj.InsertLast(17);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;

  // sobj.DeleteFirst();
  // sobj.Display();
  // iRet = sobj.Count();
  // cout<<"Number of Elements are : "<<iRet<<endl;  
  // sobj.DeleteLast();
  // sobj.Display();
  // iRet = sobj.Count();
  // cout<<"Number of Elements are : "<<iRet<<endl;  

  sobj.InsertAtPos(15,5);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  sobj.DeleteAtPos(5);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  return 0;

}