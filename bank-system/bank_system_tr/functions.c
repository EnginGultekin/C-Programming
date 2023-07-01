#include <stdio.h>
#include <string.h>

#include "user.h"

// Dosyadan kullanıcıları yükler
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


// Kullanıcıları dosyaya kaydeder
void saveUsers(const struct User *users, int numUsers) {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Dosya oluşturulamadı.\n");
        return;
    }

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "%s %s %d %.2f\n", users[i].name, users[i].password, users[i].accountNumber, users[i].balance);
    }

    fclose(file);
}

// Yeni bir kullanıcı oluşturur
void createUser(struct User *users, int *numUsers) {
    struct User newUser;

    printf("İsim: ");
    scanf("%s", newUser.name);

    printf("Şifre: ");
    scanf("%s", newUser.password);

    printf("Hesap Numarası: ");
    scanf("%d", &newUser.accountNumber);

    printf("Başlangıç Bakiyesi: ");
    scanf("%f", &newUser.balance);

    users[*numUsers] = newUser;
    (*numUsers)++;

    printf("Yeni kullanıcı oluşturuldu.\n");
}

// Kullanıcıyı günceller
void updateUser(struct User *users, int numUsers) {
    int accountNumber;
    printf("Güncellenecek hesap numarasını girin: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == accountNumber)
        {

            struct User newUser;
            int trial = 3;
            printf("%d deneme hakkınız bulunmaktadır.\n", trial);


            while(trial > 0)
            {
                printf("Şifrenizi giriniz: ");
                scanf("%s", newUser.password);
                if(strcmp(users[i].password, newUser.password) == 0)
                {
                    printf("Yeni isim: ");
                    scanf("%s", users[i].name);

                    printf("Yeni Şifre: ");
                    scanf("%s", users[i].password);

                    printf("Yeni bakiye: ");
                    scanf("%f", &users[i].balance);

                    printf("Kullanıcı güncellendi.\n");
                    return;
                }
                else
                {
                    trial--;
                    if(trial == 0)
                    {
                        printf("Kartınız bloke olmuştur.\nLütfen en yakın Şubemiz ile iletişime geçin.\n\n");
                        printf("Teşekkürler, iyi günler dileriz.\n");
                        return;
                    }
                    else {
                        printf("Girdiğiniz şifre hatalıdır tekrar deneyin.\n");
                        printf("Kalan deneme Hakkınız %d\n", trial);
                    }
                }
            }
        }
    }
    printf("Hesap numarası bulunamadı.\n");
}

// Kullanıcıyı siler
void deleteUser(struct User *users, int *numUsers) {
    int accountNumber;
    printf("Silinecek hesap numarasını girin: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < *numUsers; i++) {
        if (users[i].accountNumber == accountNumber) {
            for (int j = i; j < (*numUsers) - 1; j++) {
                users[j] = users[j + 1];
            }

            (*numUsers)--;
            printf("Kullanıcı silindi.\n");
            return;
        }
    }

    printf("Hesap numarası bulunamadı.\n");
}


// Kullanıcıyı bulur ve hesap işlemlerini yapar
void performAccountOperations(struct User *users, int numUsers) {

    struct User newUser;

    printf("Hesap Numarası: ");
    scanf("%d", &newUser.accountNumber);

    printf("Şifre: ");
    scanf("%s", newUser.password);

    for (int i = 0; i < numUsers; i++) {
        if (users[i].accountNumber == newUser.accountNumber
            && strcmp(users[i].password, newUser.password) == 0) {
            // Kullanıcı hesabına erişildi
            printf("Hoş geldiniz, %s!\n", users[i].name);

            int choice;
            float amount;

            while (1) {
                printf("\n");
                printf("1. Bakiye Görüntüle\n");
                printf("2. Bakiye Yatır\n");
                printf("3. Bakiye Çek\n");
                printf("4. Çıkış\n");
                printf("Seçiminizi yapın: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Bakiye: %.2f\n", users[i].balance);
                        break;
                    case 2:
                        printf("Yatırılacak miktarı girin: ");
                        scanf("%f", &amount);
                        users[i].balance += amount;
                        printf("Yeni bakiye: %.2f\n", users[i].balance);
                        break;
                    case 3:
                        printf("Çekilecek miktarı girin: ");
                        scanf("%f", &amount);
                        if (amount <= users[i].balance) {
                            users[i].balance -= amount;
                            printf("Yeni bakiye: %.2f\n", users[i].balance);
                        } else {
                            printf("Yetersiz bakiye.\n");
                        }
                        break;
                    case 4:
                        printf("Çıkış yapılıyor...\n");
                        return;
                    default:
                        printf("Geçersiz seçim.\n");
                }
            }
        }
    }

    printf("Hesap numarası veya şifre hatalı.\n");
}