#include "garbage_collector.h"
#include "gc_collect.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    gc_init();

    // Выделение памяти для объектов с проверкой на ошибки
    int *ptr1 = gc_malloc(sizeof(int));
    if (!ptr1) {
        fprintf(stderr, "Ошибка выделения памяти для ptr1\n");
        return EXIT_FAILURE;
    }

    int *ptr2 = gc_malloc(sizeof(int));
    if (!ptr2) {
        fprintf(stderr, "Ошибка выделения памяти для ptr2\n");
        return EXIT_FAILURE;
    }

    // Выполнение операций с ptr1 и ptr2
    // Например
    // *ptr1 = 10;
    //  *ptr2 = *ptr1 + 5;

    // Освобождение памяти, если она больше не нужна
    gc_collect(&gc, 2); // Примерное значение для gc_grow_factor

    // После gc_collect, освобождаем указатели или устанавливаем их в NULL
    ptr1 = NULL;
    ptr2 = NULL;

    return EXIT_SUCCESS;
}
