#include <stdio.h>
#include <stdlib.h>
#include "src/Array/array.h"
#include "src/Graph/graph.h"
#include "src/Heap/heap.h"
#include "src/List/list.h"
#include "src/Algo/minimize_cash_flow.h"

int main() {
    // Step 1: Initialize participants
    num_members = 4; // Let's say we have 4 participants
    initializeParticipants(num_members);

    // Setting participants and their initial balances
    setParticipant(0, "Alice", 0.0);
    setParticipant(1, "Bob", 0.0);
    setParticipant(2, "Charlie", 0.0);
    setParticipant(3, "David", 0.0);

    // Step 2: Initialize graph
    Graph graph;
    initGraph(&graph, num_members);

    // Step 3: Initialize transaction history list
    ListTransaction *transactionHistory = NULL;

    // Step 4: Add transactions (dummy transactions)
    addTransactionGraph(&graph, 0, 1, 50.0);  // Alice pays Bob $50
    addTransactionList(&transactionHistory, "Alice", "Bob", 50.0);

    addTransactionGraph(&graph, 1, 2, 30.0);  // Bob pays Charlie $30
    addTransactionList(&transactionHistory, "Bob", "Charlie", 30.0);

    addTransactionGraph(&graph, 2, 3, 20.0);  // Charlie pays David $20
    addTransactionList(&transactionHistory, "Charlie", "David", 20.0);

    addTransactionGraph(&graph, 3, 0, 10.0);  // David pays Alice $10
    addTransactionList(&transactionHistory, "David", "Alice", 10.0);

    // Display transaction history before minimization
    printf("Transaction History Before Minimization:\n");
    displayTransactions(transactionHistory);

    // Step 5: Minimize cash flow
    minimizeCashFlow(&graph, participants);

    // Step 6: Free memory
    freeTransactions(transactionHistory);
    freeGraph(&graph);

    return 0;
}
