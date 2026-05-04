#include <string.h>
#include <windows.h>
#include <stdio.h>

#include "musicmngr.h"
#include "ioutils.h"

Playlist globalPlaylist;
Statistics globalStatistics;

/**
 * Выводит в stdout пункты меню
 */
void menuPrintOptions();

/**
 * Функция меню: открыть csv-файл с исходными
 * данными
 */
void menuLoadPlaylistFromCsvFile();

/**
 * Функция меню: вывести в stdout содержимое
 * плейлиста в виде таблицы
 */
void menuPrintPlaylist();

/**
 * Функция меню: вычислить и вывести статистику по
 * суммарной и средней длительности композиций в
 * каждом жанре.
 */
void menuCalcAndPrintStatistics();

/**
 * Функция меню: сохранить статистику по суммарной
 * и средней длительности композиций в каждом жанре
 * в csv-файл.
 */
void menuSaveStatisticsToCsvFile();

/**
 * Запуск диалогового консольного UI
 */
void runConsoleUI();

int main() {
    // Установка кодировки для поддержки рус. яз.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Обнуляем количество музыкальных композиций в плейлисте
    globalPlaylist.count = 0;
    globalStatistics.count = 0;

    // Запуск диалогового консольного UI
    runConsoleUI();

    return 0;
}

void menuPrintOptions() {
    printInfoText("/*** МУЗЫКАЛЬНЫЙ КАТАЛОГ ***\\\n");

    printf("Выберите желаемое действие:\n");
    printf("1. Загрузить плейлист из csv-файла\n");
    printf("2. Вывести содержимое плейлиста\n");
    printf("3. Вывести статистику по плейлисту\n");
    printf("4. Сохранить статистику в csv-файл\n");
    printf("0. Выход\n");
}

void menuLoadPlaylistFromCsvFile() {
    char filepath[36];
    char filename[30];

    strcpy(filepath, "data/");

    printf("Введите название файла: ");
    gets_s(filename, sizeof(filename));

    strncat(filepath, filename, sizeof(filename));

    int isRead = PlaylistReadFromCsv(filepath);

    if (isRead) {
        printOkText("Данные загружены из csv-файла!\n");
    } else {
        printErrorText("Не удалось загрузить файл!\n");
    }
}

void menuPrintPlaylist() {
    PlaylistPrintTable();
}

void menuCalcAndPrintStatistics() {
    StatisticsCalc();
    StatisticsPrintDiagramm();
}

void menuSaveStatisticsToCsvFile() {
    char filepath[44];
    char filename[30];

    strcpy(filepath, "data/results/");

    printf("Введите название файла: ");
    gets_s(filename, sizeof(filename));

    strncat(filepath, filename, sizeof(filename));

    StatisticsCalc();
    int isSaved = StatisticsSaveToCsv(filepath);

    if (isSaved) {
        printOkText("Статистика сохранена в csv-файл!\n");
    } else {
        printErrorText("Не удалось сохранить статистику в csv-файл!\n");
    }
}

void runConsoleUI() {
    int choice = -1;

    while (choice != 0) {
        system("cls");
        menuPrintOptions();

        scanf("%d", &choice);
        flushStdin();

        switch (choice) {
            case 1:
                menuLoadPlaylistFromCsvFile();
                break;
            case 2:
                menuPrintPlaylist();
                break;
            case 3:
                menuCalcAndPrintStatistics();
                break;
            case 4:
                menuSaveStatisticsToCsvFile();
                break;
            default:
                break;
        }

        if (choice != 0) {
            system("pause");
        }
    }
}
