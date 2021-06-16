#include "qtgsl.h"

typedef struct   {
  int mtype      ;
  int rows       ;
  int columns    ;
  int size       ;
} MatrixDataType ;

N::Matrix:: Matrix     (void)
          : QByteArray (    )
{
}

N::Matrix:: Matrix     (const Matrix & matrix)
          : QByteArray (                     )
{
  assign ( matrix ) ;
}

N::Matrix:: Matrix     (Cpp::ValueTypes type,int row,int column)
          : QByteArray (                                       )
{
  set(type,row,column);
}

N::Matrix::~Matrix (void)
{
}

N::Cpp::ValueTypes N::Matrix::Type(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  nKickOut ( IsNull(mdt) , Cpp::Void )            ;
  return (Cpp::ValueTypes)mdt->mtype              ;
}

void N::Matrix::reset(void)
{
  resize(sizeof(MatrixDataType))                  ;
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  mdt->mtype   = Cpp::Void                        ;
  mdt->rows    = 0                                ;
  mdt->columns = 0                                ;
  mdt->size    = 0                                ;
}

void N::Matrix :: assign (const Matrix & matrix)
{
  nDropOut    ( matrix.size() <= 0    ) ;
  resize      ( matrix . size ()      ) ;
  char * sm = (char *)matrix . data ( ) ;
  char * tm = (char *)         data ( ) ;
  memcpy      ( tm , sm , size()      ) ;
}

void N::Matrix::set(Cpp::ValueTypes type,int row,int column)
{
  resize(sizeof(MatrixDataType))                  ;
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  mdt->mtype           = Cpp::Void                ;
  mdt->rows            = row                      ;
  mdt->columns         = column                   ;
  mdt->size            = Cpp::SizeOf(type)        ;
  if (mdt->size>0) mdt->mtype = type              ;
  mdt->size *= row                                ;
  mdt->size *= column                             ;
  resize(sizeof(MatrixDataType)+mdt->size)        ;
}

void N::Matrix::zerofill(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  nDropOut ( mdt->size <= 0 )                     ;
  char * f = (char *)array()                      ;
  memset(f,0,mdt->size)                           ;
}

int N::Matrix::Rows(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  return mdt->rows                                ;
}

int N::Matrix::Columns(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  return mdt->columns                             ;
}

int N::Matrix::at(int row,int column)
{
  MatrixDataType * mdt = (MatrixDataType *)data() ;
  int a                                           ;
  a  = mdt->columns                               ;
  a *= row                                        ;
  a += column                                     ;
  return a                                        ;
}

double N::Matrix::sum(double * v,int items)
{
  double r = 0                 ;
  nFullLoop(i,items) r += v[i] ;
  return r                     ;
}

void N::Matrix::dispatch(int shift,int column,int items,double * R,double * S)
{
  nFullLoop ( i , items ) {
    R [ shift ] = S [ i ] ;
    shift += column       ;
  }                       ;
}

double N::Matrix::multiple(int length,double * a,double * b)
{
  double r = 0                    ;
  nKickOut ( length <= 0 , r )    ;
  double * R = new double[length] ;
  nFullLoop(i,length)             {
    R[i] = a[i] * b[i]            ;
  }                               ;
  r = sum(R,length)               ;
  delete [] R                     ;
  return r                        ;
}

double N::Matrix::multiple(int length,double * R,double * a,double * b)
{
  nKickOut ( length <= 0 , 0 )    ;
  nFullLoop(i,length)             {
    R[i] = a[i] * b[i]            ;
  }                               ;
  return sum(R,length)            ;
}

void * N::Matrix::array(void)
{
  char * d = (char *)data()         ;
  d       += sizeof(MatrixDataType) ;
  return (void *)d                  ;
}

N::Matrix & N::Matrix::operator = (const Matrix & matrix)
{
  nKickOut    ( matrix . size () <= 0 , ME ) ;
  resize      ( matrix . size ()           ) ;
  char * sm = (char *)matrix . data (      ) ;
  char * tm = (char *)         data (      ) ;
  memcpy      ( tm , sm , size()           ) ;
  return ME                                  ;
}

N::Matrix & N::Matrix::operator += (const Matrix & matrix)
{
  nKickOut ( matrix . size () <= 0 , ME )                ;
  MatrixDataType * mdt = (MatrixDataType *)       data() ;
  MatrixDataType * mst = (MatrixDataType *)matrix.data() ;
  int rows    = mdt->rows                                ;
  int columns = mdt->columns                             ;
  switch  ( mdt->mtype )                                 {
    case Cpp::Char                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Byte                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Short                                      :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::UShort                                     :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Integer                                    :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::UInt                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::LongLong                                   :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::ULongLong                                  :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Float                                      :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Double                                     :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::LDouble                                    :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::VLong                                      :
    break                                                ;
    case Cpp::VDouble                                    :
    break                                                ;
    case Cpp::Rational                                   :
    break                                                ;
    case Cpp::Pointer                                    :
    break                                                ;
  }                                                      ;
  return ME                                              ;
}

