/*
Это заголовочный файл. Он содержит прототипы функций для работы
с объектами предметной области "Рекламные объявления".

Реализация этих функций может быть любой. Т.е. Вы можете создать
несколько файлов, в которых реализовано несколько вариантов этих функций, 
а в файле main выбирать нужную версию путем изменения подключаемого файла
реализации.
*/

#ifndef ADVERT_H
#define ADVERT_H

/**
 * Тип объявления
 */
typedef enum {
    PRIVATE,
    COMMERCIAL
} Type;

/**
 * Дата
 * @param day День
 * @param month Месяц
 * @param year Год
 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 * Рекламное объявление
 * @param fullname ФИО заказчика
 * @param type Тип объявления
 * @param date Дата выхода объявления
 * @param text Текст объявления
 */
typedef struct {
    char fullname[30];
    Type type;
    Date date;
    char text[300];
} Advert;



/**
 * Ввод типа объявления
 * @return Тип объявления
 */
Type inputType();

/**
 * Ввод даты
 * @return Дата
 */
Date inputDate();

/**
 * Ввод объявления
 * @return объявление
 */
Advert inputAdvert();

/**
 * Коллекция для хранения объявлений
 * @param count Количество объявлений
 * @param elements Массив объектов структур, описывающих объявление
 */
typedef struct {
    int count;
    Advert elements[10];
} AdvertsCollection;

// Здесь хранятся объявления
// С помощью ключевого слова extern указываем,
// что эта переменная является общей для всех файлов,
// в которых подключается текущий заголовочный файл
extern AdvertsCollection db;



/**
 * Чтение бинарного файла с коллекцией рекламных объявлений
 * @param filepath Путь к бинарному файлу
 */
AdvertsCollection readFromBinaryFile(char *filepath);

/**
 * Запись коллекции рекламных объявлений в бинарный файл
 * @param filepath Путь к бинарному файлу (будет создан новый, если не существует)
 * @param collection Коллекция с рекламными объявлениями
 */
void writeToBinaryFile(char *filepath, AdvertsCollection collection);

/**
 * Преобразование типа объявления в строку
 * @param type Тип объявления
 * @return Строковое представление типа объявления
 */
char* typeToStr(Type type);

/**
 * Преобразование даты объявления в строку
 * @param date Дата
 * @return Строковое представление даты
 */
char* dateToStr(Date date);

/**
 * Вывод информации об объявлении
 * @param advert Объявление
 * @param number Номер (для вывода)
 */
void printAdvert(Advert advert, int number);

/**
 * Вывод информации о всех объявлениях
 */
void printAllAdverts();

/**
 * Добавление объявления в массив
 * @param advert Объявление
 * @return 1, если объявление добавлено, иначе 0 (коллекция заполнена)
 */
char saveAdvert(Advert advert);

/**
 * Обновление объявления по указанному индексу
 * @param index Индекс объявления, которое необходимо изменить
 * @param advert Объявление
 * @return 1, если объявление обновлено, иначе 0 (если объявления
 * по указанному индексу не существует
 */
char updateAdvert(int index, Advert advert);

/**
 * Удаление объявления по индексу
 * @param index Индекс объявления
 * @return 1, если объявление удалено, иначе 0 (если объявления
 * по указанному индексу не существует)
 */
char removeAdvert(int index);

/**
 * Удаление объявлений по месяцу их выхода
 * @param month Месяц выхода объявления
 * @return Количество удаленных объявлений
 */
int removeAdvertsByMonth(int month);

#endif