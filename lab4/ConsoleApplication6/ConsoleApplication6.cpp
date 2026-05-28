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
    }

    for (int i = 0, j = 0; i < *size; i++) {
        if (i % 2 != 0) {  // оставляем только нечетные индексы
            new_arr[j++] = arr[i];
        }
    }

    free(arr);
    *size = new_size;
    return new_arr;
}

void task2() {
    printf("\n========== ЗАДАНИЕ 2 ==========\n");
    printf("Удалить все элементы с четными индексами\n\n");
    
    int size;
    int *arr = createArray(&size);
    if (!arr) return;

    printArray(arr, size, "Исходный массив:\n");
    
    arr = deleteEvenIndices(arr, &size);
    printArray(arr, size, "После удаления элементов с четными индексами:\n");
    
    free(arr);
}

// ==================== ЗАДАНИЕ 3 ====================
// P1 = long double, P2 = long int, P3 = float
// AB = ((1+(++p2))/p3)^{p2}
long double* calculate(long int *p2, float *p3) {
    long double *result = (long double*)malloc(sizeof(long double));
    if (!result) return NULL;

    // Вычисляем выражение: ((1 + (++p2)) / p3) ^ p2
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
    
    // Инициализация переменных
    long int val_p2 = 3;
    float val_p3 = 2.0f;
    
    // Указатели
    long int *p2 = &val_p2;
    float *p3 = &val_p3;
    
    printf("ДО вызова функции:\n");
    printf("  Адрес p2 = %p, значение *p2 = %ld\n", (void*)p2, *p2);
    printf("  Адрес p3 = %p, значение *p3 = %.2f\n", (void*)p3, *p3);
    
    // Вычисление выражения
    long double *p1 = calculate(p2, p3);
    
    printf("\nПОСЛЕ вызова функции:\n");
    printf("  Адрес p2 = %p, значение *p2 = %ld (было инкрементировано)\n", (void*)p2, *p2);
    printf("  Адрес p3 = %p, значение *p3 = %.2f\n", (void*)p3, *p3);
    
    if (p1) {
        printf("\nРЕЗУЛЬТАТ:\n");
        printf("  Указатель p1 = %p\n", (void*)p1);
        printf("  Значение *p1 = %Lf\n", *p1);
        free(p1);
    } else {
        printf("Ошибка вычислений!\n");
    }
    
    printf("\nДемонстрация арифметики указателей:\n");
    printf("  p2 + 1 = %p (следующий long int)\n", (void*)(p2 + 1));
    printf("  p3 + 1 = %p (следующий float)\n", (void*)(p3 + 1));
    printf("  p3 - p2 = %ld (разность адресов)\n", (long)((char*)p3 - (char*)p2));
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main() {
    printf("========================================\n");
    printf("ВАРИАНТ 8 - ВСЕ ЗАДАНИЯ\n");
    printf("========================================\n");
    
    task1();
    task2();
    task3();
    
    printf("\n========================================\n");
    printf("ПРОГРАММА ЗАВЕРШЕНА\n");
    printf("========================================\n");
    
    return 0;
}
}
