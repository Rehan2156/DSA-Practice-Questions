class Solution {
    for row in range(x):
        if arr[row][y] == 1:
            return False
    row=x
    col=y
    while row >= 0 and col >= 0:
        if arr[row][col] == 1:
            return False
        row=row-1
        col=col-1
    row=x
    col=y
    while row >= 0 and col < n:
        if arr[row][col] == 1:
            return False
        row=row-1
        col=col+1          
    return True
  public boolean isSafe(char arr[],int x, int y, int n)
  {
          for(int row=0;row<n;row++)
          {
              if(arr[row][y]=='Q')
                  return false;
          }
                int row=x;
                int col=y;
                
                while(row>=0 && col>=0)
                {
                    if(arr[row][col]=='Q')
                    {
                       return false;       
                    }
                    row--;
                    col--;
                    
                }
                 int row=x;
                int col=y;
                
                while(row>=0 && col<n)
                {
                    if(arr[row][col]=='Q')
                    {
                       return false;       
                    }
                    row--;
                    col++;
                    
                }
                return true;
  }
    
    
    public boolean nQueen(char arr[],int x,int n)
    {
       if(x>=n){
           return True;
       }       
       for(int col=0;col<n;col++){
           
           if(isSafe(arr,x,col,n))
           {
               arr[x][col]='Q'; 
               if(nQueen(arr,x+1,n)){
                   return true;
               }
               arr[x][col]='.'; 
           }
       }            
    }
    public void solveNQueens(int n) 
    {
        char[][] arr = new char[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j]='.';
        nQueen(arr,0,n);
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(arr[i][j]);
            System.out.println();
          }
    }
}
