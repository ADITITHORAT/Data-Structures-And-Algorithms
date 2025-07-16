class node
{
  public int data;
  public node next;

  public node()
  {
    this.data = 0;
    this.next = null;
  }
  public node(int no)
  {
    this.data = no;
    this.next = null;
  }

}
class StackX
{
  private node first;
  private int iCount;

  public StackX()
  {
    this.first = null;
    this.iCount = 0;
  }

  public void PushX(int no)
  {
    node newn = new node(no);
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
  public int PopX()
  {
    node temp = null;
    if(first == null)
    {
      System.out.println("Stack is empty");
      return  -1;
    }
    else
    {
      temp = first;
      first = first.next;
      iCount--;
      return  temp.data;
    }
  }
  public void Display()
  {
    node temp = first;
    while(temp != null)
    {
      System.out.println("| "+temp.data+"|");
      temp = temp.next;
    }
  }
  public int Count()
  {
    return  iCount;
  }
  
}

class stack_1
{
  public static void main(String A[])
  {
   StackX sobj = new StackX();
   int iRet = 0,iCnt = 0;
   sobj.PushX(11); 
   sobj.PushX(21); 
   sobj.PushX(31);  
   sobj.Display();
   iCnt = sobj.Count();
   System.out.println(iCnt +" elements in the stack");
   iRet = sobj.PopX();
   System.out.println("deleted :"+iRet+" from stack.");
   sobj.Display();
   iCnt = sobj.Count();
   System.out.println(iCnt +" elements in the stack");
  }
}

