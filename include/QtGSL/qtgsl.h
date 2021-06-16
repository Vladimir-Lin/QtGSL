/****************************************************************************
 *                                                                          *
 * Copyright (C) 2005 ~ 2015 Neutrino International Inc.                    *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 * QtGSL acts as an interface between Qt and GNU GSL library.               *
 * Please keep QtGSL as simple as possible.                                 *
 *                                                                          *
 * Qt Version   : 5.4.1                                                     *
 * CIOS Version : 1.6.0                                                     *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_GSL_H
#define QT_GSL_H

#include <QtCore>
#include <Essentials>

extern "C" {
#include <gsl/gsl_types.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_inline.h>
#include <gsl/gsl_const.h>
#include <gsl/gsl_const_cgs.h>
#include <gsl/gsl_const_cgsm.h>
#include <gsl/gsl_const_mks.h>
#include <gsl/gsl_const_mksa.h>
#include <gsl/gsl_const_num.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_qrng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_sum.h>
#include <gsl/gsl_poly.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permute.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_combination.h>
#include <gsl/gsl_multiset.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_sort.h>
#include <gsl/gsl_sort_vector.h>
#include <gsl/gsl_heapsort.h>
#include <gsl/gsl_dht.h>
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_histogram2d.h>
#include <gsl/gsl_fit.h>
#include <gsl/gsl_multifit.h>
#include <gsl/gsl_deriv.h>
#include <gsl/gsl_chebyshev.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_bspline.h>
#include <gsl/gsl_complex_math.h>
}

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QTGSL_LIB)
#    define Q_GSL_EXPORT Q_DECL_EXPORT
#  else
#    define Q_GSL_EXPORT Q_DECL_IMPORT
#  endif
#else
#    define Q_GSL_EXPORT
#endif

class Q_GSL_EXPORT vcomplex
{ // GSL complex number
  public:

    double x ;
    double y ;

    explicit vcomplex      (void) ;
    explicit vcomplex      (double x,double y) ;
             vcomplex      (const vcomplex & complex) ;
    virtual ~vcomplex      (void) ;

    double real            (void) ;
    double imaginary       (void) ;
    double argument        (void) ;
    double magnitude       (void) ; // abs ,  |z|
    double squared         (void) ; // squared magnitude ,  |z|^2
    double logabs          (void) ; // log|z|

    vcomplex & operator  = (vcomplex & complex) ;
    vcomplex & operator += (vcomplex & complex) ;
    vcomplex & operator -= (vcomplex & complex) ;
    vcomplex & operator *= (vcomplex & complex) ;
    vcomplex & operator /= (vcomplex & complex) ;

    vcomplex & rectangular (double x,double y) ; // equal to operator =
    vcomplex & polar       (double r,double theta) ;
    vcomplex & conjugate   (void) ; // z^* = x - i y
    vcomplex & inverse     (void) ; // 1/z = (x - i y)/(x^2 + y^2)
    vcomplex & negative    (void) ; // -z = (-x) + i(-y)

    void sin               (vcomplex & value) ;
    void cos               (vcomplex & value) ;
    void tan               (vcomplex & value) ;
    void sec               (vcomplex & value) ;
    void csc               (vcomplex & value) ;
    void cot               (vcomplex & value) ;

    void arcsin            (vcomplex & value) ;
    void arccos            (vcomplex & value) ;
    void arctan            (vcomplex & value) ;
    void arcsec            (vcomplex & value) ;
    void arccsc            (vcomplex & value) ;
    void arccot            (vcomplex & value) ;

    void sinh              (vcomplex & value) ;
    void cosh              (vcomplex & value) ;
    void tanh              (vcomplex & value) ;
    void sech              (vcomplex & value) ;
    void csch              (vcomplex & value) ;
    void coth              (vcomplex & value) ;

    void arcsinh           (vcomplex & value) ;
    void arccosh           (vcomplex & value) ;
    void arctanh           (vcomplex & value) ;
    void arcsech           (vcomplex & value) ;
    void arccsch           (vcomplex & value) ;
    void arccoth           (vcomplex & value) ;

  protected:

  private:

};

typedef QList < vcomplex > vcomplexes ;


namespace N
{

class Q_GSL_EXPORT Random         ;
class Q_GSL_EXPORT Histogram      ;
class Q_GSL_EXPORT Chebyshev      ;
class Q_GSL_EXPORT Permutation    ;
class Q_GSL_EXPORT Combination    ;
class Q_GSL_EXPORT Multisets      ;
class Q_GSL_EXPORT MultiFit       ;
class Q_GSL_EXPORT BSplines       ;
class Q_GSL_EXPORT Interpolation  ;
class Q_GSL_EXPORT Vector         ;
class Q_GSL_EXPORT Matrix         ;
class Q_GSL_EXPORT LevinWithError ;
class Q_GSL_EXPORT Levin          ;

namespace Math
{

Q_GSL_EXPORT QList<int>       Differential                  (QList<int>       & discrete);
Q_GSL_EXPORT QList<long long> Differential                  (QList<long long> & discrete);
Q_GSL_EXPORT QList<float>     Differential                  (QList<float>     & discrete);
Q_GSL_EXPORT QList<double>    Differential                  (QList<double>    & discrete);
Q_GSL_EXPORT QList<double>    VectorMultiply                (QList<double>    & discrete,double v);
Q_GSL_EXPORT double           SquareSigma                   (QList<double>    & discrete);
Q_GSL_EXPORT double           VectorMin                     (QList<double>    & discrete);
Q_GSL_EXPORT double           VectorMax                     (QList<double>    & discrete);
Q_GSL_EXPORT QByteArray       VectorByteArray               (QList<double>    & discrete);
Q_GSL_EXPORT QList<double>    VectorFromByteArray           (QByteArray       & B);
Q_GSL_EXPORT double           Average                       (int total,double * values) ;
Q_GSL_EXPORT int              AddValues                     (int total,double * values,double value) ;
Q_GSL_EXPORT int              Multiply                      (int total,double * values,double value) ;
Q_GSL_EXPORT int              FaPb                          (int total,double * values,double a,double b) ; // F = a * ( x[i] + b )
Q_GSL_EXPORT int              FaXb                          (int total,double * values,double a,double b) ; // F = a * x[i] + b
Q_GSL_EXPORT int              Divide                        (int total,double * values,double value) ;
Q_GSL_EXPORT void             CutOff                        (int total,double * values,double minimum,double maximum) ;

Q_GSL_EXPORT int              toByteArray                   (const vcomplexes & complexes,QByteArray & body) ;
Q_GSL_EXPORT int              toComplexes                   (const QByteArray & body,vcomplexes & complexes) ;
Q_GSL_EXPORT int              toDouble                      (int items,char           * CHARS  ,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,unsigned char  * UCHARS ,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,short          * SHORTS ,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,unsigned short * USHORTS,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,int            * INTS   ,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,unsigned int   * UINTS  ,double * DOUBLEs) ;
Q_GSL_EXPORT int              toDouble                      (int items,float          * FLOATS ,double * DOUBLEs) ;
Q_GSL_EXPORT int              Addition                      (int items,double * A,double * B           ) ; // A += B
Q_GSL_EXPORT int              Addition                      (int items,double * A,double * B,double * C) ; // A  = B + C
Q_GSL_EXPORT int              Subtract                      (int items,double * A,double * B           ) ; // A -= B
Q_GSL_EXPORT int              Subtract                      (int items,double * A,double * B,double * C) ; // A  = B - C
Q_GSL_EXPORT int              Multiply                      (int items,double * A,double * B           ) ; // A *= B
Q_GSL_EXPORT int              Multiply                      (int items,double * A,double * B,double * C) ; // A  = B * C
Q_GSL_EXPORT int              Divide                        (int items,double * A,double * B           ) ; // A /= B
Q_GSL_EXPORT int              Divide                        (int items,double * A,double * B,double * C) ; // A  = B / C

Q_GSL_EXPORT void             Sort                          (double * data,const size_t stride,size_t n) ;
Q_GSL_EXPORT void             Sort                          (float  * data,const size_t stride,size_t n) ;
Q_GSL_EXPORT void             Sort                          (int    * data,const size_t stride,size_t n) ;
Q_GSL_EXPORT void             SortIndex                     (size_t * p,const double * data,size_t stride,size_t n) ;
Q_GSL_EXPORT void             SortIndex                     (size_t * p,const float  * data,size_t stride,size_t n) ;
Q_GSL_EXPORT void             SortIndex                     (size_t * p,const int    * data,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallest                  (double * dest,size_t k,const double * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallest                  (float  * dest,size_t k,const float  * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallest                  (int    * dest,size_t k,const int    * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargest                   (double * dest,size_t k,const double * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargest                   (float  * dest,size_t k,const float  * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargest                   (int    * dest,size_t k,const int    * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallestIndex             (size_t * p,size_t k,const double * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallestIndex             (size_t * p,size_t k,const float  * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortSmallestIndex             (size_t * p,size_t k,const int    * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargestIndex              (size_t * p,size_t k,const double * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargestIndex              (size_t * p,size_t k,const float  * src,size_t stride,size_t n) ;
Q_GSL_EXPORT int              SortLargestIndex              (size_t * p,size_t k,const int    * src,size_t stride,size_t n) ;

Q_GSL_EXPORT double           Mean                          (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           Variance                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           VarianceMean                  (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           StandardDeviation             (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           StandardDeviationMean         (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           TotalSumSquares               (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           TotalSumSquaresMean           (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           VarianceFixedMean             (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           StandardDeviationFixedMean    (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           AbsoluteDeviation             (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           AbsoluteDeviationMean         (const double data [],size_t stride,size_t n,double mean) ;
Q_GSL_EXPORT double           Skew                          (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           SkewMeanSD                    (const double data [],size_t stride,size_t n,double mean,double sd) ;
Q_GSL_EXPORT double           Kurtosis                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           KurtosisMeanSD                (const double data [],size_t stride,size_t n,double mean,double sd) ;
Q_GSL_EXPORT double           Lag1AutoCorrelation           (const double data [],const size_t stride,const size_t n);
Q_GSL_EXPORT double           Lag1AutoCorrelationMean       (const double data [],const size_t stride,const size_t n,const double mean) ;
Q_GSL_EXPORT double           Covariance                    (const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n) ;
Q_GSL_EXPORT double           CovarianceMean                (const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n,const double mean1,const double mean2) ;
Q_GSL_EXPORT double           Correlation                   (const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n) ;
Q_GSL_EXPORT double           WeightedMean                  (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedVariance              (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedVarianceMean          (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,double wmean) ;
Q_GSL_EXPORT double           WeightedSd                    (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedSdMean                (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,double wmean) ;
Q_GSL_EXPORT double           WeightedVarianceFixedMean     (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,const double mean) ;
Q_GSL_EXPORT double           WeightedSdFixedMean           (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,const double mean) ;
Q_GSL_EXPORT double           WeightedTss                   (const double w    [],const size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedTssMean               (const double w    [],const size_t wstride,const double data[],size_t stride,size_t n,double wmean) ;
Q_GSL_EXPORT double           WeightedAbsoluteDeviation     (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedAbsoluteDeviationMean (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,double wmean) ;
Q_GSL_EXPORT double           WeightedSkew                  (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedSkewMeanSd            (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,double wmean,double wsd) ;
Q_GSL_EXPORT double           WeightedKurtosis              (const double w    [],size_t wstride,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           WeightedKurtosisMeanSd        (const double w    [],size_t wstride,const double data[],size_t stride,size_t n,double wmean,double wsd) ;
Q_GSL_EXPORT double           MaxValue                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           MinValue                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT size_t           MaxIndex                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT size_t           MinIndex                      (const double data [],size_t stride,size_t n) ;
Q_GSL_EXPORT double           MedianFromSorted              (const double sorted_data[],size_t stride,size_t n) ;
Q_GSL_EXPORT double           QuantileFromSorted            (const double sorted_data[],size_t stride,size_t n,double f) ;
Q_GSL_EXPORT void             MinMax                        (double * min,double * max,const double data[],size_t stride,size_t n) ;
Q_GSL_EXPORT void             MinMaxIndex                   (size_t * min_index,size_t * max_index,const double data[],size_t stride,size_t n) ;

Q_GSL_EXPORT int              FitLinear                     (const double * x,const size_t xstride,const double * y,const size_t ystride,size_t n,double * c0,double * c1,double * cov00,double * cov01,double * cov11,double * sumsq) ;
Q_GSL_EXPORT int              FitMul                        (const double * x,const size_t xstride,const double * y,const size_t ystride,size_t n,double * c1,double * cov11,double * sumsq) ;
Q_GSL_EXPORT int              WeightedFitLinear             (const double * x,const size_t xstride,const double * w,const size_t wstride,const double * y,const size_t ystride,size_t n,double * c0,double * c1,double * cov00,double * cov01,double * cov11,double * chisq) ;
Q_GSL_EXPORT int              WeightedFitMul                (const double * x,const size_t xstride,const double * w,const size_t wstride,const double * y,const size_t ystride,size_t n,double * c1,double * cov11,double * sumsq) ;
Q_GSL_EXPORT int              FitLinearest                  (double x,double c0,double c1,double cov00,double cov01,double cov11,double * y,double * y_err) ;
Q_GSL_EXPORT int              FitMulest                     (double x,double c1,double cov11,double * y,double * y_err) ;

Q_GSL_EXPORT int              DerivativeCentral             (double x,double h,double * result,double * abserr,MathFunction function,void * params) ;
Q_GSL_EXPORT int              DerivativeForward             (double x,double h,double * result,double * abserr,MathFunction function,void * params) ;
Q_GSL_EXPORT int              DerivativeBackward            (double x,double h,double * result,double * abserr,MathFunction function,void * params) ;

Q_GSL_EXPORT void             IntegerMiddleArray            (int items,unsigned char * array,int gaps,void * funcdata) ;

}

namespace Polynomial
{

Q_GSL_EXPORT double   Eval        (const double c[]    ,const int len,const double   x) ;
Q_GSL_EXPORT vcomplex Eval        (const double c[]    ,const int len,const vcomplex z) ;
Q_GSL_EXPORT vcomplex Eval        (const vcomplexes & c,const int len,const vcomplex z) ;
Q_GSL_EXPORT int      Derivatives (const double c[],const size_t lenc,const double x,double res[],const size_t lenres) ;
Q_GSL_EXPORT int      ddInit      (double dd[],const double xa[],const double ya[],size_t size) ;
Q_GSL_EXPORT double   ddEval      (const double dd[],const double xa[],const size_t size,const double x) ;
Q_GSL_EXPORT int      ddTaylor    (double c[],double xp,const double dd[],const double xa[],size_t size,double w[]) ;
Q_GSL_EXPORT int      Quadratic   (double a,double b,double c,double * x0,double * x1) ;
Q_GSL_EXPORT int      Quadratic   (double a,double b,double c,vcomplex & z0,vcomplex & z1) ;
Q_GSL_EXPORT int      Cubic       (double a,double b,double c,double * x0,double * x1,double * x2) ;
Q_GSL_EXPORT int      Cubic       (double a,double b,double c,vcomplex & z0,vcomplex & z1,vcomplex & z2) ;

}

namespace Cpp
{

Q_GSL_EXPORT int SizeOf (Cpp::ValueTypes type) ;

}

/*****************************************************************************
 *                                                                           *
 *                                  Statistics                               *
 *                                                                           *
 *****************************************************************************/

