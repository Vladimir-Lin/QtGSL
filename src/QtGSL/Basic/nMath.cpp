#include "qtgsl.h"

#ifdef Q_OS_WIN
#include <mpir/mpir.h>
#else
#include <gmp/gmp.h>
#endif

QList<int> N::Math::Differential(QList<int> & discrete)
{
  QList<int> result;
  if (discrete.size()==0) return result;
  for (int i=1;i<discrete.size();i++)
    result << (discrete[i] - discrete[i-1]);
  return result;
}

QList<long long> N::Math::Differential(QList<long long> & discrete)
{
  QList<long long> result;
  if (discrete.size()==0) return result;
  for (int i=1;i<discrete.size();i++)
    result << (discrete[i] - discrete[i-1]);
  return result;
}

QList<float> N::Math::Differential(QList<float> & discrete)
{
  QList<float> result;
  if (discrete.size()==0) return result;
  for (int i=1;i<discrete.size();i++)
    result << (discrete[i] - discrete[i-1]);
  return result;
}

QList<double> N::Math::Differential(QList<double> & discrete)
{
  QList<double> result;
  if (discrete.size()==0) return result;
  for (int i=1;i<discrete.size();i++)
    result << (discrete[i] - discrete[i-1]);
  return result;
}

QList<double> N::Math::VectorMultiply(QList<double> & discrete,double v)
{
  QList<double> vm;
  for (int i=0;i<discrete.size();i++)
    vm << discrete[i] * v;
  return vm;
}

double N::Math::SquareSigma(QList<double> & discrete)
{
  double square = 0;
  double t;
  for (int i=0;i<discrete.size();i++) {
    t       = discrete[i];
    square += (t*t);
  };
  return square;
}

double N::Math::VectorMin(QList<double> & discrete)
{
  double MinValue = 0;
  if (discrete.size()<=0) return MinValue;
  MinValue = discrete[0];
  for (int i=1;i<discrete.size();i++)
    if (MinValue>discrete[i]) MinValue = discrete[i];
  return MinValue;
}

double N::Math::VectorMax(QList<double> & discrete)
{
  double MaxValue = 0;
  if (discrete.size()<=0) return MaxValue;
  MaxValue = discrete[0];
  for (int i=1;i<discrete.size();i++)
    if (MaxValue<discrete[i]) MaxValue = discrete[i];
  return MaxValue;
}

QByteArray N::Math::VectorByteArray(QList<double> & discrete)
{
  int total = discrete.size()*sizeof(double);
  QByteArray B;
  double * d = new double[discrete.size()];
  B.resize(total);
  for (int i=0;i<discrete.size();i++) d[i] = discrete[i];
  memcpy(B.data(),d,total);
  delete d;
  return B;
}

QList<double> N::Math::VectorFromByteArray(QByteArray & B)
{
  int           total = B.size() / sizeof(double);
  double *      d     = new double[total];
  QList<double> v;
  memcpy(d,B.data(),B.size());
  for (int i=0;i<total;i++) v << d[i];
  delete d;
  return v;
}

double N::Math::Average(int total,double * values)
{
  double average = 0        ;
  if (total<=0) return 0    ;
  for (int i=0;i<total;i++) {
    average += values[i]    ;
  }                         ;
  average /= total          ;
  return average            ;
}

int N::Math::AddValues(int total,double * values,double value)
{
  for (int i=0;i<total;i++) {
    values[i] += value      ;
  }                         ;
  return total              ;
}

int N::Math::Multiply(int total,double * values,double value)
{
  for (int i=0;i<total;i++) {
    values[i] *= value      ;
  }                         ;
  return total              ;
}

int N::Math::FaPb(int total,double * values,double a,double b)
{
  for (int i=0;i<total;i++) {
    values[i] += b          ;
    values[i] *= a          ;
  }                         ;
  return total              ;
}

int N::Math::FaXb(int total,double * values,double a,double b)
{
  for (int i=0;i<total;i++) {
    values[i] *= a          ;
    values[i] += b          ;
  }                         ;
  return total              ;
}

int N::Math::Divide(int total,double * values,double value)
{
  for (int i=0;i<total;i++) {
    values[i] /= value      ;
  }                         ;
  return total              ;
}

void N::Math::CutOff(int total,double * values,double minimum,double maximum)
{
  for (int i=0;i<total;i++) {
    double v = values[i]    ;
    if (v<minimum)          {
      values[i] = minimum   ;
    } else
    if (v>maximum)          {
      values[i] = maximum   ;
    }                       ;
  }                         ;
}

int N::Math::toDouble(int items,char * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,unsigned char * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,short * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,unsigned short * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,int * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,unsigned int * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::toDouble(int items,float * C,double * D)
{
  for (int i=0;i<items;i++) D[i] = (double)C[i] ;
  return items                                  ;
}

int N::Math::Addition(int items,double * A,double * B)
{
  for (int i=0;i<items;i++) A[i] += B[i] ;
  return items                           ;
}

int N::Math::Addition(int items,double * A,double * B,double * C)
{
  for (int i=0;i<items;i++) A[i] = B[i] + C[i] ;
  return items                                 ;
}

int N::Math::Subtract(int items,double * A,double * B)
{
  for (int i=0;i<items;i++) A[i] -= B[i] ;
  return items                           ;
}

int N::Math::Subtract(int items,double * A,double * B,double * C)
{
  for (int i=0;i<items;i++) A[i] = B[i] - C[i] ;
  return items                                 ;
}

int N::Math::Multiply(int items,double * A,double * B)
{
  for (int i=0;i<items;i++) A[i] *= B[i] ;
  return items                           ;
}

int N::Math::Multiply(int items,double * A,double * B,double * C)
{
  for (int i=0;i<items;i++) A[i] = B[i] * C[i] ;
  return items                                 ;
}

int N::Math::Divide(int items,double * A,double * B)
{
  for (int i=0;i<items;i++) A[i] /= B[i] ;
  return items                           ;
}

int N::Math::Divide(int items,double * A,double * B,double * C)
{
  for (int i=0;i<items;i++) A[i] = B[i] / C[i] ;
  return items                                 ;
}

void N::Math::IntegerMiddleArray(int items,unsigned char * array,int gaps,void * funcdata)
{ Q_UNUSED ( funcdata )                  ;
  unsigned char * p = array              ;
  #define v ( (qint32 *) p )
  while ( items > 0 )                    {
    v [ 1 ]  = ( v [ 0 ] + v [ 2 ] ) / 2 ;
    p       += gaps                      ;
    items   --                           ;
  }                                      ;
  #undef  v
}

int N::Cpp::SizeOf(Cpp::ValueTypes type)
{
  #define TCAST(TYPE,CTYPE)           \
    case Cpp::TYPE: return sizeof(CTYPE)
  switch  ( type                    ) {
    TCAST ( Char      , char        ) ;
    TCAST ( Byte      , char        ) ;
    TCAST ( Short     , short       ) ;
    TCAST ( UShort    , short       ) ;
    TCAST ( Integer   , int         ) ;
    TCAST ( UInt      , int         ) ;
    TCAST ( LongLong  , long long   ) ;
    TCAST ( ULongLong , long long   ) ;
    TCAST ( Float     , float       ) ;
    TCAST ( Double    , double      ) ;
    TCAST ( LDouble   , long double ) ;
    TCAST ( VLong     , mpz_t *     ) ;
    TCAST ( VDouble   , mpf_t *     ) ;
    TCAST ( Rational  , mpq_t *     ) ;
    TCAST ( Pointer   , void  *     ) ;
  }                                   ;
  #undef  TCAST
  return 0                            ;
}
