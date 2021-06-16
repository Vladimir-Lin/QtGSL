#include "qtgsl.h"

#define P    ((gsl_multiset *)  data())
#define G(X) ((gsl_multiset *)X.data())

N::Multisets:: Multisets  (void)
             : QByteArray (    )
{
  resize(sizeof(gsl_multiset)) ;
  fill  (0                   ) ;
}

N::Multisets:: Multisets  (int n,int k)
             : QByteArray (           )
{
  resize(sizeof(gsl_multiset)) ;
  fill  (0                   ) ;
  P->n    = n                  ;
  P->k    = k                  ;
  P->data = new size_t[k]      ;
}

N::Multisets:: Multisets  (const Multisets & multisets)
             : QByteArray (                            )
{
  assign(multisets) ;
}

N::Multisets::~Multisets (void)
{
  if (IsNull(P)) return ;
  delete [] (P->data)   ;
  P->data = NULL        ;
}

int N::Multisets::isValid(void)
{
  if (IsNull(P)) return 0        ;
  return ::gsl_multiset_valid(P) ;
}

int N::Multisets::toCUIDs(CUIDs & Cuids)
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

int N::Multisets::toByteArray(QByteArray & blob)
{
  blob.resize((1+(P->n))*sizeof(size_t))    ;
  size_t * d = (size_t *)blob.data()        ;
  d[0] = P->n                               ;
  d[1] = P->k                               ;
  memcpy(&d[2],P->data,sizeof(size_t)*P->k) ;
  return blob.size()                        ;
}

int N::Multisets::setElements(int n,int k)
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

int N::Multisets::setChosen(int k)
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

int N::Multisets::elements(void) const
{
  if (IsNull(P)) return 0 ;
  return (int)P->n        ;
}

int N::Multisets::chosen(void) const
{
  if (IsNull(P)) return 0 ;
  return (int)P->k        ;
}

size_t * N::Multisets::array(void) const
{
  if (IsNull(P)) return NULL ;
  return P->data             ;
}

N::Multisets & N::Multisets::operator = (const Multisets & multisets)
{
  return assign(multisets) ;
}

N::Multisets & N::Multisets::assign (const Multisets & multisets)
{
  if (size()!=0)                        {
    if (NotNull(P))                     {
      delete [] (P->data)               ;
    }                                   ;
  }                                     ;
  resize(sizeof(gsl_multiset))          ;
  fill  (0                      )       ;
  int n = multisets.elements()          ;
  int k = multisets.chosen  ()          ;
  P->n    = n                           ;
  P->k    = k                           ;
  P->data = new size_t[k]               ;
  ::gsl_multiset_memcpy(P,G(multisets)) ;
  return ME                             ;
}

N::Multisets & N::Multisets::toFirst (void)
{
  if (IsNull(P)) return ME     ;
  ::gsl_multiset_init_first(P) ;
  return ME                    ;
}

N::Multisets & N::Multisets::toLast (void)
{
  if (IsNull(P)) return ME    ;
  ::gsl_multiset_init_last(P) ;
  return ME                   ;
}

void N::Multisets::setValue(int index,int  value)
{
  if (IsNull(P)) return          ;
  if (index>=P->n) return        ;
  P->data[index] = (size_t)value ;
}

void N::Multisets::setValue(int index,char value)
{
  if (IsNull(P)) return          ;
  if (index>=P->n) return        ;
  P->data[index] = (size_t)value ;
}

void N::Multisets::setValue(int index,QChar value)
{
  if (IsNull(P)) return                    ;
  if (index>=P->n) return                  ;
  P->data[index] = (size_t)value.unicode() ;
}

int N::Multisets::operator [] (int index)
{
  if (IsNull(P)  ) return 0                              ;
  if (index>=P->n) return 0                              ;
  return (int)::gsl_multiset_get (P,(const size_t)index) ;
}

int N::Multisets::next(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_multiset_next (P)    ;
}

int N::Multisets::previous(void)
{
  if (IsNull(P)) return GSL_FAILURE ;
  return ::gsl_multiset_prev (P)    ;
}
