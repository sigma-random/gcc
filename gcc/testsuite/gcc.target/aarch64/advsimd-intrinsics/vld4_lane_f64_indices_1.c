#include <arm_neon.h>

/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-fno-fat-lto-objects" } } */
/* { dg-excess-errors "" { xfail arm*-*-* } } */
/* { dg-skip-if "" { arm*-*-* } } */

float64x1x4_t
f_vld4_lane_f64 (float64_t * p, float64x1x4_t v)
{
  float64x1x4_t res;
  /* { dg-error "lane 1 out of range 0 - 0" "" { xfail arm*-*-* } 0 } */
  res = vld4_lane_f64 (p, v, 1);
  /* { dg-error "lane -1 out of range 0 - 0" "" { xfail arm*-*-* } 0 } */
  res = vld4_lane_f64 (p, v, -1);
  return res;
}
