#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "user.h"

// Dosyadan kullanıcıları yükler
void loadUsers(struct User *users, int *numUsers);

// Kullanıcıları dosyaya kaydeder
void saveUsers(const struct User *users, int numUsers);

// Yeni bir kullanıcı oluşturur
void createUser(struct User *users, int *numUsers);

// Kullanıcıyı günceller
void updateUser(struct User *users, int numUsers);

// Kullanıcıyı siler
void deleteUser(struct User *users, int *numUsers);

// Kullanıcıyı bulur ve hesap işlemlerini yapar
void performAccountOperations(struct User *users, int numUsers);


#endif