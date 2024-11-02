// list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Function to create a new transaction node
ListTransaction* createTransaction(const char *payer, const char *receiver, float amount) {
    ListTransaction *newTransaction = (ListTransaction*)malloc(sizeof(ListTransaction));
    if (newTransaction) {
        strncpy(newTransaction->payer, payer, MAX_NAME_LENGTH - 1);
        newTransaction->payer[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null termination
        strncpy(newTransaction->receiver, receiver, MAX_NAME_LENGTH - 1);
        newTransaction->receiver[MAX_NAME_LENGTH - 1] = '\0';
        newTransaction->amount = amount;
        newTransaction->next = NULL;
    }
    return newTransaction;
}

// Function to add a transaction to the end of the list
void addTransactionList(ListTransaction **head, const char *payer, const char *receiver, float amount) {
    ListTransaction *newTransaction = createTransaction(payer, receiver, amount);
    if (!newTransaction) return;  

    if (*head == NULL) {
        *head = newTransaction;
    } else {
        ListTransaction *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTransaction;
    }
}

// Function to display the list of transactions
void displayTransactions(ListTransaction *head) {
    printf("ListTransaction History:\n");
    ListTransaction *temp = head;
    while (temp != NULL) {
        printf("Payer: %s, Receiver: %s, Amount: %.2f\n", temp->payer, temp->receiver, temp->amount);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the transaction list
void freeTransactions(ListTransaction *head) {
    ListTransaction *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
