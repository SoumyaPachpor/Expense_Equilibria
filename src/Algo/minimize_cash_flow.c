// minimize_cash_flow.c

#include <stdio.h>
#include <stdlib.h>
#include "minimize_cash_flow.h"

// Function to minimize cash flow among participants
void minimizeCashFlow(Graph *graph, Participant *participants) {
    // Array to hold net balances of participants
    float balances[MAX_MEMBERS] = {0};

    // Calculate net balances for each participant
    for (int i = 0; i < graph->numParticipants; i++) {
        Transaction *current = graph->adjList[i];
        while (current != NULL) {
            balances[i] -= current->amount;  // Deduct amount from payer
            balances[current->receiverIndex] += current->amount;  // Add amount to receiver
            current = current->next;
        }
    }

    // Create max-heap for creditors and min-heap for debtors
    MaxHeap maxHeap;
    MinHeap minHeap;
    maxHeap.size = 0;
    minHeap.size = 0;

    // Fill heaps with participants based on their balances
    for (int i = 0; i < graph->numParticipants; i++) {
        if (balances[i] > 0) {
            maxHeapInsert(&maxHeap, &participants[i]);  // Insert into max-heap for creditors
        } else if (balances[i] < 0) {
            minHeapInsert(&minHeap, &participants[i]);  // Insert into min-heap for debtors
        }
    }

    // Settle debts
    while (maxHeap.size > 0 && minHeap.size > 0) {
        // Get the participant with the maximum balance (creditor)
        Participant *maxReceiver = maxHeapExtract(&maxHeap);
        float maxAmount = maxReceiver->balance;

        // Get the participant with the minimum balance (debtor)
        Participant *minPayer = minHeapExtract(&minHeap);
        float minAmount = -minPayer->balance;  // Negate to get positive balance

        // Determine the amount to settle
        float settleAmount = (maxAmount < minAmount) ? maxAmount : minAmount;

        // Print the transaction
        printf("%s pays %.2f to Participant %s\n", maxReceiver->name, settleAmount, minPayer->name);

        // Update balances
        maxReceiver->balance -= settleAmount;
        minPayer->balance += settleAmount;

        // Reinsert updated balances back into heaps if applicable
        if (maxReceiver->balance > 0) {
            maxHeapInsert(&maxHeap, maxReceiver);
        }
        if (minPayer->balance < 0) {
            minHeapInsert(&minHeap, minPayer);
        }
    }
}
