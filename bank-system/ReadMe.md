# Bank System Application - Banka Sistemi Uygulaması 

### Contents - İçerik

#### First in english and then in turkish - Önce ingilizce sonra türkçe


### *********************** EN ***********************

#### When we run the project for the first time, we need to run the `make bank` command. In this way, our `Makefile` file will enable `bank.c` and `functions.c` files to run at the same time. Then we can run the program with the `./bank` command.
 
#### This example code stores users in a file named `users.txt`.

##### To perform user-related operations, it first loads the users from the file and saves them to the file when the operations are completed.

##### The code includes the "createUser" function to perform user registration, the "updateUser" function to perform user update operations, and the "deleteUser" function to perform user deletion operations.

##### "performAccountOperations" function is used for user account operations. This function allows the user to access their account and perform operations such as balance view, balance deposit and balance withdrawal.

#### All these functions are contained in `functions.c`.

##### The user interface provides the user with a number of options and performs related actions based on the user's selection.

#### This sample code provides a basic bank account management system. You can customize it according to your needs and requirements while developing.

### *********************** TR ***********************

#### Projeyi ilk çalıştırdığımızda `make bank` komutunu çalıştırmamız gerekmektedir. Bu şekilde elimizdeki `Makefile` dosyası `bank.c` ve  `functions.c` dosyalarının aynı anda çalışmasını sağlıyacaktır. Daha sonra `./bank` komutu ile programı çalıştırabiliriz.
 
#### Bu örnek kod, kullanıcıları `users.txt` adlı bir dosyada saklamaktadır.

##### Kullanıcılarla ilgili işlemler yapmak için önce kullanıcıları dosyadan yükleyip, işlemler tamamlandığında tekrar dosyaya kaydeder.

##### Kod, kullanıcı kayıt işlemlerini yapabilmek için "createUser" fonksiyonunu, kullanıcı güncelleme işlemlerini yapabilmek için "updateUser" fonksiyonunu ve kullanıcı silme işlemlerini yapabilmek için "deleteUser" fonksiyonunu içermektedir.

##### Kullanıcı hesap işlemleri için "performAccountOperations" fonksiyonu kullanılmaktadır. Bu fonksiyon, kullanıcının hesabına erişmesine ve bakiye görüntüleme, bakiye yatırma ve bakiye çekme gibi işlemleri yapmasına olanak tanır.

#### Tüm bu fonksyonlar `functions.c` içinde buunmaktadır.  

##### Kullanıcı arayüzü, kullanıcıya bir dizi seçenek sunar ve kullanıcının seçimine göre ilgili işlemleri gerçekleştirir.

#### Bu örnek kod, temel bir banka hesap yönetimi sistemi sağlamaktadır. Geliştirme yaparken ihtiyaçlarınıza ve gereksinimlerinize göre özelleştirebilirsiniz.

### **********************************************