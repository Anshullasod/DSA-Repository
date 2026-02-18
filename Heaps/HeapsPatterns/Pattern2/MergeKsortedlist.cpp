#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int val;
  Node* next;
  Node(int val)
  {
    this->val=val;
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
  void push_front(int val)
  { Node* newNode=new Node(val);
    if(head==NULL)
    { 
      head=newNode=tail;
      return;
    }
    newNode->next=head;
    head=newNode;
    return;
  }
  void push_back(int val)
  { Node* newNode=new Node(val);
    if(head==NULL)
    {
      head=tail=newNode;
      return;
    }
    tail->next=newNode;
    tail=newNode;
   }
  void print()
  {
    Node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->val<<"->";
      temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return;
  }

};
struct compare{
  bool operator()(pair<Node*,int> a,pair<Node*,int> b)
  {
    return a.first->val>b.first->val;
  }
};
Node* mergeKlist(vector<Node*> listnode)
{
  priority_queue<pair<Node*,int>,vector<pair<Node*,int>>,compare> pq;
  for(int i=0;i<listnode.size();i++)
  { if(listnode[i]!=NULL)
    {pq.push({listnode[i],i});}
  }
  List ans;
  while(!pq.empty())
  {
   pair<Node*,int> curr=pq.top();
   pq.pop();
   ans.push_back(curr.first->val);
   if(curr.first->next!=NULL)
   {
    pq.push({curr.first->next,curr.second});
   }
  }
  ans.print();
  return ans.head;
}
int main()
{
  List l1;
  l1.push_back(1);
  l1.push_back(4);
  l1.push_back(5);
  List l2;
  l2.push_back(1);
  l2.push_back(2);
  l2.push_back(4);
  List l3;
  l3.push_back(2);
  l3.push_back(6);
  vector<Node*> listnode={l1.head,l2.head,l3.head};
  mergeKlist(listnode);


}