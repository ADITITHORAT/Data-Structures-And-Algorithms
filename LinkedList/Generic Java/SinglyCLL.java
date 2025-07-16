class node<T>
{
  public T data;
  public node<T> next;
  
  public node()
  {
    this.data =data;
    next = null;
  }

  public node(T no)
  {
    data = no;
    next = null;
  }
}


class SCLL<T>
{
  private int iCount ;
  private node<T> first;
  private node<T> last;

  public SCLL()
  {
    iCount = 0;
    first = null;
    last = null;
  }

  public void Display()
  { node<T> temp = null;
    temp = first;
    do
    {
      System.out.print("| "+temp.data+" | -> ");
      temp = temp.next;
    }while(temp != first);
    System.out.println(" null");
  }

  public int Count()
  {
    return iCount;
  }

  public void InsertFirst(T no)
  {
    node<T> newn = new node<>(no);
    if(first == null && last == null)
    {
      first = newn;
      last = newn;
      last.next = first;
    }
    else
    {
      newn.next = first;
      first= newn;
      last.next = first;
    }
    iCount++;

  }
  public void InsertLast(T no)
  {
    node<T> newn = new node<>(no);
    node<T> temp = null;
    if(first == null && last == null)
    {
      first = newn;
      last = newn;
    }
    else
    {
      last.next = newn;
      last = newn;
      last.next = first;
    }
    iCount++;
  }
  public void InsertAtPos(T no, int pos)
  {
    node<T> temp = null;
    node<T> newn = new node<>(no);
    if(pos <1 || pos > iCount+1)
    {
      System.out.println("Invalid position");
      return;
    }

    if(pos == 1)
    {
      InsertFirst(no);
    }
    else if (pos == iCount +1)
    {
      InsertLast(no);
    }
    else
    {
      temp = first;
      for(int iCnt = 1; iCnt < pos -1;iCnt++)
      {
        temp = temp.next;
      }
      newn.next = temp.next;
      temp.next = newn;
      iCount++;
    }
  }
  public void DeleteFirst()
  {
    if(first == null && last == null)
    {
      return;
    }
    else if(first == last)
    {
      first = null;
      last = null;
    }
    else
    {
      first = first.next;
      last.next = first;
    }
    iCount--;
  }
  public void DeleteLast()
  {
    node<T> temp = first;
    if(first == null && last == null)
    {
      return;
    }
    else if ( last == first)
    {
      first = null;
      last = null;
    }
    else
    {
      while(temp.next != last)
      {
        temp = temp.next;
      }
      last = temp ;
      last.next = first;
    }
    iCount--;
  }
  public void DeleteAtPos(int pos)
  {
    node<T> temp = null;
    if(pos <1 || pos > iCount)
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
      for(int iCnt = 1;iCnt < pos -1;iCnt++)
      {
        temp = temp.next;
      }
      temp.next = temp.next.next;
      iCount--;
    }
  }
}

class SinglyCLL
{
  public static void main(String A[])
  {
    SCLL<Integer> scobj = new SCLL<>();
    scobj.InsertFirst(21);
    scobj.InsertFirst(41);
    scobj.InsertFirst(51);
    scobj.InsertFirst(71);
    scobj.Display();
    scobj.InsertLast(11);

    scobj.Display();
    scobj.InsertAtPos(81, 4);
    scobj.Display();
    // scobj.DeleteFirst();
    // scobj.Display();
    // scobj.DeleteLast();
    // scobj.Display();
    scobj.DeleteAtPos(4);
    scobj.Display();

  }
}