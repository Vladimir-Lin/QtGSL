#include "qtgsl.h"

N::BSplines:: BSplines   (void)
            : work       (NULL)
{
}

N::BSplines:: BSplines  (int k,int nbreak)
            : work       (NULL            )
{
  Allocate ( k , nbreak ) ;
}

N::BSplines:: BSplines   (const BSplines & bsplines)
            : work       (NULL                     )
{
  if (NotNull(bsplines.work      ))                  {
    Allocate(bsplines.work->k,bsplines.work->nbreak) ;
  }                                                  ;
}

N::BSplines::~BSplines(void)
{
  if (NotNull(work)) ::gsl_bspline_free ( work ) ;
  work = NULL                                    ;
}

bool N::BSplines::Allocate(int k,int nbreak)
{
  if (NotNull(work)) ::gsl_bspline_free(work)           ;
  work = ::gsl_bspline_alloc ((size_t)k,(size_t)nbreak) ;
  return NotNull(work)                                  ;

}

int N::BSplines::Knots(const gsl_vector * breakpts)
{
  if (IsNull(work)) return 0                ;
  return ::gsl_bspline_knots(breakpts,work) ;
}

int N::BSplines::uniformKnots(const double a,const double b)
{
  if (IsNull(work)) return 0                   ;
  return ::gsl_bspline_knots_uniform(a,b,work) ;
}

int N::BSplines::Eval(const double x,gsl_vector * B)
{
  if (IsNull(work)) return 0          ;
  return ::gsl_bspline_eval(x,B,work) ;
}

int N::BSplines::EvalNonZero(const double   x      ,
                           gsl_vector   * Bk     ,
                           size_t       * istart ,
                           size_t       * iend   )
{
  if (IsNull(work)) return 0                               ;
  return ::gsl_bspline_eval_nonzero(x,Bk,istart,iend,work) ;
}

int N::BSplines::Coefficients(void)
{
  if (IsNull(work)) return 0                 ;
  return (size_t)::gsl_bspline_ncoeffs(work) ;
}

double N::BSplines::GrevilleAbscissa(int i)
{
  if (IsNull(work)) return 0                             ;
  return ::gsl_bspline_greville_abscissa((size_t)i,work) ;
}

int N::BSplines::DerivativeEval(const double x      ,
                              const int    nderiv ,
                              gsl_matrix * dB     )
{
  if (IsNull(work      )) return 0 ;
  return ::gsl_bspline_deriv_eval  (
           x                       ,
           (const size_t)nderiv    ,
           dB                      ,
           work                  ) ;
}

int N::BSplines::DerivativeEvalNonZero(const double x      ,
                                     const int    nderiv ,
                                     gsl_matrix * dB     ,
                                     size_t     * istart ,
                                     size_t     * iend   )
{
  if (IsNull(work      )) return 0        ;
  return ::gsl_bspline_deriv_eval_nonzero (
           x                              ,
           (const size_t)nderiv           ,
           dB                             ,
           istart                         ,
           iend                           ,
           work                         ) ;
}
