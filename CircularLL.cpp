#include<iostream>
using namespace std;

class Node{
public: 
    int data;
    Node *next;
};

class CLL{

public:
//CLL(int A[], int n);

    Node * head=NULL;
    void insert(int pos, int x);
    void insert2(int x);
    void display();
    int length();

};

/*
CLL::CLL(int *A, int n) {
 
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
*/
int CLL::length(){
    Node *p=head;
    int len=0;
    if(head==NULL){
        return 0;
    }else{
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
    }
}


void CLL::insert(int pos, int x){
    Node *p=head;
    Node* temp;
    if(pos<0 || pos>length()){
        cout<<"\nInvalid position\n";
        return;
    }

    if(pos==0){     //BEGIN INSERTING BEFORE HEAD
        temp=new Node();
        temp->data=x; 
        
        if(head==NULL){
            head=temp;
            head->next=head;
        }else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=temp;
            temp->next=head;
            head=temp;
        }
    }//END INSERTING BEFORE HEAD
    else{// IF POS!=0 
        
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        temp=new Node();
        temp->data=x;
        temp->next=p->next;
        p->next=temp;
    }
}

void CLL::insert2(int x){
        Node *p=head;
        Node *temp;
        temp=new Node();
        temp->data=x; 
        
        if(head==NULL){
            head=temp;
            head->next=head;
        }else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=temp;
            temp->next=head;
            //head=temp;
        }
}

void CLL::display(){
    Node*p=head;
    if(head==NULL){
        cout<<"list is empty";
    }else{
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=head);
}
    
}

int main(){

    int A[] = {1, 3, 5, 7, 9,11};
    //CLL cl(A, sizeof(A)/sizeof(A[0]));
    CLL cl;
    cl.insert(0,222);
    cl.insert(1,333);
    cl.insert2(1000);
    cl.insert2(2000);
    cl.display();
    int l=cl.length();
    cout<<"\nlength="<<l<<endl;
}