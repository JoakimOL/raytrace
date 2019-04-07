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

    /* Open file for writing */
    f = fopen(filename, "wb");

    /* PPM header info, including the size of the image */
    fprintf(f, "P6 %d %d %d\n", width, height, 255);

    /* Write the image data to the file - remember 3 byte per pixel */
    fwrite(img, 3, width*height, f);

    /* Make sure you close the file */
    fclose(f);

}

void read_scene(char* filename, sphere* spheres, ray* rays){
    FILE *f = fopen(filename, "wb");
    char cbuf[32];
    while(fscanf(f,"%c",cbuf)){
        switch(cbuf[0]){
            case 'e': // eye
                printf("found eye!");
                break;
            case 's': // sphere
                printf("found sphere!");
                break;
        }
    }
    (void) filename;
    (void) spheres;
    (void) rays;
    return;
}
