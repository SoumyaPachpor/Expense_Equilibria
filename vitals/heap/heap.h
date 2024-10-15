#ifndef HEAP_H
#define HEAP_H

typedef struct {
    double* data;    // Array to store heap elements (balances)
    int* index;      // To track which participant the balance belongs to
    int capacity;    // Max capacity of the heap
    int size;        // Current size of the heap
} Heap;

// Create a new heap
Heap* createHeap(int capacity);

// Insert into max-heap (for creditors)
void insertMaxHeap(Heap* heap, int index, double value);

// Insert into min-heap (for debtors)
void insertMinHeap(Heap* heap, int index, double value);

// Extract maximum (for max-heap)
int extractMaxHeap(Heap* heap);

// Extract minimum (for min-heap)
int extractMinHeap(Heap* heap);

// Max-heapify for max-heap
void maxHeapify(Heap* heap, int i);

// Min-heapify for min-heap
void minHeapify(Heap* heap, int i);

// Delete heap
void deleteHeap(Heap* heap);

#endif // HEAP_H
