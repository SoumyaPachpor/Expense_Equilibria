#include <stdio.h>
#include <stdlib.h>
#include "vitals/balanceArray/balanceArray.h"
#include "vitals/graph/graph.h"
#include "vitals/heap/heap.h"
#include "vitals/linkedList/transaction.h"

int main() {
    // Step 1: Create a graph for participants
    int participantCount = 3;  // You can change this based on the number of participants
    Graph* graph = createGraph(participantCount);

    // Step 2: Add some transactions (edges in the graph)
    addEdge(graph, 0, 1, 50);  // Participant 0 owes 50 to Participant 1
    addEdge(graph, 1, 2, 30);  // Participant 1 owes 30 to Participant 2
    addEdge(graph, 2, 0, 40);  // Participant 2 owes 40 to Participant 0

    // Step 3: Detect cycle in the graph of transactions
    if (detectCycle(graph)) {
        printf("Cycle detected in the transactions!\n");
    } else {
        printf("No cycle detected.\n");
    }

    // Step 4: Create a BalanceArray and calculate net balances for each participant
    BalanceArray* balances = createBalanceArray(participantCount);
    
    // Assign balances manually (replace this part with logic to compute actual balances)
    balances->balances[0] = -10;  // Net balance of Participant 0 (owes 10)
    balances->balances[1] = 20;   // Net balance of Participant 1 (gets 20)
    balances->balances[2] = -10;  // Net balance of Participant 2 (owes 10)

    // Step 5: Minimize cash flow
    printf("Minimizing cash flow:\n");
    minimizeCashFlow(graph, balances);

    // Step 6: Clean up and free the dynamically allocated memory
    deleteGraph(graph);
    deleteBalanceArray(balances);

    return 0;
}
