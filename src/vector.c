#include "vector.h"
#include <debug.h>

vec3_t vec3_add(vec3_t first, vec3_t second) {
    // dbg_printf("----------ADDITION----------\n");
    // dbg_printf("First-\nX: %f, Y: %f, Z: %f\n", first.x, first.y, first.z);
    // dbg_printf("Second-\nX: %f, Y: %f, Z: %f\n", second.x, second.y, second.z);

    vec3_t out = (vec3_t){first.x + second.x, first.y + second.y, first.z + second.z};

    // dbg_printf("Output-\nX: %f, Y: %f, Z: %f\n", out.x, out.y, out.z);

    // dbg_printf("--------END ADDITION--------\n");

    return out;
}
