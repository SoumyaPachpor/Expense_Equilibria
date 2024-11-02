// list.h

#ifndef LIST_H
#define LIST_H

#define MAX_NAME_LENGTH 50

// Define the ListTransaction struct (linked list node)
typedef struct ListTransaction {
    char payer[MAX_NAME_LENGTH];
    char receiver[MAX_NAME_LENGTH];
    float amount;
    struct ListTransaction *next;
} ListTransaction;

// Function prototypes
ListTransaction* createTransaction(const char *payer, const char *receiver, float amount);
void addTransactionList(ListTransaction **head, const char *payer, const char *receiver, float amount);
void displayTransactions(ListTransaction *head);
void freeTransactions(ListTransaction *head);

#endif  // LIST_H
