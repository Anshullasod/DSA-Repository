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
    void longesthelper(Node *root, string &ans, string temp)
    {
        for (pair<char, Node *> child : root->children)
        {
            if (child.second->isend)
            {
                temp += child.first;
                if (temp.size() == ans.size() && temp < ans || temp.size() > ans.size())
                {
                    ans = temp;
                }
                longesthelper(child.second, ans, temp);
                temp.pop_back();
            }
        }
        return;
    }
};

string longest(vector<string> words)
{
    Trie t;
    for (int i = 0; i < words.size(); i++)
    {
        t.insert(words[i]);
    }
        string ans;
        t.longesthelper(t.root, ans, "");
        return ans;

}
int main()
{
    vector<string> words = {"banana", "a", "ap", "app", "appl", "apple", "apply"};
    cout << longest(words);
}