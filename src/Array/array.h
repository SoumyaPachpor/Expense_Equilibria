// array.h

#ifndef ARRAY_H
#define ARRAY_H

#define MAX_NAME_LENGTH 50
#define MAX_MEMBERS 100

// Define the Participant struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    float balance;  // Use float for balance
    int index;
} Participant;

// Array to store participants
extern Participant participants[MAX_MEMBERS];
extern int num_members;

// Function prototypes
void initializeParticipants(int n);
void setParticipant(int index, const char *name, float balance);
void updateBalance(int index, float amount);
void displayParticipants();

#endif  // ARRAY_H
