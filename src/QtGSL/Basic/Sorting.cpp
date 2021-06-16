#include "qtgsl.h"

void N::Math::Sort(double * data,const size_t stride,size_t n)
{
  ::gsl_sort(data,stride,n) ;
}

void N::Math::Sort(float * data,const size_t stride,size_t n)
{
  ::gsl_sort_float(data,stride,n) ;
}

void N::Math::Sort(int * data,const size_t stride,size_t n)
{
  ::gsl_sort_int(data,stride,n) ;
}

void N::Math::SortIndex(size_t * p,const double * data,size_t stride,size_t n)
{
  ::gsl_sort_index(p,data,stride,n) ;
}

void N::Math::SortIndex(size_t * p,const float * data,size_t stride,size_t n)
{
  ::gsl_sort_float_index(p,data,stride,n) ;
}

void N::Math::SortIndex(size_t * p,const int * data,size_t stride,size_t n)
{
  ::gsl_sort_int_index(p,data,stride,n) ;
}

int N::Math::SortSmallest(double * dest,size_t k,const double * src,size_t stride,size_t n)
{
  return ::gsl_sort_smallest(dest,k,src,stride,n) ;
}

int N::Math::SortSmallest(float * dest,size_t k,const float * src,size_t stride,size_t n)
{
  return ::gsl_sort_float_smallest(dest,k,src,stride,n) ;
}

int N::Math::SortSmallest(int * dest,size_t k,const int * src,size_t stride,size_t n)
{
  return ::gsl_sort_int_smallest(dest,k,src,stride,n) ;
}

int N::Math::SortLargest(double * dest,size_t k,const double * src,size_t stride,size_t n)
{
  return ::gsl_sort_largest(dest,k,src,stride,n) ;
}

int N::Math::SortLargest(float * dest,size_t k,const float * src,size_t stride,size_t n)
{
  return ::gsl_sort_float_largest(dest,k,src,stride,n) ;
}

int N::Math::SortLargest(int * dest,size_t k,const int * src,size_t stride,size_t n)
{
  return ::gsl_sort_int_largest(dest,k,src,stride,n) ;
}

int N::Math::SortSmallestIndex(size_t * p,size_t k,const double * src,size_t stride,size_t n)
{
  return ::gsl_sort_smallest_index(p,k,src,stride,n) ;
}

int N::Math::SortSmallestIndex(size_t * p,size_t k,const float * src,size_t stride,size_t n)
{
  return ::gsl_sort_float_smallest_index(p,k,src,stride,n) ;
}

int N::Math::SortSmallestIndex(size_t * p,size_t k,const int * src,size_t stride,size_t n)
{
  return ::gsl_sort_int_smallest_index(p,k,src,stride,n) ;
}

int N::Math::SortLargestIndex(size_t * p,size_t k,const double * src,size_t stride,size_t n)
{
  return ::gsl_sort_largest_index(p,k,src,stride,n) ;
}

int N::Math::SortLargestIndex(size_t * p,size_t k,const float * src,size_t stride,size_t n)
{
  return ::gsl_sort_float_largest_index(p,k,src,stride,n) ;
}

int N::Math::SortLargestIndex(size_t * p,size_t k,const int * src,size_t stride,size_t n)
{
  return ::gsl_sort_int_largest_index(p,k,src,stride,n) ;
}
