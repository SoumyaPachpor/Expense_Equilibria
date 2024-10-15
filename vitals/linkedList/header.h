#define NAMESIZE 100
typedef struct Transaction{
    int to;
    struct Transaction *next;
    double balance;
    char name[NAMESIZE];
}Transaction;

void init(Transaction **head);
void appendTransaction(Transaction **head, int amount, char name, int to);
void insertBegTransaction(Transaction **head, int amount, char name, int to);
void insertEndTransaction(Transaction **head, int amount, char name, int to);
void insertPosTransaction(Transaction **head, int amount, char name, int to, int pos);
int length(Transaction **head);
void removePosTransaction(Transaction **head, int amount, char name, int to, int pos);
void display(Transaction **head);