class Q_GSL_EXPORT Random
{
  public:

    gsl_rng_type  * Type      ;
    gsl_rng       * Generator ;
    gsl_qrng_type * qType     ;
    gsl_qrng      * Quasi     ;

    explicit Random (unsigned long int seed = 0) ;
    explicit Random (gsl_rng_type  * type,unsigned long int seed = 0 ) ;
    explicit Random (gsl_qrng_type * type,unsigned int      dimension) ;
    virtual ~Random (void) ;

    static const gsl_rng_type ** All        (void) ;
    QString                      Name       (void) ;
    unsigned long int            Max        (void) ;
    unsigned long int            Min        (void) ;
    bool                         State      (QByteArray & state) ;

    bool                         Create     (gsl_rng_type * type,unsigned long int seed = 0 ) ;
    unsigned long int            Get        (void) ; // [min,max]
    unsigned long int            Get        (unsigned long int n) ; // [0,n-1]
    double                       Uniform    (void) ; // [0,1)
    double                       Positive   (void) ; // (0,1)

    bool                         Create     (gsl_qrng_type * type,unsigned int dimension) ;
    int                          QuasiGet   (double x[]) ;
    QString                      QuasiName  (void) ;
    bool                         QuasiState (QByteArray & state) ;
    void                         QuasiReset (void) ;

