#include <stdio.h>
#include <string.h>

int z_1 ();
int cou(long long num);
int pz1(long long num);
int pz2(long long num);
int pz3(long long num);
int pz4(long long num);
int pz5(long long num);
int pz6(long long num);      
long long pz7(long long num);
long long pz8(long long num, int count); 
int pz9(long long num);      
void pz10(long long num);    
int pz11(long long num, int count); 
long long pz12(long long num);


int main (){

    // //задание 1
    // printf("--- Задание 1 ---\n");
    // int i,j;
    // z_1();

    char repeat; // Переменная для повтора
printf("\n--- Задание 2 ---\n");
    do {
        
        long long num;
        printf("Введите число: ");
        scanf("%lld", &num);

        int count = cou(num); //кол-во цифр
        printf("кол-во цифр: %d\n", count);
    //подзадание 1
        int count_3 = pz1(num); //кол-во троек
        printf("\n1. кол-во троек: %d", count_3);
    //пз 2
        int count_last=pz2(num); //последнее чсило повторяется...
        printf("\n2. последняя цифра повторяется %d раз(а)",count_last);
    //пз 2
        int chet=pz3(num); //четные
        printf("\n3. кол-во четных чисел: %d",chet);
    //пз 4
        int count5=pz4(num); //числа больше 5
        printf("\n4. кол-во чисел > 5: %d",count5);
    //пз 5
        int sum=pz5(num); //сумма четных
        printf("\n5. сумма четных: %d",sum);

        //пз 6;
        int sum_ge_7 = pz6(num);
        printf("\n6. сумма цифр >= 7: %d", sum_ge_7);

        //пз 7
        long long prod_no_zero = pz7(num);
        printf("\n7. произведение (без 0): %lld", prod_no_zero);

        //пз 8
        if (count >= 2) {
            long long prod_8 = pz8(num, count);
            printf("\n8. произведение предпоследней и второй цифр: %lld", prod_8);
        } else {
            printf("\n8. недостаточно цифр");
        }

        //пз 9
        int sum_even_no_last = pz9(num);
        printf("\n9. сумма четных (без последней): %d", sum_even_no_last);

        // пз 10
        printf("\n10. пары одинаковых рядом: ");
        pz10(num);

        //  пз 11
        if (count % 2 == 0) {
            if (pz11(num, count) == 1) printf("\n11. суммы половин РАВНЫ");
            else printf("\n11. суммы половин НЕ РАВНЫ");
        } else {
            printf("\n11. нечетное кол-во цифр (нельзя разделить пополам)");
        }

        // пз 12 
        long long prod_12 = pz12(num);
        printf("\n12. произв. сумм четных и нечетных разрядов: %lld\n", prod_12);

        // --- Вопрос про повтор ---
        printf("\nХотите ввести другое число? (y - да, любой другой символ - выход): ");
        scanf(" %c", &repeat); // Пробел перед %c обязателен

    } while (repeat == 'y' || repeat == 'Y');

    printf("\nПрограмма завершена.\n"); 
    return 0;
}

int z_1(){
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            printf("%4d",i*j);
            if (j>=i) break;
        }
        printf("\n");
    }
    //1.3 подзадание
    printf("\n>> вариант 6\n");
    for (int i=1;i<=9;i++) {
        for (int j=1;j<=9;j++) {
            printf("%4d",i);
            if (j>=i) break;
        }
        printf("\n");
    }
    return 0;
}

int cou(long long num){
            //узнаем кол-во цифр
    long long i = num;
    int n = 0;
    while (i > 0) {
        n++;
        i = i / 10;
    }
    return n;
}

int pz1(long long num){
    //узнаем кол-во троек
    int count_3 = 0;
    long long i = num;
    while (i > 0) {
        if (i % 10 == 3) count_3++;
        i = i / 10;
    }
    return count_3;
}

int pz2(long long num){
    int last = num % 10;
    int count_last = 0;
    long long i = num;
    while (i > 0) {
        if (i % 10 == last) count_last++;
        i = i / 10;
    }
    return count_last;
}

int pz3(long long num){
    int chet = 0;
    long long i = num;
    while (i > 0) {
        if ((i % 10) % 2 == 0) chet++;
        i = i / 10;
    }
    return chet;
}

int pz4(long long num){
    int count5 = 0;
    long long i = num;
    while (i > 0) {
        if (i % 10 > 5 ) count5++;
        i = i / 10;
    }
    return count5;
}

int pz5(long long num) {
    int sum = 0;
    long long i = num;
    while (i > 0) {
        int d = i % 10;
        if (d % 2 != 0) {
            sum += d;
        }
        i = i / 10;
    }
    return sum;
}

int pz6(long long num) { 
    int sum = 0;
    long long i = num;
    while (i > 0) {
        int d = i % 10;
        if (d >= 7) {
            sum += d;
        }
        i = i / 10;
    }
    return sum;
}

long long pz7(long long num) { // 7. Произведение без 0
    long long prod = 1;
    long long i = num;
    while (i > 0) {
        int d = i % 10;
        if (d != 0) prod *= d;
        i = i / 10;
    }
    return prod;
}

long long pz8(long long num, int count) { 
    int penult = (num / 10) % 10;
    long long p = 1;
    for (int i = 0; i < count - 2; i++) {
        p = p * 10;//для нахождения 2(теперь 1) числа
    }
    int second = (num / p) % 10;
    return (long long)penult * second;
}

int pz9(long long num) { 
    int sum = 0;
    long long i = num / 10; // Отбрасываем последнюю
    while (i > 0) {
        int d = i % 10;
        if (d % 2 == 0) {
            sum += d;
        }
        i = i / 10;
    }
    return sum;
}

void pz10(long long num) { 
    long long i = num;
    int prev = -1;
    int found = 0;
    while (i > 0) {
        int d = i % 10;
        if (d == prev) {
            printf("%d%d ", d, prev);
            found = 1;
        }
        prev = d;
        i = i / 10;
    }
    if (found == 0) printf("нет одинаковых рядом стоящих цифр");
}

int pz11(long long num, int count) { 
    int mid = count / 2;
    long long p = 1;
    for (int i = 0; i < mid; i++) {
        p = p * 10;
    }
    long long first_half = num / p;
    long long second_half = num % p;
    
    int sum1 = 0, sum2 = 0;
    while (first_half > 0) { 
        sum1 += first_half % 10; 
        first_half /= 10; 
    }
    while (second_half > 0) { 
        sum2 += second_half % 10; 
        second_half /= 10; 
    }
    
    if (sum1 == sum2) return 1;
    else return 0;
}

long long pz12(long long num) { 
    int sum_even = 0; // четные разряды
    int sum_odd = 0;  // нечетные разряды
    long long i = num;
    int pos = 1; // младший разряд (с конца) - 1
    
    while (i > 0) {
        int d = i % 10;
        if (pos % 2 == 0) {
            sum_even += d;
        } else {
            sum_odd += d;
        }
        pos++;
        i = i / 10;
    }
    return (long long)sum_even * sum_odd;
}
