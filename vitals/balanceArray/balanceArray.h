#ifndef BALANCE_ARRAY_H
#define BALANCE_ARRAY_H

typedef struct {
    double* balances;  // Array to store net balances of participants
    char** names;      // Array to store participant names
    int size;          // Number of participants
} BalanceArray;

// Create BalanceArray for 'size' participants
BalanceArray* createBalanceArray(int size);

// Set balance for a participant
void setBalance(BalanceArray* arr, int index, double balance);

// Get balance of a participant
double getBalance(BalanceArray* arr, int index);

// Adjust a participant's balance
void adjustBalance(BalanceArray* arr, int index, double amount);

// Free memory of balance array
void deleteBalanceArray(BalanceArray* arr);

#endif // BALANCE_ARRAY_H
