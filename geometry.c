/*
 * geometry.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double coord_2d_area_triangle(const coord_2d_t *a, const coord_2d_t *b, const coord_2d_t *c){
  double area;
  double base;
  double height;
  double min_x = a->x;
  double min_y = a->y;
  double max_x = a->x;
  double max_y = a->y;

  if(b->x < min_x){
    min_x = b->x;
  }
  if(b->y < min_y){
    min_y = b->y;
  }
  if(b->x > max_x){
    max_x = b->x;
  }
  if(b->y > max_y){
    max_y = b->y;
  }

  if(c->x < min_x){
    min_x = c->x;
  }
  if(c->y < min_y){
    min_y = c->y;
  }
  if(c->x > max_x){
    max_x = c->x;
  }
  if(c->y > max_y){
    max_y = c->y;
  }

  //calculate area as (1/2) * base * height
  base = max_x - min_x;
  height = max_y - min_y;
  area = 0.5 * base * height;

  return area;
}

double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!mid){
        DEBUG(__FILE__, __LINE__, __func__, "'mid' must not be NULL");
        return;
    }
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return;
    }

    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}
