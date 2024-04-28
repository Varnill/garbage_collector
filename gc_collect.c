#include "garbage_collector.h"
#include "stdlib.h"
#include "stdio.h"

void gc_collect(GarbageCollector *gc, size_t gc_grow_factor) {
    // Пройдемся по всем объектам в gc и пометим их
    for (size_t i = 0; i < gc->object_count; ++i) {
        Object *obj = gc->objects[i];
        if (obj && !obj->marked) {
            obj->marked = 1;
            // Рекурсивно помечаем все объекты, к которым есть ссылки из этого объекта
            // Для этого нужно пройтись по всем полям объекта obj
        }
    }

    // Очищаем непомеченные объекты
    size_t valid_objects = 0;
    for (size_t i = 0; i < gc->object_count; ++i) {
        if (gc->objects[i]->marked) {
            gc->objects[valid_objects++] = gc->objects[i];
            gc->objects[i]->marked = 0;
        } else {
            free(gc->objects[i]); // Освобождаем непомеченные объекты
        }
    }

    // Обновляем количество объектов и размер буфера объектов
    gc->object_count = valid_objects;
    if (gc->object_count < gc->threshold / gc_grow_factor) {
        size_t new_threshold = gc->threshold / gc_grow_factor;
        Object **temp_objects = realloc(gc->objects, new_threshold * sizeof(Object *));
        if (temp_objects) {
            gc->threshold = new_threshold;
            gc->objects = temp_objects;
        } else {
            // Обработка ситуации, когда realloc завершился неудачно.
            fprintf(stderr, "Ошибка выделения памяти.\n");
            exit(EXIT_FAILURE);
        }
    }
}
