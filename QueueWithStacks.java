class MyQueue {

    Stack<Integer> ip = new Stack<>();
    Stack<Integer> op = new Stack<>();
    public MyQueue() {
        
    }
    
    public void push(int x)
    {
        while(!ip.isEmpty())
        {
            op.push(ip.pop());
        } 
        ip.push(x);
         while(!op.isEmpty())
         {
            ip.push(op.pop());
         }
        
    }
    
    public int pop() {
        return ip.pop();
    }
    
    public int peek() {
        return ip.peek();
    }
    
    public boolean empty() {
        
        return ip.isEmpty();
        
    }
}
