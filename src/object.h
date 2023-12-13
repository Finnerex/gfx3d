#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include <stdlib.h>

typedef struct transform_t {
    vec3_t position;
    vec3_t rotation;
} transform_t;

typedef int face_t[3];

typedef struct mesh_t {
    face_t* faces; // list of faces which are lists of vertex indices
    vec3_t* verts;

    size_t num_faces;
    size_t num_verts;
} mesh_t;

typedef struct obj3d_t {
    transform_t transform;
    mesh_t* mesh;
} obj3d_t;



#endif