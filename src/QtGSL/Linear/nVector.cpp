#include "qtgsl.h"

typedef struct   {
  int mtype      ;
  int items      ;
  int extras     ;
  int size       ;
} VectorDataType ;

N::Vector:: Vector     (void)
          : QByteArray (    )
{
}

N::Vector:: Vector     (Cpp::ValueTypes type,int items)
          : QByteArray (                              )
{
  set(type,items) ;
}

N::Vector:: Vector     (const Vector & vector)
          : QByteArray (                     )
{
  ME = vector ;
}

N::Vector::~Vector (void)
{
}

N::Cpp::ValueTypes N::Vector::Type(void)
{
  VectorDataType * mdt = (VectorDataType *)data()   ;
  nKickOut ( IsNull(mdt) , Cpp::Void )              ;
  return (Cpp::ValueTypes)mdt->mtype                ;
}

void N::Vector::reset(void)
{
  resize(sizeof(VectorDataType))                  ;
  VectorDataType * mdt = (VectorDataType *)data() ;
  mdt->mtype  = Cpp::Void                         ;
  mdt->items  = 0                                 ;
  mdt->extras = 0                                 ;
  mdt->size   = 0                                 ;
}

void N::Vector::set(Cpp::ValueTypes type,int items)
{
  resize(sizeof(VectorDataType))                  ;
  VectorDataType * mdt = (VectorDataType *)data() ;
  mdt->mtype           = Cpp::Void                ;
  mdt->items           = items                    ;
  mdt->extras          = 0                        ;
  mdt->size            = Cpp::SizeOf(type)        ;
  if (mdt->size>0) mdt->mtype = type              ;
  mdt->size *= items                              ;
  resize(sizeof(VectorDataType)+mdt->size)        ;
}

int N::Vector::count(void)
{
  VectorDataType * mdt = (VectorDataType *)data() ;
  return mdt->items                               ;
}

void N::Vector::setZero(void)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++) d[i] = 0         ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
}

void N::Vector::setAll(double x)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++) d[i] = (char)x   ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        uchar * d = (uchar *)array()               ;
        for (int i=0;i<total;i++) d[i] = (uchar)x  ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++) d[i] = (short)x  ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++) d[i] = (ushort)x ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++) d[i] = (int)x    ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
          d[i] = (unsigned int)x                   ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = (TUID)x   ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = (SUID)x   ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++) d[i] = (float)x  ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++) d[i] = x         ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++) d[i] = x         ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
}

void N::Vector::setBasis(int index)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++) d[i] = 0         ;
        d[index] = 1                               ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
}

bool N::Vector::swap(int i,int j)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  nKickOut ( i >= total , false )                  ;
  nKickOut ( j >= total , false )                  ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        char   t                                   ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        char   t                                   ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        short   t                                  ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        ushort   t                                 ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        int   t                                    ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        unsigned int   t                           ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        TUID   t                                   ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        SUID   t                                   ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        float   t                                  ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        double   t                                 ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        long double   t                            ;
        t    = d[i]                                ;
        d[i] = d[j]                                ;
        d[j] = t                                   ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return true                                      ;
}

bool N::Vector::reverse(void)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  int m     = total / 2                            ;
  int j     = total - 1                            ;
  nKickOut ( total < 2 , false )                   ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        char   t                                   ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        char   t                                   ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        short   t                                  ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        ushort   t                                 ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        int   t                                    ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        unsigned int   t                           ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        TUID   t                                   ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        SUID   t                                   ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        float   t                                  ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        double   t                                 ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        long double   t                            ;
        for (int i=0;i<m;i++,j--)                  {
          t    = d[i]                              ;
          d[i] = d[j]                              ;
          d[j] = t                                 ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return true                                      ;
}

int N::Vector::BytesPerCell(void)
{
  VectorDataType * mdt = (VectorDataType *)data() ;
  return Cpp::SizeOf((Cpp::ValueTypes)mdt->mtype) ;
}

int N::Vector::take(int pos,int items)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total   = mdt->items                         ;
  int start   = pos                                ;
  int removal = items                              ;
  int factor  = BytesPerCell()                     ;
  if (start>=total) return false                   ;
  if ((start+removal)>total)                       {
    removal = total - start                        ;
  }                                                ;
  start     *= factor                              ;
  start     += sizeof(VectorDataType)              ;
  removal   *= factor                              ;
  remove ( start , removal )                       ;
  total      = size() - sizeof(VectorDataType)     ;
  mdt->items = total / factor                      ;
  return mdt->items                                ;
}

int N::Vector::append(int items,const char * source)
{
  VectorDataType * mdt = (VectorDataType *)data() ;
  int factor = BytesPerCell()                     ;
  int total  = factor * items                     ;
  QByteArray :: append ( source , total )         ;
  mdt->items += items                             ;
  return mdt->items                               ;
}

