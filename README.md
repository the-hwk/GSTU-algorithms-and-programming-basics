## Этапы написания простых программ
1. Прочитайте техническое задание. Основа любой программы: данные и алгоритмы обработки этих данных, поэтому определите в задании какие есть данные и каким образом их необходимо обработать.
2. Составьте список переменных, определите их тип и диапазон допустимых значений.
3. Составьте блок-схему программы.
4. Составьте тесты, охватывающие все возможные сценарии ввода данных.
5. Реализуйте программу согласно блок-схемы.
6. Выполните отладку программы используя подготовленные тесты.

## Требования к написанию программ
- ввод/вывод должен быть с сопроводительным текстом
	- например, текст при вводе данных: "Input a number of bunnies: "
	- например, текст при выводе данных (`10` - значение переменной): "There are `10` bunnies in total"
- название переменной должно описывать назначение этой переменной
	- никаких a, b, c - в названии должен быть отражен смысл (итераторы не в счет). Самодокументируемый код - очень хорошая практика.
	- например, переменная, которая хранит размер массива, должна быть названа: `array_size`
	- в случае, если описать назначение переменной через ее имя трудно, то назначение этой переменной должно быть описано комментарием
	- названия переменных записываются в нижнем регистре, а слова в названиях отделяются нижним подчеркиванием
```C
int my_int_variable = 0;
char *hello_str = "hello";
pid_t current_pid = fork();
```
- логически разделяйте код пустыми строками
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int array_size = 15;
    int* array = malloc(sizeof(int) * array_size);

    for (int i = 0; i < array_size; ++i) {
        array[i] = i * 2;
    }

    printf("%d", array[5]);

    return 0;
}
```
- описывайте код комментариями
	- пока Вы еще изучаете основы, желательно комментировать все, что для Вас в новинку, чтобы лучше запоминалось (особенно необходимо комментировать используемые функции: что они делают, какие входные параметры, что возвращают)
- i, j, k - стандартные названия для итераторов цикла
```C
int array[MAX_ARRAY_SIZE] = arrinit();

for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
	for (j = 0; j < MAX_ARRAY_SIZE; j++) {
		for (k = MAX_ARRAY_SIZE; k >= 0; k--) {
			dosmthng(i, j, k, array[i]);
		}
	}
}
```
- по возможности инициализируйте переменные при объявлении. Численные с помощью нуля, указатели — NULL
```C
int counter = 0, start_position = 0, unknown_position = 0;

struct dhcp_header *dhcp = NULL, *dhcp_temp = NULL;

char input_string[32] = { 0 };
```
- файл с программой должен иметь название `main` (и файл с исходным кодом, и исполняемый)

*Старайтесь сами изучать возможности изучаемого языка программирования. У Вас есть теория (на учебном портале), есть гугл. Заведите тетрадь или эл. блокнот и коллекционируйте все свои знания.*
