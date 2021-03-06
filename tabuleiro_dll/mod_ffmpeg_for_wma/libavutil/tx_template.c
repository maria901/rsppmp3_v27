/*
 * Copyright (c) Lynne
 *
 * Power of two FFT:
 * Copyright (c) Lynne
 * Copyright (c) 2008 Loren Merritt
 * Copyright (c) 2002 Fabrice Bellard
 * Partly based on libdjbfft by D. J. Bernstein
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* All costabs for a type are defined here */
COSTABLE(16);
COSTABLE(32);
COSTABLE(64);
COSTABLE(128);
COSTABLE(256);
COSTABLE(512);
COSTABLE(1024);
COSTABLE(2048);
COSTABLE(4096);
COSTABLE(8192);
COSTABLE(16384);
COSTABLE(32768);
COSTABLE(65536);
COSTABLE(131072);
DECLARE_ALIGNED(32, FFTComplex, TX_NAME(ff_cos_53))[4];
DECLARE_ALIGNED(32, FFTComplex, TX_NAME(ff_cos_7))[3];
DECLARE_ALIGNED(32, FFTComplex, TX_NAME(ff_cos_9))[4];

static FFTSample * const cos_tabs[18] = {
    NULL,
    NULL,
    NULL,
    NULL,
    TX_NAME(ff_cos_16),
    TX_NAME(ff_cos_32),
    TX_NAME(ff_cos_64),
    TX_NAME(ff_cos_128),
    TX_NAME(ff_cos_256),
    TX_NAME(ff_cos_512),
    TX_NAME(ff_cos_1024),
    TX_NAME(ff_cos_2048),
    TX_NAME(ff_cos_4096),
    TX_NAME(ff_cos_8192),
    TX_NAME(ff_cos_16384),
    TX_NAME(ff_cos_32768),
    TX_NAME(ff_cos_65536),
    TX_NAME(ff_cos_131072),
};

static av_always_inline void init_cos_tabs_idx(int index)
{
    int m = 1 << index;
    double freq = 2*M_PI/m;
    FFTSample *tab = cos_tabs[index];

    for (int i = 0; i < m/4; i++)
        *tab++ = RESCALE(cos(i*freq));

    *tab = 0;
}

#define INIT_FF_COS_TABS_FUNC(index, size)                                     \
static av_cold void init_cos_tabs_ ## size (void)                              \
{                                                                              \
    init_cos_tabs_idx(index);                                                  \
}

INIT_FF_COS_TABS_FUNC(4, 16)
INIT_FF_COS_TABS_FUNC(5, 32)
INIT_FF_COS_TABS_FUNC(6, 64)
INIT_FF_COS_TABS_FUNC(7, 128)
INIT_FF_COS_TABS_FUNC(8, 256)
INIT_FF_COS_TABS_FUNC(9, 512)
INIT_FF_COS_TABS_FUNC(10, 1024)
INIT_FF_COS_TABS_FUNC(11, 2048)
INIT_FF_COS_TABS_FUNC(12, 4096)
INIT_FF_COS_TABS_FUNC(13, 8192)
INIT_FF_COS_TABS_FUNC(14, 16384)
INIT_FF_COS_TABS_FUNC(15, 32768)
INIT_FF_COS_TABS_FUNC(16, 65536)
INIT_FF_COS_TABS_FUNC(17, 131072)

static av_cold void ff_init_53_tabs(void)
{
    TX_NAME(ff_cos_53)[0] = (FFTComplex){ RESCALE(cos(2 * M_PI / 12)), RESCALE(cos(2 * M_PI / 12)) };
    TX_NAME(ff_cos_53)[1] = (FFTComplex){ RESCALE(cos(2 * M_PI /  6)), RESCALE(cos(2 * M_PI /  6)) };
    TX_NAME(ff_cos_53)[2] = (FFTComplex){ RESCALE(cos(2 * M_PI /  5)), RESCALE(sin(2 * M_PI /  5)) };
    TX_NAME(ff_cos_53)[3] = (FFTComplex){ RESCALE(cos(2 * M_PI / 10)), RESCALE(sin(2 * M_PI / 10)) };
}

static av_cold void ff_init_7_tabs(void)
{
    TX_NAME(ff_cos_7)[0] = (FFTComplex){ RESCALE(cos(2 * M_PI /  7)), RESCALE(sin(2 * M_PI /  7)) };
    TX_NAME(ff_cos_7)[1] = (FFTComplex){ RESCALE(sin(2 * M_PI / 28)), RESCALE(cos(2 * M_PI / 28)) };
    TX_NAME(ff_cos_7)[2] = (FFTComplex){ RESCALE(cos(2 * M_PI / 14)), RESCALE(sin(2 * M_PI / 14)) };
}

static av_cold void ff_init_9_tabs(void)
{
    TX_NAME(ff_cos_9)[0] = (FFTComplex){ RESCALE(cos(2 * M_PI /  3)), RESCALE( sin(2 * M_PI /  3)) };
    TX_NAME(ff_cos_9)[1] = (FFTComplex){ RESCALE(cos(2 * M_PI /  9)), RESCALE( sin(2 * M_PI /  9)) };
    TX_NAME(ff_cos_9)[2] = (FFTComplex){ RESCALE(cos(2 * M_PI / 36)), RESCALE( sin(2 * M_PI / 36)) };
    TX_NAME(ff_cos_9)[3] = (FFTComplex){ TX_NAME(ff_cos_9)[1].re + TX_NAME(ff_cos_9)[2].im,
                                         TX_NAME(ff_cos_9)[1].im - TX_NAME(ff_cos_9)[2].re };
}

static CosTabsInitOnce cos_tabs_init_once[] = {
    { ff_init_53_tabs, AV_ONCE_INIT },
    { ff_init_7_tabs, AV_ONCE_INIT },
    { ff_init_9_tabs, AV_ONCE_INIT },
    { NULL },
    { init_cos_tabs_16, AV_ONCE_INIT },
    { init_cos_tabs_32, AV_ONCE_INIT },
    { init_cos_tabs_64, AV_ONCE_INIT },
    { init_cos_tabs_128, AV_ONCE_INIT },
    { init_cos_tabs_256, AV_ONCE_INIT },
    { init_cos_tabs_512, AV_ONCE_INIT },
    { init_cos_tabs_1024, AV_ONCE_INIT },
    { init_cos_tabs_2048, AV_ONCE_INIT },
    { init_cos_tabs_4096, AV_ONCE_INIT },
    { init_cos_tabs_8192, AV_ONCE_INIT },
    { init_cos_tabs_16384, AV_ONCE_INIT },
    { init_cos_tabs_32768, AV_ONCE_INIT },
    { init_cos_tabs_65536, AV_ONCE_INIT },
    { init_cos_tabs_131072, AV_ONCE_INIT },
};

