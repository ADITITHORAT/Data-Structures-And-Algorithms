class node<T>
{
  public T data;
  public node<T> next;

  public node()
  {
    this.data = data;
    this.next = null;
  }
  public node(T no)
  {
    this.data = no;
    this.next = null;
  }

}
class StackX<T>
{
  private node<T> first;
  private int iCount;

  public StackX()
  {
    this.first = null;
    this.iCount = 0;
  }

  public void PushX(T no)
  {
    node<T> newn = new node<>(no);
    if(this.first == null)
    {
      this.first = newn;
    }
    else
    {
      newn.next = this.first;
      this.first = newn;
      
    }
    this.iCount++;
  }
  public T PopX()
  {
    node<T> temp = null;
    if(this.first == null)
    {
      System.out.println("Stack is empty");
      return  null;
    }
    else
    {
      temp = this.first;
      this.first = this.first.next;
      this.iCount--;
      return  temp.data;
    }
  }
  public void Display()
  {
    node<T> temp = this.first;
    while(temp != null)
    {
      System.out.println("| "+temp.data+"|");
      temp = temp.next;
    }
  }
  public int Count()
  {
    return  this.iCount;
  }
  
}

class stack_gen
{
  public static void main(String A[])
  {
   StackX<Double> sobj = new StackX<>();
   double dRet = 0.0;
   int iCnt = 0;
   sobj.PushX(11.11); 
   sobj.PushX(21.21); 
   sobj.PushX(31.31);  
   sobj.Display();
   iCnt = sobj.Count();
   System.out.println(iCnt +" elements in the stack");
   dRet = sobj.PopX();
   System.out.println("deleted :"+dRet+" from stack.");
   sobj.Display();
   iCnt = sobj.Count();
   System.out.println(iCnt +" elements in the stack");
  }
}


