#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* login;
    char* password;
    char* mail;
    int age;
} User;

User enterUser();
User getTestUser();
User copyUser(User);
User copyUser2(User*, User*);
void printUser(User);//printUser в задании был указал без параметров

User testUser;

int main () {
    User user1 = enterUser();
	User user = getTestUser();
    copyUser2 (&user1, &user);
    printUser(user1);

    User userArr[10];

	return 0;
}

User enterUser() {
    User temp;
    printf("%s", "Enter user's information: login, password, mail and age: ");
    temp.login = (char*)malloc(256);
    temp.password = (char*)malloc(256);
    temp.mail = (char*)malloc(256);
    scanf("%s%s%s%d", temp.login, temp.password, temp.mail, &temp.age);
    return temp;
}

User getTestUser() {
    testUser.login = "Test";
    testUser.password = "*******";
    testUser.mail = "test@mail.ru";
    testUser.age = 21;
    return testUser;
}

User copyUser(User user) {
    char* newLogin = (char*)malloc(sizeof(char) * 256);
    char* newPassword = (char*)malloc(sizeof(char) * 256);
    char* newMail = (char*)malloc(sizeof(char) * 256);

    strcpy(newLogin, user.login);
    strcpy(newPassword, user.password);
    strcpy(newMail, user.mail);

    User brandNew = {newLogin, newPassword, newMail, user.age};
    return brandNew;
}

User copyUser2(User* dest, User* src) {
    User temp = *dest;
    *dest = copyUser(*src);
    return temp;
}

void printUser(User user) {
    printf("%s %s %s %d", user.login, user.password, user.mail, user.age);
}