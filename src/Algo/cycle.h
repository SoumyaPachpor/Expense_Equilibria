// cycle.h

#ifndef CYCLE_H
#define CYCLE_H

#include <stdbool.h>
#include "../Array/array.h"  // For Participant structure and MAX_MEMBERS
#include "../Graph/graph.h"           // For Graph and Transaction structure

// Function prototypes
bool hasCycle(Graph *graph);
void eliminateCycles(Graph *graph, Participant *participants);

#endif  // CYCLE_H
