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

void pushTail(int value){
    Node *newNode = createNode(value);
    if(!tail){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
}

void pushHead(int value){
    Node *newNode = createNode(value);
    if(!tail){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
}

void pushPriority(int value){
    Node *newNode = createNode(value);
    Node *curr = head;
    if(!tail){
        head = tail = newNode;
    }else if (head->value > newNode->value) pushHead(newNode->value);
    else if(tail->value < newNode->value) pushTail(newNode->value);
    else{
        while(curr->next->value < newNode->value){
            curr = curr->next;
        }
        newNode->next= curr->next;
        curr->next = newNode;

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

pushPriority(1);
pushPriority(3);
pushPriority(2);
pushPriority(9);
pushPriority(8);
pushPriority(11);
display();
removeQueue();
display();

    return 0;
}