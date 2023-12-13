#include "cube.h" 

face_t cube_faces[12] = {
{ 5, 3, 1 }, { 3, 8, 4 }, { 7, 6, 8 }, { 2, 8, 6 }, { 1, 4, 2 }, { 5, 2, 6 }, { 5, 7, 3 }, { 3, 7, 8 }, 
{ 7, 5, 6 }, { 2, 4, 8 }, { 1, 3, 4 }, { 5, 1, 2 }
}; 

vec3_t cube_verts[8] = {
{ 1.0f, 1.0f, -1.0f }, { 1.0f, -1.0f, -1.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, -1.0f, 1.0f }, { -1.0f, 1.0f, -1.0f }, { -1.0f, -1.0f, -1.0f }, 
{ -1.0f, 1.0f, 1.0f }, { -1.0f, -1.0f, 1.0f }
};

mesh_t cube_data = { cube_faces, cube_verts, 12, 8 };
