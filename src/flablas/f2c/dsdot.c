/* dsdot.f -- translated by f2c (version 19991025).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "FLA_f2c.h"

/* DECK DSDOT */
doublereal dsdot_(integer *n, real *sx, integer *incx, real *sy, integer *
	incy)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    integer i__, ns, kx, ky;

/* ***BEGIN PROLOGUE  DSDOT */
/* ***PURPOSE  Compute the inner product of two vectors with extended */
/*            precision accumulation and result. */
/* ***LIBRARY   SLATEC (BLAS) */
/* ***CATEGORY  D1A4 */
/* ***TYPE      DOUBLE PRECISION (DSDOT-D, DCDOT-C) */
/* ***KEYWORDS  BLAS, COMPLEX VECTORS, DOT PRODUCT, INNER PRODUCT, */
/*             LINEAR ALGEBRA, VECTOR */
/* ***AUTHOR  Lawson, C. L., (JPL) */
/*           Hanson, R. J., (SNLA) */
/*           Kincaid, D. R., (U. of Texas) */
/*           Krogh, F. T., (JPL) */
/* ***DESCRIPTION */

/*                B L A S  Subprogram */
/*    Description of Parameters */

/*     --Input-- */
/*        N  number of elements in input vector(s) */
/*       SX  single precision vector with N elements */
/*     INCX  storage spacing between elements of SX */
/*       SY  single precision vector with N elements */
/*     INCY  storage spacing between elements of SY */

/*     --Output-- */
/*    DSDOT  double precision dot product (zero if N.LE.0) */

/*     Returns D.P. dot product accumulated in D.P., for S.P. SX and SY */
/*     DSDOT = sum for I = 0 to N-1 of  SX(LX+I*INCX) * SY(LY+I*INCY), */
/*     where LX = 1 if INCX .GE. 0, else LX = 1+(1-N)*INCX, and LY is */
/*     defined in a similar way using INCY. */

/* ***REFERENCES  C. L. Lawson, R. J. Hanson, D. R. Kincaid and F. T. */
/*                 Krogh, Basic linear algebra subprograms for Fortran */
/*                 usage, Algorithm No. 539, Transactions on Mathematical */
/*                 Software 5, 3 (September 1979), pp. 308-323. */
/* ***ROUTINES CALLED  (NONE) */
/* ***REVISION HISTORY  (YYMMDD) */
/*   791001  DATE WRITTEN */
/*   890831  Modified array declarations.  (WRB) */
/*   890831  REVISION DATE from Version 3.2 */
/*   891214  Prologue converted to Version 4.0 format.  (BAB) */
/*   920310  Corrected definition of LX in DESCRIPTION.  (WRB) */
/*   920501  Reformatted the REFERENCES section.  (WRB) */
/* ***END PROLOGUE  DSDOT */
/* ***FIRST EXECUTABLE STATEMENT  DSDOT */
    /* Parameter adjustments */
    --sy;
    --sx;

    /* Function Body */
    ret_val = 0.;
    if (*n <= 0) {
	return ret_val;
    }
    if (*incx == *incy && *incx > 0) {
	goto L20;
    }

/*     Code for unequal or nonpositive increments. */

    kx = 1;
    ky = 1;
    if (*incx < 0) {
	kx = (1 - *n) * *incx + 1;
    }
    if (*incy < 0) {
	ky = (1 - *n) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ret_val += (doublereal) sx[kx] * (doublereal) sy[ky];
	kx += *incx;
	ky += *incy;
/* L10: */
    }
    return ret_val;

/*     Code for equal, positive, non-unit increments. */

L20:
    ns = *n * *incx;
    i__1 = ns;
    i__2 = *incx;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	ret_val += (doublereal) sx[i__] * (doublereal) sy[i__];
/* L30: */
    }
    return ret_val;
} /* dsdot_ */

