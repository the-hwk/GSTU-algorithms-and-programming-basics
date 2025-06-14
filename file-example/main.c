#include <stdio.h>
// Подключаем наш заголовочный файл, который хранит
// прототипы функций для работы с объявлениями
#include "advert.h"

AdvertsCollection db;

/**
 * Консольное меню
 */
void runConsoleMenu();

int main() {
    db.count = 0;

    runConsoleMenu();

    return 0;
}

void menuAddAdvert() {
    Advert advert = inputAdvert();
    
    // Т.к. функция saveAdvert возвращает 1 или 0,
    // что обозначает успешна ли она была выполнена или нет,
    // то можно вызвать ее в конструкции if-else
    if (saveAdvert(advert)) {
        printf("Advert added!\n");
    }
}

void menuUpdateAdvert() {
    int number = -1;

    printf("Enter the number of advert: ");
    scanf("%d", &number);

    Advert advert = inputAdvert();

    if (updateAdvert(number - 1, advert)) {
        printf("The advert #%d updated!\n", number);
    }
}

void menuShowAdverts() {
    printAllAdverts();
}

void menuRemoveAdvert() {
    int number = -1;

    printf("Enter the number of advert: ");
    scanf("%d", &number);

    if (removeAdvert(number - 1)) {
        printf("The advert #%d removed!\n", number);
    }
}

void menuRemoveByMonth() {
    int month = -1;

    printf("Enter the month number: ");
    scanf("%d", &month);

    printf("Removed %d adverts!\n", removeAdvertsByMonth(month));
}

void menuSaveToFile() {
    writeToBinaryFile("data.bin", db);
    printf("Saved!\n");
}

void menuReadFromFile() {
    db = readFromBinaryFile("data.bin");
    printf("Data loaded from the file!\n");
}

void runConsoleMenu() {
    int userInput = -1;
    do {
        printf("\n1. Add advert\n");
        printf("2. Update advert\n");
        printf("3. Remove advert\n");
        printf("4. Show adverts\n");
        printf("5. Remove by month\n");
        printf("6. Save to file\n");
        printf("7. Read from file\n");
        printf("0. Exit\n");

        scanf("%d", &userInput);
        printf("\n");

        switch (userInput)
        {
            case 1:
                menuAddAdvert();
                break;
            case 2:
                menuUpdateAdvert();
                break;
            case 3:
                menuRemoveAdvert();
                break;
            case 4:
                menuShowAdverts();
                break;
            case 5:
                menuRemoveByMonth();
                break;
            case 6:
                menuSaveToFile();
                break;
            case 7:
                menuReadFromFile();
                break;
        }
    } while (userInput != 0);
}