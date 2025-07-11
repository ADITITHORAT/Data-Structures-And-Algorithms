class node
{
  public int data;
  public node next;
  
  public node()
  {
    data = 0;
    next = null;
  }

  public node(int no)
  {
    data = no;
    next = null;
  }
}


class SCLL
{
  private int iCount ;
  private node first;
  private node last;

  public SCLL()
  {
    iCount = 0;
    first = null;
    last = null;
  }

  public void Display()
  { node temp = null;
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
  public void InsertFirst(int no)
  {
    node newn = new node(no);
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
  public void InsertLast(int no)
  {
    node newn = new node(no);
    node temp = null;
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
  public void InsertAtPos(int no, int pos)
  {
    node temp = null;
    node newn = new node(no);
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
    node temp = first;
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
    node temp = null;
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
    SCLL scobj = new SCLL();
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