#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

// ==================== ЗАДАНИЕ 1 ====================
void task1() {
    printf("\n========== ЗАДАНИЕ 1 ==========\n");
    printf("Диапазон [-150; 150]\n");
    printf("Найти непрерывную последовательность отрицательных чисел\n");
    printf("с максимальной суммой элементов\n\n");
    
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Неверный размер.\n");
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    srand(time(NULL));
    int *ptr = arr;
    for (int i = 0; i < n; i++) {
        *ptr = rand() % 301 - 150;  // [-150; 150]
        ptr++;
    }

    printf("Сгенерированный массив:\n");
    ptr = arr;
    for (int i = 0; i < n; i++) {
        printf("%4d ", *ptr);
        ptr++;
    }
    printf("\n\n");

    // Поиск последовательности отрицательных чисел с максимальной суммой
    int max_sum = INT_MIN;
    int start_idx = -1, end_idx = -1;
    int cur_start = -1;
    int cur_sum = 0;
    int in_sequence = 0;

    ptr = arr;
    for (int i = 0; i < n; i++) {
        if (*ptr < 0) {
            if (!in_sequence) {
                in_sequence = 1;
                cur_start = i;
                cur_sum = 0;
            }
            cur_sum += *ptr;
        } else {
            if (in_sequence) {
                if (cur_sum > max_sum) {
                    max_sum = cur_sum;
                    start_idx = cur_start;
                    end_idx = i - 1;
                }
                in_sequence = 0;
            }
        }
        ptr++;
    }
    
    if (in_sequence && cur_sum > max_sum) {
        max_sum = cur_sum;
        start_idx = cur_start;
        end_idx = n - 1;
    }

    if (start_idx != -1) {
        printf("Результат:\n");
        printf("  Максимальная сумма: %d\n", max_sum);
        printf("  Индексы: с %d по %d\n", start_idx, end_idx);
        printf("  Элементы последовательности: ");
        for (int i = start_idx; i <= end_idx; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Отрицательных последовательностей не найдено.\n");
    }

    free(arr);
}

// ==================== ЗАДАНИЕ 2 ====================
int* createArray(int *size) {
    printf("Введите размер массива: ");
    scanf("%d", size);
    if (*size <= 0) return NULL;

    int *arr = (int*)malloc(*size * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < *size; i++) {
        arr[i] = rand() % 201 - 100;  // [-100; 100]
    }
    return arr;
}

void printArray(int *arr, int size, const char *title) {
    printf("%s", title);
    for (int i = 0; i < size; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

int* deleteEvenIndices(int *arr, int *size) {
    int new_size = (*size + 1) / 2;  // удаляем четные индексы (0,2,4...)
    int *new_arr = (int*)malloc(new_size * sizeof(int));
    if (!new_arr) {
        printf("Ошибка памяти при удалении.\n");
        return arr;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ==================== ЗАДАНИЕ 1 (ВАРИАНТ 8) ====================
// Диапазон [-50; 50]
// Подсчитать количество пар соседних элементов с разными знаками
void task1() {
    printf("\n========== ЗАДАНИЕ 1 ==========\n");
    printf("Диапазон [-50; 50]\n");
    printf("Подсчитать количество пар соседних элементов с разными знаками\n\n");
    
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Неверный размер.\n");
        return;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    // Заполнение случайными числами от -50 до 50
    srand(time(NULL));
    int *ptr = arr;
    for (int i = 0; i < n; i++) {
        *ptr = rand() % 101 - 50;  // [-50; 50]
        ptr++;
    }

    // Вывод массива (без индексации)
    printf("Сгенерированный массив:\n");
    ptr = arr;
    for (int i = 0; i < n; i++) {
        printf("%4d ", *ptr);
        ptr++;
    }
    printf("\n\n");

    // Подсчёт пар соседних элементов с разными знаками
    // Пара - это два соседних элемента (i и i+1)
    int count = 0;
    ptr = arr;
    for (int i = 0; i < n - 1; i++) {
        int current = *ptr;
        int next = *(ptr + 1);
        
        // Разные знаки: один >0, другой <0
        // Ноль считаем положительным? Обычно да, но уточним:
        // По условию "разные знаки" - значит один >0, другой <0
        if ((current > 0 && next < 0) || (current < 0 && next > 0)) {
            count++;
        }
        ptr++;
    }

    printf("Результат: количество пар соседних элементов с разными знаками = %d\n", count);
    
    free(arr);
}

// ==================== ЗАДАНИЕ 2 (ВАРИАНТ 8) ====================
// Удалить все элементы с четными индексами
int* createArray(int *size) {
    printf("Введите размер массива: ");
    scanf("%d", size);
    if (*size <= 0) return NULL;

    int *arr = (int*)malloc(*size * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    srand(time(NULL));
    for (int i = 0; i < *size; i++) {
        arr[i] = rand() % 201 - 100;  // [-100; 100]
    }
    return arr;
}

void printArray(int *arr, int size, const char *title) {
    printf("%s", title);
    for (int i = 0; i < size; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

int* deleteEvenIndices(int *arr, int *size) {
    // Индексы: 0,1,2,3,4,5...
    // Удаляем чётные индексы (0,2,4...) -> оставляем нечётные (1,3,5...)
    int new_size = *size / 2;  // если было 10 -> останется 5 (индексы 1,3,5,7,9)
    int *new_arr = (int*)malloc(new_size * sizeof(int));
    if (!new_arr) {
        printf("Ошибка памяти при удалении.\n");
        return arr;
    }

    for (int i = 0, j = 0; i < *size; i++) {
        if (i % 2 != 0) {  // нечётные индексы
            new_arr[j++] = arr[i];
        }
    }

    free(arr);
    *size = new_size;
    return new_arr;
}

void task2() {
    printf("\n========== ЗАДАНИЕ 2 ==========\n");
    printf("Удалить все элементы с четными индексами (0,2,4...)\n\n");
    
    int size;
    int *arr = createArray(&size);
    if (!arr) return;

    printArray(arr, size, "Исходный массив:\n");
    
    arr = deleteEvenIndices(arr, &size);
    printArray(arr, size, "После удаления элементов с четными индексами:\n");
    
    free(arr);
}

// ==================== ЗАДАНИЕ 3 (ВАРИАНТ 8) ====================
// P1 = long double
// P2 = long int
// P3 = float
// AB = ((1+(++p2))/p3)^{p2}
long double* calculate(long int *p2, float *p3) {
    long double *result = (long double*)malloc(sizeof(long double));
    if (!result) return NULL;

    // AB = ((1 + (++p2)) / p3) ^ p2
    ++(*p2);  // инкрементируем значение p2
    long double base = (1.0L + *p2) / (*p3);
    *result = powl(base, *p2);

    return result;
}

void task3() {
    printf("\n========== ЗАДАНИЕ 3 ==========\n");
    printf("Указатели на скалярные типы данных\n");
    printf("P1 = long double, P2 = long int, P3 = float\n");
    printf("AB = ((1+(++p2))/p3)^{p2}\n\n");
    
    // Инициализация
    long int val_p2 = 3;
    float val_p3 = 2.0f;
    
    long int *p2 = &val_p2;
    float *p3 = &val_p3;
    
    printf("ДО вызова функции:\n");
    printf("  Указатель p2 = %p, значение *p2 = %ld\n", (void*)p2, *p2);
    printf("  Указатель p3 = %p, значение *p3 = %.2f\n", (void*)p3, *p3);
    
    long double *p1 = calculate(p2, p3);
    
    printf("\nПОСЛЕ вызова функции:\n");
    printf("  Указатель p2 = %p, значение *p2 = %ld (увеличилось на 1)\n", (void*)p2, *p2);
    printf("  Указатель p3 = %p, значение *p3 = %.2f\n", (void*)p3, *p3);
    
    if (p1) {
        printf("\nРЕЗУЛЬТАТ:\n");
        printf("  Указатель p1 = %p\n", (void*)p1);
        printf("  Значение *p1 = %.10Lf\n", *p1);
        
        // Демонстрация арифметики указателей
        printf("\nАрифметика указателей:\n");
        printf("  p2 + 1 = %p (сдвиг на sizeof(long int) = %zu байт)\n", 
               (void*)(p2 + 1), sizeof(long int));
        printf("  p3 + 1 = %p (сдвиг на sizeof(float) = %zu байт)\n", 
               (void*)(p3 + 1), sizeof(float));
        
        free(p1);
    } else {
        printf("Ошибка вычислений!\n");
    }
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main() {
    printf("========================================\n");
    printf("ВАРИАНТ 8 - ВСЕ ТРИ ЗАДАНИЯ\n");
    printf("========================================\n");
    
    task1();  // Подсчёт пар с разными знаками
    task2();  // Удаление чётных индексов
    task3();  // Указатели и арифметика
    
    printf("\n========================================\n");
    printf("ПРОГРАММА ЗАВЕРШЕНА\n");
    printf("========================================\n");
    
    return 0;
}
