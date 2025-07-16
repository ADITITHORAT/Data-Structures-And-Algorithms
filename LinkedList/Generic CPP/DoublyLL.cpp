#include<iostream>
using namespace std;


template<class T>
class node 
{
  public:
  T data;
  node<T> * next;
  node<T> * prev ;

  node ()
  {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

  node (T no)
  {
    data = no;
    next = nullptr;
    prev = nullptr;
  }
};




template <class T>
class DoublyLL
{
  private:
  node<T> * first;
  int iCount ;

  public:

  DoublyLL()
  {
    first = nullptr;
    iCount = 0;
  }
  

  void Display()
  {
    node <T> * temp = first;
    cout<<"NULL <=> ";
    while(temp != nullptr)
    {
      cout<<"| "<<temp->data<<" | <=> ";
      temp = temp->next;
    }
    cout<<"NULL\n"<<endl;
  }


  void InsertFirst(T no)
  {
    node <T> * newn = new node <T>(no);
    if(first == nullptr)
    {
      first = newn; 
    }
    else
    {
      newn -> next = first;
      first ->prev = newn;
      first = newn;
    }
    iCount++;
  }


  void InsertLast(T no)
  {
    node <T>* newn = new node <T>(no);
    node <T>* temp = nullptr;
    if(first == nullptr)
    {
      first =  newn;
    }
    else 
    {
      temp = first;
      while (temp -> next != nullptr)
      {
        temp = temp -> next;
      }
      temp -> next = newn ;
      newn -> prev = temp ;
      
    }
    iCount++;
    
  }


    void InsertAtPos(T no,int pos)
    {
      node <T>* newn = new node<T>(no);
      node <T>* temp = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount +1))
      {
        cout<<"Invlaid Inpout Position"<<endl;
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
        temp = first ;
        for(iCnt = 1; iCnt < pos -1 ;iCnt++)
        {
          temp = temp -> next;
        }
        newn -> next = temp -> next ;
        temp ->next ->prev = newn;
        newn ->prev = temp;
        temp ->next = newn;

        iCount++;
      }
    }
    


    void DeleteFirst()
    {
      
      if(first == nullptr)
      {
        return;
      }
      else if (first -> next == nullptr)
      {
        delete first;
        first = nullptr;
        
      }
      else
      {
        first = first -> next;
        delete (first -> prev);
        first -> prev = nullptr;
      }
      iCount--;
    }
    void DeleteLast()
    {
      node <T>* temp = nullptr;
      if(first == nullptr)
      {
        return;
      }
      else if ( first -> next == nullptr)
      {
        delete first;
        first = nullptr;
      }
      else 
      {
        temp = first;
        while(temp ->next -> next != nullptr)
        {
          temp = temp -> next;
        }
        
        delete temp ->next;
        temp ->next = nullptr;
      }
      iCount--;
    }


    void DeleteAtPos(int pos)
    {
      node <T> * temp = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount))
      {
        cout<<"Invalid Input Position"<<endl;
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
        for(iCnt = 1 ; iCnt < pos -1 ; iCnt ++)
        {
          temp = temp -> next;
        }
        temp ->next = temp -> next -> next;
        delete temp ->next ->prev;
        temp ->next ->prev = temp;
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
  DoublyLL<int> dobj ;
  int iRet = 0;
  dobj.InsertFirst(51);
  dobj.InsertFirst(21);
  dobj.InsertFirst(11);
  dobj.Display();
  iRet = dobj.Count();
  cout<<"number of elements are : "<<iRet<<endl;
  dobj.InsertLast(51);
  dobj.InsertLast(21);
  dobj.InsertLast(11);
  dobj.Display();
  iRet = dobj.Count();
  cout<<"number of elements are : "<<iRet<<endl;
  // dobj.DeleteFirst();
  // dobj.Display();
  // iRet = dobj.Count();
  // cout<<"number of elements are : "<<iRet<<endl;
  // dobj.DeleteLast();
  // dobj.Display();
  // iRet = dobj.Count();
  // cout<<"number of elements are : "<<iRet<<endl;
  dobj.DeleteAtPos(5);
  dobj.Display();
  iRet = dobj.Count();
  cout<<"number of elements are : "<<iRet<<endl;
  dobj.InsertAtPos(105,5);
  dobj.Display();
  iRet = dobj.Count();
  cout<<"number of elements are : "<<iRet<<endl;
  return 0;
}




