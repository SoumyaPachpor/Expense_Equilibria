#include <stdlib.h>
#include <string.h>
#include "balanceArray.h"

BalanceArray* createBalanceArray(int size) {
    BalanceArray* arr = (BalanceArray*)malloc(sizeof(BalanceArray));
    arr->balances = (double*)malloc(size * sizeof(double));
    arr->names = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        arr->names[i] = (char*)malloc(50 * sizeof(char));  // Assume max length of name is 50
        arr->balances[i] = 0.0;
    }
    arr->size = size;
    return arr;
}

void setBalance(BalanceArray* arr, int index, double balance) {
    if (index >= 0 && index < arr->size) {
        arr->balances[index] = balance;
    }
}

double getBalance(BalanceArray* arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->balances[index];
    }
    return 0.0;
}

void adjustBalance(BalanceArray* arr, int index, double amount) {
    if (index >= 0 && index < arr->size) {
        arr->balances[index] += amount;
    }
}

void deleteBalanceArray(BalanceArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        free(arr->names[i]);
    }
    free(arr->names);
    free(arr->balances);
    free(arr);
}