int N::Vector::append(int items,int gap,const char * source)
{
  if (gap==0) return append ( items , source )     ;
  VectorDataType * mdt = (VectorDataType *)data()  ;
  char           * s   = (char *)source            ;
  char           * p   = NULL                      ;
  int factor = BytesPerCell()                      ;
  int total  = factor * items                      ;
  int skip   = factor * ( gap + 1 )                ;
  int end    = size ( )                            ;
  QByteArray :: resize ( end + total )             ;
  p  = (char *)data()                              ;
  p += end                                         ;
  for (int i=0;i<items;i++)                        {
    if (factor==1) *p = *s ; else                  {
      memcpy ( p , s , factor )                    ;
    }                                              ;
    p += factor                                    ;
    s += skip                                      ;
  }                                                ;
  mdt->items += items                              ;
  return mdt->items                                ;
}

int N::Vector::insert(int pos,int items,const char * source)
{
  VectorDataType * mdt = (VectorDataType *)data() ;
  int factor = BytesPerCell()                     ;
  int start  = factor * pos                       ;
  int total  = factor * items                     ;
  start += sizeof(VectorDataType)                 ;
  QByteArray :: insert ( start , source , total ) ;
  mdt->items += items                             ;
  return mdt->items                               ;
}

int N::Vector::insert(int pos,int items,int gap,const char * source)
{
  if (gap==0) return insert ( pos,items,source )  ;
  VectorDataType * mdt = (VectorDataType *)data() ;
  char           * s   = (char *)source           ;
  char           * p   = NULL                     ;
  int factor = BytesPerCell()                     ;
  int start  = factor * pos                       ;
  int total  = factor * items                     ;
  int skip   = factor * ( gap + 1 )               ;
  start += sizeof (VectorDataType)                ;
  QByteArray :: insert ( start , source , total ) ;
  p  = (char *)data()                             ;
  p += start                                      ;
  for (int i=0;i<items;i++)                       {
    if (factor==1) *p = *s ; else                 {
      memcpy ( p , s , factor )                   ;
    }                                             ;
    p += factor                                   ;
    s += skip                                     ;
  }                                               ;
  mdt->items += items                             ;
  return mdt->items                               ;
}

N::Vector & N::Vector::operator += (Vector & vector)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  nKickOut ( total != vector.count() , ME )        ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        gsl_vector b                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = vector.count()                  ;
        b.stride = vector.count()                  ;
        b.data   = (double *)vector.array()        ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
        ::gsl_vector_add ( &v , &b )               ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = 0                               ;
        b.stride = 0                               ;
        b.data   = NULL                            ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator -= (Vector & vector)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  nKickOut ( total != vector.count() , ME )        ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        gsl_vector b                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = vector.count()                  ;
        b.stride = vector.count()                  ;
        b.data   = (double *)vector.array()        ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
        ::gsl_vector_sub ( &v , &b )               ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = 0                               ;
        b.stride = 0                               ;
        b.data   = NULL                            ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator *= (Vector & vector)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  nKickOut ( total != vector.count() , ME )        ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        gsl_vector b                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = vector.count()                  ;
        b.stride = vector.count()                  ;
        b.data   = (double *)vector.array()        ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
        ::gsl_vector_mul ( &v , &b )               ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = 0                               ;
        b.stride = 0                               ;
        b.data   = NULL                            ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator /= (Vector & vector)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  nKickOut ( total != vector.count() , ME )        ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        gsl_vector b                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = vector.count()                  ;
        b.stride = vector.count()                  ;
        b.data   = (double *)vector.array()        ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
        ::gsl_vector_div ( &v , &b )               ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        b.size   = 0                               ;
        b.stride = 0                               ;
        b.data   = NULL                            ;
        b.block  = NULL                            ;
        b.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator += (double x)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        ::gsl_vector_add_constant ( &v ,  x )      ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator -= (double x)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        ::gsl_vector_add_constant ( &v , -x )      ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

N::Vector & N::Vector::operator *= (double x)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        gsl_vector v                               ;
        v.size   = total                           ;
        v.stride = total                           ;
        v.data   = (double *)array()               ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
        ::gsl_vector_scale(&v,x)                   ;
        v.size   = 0                               ;
        v.stride = 0                               ;
        v.data   = NULL                            ;
        v.block  = NULL                            ;
        v.owner  = 0                               ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return ME                                        ;
}

void * N::Vector::array(void)
{
  char * d = (char *)data()         ;
  d       += sizeof(VectorDataType) ;
  return (void *)d                  ;
}

N::Vector & N::Vector::operator = (const Vector & vector)
{
  nKickOut    ( vector . size () <= 0 , ME ) ;
  resize      ( vector . size ()           ) ;
  char * sm = (char *)vector . data (      ) ;
  char * tm = (char *)         data (      ) ;
  memcpy      ( tm , sm , size()           ) ;
  return ME                                  ;
}