static av_cold void init_cos_tabs(int index)
{
    ff_thread_once(&cos_tabs_init_once[index].control,
                    cos_tabs_init_once[index].func);
}

static av_always_inline void fft3(FFTComplex *out, FFTComplex *in,
                                  ptrdiff_t stride)
{
    FFTComplex tmp[2];
#ifdef TX_INT32
    int64_t mtmp[4];
#endif

    BF(tmp[0].re, tmp[1].im, in[1].im, in[2].im);
    BF(tmp[0].im, tmp[1].re, in[1].re, in[2].re);

    out[0*stride].re = in[0].re + tmp[1].re;
    out[0*stride].im = in[0].im + tmp[1].im;

#ifdef TX_INT32
    mtmp[0] = (int64_t)TX_NAME(ff_cos_53)[0].re * tmp[0].re;
    mtmp[1] = (int64_t)TX_NAME(ff_cos_53)[0].im * tmp[0].im;
    mtmp[2] = (int64_t)TX_NAME(ff_cos_53)[1].re * tmp[1].re;
    mtmp[3] = (int64_t)TX_NAME(ff_cos_53)[1].re * tmp[1].im;
    out[1*stride].re = in[0].re - (mtmp[2] + mtmp[0] + 0x40000000 >> 31);
    out[1*stride].im = in[0].im - (mtmp[3] - mtmp[1] + 0x40000000 >> 31);
    out[2*stride].re = in[0].re - (mtmp[2] - mtmp[0] + 0x40000000 >> 31);
    out[2*stride].im = in[0].im - (mtmp[3] + mtmp[1] + 0x40000000 >> 31);
#else
    tmp[0].re = TX_NAME(ff_cos_53)[0].re * tmp[0].re;
    tmp[0].im = TX_NAME(ff_cos_53)[0].im * tmp[0].im;
    tmp[1].re = TX_NAME(ff_cos_53)[1].re * tmp[1].re;
    tmp[1].im = TX_NAME(ff_cos_53)[1].re * tmp[1].im;
    out[1*stride].re = in[0].re - tmp[1].re + tmp[0].re;
    out[1*stride].im = in[0].im - tmp[1].im - tmp[0].im;
    out[2*stride].re = in[0].re - tmp[1].re - tmp[0].re;
    out[2*stride].im = in[0].im - tmp[1].im + tmp[0].im;
#endif
}

#define DECL_FFT5(NAME, D0, D1, D2, D3, D4)                                                       \
static av_always_inline void NAME(FFTComplex *out, FFTComplex *in,                                \
                                  ptrdiff_t stride)                                               \
{                                                                                                 \
    FFTComplex z0[4], t[6];                                                                       \
                                                                                                  \
    BF(t[1].im, t[0].re, in[1].re, in[4].re);                                                     \
    BF(t[1].re, t[0].im, in[1].im, in[4].im);                                                     \
    BF(t[3].im, t[2].re, in[2].re, in[3].re);                                                     \
    BF(t[3].re, t[2].im, in[2].im, in[3].im);                                                     \
                                                                                                  \
    out[D0*stride].re = in[0].re + t[0].re + t[2].re;                                             \
    out[D0*stride].im = in[0].im + t[0].im + t[2].im;                                             \
                                                                                                  \
    SMUL(t[4].re, t[0].re, TX_NAME(ff_cos_53)[2].re, TX_NAME(ff_cos_53)[3].re, t[2].re, t[0].re); \
    SMUL(t[4].im, t[0].im, TX_NAME(ff_cos_53)[2].re, TX_NAME(ff_cos_53)[3].re, t[2].im, t[0].im); \
    CMUL(t[5].re, t[1].re, TX_NAME(ff_cos_53)[2].im, TX_NAME(ff_cos_53)[3].im, t[3].re, t[1].re); \
    CMUL(t[5].im, t[1].im, TX_NAME(ff_cos_53)[2].im, TX_NAME(ff_cos_53)[3].im, t[3].im, t[1].im); \
                                                                                                  \
    BF(z0[0].re, z0[3].re, t[0].re, t[1].re);                                                     \
    BF(z0[0].im, z0[3].im, t[0].im, t[1].im);                                                     \
    BF(z0[2].re, z0[1].re, t[4].re, t[5].re);                                                     \
    BF(z0[2].im, z0[1].im, t[4].im, t[5].im);                                                     \
                                                                                                  \
    out[D1*stride].re = in[0].re + z0[3].re;                                                      \
    out[D1*stride].im = in[0].im + z0[0].im;                                                      \
    out[D2*stride].re = in[0].re + z0[2].re;                                                      \
    out[D2*stride].im = in[0].im + z0[1].im;                                                      \
    out[D3*stride].re = in[0].re + z0[1].re;                                                      \
    out[D3*stride].im = in[0].im + z0[2].im;                                                      \
    out[D4*stride].re = in[0].re + z0[0].re;                                                      \
    out[D4*stride].im = in[0].im + z0[3].im;                                                      \
}

DECL_FFT5(fft5,     0,  1,  2,  3,  4)
DECL_FFT5(fft5_m1,  0,  6, 12,  3,  9)
DECL_FFT5(fft5_m2, 10,  1,  7, 13,  4)
DECL_FFT5(fft5_m3,  5, 11,  2,  8, 14)

