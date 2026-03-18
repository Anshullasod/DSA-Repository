#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
    unordered_map<char, Node *> children;
    bool isend;
    int count;
    Node()
    {
        isend = false;
        count=1;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
        root->count=-1;
    }
    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (!temp->children.count(key[i]))
            {   
                temp->children[key[i]] = new Node();
            }
            else{
            temp->children[key[i]]->count++;}
            temp = temp->children[key[i]];
         
        }
        temp->isend = true;
    }
    bool search(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (!temp->children.count(key[i]))
            {
                return false;
            }
            temp = temp->children[key[i]];
        }
        if (temp->isend)
        {
            return true;
        }
        return false;
    }
};
void helper(Trie t,string key)
{   Node* temp=t.root;
    string ans;
    for(int i=0;i<key.size();i++)
    { ans+=key[i];
      if(temp->children[key[i]]->count==1)
      {
       cout<<ans<<endl;
       return;
      }  
      temp=temp->children[key[i]];
    }
}
void findprefix(Trie t,vector<string> words)
{ 
    for(int i=0;i<words.size();i++)
    {
        helper(t,words[i]);
    }
}
int main()
{   Trie t;
    vector<string> words={"zebra","dog","duck","dove"};
    for(int i=0;i<words.size();i++)
    {
     t.insert(words[i]);
    }
    findprefix(t,words);

}