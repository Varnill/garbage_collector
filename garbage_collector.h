#pragma once

#include <stddef.h>

// Структура объекта
typedef struct {
    size_t marked; // Помечен ли объект для сохранения
    // Добавьте другие поля объекта здесь
} Object;

// Структура сборщика мусора
typedef struct GarbageCollector {
    size_t threshold; // Порог сборки мусора
    size_t allocated; // Количество выделенной памяти
    Object **objects; // Массив указателей на объекты
    size_t object_count; // Количество объектов
    size_t gc_grow_factor;
} GarbageCollector;

// Инициализация сборщика мусора
void gc_init();

// Функция выделения памяти с автоматическим сборщиком мусора
void *gc_malloc(size_t size);