    Random &                     operator = (Random & source) ;

    double       Gaussian                   (double sigma) ;
    double       GaussianPDF                (double x,double sigma) ;
    double       GaussianZiggurat           (double sigma) ;
    double       GaussianRatioMethod        (double sigma) ;
    double       UnitGaussian               (void) ;
    double       UnitGaussianPDF            (double x) ;
    double       UnitGaussianRatioMethod    (void) ;
    double       CdfGaussianP               (double x,double sigma) ;
    double       CdfGaussianQ               (double x,double sigma) ;
    double       CdfGaussianPinv            (double P,double sigma) ;
    double       CdfGaussianQinv            (double Q,double sigma) ;
    double       CdfUnitGaussianP           (double x) ;
    double       CdfUnitGaussianQ           (double x) ;
    double       CdfUnitGaussianPinv        (double P) ;
    double       CdfUnitGaussianQinv        (double Q) ;
    double       GaussianTail               (double a,double sigma) ;
    double       GaussianTailPDF            (double x,double a,double sigma) ;
    double       UnitGaussianTail           (double a) ;
    double       UnitGaussianTailPDF        (double x, double a) ;
    bool         BivariateGaussian          (double   sigma_x ,
                                             double   sigma_y ,
                                             double   rho     ,
                                             double & x       ,
                                             double & y     ) ;
    double       BivariateGaussianPDF          (double x         ,
                                             double y         ,
                                             double sigma_x   ,
                                             double sigma_y   ,
                                             double rho     ) ;
    double       Exponential                (double mu) ;
    double       ExponentialPDF             (double x,double mu) ;
    double       CdfExponentialP            (double x,double mu) ;
    double       CdfExponentialQ            (double x,double mu) ;
    double       CdfExponentialPinv         (double P,double mu) ;
    double       CdfExponentialQinv         (double Q,double mu) ;
    double       Laplace                    (double a) ;
    double       LaplacePDF                 (double x,double a) ;
    double       CdfLaplaceP                (double x,double a) ;
    double       CdfLaplaceQ                (double x,double a) ;
    double       CdfLaplacePinv             (double P,double a) ;
    double       CdfLaplaceQinv             (double Q,double a) ;
    double       ExpPow                     (double a,double b) ;
    double       ExpPowPDF                  (double x,double a,double b) ;
    double       CdfExpPowP                 (double x,double a,double b) ;
    double       CdfExpPowQ                 (double x,double a,double b) ;
    double       Cauchy                     (double a) ;
    double       CauchyPDF                  (double x,double a) ;
    double       CdfCauchyP                 (double x,double a) ;
    double       CdfCauchyQ                 (double x,double a) ;
    double       CdfCauchyPinv              (double P,double a) ;
    double       CdfCauchyQinv              (double Q,double a) ;
    double       Rayleigh                   (double sigma) ;
    double       RayleighPDF                (double x,double sigma) ;
    double       CdfRayleighP               (double x,double sigma) ;
    double       CdfRayleighQ               (double x,double sigma) ;
    double       CdfRayleighPinv            (double P,double sigma) ;
    double       CdfRayleighQinv            (double Q,double sigma) ;
    double       RayleighTail               (double a,double sigma) ;
    double       RayleighTailPDF            (double x,double a, double sigma) ;
    double       Landau                     (void) ;
    double       LandauPDF                  (double x) ;
    double       Levy                       (double c,double alpha) ;
    double       LevySkew                   (double c,double alpha,double beta) ;
    double       Gamma                      (double a,double b) ;
    double       GammaKnuth                 (double a,double b) ;
    double       GammaKnuthPDF              (double x,double a,double b) ;
    double       CdfGammaP                  (double x,double a,double b) ;
    double       CdfGammaQ                  (double x,double a,double b) ;
    double       CdfGammaPinv               (double P,double a,double b) ;
    double       CdfGammaQinv               (double Q,double a,double b) ;
    double       Flat                       (double a,double b) ;
    double       FlatPDF                    (double x,double a,double b) ;
    double       CdfFlatP                   (double x,double a,double b) ;
    double       CdfFlatQ                   (double x,double a,double b) ;
    double       CdfFlatPinv                (double P,double a,double b) ;
    double       CdfFlatQinv                (double Q,double a,double b) ;
    double       LogNormal                  (double zeta,double sigma) ;
    double       LogNormalPDF               (double x,double zeta,double sigma) ;
    double       CdfLogNormalP              (double x,double zeta,double sigma) ;
    double       CdfLogNormalQ              (double x,double zeta,double sigma) ;
    double       CdfLogNormalPinv           (double P,double zeta,double sigma) ;
    double       CdfLogNormalQinv           (double Q,double zeta,double sigma) ;
    double       ChiSquared                 (double nu) ;
    double       ChiSquaredPDF              (double x,double nu) ;
    double       CdfChiSquaredP             (double x,double nu) ;
    double       CdfChiSquaredQ             (double x,double nu) ;
    double       CdfChiSquaredPinv          (double P,double nu) ;
    double       CdfChiSquaredQinv          (double Q,double nu) ;
    double       Fdist                      (double a,double b) ;
    double       FdistPDF                   (double x,double a,double b) ;
    double       CdfFdistP                  (double x,double a,double b) ;
    double       CdfFdistQ                  (double x,double a,double b) ;
    double       CdfFdistPinv               (double P,double a,double b) ;
    double       CdfFdistQinv               (double Q,double a,double b) ;
    double       Tdist                      (double a) ;
    double       TdistPDF                   (double x,double a) ;
    double       CdfTdistP                  (double x,double a) ;
    double       CdfTdistQ                  (double x,double a) ;
    double       CdfTdistPinv               (double P,double a) ;
    double       CdfTdistQinv               (double Q,double a) ;
    double       Beta                       (double a,double b) ;
    double       BetaPDF                    (double x,double a,double b) ;
    double       CdfBetaP                   (double x,double a,double b) ;
    double       CdfBetaQ                   (double x,double a,double b) ;
    double       CdfBetaPinv                (double P,double a,double b) ;
    double       CdfBetaQinv                (double Q,double a,double b) ;
    double       Logistic                   (double a) ;
    double       LogisticPDF                (double x,double a) ;
    double       CdfLogisticP               (double x,double a) ;
    double       CdfLogisticQ               (double x,double a) ;
    double       CdfLogisticPinv            (double P,double a) ;
    double       CdfLogisticQinv            (double Q,double a) ;
    double       Pareto                     (double a,double b) ;
    double       ParetoPDF                  (double x,double a,double b) ;
    double       CdfParetoP                 (double x,double a,double b) ;
    double       CdfParetoQ                 (double x,double a,double b) ;
    double       CdfParetoPinv              (double P,double a,double b) ;
    double       CdfParetoQinv              (double Q,double a,double b) ;
    double       Weibull                    (double a,double b) ;
    double       WeibullPDF                 (double x,double a,double b) ;
    double       CdfWeibullP                (double x,double a,double b) ;
    double       CdfWeibullQ                (double x,double a,double b) ;
    double       CdfWeibullPinv             (double P,double a,double b) ;
    double       CdfWeibullQinv             (double Q,double a,double b) ;
    double       Gumbell                    (double a,double b) ;
    double       GumbellPDF                 (double x,double a,double b) ;
    double       CdfGumbellP                (double x,double a,double b) ;
    double       CdfGumbellQ                (double x,double a,double b) ;
    double       CdfGumbellPinv             (double P,double a,double b) ;
    double       CdfGumbellQinv             (double Q,double a,double b) ;
    double       Gumbell2                   (double a,double b) ;
    double       Gumbell2PDF                (double x,double a,double b) ;
    double       CdfGumbell2P               (double x,double a,double b) ;
    double       CdfGumbell2Q               (double x,double a,double b) ;
    double       CdfGumbell2Pinv            (double P,double a,double b) ;
    double       CdfGumbell2Qinv            (double Q,double a,double b) ;
    unsigned int Poisson                    (double mu) ;
    double       PoissonPDF                 (unsigned int k,double mu) ;
    double       CdfPoissonP                (unsigned int k,double mu) ;
    double       CdfPoissonQ                (unsigned int k,double mu) ;
    unsigned int Bernoulli                  (double p) ;
    double       BernoulliPDF               (unsigned int k,double p) ;
    unsigned int Binomial                   (double p,unsigned int n) ;
    double       BinomialPDF                (unsigned int k,double p,unsigned int n) ;
    double       CdfBinomialP               (unsigned int k,double p,unsigned int n) ;
    double       CdfBinomialQ               (unsigned int k,double p,unsigned int n) ;
    void         Multinomial                (size_t       K     ,
                                             unsigned int N     ,
                                             const double p[]   ,
                                             unsigned int n[] ) ;
    double       MultinomialPDF             (size_t             K     ,
                                             const double       p[]   ,
                                             const unsigned int n[] ) ;
    double       MultinomialLnPDF           (size_t             K     ,
                                             const double       p[]   ,
                                             const unsigned int n[] ) ;
    unsigned int NegativeBinomial           (double p,double n) ;
    double       NegativeBinomialPDF        (unsigned int k,double p,double n) ;
    double       CdfNegativeBinomialP       (unsigned int k,double p,double n) ;
    double       CdfNegativeBinomialQ       (unsigned int k,double p,double n) ;
    unsigned int Pascal                     (double p,unsigned int n) ;
    double       PascalPDF                  (unsigned int k,double p,unsigned int n) ;
    double       CdfPascalP                 (unsigned int k,double p,unsigned int n) ;
    double       CdfPascalQ                 (unsigned int k,double p,unsigned int n) ;
    unsigned int Geometric                  (double p) ;
    double       GeometricPDF               (unsigned int k,double p) ;
    double       CdfGeometricP              (unsigned int k,double p) ;
    double       CdfGeometricQ              (unsigned int k,double p) ;
    unsigned int Hypergeometric             (unsigned int n1          ,
                                             unsigned int n2          ,
                                             unsigned int t         ) ;
    double       HypergeometricPDF          (unsigned int k           ,
                                             unsigned int n1          ,
                                             unsigned int n2          ,
                                             unsigned int t         ) ;
    double       CdfHypergeometricP         (unsigned int k           ,
                                             unsigned int n1          ,
                                             unsigned int n2          ,
                                             unsigned int t         ) ;
    double       CdfHypergeometricQ         (unsigned int k           ,
                                             unsigned int n1          ,
                                             unsigned int n2          ,
                                             unsigned int t         ) ;
    unsigned int Logarithmic                (double p) ;
    double       LogarithmicPDF             (unsigned int k, double p) ;
    void         Dirichlet                  (int K,const double alpha[],double theta[]) ;
    double       DirichletPDF               (int K,const double alpha[],const double theta[]) ;
    double       DirichletLnPDF             (int K,const double alpha[],const double theta[]) ;
    void         SphericalDir2D             (double & x,double & y) ;
    void         SphericalDir2DTrigMethod   (double & x,double & y) ;
    void         SphericalDir3D             (double & x,double & y,double & z) ;
    void         SphericalDirN              (int n, double * x) ;
    gsl_ran_discrete_t * PrepareDiscrete    (int K,const double * P) ;
    size_t               Discrete           (const gsl_ran_discrete_t * g) ;
    double               DiscretePDF        (size_t k,const gsl_ran_discrete_t * g) ;
    void                 DiscreteFree       (gsl_ran_discrete_t * g) ;
    void         Shuffle                    (void * base,size_t n,size_t size) ;
    void         Choose                     (void * dest,size_t k,void * src,size_t n,size_t size) ;
    void         Sample                     (void * dest,size_t k,void * src,size_t n,size_t size) ;

};

