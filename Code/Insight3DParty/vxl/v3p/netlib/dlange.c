/* dlange.f -- translated by f2c (version of 4 June 1993  1:43:59).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/*<       DOUBLE PRECISION FUNCTION DLANGE( NORM, M, N, A, LDA, WORK ) >*/
doublereal dlange_(char *norm, integer *m, integer *n, doublereal *a, integer 
	*lda, doublereal *work, ftnlen norm_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;
    doublereal ret_val, d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i, j;
    static doublereal scale;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static doublereal value;
    extern /* Subroutine */ int dlassq_(integer *, doublereal *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sum;


/*  -- LAPACK auxiliary routine (version 2.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     October 31, 1992 */

/*     .. Scalar Arguments .. */
/*<       CHARACTER          NORM >*/
/*<       INTEGER            LDA, M, N >*/
/*     .. */
/*     .. Array Arguments .. */
/*<       DOUBLE PRECISION   A( LDA, * ), WORK( * ) >*/
/*     .. */

/*  Purpose */
/*  ======= */

/*  DLANGE  returns the value of the one norm,  or the Frobenius norm, or 
*/
/*  the  infinity norm,  or the  element of  largest absolute value  of a 
*/
/*  real matrix A. */

/*  Description */
/*  =========== */

/*  DLANGE returns the value */

/*     DLANGE = ( max(abs(A(i,j))), NORM = 'M' or 'm' */
/*              ( */
/*              ( norm1(A),         NORM = '1', 'O' or 'o' */
/*              ( */
/*              ( normI(A),         NORM = 'I' or 'i' */
/*              ( */
/*              ( normF(A),         NORM = 'F', 'f', 'E' or 'e' */

/*  where  norm1  denotes the  one norm of a matrix (maximum column sum), 
*/
/*  normI  denotes the  infinity norm  of a matrix  (maximum row sum) and 
*/
/*  normF  denotes the  Frobenius norm of a matrix (square root of sum of 
*/
/*  squares).  Note that  max(abs(A(i,j)))  is not a  matrix norm. */

/*  Arguments */
/*  ========= */

/*  NORM    (input) CHARACTER*1 */
/*          Specifies the value to be returned in DLANGE as described */
/*          above. */

/*  M       (input) INTEGER */
/*          The number of rows of the matrix A.  M >= 0.  When M = 0, */
/*          DLANGE is set to zero. */

/*  N       (input) INTEGER */
/*          The number of columns of the matrix A.  N >= 0.  When N = 0, 
*/
/*          DLANGE is set to zero. */

/*  A       (input) DOUBLE PRECISION array, dimension (LDA,N) */
/*          The m by n matrix A. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(M,1). */

/*  WORK    (workspace) DOUBLE PRECISION array, dimension (LWORK), */
/*          where LWORK >= M when NORM = 'I'; otherwise, WORK is not */
/*          referenced. */

/* ===================================================================== 
*/

/*     .. Parameters .. */
/*<       DOUBLE PRECISION   ONE, ZERO >*/
/*<       PARAMETER          ( ONE = 1.0D+0, ZERO = 0.0D+0 ) >*/
/*     .. */
/*     .. Local Scalars .. */
/*<       INTEGER            I, J >*/
/*<       DOUBLE PRECISION   SCALE, SUM, VALUE >*/
/*     .. */
/*     .. External Subroutines .. */
/*<       EXTERNAL           DLASSQ >*/
/*     .. */
/*     .. External Functions .. */
/*<       LOGICAL            LSAME >*/
/*<       EXTERNAL           LSAME >*/
/*     .. */
/*     .. Intrinsic Functions .. */
/*<       INTRINSIC          ABS, MAX, MIN, SQRT >*/
/*     .. */
/*     .. Executable Statements .. */

/*<       IF( MIN( M, N ).EQ.0 ) THEN >*/
    /* Parameter adjustments */
    --work;
    a_dim1 = *lda;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    if (min(*m,*n) == 0) {
/*<          VALUE = ZERO >*/
	value = 0.;
/*<       ELSE IF( LSAME( NORM, 'M' ) ) THEN >*/
    } else if (lsame_(norm, "M", 1L, 1L)) {

/*        Find max(abs(A(i,j))). */

/*<          VALUE = ZERO >*/
	value = 0.;
/*<          DO 20 J = 1, N >*/
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/*<             DO 10 I = 1, M >*/
	    i__2 = *m;
	    for (i = 1; i <= i__2; ++i) {
/*<                VALUE = MAX( VALUE, ABS( A( I, J ) ) ) >*/
/* Computing MAX */
		d__2 = value, d__3 = (d__1 = a[i + j * a_dim1], abs(d__1));
		value = max(d__2,d__3);
/*<    10       CONTINUE >*/
/* L10: */
	    }
/*<    20    CONTINUE >*/
/* L20: */
	}
/*<       ELSE IF( ( LSAME( NORM, 'O' ) ) .OR. ( NORM.EQ.'1' ) ) THEN >*/
    } else if (lsame_(norm, "O", 1L, 1L) || *norm == '1') {

/*        Find norm1(A). */

/*<          VALUE = ZERO >*/
	value = 0.;
/*<          DO 40 J = 1, N >*/
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/*<             SUM = ZERO >*/
	    sum = 0.;
/*<             DO 30 I = 1, M >*/
	    i__2 = *m;
	    for (i = 1; i <= i__2; ++i) {
/*<                SUM = SUM + ABS( A( I, J ) ) >*/
		sum += (d__1 = a[i + j * a_dim1], abs(d__1));
/*<    30       CONTINUE >*/
/* L30: */
	    }
/*<             VALUE = MAX( VALUE, SUM ) >*/
	    value = max(value,sum);
/*<    40    CONTINUE >*/
/* L40: */
	}
/*<       ELSE IF( LSAME( NORM, 'I' ) ) THEN >*/
    } else if (lsame_(norm, "I", 1L, 1L)) {

/*        Find normI(A). */

/*<          DO 50 I = 1, M >*/
	i__1 = *m;
	for (i = 1; i <= i__1; ++i) {
/*<             WORK( I ) = ZERO >*/
	    work[i] = 0.;
/*<    50    CONTINUE >*/
/* L50: */
	}
/*<          DO 70 J = 1, N >*/
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/*<             DO 60 I = 1, M >*/
	    i__2 = *m;
	    for (i = 1; i <= i__2; ++i) {
/*<                WORK( I ) = WORK( I ) + ABS( A( I, J ) ) >*/
		work[i] += (d__1 = a[i + j * a_dim1], abs(d__1));
/*<    60       CONTINUE >*/
/* L60: */
	    }
/*<    70    CONTINUE >*/
/* L70: */
	}
