// array.c

#include <stdio.h>
#include <string.h>
#include "array.h"

// Define the participants array and number of members
Participant participants[MAX_MEMBERS];
int num_members = 0;

// Function to initialize the participants array with zero balances and empty names
void initializeParticipants(int n) {
    num_members = n;
    for (int i = 0; i < num_members; i++) {
        participants[i].balance = 0.0f;
        participants[i].index = i;
        strcpy(participants[i].name, "");
    }
}

// Function to set a participant's name and initial balance
void setParticipant(int index, const char *name, float balance) {
    if (index >= 0 && index < num_members) {
        strncpy(participants[index].name, name, MAX_NAME_LENGTH - 1);
        participants[index].name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null termination
        participants[index].balance = balance;
        participants[index].index = index;
    }
}

// Function to update the balance of a participant by a specific amount
void updateBalance(int index, float amount) {
    if (index >= 0 && index < num_members) {
        participants[index].balance += amount;
    }
}

// Function to display all participants and their balances
void displayParticipants() {
    printf("Participants:\n");
    for (int i = 0; i < num_members; i++) {
        printf("Index: %d, Name: %s, Balance: %.2f\n", participants[i].index, participants[i].name, participants[i].balance);
    }
}
