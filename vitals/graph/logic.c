#include <stdlib.h>
#include "graph.h"
#include "../balanceArray/balanceArray.h"
#include "../linkedList/transaction.h"

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->participants = (Participant*)malloc(size * sizeof(Participant));
    graph->size = size;
    for (int i = 0; i < size; i++) {
        graph->participants[i].debts = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to, double amount) {
    addTransaction(&(graph->participants[from]), to, amount);
}

int detectCycle(Graph* graph) {
    // Implement DFS-based cycle detection algorithm
    return 0;  // Placeholder, implement actual cycle detection
}

void minimizeCashFlow(Graph* graph, BalanceArray* balances) {
    // Implement the cash flow minimization using the heap and balance array
}

void deleteGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        clearTransactions(&(graph->participants[i]));
    }
    free(graph->participants);
    free(graph);
}