static av_always_inline void fft7(FFTComplex *out, FFTComplex *in,
                                  ptrdiff_t stride)
{
    FFTComplex t[6], z[3];
    const FFTComplex *tab = TX_NAME(ff_cos_7);
#ifdef TX_INT32
    int64_t mtmp[12];
#endif

    BF(t[1].re, t[0].re, in[1].re, in[6].re);
    BF(t[1].im, t[0].im, in[1].im, in[6].im);
    BF(t[3].re, t[2].re, in[2].re, in[5].re);
    BF(t[3].im, t[2].im, in[2].im, in[5].im);
    BF(t[5].re, t[4].re, in[3].re, in[4].re);
    BF(t[5].im, t[4].im, in[3].im, in[4].im);

    out[0*stride].re = in[0].re + t[0].re + t[2].re + t[4].re;
    out[0*stride].im = in[0].im + t[0].im + t[2].im + t[4].im;

#ifdef TX_INT32 /* NOTE: it's possible to do this with 16 mults but 72 adds */
    mtmp[ 0] = ((int64_t)tab[0].re)*t[0].re - ((int64_t)tab[2].re)*t[4].re;
    mtmp[ 1] = ((int64_t)tab[0].re)*t[4].re - ((int64_t)tab[1].re)*t[0].re;
    mtmp[ 2] = ((int64_t)tab[0].re)*t[2].re - ((int64_t)tab[2].re)*t[0].re;
    mtmp[ 3] = ((int64_t)tab[0].re)*t[0].im - ((int64_t)tab[1].re)*t[2].im;
    mtmp[ 4] = ((int64_t)tab[0].re)*t[4].im - ((int64_t)tab[1].re)*t[0].im;
    mtmp[ 5] = ((int64_t)tab[0].re)*t[2].im - ((int64_t)tab[2].re)*t[0].im;

    mtmp[ 6] = ((int64_t)tab[2].im)*t[1].im + ((int64_t)tab[1].im)*t[5].im;
    mtmp[ 7] = ((int64_t)tab[0].im)*t[5].im + ((int64_t)tab[2].im)*t[3].im;
    mtmp[ 8] = ((int64_t)tab[2].im)*t[5].im + ((int64_t)tab[1].im)*t[3].im;
    mtmp[ 9] = ((int64_t)tab[0].im)*t[1].re + ((int64_t)tab[1].im)*t[3].re;
    mtmp[10] = ((int64_t)tab[2].im)*t[3].re + ((int64_t)tab[0].im)*t[5].re;
    mtmp[11] = ((int64_t)tab[2].im)*t[1].re + ((int64_t)tab[1].im)*t[5].re;

    z[0].re = (int32_t)(mtmp[ 0] - ((int64_t)tab[1].re)*t[2].re + 0x40000000 >> 31);
    z[1].re = (int32_t)(mtmp[ 1] - ((int64_t)tab[2].re)*t[2].re + 0x40000000 >> 31);
    z[2].re = (int32_t)(mtmp[ 2] - ((int64_t)tab[1].re)*t[4].re + 0x40000000 >> 31);
    z[0].im = (int32_t)(mtmp[ 3] - ((int64_t)tab[2].re)*t[4].im + 0x40000000 >> 31);
    z[1].im = (int32_t)(mtmp[ 4] - ((int64_t)tab[2].re)*t[2].im + 0x40000000 >> 31);
    z[2].im = (int32_t)(mtmp[ 5] - ((int64_t)tab[1].re)*t[4].im + 0x40000000 >> 31);

    t[0].re = (int32_t)(mtmp[ 6] - ((int64_t)tab[0].im)*t[3].im + 0x40000000 >> 31);
    t[2].re = (int32_t)(mtmp[ 7] - ((int64_t)tab[1].im)*t[1].im + 0x40000000 >> 31);
    t[4].re = (int32_t)(mtmp[ 8] + ((int64_t)tab[0].im)*t[1].im + 0x40000000 >> 31);
    t[0].im = (int32_t)(mtmp[ 9] + ((int64_t)tab[2].im)*t[5].re + 0x40000000 >> 31);
    t[2].im = (int32_t)(mtmp[10] - ((int64_t)tab[1].im)*t[1].re + 0x40000000 >> 31);
    t[4].im = (int32_t)(mtmp[11] - ((int64_t)tab[0].im)*t[3].re + 0x40000000 >> 31);
#else
    z[0].re = tab[0].re*t[0].re - tab[2].re*t[4].re - tab[1].re*t[2].re;
    z[1].re = tab[0].re*t[4].re - tab[1].re*t[0].re - tab[2].re*t[2].re;
    z[2].re = tab[0].re*t[2].re - tab[2].re*t[0].re - tab[1].re*t[4].re;
    z[0].im = tab[0].re*t[0].im - tab[1].re*t[2].im - tab[2].re*t[4].im;
    z[1].im = tab[0].re*t[4].im - tab[1].re*t[0].im - tab[2].re*t[2].im;
    z[2].im = tab[0].re*t[2].im - tab[2].re*t[0].im - tab[1].re*t[4].im;

    /* It's possible to do t[4].re and t[0].im with 2 multiplies only by
     * multiplying the sum of all with the average of the twiddles */

    t[0].re = tab[2].im*t[1].im + tab[1].im*t[5].im - tab[0].im*t[3].im;
    t[2].re = tab[0].im*t[5].im + tab[2].im*t[3].im - tab[1].im*t[1].im;
    t[4].re = tab[2].im*t[5].im + tab[1].im*t[3].im + tab[0].im*t[1].im;
    t[0].im = tab[0].im*t[1].re + tab[1].im*t[3].re + tab[2].im*t[5].re;
    t[2].im = tab[2].im*t[3].re + tab[0].im*t[5].re - tab[1].im*t[1].re;
    t[4].im = tab[2].im*t[1].re + tab[1].im*t[5].re - tab[0].im*t[3].re;
#endif

    BF(t[1].re, z[0].re, z[0].re, t[4].re);
    BF(t[3].re, z[1].re, z[1].re, t[2].re);
    BF(t[5].re, z[2].re, z[2].re, t[0].re);
    BF(t[1].im, z[0].im, z[0].im, t[0].im);
    BF(t[3].im, z[1].im, z[1].im, t[2].im);
    BF(t[5].im, z[2].im, z[2].im, t[4].im);

    out[1*stride].re = in[0].re + z[0].re;
    out[1*stride].im = in[0].im + t[1].im;
    out[2*stride].re = in[0].re + t[3].re;
    out[2*stride].im = in[0].im + z[1].im;
    out[3*stride].re = in[0].re + z[2].re;
    out[3*stride].im = in[0].im + t[5].im;
    out[4*stride].re = in[0].re + t[5].re;
    out[4*stride].im = in[0].im + z[2].im;
    out[5*stride].re = in[0].re + z[1].re;
    out[5*stride].im = in[0].im + t[3].im;
    out[6*stride].re = in[0].re + t[1].re;
    out[6*stride].im = in[0].im + z[0].im;
}