/*<          VALUE = ZERO >*/
	value = 0.;
/*<          DO 80 I = 1, M >*/
	i__1 = *m;
	for (i = 1; i <= i__1; ++i) {
/*<             VALUE = MAX( VALUE, WORK( I ) ) >*/
/* Computing MAX */
	    d__1 = value, d__2 = work[i];
	    value = max(d__1,d__2);
/*<    80    CONTINUE >*/
/* L80: */
	}
/*<       ELSE IF( ( LSAME( NORM, 'F' ) ) .OR. ( LSAME( NORM, 'E' ) ) ) THEN >*/
    } else if (lsame_(norm, "F", 1L, 1L) || lsame_(norm, "E", 1L, 1L)) {

/*        Find normF(A). */

/*<          SCALE = ZERO >*/
	scale = 0.;
/*<          SUM = ONE >*/
	sum = 1.;
/*<          DO 90 J = 1, N >*/
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/*<             CALL DLASSQ( M, A( 1, J ), 1, SCALE, SUM ) >*/
	    dlassq_(m, &a[j * a_dim1 + 1], &c__1, &scale, &sum);
/*<    90    CONTINUE >*/
/* L90: */
	}
/*<          VALUE = SCALE*SQRT( SUM ) >*/
	value = scale * sqrt(sum);
/*<       END IF >*/
    }

/*<       DLANGE = VALUE >*/
    ret_val = value;
/*<       RETURN >*/
    return ret_val;

/*     End of DLANGE */

/*<       END >*/
} /* dlange_ */

