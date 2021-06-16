#include "qtgsl.h"

N::Histogram:: Histogram  (void)
             : histo      (NULL)
             , histoPdf   (NULL)
             , histo2d    (NULL)
             , histo2dPdf (NULL)
{
}

N::Histogram:: Histogram  (int n)
             : histo      (NULL )
             , histoPdf   (NULL )
             , histo2d    (NULL )
             , histo2dPdf (NULL )
{
  allocate(n) ;
}

N::Histogram:: Histogram  (const Histogram & histogram)
             : histo      (NULL                        )
             , histoPdf   (NULL                        )
             , histo2d    (NULL                        )
             , histo2dPdf (NULL                        )
{
  if ( NotNull ( histogram.histo      ))                               {
    if (NotNull(histo     )) ::gsl_histogram_free       ( histo      ) ;
    histo   = ::gsl_histogram_clone   ( histogram.histo   )            ;
  }                                                                    ;
  if ( NotNull ( histogram.histoPdf   ))                               {
    if (NotNull(histoPdf  )) ::gsl_histogram_pdf_free   ( histoPdf   ) ;
    histoPdf = ::gsl_histogram_pdf_alloc(histogram.histoPdf->n)        ;
    ::gsl_histogram_pdf_init(histoPdf,histo)                           ;
  }                                                                    ;
  if ( NotNull ( histogram.histo2d    ))                               {
    if (NotNull(histo2d   )) ::gsl_histogram2d_free     ( histo2d    ) ;
    histo2d = ::gsl_histogram2d_clone ( histogram.histo2d )            ;
  }                                                                    ;
  if ( NotNull ( histogram.histo2dPdf ))                               {
    if (NotNull(histo2dPdf)) ::gsl_histogram2d_pdf_free ( histo2dPdf ) ;
    size_t nx = histogram.histo2dPdf->nx                               ;
    size_t ny = histogram.histo2dPdf->ny                               ;
    histo2dPdf = ::gsl_histogram2d_pdf_alloc(nx,ny)                    ;
    ::gsl_histogram2d_pdf_init(histo2dPdf,histo2d)                     ;
  }                                                                    ;
}

N::Histogram::~Histogram (void)
{
  if (NotNull(histo     )) ::gsl_histogram_free       ( histo      ) ;
  if (NotNull(histoPdf  )) ::gsl_histogram_pdf_free   ( histoPdf   ) ;
  if (NotNull(histo2d   )) ::gsl_histogram2d_free     ( histo2d    ) ;
  if (NotNull(histo2dPdf)) ::gsl_histogram2d_pdf_free ( histo2dPdf ) ;
}

bool N::Histogram::allocate(int n)
{
  if (NotNull(histo)) ::gsl_histogram_free(histo) ;
  histo = ::gsl_histogram_alloc((size_t)n)        ;
  return NotNull(histo)                           ;
}

int N::Histogram::setRanges(const double range[],int size)
{
  if (IsNull(histo)) return 0                                 ;
  return ::gsl_histogram_set_ranges(histo,range,(size_t)size) ;
}

int N::Histogram::uniformRanges(double xmin,double xmax)
{
  if (IsNull(histo)) return 0                                ;
  return ::gsl_histogram_set_ranges_uniform(histo,xmin,xmax) ;
}

int N::Histogram::increment(double x)
{
  if (IsNull(histo)) return 0               ;
  return ::gsl_histogram_increment(histo,x) ;
}

int N::Histogram::accumulate(double x,double weight)
{
  if (IsNull(histo)) return 0                       ;
  return ::gsl_histogram_accumulate(histo,x,weight) ;
}

double N::Histogram::get(int i)
{
  if (IsNull(histo)) return 0                 ;
  return ::gsl_histogram_get(histo,(size_t)i) ;
}

int N::Histogram::getRange(int i,double * lower,double * upper)
{
  if (IsNull(histo)) return 0                                   ;
  return ::gsl_histogram_get_range(histo,(size_t)i,lower,upper) ;
}

