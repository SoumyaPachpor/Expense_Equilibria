#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

// Helper function to perform DFS and detect a cycle
bool dfsCycleCheck(Graph* graph, int participant, bool* visited, bool* recStack) {
    if (!visited[participant]) {
        // Mark the current participant as visited and part of recursion stack
        visited[participant] = true;
        recStack[participant] = true;

        // Traverse through all the debts (transactions) of this participant
        Transaction* debt = graph->participants[participant].debts;
        while (debt != NULL) {
            int toParticipant = debt->to;
            // If the next participant is not visited and there's a cycle, return true
            if (!visited[toParticipant] && dfsCycleCheck(graph, toParticipant, visited, recStack)) {
                return true;
            } else if (recStack[toParticipant]) {
                return true; // Found a cycle
            }
            debt = debt->next;
        }
    }

    // Remove the participant from recursion stack
    recStack[participant] = false;
    return false;
}

int detectCycle(Graph* graph) {
    int size = graph->size;
    bool* visited = (bool*)malloc(size * sizeof(bool));
    bool* recStack = (bool*)malloc(size * sizeof(bool));

    // Initialize visited and recursion stack arrays
    for (int i = 0; i < size; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    // Check for cycle in different DFS trees
    for (int i = 0; i < size; i++) {
        if (!visited[i] && dfsCycleCheck(graph, i, visited, recStack)) {
            free(visited);
            free(recStack);
            return 1;  // Cycle found
        }
    }

    free(visited);
    free(recStack);
    return 0;  // No cycle
}

#include "balanceArray.h"
#include "heap.h"
#include <stdio.h>

// Function to minimize cash flow between participants
void minimizeCashFlow(Graph* graph, BalanceArray* balances) {
    int size = balances->size;

    // Create min-heap (for creditors) and max-heap (for debtors)
    Heap* maxHeap = createHeap(size);  // Max-heap for debtors (negative balance)
    Heap* minHeap = createHeap(size);  // Min-heap for creditors (positive balance)

    // Populate heaps with net balances
    for (int i = 0; i < size; i++) {
        if (balances->balances[i] < 0) {
            insertMaxHeap(maxHeap, i, -balances->balances[i]);  // Convert to positive for max-heap
        } else if (balances->balances[i] > 0) {
            insertMinHeap(minHeap, i, balances->balances[i]);
        }
    }

    // Settle debts
    while (maxHeap->size > 0 && minHeap->size > 0) {
        int debtor = extractMaxHeap(maxHeap);  // Participant who owes money
        int creditor = extractMinHeap(minHeap);  // Participant who is owed money

        double minAmount = balances->balances[creditor] < -balances->balances[debtor] ? balances->balances[creditor] : -balances->balances[debtor];

        // Settle the debt
        balances->balances[creditor] -= minAmount;
        balances->balances[debtor] += minAmount;

        // Print the transaction
        printf("%s pays %s: %.2f\n", graph->participants[debtor].name, graph->participants[creditor].name, minAmount);

        // Adjust the heaps
        if (balances->balances[debtor] < 0) {
            insertMaxHeap(maxHeap, debtor, -balances->balances[debtor]);
        }
        if (balances->balances[creditor] > 0) {
            insertMinHeap(minHeap, creditor, balances->balances[creditor]);
        }
    }

    // Free the heaps
    deleteHeap(maxHeap);
    deleteHeap(minHeap);
}


void deleteGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        clearTransactions(&(graph->participants[i]));
    }
    free(graph->participants);
    free(graph);
}
