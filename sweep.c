#include "sweep.h"
#include <stdlib.h>

void sweep(GarbageCollector *gc, size_t gc_grow_factor) {
    size_t valid_objects = 0;

    // Приведем указатель к типу Object *
    for (size_t i = 0; i < gc->object_count; ++i) {
        // Приведем указатель к типу Object *
        if (((Object *)gc->objects[i])->marked) {
            free(gc->objects[i]);
        } else {
            gc->objects[valid_objects++] = gc->objects[i];
        }
    }

    gc->object_count = valid_objects;

    if (gc->object_count < gc->threshold / gc_grow_factor) {
        gc->threshold /= gc_grow_factor;
        gc->objects = realloc(gc->objects, gc->threshold * sizeof(Object *));
    }

    // Приведем указатель к типу Object *
    for (size_t i = 0; i < gc->object_count; ++i) {
        // Приведем указатель к типу Object *
        ((Object *)gc->objects[i])->marked = 0;
    }
}