double N::Histogram::Max(void)
{
  if (IsNull(histo)) return 0       ;
  return ::gsl_histogram_max(histo) ;
}

double N::Histogram::Min(void)
{
  if (IsNull(histo)) return 0       ;
  return ::gsl_histogram_min(histo) ;
}

int N::Histogram::bins(void)
{
  if (IsNull(histo)) return 0             ;
  return (int)::gsl_histogram_bins(histo) ;
}

void N::Histogram::reset(void)
{
  if (IsNull(histo)) return    ;
  ::gsl_histogram_reset(histo) ;
}

int N::Histogram::find(double x,size_t * i)
{
  if (IsNull(histo)) return 0            ;
  return ::gsl_histogram_find(histo,x,i) ;
}

double N::Histogram::maxValue(void)
{
  if (IsNull(histo)) return 0           ;
  return ::gsl_histogram_max_val(histo) ;
}

double N::Histogram::minValue(void)
{
  if (IsNull(histo)) return 0           ;
  return ::gsl_histogram_min_val(histo) ;
}

double N::Histogram::mean(void)
{
  if (IsNull(histo)) return 0        ;
  return ::gsl_histogram_mean(histo) ;
}

double N::Histogram::sigma(void)
{
  if (IsNull(histo)) return 0         ;
  return ::gsl_histogram_sigma(histo) ;
}

double N::Histogram::sum(void)
{
  if (IsNull(histo)) return 0       ;
  return ::gsl_histogram_sum(histo) ;
}

int N::Histogram::maxBin(void)
{
  if (IsNull(histo)) return 0                ;
  return (int)::gsl_histogram_max_bin(histo) ;
}

int N::Histogram::minBin(void)
{
  if (IsNull(histo)) return 0                ;
  return (int)::gsl_histogram_min_bin(histo) ;
}

int N::Histogram::scale(double scale)
{
  if (IsNull(histo)) return 0               ;
  return ::gsl_histogram_scale(histo,scale) ;
}

int N::Histogram::shift(double offset)
{
  if (IsNull(histo)) return 0                ;
  return ::gsl_histogram_shift(histo,offset) ;
}

bool N::Histogram::equalBins(Histogram & histogram)
{
  if (IsNull(          histo)) return false                       ;
  if (IsNull(histogram.histo)) return false                       ;
  return (1==::gsl_histogram_equal_bins_p(histo,histogram.histo)) ;
}

int N::Histogram::add(Histogram & histogram)
{
  if (IsNull(          histo)) return 0             ;
  if (IsNull(histogram.histo)) return 0             ;
  return ::gsl_histogram_add(histo,histogram.histo) ;
}

int N::Histogram::sub(Histogram & histogram)
{
  if (IsNull(          histo)) return 0             ;
  if (IsNull(histogram.histo)) return 0             ;
  return ::gsl_histogram_sub(histo,histogram.histo) ;
}

int N::Histogram::mul(Histogram & histogram)
{
  if (IsNull(          histo)) return 0             ;
  if (IsNull(histogram.histo)) return 0             ;
  return ::gsl_histogram_mul(histo,histogram.histo) ;
}

int N::Histogram::div(Histogram & histogram)
{
  if (IsNull(          histo)) return 0             ;
  if (IsNull(histogram.histo)) return 0             ;
  return ::gsl_histogram_div(histo,histogram.histo) ;
}

bool N::Histogram::allocatePdf(int n)
{
  if (IsNull(histo)) return false                           ;
  if (NotNull(histoPdf)) ::gsl_histogram_pdf_free(histoPdf) ;
  histoPdf = ::gsl_histogram_pdf_alloc((size_t)n)           ;
  ::gsl_histogram_pdf_init (histoPdf,histo)                 ;
  return NotNull(histoPdf)                                  ;
}

double N::Histogram::sample(double r)
{
  if (IsNull(histo   )) return 0                ;
  if (IsNull(histoPdf)) return 0                ;
  return ::gsl_histogram_pdf_sample(histoPdf,r) ;
}

