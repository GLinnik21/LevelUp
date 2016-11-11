#include <stdio.h>

typedef struct {
    char* login;
    char* password;
    char* mail;
    int age;
} User;

void swap(User*, User*);

int main () {
    User user1;
    user1.login = "Glebas";
    User user2;
    user2.login = "Not Glebas";

    swap(&user1, &user2);
    printf("%s %s", user1.login, user2.login);
    return 0;
}

void swap(User* first, User* second) {
    User temp = *first;
    *first = *second;
    *second = temp;
}