class Q_GSL_EXPORT Histogram
{
  public:

    gsl_histogram       * histo      ;
    gsl_histogram_pdf   * histoPdf   ;
    gsl_histogram2d     * histo2d    ;
    gsl_histogram2d_pdf * histo2dPdf ;

    explicit Histogram        (void) ;
    explicit Histogram        (int n) ;
             Histogram        (const Histogram & histogram) ;
    virtual ~Histogram        (void) ;

    bool   allocate           (int n) ;
    int    setRanges          (const double range[],int size) ;
    int    uniformRanges      (double xmin, double xmax) ;
    int    increment          (double x) ;
    int    accumulate         (double x,double weight) ;
    double get                (int i) ;
    int    getRange           (int i,double * lower,double * upper) ;
    double Max                (void) ;
    double Min                (void) ;
    int    bins               (void) ;
    void   reset              (void) ;
    int    find               (double x,size_t * i) ;
    double maxValue           (void) ;
    double minValue           (void) ;
    double mean               (void) ;
    double sigma              (void) ;
    double sum                (void) ;
    int    maxBin             (void) ;
    int    minBin             (void) ;
    int    scale              (double scale) ;
    int    shift              (double offset) ;
    bool   equalBins          (Histogram & histogram) ;
    int    add                (Histogram & histogram) ;
    int    sub                (Histogram & histogram) ;
    int    mul                (Histogram & histogram) ;
    int    div                (Histogram & histogram) ;

