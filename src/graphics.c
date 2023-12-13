#include <graphx.h>
#include <math.h>
#include <ti/screen.h>
#include "vector.h"
#include "graphics.h"

#define HW GFX_LCD_WIDTH / 2
#define HH GFX_LCD_HEIGHT / 2


vec2_t gfx3d_projectVert(vec3_t vert) {
    return (fabsf(vert.z) < 0.001f) ?
    (vec2_t) {sign(vert.x) * INFINITY, sign(vert.y) * INFINITY} :
    (vec2_t) {vert.x / vert.z + HW, vert.y / vert.z + HH};
}

void gfx3d_line(vec3_t vert1, vec3_t vert2) {
    vec2_t pv1 = gfx3d_projectVert(vert1);
    vec2_t pv2 = gfx3d_projectVert(vert2);

    gfx_Line(pv1.x, pv1.y, pv2.x, pv2.y);
}

void gfx3d_triWireframe(vec3_t vert1, vec3_t vert2, vec3_t vert3) {
    gfx3d_line(vert1, vert2);
    gfx3d_line(vert2, vert3);
    gfx3d_line(vert3, vert1);
}

#include <debug.h>

void gfx3d_meshWireframe(mesh_t* mesh, vec3_t center) {

    // is this efficient?
    // size_t size = mesh->num_verts; // why did it make me do this?
    // vec3_t new_verts[size];
    // dbg_printf("--------------------NEW MESH--------------------\n");

    // for (unsigned int i = 0; i < size; i++) {
    //     dbg_printf("Old-\nX: %f, Y: %f, Z: %f\n", mesh->verts[i].x, mesh->verts[i].y, mesh->verts[i].z);

    //     vec3_t value = vec3_add(mesh->verts[i], center);

    //     dbg_printf("Value-\nX: %f, Y: %f, Z: %f\n", value.x, value.y, value.z);

    //     new_verts[i] = value;

    //     dbg_printf("Center-\nX: %f, Y: %f, Z: %f\n", center.x, center.y, center.z);
    //     dbg_printf("NewOld-\nX: %f, Y: %f, Z: %f\n", mesh->verts[i].x, mesh->verts[i].y, mesh->verts[i].z);
    //     dbg_printf("NewNew-\nX: %f, Y: %f, Z: %f\n", new_verts[i].x, new_verts[i].y, new_verts[i].z);
    // }
    
    for (unsigned int i = 0; i < mesh->num_faces; i++) {

        // is this efficient? There is no way this is efficient.
        gfx3d_triWireframe(
            vec3_add(mesh->verts[mesh->faces[i][0]], center),
            vec3_add(mesh->verts[mesh->faces[i][1]], center),
            vec3_add(mesh->verts[mesh->faces[i][2]], center)
        );
    }
}

