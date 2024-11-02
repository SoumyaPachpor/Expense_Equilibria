// cycle.c

#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"

// Depth-First Search (DFS) helper for cycle detection
bool dfs(int v, bool visited[], bool recStack[], Graph *graph) {
    visited[v] = true;
    recStack[v] = true;

    Transaction *current = graph->adjList[v];
    while (current != NULL) {
        int neighbor = current->receiverIndex;

        if (!visited[neighbor] && dfs(neighbor, visited, recStack, graph)) {
            return true; // Cycle detected
        } else if (recStack[neighbor]) {
            return true; // Cycle detected
        }
        current = current->next;
    }

    recStack[v] = false; // Remove vertex from recursion stack
    return false;
}

// Detects if there is a cycle in the graph
bool hasCycle(Graph *graph) {
    bool *visited = (bool *)malloc(graph->numParticipants * sizeof(bool));
    bool *recStack = (bool *)malloc(graph->numParticipants * sizeof(bool));

    for (int i = 0; i < graph->numParticipants; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->numParticipants; i++) {
        if (!visited[i] && dfs(i, visited, recStack, graph)) {
            free(visited);
            free(recStack);
            return true; // Cycle detected
        }
    }

    free(visited);
    free(recStack);
    return false; // No cycles found
}

// Placeholder for eliminating cycles; modify as per specific requirements
void eliminateCycles(Graph *graph, Participant *participants) {
    if (hasCycle(graph)) {
        printf("Cycle detected! Elimination logic needs to be implemented.\n");
        // This would involve logic to consolidate or reduce cycles
    } else {
        printf("No cycles detected.\n");
    }
}
