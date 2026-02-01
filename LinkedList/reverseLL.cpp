#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void push_back(int val)
    {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    void pop_back()
    {
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void reverse()
{
    Node* prev=NULL;
    Node* curr=head;
    Node* curnext;
    tail=head;
    while(curr!=NULL)
    { curnext=curr->next;
      curr->next=prev;
      prev=curr;
      curr=curnext;
    }
    head=prev;
}
};

int main()
{
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    cout<<l1.head->data<<" "<<l1.tail->data<<endl;
    l1.reverse();
    cout<<l1.head->data<<" "<<l1.tail->data<<endl;
}