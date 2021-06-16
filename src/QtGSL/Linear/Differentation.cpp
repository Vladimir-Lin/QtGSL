#include "qtgsl.h"

int N::Math::DerivativeCentral(double x,double h,double * result,double * abserr,MathFunction function,void * params)
{
  gsl_function fx                                   ;
  fx.function = function                            ;
  fx.params   = params                              ;
  return ::gsl_deriv_central(&fx,x,h,result,abserr) ;
}

int N::Math::DerivativeForward(double x,double h,double * result,double * abserr,MathFunction function,void * params)
{
  gsl_function fx                                   ;
  fx.function = function                            ;
  fx.params   = params                              ;
  return ::gsl_deriv_forward(&fx,x,h,result,abserr) ;
}

int N::Math::DerivativeBackward(double x,double h,double * result,double * abserr,MathFunction function,void * params)
{
  gsl_function fx                                    ;
  fx.function = function                             ;
  fx.params   = params                               ;
  return ::gsl_deriv_backward(&fx,x,h,result,abserr) ;
}
