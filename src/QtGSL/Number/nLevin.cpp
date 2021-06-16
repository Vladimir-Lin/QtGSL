#include "qtgsl.h"

N::Levin:: Levin (void)
         : work  (NULL)
{
}

N::Levin:: Levin (int n)
         : work  (NULL )
{
  Allocate(n) ;
}

N::Levin:: Levin (const Levin & levin)
         : work  (NULL               )
{
  if (NotNull(levin.work))     {
    Allocate(levin.work->size) ;
  }                            ;
}

N::Levin::~Levin (void)
{
  if (NotNull(work)) ::gsl_sum_levin_utrunc_free(work) ;
  work = NULL                                          ;
}

bool N::Levin::Allocate (int n)
{
  if (NotNull(work)) ::gsl_sum_levin_utrunc_free(work) ;
  work = ::gsl_sum_levin_utrunc_alloc(n)               ;
  return NotNull(work)                                 ;
}

int N::Levin::Acceleration(const double * array        ,
                         const size_t   n            ,
                         double       * sum_accel    ,
                         double       * abserr_trunc )
{
  if (IsNull(work)) return 0          ;
  return ::gsl_sum_levin_utrunc_accel (
           array                      ,
           n                          ,
           work                       ,
           sum_accel                  ,
           abserr_trunc             ) ;
}

int N::Levin::MinMax(const double * array        ,
                   const size_t   n            ,
                   const size_t   min_terms    ,
                   const size_t   max_terms    ,
                   double       * sum_accel    ,
                   double       * abserr_trunc )
{
  if (IsNull(work)) return 0           ;
  return ::gsl_sum_levin_utrunc_minmax (
           array                       ,
           n                           ,
           min_terms                   ,
           max_terms                   ,
           work                        ,
           sum_accel                   ,
           abserr_trunc              ) ;
}

int N::Levin::Step(const double   term      ,
                 const size_t   n         ,
                 double       * sum_accel )
{
  if (IsNull(work)) return 0         ;
  return ::gsl_sum_levin_utrunc_step (
           term                      ,
           n                         ,
           work                      ,
           sum_accel               ) ;
}
