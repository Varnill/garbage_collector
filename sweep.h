// sweep.h
#pragma once

#include "garbage_collector.h"

// Функция сборки мусора
void sweep(GarbageCollector *gc, size_t gc_grow_factor);

