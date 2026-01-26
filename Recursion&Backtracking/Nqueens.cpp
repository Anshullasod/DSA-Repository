#include<iostream>
using namespace std;
#include<vector>
#include<string>
void print(vector<vector<char>> board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool issafe(vector<vector<char>> &board,int row,int col,int n)
{
  for(int i=row;i>=0;i--)
  {
    if(board[i][col]=='Q')
    {
        return false;
    }
  }
  for(int j=col;j>=0;j--)
  {
    if(board[row][j]=='Q')
    {
        return false;
    }
  }
  for(int i=row,j=col;i>=0&&j>=0;i--,j--)
  {
    if(board[i][j]=='Q')
    {
        return false;
    }
  }
    
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
  {
    if(board[i][j]=='Q')
    {
        return false;
    }
  }
  return true;
}
void nqueens(vector<vector<char>> &board,int n,int col)
{
    if(col==n)
    {
        print(board,n);
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(issafe(board,i,col,n))
        {
            board[i][col]='Q';
            nqueens(board,n,col+1);
            board[i][col]='.';
        }}}
int main()
{
  vector<vector<char>> board;
  int n=4;
  for(int i=0;i<4;i++)
  {
    vector<char> temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back('.');
    }
    board.push_back(temp);
  }
  print(board,4);
  nqueens(board,4,0);
}