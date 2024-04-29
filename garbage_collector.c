#include "garbage_collector.h"

GarbageCollector gc;

// Определение статической функции gc_init
static void gc_init() {
    gc.threshold = INITIAL_GC_THRESHOLD;
    gc.allocated = 0;
    gc.objects = malloc(gc.threshold * sizeof(Object *));
    gc.object_count = 0;
}

// Определение статической функции gc_malloc
static void *gc_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) return NULL;

    Object *obj = (Object *)ptr;
    obj->marked = 0;

    gc.objects[gc.object_count++] = obj;
    gc.allocated += size;

    return ptr;
}
