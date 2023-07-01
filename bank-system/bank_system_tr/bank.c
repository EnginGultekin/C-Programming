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

// Kullanıcı arayüzü
void showMenu() {
    struct User users[100];
    int numUsers = 0;

    loadUsers(users, &numUsers);

    int choice;

    while (1) {
        printf("\n");
        printf("1. Yeni Kullanıcı Oluştur\n");
        printf("2. Kullanıcı Güncelle\n");
        printf("3. Kullanıcı Sil\n");
        printf("4. Hesap İşlemleri\n");
        printf("5. Çıkış\n");
        printf("Seçiminizi yapın: ");
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
                printf("Çıkış yapılıyor...\n");
                return;
            default:
                printf("Geçersiz seçim.\n");
        }
    }
}
