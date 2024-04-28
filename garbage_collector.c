#include "garbage_collector.h"
#include <stdlib.h>
#include <stdio.h>

#include "sweep.h"
#define INITIAL_GC_THRESHOLD 10

static GarbageCollector gc;

void gc_init() {
    gc.threshold = INITIAL_GC_THRESHOLD;
    gc.allocated = 0;
    gc.objects = malloc(gc.threshold * sizeof(Object *));
    gc.object_count = 0;
}

void *gc_malloc(size_t size) {

    void *ptr = malloc(size);
    if (!ptr) return NULL;

    Object *obj = (Object *)ptr;
    obj->marked = 0;

    gc.objects[gc.object_count++] = obj;
    gc.allocated += size;

    return ptr;
}

void gc_free(void *ptr) {
    free(ptr);
}


