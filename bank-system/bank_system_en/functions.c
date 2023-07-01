#include <stdio.h>
#include <string.h>

#include "user.h"

// Loads users from file
void loadUsers(struct User *users, int *numUsers) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        *numUsers = 0;
        return;
    }

    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s %s %d %f", users[i].name, users[i].password, &users[i].accountNumber, &users[i].balance);
        i++;
    }

    *numUsers = i;

    fclose(file);
}


// Saves users to file
void saveUsers(const struct User *users, int numUsers) {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Could not create file.\n");
        return;
    }

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "%s %s %d %.2f\n", users[i].name, users[i].password, users[i].accountNumber, users[i].balance);
    }

    fclose(file);
}

// Creates a new user
void createUser(struct User *users, int *numUsers) {
    struct User newUser;

    printf("Name: ");
    scanf("%s", newUser.name);

    printf("Password: ");
    scanf("%s", newUser.password);

    printf("Account Number: ");
    scanf("%d", &newUser.accountNumber);

    printf("Initial Balance: ");
    scanf("%f", &newUser.balance);

    users[*numUsers] = newUser;
    (*numUsers)++;

    printf("New user created.\n");
}

// Updates the user
void updateUser(struct User *users, int numUsers) {
    int accountNumber;
    printf("Enter the account number to update: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber)
        {

            struct User newUser;
            int trial = 3;
            printf("You have %d try.\n", trial);


            while(trial > 0)
            {
                printf("Enter your password: ");
                scanf("%s", newUser.password);
                if(strcmp(users[i].password, newUser.password) == 0)
                {
                    printf("New name: ");
                    scanf("%s", users[i].name);

                    printf("New password: ");
                    scanf("%s", users[i].password);

                    printf("New balance: ");
                    scanf("%f", &users[i].balance);

                    printf("User updated.\n");
                    return;
                }
                else
                {
                    trial--;
                    if(trial == 0)
                    {
                        printf("Your card has been blocked.\nPlease contact our nearest Branch.\n\n");
                        printf("Thank you, have a nice day.\n");
                        return;
                    }
                    else {
                        printf("The password you entered is incorrect, try again.\n");
                        printf("Your remaining trial entitlement: %d\n", trial);
                    }
                }
            }
        }
    }
    printf("Account number not found.\n");
}

// Deletes the user
void deleteUser(struct User *users, int *numUsers) {
    int accountNumber;
    printf("Enter the account number to be deleted: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < *numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            for (int j = i; j < (*numUsers) - 1; j++) {
                users[j] = users[j + 1];
            }

            (*numUsers)--;
            printf("User deleted.\n");
            return;
        }
    }

    printf("Account number not found.\n");
}


// Finds the user and performs account transactions
void performAccountOperations(struct User *users, int numUsers) {

    struct User newUser;

    printf("Account number: ");
    scanf("%d", &newUser.accountNumber);

    printf("Password: ");
    scanf("%s", newUser.password);

    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == newUser.accountNumber
            && strcmp(users[i].password, newUser.password) == 0) {
            // User account accessed
            printf("Welcome, %s!\n", users[i].name);

            int choice;
            float amount;

            while (1) {
                printf("\n");
                printf("1. View Balance\n");
                printf("2. To Deposit Money\n");
                printf("3. Withdraw Money\n");
                printf("4. Log Out\n");
                printf("Make your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Balance: %.2f\n", users[i].balance);
                        break;
                    case 2:
                        printf("Enter the amount to deposit: ");
                        scanf("%f", &amount);
                        users[i].balance += amount;
                        printf("New balance: %.2f\n", users[i].balance);
                        break;
                    case 3:
                        printf("Enter the amount to withdraw: ");
                        scanf("%f", &amount);
                        if (amount <= users[i].balance) {
                            users[i].balance -= amount;
                            printf("New balance: %.2f\n", users[i].balance);
                        } else {
                            printf("Insufficient balance.\n");
                        }
                        break;
                    case 4:
                        printf("Exiting...\n");
                        return;
                    default:
                        printf("Invalid selection.\n");
                }
            }
        }
    }

    printf("Account number or password is incorrect.\n");
}