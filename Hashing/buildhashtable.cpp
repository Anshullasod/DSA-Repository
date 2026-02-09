#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
    int value;
    string key;
    Node *next;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};
class HashTable
{
    int totalsize = 5;
    int cursize;

public:
    Node **table;
    int hashfn(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.size(); i++)
        {
            int val = key[i] - 'A';
            sum += (val * val) % totalsize;
        }
        return sum % totalsize;
    }
    void rehash()
    {
        Node **oldtable = table;
        int oldsize = totalsize;
        totalsize = 2 * totalsize;
        cursize = 0;
        table = new Node *[totalsize];
        for (int i = 0; i < totalsize; i++)
        {
            table[i] = NULL;
        }
        // copy old values
        for (int i = 0; i < oldsize; i++)
        {
            Node *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }
    HashTable(int size)
    {
        totalsize = size;
        cursize = 0;
        table = new Node *[totalsize];
        for (int i = 0; i < totalsize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int val)
    {
        int idx = hashfn(key);
        Node *newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        cursize++;
        double lambda = cursize / (double)totalsize;
        if (lambda > 1)
        {
            rehash(); // Rehashing
        }
    }

    void remove(string key)
    {
        int idx = hashfn(key);
        Node *temp = table[idx];
        if(temp==NULL)
        {
            return;
        }
        if (temp->key == key)
        {
            table[idx] = temp->next;
            return;
        }
        Node *prev = temp;
        while (temp != NULL && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    void print()
    {
        for (int i = 0; i < totalsize; i++)
        {
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << "idx " << i << " Key- " << temp->key << " & value -" << temp->value << endl;
                temp = temp->next;
            }
        }
    }
    void search(string key)
    {
        int idx = hashfn(key);
        Node *temp = table[idx];
        while (temp != NULL && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            cout << temp->value << " ";
        }
    }
};
int main()
{
    HashTable h(3);
    h.insert("INDIA", 150);
    h.insert("HIN", 200);
    h.insert("USA", 100);
    h.insert("RUSSIA", 125);
    h.print();


}