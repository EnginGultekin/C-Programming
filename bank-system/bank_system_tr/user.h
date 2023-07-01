#ifndef USER_H
#define USER_H

// Kullanıcı yapısı (isim, şifre, hesap numarası ve bakiye bilgilerini içerir)
struct User {
    char name[100];
    char password[100];
    int accountNumber;
    float balance;
};

#endif
