#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        int customerID;
        string name;
        int tickets;
        Node* next;
        Node(int id,string n,int t){
            customerID=id;
            name=n;
            tickets=t;
            next=NULL;
        }
};

class TicketQueue{
    private:
        Node* front;
        Node* rear;
    public:
        TicketQueue(){
            front=NULL;
            rear=NULL;
        }
        void enqueue(int id,string n,int t){
            Node* newNode=new Node(id,n,t);
            if(rear==NULL){
                front=rear=newNode;
                return;
            }
            rear->next=newNode;
            rear=newNode;
        }
        void dequeue(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* temp=front;
            front=front->next;
            if(front==NULL)rear=NULL;
            delete temp;
        }
        void display(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* temp=front;
            while(temp!=NULL){
                cout<<"Customer ID: "<<temp->customerID<<", Name: "<<temp->name<<", Tickets: "<<temp->tickets<<endl;
                temp=temp->next;
            }
        }
        ~TicketQueue(){
            Node* temp=front;
            while(temp!=NULL){
                Node* next=temp->next;
                delete temp;
                temp=next;
            }
        }
};

int main(){
    TicketQueue q;
    q.enqueue(1,"Ali",2);
    q.enqueue(2,"Sara",4);
    q.enqueue(3,"Ahmed",3);
    cout<<"Current Queue:"<<endl;
    q.display();
    cout<<"After serving one customer:"<<endl;
    q.dequeue();
    q.display();
    return 0;
}
