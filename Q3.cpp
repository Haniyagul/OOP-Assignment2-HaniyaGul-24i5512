#include<iostream>
using namespace std;

class node{
    public:
        int bookID;
        string title;
        string author;
        node* next;
        node* prev;
        node(int id,string t,string a){
            bookID=id;
            title=t;
            author=a;
            next=NULL;
            prev=NULL;
        }
};

class doublyLinkedList{
    private:
        node* head;
    public:
        doublyLinkedList(){head=NULL;}
        void addAtBeginning(int id,string t,string a){
            node* newNode=new node(id,t,a);
            if(head==NULL){head=newNode;return;}
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        void addAtEnd(int id,string t,string a){
            node* newNode=new node(id,t,a);
            if(head==NULL){head=newNode;return;}
            node* temp=head;
            while(temp->next!=NULL){temp=temp->next;}
            temp->next=newNode;
            newNode->prev=temp;
        }
        void addAtPosition(int pos,int id,string t,string a){
            if(pos<=1){addAtBeginning(id,t,a);return;}
            node* temp=head;
            for(int i=1;i<pos-1&&temp!=NULL;i++){temp=temp->next;}
            if(temp==NULL){addAtEnd(id,t,a);return;}
            node* newNode=new node(id,t,a);
            newNode->next=temp->next;
            newNode->prev=temp;
            if(temp->next!=NULL)temp->next->prev=newNode;
            temp->next=newNode;
        }
        void deleteByID(int id){
            if(head==NULL)return;
            if(head->bookID==id){
                node* temp=head;
                head=head->next;
                if(head!=NULL)head->prev=NULL;
                delete temp;
                return;
            }
            node* temp=head;
            while(temp!=NULL&&temp->bookID!=id){temp=temp->next;}
            if(temp==NULL)return;
            if(temp->prev!=NULL)temp->prev->next=temp->next;
            if(temp->next!=NULL)temp->next->prev=temp->prev;
            delete temp;
        }
        void displayForward(){
            node* temp=head;
            while(temp!=NULL){
                cout<<"BookID: "<<temp->bookID<<", Title: "<<temp->title<<", Author: "<<temp->author<<endl;
                temp=temp->next;
            }
        }
        void displayReverse(){
            if(head==NULL)return;
            node* temp=head;
            while(temp->next!=NULL){temp=temp->next;}
            while(temp!=NULL){
                cout<<"BookID: "<<temp->bookID<<", Title: "<<temp->title<<", Author: "<<temp->author<<endl;
                temp=temp->prev;
            }
        }
        ~doublyLinkedList(){
            node* temp=head;
            while(temp!=NULL){
                node* next=temp->next;
                delete temp;
                temp=next;
            }
        }
};

int main(){
    doublyLinkedList list;
    list.addAtEnd(1,"The Alchemist","Paulo Coelho");
    list.addAtEnd(2,"1984","George Orwell");
    list.addAtBeginning(3,"Sapiens","Yuval Noah Harari");
    list.addAtPosition(2,4,"To Kill a Mockingbird","Harper Lee");
    cout<<"Books in order:"<<endl;
    list.displayForward();
    cout<<"After deleting ID 2:"<<endl;
    list.deleteByID(2);
    list.displayForward();
    cout<<"Books in reverse order:"<<endl;
    list.displayReverse();
}
