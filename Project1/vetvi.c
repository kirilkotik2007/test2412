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
/*
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>  // ← ОБЯЗАТЕЛЬНО для strcspn!

#define n 5

struct BANK {
    char name[20];
    float buy_course;
    float sell_course;
    char address[30];
    char phone[20];
};

void main(void) {
    setlocale(LC_ALL, "rus");

    struct BANK bank[n];  // массив из 5 банков
    int i;

    // Ввод данных
    for (i = 0; i < n; i++) {
        printf("\n------- Банк %d -------\n", i + 1);

        printf("Введите название банка: ");
        fgets(bank[i].name, 20, stdin);
        bank[i].name[strcspn(bank[i].name, "\n")] = '\0';  // ← исправлено

        printf("Введите курс покупки: ");
        scanf_s("%f", &bank[i].buy_course);

        printf("Введите курс продажи: ");
        scanf_s("%f", &bank[i].sell_course);

        while (getchar() != '\n');  // очистка буфера

        printf("Введите адрес: ");
        fgets(bank[i].address, 30, stdin);
        bank[i].address[strcspn(bank[i].address, "\n")] = '\0';  // ← исправлено

        printf("Введите телефон: ");
        fgets(bank[i].phone, 20, stdin);
        bank[i].phone[strcspn(bank[i].phone, "\n")] = '\0';  // ← исправлено
    }

    // Вывод данных
    printf("\n==== Введённые данные ====\n");
    for (i = 0; i < n; i++) {
        printf("\nБанк %d:\n", i + 1);
        printf("Название: %s\n", bank[i].name);
        printf("Курс покупки: %.2f\n", bank[i].buy_course);
        printf("Курс продажи: %.2f\n", bank[i].sell_course);
        printf("Адрес: %s\n", bank[i].address);
        printf("Телефон: %s\n", bank[i].phone);
    }


    // а) Выяснить название и адрес обменного пункта с максимальным курсом покупки валюты.
    int max_index = 0;
    for (i = 1; i < n; i++)
    {
        if (bank[i].buy_course > bank[max_index].buy_course)
        {
            max_index = i;
        }
    }
    printf("\n=== а) Пункт с максимальным курсом покупки ===\n");
    printf("Название: %s\n", bank[max_index].name);
    printf("Адрес: %s\n", bank[max_index].address);
    printf("Курс покупки: %.2f\n", bank[max_index].buy_course);


    // б) Выяснить название адрес телефон обменного пункта с минимальным курсом продажи валюты.
    int min_index = 0;
    for (i = 1; i < n; i++)
    {
        if (bank[i].sell_course < bank[min_index].sell_course)
        {
            min_index = i;
        }
    }
    printf("\n=== б) Пункт с минимальным курсом покупки ===\n");
    printf("Название: %s\n", bank[min_index].name);
    printf("Адрес: %s\n", bank[min_index].address);
    printf("Курс продажи: %.2f\n", bank[min_index].sell_course);
    printf("Телефон: %f", bank[min_index].sell_course);

    
    // в) Вывести адреса и названия обменных пунктов с одинаковыми курсами покупки.
    printf("\n=== в) Пункты с одинаковым курсом покупки ===\n");
    int found = 0;  // флаг

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bank[i].buy_course == bank[j].buy_course)
            {
                printf("Пункт \"%s\" (%s) и пункт \"%s\" (%s) — курс покупки %.2f\n", bank[i].name, bank[i].address, bank[j].name, bank[j].address, bank[i].buy_course);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("Нет пунктов с одинаковым курсом покупки.\n");
    }
    // г) Вывести названия, адреса и телефоны обменных пунктов с совпадающими курсами продажи валюты.

    printf("\n=== г) Пункты с совпадающими курсами продажи валюты ===\n");

    found = 0;  // флаг

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bank[i].sell_course == bank[j].sell_course)
            {
                printf("Пункт \"%s\" (%s) и пункт \"%s\" (%s) — курс продажи %.2f\n", bank[i].name, bank[i].address, bank[j].name, bank[j].address, bank[i].buy_course);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("Нет пунктов с одинаковым курсом продажи.\n");
    }
    _getch();
}
*/