N::Matrix & N::Matrix::operator -= (const Matrix & matrix)
{
  nKickOut ( matrix . size () <= 0 , ME )                ;
  MatrixDataType * mdt = (MatrixDataType *)       data() ;
  MatrixDataType * mst = (MatrixDataType *)matrix.data() ;
  int rows    = mdt->rows                                ;
  int columns = mdt->columns                             ;
  switch  ( mdt->mtype )                                 {
    case Cpp::Char                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Byte                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Short                                      :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::UShort                                     :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Integer                                    :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::UInt                                       :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::LongLong                                   :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::ULongLong                                  :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Float                                      :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::Double                                     :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::LDouble                                    :
      if (rows>0 && columns>0)                           {
      }                                                  ;
    break                                                ;
    case Cpp::VLong                                      :
    break                                                ;
    case Cpp::VDouble                                    :
    break                                                ;
    case Cpp::Rational                                   :
    break                                                ;
    case Cpp::Pointer                                    :
    break                                                ;
  }                                                      ;
  return ME                                              ;
}

N::Matrix & N::Matrix::operator += (int value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,+)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] =  value O d [ i ] ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator += (double value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,+)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] =  value O d [ i ] ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator -= (int value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,-)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] = d [ i ] O value  ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator -= (double value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,-)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] = d [ i ] O value  ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator *= (int value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,*)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] =  value O d [ i ] ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator *= (double value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,*)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] =  value O d [ i ] ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator /= (int value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,/)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] = d [ i ] O value  ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

N::Matrix & N::Matrix::operator /= (double value)
{
  nKickOut ( size () <= 0 , ME )                           ;
  MatrixDataType * mdt = (MatrixDataType *)data()          ;
  int rows    = mdt->rows                                  ;
  int columns = mdt->columns                               ;
  int total   = rows * columns                             ;
  nKickOut ( total , ME )                                  ;
  #define SX(TYPE) OP(TYPE,/)
  #define OP(TYPE,O)                                       \
    if (total>0)                                         { \
      TYPE * d = (TYPE *)array()                         ; \
      nFullLoop ( i , total ) d [ i ] =  d [ i ] O value ; \
    }
  switch  ( mdt->mtype )                                   {
    case Cpp::Char                                         :
      SX(char)                                             ;
    break                                                  ;
    case Cpp::Byte                                         :
      SX(unsigned char)                                    ;
    break                                                  ;
    case Cpp::Short                                        :
      SX(short)                                            ;
    break                                                  ;
    case Cpp::UShort                                       :
      SX(unsigned short)                                   ;
    break                                                  ;
    case Cpp::Integer                                      :
      SX(int)                                              ;
    break                                                  ;
    case Cpp::UInt                                         :
      SX(unsigned int)                                     ;
    break                                                  ;
    case Cpp::LongLong                                     :
      SX(long long)                                        ;
    break                                                  ;
    case Cpp::ULongLong                                    :
      SX(unsigned long long)                               ;
    break                                                  ;
    case Cpp::Float                                        :
      SX(float)                                            ;
    break                                                  ;
    case Cpp::Double                                       :
      SX(double)                                           ;
    break                                                  ;
    case Cpp::LDouble                                      :
      SX(long double)                                      ;
    break                                                  ;
    case Cpp::VLong                                        :
    break                                                  ;
    case Cpp::VDouble                                      :
    break                                                  ;
    case Cpp::Rational                                     :
    break                                                  ;
    case Cpp::Pointer                                      :
    break                                                  ;
  }                                                        ;
  #undef  OP
  #undef  SX
  return ME                                                ;
}

bool N::Matrix::swapRows(int i,int j)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int rows    = mdt->rows                          ;
  int columns = mdt->columns                       ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (rows>0 && columns>0)                     {
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
  return true                                      ;
}

bool N::Matrix::swapColumns(int i,int j)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int rows    = mdt->rows                          ;
  int columns = mdt->columns                       ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (rows>0 && columns>0)                     {
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
  return true                                      ;
}

