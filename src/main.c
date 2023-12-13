#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"

#include "vector.h"
#include "graphics.h"
#include "object.h"

void begin();
void end();
bool step();
void draw();

int main() {
    begin();                // No rendering allowed!

    gfx_Begin();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_SetDrawBuffer();    // Draw to the buffer to avoid rendering artifacts

    while (step()) {        // No rendering allowed in step!
        draw();             // As little non-rendering logic as possible
        gfx_SwapDraw();     // Queue the buffered frame to be displayed
    }

    gfx_End();
    end();

    return 0;
}

#include "cube.h"

obj3d_t objects[] = { { {{0, 0, 2}, {0, 0, 0}}, cube_mesh } }; // what a set a braces
int num_objs = 1;

int selected_obj = 0;


void begin() {

}

bool step() {

    kb_Scan();

    if (kb_Data[6] & kb_Clear)
        return false;
    

    if (kb_Data[7] & kb_Up)
        objects[selected_obj].transform.position.y --;
    else if (kb_Data[7] & kb_Down)
        objects[selected_obj].transform.position.y ++;

    if (kb_Data[7] & kb_Left)
        objects[selected_obj].transform.position.x --;
    else if (kb_Data[7] & kb_Right)
        objects[selected_obj].transform.position.x ++;

    if (kb_Data[1] & kb_2nd)
        objects[selected_obj].transform.position.z -= 0.1f;
    else if (kb_Data[2] & kb_Alpha)
        objects[selected_obj].transform.position.z += 0.1f;

    static bool lm, ld, m, d;
    m = kb_Data[1] & kb_Mode;
    d = kb_Data[1] & kb_Del;

    if (m && !lm)
        selected_obj = (selected_obj == 0) ? num_objs - 1 : selected_obj - 1;
    else if (d && !ld)
        selected_obj = (selected_obj == num_objs - 1) ? 0 : selected_obj + 1;

    lm = m; ld = d;

    return true;

}

void draw() {

    gfx_FillScreen(0);

    gfx_SetColor(1);
    gfx3d_meshWireframe(objects[selected_obj].mesh, objects[selected_obj].transform.position);

    vec3_t* center = &objects[selected_obj].transform.position;

    vec2_t projected_selected_vertex = gfx3d_projectVert(*center);

    gfx_SetColor(3);
    gfx_Circle(projected_selected_vertex.x, projected_selected_vertex.y, 3);

    gfx_SetTextFGColor(3);
    gfx_SetTextXY(20, 220);
    gfx_PrintString("x: ");
    gfx_PrintInt(center->x, 1);
    gfx_PrintString(" y: ");
    gfx_PrintInt(center->y, 1);
    gfx_PrintString(" z: ");
    gfx_PrintInt(center->z * 10, 1);
    gfx_PrintString(" object: ");
    gfx_PrintInt(selected_obj, 1);

}

void end() {

}

