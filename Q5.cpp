#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(char d){data=d;next=NULL;}
};

class LinkedListStack{
    private:
        Node* top;
    public:
        LinkedListStack(){top=NULL;}
        void push(char c){
            Node* newNode=new Node(c);
            newNode->next=top;
            top=newNode;
        }
        void pop(){
            if(top==NULL)return;
            Node* temp=top;
            top=top->next;
            delete temp;
        }
        bool isEmpty(){
            return top==NULL;
        }
        char peek(){
            if(top==NULL)return '\0';
            return top->data;
        }
        ~LinkedListStack(){
            while(!isEmpty())pop();
        }
};

class ArrayStack{
    private:
        char* arr;
        int top;
        int capacity;
    public:
        ArrayStack(int size){
            capacity=size;
            arr=new char[capacity];
            top=-1;
        }
        void push(char c){
            if(top==capacity-1)return;
            arr[++top]=c;
        }
        void pop(){
            if(top==-1)return;
            top--;
        }
        bool isEmpty(){
            return top==-1;
        }
        char peek(){
            if(top==-1)return '\0';
            return arr[top];
        }
        ~ArrayStack(){
            delete[] arr;
        }
};

void iterativeReverse(char* arr,int b1,int b2){
    ArrayStack s(b2-b1+1);
    for(int i=b1;i<=b2;i++)s.push(arr[i]);
    for(int i=b1;i<=b2;i++){arr[i]=s.peek();s.pop();}
}

void iterativeReverseLL(char* arr,int b1,int b2){
    LinkedListStack s;
    for(int i=b1;i<=b2;i++)s.push(arr[i]);
    for(int i=b1;i<=b2;i++){arr[i]=s.peek();s.pop();}
}

int main(){
    char arr1[8]={'C','O','M','P','U','T','E','R'};
    char arr2[8]={'C','O','M','P','U','T','E','R'};

    cout<<"Original Array: ";
    for(int i=0;i<8;i++)cout<<arr1[i]<<" ";
    cout<<endl;

    iterativeReverse(arr1,2,5);
    cout<<"After Iterative Reverse (Array Stack): ";
    for(int i=0;i<8;i++)cout<<arr1[i]<<" ";
    cout<<endl;

    iterativeReverseLL(arr2,2,5);
    cout<<"After Iterative Reverse (Linked List Stack): ";
    for(int i=0;i<8;i++)cout<<arr2[i]<<" ";
    cout<<endl;

    cout<<endl<<"Algorithm Analysis:"<<endl;
    cout<<"Array-based stack:"<<endl;
    cout<<"Push and pop operations are O(1) in average case but may require resizing if capacity is exceeded."<<endl;
    cout<<"Memory is contiguous and faster for access but limited by initial capacity."<<endl;
    cout<<"Linked list-based stack:"<<endl;
    cout<<"Push and pop operations are always O(1)."<<endl;
    cout<<"No size limit but memory allocation overhead is higher due to node creation."<<endl;
    cout<<"Overall, array stack is faster in small, fixed-size operations, while linked list stack is more flexible for dynamic use."<<endl;

    return 0;
}
