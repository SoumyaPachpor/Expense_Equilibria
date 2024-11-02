// graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include "../Array/array.h"  // For Participant structure and MAX_MEMBERS

// Define a structure for each transaction (edge in the graph)
typedef struct Transaction {
    int receiverIndex;           // Index of the participant who receives the amount
    float amount;                // Amount owed to this participant
    struct Transaction *next;    // Pointer to the next transaction in the list
} Transaction;

// Define the Graph structure with an adjacency list
typedef struct {
    Transaction *adjList[MAX_MEMBERS];  // Array of pointers to linked lists for each participant
    int numParticipants;                // Number of participants in the group
} Graph;

// Function prototypes
void initGraph(Graph *graph, int numParticipants);
void addTransactionGraph(Graph *graph, int payerIndex, int receiverIndex, float amount);
void displayGraph(const Graph *graph);
void freeGraph(Graph *graph);  // To free memory allocated for transactions

#endif  // GRAPH_H
