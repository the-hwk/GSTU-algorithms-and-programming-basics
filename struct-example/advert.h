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
 * @param fullName ФИО заказчика
 * @param type Тип объявления
 * @param date Дата выхода объявления
 * @param text Текст объявления
 */
typedef struct {
    char fullName[100];
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
 * Преобразование типа объявления в строку
 * @param type Тип объявления
 */
char* typeToStr(Type type);

/**
 * Преобразование даты объявления в строку
 * @param date Дата
 */
char* dateToStr(Date date);

/**
 * Вывод информации об объявлении
 * @param advert Объявление
 */
void printAdvert(Advert advert);

/**
 * Добавление объявления в массив
 * @param advert Объявление
 */
void saveAdvert(Advert advert);

/**
 * Обновление объявления по указанному индексу
 * @param index Индекс объявления, которое необходимо изменить
 * @param advert Объявление
 */
void updateAdvert(int index, Advert advert);

/**
 * Удаление объявления по индексу
 * @param index Индекс объявления
 */
void removeAdvert(int index);



/**
 * Коллекция для хранения объявлений
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

#endif