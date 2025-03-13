#include <string.h>    // для работы со строками
#include <stdio.h>

/**
 * Сдвиг символов в строке вправо
 * @param str строка, в которой необходимо выполнить сдвиг
 * @param from_pos позиция, с которой необходимо выполнить сдвиг (не включая ее)
 * @param shift_value величина смещения
 */
void shift(char* str, int from_pos, int shift_value) {
    int new_size = strlen(str) + shift_value - 1;

    for (int i = new_size; i > from_pos; i--) {
        str[i + shift_value] = str[i];
    }
}

/**
 * Задача: вставить после символов '.' два пробела.
 * Посчитать количество "C+" перед символом 'D'.
 */
int main() {
    char data_string[100];

    printf("Write a string: ");
    // (примеч.) для заполнения строки символами из стандартного потока ввода
    fgets(data_string, sizeof(data_string), stdin);

    printf("---\n");

    /*
        Поиск символов и вставка символов после них
    */
    const int  SHIFT       = 2;      // кол-во вставляемых символов (смещение строки)
    const char SEARCH_CHAR = '.';    // символ, после которого нужна вставка
    const char INSERT_CHAR = ' ';    // вставляемый символ
    for (int i = 0; i < strlen(data_string); i++)
    {
        if (data_string[i] == SEARCH_CHAR) {
            shift(data_string, i, SHIFT);    // смещаем символы в строке

            // и вставляем нужные символы
            for (int j = 1; j <= SHIFT; j++)
            {
                data_string[i + j] = INSERT_CHAR;
            }
        }
    }

    /*
        Подсчет кол-ва подстрок в строке
    */
    const char STR_TO_SEARCH[]   = "C+D";          // искомая подстрока
    const int  STR_TO_SEARCH_LEN = strlen(STR_TO_SEARCH);
    char*      substr_buffer     = data_string;    // буфер символов для упрощения подсчета (изначально хранит исходн. строку)
    int        substr_count      = -1;             // кол-во найденных подстрок
    
    do {
        substr_count++;
        substr_buffer = strstr(substr_buffer, STR_TO_SEARCH);    // поиск подстроки в строке (читайте документацию к этой функц.)

        /* Если указатель не NULL (т.е. подстрока найдена и функция strstr
        вернула указатель на первый символ подстроки в исходной строке),
        то смещаем указатель на длину подстроки, чтобы поиск на след. итерации
        выполнялся корректно
        */
        if (substr_buffer != NULL) {
            substr_buffer += STR_TO_SEARCH_LEN;
        }
    } while (substr_buffer != NULL);



    printf("1. Processed string: %s", data_string);
    printf("2. Count of \"%s\": %d", STR_TO_SEARCH, substr_count);


    
    return 0;
}
