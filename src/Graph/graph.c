// graph.c

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Initialize the graph with the specified number of participants
void initGraph(Graph *graph, int numParticipants) {
    graph->numParticipants = numParticipants;
    for (int i = 0; i < numParticipants; i++) {
        graph->adjList[i] = NULL;  // Initialize each adjacency list as empty
    }
}

// Add a transaction where 'payer' pays 'amount' to 'receiver'
void addTransactionGraph(Graph *graph, int payerIndex, int receiverIndex, float amount) {
    // Create a new transaction for the payer
    Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
    newTransaction->receiverIndex = receiverIndex;
    newTransaction->amount = amount;
    newTransaction->next = graph->adjList[payerIndex];
    graph->adjList[payerIndex] = newTransaction;

    // Update the balances
    participants[payerIndex].balance -= amount; // Deduct from payer
    participants[receiverIndex].balance += amount; // Add to receiver
}


// Display the debt relationships for each participant
void displayGraph(const Graph *graph) {
    printf("Debt Relationships:\n");
    for (int i = 0; i < graph->numParticipants; i++) {
        printf("Participant %d owes:\n", i);
        Transaction *current = graph->adjList[i];
        while (current != NULL) {
            printf("  - Participant %d: %.2f\n", current->receiverIndex, current->amount);
            current = current->next;
        }
    }
}

// Free the memory allocated for the transactions in the adjacency list
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numParticipants; i++) {
        Transaction *current = graph->adjList[i];
        while (current != NULL) {
            Transaction *nextTransaction = current->next;
            free(current);
            current = nextTransaction;
        }
        graph->adjList[i] = NULL;  // Set to NULL after freeing
    }
}
