#include "utils.h"

bool intersectRaySphere(ray *r, sphere *s, float *t){
    // Quadratic formula
    // Ax² + Bx + C = 0
    //
    // solved by 
    //
    // x = (-B (+-) sqrt(D) )/ 2A
    // D = B² - 4AC
    float A = vector_dot(&r->dir, &r->dir);
    vector3 dist = vector_sub(&r->start, &s->pos);
    float B = 2 * vector_dot(&r->dir, &dist);
    float C = vector_dot(&dist, &dist) - (s->radius * s->radius);
    float D = B * B - 4 * A * C;
    if(D < 0) return false;

    float sqrtD = sqrtf(D);
    float dist0 = (-B + sqrtD) / 2;
    float dist1 = (-B - sqrtD) / 2;

    if( dist0 > dist1 ) dist0 = dist1;
    if((dist0 > 0.001f) && (dist0 < *t)){
        *t = dist0;
        return true;
    }
    return false;
}

void saveppm(char *filename, unsigned char *img, unsigned int width, unsigned int height){

    /* FILE pointer */
    FILE *f;

    f = fopen(filename, "wb");

    fprintf(f, "P6 %d %d %d\n", width, height, 255);
    fwrite(img, 3, width*height, f);

    fclose(f);

}

/**
 * Reads scene file to supplied pointers.
 * allocates memory to spheres pointer.
 */
void read_scene(char* filename, size_t* numspheres, sphere** spheres, vector3* eye){
    FILE *f = fopen(filename, "r");
    char c;
    int i = 0;

    fscanf(f,"%zu",numspheres);
    *spheres = calloc(*numspheres,sizeof(sphere));

    while((c = (char)fgetc(f)) != EOF){
        switch(c){
            case 'e': // eye
            {
                float x;
                float y;
                float z;
                fscanf(f, "%f %f %f", &x, &y, &z);
                (*eye) = (vector3){x,y,z};
                break;
            }
            case 's': // sphere
            {
                float x;
                float y;
                float z;
                float radius;
                int material;
                fscanf(f, 
                       "%f %f %f %f %d",
                       &x,&y,&z,&radius,&material);
                (*spheres)[i] = (sphere){
                    (vector3){x,y,z},
                        radius,
                        material
                };
                i++;
                break;
            }
        }
    }
}