    bool   allocatePdf        (int n) ;
    double sample             (double r) ;

    bool   allocate2d         (int nx,int ny) ;
    int    setRanges2d        (const double xrange[],int xsize,const double yrange[],int ysize) ;
    int    uniformRanges2d    (double xmin,double xmax,double ymin,double ymax) ;
    int    increment2d        (double x,double y) ;
    int    accumulate2d       (double x,double y,double weight) ;
    double get2d              (int i,int j) ;
    int    getXrange2d        (int i,double * xlower,double * xupper) ;
    int    getYrange2d        (int j,double * ylower,double * yupper) ;
    double xmax2d             (void) ;
    double xmin2d             (void) ;
    int    nx2d               (void) ;
    int    ny2d               (void) ;
    double ymax2d             (void) ;
    double ymin2d             (void) ;
    void   reset2d            (void) ;
    int    find2d             (double x,double y,size_t * i,size_t * j) ;
    double maxValue2d         (void) ;
    double minValue2d         (void) ;
    void   maxBin2d           (size_t * i,size_t * j) ;
    void   minBin2d           (size_t * i,size_t * j) ;
    double xmean2d            (void) ;
    double ymean2d            (void) ;
    double xsigma2d           (void) ;
    double ysigma2d           (void) ;
    double cov2d              (void) ;
    double sum2d              (void) ;
    int    scale2d            (double scale) ;
    int    shift2d            (double offset);
    bool   equalBins2d        (Histogram & histogram) ;
    int    add2d              (Histogram & histogram) ;
    int    sub2d              (Histogram & histogram) ;
    int    mul2d              (Histogram & histogram) ;
    int    div2d              (Histogram & histogram) ;

