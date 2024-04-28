#include "garbage_collector.h"
#include "gc_collect.h"
#include <stdlib.h>

void *gc_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) return NULL;

    Object *obj = (Object *)ptr;
    obj->marked = 0;

    gc.objects[gc.object_count++] = obj;
    gc.allocated += size;

    return ptr;
}
