/*
В этом файле описаны реализации функций, прототипы которых
описаны в файле advert.h.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "advert.h"

// Шаблон для вывода шапки таблицы
const char *HEAD_TEMPLATE = "|%2s|%-30s|%-10s|%-10s|%-70s|\n";
// Шаблон для вывода строки таблицы
const char *ROW_TEMPLATE = "|%02d|%-30s|%-10s|%02d-%02d-%4d|%-70s|\n";

AdvertsCollection readFromBinaryFile(char *filepath) {
    // Открываем бинарный файл в режиме чтения
    FILE *file = fopen(filepath, "rb");

    // Проверяем открылся ли файл
    // (условие: если он не открылся)
    if (file == NULL) {
        // Выводим ошибку в стандартный поток ошибок
        perror("File opening error!");
        // Завершаем программу с кодом ошибки 1 (ошибка выполнения)
        exit(EXIT_FAILURE);
    }

    AdvertsCollection collection;

    // Выполняем чтение файла
    fread(&collection, sizeof(AdvertsCollection), 1, file);
    // И закрываем его
    fclose(file);

    return collection;
}

void writeToBinaryFile(char *filepath, AdvertsCollection collection) {
    // Открываем файл для записи
    // Если файла не существует, то он будет создан
    FILE *file = fopen(filepath, "wb");

    // Проверяем открылся ли файл
    // (обычно ошибка бывает, когда файловая система
    // запрещает создание файла)    
    if (file == NULL) {
        perror("File opening/creating error!");
        exit(EXIT_FAILURE);
    }

    // Записываем структуру в файл
    fwrite(&collection, sizeof(AdvertsCollection), 1, file);
    // И закрываем его
    fclose(file);
}

/**
 * Вспомогательная функция для ввода строки.
 * Очищает буфер потока ввода и заменяет
 * символ перевода на новую строку на нуль-символ
 */
void inputStr(char *str, int size) {
    while (getchar() != '\n');
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

Type inputType() {
    printf("Enter the type of advert:\n");
    printf("1. Private\n");
    printf("2. Commercial\n");

    // Выбор пользователя
    int userInput = 0;
    scanf("%d", &userInput);

    Type type;

    switch (userInput)
    {
        case 1:
            type = PRIVATE;
            break;
        case 2:
            type = COMMERCIAL;
            break;
    }

    return type;
}

Date inputDate() {
    Date date;

    printf("Enter the date in format DD-MM-YY: ");
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);
    
    return date;
}

Advert inputAdvert() {
    Advert advert;

    printf("Enter your fullname: ");
    inputStr(advert.fullname, sizeof(advert.fullname));

    advert.type = inputType();
    advert.date = inputDate();

    printf("Enter the text of advert:\n");
    inputStr(advert.text, sizeof(advert.text));

    return advert;
}

char* typeToStr(Type type) {
    switch (type)
    {
        case PRIVATE:
            return "private";
        case COMMERCIAL:
            return "commercial";
        default:
            return "";
    }
}

/**
 * Вывод шапки таблицы
 */
void printHead() {
    printf(HEAD_TEMPLATE, "#", "Customer", "Type", "Date", "Text");
}

void printAdvert(Advert advert, int number) {
    printf(ROW_TEMPLATE,
        number,
        advert.fullname,
        typeToStr(advert.type), 
        advert.date.day,
        advert.date.month,
        advert.date.year,
        advert.text
    );
}

void printAllAdverts() {
    printHead();

    for (int i = 0; i < db.count; i++) {
        printAdvert(db.elements[i], (i + 1));
    }
}

char saveAdvert(Advert advert) {
    // Если коллекция неполная, то добавляем
    if (db.count < sizeof(db.elements)) {
        db.elements[db.count++] = advert;
        return 1;
    }

    return 0;
}

char updateAdvert(int index, Advert advert) {
    // Если индекс верный, то обновляем
    if (index >= 0 && index < db.count) {
        db.elements[index] = advert;
        return 1;
    }

    return 0;
}

char removeAdvert(int index) {
    // Если индекс верный, то удаляем
    // путем смещения элементов массива
    if (index >= 0 && index < db.count) {
        for (int i = index; i < db.count - 1; i++) {
            db.elements[i] = db.elements[i + 1];
        }

        db.count--;

        return 1;
    }

    return 0;
}

int removeAdvertsByMonth(int month) {
    int removed = 0;    // счетчик удаленных объявлений

    for (int i = 0; i < db.count; i++) {
        // Если месяц выхода объявления совпадает, то удаляем его
        if (db.elements[i].date.month == month) {
            // Удаляем вызовом функции для удаления объявления
            // при этом после удаления уменьшаем индекс на 1
            // и добавляем 1 к счетчику удаленных объявлений
            removed += removeAdvert(i--);
        }
    }

    return removed;
}