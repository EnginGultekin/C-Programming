#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "functions.h"

void showMenu();

int main() {
    showMenu();

    return 0;
}

// User interface
void showMenu() {
    struct User users[100];
    int numUsers = 0;

    loadUsers(users, &numUsers);

    int choice;

    while (1) {
        printf("\n");
        printf("1. Creating a New User\n");
        printf("2. Update User\n");
        printf("3. Delete User\n");
        printf("4. Account Transactions\n");
        printf("5. Log Out\n");
        printf("Make your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(users, &numUsers);
                break;
            case 2:
                updateUser(users, numUsers);
                break;
            case 3:
                deleteUser(users, &numUsers);
                break;
            case 4:
                performAccountOperations(users, numUsers);
                break;
            case 5:
                saveUsers(users, numUsers);
                printf("Logging Out...\n");
                return;
            default:
                printf("Invalid selection.\n");
        }
    }
}
