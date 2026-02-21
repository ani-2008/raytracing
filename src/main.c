#include <stdio.h>

int main()
{
    int img_height = 256;
    int img_width  = 256;

    printf("P3\n%d %d\n255\n",img_width,img_height);
    for(int j = 0; j < img_height; j++){
        for(int i = 0; i < img_width; i++){
            long double r = (double)i / (img_width-1);
            long double g = (double)j / (img_height-1);
            long double b = 0.0;
            int ir = (int)(255.999 * r);
            int ig = (int)(255.999 * g);
            int ib = (int)(255.999 * b);

            printf("%d %d %d\n",ir,ig,ib);
        }
    }

}
