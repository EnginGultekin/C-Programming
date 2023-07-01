#ifndef USER_H
#define USER_H

// User structure (includes name, password, account number and balance information)
struct User {
    char name[100];
    char password[100];
    int accountNumber;
    float balance;
};

#endif