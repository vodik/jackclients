#ifndef BIQUAD_H
#define BIQUAD_H

/* Simple implementation of Biquad filters -- Tom St Denis
 *
 * Based on the work

Cookbook formulae for audio EQ biquad filter coefficients
---------------------------------------------------------
by Robert Bristow-Johnson, pbjrbj@viconet.com  a.k.a. robert@audioheads.com

 * Available on the web at

http://www.smartelectronix.com/musicdsp/text/filters005.txt
*/

#include <math.h>
#include <stdlib.h>

#ifndef M_LN2
#define M_LN2   0.69314718055994530942
#endif

#ifndef M_PI
#define M_PI	3.14159265358979323846
#endif

/* whatever sample type you want */
typedef double smp_type;

/* this holds the data required to update samples thru a filter */
typedef struct {
    smp_type b0, b1, b2, a1, a2;
    smp_type x1, x2, y1, y2;
}biquad;

/* this holds the control data instructions to compute a 
 * biquad filter */
typedef struct {
    int type;	    /* see filter types below */
    smp_type dBgain;/* gain in dB */
    smp_type fc;    /* cut off / center frequency */
    smp_type fs;    /* sample rate (not actual control data?) */
    smp_type bw;    /* bandwidth in octaves */
}control_list;

extern smp_type BiQuad(smp_type sample, biquad * b);
extern biquad *BiQuad_new(int type, smp_type dbGain, /* gain of filter */
                          smp_type freq,             /* center frequency */
                          smp_type srate,            /* sampling rate */
                          smp_type bandwidth);       /* bandwidth in octaves */

/* filter types */
enum {
    LPF, /* low pass filter */
    HPF, /* High pass filter */
    BPF, /* band pass filter */
    NOTCH, /* Notch Filter */
    PEQ, /* Peaking band EQ filter */
    LSH, /* Low shelf filter */
    HSH /* High shelf filter */
};

/* Filter functions */
smp_type df1(smp_type sample, biquad *b);

biquad *
compute_biquad(int type, smp_type dbGain, smp_type freq, 
	smp_type srate, smp_type bandwidth);

#endif