bool N::Histogram::allocate2d(int nx,int ny)
{
  if (NotNull(histo2d)) ::gsl_histogram2d_free(histo2d)    ;
  histo2d = ::gsl_histogram2d_alloc((size_t)nx,(size_t)ny) ;
  return NotNull(histo2d)                                  ;
}

int N::Histogram::setRanges2d(const double xrange[],int xsize,const double yrange[],int ysize)
{
  if (IsNull(histo2d)) return 0 ;
  return ::gsl_histogram2d_set_ranges(histo2d,xrange,(size_t)xsize,yrange,(size_t)ysize) ;
}

int N::Histogram::uniformRanges2d(double xmin,double xmax,double ymin,double ymax)
{
  if (IsNull(histo2d)) return 0                                            ;
  return ::gsl_histogram2d_set_ranges_uniform(histo2d,xmin,xmax,ymin,ymax) ;
}

int N::Histogram::increment2d(double x,double y)
{
  if (IsNull(histo2d)) return 0                   ;
  return ::gsl_histogram2d_increment(histo2d,x,y) ;
}

int N::Histogram::accumulate2d(double x,double y,double weight)
{
  if (IsNull(histo2d)) return 0                           ;
  return ::gsl_histogram2d_accumulate(histo2d,x,y,weight) ;
}

double N::Histogram::get2d(int i,int j)
{
  if (IsNull(histo2d)) return 0                             ;
  return ::gsl_histogram2d_get(histo2d,(size_t)i,(size_t)j) ;
}

int N::Histogram::getXrange2d(int i,double * xlower,double * xupper)
{
  if (IsNull(histo2d)) return 0                                        ;
  return ::gsl_histogram2d_get_xrange(histo2d,(size_t)i,xlower,xupper) ;
}

int N::Histogram::getYrange2d(int j,double * ylower,double * yupper)
{
  if (IsNull(histo2d)) return 0                                        ;
  return ::gsl_histogram2d_get_yrange(histo2d,(size_t)j,ylower,yupper) ;
}

double N::Histogram::xmax2d(void)
{
  if (IsNull(histo2d)) return 0           ;
  return ::gsl_histogram2d_xmax (histo2d) ;
}

double N::Histogram::xmin2d(void)
{
  if (IsNull(histo2d)) return 0          ;
  return ::gsl_histogram2d_xmin(histo2d) ;
}

int N::Histogram::nx2d(void)
{
  if (IsNull(histo2d)) return 0        ;
  return ::gsl_histogram2d_nx(histo2d) ;
}

int N::Histogram::ny2d(void)
{
  if (IsNull(histo2d)) return 0        ;
  return ::gsl_histogram2d_ny(histo2d) ;
}

double N::Histogram::ymax2d(void)
{
  if (IsNull(histo2d)) return 0          ;
  return ::gsl_histogram2d_ymax(histo2d) ;
}

double N::Histogram::ymin2d(void)
{
  if (IsNull(histo2d)) return 0          ;
  return ::gsl_histogram2d_ymin(histo2d) ;
}

void N::Histogram::reset2d(void)
{
  if (IsNull(histo2d)) return      ;
  ::gsl_histogram2d_reset(histo2d) ;
}

int N::Histogram::find2d(double x,double y,size_t * i,size_t * j)
{
  if (IsNull(histo2d)) return 0                ;
  return ::gsl_histogram2d_find(histo2d,x,y,i,j) ;
}

double N::Histogram::maxValue2d(void)
{
  if (IsNull(histo2d)) return 0             ;
  return ::gsl_histogram2d_max_val(histo2d) ;
}

double N::Histogram::minValue2d(void)
{
  if (IsNull(histo2d)) return 0             ;
  return ::gsl_histogram2d_min_val(histo2d) ;
}