    bool   allocatePdf2d      (int nx,int ny) ;
    int    sample2d           (double r1,double r2,double * x,double * y) ;

  protected:

  private:

};

class Q_GSL_EXPORT Chebyshev
{
  public:

    gsl_cheb_series * chebyshev ;
    gsl_function    * function  ;

    explicit Chebyshev    (void) ;
    explicit Chebyshev    (int n) ;
             Chebyshev    (const Chebyshev & cheb) ;
    virtual ~Chebyshev    (void) ;

    bool     Allocate     (int n) ;
    int      Initialize   (const double   a         ,
                           const double   b         ,
                           MathFunction   equation  ,
                           void         * params  ) ;

    size_t   Order        (void) ;
    size_t   Size         (void) ;
    double * Coefficients (void) ;
    double   Eval         (double x) ;
    double   EvalN        (size_t         order    ,
                           double         x      ) ;
    int      EvalAbsErr   (const double   x        ,
                           double       * result   ,
                           double       * abserr ) ;
    int      EvalNAbserr  (const size_t   order    ,
                           const double   x        ,
                           double       * result   ,
                           double       * abserr ) ;

    int      Derivative   (Chebyshev & cheb) ;
    int      Integral     (Chebyshev & cheb) ;

  protected:

  private:

};

/*****************************************************************************
 *                                                                           *
 *                        Permutation and Combination                        *
 *                                                                           *
 *****************************************************************************/

class Q_GSL_EXPORT Permutation : public QByteArray
{
  public:

    explicit Permutation          (void) ;
    explicit Permutation          (int size) ;
    explicit Permutation          (QString m) ;
             Permutation          (const Permutation & permutation) ;
    virtual ~Permutation          (void) ;

    int           isValid         (void) ; // gsl_permutation_valid
    int           toCUIDs         (CUIDs & Cuids) ;
    QString       toString        (void) ;
    int           toByteArray     (QByteArray & blob) ;
    int           setElements     (int size) ;
    int           elements        (void) const ;
    size_t *      array           (void) const ;
    Permutation & operator =      (const Permutation & permutation) ;
    Permutation & assign          (const Permutation & permutation) ;
    Permutation & toIdentity      (void) ; // gsl_permutation_init
    Permutation & Reverse         (void) ; // gsl_permutation_reverse
    void          swap            (int a,int b) ; // gsl_permutation_swap
    void          setValue        (int index,int   value) ;
    void          setValue        (int index,char  value) ;
    void          setValue        (int index,QChar value) ;
    void          setValue        (QString m) ;
    int           operator []     (int index) ; // gsl_permutation_get
    int           next            (void) ; // gsl_permutation_next
    int           previous        (void) ; // gsl_permutation_prev
    int           inverse         (Permutation & inv) ; // gsl_permutation_inverse(inv,this)
    int           toCanonical     (Permutation & canonical); //gsl_permutation_linear_to_canonical(canonical,this)
    int           toLinear        (Permutation & linear); //gsl_permutation_canonical_to_linear(linear,this)
    int           inversions      (void) ; // gsl_permutation_inversions
    int           linearCycles    (void) ; // gsl_permutation_linear_cycles
    int           canonicalCycles (void) ; // gsl_permutation_canonical_cycles
    static int    permute         (const size_t * p,double * data,size_t stride,size_t n) ; // gsl_permute
    static int    inverse         (const size_t * p,double * data,size_t stride,size_t n) ; // gsl_permute_inverse

    // gsl_permute_vector
    // gsl_permute_vector_inverse
    // gsl_permutation_mul

  protected:

  private:

};

class Q_GSL_EXPORT Combination : public QByteArray
{
  public:

    explicit Combination      (void) ;
    explicit Combination      (int n,int k) ;
             Combination      (const Combination & combination) ;
    virtual ~Combination      (void) ;

    int           isValid     (void) ; // gsl_combination_valid
    int           toCUIDs     (CUIDs & Cuids) ;
    int           toByteArray (QByteArray & blob) ;
    int           setElements (int n,int k) ;
    int           setChosen   (int k) ;
    int           elements    (void) const ;
    int           chosen      (void) const ;
    size_t *      array       (void) const ;
    Combination & operator =  (const Combination & combination) ;
    Combination & assign      (const Combination & combination) ;
    Combination & toFirst     (void) ; // gsl_combination_init_first
    Combination & toLast      (void) ; // gsl_combination_init_last
    void          setValue    (int index,int   value) ;
    void          setValue    (int index,char  value) ;
    void          setValue    (int index,QChar value) ;
    int           operator [] (int index) ; // gsl_combination_get
    int           next        (void) ; // gsl_combination_next
    int           previous    (void) ; // gsl_combination_prev

  protected:

  private:

};

class Q_GSL_EXPORT Multisets : public QByteArray
{
  public:

    explicit Multisets      (void) ;
    explicit Multisets      (int n,int k) ;
             Multisets      (const Multisets & multisets) ;
    virtual ~Multisets      (void) ;

    int         isValid     (void) ; // gsl_combination_valid
    int         toCUIDs     (CUIDs & Cuids) ;
    int         toByteArray (QByteArray & blob) ;
    int         setElements (int n,int k) ;
    int         setChosen   (int k) ;
    int         elements    (void) const ;
    int         chosen      (void) const ;
    size_t    * array       (void) const ;
    Multisets & operator =  (const Multisets & multisets) ;
    Multisets & assign      (const Multisets & multisets) ;
    Multisets & toFirst     (void) ; // gsl_combination_init_first
    Multisets & toLast      (void) ; // gsl_combination_init_last
    void        setValue    (int index,int   value) ;
    void        setValue    (int index,char  value) ;
    void        setValue    (int index,QChar value) ;
    int         operator [] (int index) ; // gsl_combination_get
    int         next        (void) ; // gsl_combination_next
    int         previous    (void) ; // gsl_combination_prev

