#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
  public:
  unordered_map<char,Node*> children;
  bool isend;
  Node()
  {
    isend=false;
  }
};
class Tries{
  public:
  Node* root;
  Tries()
  {
    root=new Node();
  }
  void insert(string key)
  { Node* temp=root;
    for(int i=0;i<key.size();i++)
    {
      if(!temp->children.count(key[i]))
      {
        temp->children[key[i]]=new Node();
      }
      temp=temp->children[key[i]];
    }
    temp->isend=true;
  }
};
bool findword(Node* temp,vector<vector<char>> &board,int row,int col,string ans)
{
  if(row<0||row>board.size()||col<0||col>board[0].size()||board[row][col]=='#')
  {
    return false;
  }
  if(!temp->children.count(board[row][col]))
  {
    return false;
  }
  char ch=board[row][col];
  temp=temp->children[ch];
  board[row][col]='#';
  ans+=ch;
  if(temp->isend)
  { cout<<ans<<endl;
    temp->isend=false;
   }

  findword(temp,board,row,col+1,ans);
  findword(temp,board,row,col-1,ans);
  findword(temp,board,row+1,col,ans);
  findword(temp,board,row-1,col,ans);
  board[row][col]=ch;
  ans.pop_back();
  return true;
  
}
void wordsearch(vector<vector<char>> &board,vector<string> &words)
{ 
  Tries t;
  for(int i=0;i<words.size();i++)
  {
    t.insert(words[i]);
  }
  string ans;
  for(int i=0;i<board.size();i++)
  {
    for(int j=0;j<board[0].size();j++)
    {
      findword(t.root,board,i,j,ans);
    }
  }

}
int main()
{
  vector<vector<char>> board={{'o','a','a','n'},
                              {'e','t','a','e'},
                              {'i','h','k','r'},
                              {'i','f','l','v'}};
  vector<string> words={"eat","oath","pea","rain"};                   
  wordsearch(board,words);
}