static av_always_inline void fft9(FFTComplex *out, FFTComplex *in,
                                  ptrdiff_t stride)
{
    const FFTComplex *tab = TX_NAME(ff_cos_9);
    FFTComplex t[16], w[4], x[5], y[5], z[2];
#ifdef TX_INT32
    int64_t mtmp[12];
#endif

    BF(t[1].re, t[0].re, in[1].re, in[8].re);
    BF(t[1].im, t[0].im, in[1].im, in[8].im);
    BF(t[3].re, t[2].re, in[2].re, in[7].re);
    BF(t[3].im, t[2].im, in[2].im, in[7].im);
    BF(t[5].re, t[4].re, in[3].re, in[6].re);
    BF(t[5].im, t[4].im, in[3].im, in[6].im);
    BF(t[7].re, t[6].re, in[4].re, in[5].re);
    BF(t[7].im, t[6].im, in[4].im, in[5].im);

    w[0].re = t[0].re - t[6].re;
    w[0].im = t[0].im - t[6].im;
    w[1].re = t[2].re - t[6].re;
    w[1].im = t[2].im - t[6].im;
    w[2].re = t[1].re - t[7].re;
    w[2].im = t[1].im - t[7].im;
    w[3].re = t[3].re + t[7].re;
    w[3].im = t[3].im + t[7].im;

    z[0].re = in[0].re + t[4].re;
    z[0].im = in[0].im + t[4].im;

    z[1].re = t[0].re + t[2].re + t[6].re;
    z[1].im = t[0].im + t[2].im + t[6].im;

    out[0*stride].re = z[0].re + z[1].re;
    out[0*stride].im = z[0].im + z[1].im;

#ifdef TX_INT32
    mtmp[0] = t[1].re - t[3].re + t[7].re;
    mtmp[1] = t[1].im - t[3].im + t[7].im;

    y[3].re = (int32_t)(((int64_t)tab[0].im)*mtmp[0] + 0x40000000 >> 31);
    y[3].im = (int32_t)(((int64_t)tab[0].im)*mtmp[1] + 0x40000000 >> 31);

    mtmp[0] = (int32_t)(((int64_t)tab[0].re)*z[1].re + 0x40000000 >> 31);
    mtmp[1] = (int32_t)(((int64_t)tab[0].re)*z[1].im + 0x40000000 >> 31);
    mtmp[2] = (int32_t)(((int64_t)tab[0].re)*t[4].re + 0x40000000 >> 31);
    mtmp[3] = (int32_t)(((int64_t)tab[0].re)*t[4].im + 0x40000000 >> 31);

    x[3].re = z[0].re  + (int32_t)mtmp[0];
    x[3].im = z[0].im  + (int32_t)mtmp[1];
    z[0].re = in[0].re + (int32_t)mtmp[2];
    z[0].im = in[0].im + (int32_t)mtmp[3];

    mtmp[0] = ((int64_t)tab[1].re)*w[0].re;
    mtmp[1] = ((int64_t)tab[1].re)*w[0].im;
    mtmp[2] = ((int64_t)tab[2].im)*w[0].re;
    mtmp[3] = ((int64_t)tab[2].im)*w[0].im;
    mtmp[4] = ((int64_t)tab[1].im)*w[2].re;
    mtmp[5] = ((int64_t)tab[1].im)*w[2].im;
    mtmp[6] = ((int64_t)tab[2].re)*w[2].re;
    mtmp[7] = ((int64_t)tab[2].re)*w[2].im;

    x[1].re = (int32_t)(mtmp[0] + ((int64_t)tab[2].im)*w[1].re + 0x40000000 >> 31);
    x[1].im = (int32_t)(mtmp[1] + ((int64_t)tab[2].im)*w[1].im + 0x40000000 >> 31);
    x[2].re = (int32_t)(mtmp[2] - ((int64_t)tab[3].re)*w[1].re + 0x40000000 >> 31);
    x[2].im = (int32_t)(mtmp[3] - ((int64_t)tab[3].re)*w[1].im + 0x40000000 >> 31);
    y[1].re = (int32_t)(mtmp[4] + ((int64_t)tab[2].re)*w[3].re + 0x40000000 >> 31);
    y[1].im = (int32_t)(mtmp[5] + ((int64_t)tab[2].re)*w[3].im + 0x40000000 >> 31);
    y[2].re = (int32_t)(mtmp[6] - ((int64_t)tab[3].im)*w[3].re + 0x40000000 >> 31);
    y[2].im = (int32_t)(mtmp[7] - ((int64_t)tab[3].im)*w[3].im + 0x40000000 >> 31);

    y[0].re = (int32_t)(((int64_t)tab[0].im)*t[5].re + 0x40000000 >> 31);
    y[0].im = (int32_t)(((int64_t)tab[0].im)*t[5].im + 0x40000000 >> 31);

#else
    y[3].re = tab[0].im*(t[1].re - t[3].re + t[7].re);
    y[3].im = tab[0].im*(t[1].im - t[3].im + t[7].im);

    x[3].re = z[0].re  + tab[0].re*z[1].re;
    x[3].im = z[0].im  + tab[0].re*z[1].im;
    z[0].re = in[0].re + tab[0].re*t[4].re;
    z[0].im = in[0].im + tab[0].re*t[4].im;

    x[1].re = tab[1].re*w[0].re + tab[2].im*w[1].re;
    x[1].im = tab[1].re*w[0].im + tab[2].im*w[1].im;
    x[2].re = tab[2].im*w[0].re - tab[3].re*w[1].re;
    x[2].im = tab[2].im*w[0].im - tab[3].re*w[1].im;
    y[1].re = tab[1].im*w[2].re + tab[2].re*w[3].re;
    y[1].im = tab[1].im*w[2].im + tab[2].re*w[3].im;
    y[2].re = tab[2].re*w[2].re - tab[3].im*w[3].re;
    y[2].im = tab[2].re*w[2].im - tab[3].im*w[3].im;

    y[0].re = tab[0].im*t[5].re;
    y[0].im = tab[0].im*t[5].im;
#endif

    x[4].re = x[1].re + x[2].re;
    x[4].im = x[1].im + x[2].im;

    y[4].re = y[1].re - y[2].re;
    y[4].im = y[1].im - y[2].im;
    x[1].re = z[0].re + x[1].re;
    x[1].im = z[0].im + x[1].im;
    y[1].re = y[0].re + y[1].re;
    y[1].im = y[0].im + y[1].im;
    x[2].re = z[0].re + x[2].re;
    x[2].im = z[0].im + x[2].im;
    y[2].re = y[2].re - y[0].re;
    y[2].im = y[2].im - y[0].im;
    x[4].re = z[0].re - x[4].re;
    x[4].im = z[0].im - x[4].im;
    y[4].re = y[0].re - y[4].re;
    y[4].im = y[0].im - y[4].im;

    out[1*stride] = (FFTComplex){ x[1].re + y[1].im, x[1].im - y[1].re };
    out[2*stride] = (FFTComplex){ x[2].re + y[2].im, x[2].im - y[2].re };
    out[3*stride] = (FFTComplex){ x[3].re + y[3].im, x[3].im - y[3].re };
    out[4*stride] = (FFTComplex){ x[4].re + y[4].im, x[4].im - y[4].re };
    out[5*stride] = (FFTComplex){ x[4].re - y[4].im, x[4].im + y[4].re };
    out[6*stride] = (FFTComplex){ x[3].re - y[3].im, x[3].im + y[3].re };
    out[7*stride] = (FFTComplex){ x[2].re - y[2].im, x[2].im + y[2].re };
    out[8*stride] = (FFTComplex){ x[1].re - y[1].im, x[1].im + y[1].re };
}

