
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
    printf("\n Задание выполнено!");// сообщение преподавателю
    _getch();
}

