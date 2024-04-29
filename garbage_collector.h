#pragma once

#include <stdlib.h>

#define INITIAL_GC_THRESHOLD 10

typedef struct {
    size_t marked;
} Object;

typedef struct {
    size_t threshold;
    size_t allocated;
    Object **objects;
    size_t object_count;
} GarbageCollector;

extern GarbageCollector gc; // Объявление переменной gc как extern

void gc_init();
void *gc_malloc(size_t size);
