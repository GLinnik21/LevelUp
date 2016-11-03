#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef struct {
    const char* russian;
    const char* english;
} Dictionary;

int main() {
    Dictionary dictionary[20];

    dictionary[0].english = "Dog";
    dictionary[0].russian = "Собака";

    dictionary[1].english = "Who is Gori?";
    dictionary[1].russian = "Кто такой Горы?";

    dictionary[2].english = "Cat";
    dictionary[2].russian = "Кот";

    dictionary[3].english = "Book";
    dictionary[3].russian = "Книга";

    dictionary[4].english = "Notebook";
    dictionary[4].russian = "Ноутбук";

    dictionary[5].english = "Photo";
    dictionary[5].russian = "Фотография";

    dictionary[6].english = "Mail";
    dictionary[6].russian = "Почта";

    dictionary[7].english = "Dog";
    dictionary[7].russian = "Собака";

    dictionary[8].english = "Message";
    dictionary[8].russian = "Сообщение";

    dictionary[9].english = "Experience";
    dictionary[9].russian = "Опыт";

    dictionary[10].english = "Remainder";
    dictionary[10].russian = "Напоминание";

    dictionary[11].english = "Setting";
    dictionary[11].russian = "Настройка";

    dictionary[12].english = "Source";
    dictionary[12].russian = "Источник";

    char enter[256];

    while (1) {
        printf("Choose the language:\n"
                "(1)   RUS->ENG\n"
                "(2)   ENG->RUS\n"
                "(exit)To exit\n"
                "Your choice:");
        fgets(enter, 256, stdin);

        if (!strcmp(enter, "exit")) {
            break;
        }

        if (!strcmp(enter, "1")) {
            printf("Введите ваше слово:");
            fgets(enter, 256, stdin);
            for (int i = 0; i < 13; ++i) {
                if (!strcmp(dictionary[i].russian, enter)) {
                    printf("\n%s->%s\n\n", dictionary[i].russian, dictionary[i].english);
                    break;
                }
            }
        } else {
            printf("Enter your word:");
            fgets(enter, 256, stdin);
            for (int i = 0; i < 13; ++i) {
                if (!strcmp(dictionary[i].english, enter)) {
                    printf("\n%s->%s\n\n", dictionary[i].english, dictionary[i].russian);
                    break;
                }
            }
        }
    }

    return 0;
}