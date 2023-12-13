#ifndef VECTOR_H
#define VECTOR_H

#if __cplusplus
extern "C" {
#endif


typedef struct vec3_t {
  float x;
  float y;
  float z;
} vec3_t;

typedef struct vec2_t {
  float x;
  float y;
} vec2_t;

vec3_t vec3_add(vec3_t first, vec3_t second);


#if __cplusplus
}
#endif

#endif