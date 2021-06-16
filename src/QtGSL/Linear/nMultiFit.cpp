#include "qtgsl.h"

N::MultiFit:: MultiFit (void)
            : work     (NULL)
{
}

N::MultiFit:: MultiFit (int n,int p)
            : work     (NULL       )
{
  Allocate ( n , p ) ;
}

N::MultiFit:: MultiFit (const MultiFit & fit)
            : work     (NULL                )
{
  if (NotNull(fit.work))                   {
    Allocate ( fit.work->n , fit.work->p ) ;
  }                                        ;
}

N::MultiFit::~MultiFit(void)
{
  if (NotNull(work)) ::gsl_multifit_linear_free(work) ;
  work = NULL                                         ;
}

bool N::MultiFit::Allocate(int n,int p)
{
  if (NotNull(work)) ::gsl_multifit_linear_free(work)     ;
  work = ::gsl_multifit_linear_alloc((size_t)n,(size_t)p) ;
  return NotNull(work)                                    ;
}

int N::MultiFit::Linear ( const gsl_matrix * X     ,
                        const gsl_vector * y     ,
                              gsl_vector * c     ,
                              gsl_matrix * cov   ,
                        double           * chisq )
{
  if (IsNull(work)) return 0                         ;
  return ::gsl_multifit_linear(X,y,c,cov,chisq,work) ;
}

int N::MultiFit::WeightedLinear ( const gsl_matrix * X     ,
                                const gsl_vector * w     ,
                                const gsl_vector * y     ,
                                      gsl_vector * c     ,
                                      gsl_matrix * cov   ,
                                double           * chisq )
{
  if (IsNull(work)) return 0                            ;
  return ::gsl_multifit_wlinear(X,w,y,c,cov,chisq,work) ;
}

int N::MultiFit::svdLinear (const gsl_matrix * X)
{
  if (IsNull(work)) return 0               ;
  return ::gsl_multifit_linear_svd(X,work) ;
}

int N::MultiFit::svdWeightedLinear ( const gsl_matrix * X     ,
                                   const gsl_vector * w     ,
                                   const gsl_vector * y     ,
                                   double             tol   ,
                                   size_t           * rank  ,
                                         gsl_vector * c     ,
                                         gsl_matrix * cov   ,
                                   double           * chisq )
{
  if (IsNull(work)) return 0                                         ;
  return ::gsl_multifit_wlinear_svd(X,w,y,tol,rank,c,cov,chisq,work) ;
}

int N::MultiFit::usvdWeightedLinear ( const gsl_matrix * X     ,
                                    const gsl_vector * w     ,
                                    const gsl_vector * y     ,
                                    double             tol   ,
                                    size_t           * rank  ,
                                          gsl_vector * c     ,
                                          gsl_matrix * cov   ,
                                    double           * chisq )
{
  if (IsNull(work)) return 0                                          ;
  return ::gsl_multifit_wlinear_usvd(X,w,y,tol,rank,c,cov,chisq,work) ;
}

int N::MultiFit::Linearest ( const gsl_vector * x     ,
                           const gsl_vector * c     ,
                           const gsl_matrix * cov   ,
                           double           * y     ,
                           double           * y_err )
{
  return ::gsl_multifit_linear_est(x,c,cov,y,y_err) ;
}

int N::MultiFit::Residuals ( const gsl_matrix * X ,
                           const gsl_vector * y ,
                           const gsl_vector * c ,
                                 gsl_vector * r )
{
  return ::gsl_multifit_linear_residuals(X,y,c,r) ;
}
