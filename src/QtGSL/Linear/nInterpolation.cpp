#include "qtgsl.h"

N::Interpolation:: Interpolation (void)
                 : work          (NULL)
                 , accel         (NULL)
                 , spline        (NULL)
{
}

N::Interpolation:: Interpolation (const gsl_interp_type * T,int size)
                 : work          (NULL                              )
                 , accel         (NULL                              )
                 , spline        (NULL                              )
{
  Allocate ( T , size ) ;
}

N::Interpolation:: Interpolation (const Interpolation & interpolation)
                 : work          (NULL                               )
                 , accel         (NULL                               )
                 , spline        (NULL                               )
{
  if (NotNull(interpolation.work      ))                                {
    Allocate(interpolation.work->type,interpolation.work->size)         ;
  }                                                                     ;
  if (NotNull(interpolation.accel))                                     {
    AllocateAccel()                                                     ;
  }                                                                     ;
  if (NotNull(interpolation.spline))                                    {
    AllocateSpline(interpolation.work->type,interpolation.spline->size) ;
  }                                                                     ;
}

N::Interpolation::~Interpolation(void)
{
  if (NotNull(work  )) ::gsl_interp_free       ( work   ) ;
  if (NotNull(accel )) ::gsl_interp_accel_free ( accel  ) ;
  if (NotNull(spline)) ::gsl_spline_free       ( spline ) ;
  work   = NULL                                           ;
  accel  = NULL                                           ;
  spline = NULL                                           ;
}

bool N::Interpolation::Allocate(const gsl_interp_type * T,int size)
{
  if (NotNull(work)) ::gsl_interp_free(work) ;
  work = ::gsl_interp_alloc(T,(size_t)size)  ;
  return NotNull(work)                       ;
}

bool N::Interpolation::AllocateAccel(void)
{
  if (NotNull(accel)) ::gsl_interp_accel_free(accel) ;
  accel = ::gsl_interp_accel_alloc()                 ;
  return NotNull(accel)                              ;
}

bool N::Interpolation::AllocateSpline(const gsl_interp_type * T,int size)
{
  if (NotNull(spline)) ::gsl_spline_free(spline) ;
  spline = ::gsl_spline_alloc(T,(size_t)size)  ;
  return NotNull(spline)                       ;
}

int N::Interpolation::Initialize(const double xa[] ,
                               const double ya[] ,
                               int          size )
{
  if (IsNull(work)) return 0                        ;
  return ::gsl_interp_init(work,xa,ya,(size_t)size) ;
}

int N::Interpolation::InitializeSpline(const double xa[] ,
                                     const double ya[] ,
                                     int          size )
{
  if (IsNull(spline)) return 0                        ;
  return ::gsl_spline_init(spline,xa,ya,(size_t)size) ;
}

QString N::Interpolation::Name(void)
{
  if (IsNull(work)) return ""             ;
  return QString(::gsl_interp_name(work)) ;
}

QString N::Interpolation::SplineName(void)
{
  if (IsNull(spline)) return 0              ;
  return QString(::gsl_spline_name(spline)) ;
}

unsigned int N::Interpolation::MinSize(void)
{
  if (IsNull(work)) return 0         ;
  return ::gsl_interp_min_size(work) ;
}

unsigned int N::Interpolation::MinSize(const gsl_interp_type * T)
{
  return ::gsl_interp_type_min_size(T) ;
}

unsigned int N::Interpolation::SplineMinSize(void)
{
  if (IsNull(spline)) return 0         ;
  return ::gsl_spline_min_size(spline) ;
}

int N::Interpolation::BSearch(const double x_array[] ,
                                  double x         ,
                                  int    index_lo  ,
                                  int    index_hi  )
{
  return (int)::gsl_interp_bsearch(x_array,x,(size_t)index_lo,(size_t)index_hi) ;
}

int N::Interpolation::Find(const double x_array[] ,
                               int    size      ,
                               double x         )
{
  if (IsNull(accel)) return 0                                       ;
  return (int)::gsl_interp_accel_find(accel,x_array,(size_t)size,x) ;
}

int N::Interpolation::Reset(void)
{
  if (IsNull(accel)) return 0            ;
  return ::gsl_interp_accel_reset(accel) ;
}

double N::Interpolation::Eval(const double xa[] ,
                            const double ya[] ,
                                  double x    )
{
  if (IsNull(work )) return 0                  ;
  if (IsNull(accel)) return 0                  ;
  return ::gsl_interp_eval(work,xa,ya,x,accel) ;
}

