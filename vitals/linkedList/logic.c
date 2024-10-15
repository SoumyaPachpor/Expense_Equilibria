#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>
void init(Transaction **head){
    *head = NULL;

}
Transaction *createTransaction(int amount, char* name, int to){

    Transaction *p = (Transaction *)malloc(sizeof(Transaction));
    if(!p){
        return NULL; //memeroy is full 
    }
    p->balance = amount;
    strcpy(p->name, name);
    p->to = to;
    return p;
}
void appendTransaction(Transaction **head, int amount, char name, int to){
    Transaction *p = createTransaction(amount, name, to);
    if(!p){
        return NULL;
    }
  
    if (*head == NULL){
        *head = p;
    }

    Transaction *q = *head;
    while (q->next != NULL){
        q = q->next;
    }
    q->next = p;
}
void insertBegTransaction(Transaction **head, int amount, char name, int to){
    Transaction *p = createTransaction(amount, name, to);
    if(!p){
        return ;
    }
    if(*head == NULL){
        *head = p;
    }
    p->next = *head;
    *head = p;
}
void insertEndTransaction(Transaction **head, int amount, char name, int to){
    Transaction *p = createTransaction(amount, name, to);
    if(!p){
        return;
    }
    if(*head == NULL){
        *head = p;
    }
    Transaction *q = *head;
    while (q){
        q = q->next;
    }
    q->next = p; 

}
void insertPosTransaction(Transaction **head, int amount, char name, int to, int pos){
    Transaction *p = createTransaction(amount, name, to);
    if(!p){
        return;
    }    
    if(pos == 0){
       insertBegTransaction(head, amount, name, to); 
    }
    Transaction *q = *head;
    for(int i = 0; i < pos; i++){
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    Transaction *m = *head;
    while(m){
        m = m->next;
    }
    m->next = p;
    p->next = NULL;
}
int length(Transaction **head){
    int count = 0;
    Transaction *p = *head;
    while(p){
        count++;
        p = p->next;
    }
    return count;    
}
void removePosTransaction(Transaction **head, int amount, char name, int to, int pos){
    Transaction *p = *head;
    if(*head == NULL){
        return;
    }
    if(pos == 0){
       *head = (*head)->next;
       free(p);
    }
    Transaction *q = NULL;
     for(int i = 0; i < pos; i++){
        p = p->next;
        q = p;
    }
   q->next = p->next;
   free(p);
}
void destroy(Transaction **head){
    Transaction *q = *head, *p;
    while(q){
        p = q;
        q = q->next;
        free(p);
    }
}
void display(Transaction **head){
    Transaction *p = *head;
    while(p){
        printf("anjali owes %s %d\n", p->name, p->balance);
    }
}