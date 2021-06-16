#include "qtgsl.h"

double N::Polynomial::Eval(const double c[],const int len,const double x)
{
  return ::gsl_poly_eval(c,len,x) ;
}

vcomplex N::Polynomial::Eval(const double c[],const int len,const vcomplex z)
{
  gsl_complex Z                        ;
  gsl_complex R                        ;
  Z.dat[0] = z.x                       ;
  Z.dat[1] = z.y                       ;
  R = ::gsl_poly_complex_eval(c,len,Z) ;
  return vcomplex(R.dat[0],R.dat[1])   ;
}

vcomplex N::Polynomial::Eval(const vcomplexes & c,const int len,const vcomplex z)
{
  QByteArray Body ;
  gsl_complex Z                                ;
  gsl_complex R                                ;
  Z.dat[0] = z.x                               ;
  Z.dat[1] = z.y                               ;
  N::Math::toByteArray(c,Body)                 ;
  gsl_complex * C = (gsl_complex *)Body.data() ;
  R = ::gsl_complex_poly_complex_eval(C,len,Z) ;
  return vcomplex(R.dat[0],R.dat[1])           ;
}

int N::Polynomial::Derivatives(const double c[],const size_t lenc,const double x,double res[],const size_t lenres)
{
  return ::gsl_poly_eval_derivs(c,lenc,x,res,lenres) ;
}

int N::Polynomial::ddInit(double dd[],const double xa[],const double ya[],size_t size)
{
  return ::gsl_poly_dd_init(dd,xa,ya,size) ;
}

double N::Polynomial::ddEval(const double dd[],const double xa[],const size_t size,const double x)
{
  return ::gsl_poly_dd_eval(dd,xa,size,x) ;
}

int N::Polynomial::ddTaylor(double c[],double xp,const double dd[],const double xa[],size_t size,double w[])
{
  return ::gsl_poly_dd_taylor(c,xp,dd,xa,size,w) ;
}

int N::Polynomial::Quadratic(double a,double b,double c,double * x0,double * x1)
{
  return ::gsl_poly_solve_quadratic(a,b,c,x0,x1) ;
}

int N::Polynomial::Quadratic(double a,double b,double c,vcomplex & z0,vcomplex & z1)
{
  gsl_complex Z0                                        ;
  gsl_complex Z1                                        ;
  int         R                                         ;
  R = ::gsl_poly_complex_solve_quadratic(a,b,c,&Z0,&Z1) ;
  z0.x = Z0.dat[0]                                      ;
  z0.y = Z0.dat[1]                                      ;
  z1.x = Z1.dat[0]                                      ;
  z1.y = Z1.dat[1]                                      ;
  return R                                              ;
}

int N::Polynomial::Cubic(double a,double b,double c,double * x0,double * x1,double * x2)
{
  return ::gsl_poly_solve_cubic(a,b,c,x0,x1,x2) ;
}

int N::Polynomial::Cubic(double a,double b,double c,vcomplex & z0,vcomplex & z1,vcomplex & z2)
{
  gsl_complex Z0                                        ;
  gsl_complex Z1                                        ;
  gsl_complex Z2                                        ;
  int         R                                         ;
  R = ::gsl_poly_complex_solve_cubic(a,b,c,&Z0,&Z1,&Z2) ;
  z0.x = Z0.dat[0]                                      ;
  z0.y = Z0.dat[1]                                      ;
  z1.x = Z1.dat[0]                                      ;
  z1.y = Z1.dat[1]                                      ;
  z2.x = Z2.dat[0]                                      ;
  z2.y = Z2.dat[1]                                      ;
  return R                                              ;
}
