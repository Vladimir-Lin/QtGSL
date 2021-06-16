#include "qtgsl.h"

int N::Math::FitLinear(const double * x,const size_t xstride,const double * y,const size_t ystride,size_t n,double * c0,double * c1,double * cov00,double * cov01,double * cov11,double * sumsq)
{
  return ::gsl_fit_linear(x,xstride,y,ystride,n,c0,c1,cov00,cov01,cov11,sumsq) ;
}

int N::Math::WeightedFitLinear(const double * x,const size_t xstride,const double * w,const size_t wstride,const double * y,const size_t ystride,size_t n,double * c0,double * c1,double * cov00,double * cov01,double * cov11,double * chisq)
{
  return ::gsl_fit_wlinear(x,xstride,w,wstride,y,ystride,n,c0,c1,cov00,cov01,cov11,chisq) ;
}

int N::Math::FitLinearest(double x,double c0,double c1,double cov00,double cov01,double cov11,double * y,double * y_err)
{
  return ::gsl_fit_linear_est(x,c0,c1,cov00,cov01,cov11,y,y_err) ;
}

int N::Math::FitMul(const double * x,const size_t xstride,const double * y,const size_t ystride,size_t n,double * c1,double * cov11,double * sumsq)
{
  return ::gsl_fit_mul(x,xstride,y,ystride,n,c1,cov11,sumsq) ;
}

int N::Math::WeightedFitMul(const double * x,const size_t xstride,const double * w,const size_t wstride,const double * y,const size_t ystride,size_t n,double * c1,double * cov11,double * sumsq)
{
  return ::gsl_fit_wmul(x,xstride,w,wstride,y,ystride,n,c1,cov11,sumsq) ;
}

int N::Math::FitMulest(double x,double c1,double cov11,double * y,double * y_err)
{
  return ::gsl_fit_mul_est(x,c1,cov11,y,y_err) ;
}
