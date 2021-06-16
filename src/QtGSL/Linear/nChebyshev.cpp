#include "qtgsl.h"

N::Chebyshev:: Chebyshev (void)
             : chebyshev (NULL)
             , function  (NULL)
{
}

N::Chebyshev:: Chebyshev (int n)
             : chebyshev (NULL )
             , function  (NULL )
{
  Allocate ( n ) ;
}

N::Chebyshev:: Chebyshev (const Chebyshev & cheb)
             : chebyshev (NULL                  )
             , function  (NULL                  )
{
  if (NotNull(cheb.chebyshev))            {
    Allocate ( cheb.chebyshev->order )    ;
    if (NotNull(cheb.function))           {
      Initialize(cheb.chebyshev->a        ,
                 cheb.chebyshev->b        ,
                 cheb.function->function  ,
                 cheb.function->params  ) ;
    }                                     ;
  }                                       ;
}

N::Chebyshev::~Chebyshev(void)
{
  if (NotNull(chebyshev)) ::gsl_cheb_free(chebyshev) ;
  if (NotNull(function )) delete function            ;
  chebyshev = NULL                                   ;
  function  = NULL                                   ;
}

bool N::Chebyshev::Allocate (int n)
{
  if (NotNull(chebyshev)) ::gsl_cheb_free(chebyshev) ;
  chebyshev = ::gsl_cheb_alloc((size_t)n)            ;
  return NotNull(chebyshev)                          ;
}

int N::Chebyshev::Initialize ( const double   a        ,
                               const double   b        ,
                               MathFunction   equation ,
                               void         * params   )
{
  if (IsNull(function)) function = new gsl_function ;
  function->function = equation                     ;
  function->params   = params                       ;
  return ::gsl_cheb_init(chebyshev,function,a,b)    ;
}

size_t N::Chebyshev::Order(void)
{
  if (IsNull(chebyshev)) return 0    ;
  return ::gsl_cheb_order(chebyshev) ;
}

size_t N::Chebyshev::Size(void)
{
  if (IsNull(chebyshev)) return 0   ;
  return ::gsl_cheb_size(chebyshev) ;
}

double * N::Chebyshev::Coefficients(void)
{
  if (IsNull(chebyshev)) return NULL  ;
  return ::gsl_cheb_coeffs(chebyshev) ;
}

double N::Chebyshev::Eval(double x)
{
  if (IsNull(chebyshev)) return 0     ;
  if (IsNull(function )) return 0     ;
  return ::gsl_cheb_eval(chebyshev,x) ;
}

double N::Chebyshev::EvalN(size_t order,double x)
{
  if (IsNull(chebyshev)) return 0             ;
  if (IsNull(function )) return 0             ;
  return ::gsl_cheb_eval_n(chebyshev,order,x) ;
}

int N::Chebyshev::EvalAbsErr(const double   x      ,
                           double       * result ,
                           double       * abserr )
{
  if (IsNull(chebyshev)) return 0                       ;
  if (IsNull(function )) return 0                       ;
  return ::gsl_cheb_eval_err(chebyshev,x,result,abserr) ;
}

int N::Chebyshev::EvalNAbserr(const size_t   order  ,
                            const double   x      ,
                            double       * result ,
                            double       * abserr )
{
  if (IsNull(chebyshev)) return 0                               ;
  if (IsNull(function )) return 0                               ;
  return ::gsl_cheb_eval_n_err(chebyshev,order,x,result,abserr) ;
}

int N::Chebyshev::Derivative(Chebyshev & cheb)
{
  if (IsNull(chebyshev)) return 0                        ;
  if (IsNull(function )) return 0                        ;
  return ::gsl_cheb_calc_deriv(cheb.chebyshev,chebyshev) ;
}

int N::Chebyshev::Integral(Chebyshev & cheb)
{
  if (IsNull(chebyshev)) return 0                        ;
  if (IsNull(function )) return 0                        ;
  return ::gsl_cheb_calc_integ(cheb.chebyshev,chebyshev) ;
}
