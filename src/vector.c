#include "vector.h"

vec3_t vec3_add(vec3_t first, vec3_t second) {
    return (vec3_t) {first.x + second.x, first.y + second.y, first.z + second.z};
}
