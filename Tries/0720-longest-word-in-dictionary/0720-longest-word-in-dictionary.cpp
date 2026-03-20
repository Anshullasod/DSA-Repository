class Node{
    public:
    unordered_map<char,Node*> children;
    bool isend;
    Node()
    {
        isend=false;
    }
};
class Tries
{
    public:
    Node* root;
    Tries()
    {
      root=new Node();
    }
    void insert(string key)
    {   Node* temp=root;
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
class Solution {
public:
    void longest(Node* root,string &ans,string temp)
    {
        for(pair<char,Node*> child:root->children)
        {   
            if(child.second->isend)
            {
              temp+=child.first;
              if(temp.size()==ans.size()&&temp<ans||temp.size()>ans.size())
              {
                ans=temp;
              }
              longest(child.second,ans,temp);
              temp.pop_back();
            }

        }
        return;
    }
    string longestWord(vector<string>& words) {
        Tries t;
        for(int i=0;i<words.size();i++)
        {
          t.insert(words[i]);
        }
        string ans;
        longest(t.root,ans,"");
        return ans;
    }
};