#include <bits/stdc++.h>
using namespace std;

class Node  //NODE STRUCTURE
{
public:
    int data;
    Node *next;
};

class LL
{
public:
    Node *head = NULL; //declare head in public so all the functions can access to the head of the list
    void create(int arr[], int n); //CREATE A LINKED LIST FROM AN ARRAY
    void display();                //DISPLAY LINKED LIST
    int count();
    void insert(int x, int pos, int count); //INSERT ELEMENTS AT ANY POSITION(CAN ALSO BE USED TO CREATE A NEW LINKED LIST)
    void del(int x);                        //DELETE AN ELEMENT FROM LIST
    void delPos(int pos,int c); //DELETE THE NODE ACCORDING TO POSITION
    void append(int x); //APPEND A LINKED LIST (CAN BE STARTED FROM SCRATCH)
    void begin(int x); //ADD ELEMENT AT THE BEGINING
    void max();
    void min();
    void reverse();
    void sort();
    void swap(Node *p1, Node*p2);
};

void LL::create(int arr[], int n)
{
    head = new Node(); //allocation of head node in HEAP storage
    Node *last = NULL; //declaration and initialization of last node
    Node *temp = NULL; //declaration and initialization of temporary node.. data will be inserted into temp node always.

    head->data = arr[0]; //store the first element of array in the head node
    head->next = NULL;   //head's next pointer should be null  (this will be edited later in this function only)
    last = head;         //the first and last(head and last) nodes should be the same

    for (int i = 1; i < n; i++)
    {                        //start filling the data in linked list
        temp = new Node();   //allocation of temp node in HEAP STORAGE
        temp->data = arr[i]; //arr[i] will be stored in temp->data
        temp->next = NULL;   //this represents the creation of single temp node
        last->next = temp;   //now the last->next should point to temp node (in the first iteration, last=head will change to last=temp)
        last = temp;
    }
}

void LL::display()
{
    Node *p = head; //declare a p node and initialize it with HEAD node value
    while (p != NULL)
    {                            //until the p->next becomes null, this loop should continue
        cout << p->data << endl; //data of each node is printed
        p = p->next;             //p is incremented
    }
}

