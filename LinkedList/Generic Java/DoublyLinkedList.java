class node<T>
{
  public T data;
  public node<T> next;
  public node<T> prev;

  public node()
  {
    this.data = data;
    next = null;
    prev = null;
  }
  public node(T no)
  {
    data = no;
    next = null;
    prev = null;
  }
}

class DLL<T>
{
  private int iCount ;
  private node<T> first;

    public DLL() 
    {
      iCount = 0;
      first = null;
    }
    

    public void Display()
    {
      node<T> temp = first;
      while(temp != null)
      {
        System.out.print("| "+temp.data+" | <=> ");
        temp = temp.next;
      }
      System.out.println(" null");
    }

    public int Count()
    {
      return iCount;
    }


    public void InsertFirst(T no)
    {
      node<T> newn = new  node<>(no);
      if(first == null)
      {
        first = newn;
      }
      else
      {
        newn.next = first;
        first = newn;

      }
      iCount++;
    }

    public void InsertLast(T no)
    {
      node<T> newn = new node<>(no);
      node<T> temp = null;
      if(first == null)
      {
        first = newn;
      }
      else
      {
        temp = first;
        while(temp.next != null)
        {
          temp = temp.next;
        }
        temp.next = newn;
        newn.prev = temp;
      }
      iCount++;
    }

    public void InsertAtPos(T no,int pos)
    {
      node<T> newn = new node<>(no);
      node<T> temp = null;
      if(pos < 1 || pos > iCount+1)
      {
        System.out.println("Invalid position");
        return;
      }

      if(pos == 1)
      {
        InsertFirst(no);
      }
      else if (pos == iCount+1)
      {
        InsertLast(no);
      }
      else 
      {
        temp = first;
      for(int iCnt = 1;iCnt < pos -1;iCnt++)
      {
        temp = temp.next;
      }
      newn.next=temp.next;
      newn.prev = temp;
      temp.next = newn;
      temp.next.prev = newn;
      }
    }

    public void DeleteFirst()
    {
      if(first == null)
      {
        return;
      }
      else
      {
        first = first.next;
        first.prev = null;
      }
    }

    public void DeleteLast()
    {
      node<T> temp = null;
      if(first == null)
      {
        return;
      }
      else
      {
        temp = first;
        while(temp.next.next != null)
        {
          temp = temp.next;
        }
        temp.next = temp.next.next;
        
      }
    }

    public void DeleteAtPos(int pos)
    {
      node<T> temp = null;
      if(pos < 1 || pos > iCount)
      {
        System.out.println("Invalid Position");
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
        for(int iCnt = 1; iCnt < pos -1 ;iCnt ++)
        {
          temp = temp.next;
        }
        temp.next = temp.next.next;
      }
    }
  
}

public class DoublyLinkedList {
  public static void main(String A[]) {
      DLL <Integer>dobj = new DLL<>();
      dobj.InsertFirst(21);
      dobj.Display();
      dobj.InsertLast(221);
      dobj.InsertFirst(21);
      dobj.Display();
      dobj.InsertLast(221);
      dobj.Display();
      dobj.InsertAtPos(334, 2);
      // dobj.Display();
      // dobj.DeleteFirst();
      // dobj.Display();
      // dobj.DeleteLast();
      dobj.DeleteAtPos(2);
      dobj.Display();
  }
}
