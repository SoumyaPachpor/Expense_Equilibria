#ifndef GRAPH_H
#define GRAPH_H

#include "transaction.h"

typedef struct {
    Participant* participants;  // Array of participants
    int size;                   // Number of participants
} Graph;

// Create a new graph
Graph* createGraph(int size);

// Add a transaction to the graph (from one participant to another)
void addEdge(Graph* graph, int from, int to, double amount);

// Detect cycle in the graph using DFS (returns 1 if cycle exists, 0 otherwise)
int detectCycle(Graph* graph);
bool dfsCycleCheck(Graph* graph, int participant, bool* visited, bool* recStack);

// Minimize cash flow between participants
void minimizeCashFlow(Graph* graph, BalanceArray* balances);

// Free the memory allocated for the graph
void deleteGraph(Graph* graph);

#endif // GRAPH_H
