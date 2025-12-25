/* 1
#include <stdio.h>
#include <locale.h>
#include <conio.h>


int main() {
    setlocale(LC_ALL, "rus");
    int n, a, b, c, d;


    printf("\n Введите четырёхзначное число N: ");
    scanf_s("%d", &n);

    if (n < 1000 || n > 9999) {
        printf("Ошибка: Число должно быть четырёхзначным!\n");
        return 1;
    }

    a = n / 1000;
    b = (n / 100) % 10;
    c = (n / 10) % 10;
    d = n % 10;

    if (a != b && a != c && a != d && b != c && b != d && c != d) {
        printf("\n Истинно: все цифры числа %d различны.", n);
    }
    else {
        printf("\n Ложно: в числе %d есть одинаковые цифры.", n);
    }

    _getch();
}
*/
/* 2
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus");
    float v1, m1, v2, m2, p1, p2;

    printf("\n Введите объем и массу первого тела через пробел: ");
    if (scanf_s("%f %f", &v1, &m1) != 2) {
        printf("\n Ошибка ввода первого тела!\n");

        return 1;
    }
    printf("\n Введите объем и массу второго тела через пробел: ");
    if (scanf_s("%f %f", &v2, &m2) != 2) {
        printf("\n Ошибка ввода второго тела!\n");

        return 1;
    }
    if (v1 <= 0 || v2 <= 0) {
        printf("\n Объем не может быть нулевым или отрицательным!\n");

        return 1;
    }


    p1 = m1 / v1;
    p2 = m2 / v2;

    if (p1 > p2) {
        printf("\n Плотность первого тела выше плотности второго тела: %.2f кг/м³!\n", p1);
    }
    else if (p2 > p1) {
        printf("\n Плотность второго тела выше плотности первого тела: %.2f кг/м³!\n", p2);
    }
    else {
        printf("\n Плотности тел равны: %.2f кг/м³!\n", p1);
    }


    _getch();
}
*/
/* 3

#include <stdio.h>
#include <conio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "rus");
    int a1, b, c, x, a;
    int sum;


    printf("\nВведите трехзначное число N: ");
    if (scanf_s("%d", &x) != 1) {
        printf("Ошибка ввода числа!\n");
    }
    printf("Введите число a: ");
    if (scanf_s("%d", &a) != 1) {
        printf("Ошибка ввода числа a!\n");
    }

    if (x < 100 || x > 999) {
        printf("Ошибка: Число должно быть трехзначным!\n");
    }


    a1 = x / 100;
    b = (x / 10) % 10;
    c = x % 10;


    sum = a1 + b + c;


    if (sum % a == 0) {
        printf("\nИстинно: сумма цифр числа %d (%d) кратна числу %d.\n", x, sum, a);
    }
    else {
        printf("\nЛожно: сумма цифр числа %d (%d) не кратна числу %d.\n", x, sum, a);
    }

    _getch();
}

*/
// 4
/*
#include <stdio.h>
#include <conio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "rus");

    int day, month;

    printf("\n Введите месяц(1-12): ");
        if (scanf_s("%d", &month) != 1) {
            printf("\n Ошибка! Введите корректное число(1-12): ");
            _getch();
        }
        if (month == 2) {
            printf("Введите день (1-28): ");
        }
        if (scanf_s("%d", &day) != 1) {
            printf("\n Ошибка! Введите корректное число(1-31): ");
            _getch();
        }


        if (day < 1 || day > 31) {
            printf("\n Ошибка! Введите корректное число(1-31): ");
            _getch();
        }
        if (month < 1 || month > 12) {
            printf("\n Введите корректное число(1-12): ");

        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            printf("Ошибка: В месяце %d максимум 30 дней!\n", month);
        }
        else if (month == 2 && day > 28) {
            printf("Ошибка: В феврале максимум 28 дней!\n");
        }
        else {
            printf("Дата %d.%d корректна.\n", day, month);
        }
        _getch();
    }
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
#define LEN 50

struct Exchange {
    char name[LEN];
    float buy;
    float sell;
    char address[LEN];
    char phone[LEN];
};

void main(void) {
    setlocale(LC_ALL, "Russian");
    struct Exchange ex[N];

    // Ввод данных о каждой валюте
    for (int i = 0; i < N; i++) {
        printf("Введите информацию для валюты %d:\n", i + 1);
        printf("Название пункта обмена: ");
        fgets(ex[i].name, LEN, stdin);
        ex[i].name[strcspn(ex[i].name, "\n")] = '\0'; // Удаление символа новой строки

        printf("Курс покупки: ");
        while (scanf_s("%f", &ex[i].buy) != 1) {
            printf("Неверный ввод. Попробуйте снова: ");
            while (getchar() != '\n'); // Очистка буфера
        }

        printf("Курс продажи: ");
        while (scanf_s("%f", &ex[i].sell) != 1) {
            printf("Неверный ввод. Попробуйте снова: ");
            while (getchar() != '\n'); // Очистка буфера
        }

        getchar(); // Для очистки символа новой строки после ввода числа

        printf("Адрес: ");
        fgets(ex[i].address, LEN, stdin);
        ex[i].address[strcspn(ex[i].address, "\n")] = '\0'; // Удаление символа новой строки

        printf("Телефон: ");
        fgets(ex[i].phone, LEN, stdin);
        ex[i].phone[strcspn(ex[i].phone, "\n")] = '\0'; // Удаление символа новой строки

        printf("\n");
    }

    // а) Максимальный курс покупки
    int maxBuy = 0;
    for (int i = 1; i < N; i++) {
        if (ex[i].buy > ex[maxBuy].buy)
            maxBuy = i;
    }
    printf("а) Максимальный курс покупки:\n");
    printf("%s, %s\n\n", ex[maxBuy].name, ex[maxBuy].address);

    // б) Минимальный курс продажи
    int minSell = 0;
    for (int i = 1; i < N; i++) {
        if (ex[i].sell < ex[minSell].sell)
            minSell = i;
    }
    printf("б) Минимальный курс продажи:\n");
    printf("%s, %s, %s\n\n", ex[minSell].name, ex[minSell].address, ex[minSell].phone);

    // в) Одинаковые курсы покупки
    printf("в) Одинаковые курсы покупки:\n");
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (ex[i].buy == ex[j].buy) {
                printf("%s (%s) и %s (%s)\n", ex[i].name, ex[i].address, ex[j].name, ex[j].address);
            }
        }
    }
    printf("\n");

    printf("\n Количество положительных чисел = %d\n", count);
    printf("\n conflict test");
    _getch();
}
