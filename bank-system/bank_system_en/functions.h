#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "user.h"

// Loads users from file
void loadUsers(struct User *users, int *numUsers);

// Saves users to file
void saveUsers(const struct User *users, int numUsers);

// Creates a new user
void createUser(struct User *users, int *numUsers);

// Updates the user
void updateUser(struct User *users, int numUsers);

// Deletes the user
void deleteUser(struct User *users, int *numUsers);

// Finds the user and performs the account operations
void performAccountOperations(struct User *users, int numUsers);


#endif