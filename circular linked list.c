#include<stdio.h>
#include<stdlib.h>
// step 1:structure of node
struct node{
int data;
struct node*next;
};
//step 2:define head and tail
struct node*head=NULL;
struct node*tail=NULL;
//enqueue (insert at rear)
void enqueue(int value){
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=value;
temp->next=NULL;
//case 1: empty queue
if(head==NULL && tail==NULL){
head=tail=temp;
tail->next=head; //circular link
}
else{
tail->next=temp;
tail=temp;
tail->next=head; //maintain circular link
}
printf("%d inserted\n",value);
}
//dequeue (delete from front)
void dequeue(){
if (head==NULL && tail==NULL){
printf("queue is empty\n");
return;
}
struct node*temp=head;
//case:only one node
if(head==tail){
printf("%d deleted\n",temp->data);
head=tail=NULL;
free(temp);
}
else{
head=head->next;
tail->next=head; //maintain circular link
free(temp);
}
}
// display
void display(){
if (head==NULL && tail==NULL){
printf("queue is empty\n");
return;
}
struct node*current=head;
printf("queue:");
//print all nodes
do{
printf("%d",current->data);
current=current->next;
}while(current!=head);
printf("\n");
}
//main function
int main(){
//enqueue elements
enqueue(10);
enqueue(20);
enqueue(30);
display();
//dequeue elements
dequeue();
display();
dequeue();
display();
dequeue();
display();
return 0;
}
