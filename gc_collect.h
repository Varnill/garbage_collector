#pragma once

#include "garbage_collector.c"

// Объявление функции gc_collect
void gc_collect(GarbageCollector *gc, size_t gc_grow_factor);


