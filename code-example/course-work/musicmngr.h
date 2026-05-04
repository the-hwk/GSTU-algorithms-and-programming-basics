/* Это заголовочный файл. Он содержит прототипы функций для работы
 * с объектами предметной области "Музыкальный каталог".
 * Реализация этих функций может быть любой. Т.е. Вы можете создать
 * несколько файлов, в которых реализовано несколько вариантов этих функций,
 * а в файле main.c выбирать нужную версию путем изменения подключаемого файла
 * реализации.
 */
#ifndef MUSIC_MNGR_H
#define MUSIC_MNGR_H

#define PLAYLIST_SIZE 100
#define STATISTICS_SIZE 10

/**
 * Перечисление жанров музыки
 */
typedef enum {
    ROCK,
    POP,
    DANCE,
    HIP_HOP,
    UNKNOWN
} Genre;

/**
 * Продолжительность музыкальной композиции
 * @param minutes Минут
 * @param seconds Секунд
 */
typedef struct
{
    int minutes;
    int seconds;
} Duration;

/**
 * Музыкальная композиция
 * @param index Номер
 * @param artist Исполнитель
 * @param title Заголовок
 * @param genre Жанр
 * @param year Год
 * @param duration Продолжительность
 */
typedef struct
{
    int index;
    char artist[30];
    char title[30];
    Genre genre;
    int year;
    Duration duration;
} Track;

/**
 * Коллекция для хранения музыкальных композиций
 * @param count Количество композиций
 * @param elements Массив объектов структур, описывающих композицию
 */
typedef struct {
    int count;
    Track elements[PLAYLIST_SIZE];
} Playlist;

/**
 * Коллекция для хранения отсортированных музыкальных композиций
 * @param count Количество композиций
 * @param elements Массив указателей на структуру, описывающую
 * композицию
 */
typedef struct {
    int count;
    Track* elements[PLAYLIST_SIZE];
} PlaylistSorted;

/**
 * Статистика по конкретному жанру
 * @param genre Жанр
 * @param tracksCount Количество композиций этого жанра
 * @param summaryDuration Общая длительность
 * @param meanDuration Средняя длительность
 */
typedef struct {
    Genre genre;
    int tracksCount;
    int summaryDuration;
    int meanDuration;
} GenreStatistics;

/**
 * Статистика музыкальных композиций по жанрам
 * @param count Количество жанров
 * @param elements Массив объектов структур, описывающих жанр
 */
typedef struct {
    int count;
    GenreStatistics elements[STATISTICS_SIZE];
} Statistics;

/* Здесь хранится плейлист.
 * С помощью ключевого слова extern указываем,
 * что эта переменная является общей для всех файлов,
 * в которых подключается текущий заголовочный файл
 */
extern Playlist globalPlaylist;
extern Statistics globalStatistics;

/**
 * Чтение данных о плейлисте из csv-файла в
 * глобальный объект структуры Playlist globalPlaylist
 * @param filepath Путь к csv-файлу
 * @return Количество прочитанных записей или 0, если ошибка
 * чтения файла
 */
int PlaylistReadFromCsv(const char *filepath);

/**
 * Вывод в stdout глобального плейлиста в табличном виде
 */
void PlaylistPrintTable();

/**
 * Расчет статистики по суммарной и средней длительности
 * композиций в каждом жанре
 */
void StatisticsCalc();

/**
 * Вывод расчитанной статистики по суммарной и средней длительности
 * композиций в каждом жанре.
 * Примечание: перед вызовом этой функции необходимо вызвать
 * функцию для расчета статистики
 */
void StatisticsPrintDiagramm();

/**
 * Сохранение статистики по суммарной и средней длительности
 * композиций в каждом жанре в csv-файл.
 * Примечание: перед вызовом этой функции необходимо вызвать
 * функцию для расчета статистики
 * @param filepath Путь к csv-файлу
 * @return Количество записанных записей или 0, если ошибка
 * открытия файла
 */
int StatisticsSaveToCsv(const char *filepath);

#endif
