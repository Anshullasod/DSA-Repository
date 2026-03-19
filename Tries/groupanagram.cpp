#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Node
{
public:
    unordered_map<char, Node *> children;
    bool isend;
    vector<string> anagram;
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
    void insert(string key,string original)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {   if(!temp->children.count(key[i]))
            {temp->children[key[i]]=new Node();}
            temp=temp->children[key[i]];
        }
        temp->isend=true;
        temp->anagram.push_back(original);
    } 
    void dfs(Node* temp,vector<vector<string>> &result)
    {
        if(temp==NULL)
        {
            return;
        }
        if(temp->isend)
        {
            result.push_back(temp->anagram);
            for(int i=0;i<temp->anagram.size();i++)
            {
                cout<<temp->anagram[i]<<" ";
            }
            cout<<endl;
        }
        for(auto it:temp->children)
        {
            dfs(it.second,result);
        }
    }
};
void findanagram(vector<string> words)
{Trie t;
 for(int i=0;i<words.size();i++)
 {
    string temp=words[i];
    sort(temp.begin(),temp.end());
    t.insert(temp,words[i]);
 }
 vector<vector<string>> result;
 t.dfs(t.root,result);

 return;

}
int main()
{
    vector<string> words={"a"};
    findanagram(words);
}