int LL::count()
{ //same as display, only counter is incremented with each iteration
    Node *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void LL::insert(int x, int pos, int count)
{

    Node *p = head;  //allocation of head node in HEAP storage
    if (pos < 0 || pos > count)
    {               //position should not be outside the range of list
        cout << "Invalid position" << endl;
    }

    else
    {                   //The procedure will be similar to CREATE() function
        Node *t = NULL; //create a temp node
        t = new Node(); //allocate space in HEAP
        t->data = x;    //element to be inserted is assigned to t->data
        t->next = NULL; //makes sure that temp node is singular

        if (pos == 0)
        {                   //if the position is before the HEAD node
            t->next = head; //t's next should point to the address of HEAD node
            head = t;       //the temp node is now the HEAD NODE
        }
        else
        {                    //if position is after the head node anywhere in the list
            for (int i = 0; i < pos - 1; i++)   
            {
                p = p->next;        //take the pointer p to the position-1 node in the list(THIS p started from HEAD node)
            }
            t->next = p->next;  //#1now store the address of p's next node in the singular temp node
            p->next = t;        //#2replace p's next node's address by the temp node's address
        }                       // step #1 and #2 is used to insert a temp node in between two nodes
    }
}

void LL::del(int x)     //for deletion u require two nodes. PREV node to store/point the address of the iterating CURRENT node and
{                       //CURRENT node detects/finds the node to be deleted.(or CURRENT node is the node to be deleted)
    Node *current = head;   //store/point the head node in current node
    Node *prev = NULL;      //prev is declared and initialized to NULL or HEAD
                            //THE CURRENT NODE WILL ALWAYS BE +1 MORE THAN PREV NODE
    int flag=0; //if element is not found till the end of the list, flag will be 0 only
    while (current->next != NULL)   //Iterate throughout the list
    {
        prev = current;         //store the current node into prev
        current = current->next;    //increment the current node.. this does not increment the PREV node, so PREV=position-1,while current=position
        if (current->data == x) //if the element to be deleted is found
        {
            cout << "\nfound\n";    //now position of the node to be deleted =CURRENT NODE
            prev->next = current->next; //prev holded the address of the node to be deleted(CURRENT) so replace it with the address of CURRENT's next node in the list.
            delete (current);   //disallocate the memory allocated to the node to be deleted
            cout << "\n deleted\n";
            flag=1;         //set flag=1 after successful operation
            break;//come out of the while loop after the node is deleted.
        }
    }
    if(flag==0){
        cout<<"\nELEMENT NOT FOUND\n";
    }                           

}

void LL::delPos(int pos,int c){ //c=count of list
    Node* current=head;     
    Node* prev=head; //THE CURRENT NODE WILL ALWAYS BE +1 MORE THAN PREV NODE
    if(pos>0 && pos<=c){
    for(int i =0;i<pos-1;i++){ //iterate upto position
        prev=current;           //store the current node into prev
        current=current->next; //increment the current node.. this does not increment the PREV node, so PREV=position-1,while current=position to be deleted
    }
    prev->next=current->next;
    delete(current);
    cout<<"\nNode successfully deleted\n";
    }else{
        cout<<"\nInvalid position\n";
    }

}

void LL::append(int x){
    Node *temp=NULL;
    temp=new Node();
    Node *last=head;

    temp->data=x;
    temp->next=NULL;

    if(head==NULL){
        head=temp;
        return;
    }
    while (last->next!=NULL)
    {
        last=last->next;
    }
    last->next=temp;
}

void LL::begin(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
}

void LL::max(){
    Node*p=head;
    int mx=p->data;
    while(p!=NULL){
        if(p->data>mx){
            mx=p->data;
        }
        p=p->next;
    }
    cout<<"\nMax element="<<mx<<endl;
}
void LL::min(){
    Node*p=head;
    int mn=p->data;
    while (p!=NULL)
    {
        if(p->data<mn){
            mn=p->data;
        }
        p=p->next;
    }
    cout<<"\nMin element="<<mn<<endl;
}

void LL::reverse(){

    cout<<"\nREVERSED LIST: \n";
    Node*p=head;
    Node *q=NULL;
    Node *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;

}



void LL::swap(Node *p1, Node*p2){
    int temp=p2->data;
    p2->data=p1->data;
    p1->data=temp;
    
}

void LL::sort(){
    cout<<"\nSORTED LIST:\n";
    Node *p;
    //Node *q=NULL;
    int swapped;
    do{
        p=head;
        swapped=0;
        while (p->next!=NULL)
        {
            if(p->data > p->next->data){
                swap(p,p->next);
                swapped=1;
            }
            p=p->next;
        }
    }while(swapped);
}


 int main()
{
    int arr[] = {1, 2, 4, 6, 3, 7, 9999, 8};
    int n = sizeof(arr) / sizeof(int);

    LL list;
    //list.create(arr, n);
    list.begin(420);
    list.append(2555);
    list.append(9837);
    list.append(2234);
    list.append(6666);
    list.append(9012);
    list.append(18272);
    list.append(9999);
    list.append(69);

    list.display();
    int c = list.count();
    cout << "count=" << c << endl;
    list.insert(1000, 0, c);
    list.display();

    c = list.count();
    cout << "New count=" << c << endl;

    list.del(9999);
    cout << "\nlist after deleting:\n";
    list.display();
    c = list.count();
    cout << "Count After deletion=" << c << endl;

    list.delPos(5, c); //i.e. element 6 should be deleted;
    list.display();
    c = list.count();
    cout << "Count After delPos=" << c << endl;

    list.append(25555);
    list.begin(6969);
    list.display();
    list.max();
    list.min();
    
    list.reverse();
    list.display();
    

    list.sort();
    list.display();



}