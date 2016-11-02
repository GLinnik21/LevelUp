#include <stdio.h>
#include <stdlib.h>

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
void printUser();

User testUser;

int main () {
    User user1 = enterUser();
	User user = getTestUser();
    copyUser2 (&user1, &user);
    printf("%s %s %s %d", user.login, user.password, user.mail, user.age);

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
    return user;
}

User copyUser2(User* dest, User* src) {
    *src = *dest;
    return *src;
}

void printUser() {
    printf("%s %s %s %d", testUser.login, testUser.password, testUser.mail, testUser.age);
}