  protected:

  private:

};

/*****************************************************************************
 *                                                                           *
 *                               Linear algebra                              *
 *                                                                           *
 *****************************************************************************/

class Q_GSL_EXPORT MultiFit
{
  public:

    gsl_multifit_linear_workspace * work ;

    explicit MultiFit      (void) ;
    explicit MultiFit      (int n,int p) ;
             MultiFit      (const MultiFit & fit) ;
    virtual ~MultiFit      (void) ;

    bool Allocate          (int n,int p) ;

    int Linear             (const gsl_matrix * X       ,
                            const gsl_vector * y       ,
                                  gsl_vector * c       ,
                                  gsl_matrix * cov     ,
                            double           * chisq ) ;
    int WeightedLinear     (const gsl_matrix * X       ,
                            const gsl_vector * w       ,
                            const gsl_vector * y       ,
                                  gsl_vector * c       ,
                                  gsl_matrix * cov     ,
                            double           * chisq ) ;
    int svdLinear          (const gsl_matrix * X     ) ;
    int svdWeightedLinear  (const gsl_matrix * X       ,
                            const gsl_vector * w       ,
                            const gsl_vector * y       ,
                            double             tol     ,
                            size_t           * rank    ,
                                  gsl_vector * c       ,
                                  gsl_matrix * cov     ,
                            double           * chisq ) ;
    int usvdWeightedLinear (const gsl_matrix * X       ,
                            const gsl_vector * w       ,
                            const gsl_vector * y       ,
                            double             tol     ,
                            size_t           * rank    ,
                                  gsl_vector * c       ,
                                  gsl_matrix * cov     ,
                            double           * chisq ) ;

    int Linearest          (const gsl_vector * x       ,
                            const gsl_vector * c       ,
                            const gsl_matrix * cov     ,
                            double           * y       ,
                            double           * y_err ) ;
    int Residuals          (const gsl_matrix * X       ,
                            const gsl_vector * y       ,
                            const gsl_vector * c       ,
                                  gsl_vector * r     ) ;

  protected:

  private:

};

class Q_GSL_EXPORT BSplines
{
  public:

    gsl_bspline_workspace * work ;

    explicit BSplines            (void) ;
    explicit BSplines            (int k,int nbreak) ;
             BSplines            (const BSplines & bsplines) ;
    virtual ~BSplines            (void) ;

    bool   Allocate              (int k,int nbreak) ;

    int    Knots                 (const gsl_vector * breakpts) ;
    int    uniformKnots          (const double a,const double b) ;
    int    Eval                  (const double x,gsl_vector * B) ;
    int    EvalNonZero           (const double   x       ,
                                  gsl_vector   * Bk      ,
                                  size_t       * istart  ,
                                  size_t       * iend  ) ;
    int    Coefficients          (void) ;
    double GrevilleAbscissa      (int i) ;

    int    DerivativeEval        (const double   x       ,
                                  const int      nderiv  ,
                                  gsl_matrix   * dB    ) ;
    int    DerivativeEvalNonZero (const double   x       ,
                                  const int      nderiv  ,
                                  gsl_matrix   * dB      ,
                                  size_t       * istart  ,
                                  size_t       * iend  ) ;

  protected:

  private:

};

class Q_GSL_EXPORT Interpolation
{
  public:

    gsl_interp       * work   ;
    gsl_interp_accel * accel  ;
    gsl_spline       * spline ;

    explicit Interpolation              (void) ;
    explicit Interpolation              (const gsl_interp_type * T,int size) ;
             Interpolation              (const Interpolation & interpolation) ;
    virtual ~Interpolation              (void) ;

    bool         Allocate               (const gsl_interp_type * T,int size) ;
    bool         AllocateAccel          (void) ;
    bool         AllocateSpline         (const gsl_interp_type * T,int size) ;

    int          Initialize             (const double xa[]   ,
                                         const double ya[]   ,
                                         int          size ) ;
    int          InitializeSpline       (const double xa[]   ,
                                         const double ya[]   ,
                                         int          size ) ;

    QString      Name                   (void) ;
    QString      SplineName             (void) ;
    unsigned int MinSize                (void) ;
    unsigned int MinSize                (const gsl_interp_type * T) ;
    unsigned int SplineMinSize          (void) ;

    int          BSearch                (const double x_array[]  ,
                                               double x          ,
                                               int    index_lo   ,
                                               int    index_hi ) ;
    int          Find                   (const double x_array[]  ,
                                               int    size       ,
                                               double x        ) ;
    int          Reset                  (void) ;

    double       Eval                   (const double   xa[]  ,
                                         const double   ya[]  ,
                                               double   x   ) ;
    int          EvalE                  (const double   xa[]  ,
                                         const double   ya[]  ,
                                               double   x     ,
                                               double * y   ) ;
    double       EvalDerivative         (const double xa[]    ,
                                         const double ya[]    ,
                                               double x     ) ;
    double       EvalDerivative2        (const double xa[]    ,
                                         const double ya[]    ,
                                               double x     ) ;
    double       EvalIntegral           (const double xa[]    ,
                                         const double ya[]    ,
                                               double a       ,
                                               double b     ) ;
    double       SplineEval             (double x) ;
    double       SplineEvalDerivative   (double x) ;
    double       SplineEvalDerivative2  (double x) ;
    double       SplineEvalIntegral     (double a,double b) ;
    int          EvalDerivativeE        (const double   xa[] ,
                                         const double   ya[] ,
                                               double   x    ,
                                               double * d  ) ;
    int          EvalDerivative2E       (const double   xa[] ,
                                         const double   ya[] ,
                                               double   x    ,
                                               double * d2 ) ;
    int          EvalIntegralE          (const double   xa[]     ,
                                         const double   ya[]     ,
                                               double   a        ,
                                               double   b        ,
                                               double * result ) ;
    int          SplineEvalE            (double x,double * y) ;
    int          SplineEvalDerivativeE  (double x,double * d) ;
    int          SplineEvalDerivative2E (double x,double * d2) ;
    int          SplineEvalIntegralE    (double a,double b,double * result) ;

  protected:

  private:

};

class Q_GSL_EXPORT Vector : public QByteArray
{
  public:

