/* caxpy.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "FLA_f2c.h"

/* Subroutine */ int caxpy_(integer *n, complex *ca, complex *cx, integer *
	incx, complex *cy, integer *incy)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    real r__1, r__2;
    complex q__1, q__2;

    /* Builtin functions */
    double r_imag(complex *);

    /* Local variables */
    integer i__, ix, iy;


/*     constant times a vector plus a vector. */
/*     jack dongarra, linpack, 3/11/78. */
/*     modified 12/3/93, array(1) declarations changed to array(*) */


    /* Parameter adjustments */
    --cy;
    --cx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if ((r__1 = ca->r, abs(r__1)) + (r__2 = r_imag(ca), abs(r__2)) == 0.f) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        code for unequal increments or equal increments */
/*          not equal to 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = iy;
	i__3 = iy;
	i__4 = ix;
	q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i, q__2.i = ca->r * cx[
		i__4].i + ca->i * cx[i__4].r;
	q__1.r = cy[i__3].r + q__2.r, q__1.i = cy[i__3].i + q__2.i;
	cy[i__2].r = q__1.r, cy[i__2].i = q__1.i;
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*        code for both increments equal to 1 */

L20:
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	i__3 = i__;
	i__4 = i__;
	q__2.r = ca->r * cx[i__4].r - ca->i * cx[i__4].i, q__2.i = ca->r * cx[
		i__4].i + ca->i * cx[i__4].r;
	q__1.r = cy[i__3].r + q__2.r, q__1.i = cy[i__3].i + q__2.i;
	cy[i__2].r = q__1.r, cy[i__2].i = q__1.i;
/* L30: */
    }
    return 0;
} /* caxpy_ */

