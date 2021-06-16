#include "qtgsl.h"

N::LevinWithError:: LevinWithError (void)
                  : work           (NULL)
{
}

N::LevinWithError:: LevinWithError (int n)
                  : work           (NULL )
{
  Allocate(n) ;
}

N::LevinWithError:: LevinWithError (const LevinWithError & levin)
                  : work           (NULL                        )
{
  if (NotNull(levin.work))     {
    Allocate(levin.work->size) ;
  }                            ;
}

N::LevinWithError::~LevinWithError (void)
{
  if (NotNull(work)) ::gsl_sum_levin_u_free(work) ;
  work = NULL                                     ;
}

bool N::LevinWithError::Allocate (int n)
{
  if (NotNull(work)) ::gsl_sum_levin_u_free(work) ;
  work = ::gsl_sum_levin_u_alloc(n)               ;
  return NotNull(work)                            ;
}

int N::LevinWithError::Acceleration(const double * array     ,
                                  const size_t   n         ,
                                  double       * sum_accel ,
                                  double       * abserr    )
{
  if (IsNull(work)) return 0     ;
  return ::gsl_sum_levin_u_accel (
           array                 ,
           n                     ,
           work                  ,
           sum_accel             ,
           abserr              ) ;
}

int N::LevinWithError::MinMax(const double * array     ,
                            const size_t   n         ,
                            const size_t   min_terms ,
                            const size_t   max_terms ,
                            double       * sum_accel ,
                            double       * abserr    )
{
  if (IsNull(work)) return 0      ;
  return ::gsl_sum_levin_u_minmax (
           array                  ,
           n                      ,
           min_terms              ,
           max_terms              ,
           work                   ,
           sum_accel              ,
           abserr               ) ;
}

int N::LevinWithError::Step(const double   term      ,
                          const size_t   n         ,
                          const size_t   nmax      ,
                          double       * sum_accel )
{
  if (IsNull(work)) return 0    ;
  return ::gsl_sum_levin_u_step (
           term                 ,
           n                    ,
           nmax                 ,
           work                 ,
           sum_accel          ) ;
}