int N::Interpolation::EvalE(const double   xa[] ,
                          const double   ya[] ,
                                double   x    ,
                                double * y    )
{
  if (IsNull(work )) return 0                      ;
  if (IsNull(accel)) return 0                      ;
  return ::gsl_interp_eval_e(work,xa,ya,x,accel,y) ;
}

double N::Interpolation::EvalDerivative(const double xa[] ,
                                      const double ya[] ,
                                            double x    )
{
  if (IsNull(work )) return 0                        ;
  if (IsNull(accel)) return 0                        ;
  return ::gsl_interp_eval_deriv(work,xa,ya,x,accel) ;
}

double N::Interpolation::EvalDerivative2(const double xa[] ,
                                       const double ya[] ,
                                             double x    )
{
  if (IsNull(work )) return 0                         ;
  if (IsNull(accel)) return 0                         ;
  return ::gsl_interp_eval_deriv2(work,xa,ya,x,accel) ;
}

double N::Interpolation::EvalIntegral(const double xa[] ,
                                    const double ya[] ,
                                          double a    ,
                                          double b    )
{
  if (IsNull(work )) return 0                          ;
  if (IsNull(accel)) return 0                          ;
  return ::gsl_interp_eval_integ(work,xa,ya,a,b,accel) ;
}

double N::Interpolation::SplineEval(double x)
{
  if (IsNull(spline)) return 0             ;
  if (IsNull(accel )) return 0             ;
  return ::gsl_spline_eval(spline,x,accel) ;
}

double N::Interpolation::SplineEvalDerivative(double x)
{
  if (IsNull(spline)) return 0                   ;
  if (IsNull(accel )) return 0                   ;
  return ::gsl_spline_eval_deriv(spline,x,accel) ;
}

double N::Interpolation::SplineEvalDerivative2(double x)
{
  if (IsNull(spline)) return 0                    ;
  if (IsNull(accel )) return 0                    ;
  return ::gsl_spline_eval_deriv2(spline,x,accel) ;
}

double N::Interpolation::SplineEvalIntegral(double a,double b)
{
  if (IsNull(spline)) return 0                     ;
  if (IsNull(accel )) return 0                     ;
  return ::gsl_spline_eval_integ(spline,a,b,accel) ;
}

int N::Interpolation::EvalDerivativeE(const double   xa[] ,
                                    const double   ya[] ,
                                          double   x    ,
                                          double * d    )
{
  if (IsNull(work )) return 0                            ;
  if (IsNull(accel)) return 0                            ;
  return ::gsl_interp_eval_deriv_e(work,xa,ya,x,accel,d) ;
}

int N::Interpolation::EvalDerivative2E(const double   xa[] ,
                                     const double   ya[] ,
                                           double   x    ,
                                           double * d2   )
{
  if (IsNull(work )) return 0                              ;
  if (IsNull(accel)) return 0                              ;
  return ::gsl_interp_eval_deriv2_e(work,xa,ya,x,accel,d2) ;
}

int N::Interpolation::EvalIntegralE(const double   xa[]   ,
                                  const double   ya[]   ,
                                        double   a      ,
                                        double   b      ,
                                        double * result )
{
  if (IsNull(work )) return 0                                   ;
  if (IsNull(accel)) return 0                                   ;
  return ::gsl_interp_eval_integ_e(work,xa,ya,a,b,accel,result) ;
}

int N::Interpolation::SplineEvalE(double x,double * y)
{
  if (IsNull(spline)) return 0                 ;
  if (IsNull(accel )) return 0                 ;
  return ::gsl_spline_eval_e(spline,x,accel,y) ;
}

int N::Interpolation::SplineEvalDerivativeE(double x,double * d)
{
  if (IsNull(spline)) return 0                       ;
  if (IsNull(accel )) return 0                       ;
  return ::gsl_spline_eval_deriv_e(spline,x,accel,d) ;
}

int N::Interpolation::SplineEvalDerivative2E (double x,double * d2)
{
  if (IsNull(spline)) return 0                         ;
  if (IsNull(accel )) return 0                         ;
  return ::gsl_spline_eval_deriv2_e(spline,x,accel,d2) ;
}

int N::Interpolation::SplineEvalIntegralE(double a,double b,double * result)
{
  if (IsNull(spline)) return 0                              ;
  if (IsNull(accel )) return 0                              ;
  return ::gsl_spline_eval_integ_e(spline,a,b,accel,result) ;
}
