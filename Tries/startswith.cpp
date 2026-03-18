#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
    bool isend;
    unordered_map<char, Node *> children;
    Node()
    {
        isend = false;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
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
bool startswith(Trie t,string key)
{   Node* temp=t.root;
    for(int i=0;i<key.size();i++)
    {
      if(!temp->children.count(key[i]))
      {
        return false;
      }  
      temp=temp->children[key[i]];
    }
    return true;
}
int main()
{   Trie t;
    vector<string> words = {"apple","app","mango","man","woman"};
    for(int i=0;i<words.size();i++)
    {
     t.insert(words[i]);
    }
    cout<<startswith(t,"wom");
}