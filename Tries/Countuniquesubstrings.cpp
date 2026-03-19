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
int findheight(Node* root)
{
 int ans=0;
 for(pair<char,Node*> child:root->children)
 {
    ans+=findheight(child.second);
 }
 return ans+1;
}
int countunique(string key)
{
 vector<string> words;
 for(int i=0;i<key.size();i++)
 {
    words.push_back(key.substr(i));
 }
 Trie tries;
 for(int i=0;i<words.size();i++)
 {
    tries.insert(words[i]);
 }
 cout<<findheight(tries.root);
 return 0;
}
int main()
{   
    string key="ababa";
    countunique(key);
  
}