bool N::Vector::subVector(Vector & vector,int offset,int items)
{
  nKickOut( (offset+items)>count() , false ) ;
  int    soi = Cpp::SizeOf(Type())           ;
  char * dvi = (char *)array()               ;
  vector.set(Type(),items)                   ;
  char * tvi = (char *)vector.array()        ;
  dvi += ( soi * offset    )                 ;
  soi *= items                               ;
  memcpy ( tvi , dvi , soi )                 ;
  return true                                ;
}

bool N::Vector::setVector(int offset,Vector & vector)
{
  nKickOut (  NotEqual(vector.Type(),Type()) , false ) ;
  nKickOut ( (offset+vector.count())>count() , false ) ;
  int    soi = Cpp::SizeOf(Type())           ;
  char * dvi = (char *)array()                         ;
  char * tvi = (char *)vector.array()                  ;
  dvi += ( soi * offset    )                           ;
  soi *= vector . count (  )                           ;
  memcpy ( dvi , tvi , soi )                           ;
  return true                                          ;
}

QString N::Vector::toCpp(void)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  QString Cpp                                      ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return Cpp                                       ;
}

QString N::Vector::toCpp(QString variableName)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  QString Cpp                                      ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  return Cpp                                       ;
}

double N::Vector::polynomial(double x)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  if (total<=0) return 0                           ;
  double * v = new double[total]                   ;
  double   r = 0                                   ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                                :
    break                                          ;
    case Cpp::VDouble                              :
    break                                          ;
    case Cpp::Rational                             :
    break                                          ;
    case Cpp::Pointer                              :
    break                                          ;
  }                                                ;
  r = ::gsl_poly_eval(v,total,x)                   ;
  delete [] v                                      ;
  return r                                         ;
}

bool N::Vector::polynomial(vcomplex & x,vcomplex & result)
{
  VectorDataType * mdt = (VectorDataType *)data()  ;
  int total = mdt->items                           ;
  if (total<=0) return false                       ;
  double * v = new double[total]                   ;
  gsl_complex z                                    ;
  gsl_complex r                                    ;
  z.dat[0] = x.x                                   ;
  z.dat[1] = x.y                                   ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                       :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                      :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                     :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                    :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                       :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                   :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                  :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                      :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                     :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                    :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
          v[i] = (double)d[i]                      ;
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::VLong                      :
    break                                          ;
    case Cpp::VDouble                    :
    break                                          ;
    case Cpp::Rational                   :
    break                                          ;
    case Cpp::Pointer                    :
    break                                          ;
  }                                                ;
  r = ::gsl_poly_complex_eval ( v , total , z )    ;
  delete [] v                                      ;
  result.x = r.dat[0]                              ;
  result.y = r.dat[1]                              ;
  return true                                      ;
}

int N::Vector:: derivatives (double x,int length,double * results)
{
  VectorDataType * mdt = (VectorDataType *)data()      ;
  int total = mdt->items                               ;
  if (total<=0) return 0                               ;
  double * v = new double[total]                       ;
  int      r = 0                                       ;
  switch  ( mdt->mtype )                               {
    case Cpp::Char                           :
      if (total>0)                                     {
        char * d = (char *)array()                     ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::Byte                           :
      if (total>0)                                     {
        char * d = (char *)array()                     ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::Short                          :
      if (total>0)                                     {
        short * d = (short *)array()                   ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::UShort                         :
      if (total>0)                                     {
        ushort * d = (ushort *)array()                 ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::Integer                        :
      if (total>0)                                     {
        int * d = (int *)array()                       ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::UInt                           :
      if (total>0)                                     {
        unsigned int * d = (unsigned int *)array()     ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::LongLong                       :
      if (total>0)                                     {
        TUID * d = (TUID *)array()                     ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::ULongLong                      :
      if (total>0)                                     {
        SUID * d = (SUID *)array()                     ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::Float                          :
      if (total>0)                                     {
        float * d = (float *)array()                   ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::Double                         :
      if (total>0)                                     {
        double * d = (double *)array()                 ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::LDouble                        :
      if (total>0)                                     {
        long double * d = (long double *)array()       ;
        for (int i=0;i<total;i++)                      {
          v[i] = (double)d[i]                          ;
        }                                              ;
      }                                                ;
    break                                              ;
    case Cpp::VLong                          :
    break                                              ;
    case Cpp::VDouble                        :
    break                                              ;
    case Cpp::Rational                       :
    break                                              ;
    case Cpp::Pointer                        :
    break                                              ;
  }                                                    ;
  r = ::gsl_poly_eval_derivs(v,total,x,results,length) ;
  delete [] v                                          ;
  return r                                             ;
}