bool N::Matrix::transpose(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int rows    = mdt->rows                          ;
  int columns = mdt->columns                       ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (rows>0 && columns>0)                     {
        gsl_matrix m                               ;
        m.size1 = rows                             ;
        m.size2 = columns                          ;
        m.tda   = columns                          ;
        m.data  = (double *)array()                ;
        m.block = NULL                             ;
        m.owner = 0                                ;
        ::gsl_matrix_transpose ( &m )              ;
        m.size1 = 0                                ;
        m.size2 = 0                                ;
        m.tda   = 0                                ;
        m.data  = NULL                             ;
        m.block = NULL                             ;
        m.owner = 0                                ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (rows>0 && columns>0)                     {
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
  return true                                      ;
}

bool N::Matrix::transpose(const Matrix & T)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int rows    = mdt->rows                          ;
  int columns = mdt->columns                       ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if ( ( rows > 0 ) && ( columns > 0 ) )       {
        (*this) = T                                ;
        transpose ( )                              ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (rows>0 && columns>0)                     {
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
  return true                                      ;
}

bool N::Matrix::inverse(Matrix & T)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int rows    = mdt->rows                          ;
  int columns = mdt->columns                       ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (rows>0 && columns>0)                     {
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if ( ( rows > 0 ) && ( columns > 0 ) )       {
        if ( rows != columns ) return false        ;
        if ( rows != 4       ) return false        ;
#ifdef XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        QMatrix4x4 M44                             ;
        QMatrix4x4 R44                             ;
        float    * v = (float  *) M44 . data ( )   ;
        double   * a = (double *) array      ( )   ;
        bool       inverted = false                ;
        for (int i=0;i<16;i++) v [ i ] = a [ i ]   ;
        R44 = M44 . inverted ( &inverted )         ;
        if ( inverted )                            {
          T . set ( Cpp::Double , 4 , 4 )          ;
          v = (float  *) R44 . data  ( )           ;
          a = (double *) T   . array ( )           ;
          for (int i=0;i<16;i++) a [ i ] = v [ i ] ;
          return true                              ;
        }                                          ;
#endif
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (rows>0 && columns>0)                     {
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
  return false                                     ;
}

QString N::Matrix::toCpp(void)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int total = mdt->rows * mdt->columns             ;
  QString Cpp                                      ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
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
  return Cpp                                       ;
}

QString N::Matrix::toCpp(QString variableName)
{
  MatrixDataType * mdt = (MatrixDataType *)data()  ;
  int total = mdt->rows * mdt->columns             ;
  QString Cpp                                      ;
  switch  ( mdt->mtype )                           {
    case Cpp::Char                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Byte                                 :
      if (total>0)                                 {
        char * d = (char *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Short                                :
      if (total>0)                                 {
        short * d = (short *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UShort                               :
      if (total>0)                                 {
        ushort * d = (ushort *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Integer                              :
      if (total>0)                                 {
        int * d = (int *)array()                   ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::UInt                                 :
      if (total>0)                                 {
        unsigned int * d = (unsigned int *)array() ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LongLong                             :
      if (total>0)                                 {
        TUID * d = (TUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::ULongLong                            :
      if (total>0)                                 {
        SUID * d = (SUID *)array()                 ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Float                                :
      if (total>0)                                 {
        float * d = (float *)array()               ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::Double                               :
      if (total>0)                                 {
        double * d = (double *)array()             ;
        for (int i=0;i<total;i++)                  {
        }                                          ;
      }                                            ;
    break                                          ;
    case Cpp::LDouble                              :
      if (total>0)                                 {
        long double * d = (long double *)array()   ;
        for (int i=0;i<total;i++)                  {
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
  return Cpp                                       ;
}

void N::Matrix::vertical(double * R,double * V)
{
  double * D = (double *)array() ;
  R[0]  = D [  0 ] * V [ 0 ]     ;
  R[0] += D [  4 ] * V [ 1 ]     ;
  R[0] += D [  8 ] * V [ 2 ]     ;
  R[0] += D [ 12 ] * V [ 3 ]     ;
  R[1]  = D [  1 ] * V [ 0 ]     ;
  R[1] += D [  5 ] * V [ 1 ]     ;
  R[1] += D [  9 ] * V [ 2 ]     ;
  R[1] += D [ 13 ] * V [ 3 ]     ;
  R[2]  = D [  2 ] * V [ 0 ]     ;
  R[2] += D [  6 ] * V [ 1 ]     ;
  R[2] += D [ 10 ] * V [ 2 ]     ;
  R[2] += D [ 14 ] * V [ 3 ]     ;
  R[3]  = D [  3 ] * V [ 0 ]     ;
  R[3] += D [  7 ] * V [ 1 ]     ;
  R[3] += D [ 11 ] * V [ 2 ]     ;
  R[3] += D [ 15 ] * V [ 3 ]     ;
}
