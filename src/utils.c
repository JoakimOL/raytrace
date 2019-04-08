#include "utils.h"

void saveppm(char *filename, unsigned char *img, unsigned int width, unsigned int height){

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
void read_scene(char* filename, size_t* numspheres, sphere** spheres, vector3f* eye){
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
                (*eye) = (vector3f){x,y,z};
                break;
            }
            case 's': // sphere
            {
                vector3f pos;
                float radius;
                vector3f emit;
                vector3f surface;
                float transparent;
                float reflection;

                fscanf(f, 
                       "%f %f %f %f %f %f %f %f %f %f %f %f",
                       &pos.x,&pos.y,&pos.z,
                       &radius,
                       &surface.x, &surface.y, &surface.z,
                       &emit.x, &emit.y, &emit.z,
                       &reflection, &transparent);
                (*spheres)[i] = (sphere){
                    pos,
                    surface,
                    emit,
                    radius,
                    transparent,
                    reflection,
                };
                i++;
                break;
            }
        }
    }
    fclose(f);
}