static av_always_inline void fft15(FFTComplex *out, FFTComplex *in,
                                   ptrdiff_t stride)
{
    FFTComplex tmp[15];

    for (int i = 0; i < 5; i++)
        fft3(tmp + i, in + i*3, 5);

    fft5_m1(out, tmp +  0, stride);
    fft5_m2(out, tmp +  5, stride);
    fft5_m3(out, tmp + 10, stride);
}

#define BUTTERFLIES(a0,a1,a2,a3)               \
    do {                                       \
        r0=a0.re;                              \
        i0=a0.im;                              \
        r1=a1.re;                              \
        i1=a1.im;                              \
        BF(t3, t5, t5, t1);                    \
        BF(a2.re, a0.re, r0, t5);              \
        BF(a3.im, a1.im, i1, t3);              \
        BF(t4, t6, t2, t6);                    \
        BF(a3.re, a1.re, r1, t4);              \
        BF(a2.im, a0.im, i0, t6);              \
    } while (0)

#define TRANSFORM(a0,a1,a2,a3,wre,wim)         \
    do {                                       \
        CMUL(t1, t2, a2.re, a2.im, wre, -wim); \
        CMUL(t5, t6, a3.re, a3.im, wre,  wim); \
        BUTTERFLIES(a0, a1, a2, a3);           \
    } while (0)

/* z[0...8n-1], w[1...2n-1] */
static void split_radix_combine(FFTComplex *z, const FFTSample *cos, int n)
{
    int o1 = 2*n;
    int o2 = 4*n;
    int o3 = 6*n;
    const FFTSample *wim = cos + o1 - 7;
    FFTSample t1, t2, t3, t4, t5, t6, r0, i0, r1, i1;

    for (int i = 0; i < n; i += 4) {
        TRANSFORM(z[0], z[o1 + 0], z[o2 + 0], z[o3 + 0], cos[0], wim[7]);
        TRANSFORM(z[2], z[o1 + 2], z[o2 + 2], z[o3 + 2], cos[2], wim[5]);
        TRANSFORM(z[4], z[o1 + 4], z[o2 + 4], z[o3 + 4], cos[4], wim[3]);
        TRANSFORM(z[6], z[o1 + 6], z[o2 + 6], z[o3 + 6], cos[6], wim[1]);

        TRANSFORM(z[1], z[o1 + 1], z[o2 + 1], z[o3 + 1], cos[1], wim[6]);
        TRANSFORM(z[3], z[o1 + 3], z[o2 + 3], z[o3 + 3], cos[3], wim[4]);
        TRANSFORM(z[5], z[o1 + 5], z[o2 + 5], z[o3 + 5], cos[5], wim[2]);
        TRANSFORM(z[7], z[o1 + 7], z[o2 + 7], z[o3 + 7], cos[7], wim[0]);

        z   += 2*4;
        cos += 2*4;
        wim -= 2*4;
    }
}

