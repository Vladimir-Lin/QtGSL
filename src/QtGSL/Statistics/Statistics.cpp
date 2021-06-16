#include "qtgsl.h"

double N::Math::Mean(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_mean(data,stride,n) ;
}

double N::Math::Variance(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_variance(data,stride,n) ;
}

double N::Math::VarianceMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_variance_m(data,stride,n,mean) ;
}

double N::Math::StandardDeviation(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_sd(data,stride,n) ;
}

double N::Math::StandardDeviationMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_sd_m(data,stride,n,mean) ;
}

double N::Math::TotalSumSquares(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_tss(data,stride,n) ;
}

double N::Math::TotalSumSquaresMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_tss_m(data,stride,n,mean) ;
}

double N::Math::VarianceFixedMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_variance_with_fixed_mean(data,stride,n,mean) ;
}

double N::Math::StandardDeviationFixedMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_sd_with_fixed_mean(data,stride,n,mean) ;
}

double N::Math::AbsoluteDeviation(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_absdev(data,stride,n) ;
}

double N::Math::AbsoluteDeviationMean(const double data[],size_t stride,size_t n,double mean)
{
  return ::gsl_stats_absdev_m(data,stride,n,mean) ;
}

double N::Math::Skew(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_skew(data,stride,n) ;
}

double N::Math::SkewMeanSD(const double data[],size_t stride,size_t n,double mean,double sd)
{
  return ::gsl_stats_skew_m_sd(data,stride,n,mean,sd) ;
}

double N::Math::Kurtosis(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_kurtosis(data,stride,n) ;
}

double N::Math::KurtosisMeanSD(const double data[],size_t stride,size_t n,double mean,double sd)
{
  return ::gsl_stats_kurtosis_m_sd(data,stride,n,mean,sd) ;
}

double N::Math::Lag1AutoCorrelation(const double data[],const size_t stride,const size_t n)
{
  return ::gsl_stats_lag1_autocorrelation(data,stride,n) ;
}

double N::Math::Lag1AutoCorrelationMean(const double data[],const size_t stride,const size_t n,const double mean)
{
  return ::gsl_stats_lag1_autocorrelation_m(data,stride,n,mean) ;
}

double N::Math::Covariance(const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n)
{
  return ::gsl_stats_covariance(data1,stride1,data2,stride2,n) ;
}

double N::Math::CovarianceMean(const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n,const double mean1,const double mean2)
{
  return ::gsl_stats_covariance_m(data1,stride1,data2,stride2,n,mean1,mean2) ;
}

double N::Math::Correlation(const double data1[],const size_t stride1,const double data2[],const size_t stride2,const size_t n)
{
  return ::gsl_stats_correlation(data1,stride1,data2,stride2,n) ;
}

double N::Math::WeightedMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wmean(w,wstride,data,stride,n) ;
}

double N::Math::WeightedVariance(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wvariance(w,wstride,data,stride,n) ;
}

double N::Math::WeightedVarianceMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n,double wmean)
{
  return ::gsl_stats_wvariance_m(w,wstride,data,stride,n,wmean) ;
}

double N::Math::WeightedSd(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wsd(w,wstride,data,stride,n) ;
}

double N::Math::WeightedSdMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n,double wmean)
{
  return ::gsl_stats_wsd_m(w,wstride,data,stride,n,wmean) ;
}

double N::Math::WeightedVarianceFixedMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n,const double mean)
{
  return ::gsl_stats_wvariance_with_fixed_mean(w,wstride,data,stride,n,mean) ;
}

double N::Math::WeightedSdFixedMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n,const double mean)
{
  return ::gsl_stats_wsd_with_fixed_mean(w,wstride,data,stride,n,mean) ;
}

double N::Math::WeightedTss(const double w[],const size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wtss(w,wstride,data,stride,n) ;
}

double N::Math::WeightedTssMean(const double w[],const size_t wstride,const double data[],size_t stride,size_t n,double wmean)
{
  return ::gsl_stats_wtss_m(w,wstride,data,stride,n,wmean) ;
}

double N::Math::WeightedAbsoluteDeviation(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wabsdev(w,wstride,data,stride,n) ;
}

double N::Math::WeightedAbsoluteDeviationMean(const double w[],size_t wstride,const double data[],size_t stride,size_t n,double wmean)
{
  return ::gsl_stats_wabsdev_m(w,wstride,data,stride,n,wmean) ;
}

double N::Math::WeightedSkew(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wskew(w,wstride,data,stride,n) ;
}

double N::Math::WeightedSkewMeanSd(const double w[],size_t wstride,const double data[],size_t stride,size_t n,double wmean,double wsd)
{
  return ::gsl_stats_wskew_m_sd(w,wstride,data,stride,n,wmean,wsd) ;
}

double N::Math::WeightedKurtosis(const double w[],size_t wstride,const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_wkurtosis(w,wstride,data,stride,n) ;
}

double N::Math::WeightedKurtosisMeanSd(const double w[],size_t wstride,const double data[],size_t stride,size_t n,double wmean,double wsd)
{
  return ::gsl_stats_wkurtosis_m_sd(w,wstride,data,stride,n,wmean,wsd) ;
}

double N::Math::MaxValue(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_max(data,stride,n) ;
}

double N::Math::MinValue(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_min(data,stride,n) ;
}

void N::Math::MinMax(double * min,double * max,const double data[],size_t stride,size_t n)
{
  ::gsl_stats_minmax(min,max,data,stride,n) ;
}

size_t N::Math::MaxIndex(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_max_index(data,stride,n) ;
}

size_t N::Math::MinIndex(const double data[],size_t stride,size_t n)
{
  return ::gsl_stats_min_index(data,stride,n) ;
}

void N::Math::MinMaxIndex(size_t * min_index,size_t * max_index,const double data[],size_t stride,size_t n)
{
  ::gsl_stats_minmax_index(min_index,max_index,data,stride,n) ;
}

double N::Math::MedianFromSorted(const double sorted_data[],size_t stride,size_t n)
{
  return ::gsl_stats_median_from_sorted_data(sorted_data,stride,n) ;
}

double N::Math::QuantileFromSorted(const double sorted_data[],size_t stride,size_t n,double f)
{
  return ::gsl_stats_quantile_from_sorted_data(sorted_data,stride,n,f) ;
}