    explicit Vector              (void) ;
    explicit Vector              (Cpp::ValueTypes type,int items) ;
             Vector              (const Vector & vector) ;
    virtual ~Vector              (void) ;

    Cpp::ValueTypes Type         (void);
    int             BytesPerCell (void) ;

    Vector & operator =          (const Vector & vector) ;

    bool     subVector           (Vector & vector,int offset,int items) ; // get sub-vector
    bool     setVector           (int offset,Vector & vector) ;

    void     reset               (void);
    void     set                 (Cpp::ValueTypes type,int items) ;

    void *   array               (void);

    int      count               (void) ;
    void     setZero             (void) ;
    void     setAll              (double x) ;
    void     setBasis            (int index) ;
    bool     swap                (int i,int j) ;
    bool     reverse             (void) ;
    int      take                (int pos,int items) ;
    int      append              (int items,const char * source) ;
    int      append              (int items,int gap,const char * source) ;
    int      insert              (int pos,int items,const char * source) ;
    int      insert              (int pos,int items,int gap,const char * source) ;

    Vector & operator +=         (Vector & vector) ;
    Vector & operator -=         (Vector & vector) ;
    Vector & operator *=         (Vector & vector) ;
    Vector & operator /=         (Vector & vector) ;

    Vector & operator +=         (double x) ;
    Vector & operator -=         (double x) ;
    Vector & operator *=         (double x) ;

    QString  toCpp               (void) ;
    QString  toCpp               (QString variableName) ;

    // P(x) = c[0] + c[1] x + c[2] x^2 + ... + c[len-1] x^{len-1}
    double   polynomial          (double x) ;
    bool     polynomial          (vcomplex & x,vcomplex & result) ;
    int      derivatives         (double x,int length,double * results) ;

  protected:

  private:

};

class Q_GSL_EXPORT Matrix : public QByteArray
{
  public:

    explicit Matrix        (void);
    explicit Matrix        (Cpp::ValueTypes type,int rows,int columns) ;
             Matrix        (const Matrix & matrix) ;
    virtual ~Matrix        (void);

    Cpp::ValueTypes Type   (void);

    Matrix & operator  =   (const Matrix & matrix) ;

    Matrix & operator +=   (const Matrix & matrix) ;
    Matrix & operator +=   (int value) ;
    Matrix & operator +=   (double value) ;
    Matrix & operator -=   (const Matrix & matrix) ;
    Matrix & operator -=   (int value) ;
    Matrix & operator -=   (double value) ;
    Matrix & operator *=   (int value) ;
    Matrix & operator *=   (double value) ;
    Matrix & operator /=   (int value) ;
    Matrix & operator /=   (double value) ;

    void   reset           (void);
    void   assign          (const Matrix & matrix) ;
    void   set             (Cpp::ValueTypes type,int rows,int columns);
    void   zerofill        (void);

    int    Rows            (void);
    int    Columns         (void);
    int    at              (int row,int column) ;

    void * array           (void);

    bool   swapRows        (int i,int j) ;
    bool   swapColumns     (int i,int j) ;

    bool   transpose       (void) ;
    bool   transpose       (const Matrix & T) ;
    bool   inverse         (Matrix & T) ;

    static double sum      (double * v,int items) ;
    static void   dispatch (int shift,int column,int items,double * R,double * S) ;
    static double multiple (int length,double * a,double * b) ;
    static double multiple (int length,double * R,double * a,double * b) ;

    QString toCpp          (void) ;
    QString toCpp          (QString variableName) ;

    void    vertical       (double * R,double * V) ;

  protected:

  private:

};

/*****************************************************************************
 *                                                                           *
 *               Fourier, Wavelet, and other series transformation           *
 *                                                                           *
 *****************************************************************************/

class Q_GSL_EXPORT LevinWithError
{
  public:

    gsl_sum_levin_u_workspace * work ;

    explicit LevinWithError (void) ;
    explicit LevinWithError (int n) ;
             LevinWithError (const LevinWithError & levin) ;
    virtual ~LevinWithError (void) ;

    bool Allocate           (int n) ;
    int  Acceleration       (const double * array       ,
                             const size_t   n           ,
                             double       * sum_accel   ,
                             double       * abserr    ) ;
    int  MinMax             (const double * array       ,
                             const size_t   n           ,
                             const size_t   min_terms   ,
                             const size_t   max_terms   ,
                             double       * sum_accel   ,
                             double       * abserr    ) ;
    int  Step               (const double   term        ,
                             const size_t   n           ,
                             const size_t   nmax        ,
                             double       * sum_accel ) ;

  protected:

  private:

};

class Q_GSL_EXPORT Levin
{
  public:

    gsl_sum_levin_utrunc_workspace * work ;

    explicit Levin    (void) ;
    explicit Levin    (int n) ;
             Levin    (const Levin & levin) ;
    virtual ~Levin    (void) ;

    bool Allocate     (int n) ;
    int  Acceleration (const double * array          ,
                       const size_t   n              ,
                       double       * sum_accel      ,
                       double       * abserr_trunc ) ;
    int  MinMax       (const double * array          ,
                       const size_t   n              ,
                       const size_t   min_terms      ,
                       const size_t   max_terms      ,
                       double       * sum_accel      ,
                       double       * abserr_trunc ) ;
    int  Step         (const double   term           ,
                       const size_t   n              ,
                       double       * sum_accel    ) ;

  protected:

  private:

};

}

Q_DECLARE_METATYPE(vcomplex)
Q_DECLARE_METATYPE(vcomplexes)
Q_DECLARE_METATYPE(N::Random)
Q_DECLARE_METATYPE(N::Histogram)
Q_DECLARE_METATYPE(N::Chebyshev)
Q_DECLARE_METATYPE(N::Permutation)
Q_DECLARE_METATYPE(N::Combination)
Q_DECLARE_METATYPE(N::Multisets)
Q_DECLARE_METATYPE(N::MultiFit)
Q_DECLARE_METATYPE(N::BSplines)
Q_DECLARE_METATYPE(N::Interpolation)
Q_DECLARE_METATYPE(N::Vector)
Q_DECLARE_METATYPE(N::Matrix)
Q_DECLARE_METATYPE(N::LevinWithError)
Q_DECLARE_METATYPE(N::Levin)

QT_END_NAMESPACE

#endif
