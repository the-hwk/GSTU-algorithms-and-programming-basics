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
    printf("All adverts:\n");
    for (int i = 0; i < db.count; i++) {
        printf("---%d---\n", (i + 1));
        printAdvert(db.elements[i]);
        printf("\n");
    }
}

void menuRemoveAdvert() {
    int index = -1;

    printf("Input index of advert: ");
    scanf("%d", &index);

    removeAdvert(index - 1);
}

void runConsoleMenu() {
    int userInput = -1;
    do {
        printf("1. Add advert\n");
        printf("2. Update advert\n");
        printf("3. Remove advert\n");
        printf("4. Show adverts\n");
        printf("0. Exit\n");

        scanf("%d", &userInput);

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
        }
    } while (userInput != 0);
}