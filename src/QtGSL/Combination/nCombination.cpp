#include "qtgsl.h"

#define P    ((gsl_combination *)  data())
#define G(X) ((gsl_combination *)X.data())

N::Combination:: Combination(void)
             : QByteArray  (    )
{
  resize(sizeof(gsl_combination)) ;
  fill  (0                      ) ;
}

N::Combination:: Combination(int n,int k)
             : QByteArray  (           )
{
  resize(sizeof(gsl_combination)) ;
  fill  (0                      ) ;
  P->n    = n                     ;
  P->k    = k                     ;
  P->data = new size_t[k]         ;
}

N::Combination:: Combination (const Combination & combination)
             : QByteArray   (                                )
{
  assign(combination) ;
}

N::Combination::~Combination (void)
{
  if (IsNull(P)) return ;
  delete [] (P->data)   ;
  P->data = NULL        ;
}

int N::Combination::isValid(void)
{
  if (IsNull(P)) return 0           ;
  return ::gsl_combination_valid(P) ;
}

int N::Combination::toCUIDs(CUIDs & Cuids)
{
  Cuids . clear ( )         ;
  if (IsNull(P)) return 0   ;
  int total = P->k          ;
  size_t * d = array()      ;
  for (int i=0;i<total;i++) {
    Cuids << (int)d[i]      ;
  }                         ;
  return Cuids . count ( )  ;
}

int N::Combination::toByteArray(QByteArray & blob)
{
  blob.resize((1+(P->n))*sizeof(size_t))    ;
  size_t * d = (size_t *)blob.data()        ;
  d[0] = P->n                               ;
  d[1] = P->k                               ;
  memcpy(&d[2],P->data,sizeof(size_t)*P->k) ;
  return blob.size()                        ;
}

int N::Combination::setElements(int n,int k)
{
  P->n = n                  ;
  P->k    = k               ;
  if (NotNull(P->data))     {
    delete [] (P->data)     ;
  }                         ;
  P->data = NULL            ;
  if (k>0)                  {
    P->data = new size_t[k] ;
  }                         ;
  return n                  ;
}

int N::Combination::setChosen(int k)
{
  if (IsNull(P)) return 0   ;
  if (NotNull(P->data))     {
    delete [] (P->data)     ;
  }                         ;
  P->k = k                  ;
  P->data = NULL            ;
  if (k>0)                  {
    P->data = new size_t[k] ;
  }                         ;
  return k                  ;
}

int N::Combination::elements(void) const
{
  if (IsNull(P)) return 0 ;
  return (int)P->n        ;
}

int N::Combination::chosen(void) const
{
  if (IsNull(P)) return 0 ;
  return (int)P->k        ;
}

size_t * N::Combination::array(void) const
{
  if (IsNull(P)) return NULL ;
  return P->data             ;
}

N::Combination & N::Combination::operator = (const Combination & combination)
{
  return assign(combination) ;
}

N::Combination & N::Combination::assign (const Combination & combination)
{
  if (size()!=0)                             {
    if (NotNull(P))                          {
      delete [] (P->data)                    ;
    }                                        ;
  }                                          ;
  resize(sizeof(gsl_combination))            ;
  fill  (0                      )            ;
  int n = combination.elements()             ;
  int k = combination.chosen  ()             ;
  P->n    = n                                ;
  P->k    = k                                ;
  P->data = new size_t[k]                    ;
  ::gsl_combination_memcpy(P,G(combination)) ;
  return ME                                  ;
}

N::Combination & N::Combination::toFirst (void)
{
  if (IsNull(P)) return ME        ;
  ::gsl_combination_init_first(P) ;
  return ME                       ;
}

N::Combination & N::Combination::toLast (void)
{
  if (IsNull(P)) return ME       ;
  ::gsl_combination_init_last(P) ;
  return ME                      ;
}

void N::Combination::setValue(int index,int  value)
{
  if (IsNull(P)) return          ;
  if (index>=P->n) return        ;
  P->data[index] = (size_t)value ;
}

void N::Combination::setValue(int index,char value)
{
  if (IsNull(P)) return          ;
  if (index>=P->n) return        ;
  P->data[index] = (size_t)value ;
}

void N::Combination::setValue(int index,QChar value)
{
  if (IsNull(P)) return                    ;
  if (index>=P->n) return                  ;
  P->data[index] = (size_t)value.unicode() ;
}

int N::Combination::operator [] (int index)
{
  if (IsNull(P)  ) return 0                                 ;
  if (index>=P->n) return 0                                 ;
  return (int)::gsl_combination_get (P,(const size_t)index) ;
}

int N::Combination::next(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_combination_next (P) ;
}

int N::Combination::previous(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_combination_prev (P) ;
}
