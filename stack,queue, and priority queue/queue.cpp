#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next;
}*head = NULL, *tail = NULL;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void insertNode(int value){
    Node *newNode = createNode(value);
    if(!tail){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
}

void removeQueue(){
    Node *curr = head->next;
    head->next=NULL;
    free(head);
    head = curr;
}

void display(){
    Node *curr = head;
    while(curr){
        printf(" -> %d", curr->value);
        curr = curr->next;
    }
    puts("");
}

int main(){

insertNode(1);
insertNode(2);
insertNode(3);
display();
removeQueue();
display();

    return 0;
}