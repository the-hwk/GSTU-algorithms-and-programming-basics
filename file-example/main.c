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
    saveAdvert(advert);
}

void menuUpdateAdvert() {
    int index = -1;

    printf("Input index of advert: ");
    scanf("%d", &index);

    Advert advert = inputAdvert();
    updateAdvert(index - 1, advert);
}

void menuShowAdverts() {
    // printf("All adverts:\n");
    // for (int i = 0; i < db.count; i++) {
    //     printf("---%d---\n", (i + 1));
    //     printAdvert(db.elements[i]);
    //     printf("\n");
    // }
    printAllAdverts();
}

void menuRemoveAdvert() {
    int index = -1;

    printf("Input index of advert: ");
    scanf("%d", &index);

    removeAdvert(index - 1);
}

void menuSaveToFile() {
    writeToBinaryFile("data.bin", db);
    printf("Saved!\n");
}

void menuReadFromFile() {
    db = readFromBinaryFile("data.bin");
    printf("Data loaded from file!\n");
}

void runConsoleMenu() {
    int userInput = -1;
    do {
        printf("\n1. Add advert\n");
        printf("2. Update advert\n");
        printf("3. Remove advert\n");
        printf("4. Show adverts\n");
        printf("5. Save to file\n");
        printf("6. Read from file\n");
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
                menuSaveToFile();
                break;
            case 6:
                menuReadFromFile();
                break;
        }
    } while (userInput != 0);
}