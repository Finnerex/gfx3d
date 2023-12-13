#include <graphx.h>
#include <math.h>
#include <ti/screen.h>
#include "vector.h"
#include "graphics.h"

#define HW GFX_LCD_WIDTH / 2
#define HH GFX_LCD_HEIGHT / 2

#include <debug.h>

vec2_t gfx3d_projectVert(vec3_t vert) {
    return (fabsf(vert.z) < 0.001f) ?
    (vec2_t) {sign(vert.x) * INFINITY, sign(vert.y) * INFINITY} :
    (vec2_t) {vert.x / vert.z + HW, vert.y / vert.z + HH};
}

void gfx3d_line(vec3_t vert1, vec3_t vert2) {
    vec2_t pv1 = gfx3d_projectVert(vert1);
    vec2_t pv2 = gfx3d_projectVert(vert2);

    dbg_printf("First-\nX: %f, Y: %f\n", pv1.x, pv1.y);
    dbg_printf("Second-\nX: %f, Y: %f\n", pv2.x, pv2.y);

    gfx_Line(pv1.x, pv1.y, pv2.x, pv2.y);
}


void gfx3d_triWireframe(vec3_t vert1, vec3_t vert2, vec3_t vert3) {

    dbg_printf("----------NEW FACE----------\n");
    dbg_printf("First-\nX: %f, Y: %f, Z: %f\n", vert1.x, vert1.y, vert1.z);
    dbg_printf("Second-\nX: %f, Y: %f, Z: %f\n", vert2.x, vert2.y, vert2.z);
    dbg_printf("Third-\nX: %f, Y: %f, Z: %f\n", vert3.x, vert3.y, vert3.z);

    dbg_printf("----------2D STUFF----------\n");
    gfx3d_line(vert1, vert2);
    gfx3d_line(vert2, vert3);
    gfx3d_line(vert3, vert1);
}



void gfx3d_meshWireframe(mesh_t* mesh, vec3_t center) {

    dbg_printf("--------------------NEW MESH--------------------\n");
    
    for (unsigned int i = 0; i < mesh->num_faces; i++) {

        // face_t face = mesh->faces[i];

        // is this efficient? There is no way this is efficient.
        gfx3d_triWireframe(
            vec3_add(mesh->verts[mesh->faces[i][0]], center),
            vec3_add(mesh->verts[mesh->faces[i][1]], center),
            vec3_add(mesh->verts[mesh->faces[i][2]], center)
        );
    }
}

