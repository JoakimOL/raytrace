#ifndef UTILS_H_
#define UTILS_H_

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#include "sphere.h"
#include "ray.h"
#include "vector.h"


void saveppm(char *filename, unsigned char *img, unsigned int width, unsigned int height);

void read_scene(char* filename, size_t* numspheres, sphere** spheres, vector3f* eye);


float color_expand(float c);

vector3f color_expand_vec3f(const vector3f* c);

void color_expand_vec3f_inplace(vector3f* c);
#endif
