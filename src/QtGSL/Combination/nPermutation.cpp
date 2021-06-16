#include "qtgsl.h"

#define P    ((gsl_permutation *)  data())
#define G(X) ((gsl_permutation *)X.data())

N::Permutation:: Permutation (void)
               : QByteArray  (    )
{
  resize(sizeof(gsl_permutation)) ;
  fill  (0                      ) ;
}

N::Permutation:: Permutation (int size)
               : QByteArray  (        )
{
  resize(sizeof(gsl_permutation)) ;
  fill  (0                      ) ;
  P->size = size                  ;
  P->data = new size_t[size]      ;
}

N::Permutation:: Permutation (QString m)
               : QByteArray  (         )
{
  resize(sizeof(gsl_permutation)) ;
  fill  (0                      ) ;
  if (m.length()<=0) return       ;
  P->size = m.length()            ;
  P->data = new size_t[P->size]   ;
  setValue ( m )                  ;
}

N::Permutation:: Permutation (const Permutation & permutation)
               : QByteArray  (                               )
{
  assign(permutation) ;
}

N::Permutation::~Permutation (void)
{
  if (IsNull(P)) return   ;
  if (NotNull(P->data))   {
    delete [] (P->data)   ;
  }                       ;
  P->data = NULL          ;
}

int N::Permutation::isValid(void)
{
  if (IsNull(P)) return 0            ;
  return ::gsl_permutation_valid (P) ;
}

int N::Permutation::toCUIDs(CUIDs & Cuids)
{
  Cuids . clear ( )         ;
  if (IsNull(P)) return 0   ;
  int total = P->size       ;
  size_t * d = array()      ;
  for (int i=0;i<total;i++) {
    Cuids << (int)d[i]      ;
  }                         ;
  return Cuids . count ( )  ;
}

QString N::Permutation::toString(void)
{
  QString M = ""               ;
  if (IsNull(P)) return M      ;
  int total  = P->size         ;
  size_t * d = array()         ;
  for (int i=0;i<total;i++)    {
    M.append(QChar((int)d[i])) ;
  }                            ;
  return M                     ;
}

int N::Permutation::toByteArray(QByteArray & blob)
{
  blob.resize((1+(P->size))*sizeof(size_t))    ;
  size_t * d = (size_t *)blob.data()           ;
  d[0] = P->size                               ;
  if (P->size<=0) return blob.size()           ;
  memcpy(&d[1],P->data,sizeof(size_t)*P->size) ;
  return blob.size()                           ;
}

int N::Permutation::setElements(int size)
{
  P->size = size               ;
  if (NotNull(P->data))        {
    delete [] (P->data)        ;
  }                            ;
  P->data = NULL               ;
  if (size>0)                  {
    P->size = size             ;
    P->data = new size_t[size] ;
  }                            ;
  return size                  ;
}

int N::Permutation::elements(void) const
{
  if (IsNull(P)) return 0 ;
  return (int)P->size     ;
}

size_t * N::Permutation::array(void) const
{
  if (IsNull(P)) return NULL ;
  return P->data             ;
}

N::Permutation & N::Permutation::operator = (const Permutation & permutation)
{
  return assign(permutation) ;
}

N::Permutation & N::Permutation::assign (const Permutation & permutation)
{
  if (size()!=0)                             {
    if (NotNull(P))                          {
      delete [] (P->data)                    ;
    }                                        ;
  }                                          ;
  resize(sizeof(gsl_permutation))            ;
  fill  (0                      )            ;
  P->size = permutation.elements()           ;
  P->data = new size_t[P->size]              ;
  ::gsl_permutation_memcpy(P,G(permutation)) ;
  return ME                                  ;
}

N::Permutation & N::Permutation::toIdentity (void)
{
  if (IsNull(P)) return ME  ;
  ::gsl_permutation_init(P) ;
  return ME                 ;
}

N::Permutation & N::Permutation::Reverse(void)
{
  if (IsNull(P)) return ME     ;
  ::gsl_permutation_reverse(P) ;
  return ME                    ;
}

void N::Permutation::swap(int a,int b)
{
  if (IsNull(P) ) return                                    ;
  if (a>=P->size) return                                    ;
  if (b>=P->size) return                                    ;
  ::gsl_permutation_swap(P,(const size_t)a,(const size_t)b) ;
}

void N::Permutation::setValue(int index,int  value)
{
  if (IsNull(P)) return          ;
  if (index>=P->size) return     ;
  P->data[index] = (size_t)value ;
}

void N::Permutation::setValue(int index,char value)
{
  if (IsNull(P)) return          ;
  if (index>=P->size) return     ;
  P->data[index] = (size_t)value ;
}

void N::Permutation::setValue(int index,QChar value)
{
  if (IsNull(P)) return                    ;
  if (index>=P->size) return               ;
  P->data[index] = (size_t)value.unicode() ;
}

void N::Permutation::setValue(QString m)
{
  if (IsNull(P)) return            ;
  int total = m.length()           ;
  for (int i=0;i<total;i++)        {
    int v = (int)m.at(i).unicode() ;
    if (i<P->size)                 {
      P->data[i] = (size_t)v       ;
    }                              ;
  }                                ;
}

int N::Permutation::operator [] (int index)
{
  if (IsNull(P)     ) return 0                             ;
  if (index>=P->size) return 0                             ;
  return (int)::gsl_permutation_get(P,(const size_t)index) ;
}

int N::Permutation::next(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_permutation_next (P) ;
}

int N::Permutation::previous(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_permutation_prev (P) ;
}

int N::Permutation::inverse(Permutation & inv)
{
  if (IsNull(P)     ) return GSL_FAILURE     ;
  if (IsNull(G(inv))) return GSL_FAILURE     ;
  return ::gsl_permutation_inverse(G(inv),P) ;
}

int N::Permutation::toCanonical(Permutation & canonical)
{
  if (IsNull(P)           ) return GSL_FAILURE                 ;
  if (IsNull(G(canonical))) return GSL_FAILURE                 ;
  return ::gsl_permutation_linear_to_canonical(G(canonical),P) ;
}

int N::Permutation::toLinear(Permutation & linear)
{
  if (IsNull(P)        ) return GSL_FAILURE                  ;
  if (IsNull(G(linear))) return GSL_FAILURE                  ;
  return ::gsl_permutation_canonical_to_linear (G(linear),P) ;
}

int N::Permutation::inversions(void)
{
  if (IsNull(P)) return GSL_FAILURE       ;
  return ::gsl_permutation_inversions (P) ;
}

int N::Permutation::linearCycles(void)
{
  if (IsNull(P)) return GSL_FAILURE          ;
  return ::gsl_permutation_linear_cycles (P) ;
}

int N::Permutation::canonicalCycles(void)
{
  if (IsNull(P)) return GSL_FAILURE             ;
  return ::gsl_permutation_canonical_cycles (P) ;
}

int N::Permutation::permute(const size_t * p,double * data,size_t stride,size_t n)
{
  return ::gsl_permute(p,data,stride,n) ;
}

int N::Permutation::inverse(const size_t * p,double * data,size_t stride,size_t n)
{
  return ::gsl_permute_inverse(p,data,stride,n) ;
}
