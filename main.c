#include "garbage_collector.h"
#include "sweep.h"
#include "gc_collect.h"

int main() {
    // Инициализируем сборщик мусора
    gc_init();

    // Выделяем память для объектов
    int *ptr1 = (int *)gc_malloc(sizeof(int));
    int *ptr2 = (int *)gc_malloc(sizeof(int));

    // Выполняем какие-то операции

    // Освобождаем память, если она больше не нужна
    gc_collect(gc, 2); // Примерное значение для gc_grow_factor


    return 0;
}