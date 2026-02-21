#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdio.h>

typedef struct{
    double e[3];
} vec3;

static inline void vec3_init(vec3 *v)
{
    v->e[0] = 0;
    v->e[1] = 0; 
    v->e[2] = 0;
}

static inline void vec3_put(vec3 *v, double e0, double e1, double e2)
{
    v->e[0] = e0;
    v->e[1] = e1;
    v->e[2] = e2;
}

static inline double vec3_x(const vec3 *v)
{
    return v->e[0];
}

static inline double vec3_y(const vec3 *v)
{
    return v->e[1];
}

static inline double vec3_z(const vec3 *v)
{
    return v->e[2];
}

static inline vec3 *vec3_add_assign(vec3 *v, const vec3 *v1)
{
    v->e[0] += v1->e[0];
    v->e[1] += v1->e[1];
    v->e[2] += v1->e[2];

    return v;
}


static inline vec3 *vec3_mul_assign(vec3 *v, double t)
{
    v->e[0] *= t;
    v->e[1] *= t;
    v->e[2] *= t;

    return v;
}

static inline vec3 *vec3_div_assign(vec3 *v, double t)
{
    return vec3_mul_assign(v,1.0/t);
}

static inline double vec3_length_squared(const vec3 *v)
{
    return (v->e[0] * v->e[0]) + (v->e[1] * v->e[1]) + (v->e[2] * v->e[2]);
}

static inline double vec3_length(const vec3 *v)
{
    return sqrt(vec3_length_squared(v));
}

typedef vec3 point3;

static inline void vec3_print(const vec3 *v)
{
    printf("%f %f %f\n", v->e[0], v->e[1], v->e[2]);
}

static inline vec3 vec3_add(const vec3 *u, const vec3 *v)
{
    vec3 *x;

    vec3_put(x, (u->e[0] + v->e[0]), (u->e[1] + v->e[1]), (u->e[2] + v->e[2]));

    return *x;
}

static inline vec3 vec3_sub(const vec3 *u, const vec3 *v)
{
    vec3 *x;

    vec3_put(x, (u->e[0] - v->e[0]), (u->e[1] - v->e[1]), (u->e[2] - v->e[2]));

    return *x;
}

static inline vec3 vec3_mul(const vec3 *u, const vec3 *v)
{
    vec3 *x;

    vec3_put(x, (u->e[0] * v->e[0]), (u->e[1] * v->e[1]), (u->e[2] * v->e[2]));

    return *x;
}

static inline vec3 vec3_mul_t(double t, const vec3 *v)
{
    vec3 *x;

    vec3_put(x, (t * v->e[0]), (t * v->e[1]), (t * v->e[2]));

    return *x;
}

static inline vec3 vec3_div(const vec3 *v, double t)
{
    vec3 *x;

    vec3_mul_t((1.0/t), v);

    return *x;
}

static inline double dot(const vec3 *u, const vec3 *v)
{
    return (u->e[0] * v->e[0]
          + u->e[1] * v->e[1]
          + u->e[2] * v->e[2]);
}

static inline vec3 cross(const vec3 *u, const vec3 *v)
{
    vec3 *x;
    vec3_put(x, u->e[1] * v->e[2] - u->e[2] * v->e[1],
                u->e[0] * v->e[2] - u->e[2] * v->e[0],
                u->e[0] * v->e[1] - u->e[1] * v->e[0]);
    return *x;
}

static inline vec3 unit_vector(const vec3 *v)
{
    return vec3_div(v, vec3_length(v));
}

#endif
