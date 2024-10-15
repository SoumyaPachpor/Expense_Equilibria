#include <stdlib.h>
#include "transaction.h"

void addTransaction(Participant* participant, int to, double amount) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    newTransaction->to = to;
    newTransaction->amount = amount;
    newTransaction->next = participant->debts;
    participant->debts = newTransaction;
}

void clearTransactions(Participant* participant) {
    Transaction* current = participant->debts;
    Transaction* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    participant->debts = NULL;
}
