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
bool helper(string key, Trie t)
{
    if (key.size() == 0)
    {
        return true;
    }
    for (int i = 0; i < key.size(); i++)
    {
        string first = key.substr(0, i + 1);
        string second = key.substr(i + 1);
        if (t.search(first) && helper(second, t))
        {
            return true;
        }
    }
    return false;
}
bool wordbreak(vector<string> words, string key)
{
    Trie t;
    for (int i = 0; i < words.size(); i++)
    {
        t.insert(words[i]);
    }
    cout<<helper(key,t);
}
int main()
{
    vector<string> words = {"i", "like", "sam", "samsung", "mobile", "ice"};
    wordbreak(words,"ilikesung");
}