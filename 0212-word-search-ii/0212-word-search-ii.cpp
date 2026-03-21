class Node {
public:
    unordered_map<char, Node*> children;
    bool isend;
    Node() { isend = false; }
};
class Tries {
public:
    Node* root;
    Tries() { root = new Node(); }
    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->isend = true;
    }
};
class Solution {
public:
    void helper(Node* temp,vector<vector<char>> &board,int row,int col,string &ans,vector<string> &result)
{
  if(row<0||row>=board.size()||col<0||col>=board[0].size())
  {
    return ;
  }
  if(board[row][col]=='#'||!temp->children.count(board[row][col]))
  {
    return ;
  }
  char ch=board[row][col];
  temp=temp->children[ch];
  board[row][col]='#';
  ans+=ch;
  if(temp->isend)
  { result.push_back(ans);
    temp->isend=false;
   }

  helper(temp,board,row,col+1,ans,result);
  helper(temp,board,row,col-1,ans,result);
  helper(temp,board,row+1,col,ans,result);
  helper(temp,board,row-1,col,ans,result);
  board[row][col]=ch;
  ans.pop_back();
  return ;
  
}
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Tries t;
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i]);
        }
        string ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                helper(t.root, board, i, j, ans, result);
            }
        }
        return result;
    }
};