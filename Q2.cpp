#include<iostream>
using namespace std;

class feature{
    protected:
        string name;
    public:
        feature(string name){this->name=name;}
        virtual void analyze()=0;
        virtual ~feature(){}
};

class landFeature: public feature{
    public:
        landFeature(string name):feature(name){}
        void analyze(){cout<<name<<" land feature detected"<<endl;}
};

class waterFeature: public feature{
    public:
        waterFeature(string name):feature(name){}
        void analyze(){cout<<name<<" water feature detected"<<endl;}
};

class node{
    public:
        int featureID;
        feature* f;
        node* next;
        node(int id,feature* f){this->featureID=id;this->f=f;next=NULL;}
        ~node(){delete f;}
};

class singlyLinkedList{
    private:
        node* head;
    public:
        singlyLinkedList(){head=NULL;}
        void insertAtEnd(int featureID,feature* f){
            node* newNode=new node(featureID,f);
            if(head==NULL){head=newNode;return;}
            node* temp=head;
            while(temp->next!=NULL){temp=temp->next;}
            temp->next=newNode;
        }
        void deleteByID(int featureID){
            if(head==NULL)return;
            if(head->featureID==featureID){
                node* temp=head;
                head=head->next;
                delete temp;
                return;
            }
            node* prev=NULL;
            node* curr=head;
            while(curr!=NULL&&curr->featureID!=featureID){
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL)return;
            prev->next=curr->next;
            delete curr;
        }
        void displayAll(){
            node* temp=head;
            while(temp!=NULL){
                cout<<"Feature ID: "<<temp->featureID<<" -> ";
                temp->f->analyze();
                temp=temp->next;
            }
        }
        void reverseList(){
            node* prev=NULL;
            node* curr=head;
            node* next=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head=prev;
        }
        ~singlyLinkedList(){
            node* temp=head;
            while(temp!=NULL){
                node* next=temp->next;
                delete temp;
                temp=next;
            }
        }
};

int main(){
    singlyLinkedList list;
    list.insertAtEnd(1,new landFeature("Forest"));
    list.insertAtEnd(2,new waterFeature("River"));
    list.insertAtEnd(3,new landFeature("Mountain"));
    list.insertAtEnd(4,new waterFeature("Ocean"));
    cout<<"All features:"<<endl;
    list.displayAll();
    cout<<"After deleting ID 2:"<<endl;
    list.deleteByID(2);
    list.displayAll();
    cout<<"After reversing:"<<endl;
    list.reverseList();
    list.displayAll();
}
