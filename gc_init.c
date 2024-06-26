#include "garbage_collector.h"

void gc_init() {
    gc.threshold = INITIAL_GC_THRESHOLD;
    gc.allocated = 0;
    gc.objects = malloc(gc.threshold * sizeof(Object *));
    gc.object_count = 0;
}
