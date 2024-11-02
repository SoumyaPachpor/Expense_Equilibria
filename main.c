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

    // Step 3: Add transactions (dummy transactions)
    addTransactionGraph(&graph, 0, 1, 50.0);  // Alice pays Bob $50
    addTransactionGraph(&graph, 1, 2, 30.0);  // Bob pays Charlie $30
    addTransactionGraph(&graph, 2, 3, 20.0);  // Charlie pays David $20
    addTransactionGraph(&graph, 3, 0, 10.0);  // David pays Alice $10

    displayParticipants();
    // Step 4: Minimize cash flow
    minimizeCashFlow(&graph, participants);
    displayParticipants();
    // Free allocated memory (optional, good practice)
    freeGraph(&graph);

    return 0;
}
