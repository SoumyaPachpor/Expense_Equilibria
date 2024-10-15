#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (double*)malloc(capacity * sizeof(double));
    heap->index = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void insertMaxHeap(Heap* heap, int index, double value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = value;
    heap->index[i] = index;
    
    // Fix the max-heap property
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        // Swap the values
        double tempVal = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = tempVal;

        // Swap the index
        int tempIndex = heap->index[i];
        heap->index[i] = heap->index[(i - 1) / 2];
        heap->index[(i - 1) / 2] = tempIndex;

        i = (i - 1) / 2;
    }
}

void insertMinHeap(Heap* heap, int index, double value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = value;
    heap->index[i] = index;
    
    // Fix the min-heap property
    while (i != 0 && heap->data[(i - 1) / 2] > heap->data[i]) {
        // Swap the values
        double tempVal = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = tempVal;

        // Swap the index
        int tempIndex = heap->index[i];
        heap->index[i] = heap->index[(i - 1) / 2];
        heap->index[(i - 1) / 2] = tempIndex;

        i = (i - 1) / 2;
    }
}

int extractMaxHeap(Heap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->index[0];
    }

    int rootIndex = heap->index[0];
    
    // Replace the root with the last element
    heap->data[0] = heap->data[heap->size - 1];
    heap->index[0] = heap->index[heap->size - 1];
    heap->size--;

    maxHeapify(heap, 0);

    return rootIndex;
}

int extractMinHeap(Heap* heap) {
    if (heap->size <= 0) return -1;
    if (heap->size == 1) {
        heap->size--;
        return heap->index[0];
    }

    int rootIndex = heap->index[0];
    
    // Replace the root with the last element
    heap->data[0] = heap->data[heap->size - 1];
    heap->index[0] = heap->index[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);

    return rootIndex;
}

void maxHeapify(Heap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;
    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != i) {
        // Swap values
        double tempVal = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = tempVal;

        // Swap indices
        int tempIndex = heap->index[i];
        heap->index[i] = heap->index[largest];
        heap->index[largest] = tempIndex;

        maxHeapify(heap, largest);
    }
}

void minHeapify(Heap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != i) {
        // Swap values
        double tempVal = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = tempVal;

        // Swap indices
        int tempIndex = heap->index[i];
        heap->index[i] = heap->index[smallest];
        heap->index[smallest] = tempIndex;

        minHeapify(heap, smallest);
    }
}

void deleteHeap(Heap* heap) {
    free(heap->data);
    free(heap->index);
    free(heap);
}
