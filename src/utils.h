#ifndef UTILS_H_
#define UTILS_H_

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#include "sphere.h"
#include "ray.h"
#include "vector.h"


bool intersectRaySphere(ray *r, sphere *s, float *t);

void saveppm(char *filename, unsigned char *img, unsigned int width, unsigned int height);

void read_scene(char* filename, size_t* numspheres, sphere** spheres, vector3* eye);


#endif