#define DECL_FFT(n, n2, n4)                            \
static void fft##n(FFTComplex *z)                      \
{                                                      \
    fft##n2(z);                                        \
    fft##n4(z + n4*2);                                 \
    fft##n4(z + n4*3);                                 \
    split_radix_combine(z, TX_NAME(ff_cos_##n), n4/2); \
}

static void fft2(FFTComplex *z)
{
    FFTComplex tmp;
    BF(tmp.re, z[0].re, z[0].re, z[1].re);
    BF(tmp.im, z[0].im, z[0].im, z[1].im);
    z[1] = tmp;
}

static void fft4(FFTComplex *z)
{
    FFTSample t1, t2, t3, t4, t5, t6, t7, t8;

    BF(t3, t1, z[0].re, z[1].re);
    BF(t8, t6, z[3].re, z[2].re);
    BF(z[2].re, z[0].re, t1, t6);
    BF(t4, t2, z[0].im, z[1].im);
    BF(t7, t5, z[2].im, z[3].im);
    BF(z[3].im, z[1].im, t4, t8);
    BF(z[3].re, z[1].re, t3, t7);
    BF(z[2].im, z[0].im, t2, t5);
}

static void fft8(FFTComplex *z)
{
    FFTSample t1, t2, t3, t4, t5, t6, r0, i0, r1, i1;

    fft4(z);

    BF(t1, z[5].re, z[4].re, -z[5].re);
    BF(t2, z[5].im, z[4].im, -z[5].im);
    BF(t5, z[7].re, z[6].re, -z[7].re);
    BF(t6, z[7].im, z[6].im, -z[7].im);

    BUTTERFLIES(z[0], z[2], z[4], z[6]);
    TRANSFORM(z[1], z[3], z[5], z[7], RESCALE(M_SQRT1_2), RESCALE(M_SQRT1_2));
}

static void fft16(FFTComplex *z)
{
    FFTSample t1, t2, t3, t4, t5, t6, r0, i0, r1, i1;
    FFTSample cos_16_1 = TX_NAME(ff_cos_16)[1];
    FFTSample cos_16_2 = TX_NAME(ff_cos_16)[2];
    FFTSample cos_16_3 = TX_NAME(ff_cos_16)[3];

    fft8(z +  0);
    fft4(z +  8);
    fft4(z + 12);

    t1 = z[ 8].re;
    t2 = z[ 8].im;
    t5 = z[12].re;
    t6 = z[12].im;
    BUTTERFLIES(z[0], z[4], z[8], z[12]);

    TRANSFORM(z[ 2], z[ 6], z[10], z[14], cos_16_2, cos_16_2);
    TRANSFORM(z[ 1], z[ 5], z[ 9], z[13], cos_16_1, cos_16_3);
    TRANSFORM(z[ 3], z[ 7], z[11], z[15], cos_16_3, cos_16_1);
}

DECL_FFT(32,16,8)
DECL_FFT(64,32,16)
DECL_FFT(128,64,32)
DECL_FFT(256,128,64)
DECL_FFT(512,256,128)
DECL_FFT(1024,512,256)
DECL_FFT(2048,1024,512)
DECL_FFT(4096,2048,1024)
DECL_FFT(8192,4096,2048)
DECL_FFT(16384,8192,4096)
DECL_FFT(32768,16384,8192)
DECL_FFT(65536,32768,16384)
DECL_FFT(131072,65536,32768)

static void (* const fft_dispatch[])(FFTComplex*) = {
    NULL, fft2, fft4, fft8, fft16, fft32, fft64, fft128, fft256, fft512,
    fft1024, fft2048, fft4096, fft8192, fft16384, fft32768, fft65536, fft131072
};

#define DECL_COMP_FFT(N)                                                       \
static void compound_fft_##N##xM(AVTXContext *s, void *_out,                   \
                                 void *_in, ptrdiff_t stride)                  \
{                                                                              \
    const int m = s->m, *in_map = s->pfatab, *out_map = in_map + N*m;          \
    FFTComplex *in = _in;                                                      \
    FFTComplex *out = _out;                                                    \
    FFTComplex fft##N##in[N];                                                  \
    void (*fftp)(FFTComplex *z) = fft_dispatch[av_log2(m)];                    \
                                                                               \
    for (int i = 0; i < m; i++) {                                              \
        for (int j = 0; j < N; j++)                                            \
            fft##N##in[j] = in[in_map[i*N + j]];                               \
        fft##N(s->tmp + s->revtab_c[i], fft##N##in, m);                        \
    }                                                                          \
                                                                               \
    for (int i = 0; i < N; i++)                                                \
        fftp(s->tmp + m*i);                                                    \
                                                                               \
    for (int i = 0; i < N*m; i++)                                              \
        out[i] = s->tmp[out_map[i]];                                           \
}

DECL_COMP_FFT(3)
DECL_COMP_FFT(5)
DECL_COMP_FFT(7)
DECL_COMP_FFT(9)
DECL_COMP_FFT(15)

static void split_radix_fft(AVTXContext *s, void *_out, void *_in,
                            ptrdiff_t stride)
{
    FFTComplex *in = _in;
    FFTComplex *out = _out;
    int m = s->m, mb = av_log2(m);

    if (s->flags & AV_TX_INPLACE) {
        FFTComplex tmp;
        int src, dst, *inplace_idx = s->inplace_idx;

        src = *inplace_idx++;

        do {
            tmp = out[src];
            dst = s->revtab_c[src];
            do {
                FFSWAP(FFTComplex, tmp, out[dst]);
                dst = s->revtab_c[dst];
            } while (dst != src); /* Can be > as well, but is less predictable */
            out[dst] = tmp;
        } while ((src = *inplace_idx++));
    } else {
        for (int i = 0; i < m; i++)
            out[i] = in[s->revtab_c[i]];
    }

    fft_dispatch[mb](out);
}

static void naive_fft(AVTXContext *s, void *_out, void *_in,
                      ptrdiff_t stride)
{
    FFTComplex *in = _in;
    FFTComplex *out = _out;
    const int n = s->n;
    double phase = s->inv ? 2.0*M_PI/n : -2.0*M_PI/n;

    for(int i = 0; i < n; i++) {
        FFTComplex tmp = { 0 };
        for(int j = 0; j < n; j++) {
            const double factor = phase*i*j;
            const FFTComplex mult = {
                RESCALE(cos(factor)),
                RESCALE(sin(factor)),
            };
            FFTComplex res;
            CMUL3(res, in[j], mult);
            tmp.re += res.re;
            tmp.im += res.im;
        }
        out[i] = tmp;
    }
}

#define DECL_COMP_IMDCT(N)                                                     \
static void compound_imdct_##N##xM(AVTXContext *s, void *_dst, void *_src,     \
                                   ptrdiff_t stride)                           \
{                                                                              \
    FFTComplex fft##N##in[N];                                                  \
    FFTComplex *z = _dst, *exp = s->exptab;                                    \
    const int m = s->m, len8 = N*m >> 1;                                       \
    const int *in_map = s->pfatab, *out_map = in_map + N*m;                    \
    const FFTSample *src = _src, *in1, *in2;                                   \
    void (*fftp)(FFTComplex *) = fft_dispatch[av_log2(m)];                     \
                                                                               \
    stride /= sizeof(*src); /* To convert it from bytes */                     \
    in1 = src;                                                                 \
    in2 = src + ((N*m*2) - 1) * stride;                                        \
                                                                               \
    for (int i = 0; i < m; i++) {                                              \
        for (int j = 0; j < N; j++) {                                          \
            const int k = in_map[i*N + j];                                     \
            FFTComplex tmp = { in2[-k*stride], in1[k*stride] };                \
            CMUL3(fft##N##in[j], tmp, exp[k >> 1]);                            \
        }                                                                      \
        fft##N(s->tmp + s->revtab_c[i], fft##N##in, m);                        \
    }                                                                          \
                                                                               \
    for (int i = 0; i < N; i++)                                                \
        fftp(s->tmp + m*i);                                                    \
                                                                               \
    for (int i = 0; i < len8; i++) {                                           \
        const int i0 = len8 + i, i1 = len8 - i - 1;                            \
        const int s0 = out_map[i0], s1 = out_map[i1];                          \
        FFTComplex src1 = { s->tmp[s1].im, s->tmp[s1].re };                    \
        FFTComplex src0 = { s->tmp[s0].im, s->tmp[s0].re };                    \
                                                                               \
        CMUL(z[i1].re, z[i0].im, src1.re, src1.im, exp[i1].im, exp[i1].re);    \
        CMUL(z[i0].re, z[i1].im, src0.re, src0.im, exp[i0].im, exp[i0].re);    \
    }                                                                          \
}

DECL_COMP_IMDCT(3)
DECL_COMP_IMDCT(5)
DECL_COMP_IMDCT(7)
DECL_COMP_IMDCT(9)
DECL_COMP_IMDCT(15)

#define DECL_COMP_MDCT(N)                                                      \
static void compound_mdct_##N##xM(AVTXContext *s, void *_dst, void *_src,      \
                                  ptrdiff_t stride)                            \
{                                                                              \
    FFTSample *src = _src, *dst = _dst;                                        \
    FFTComplex *exp = s->exptab, tmp, fft##N##in[N];                           \
    const int m = s->m, len4 = N*m, len3 = len4 * 3, len8 = len4 >> 1;         \
    const int *in_map = s->pfatab, *out_map = in_map + N*m;                    \
    void (*fftp)(FFTComplex *) = fft_dispatch[av_log2(m)];                     \
                                                                               \
    stride /= sizeof(*dst);                                                    \
                                                                               \
    for (int i = 0; i < m; i++) { /* Folding and pre-reindexing */             \
        for (int j = 0; j < N; j++) {                                          \
            const int k = in_map[i*N + j];                                     \
            if (k < len4) {                                                    \
                tmp.re = FOLD(-src[ len4 + k],  src[1*len4 - 1 - k]);          \
                tmp.im = FOLD(-src[ len3 + k], -src[1*len3 - 1 - k]);          \
            } else {                                                           \
                tmp.re = FOLD(-src[ len4 + k], -src[5*len4 - 1 - k]);          \
                tmp.im = FOLD( src[-len4 + k], -src[1*len3 - 1 - k]);          \
            }                                                                  \
            CMUL(fft##N##in[j].im, fft##N##in[j].re, tmp.re, tmp.im,           \
                 exp[k >> 1].re, exp[k >> 1].im);                              \
        }                                                                      \
        fft##N(s->tmp + s->revtab_c[i], fft##N##in, m);                        \
    }                                                                          \
                                                                               \
    for (int i = 0; i < N; i++)                                                \
        fftp(s->tmp + m*i);                                                    \
                                                                               \
    for (int i = 0; i < len8; i++) {                                           \
        const int i0 = len8 + i, i1 = len8 - i - 1;                            \
        const int s0 = out_map[i0], s1 = out_map[i1];                          \
        FFTComplex src1 = { s->tmp[s1].re, s->tmp[s1].im };                    \
        FFTComplex src0 = { s->tmp[s0].re, s->tmp[s0].im };                    \
                                                                               \
        CMUL(dst[2*i1*stride + stride], dst[2*i0*stride], src0.re, src0.im,    \
             exp[i0].im, exp[i0].re);                                          \
        CMUL(dst[2*i0*stride + stride], dst[2*i1*stride], src1.re, src1.im,    \
             exp[i1].im, exp[i1].re);                                          \
    }                                                                          \
}

