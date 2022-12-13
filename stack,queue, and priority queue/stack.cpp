#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next, *prev;
}*end = NULL, *start = NULL;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

void insertStack(int value){
    Node *newNode = createNode(value);
    if(!end){
        end = start = newNode;
    }else{
        end->next = newNode;
        newNode->prev = end;
        end = end->next;
    }
}

void removeStack(){
    if(!end){
        return;
    }else if(!end->prev){
        free(end);
    }else{
        Node *curr = end->prev;
        end->prev = curr->next = NULL;
        free(end);
        end = curr;
    }
}

void display(){
    Node *curr = start;
    while(curr){
        printf(" -> %d", curr->value);
        curr = curr->next;
    } puts("");
}

int main (){
    insertStack(1);
    insertStack(6);
    insertStack(8);
    display();
    removeStack();
    display();

    return 0;
}