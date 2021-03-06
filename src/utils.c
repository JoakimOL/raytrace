#include "utils.h"

float color_expand(float c){
    return c*255;
}

vector3f color_expand_vec3f(const vector3f* c){
    return (vector3f){
        c->x*255,
        c->y*255,
        c->z*255,
    };
}

void color_expand_vec3f_inplace(vector3f* c){
        c->x*=255;
        c->y*=255;
        c->z*=255;
}

void saveppm(
        char *filename,
        unsigned char *img,
        unsigned int width,
        unsigned int height){

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
void read_scene(
        char* filename,
        size_t* numspheres,
        size_t* numlights,
        sphere** spheres,
        light** lights,
        vector3f* eye)
{
    FILE *f = fopen(filename, "r");
    if(!f) exit(INVALID_INPUT);
    char c;
    int i = 0;
    int j = 0;

    fscanf(f,"%zu",numspheres);
    fscanf(f,"%zu",numlights);
    *spheres = calloc(*numspheres,sizeof(sphere));
    *lights = calloc(*numlights,sizeof(light));

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

            case 'd': // distant light
            {
                vector3f dir;
                vector3f color;
                float intensity;

                fscanf(f, 
                       "%f %f %f %f %f %f %f",
                       &dir.x,&dir.y,&dir.z,
                       &color.x,&color.y,&color.z,
                       &intensity);
                (*lights)[j] = (light){
                    dir,
                    color,
                    intensity,
                };
                j++;
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