DECL_COMP_MDCT(3)
DECL_COMP_MDCT(5)
DECL_COMP_MDCT(7)
DECL_COMP_MDCT(9)
DECL_COMP_MDCT(15)

static void monolithic_imdct(AVTXContext *s, void *_dst, void *_src,
                             ptrdiff_t stride)
{
    FFTComplex *z = _dst, *exp = s->exptab;
    const int m = s->m, len8 = m >> 1;
    const FFTSample *src = _src, *in1, *in2;
    void (*fftp)(FFTComplex *) = fft_dispatch[av_log2(m)];

    stride /= sizeof(*src);
    in1 = src;
    in2 = src + ((m*2) - 1) * stride;

    for (int i = 0; i < m; i++) {
        FFTComplex tmp = { in2[-2*i*stride], in1[2*i*stride] };
        CMUL3(z[s->revtab_c[i]], tmp, exp[i]);
    }

    fftp(z);

    for (int i = 0; i < len8; i++) {
        const int i0 = len8 + i, i1 = len8 - i - 1;
        FFTComplex src1 = { z[i1].im, z[i1].re };
        FFTComplex src0 = { z[i0].im, z[i0].re };

        CMUL(z[i1].re, z[i0].im, src1.re, src1.im, exp[i1].im, exp[i1].re);
        CMUL(z[i0].re, z[i1].im, src0.re, src0.im, exp[i0].im, exp[i0].re);
    }
}

static void monolithic_mdct(AVTXContext *s, void *_dst, void *_src,
                            ptrdiff_t stride)
{
    FFTSample *src = _src, *dst = _dst;
    FFTComplex *exp = s->exptab, tmp, *z = _dst;
    const int m = s->m, len4 = m, len3 = len4 * 3, len8 = len4 >> 1;
    void (*fftp)(FFTComplex *) = fft_dispatch[av_log2(m)];

    stride /= sizeof(*dst);

    for (int i = 0; i < m; i++) { /* Folding and pre-reindexing */
        const int k = 2*i;
        if (k < len4) {
            tmp.re = FOLD(-src[ len4 + k],  src[1*len4 - 1 - k]);
            tmp.im = FOLD(-src[ len3 + k], -src[1*len3 - 1 - k]);
        } else {
            tmp.re = FOLD(-src[ len4 + k], -src[5*len4 - 1 - k]);
            tmp.im = FOLD( src[-len4 + k], -src[1*len3 - 1 - k]);
        }
        CMUL(z[s->revtab_c[i]].im, z[s->revtab_c[i]].re, tmp.re, tmp.im,
             exp[i].re, exp[i].im);
    }

    fftp(z);

    for (int i = 0; i < len8; i++) {
        const int i0 = len8 + i, i1 = len8 - i - 1;
        FFTComplex src1 = { z[i1].re, z[i1].im };
        FFTComplex src0 = { z[i0].re, z[i0].im };

        CMUL(dst[2*i1*stride + stride], dst[2*i0*stride], src0.re, src0.im,
             exp[i0].im, exp[i0].re);
        CMUL(dst[2*i0*stride + stride], dst[2*i1*stride], src1.re, src1.im,
             exp[i1].im, exp[i1].re);
    }
}

static void naive_imdct(AVTXContext *s, void *_dst, void *_src,
                        ptrdiff_t stride)
{
    int len = s->n;
    int len2 = len*2;
    FFTSample *src = _src;
    FFTSample *dst = _dst;
    double scale = s->scale;
    const double phase = M_PI/(4.0*len2);

    stride /= sizeof(*src);

    for (int i = 0; i < len; i++) {
        double sum_d = 0.0;
        double sum_u = 0.0;
        double i_d = phase * (4*len  - 2*i - 1);
        double i_u = phase * (3*len2 + 2*i + 1);
        for (int j = 0; j < len2; j++) {
            double a = (2 * j + 1);
            double a_d = cos(a * i_d);
            double a_u = cos(a * i_u);
            double val = UNSCALE(src[j*stride]);
            sum_d += a_d * val;
            sum_u += a_u * val;
        }
        dst[i +   0] = RESCALE( sum_d*scale);
        dst[i + len] = RESCALE(-sum_u*scale);
    }
}

