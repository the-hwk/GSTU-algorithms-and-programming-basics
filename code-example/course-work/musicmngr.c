#include "musicmngr.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CSV_COLS_COUNT   6      // Количество столбцов исх. данных
#define CSV_COL_MAX_SIZE 31     // Макс. кол-во символов значения столбца

#define GENRE_STR_SIZE      11  // Макс. размер строки жанра
#define DURATION_STR_SIZE   7   // Макс. размер строки длительности
#define TRACK_STR_SIZE      100 // Макс. размер строки записи муз. комп.
#define STATISTICS_STR_SIZE 50  // Макс. размер строки записи статистики

// CSV-заголовки для файлов
#define PLAYLIST_CSV_HEADER   "Номер;Исполнитель;Название;Жанр;Год;Длительность\n"
#define STATISTICS_CSV_HEADER "Номер;Жанр;Общая длительность;Средняя Длительность\n"

// Строки форматирования для вывода
#define TABLE_PLAYLIST_HEAD_TEMPLATE "|%5s|%-30s|%-30s|%-10s|%-4s|%-12s|\n"
#define TABLE_PLAYLIST_ROW_TEMPLATE  "|%5d|%-30s|%-30s|%-10s|%d|%-12s|\n"

/**
 * Разбивает строку на части по разделителю
 * @param string Строка
 * @param separator Разделитель
 * @param parts Массив с частями строки
 * @return Количество частей
 */
int split(const char *string, const char separator, char parts[CSV_COLS_COUNT][CSV_COL_MAX_SIZE]) {
    // Code
}

/**
 * Заполняет экземпляр перечисления Genre данными из строки.
 * Если элемент перечисления отсутсвует, то устанавливается
 * значение UNKNOWN
 * @param string Строка с названием жанра
 * @param genreToFill Указатель на перечисление Genre
 */
void GenreFromString(const char *string, Genre *genreToFill) {
    // Code
}

/**
 * Преобразует перечисление Genre в строку
 * @param genre Указатель на перечисление Genre
 * @param destination Строка назначения
 */
void GenreToString(const Genre *genre, char destination[GENRE_STR_SIZE]) {
    // Code
}

/**
 * Заполняет экземпляр структуры Duration данными из строки
 * @param string Строка с длительностью формата mm:ss (минуты:секунды)
 * @param durationToFill Указатель на структуру Duration
 */
void DurationFromString(const char *string, Duration *durationToFill) {
    // Code
}

/**
 * Преобразует структуру Duration в строку формата
 * mm:ss (минуты:секунды)
 * @param genre Указатель на структуру Duration
 * @param destination Строка назначения
 */
void DurationToString(const Duration *duration, char destination[DURATION_STR_SIZE]) {
    // Code
}

/**
 * Преобразует длительность музыкальной композиции из секунд
 * в экземпляр структуры Duration
 * @param duration Указатель на структуру Duration
 * @param seconds Длительность в секундах
 */
void DurationFromSeconds(Duration *duration, const int seconds) {
    // Code
}

/**
 * Преобразует экземпляр структуры Duration в секунды
 * @param duration Указатель на структуру Duration
 * @return Длительность музыкальной композиции в секундах
 */
int DurationToSeconds(const Duration *duration) {
    // Code
}

/**
 * Заполняет экземпляр структуры Track данными из строки
 * формата csv
 * @param string Строка формата csv с данными о музыкальной
 * композиции (ID;Artist;Title;Genre;Year;Duration)
 * @param trackToFill Указатель на структуру Track
 */
void TrackFromCsvString(const char *string, Track *trackToFill) {
    // Code
    // Здесь вызываются функции:
    // - GenreFromString
    // - DurationFromString
}

/**
 * Вывод в stdout шапки таблицы
 */
void PlaylistPrintTableHead() {
    // Code
}

/**
 * Вывод в stdout футера таблицы
 */
void PlaylistPrintTableFooter() {
    // Code
}

/**
 * Выводит в stdout строку таблицы
 * @param track Указатель на структуру Track
 */
void TrackPrintTableRow(const Track *track) {
    // Code
    // Здесь вызываются функции:
    // - GenreToString
    // - DurationToString
}

/**
 * Сбрасывает статистику
 */
void StatisticsReset() {
    for (int i = 0; i < globalStatistics.count; i++) {
        globalStatistics.elements[i].tracksCount = 0;
        globalStatistics.elements[i].meanDuration = 0;
        globalStatistics.elements[i].summaryDuration = 0;
    }

    globalStatistics.count = 0;
}

/**
 * Сортировка плейлиста по жанру (в алфавитном порядке)
 * @param sorted Указатель на структуру PlaylistSorted
 */
void PlaylistSortByGenre(PlaylistSorted *sorted) {
    // Code
}

/**
 * Преобразует экземпляр структуры GenreStatistics в csv-строку
 * @param statistics Указатель на структуру GenreStatistics
 * @param number Порядковый номер
 * @param destination Строка назначения
 */
void StatisticsToCsvString(const GenreStatistics *statistics, int number, char destination[STATISTICS_STR_SIZE]) {
    // Code
    // Здесь вызываются функции:
    // - GenreToString
    // - DurationFromSeconds
    // - DurationToString
}



/* -------------------------------------------------- */
/* Реализации функций заголовочного файла musicmngr.h */
/* -------------------------------------------------- */

int PlaylistReadFromCsv(const char *filepath) {
    // Code
    // Здесь вызываются функции:
    // - TrackFromCsvString
}

void PlaylistPrintTable() {
    // Code
    // Здесь вызываются функции:
    // - PlaylistPrintTableHead
    // - TrackPrintTableRow
    // - PlaylistPrintTableFooter
}

void StatisticsPrintDiagramm() {
    // Code
}

void StatisticsCalc() {
    // Code
    // Здесь вызываются функции:
    // - StatisticsReset
    // - PlaylistSortByGenre
}

int StatisticsSaveToCsv(const char *filepath) {
    // Code
    // Здесь вызываются функции:
    // - StatisticsToCsvString
}
