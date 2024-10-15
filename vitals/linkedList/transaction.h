#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct Transaction {
    int to;                      // Index of the participant who receives
    double amount;               // Amount transferred
    struct Transaction* next;    // Pointer to the next transaction
} Transaction;

typedef struct Participant {
    char name[50];               // Name of the participant
    Transaction* debts;          // List of debts
} Participant;

// Add a transaction (debt) to a participant
void addTransaction(Participant* participant, int to, double amount);

// Clear all transactions for a participant
void clearTransactions(Participant* participant);

#endif // TRANSACTION_H
