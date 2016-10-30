#include <iostream>
#define Nod struct Node
using namespace std;
struct Node{
int data;
struct Node *next;
};
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL) return false;
    Node *slow,*fast;
    slow=head;
    fast=head->next;
    while(fast && fast->next && slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==NULL || fast==NULL) return false;
    else return true;
}

int main(){

Nod *x,*y,*z;
x=new Nod;
y=new Nod;
z=new Nod;
x->data=10;
x->next=y;
y->next=z;
z->next=x;
if(has_cycle(x)) cout<<"1";
else cout<<"0";
return 0;
}
