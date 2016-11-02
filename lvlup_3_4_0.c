#include <stdio.h>

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

    dictionary[11].english = "File";
    dictionary[11].russian = "Файл";


    return 0;
}