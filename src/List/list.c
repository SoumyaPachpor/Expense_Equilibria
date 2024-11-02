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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Helper function to check if a transaction is unique
int isUniqueTransaction(ListTransaction *head, const char *payer, const char *receiver) {
    ListTransaction *current = head;
    while (current != NULL) {
        if (strcmp(current->payer, payer) == 0 && strcmp(current->receiver, receiver) == 0) {
            return 0;  // Not unique
        }
        current = current->next;
    }
    return 1;  // Unique
}

void displayTransactions(ListTransaction *head) {
    if (!head) {
        printf("No transactions to display.\n");
        return;
    }

    printf("\n==============================\n");
    printf("        Transaction History\n");
    printf("==============================\n");
    printf("%-15s %-15s %-10s\n", "Payer", "Receiver", "Amount");
    printf("------------------------------------------------\n");

    ListTransaction *current = head;
    while (current != NULL) {
        if (isUniqueTransaction(head, current->payer, current->receiver)) {
            printf("%-15s %-15s $%.2f\n", current->payer, current->receiver, current->amount);
        }
        current = current->next;
    }

    printf("------------------------------------------------\n");
    printf("          End of History\n\n");
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