static void naive_mdct(AVTXContext *s, void *_dst, void *_src,
                       ptrdiff_t stride)
{
    int len = s->n*2;
    FFTSample *src = _src;
    FFTSample *dst = _dst;
    double scale = s->scale;
    const double phase = M_PI/(4.0*len);

    stride /= sizeof(*dst);

    for (int i = 0; i < len; i++) {
        double sum = 0.0;
        for (int j = 0; j < len*2; j++) {
            int a = (2*j + 1 + len) * (2*i + 1);
            sum += UNSCALE(src[j]) * cos(a * phase);
        }
        dst[i*stride] = RESCALE(sum*scale);
    }
}

static void full_imdct_wrapper_fn(AVTXContext *s, void *_dst, void *_src,
                                  ptrdiff_t stride)
{
    int len = s->m*s->n*4;
    int len2 = len >> 1;
    int len4 = len >> 2;
    FFTSample *dst = _dst;

    s->top_tx(s, dst + len4, _src, stride);

    stride /= sizeof(*dst);

    for (int i = 0; i < len4; i++) {
        dst[            i*stride] = -dst[(len2 - i - 1)*stride];
        dst[(len - i - 1)*stride] =  dst[(len2 + i + 0)*stride];
    }
}

static int gen_mdct_exptab(AVTXContext *s, int len4, double scale)
{
    const double theta = (scale < 0 ? len4 : 0) + 1.0/8.0;

    if (!(s->exptab = av_malloc_array(len4, sizeof(*s->exptab))))
        return AVERROR(ENOMEM);

    scale = sqrt(fabs(scale));
    for (int i = 0; i < len4; i++) {
        const double alpha = M_PI_2 * (i + theta) / len4;
        s->exptab[i].re = RESCALE(cos(alpha) * scale);
        s->exptab[i].im = RESCALE(sin(alpha) * scale);
    }

    return 0;
}

int TX_NAME(ff_tx_init_mdct_fft)(AVTXContext *s, av_tx_fn *tx,
                                 enum AVTXType type, int inv, int len,
                                 const void *scale, uint64_t flags)
{
    const int is_mdct = ff_tx_type_is_mdct(type);
    int err, l, n = 1, m = 1, max_ptwo = 1 << (FF_ARRAY_ELEMS(fft_dispatch) - 1);

    if (is_mdct)
        len >>= 1;

    l = len;

#define CHECK_FACTOR(DST, FACTOR, SRC)                                         \
    if (DST == 1 && !(SRC % FACTOR)) {                                         \
        DST = FACTOR;                                                          \
        SRC /= FACTOR;                                                         \
    }
    CHECK_FACTOR(n, 15, len)
    CHECK_FACTOR(n,  9, len)
    CHECK_FACTOR(n,  7, len)
    CHECK_FACTOR(n,  5, len)
    CHECK_FACTOR(n,  3, len)
#undef CHECK_FACTOR

    /* len must be a power of two now */
    if (!(len & (len - 1)) && len >= 2 && len <= max_ptwo) {
        m = len;
        len = 1;
    }

    s->n = n;
    s->m = m;
    s->inv = inv;
    s->type = type;
    s->flags = flags;

    /* If we weren't able to split the length into factors we can handle,
     * resort to using the naive and slow FT. This also filters out
     * direct 3, 5 and 15 transforms as they're too niche. */
    if (len > 1 || m == 1) {
        if (is_mdct && (l & 1)) /* Odd (i)MDCTs are not supported yet */
            return AVERROR(ENOSYS);
        if (flags & AV_TX_INPLACE) /* Neither are in-place naive transforms */
            return AVERROR(ENOSYS);
        s->n = l;
        s->m = 1;
        *tx = naive_fft;
        if (is_mdct) {
            s->scale = *((SCALE_TYPE *)scale);
            *tx = inv ? naive_imdct : naive_mdct;
            if (inv && (flags & AV_TX_FULL_IMDCT)) {
                s->top_tx = *tx;
                *tx = full_imdct_wrapper_fn;
            }
        }
        return 0;
    }

    if (n > 1 && m > 1) { /* 2D transform case */
        if ((err = ff_tx_gen_compound_mapping(s)))
            return err;
        if (!(s->tmp = av_malloc(n*m*sizeof(*s->tmp))))
            return AVERROR(ENOMEM);
        if (!(m & (m - 1))) {
            *tx = n == 3 ? compound_fft_3xM :
                  n == 5 ? compound_fft_5xM :
                  n == 7 ? compound_fft_7xM :
                  n == 9 ? compound_fft_9xM :
                           compound_fft_15xM;
            if (is_mdct)
                *tx = n == 3 ? inv ? compound_imdct_3xM  : compound_mdct_3xM :
                      n == 5 ? inv ? compound_imdct_5xM  : compound_mdct_5xM :
                      n == 7 ? inv ? compound_imdct_7xM  : compound_mdct_7xM :
                      n == 9 ? inv ? compound_imdct_9xM  : compound_mdct_9xM :
                               inv ? compound_imdct_15xM : compound_mdct_15xM;
        }
    } else { /* Direct transform case */
        *tx = split_radix_fft;
        if (is_mdct)
            *tx = inv ? monolithic_imdct : monolithic_mdct;
    }

    if (n == 3 || n == 5 || n == 15)
        init_cos_tabs(0);
    else if (n == 7)
        init_cos_tabs(1);
    else if (n == 9)
        init_cos_tabs(2);

    if (m != 1 && !(m & (m - 1))) {
        if ((err = ff_tx_gen_ptwo_revtab(s, n == 1 && !is_mdct && !(flags & AV_TX_INPLACE))))
            return err;
        if (flags & AV_TX_INPLACE) {
            if (is_mdct) /* In-place MDCTs are not supported yet */
                return AVERROR(ENOSYS);
            if ((err = ff_tx_gen_ptwo_inplace_revtab_idx(s, s->revtab_c)))
                return err;
        }
        for (int i = 4; i <= av_log2(m); i++)
            init_cos_tabs(i);
    }

    if (is_mdct) {
        if (inv && (flags & AV_TX_FULL_IMDCT)) {
            s->top_tx = *tx;
            *tx = full_imdct_wrapper_fn;
        }
        return gen_mdct_exptab(s, n*m, *((SCALE_TYPE *)scale));
    }

    return 0;
}
