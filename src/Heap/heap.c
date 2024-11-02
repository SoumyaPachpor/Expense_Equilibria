// heap.c

#include <stdio.h>
#include "heap.h"

// Utility functions for swapping elements
void swap(Participant **a, Participant **b) {
    Participant *temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heap Functions

// Insert participant into max-heap based on balance
void maxHeapInsert(MaxHeap *heap, Participant *participant) {
    int i = heap->size++;
    heap->data[i] = participant;

    // Bubble up to maintain max-heap property
    while (i > 0 && heap->data[(i - 1) / 2]->balance < heap->data[i]->balance) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract participant with max balance from max-heap
Participant* maxHeapExtract(MaxHeap *heap) {
    if (heap->size <= 0) return NULL;
    Participant *max = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    maxHeapifyDown(heap, 0);
    return max;
}

// Heapify down for max-heap to maintain heap property
void maxHeapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left]->balance > heap->data[largest]->balance) {
        largest = left;
    }
    if (right < heap->size && heap->data[right]->balance > heap->data[largest]->balance) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        maxHeapifyDown(heap, largest);
    }
}

// Min-Heap Functions

// Insert participant into min-heap based on balance
void minHeapInsert(MinHeap *heap, Participant *participant) {
    int i = heap->size++;
    heap->data[i] = participant;

    // Bubble up to maintain min-heap property
    while (i > 0 && heap->data[(i - 1) / 2]->balance > heap->data[i]->balance) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract participant with min balance from min-heap
Participant* minHeapExtract(MinHeap *heap) {
    if (heap->size <= 0) return NULL;
    Participant *min = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    minHeapifyDown(heap, 0);
    return min;
}

// Heapify down for min-heap to maintain heap property
void minHeapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left]->balance < heap->data[smallest]->balance) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right]->balance < heap->data[smallest]->balance) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        minHeapifyDown(heap, smallest);
    }
}
