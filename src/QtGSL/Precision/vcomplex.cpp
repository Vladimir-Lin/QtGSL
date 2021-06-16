#include "qtgsl.h"

vcomplex:: vcomplex (void)
{
}

vcomplex:: vcomplex ( double X , double Y )
         : x        (        X            )
         , y        (                   Y )
{
}

vcomplex:: vcomplex(const vcomplex & complex)
{
  x = complex.x ;
  y = complex.y ;
}

vcomplex::~vcomplex (void)
{
}

double vcomplex::real(void)
{
  return x ;
}

double vcomplex::imaginary(void)
{
  return y ;
}

double vcomplex::argument(void)
{
  gsl_complex z               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  return ::gsl_complex_arg(z) ;
}

double vcomplex::magnitude(void)
{
  gsl_complex z               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  return ::gsl_complex_abs(z) ;
}

double vcomplex::squared(void)
{
  gsl_complex z                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  return ::gsl_complex_abs2(z) ;
}

double vcomplex::logabs(void)
{
  gsl_complex z                  ;
  z.dat[0] = x                   ;
  z.dat[1] = y                   ;
  return ::gsl_complex_logabs(z) ;
}

vcomplex & vcomplex::operator = (vcomplex & complex)
{
  x = complex.x ;
  y = complex.y ;
  return ME     ;
}

vcomplex & vcomplex::operator += (vcomplex & complex)
{
  gsl_complex z              ;
  gsl_complex w              ;
  gsl_complex r              ;
  z.dat[0] = x               ;
  z.dat[1] = y               ;
  w.dat[0] = complex.x       ;
  w.dat[1] = complex.y       ;
  r = ::gsl_complex_add(z,w) ;
  x = r.dat[0]               ;
  y = r.dat[1]               ;
  return ME                  ;
}

vcomplex & vcomplex::operator -= (vcomplex & complex)
{
  gsl_complex z              ;
  gsl_complex w              ;
  gsl_complex r              ;
  z.dat[0] = x               ;
  z.dat[1] = y               ;
  w.dat[0] = complex.x       ;
  w.dat[1] = complex.y       ;
  r = ::gsl_complex_sub(z,w) ;
  x = r.dat[0]               ;
  y = r.dat[1]               ;
  return ME                  ;
}

vcomplex & vcomplex::operator *= (vcomplex & complex)
{
  gsl_complex z              ;
  gsl_complex w              ;
  gsl_complex r              ;
  z.dat[0] = x               ;
  z.dat[1] = y               ;
  w.dat[0] = complex.x       ;
  w.dat[1] = complex.y       ;
  r = ::gsl_complex_mul(z,w) ;
  x = r.dat[0]               ;
  y = r.dat[1]               ;
  return ME                  ;
}

vcomplex & vcomplex::operator /= (vcomplex & complex)
{
  gsl_complex z              ;
  gsl_complex w              ;
  gsl_complex r              ;
  z.dat[0] = x               ;
  z.dat[1] = y               ;
  w.dat[0] = complex.x       ;
  w.dat[1] = complex.y       ;
  r = ::gsl_complex_div(z,w) ;
  x = r.dat[0]               ;
  y = r.dat[1]               ;
  return ME                  ;
}

vcomplex & vcomplex::rectangular (double X,double Y)
{
  x = X ;
  y = Y ;
  return ME ;
}

vcomplex & vcomplex::polar(double r,double theta)
{
  gsl_complex z                         ;
  z = ::gsl_complex_polar ( r , theta ) ;
  x = z.dat[0]                          ;
  y = z.dat[1]                          ;
  return ME                             ;
}

vcomplex & vcomplex::conjugate(void)
{
  y = -y    ;
  return ME ;
}

vcomplex & vcomplex::inverse(void)
{
  gsl_complex z                ;
  gsl_complex i                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  i = ::gsl_complex_inverse(z) ;
  x = i.dat[0]                 ;
  y = i.dat[1]                 ;
  return ME                    ;
}

vcomplex & vcomplex::negative(void)
{
  x = -x    ;
  y = -y    ;
  return ME ;
}

void vcomplex::sin(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_sin(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::cos(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_cos(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::tan(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_tan(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::sec(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_sec(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::csc(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_csc(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::cot(vcomplex & value)
{
  gsl_complex z            ;
  gsl_complex r            ;
  z.dat[0] = x             ;
  z.dat[1] = y             ;
  r = ::gsl_complex_cot(z) ;
  value.x = r.dat[0]       ;
  value.y = r.dat[1]       ;
}

void vcomplex::arcsin(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arcsin(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::arccos(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arccos(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::arctan(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arctan(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::arcsec(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arcsec(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::arccsc(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arccsc(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::arccot(vcomplex & value)
{
  gsl_complex z               ;
  gsl_complex r               ;
  z.dat[0] = x                ;
  z.dat[1] = y                ;
  r = ::gsl_complex_arccot(z) ;
  value.x = r.dat[0]          ;
  value.y = r.dat[1]          ;
}

void vcomplex::sinh(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_sinh(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::cosh(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_cosh(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::tanh(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_tanh(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::sech(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_sech(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::csch(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_csch(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::coth(vcomplex & value)
{
  gsl_complex z             ;
  gsl_complex r             ;
  z.dat[0] = x              ;
  z.dat[1] = y              ;
  r = ::gsl_complex_coth(z) ;
  value.x = r.dat[0]        ;
  value.y = r.dat[1]        ;
}

void vcomplex::arcsinh(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arcsinh(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

void vcomplex::arccosh(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arccosh(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

void vcomplex::arctanh(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arctanh(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

void vcomplex::arcsech(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arcsech(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

void vcomplex::arccsch(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arccsch(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

void vcomplex::arccoth(vcomplex & value)
{
  gsl_complex z                ;
  gsl_complex r                ;
  z.dat[0] = x                 ;
  z.dat[1] = y                 ;
  r = ::gsl_complex_arccoth(z) ;
  value.x = r.dat[0]           ;
  value.y = r.dat[1]           ;
}

int N::Math::toByteArray(const vcomplexes & complexes,QByteArray & body)
{
  int total = complexes.count()                ;
  body.resize(total*sizeof(gsl_complex))       ;
  gsl_complex * z = (gsl_complex *)body.data() ;
  for (int i=0;i<total;i++)                    {
    z[i].dat[0] = complexes[i].x               ;
    z[i].dat[1] = complexes[i].y               ;
  }                                            ;
  return body.size()                           ;
}

int N::Math::toComplexes(const QByteArray & body,vcomplexes & complexes)
{
  int total = body.size() / sizeof(gsl_complex) ;
  complexes.clear()                             ;
  gsl_complex * z = (gsl_complex *)body.data()  ;
  for (int i=0;i<total;i++)                     {
    vcomplex v(z[i].dat[0],z[i].dat[1])         ;
    complexes << v                              ;
  }                                             ;
  return complexes.count()                      ;
}
