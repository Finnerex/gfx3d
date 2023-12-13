#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "vector.h"
#include "object.h"


vec2_t gfx3d_projectVert(vec3_t vert);

void gfx3d_line(vec3_t vert1, vec3_t vert2);

void gfx3d_triWireframe(vec3_t vert1, vec3_t vert2, vec3_t vert3);

void gfx3d_meshWireframe(mesh_t* mesh, vec3_t center);

static inline int sign(float num) {
    return (num > 0) - (num < 0);
}


#endif