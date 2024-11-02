// heap.h

#ifndef HEAP_H
#define HEAP_H

#include "../Array/array.h"
// Define the MaxHeap and MinHeap structs
typedef struct {
    Participant *data[MAX_MEMBERS];
    int size;
} MaxHeap, MinHeap;

// Function prototypes for MaxHeap
void maxHeapInsert(MaxHeap *heap, Participant *participant);
Participant* maxHeapExtract(MaxHeap *heap);
void maxHeapifyDown(MaxHeap *heap, int index);

// Function prototypes for MinHeap
void minHeapInsert(MinHeap *heap, Participant *participant);
Participant* minHeapExtract(MinHeap *heap);
void minHeapifyDown(MinHeap *heap, int index);

#endif  // HEAP_H
