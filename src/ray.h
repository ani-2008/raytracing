#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct{
    Point3 origin;
    Vec3 dir;

}ray;


static inline void ray_set(ray *p, Point3 *origin, Vec3 *direction)
{
    p->origin = *origin;
    p->dir = *direction;
}

static inline Point3 ray_origin(const ray *p)
{
    return p->origin;
}

static inline Vec3 ray_direction(const ray *p)
{
    return p->dir;
}

static inline Point3 ray_at(const ray *p, double t)
{
    Vec3 scaled_dir = vec3_mul_t(t, &(p->dir));
    return vec3_add(&(p->origin), &scaled_dir);

}
#endif