void N::Histogram::maxBin2d(size_t * i,size_t * j)
{
  if (IsNull(histo2d)) return            ;
  ::gsl_histogram2d_max_bin(histo2d,i,j) ;
}

void N::Histogram::minBin2d(size_t * i,size_t * j)
{
  if (IsNull(histo2d)) return            ;
  ::gsl_histogram2d_min_bin(histo2d,i,j) ;
}

double N::Histogram::xmean2d(void)
{
  if (IsNull(histo2d)) return 0           ;
  return ::gsl_histogram2d_xmean(histo2d) ;
}

double N::Histogram::ymean2d(void)
{
  if (IsNull(histo2d)) return 0           ;
  return ::gsl_histogram2d_ymean(histo2d) ;
}

double N::Histogram::xsigma2d(void)
{
  if (IsNull(histo2d)) return 0            ;
  return ::gsl_histogram2d_xsigma(histo2d) ;
}

double N::Histogram::ysigma2d(void)
{
  if (IsNull(histo2d)) return 0            ;
  return ::gsl_histogram2d_ysigma(histo2d) ;
}

double N::Histogram::cov2d(void)
{
  if (IsNull(histo2d)) return 0         ;
  return ::gsl_histogram2d_cov(histo2d) ;
}

double N::Histogram::sum2d(void)
{
  if (IsNull(histo2d)) return 0         ;
  return ::gsl_histogram2d_sum(histo2d) ;
}

int N::Histogram::scale2d(double scale)
{
  if (IsNull(histo2d)) return 0                 ;
  return ::gsl_histogram2d_scale(histo2d,scale) ;
}

int N::Histogram::shift2d(double offset)
{
  if (IsNull(histo2d)) return 0                  ;
  return ::gsl_histogram2d_shift(histo2d,offset) ;
}

bool N::Histogram::equalBins2d(Histogram & histogram)
{
  if (IsNull(          histo2d)) return false                           ;
  if (IsNull(histogram.histo2d)) return false                           ;
  return (1==::gsl_histogram2d_equal_bins_p(histo2d,histogram.histo2d)) ;
}

int N::Histogram::add2d(Histogram & histogram)
{
  if (IsNull(          histo2d)) return 0                 ;
  if (IsNull(histogram.histo2d)) return 0                 ;
  return ::gsl_histogram2d_add(histo2d,histogram.histo2d) ;
}

int N::Histogram::sub2d(Histogram & histogram)
{
  if (IsNull(          histo2d)) return 0                 ;
  if (IsNull(histogram.histo2d)) return 0                 ;
  return ::gsl_histogram2d_sub(histo2d,histogram.histo2d) ;
}

int N::Histogram::mul2d(Histogram & histogram)
{
  if (IsNull(          histo2d)) return 0                 ;
  if (IsNull(histogram.histo2d)) return 0                 ;
  return ::gsl_histogram2d_mul(histo2d,histogram.histo2d) ;
}

int N::Histogram::div2d(Histogram & histogram)
{
  if (IsNull(          histo2d)) return 0                 ;
  if (IsNull(histogram.histo2d)) return 0                 ;
  return ::gsl_histogram2d_div(histo2d,histogram.histo2d) ;
}

bool N::Histogram::allocatePdf2d(int nx,int ny)
{
  if (IsNull(histo2d)) return false                               ;
  if (NotNull(histo2dPdf)) ::gsl_histogram2d_pdf_free(histo2dPdf) ;
  histo2dPdf = ::gsl_histogram2d_pdf_alloc((size_t)nx,(size_t)ny) ;
  ::gsl_histogram2d_pdf_init (histo2dPdf,histo2d)                 ;
  return NotNull(histo2dPdf)                                      ;
}

int N::Histogram::sample2d(double r1,double r2,double * x,double * y)
{
  if (IsNull(histo2d   )) return 0                          ;
  if (IsNull(histo2dPdf)) return 0                          ;
  return ::gsl_histogram2d_pdf_sample(histo2dPdf,r1,r2,x,y) ;
}
