/*
В этом файле описаны реализации функций, прототипы которых
описаны в файле advert.h.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "advert.h"

// Шаблон для вывода элементов структуры
const char *TEMPLATE = "|%2s|%-30s|%-10s|%-10s|%-70s|\n";

AdvertsCollection readFromBinaryFile(char *filepath) {
    // Открываем бинарный файл в режиме чтения
    FILE *file = fopen(filepath, "rb");

    // Проверяем открылся ли файл
    // (условие: если он не открылся)
    if (file == NULL) {
        // Выводим ошибку в стандартный поток ошибок
        perror("Ошибка открытия файла!");
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
        perror("Ошибка открытия/создания файла!");
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
    printf("Input a type of advert:\n");
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

Date strToDate(char *strDate) {
    const char *delimiter = "-";    // разделитель элементов даты

    int i = 1;
    Date date;
    char *token = strtok(strDate, delimiter);    // Получаем первый элемент даты
    // и преобразуем элементы даты (строки) в число и записываем в Date
    while (token)
    {
        if (i == 1) date.day = atoi(token);
        else if (i == 2) date.month = atoi(token);
        else if (i == 3) date.year = atoi(token);

        i++;
        token = strtok(0, delimiter);    // получаем следующий элемент даты
    }
    
    return date;
}

Date inputDate() {
    char strDate[11];

    printf("Input a date in format DD-MM-YY: ");
    inputStr(strDate, sizeof(strDate));

    return strToDate(strDate);
}

Advert inputAdvert() {
    Advert advert;

    printf("Input your fullname: ");
    inputStr(advert.fullName, sizeof(advert.fullName));

    advert.type = inputType();
    advert.date = inputDate();

    printf("Input advert text:\n");
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

char* dateToStr(Date date) {
    // если необходимо вернуть строковую переменную
    // из функции, то необходимо выделить память динамически
    char *strDate = malloc(sizeof(char) * 11);

    // Эта функция аналогична printf,
    // но она сохраняет форматированную строку
    // в переменную
    sprintf(
        strDate,           // буфер, куда сохраняется строка
        "%d-%d-%d",        // формат (как в printf)
        date.day, date.month, date.year
    );

    return strDate;
}

/**
 * Вывод шапки таблицы
 */
void printHead() {
    printf(TEMPLATE, "#", "Customer", "Type", "Date", "Text");
}

void printAdvert(Advert advert, int number) {
    char *strDate = dateToStr(advert.date);

    char strNumber[2];
    sprintf(strNumber, "%d", number);

    printf(TEMPLATE,
        strNumber,
        advert.fullName, 
        typeToStr(advert.type), 
        strDate,
        advert.text);

    free(strDate);
}

void printAllAdverts() {
    printHead();

    for (int i = 0; i < db.count; i++) {
        printAdvert(db.elements[i], (i + 1));
    }
}

void saveAdvert(Advert advert) {
    // если коллекция неполная, то добавляем
    if (db.count < sizeof(db.elements)) {
        db.elements[db.count++] = advert;
    }
}

void updateAdvert(int index, Advert advert) {
    // если индекс верный, то обновляем
    if (index < db.count) {
        db.elements[index] = advert;
    }
}

void removeAdvert(int index) {
    // если индекс верный, то удаляем
    // путем смещения элементов массива
    if (index < db.count) {
        for (int i = index; i < db.count - 1; i++) {
            db.elements[i] = db.elements[i + 1];
        }

        db.count--;
    }
}