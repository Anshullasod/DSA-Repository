#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
class Node{
    public:
    bool isend;
    unordered_map<char,Node*> children;
    Node()
    {
        isend=false;
    }
};
class Trie{
    public:
    Node* root;
    Trie()
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
    bool search(string key)
    {   Node* temp=root;
        for(int i=0;i<key.size();i++)
        {
            if(!temp->children.count(key[i]))
            {   cout<<"Not present"<<endl;
                return false;}
            temp=temp->children[key[i]];    
        }
        if(temp->isend)
        {
            cout<<"present"<<endl;
            return true;
        }
        cout<<"Not present"<<endl;
                return false;
    }
};
int main()
{
  vector<string> words={"the","a","there","their","any","thee"};
  Trie t;
  for(int i=0;i<words.size();i++)
  {
    t.insert(words[i]);
  }
  t.search("their");
  t.search("anshul");
}