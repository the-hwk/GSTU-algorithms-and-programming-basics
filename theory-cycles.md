### Циклы

Есть два способа создания цикла: с помощью оператора `for` и `while`. Выбор оператора цикла зависит от наличия условия преждевременного выхода из цикла.

Например, если необходимо пройтись в цикле от начала до конца, то используется оператор `for`:

```C
float x_start = 0.0f;
float x_end   = 15.3f;
float x_step    = 0.1f;

float y       = 0.0;

int n = ((x_end - x_start) / x_step) + 1;

for (int i = 0; i < n; i++) {
    y = x * 2;
    printf("y(%.3f) = %.3f", x, y);
    x += x_step;
}
```

А если также необходимо пройтись в цикле от начала до конца, но при этом есть условие преждевременного выхода из цикла, то используется оператор `while`:

```C
char stop   = 0;

float x     = 0.0f;
float x_end = 10.0f;
float step  = 0.1f;

const float TRESHOLD = 7.3f;

scanf("%f", &step);

while (x <= x_end && !stop) {
    if (x > TRESHOLD) {
	    stop = 1;
	}

	x += step;
}

if (stop) {
    printf("x has reached on value %.3f", x);
} else {
    printf("x has not reached the threshold");
}
```

Операторы `break` и `goto` использовать **ЗАПРЕЩЕНО**, т.к. они ухудшают читаемость кода.