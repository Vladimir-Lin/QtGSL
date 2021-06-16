#include "qtgsl.h"

N::Random ::  Random (unsigned long int seed)
{
  qType = NULL                                             ;
  Quasi = NULL                                             ;
  Type  = (gsl_rng_type *)::gsl_rng_default                ;
  if (NotNull(Type))                                       {
    Generator = ::gsl_rng_alloc ( Type )                   ;
    if (NotNull(Generator))                                {
      if (seed>0)                                          {
        ::gsl_rng_set ( Generator , seed                 ) ;
      } else                                               {
        ::gsl_rng_set ( Generator , gsl_rng_default_seed ) ;
      }                                                    ;
    }                                                      ;
  } else Generator = NULL                                  ;
}

N::Random ::  Random (gsl_rng_type * type,unsigned long int seed)
{
  qType = NULL                                             ;
  Quasi = NULL                                             ;
  Type  = type                                             ;
  if (NotNull(Type))                                       {
    Generator = ::gsl_rng_alloc ( Type )                   ;
    if (NotNull(Generator))                                {
      if (seed>0)                                          {
        ::gsl_rng_set ( Generator , seed                 ) ;
      } else                                               {
        ::gsl_rng_set ( Generator , gsl_rng_default_seed ) ;
      }                                                    ;
    }                                                      ;
  } else Generator = NULL                                  ;
}

N::Random :: Random (gsl_qrng_type * type,unsigned int dimension)
{
  Type      = NULL                                 ;
  Generator = NULL                                 ;
  qType     = type                                 ;
  if (NotNull(qType))                              {
    Quasi = ::gsl_qrng_alloc ( qType , dimension ) ;
  } else Quasi = NULL                              ;
}

N::Random :: ~Random (void)
{
  if (NotNull(Generator))         {
    ::gsl_rng_free  ( Generator ) ;
    Generator = NULL              ;
  }                               ;
  if (NotNull(Quasi))             {
    ::gsl_qrng_free ( Quasi     ) ;
    Quasi     = NULL              ;
  }                               ;
}

const gsl_rng_type ** N::Random :: All (void)
{
  return ::gsl_rng_types_setup ( ) ;
}

QString N::Random :: Name (void)
{
  if (IsNull(Generator)) return ""        ;
  return QString(gsl_rng_name(Generator)) ;
}

unsigned long int N::Random :: Max (void)
{
  if (IsNull(Generator)) return 0 ;
  return ::gsl_rng_max(Generator) ;
}

unsigned long int N::Random :: Min (void)
{
  if (IsNull(Generator)) return 0 ;
  return ::gsl_rng_min(Generator) ;
}

bool N::Random :: State (QByteArray & state)
{
  if (IsNull(Generator)) return false     ;
  void * s = ::gsl_rng_state (Generator)  ;
  size_t n = ::gsl_rng_size  (Generator)  ;
  if (IsNull(s)        ) return false     ;
  if (n<=0             ) return false     ;
  state . resize ( (int)n               ) ;
  memcpy         ( state.data() , s , n ) ;
  return true                             ;
}

bool N::Random :: Create (gsl_rng_type * type,unsigned long int seed)
{
  Type  = type                                             ;
  if (NotNull(Generator))                                  {
    ::gsl_rng_free  ( Generator )                          ;
    Generator = NULL                                       ;
  }                                                        ;
  if (NotNull(Type))                                       {
    Generator = ::gsl_rng_alloc ( Type )                   ;
    if (NotNull(Generator))                                {
      if (seed>0)                                          {
        ::gsl_rng_set ( Generator , seed                 ) ;
      } else                                               {
        ::gsl_rng_set ( Generator , gsl_rng_default_seed ) ;
      }                                                    ;
    }                                                      ;
  } else Generator = NULL                                  ;
  return ( Generator != NULL )                             ;
}

unsigned long int N::Random :: Get (void)
{
  if (IsNull(Generator)) return 0 ;
  return ::gsl_rng_get(Generator) ;
}

unsigned long int N::Random :: Get (unsigned long int n)
{
  if (IsNull(Generator)) return 0                ;
  return ::gsl_rng_uniform_int ( Generator , n ) ;
}

double N::Random :: Uniform (void)
{
  if (IsNull(Generator)) return -1           ;
  return ::gsl_rng_uniform     ( Generator ) ;
}

double N::Random :: Positive (void)
{
  if (IsNull(Generator)) return -1           ;
  return ::gsl_rng_uniform_pos ( Generator ) ;
}

bool N::Random :: Create (gsl_qrng_type * type,unsigned int dimension)
{
  qType     = type                                 ;
  if (NotNull(Quasi))                              {
    ::gsl_qrng_free  ( Quasi )                     ;
    Quasi = NULL                                   ;
  }                                                ;
  if (NotNull(qType))                              {
    Quasi = ::gsl_qrng_alloc ( qType , dimension ) ;
  } else Quasi = NULL                              ;
  return ( Quasi != NULL )                         ;
}

int N::Random :: QuasiGet (double x[])
{
  if (IsNull(Quasi)) return 0    ;
  return ::gsl_qrng_get(Quasi,x) ;
}

QString N::Random :: QuasiName (void)
{
  if (IsNull(Quasi)) return ""         ;
  return QString(gsl_qrng_name(Quasi)) ;
}

bool N::Random :: QuasiState (QByteArray & state)
{
  if (IsNull(Quasi)) return false         ;
  void * s = ::gsl_qrng_state (Quasi)     ;
  size_t n = ::gsl_qrng_size  (Quasi)     ;
  if (IsNull(s)        ) return false     ;
  if (n<=0             ) return false     ;
  state . resize ( (int)n               ) ;
  memcpy         ( state.data() , s , n ) ;
  return true                             ;
}

void N::Random :: QuasiReset (void)
{
  if (IsNull(Quasi)) return ;
  ::gsl_qrng_init (Quasi)   ;
}

N::Random & N::Random :: operator = (Random & source)
{
  Type  = source . Type                            ;
  qType = source . qType                           ;
  if (NotNull(Generator))                          {
    ::gsl_rng_free  ( Generator )                  ;
    Generator = NULL                               ;
  }                                                ;
  if (NotNull(Quasi))                              {
    ::gsl_qrng_free  ( Quasi )                     ;
    Quasi = NULL                                   ;
  }                                                ;
  if (NotNull(source.Generator))                   {
    Generator = ::gsl_rng_clone (source.Generator) ;
  }                                                ;
  if (NotNull(source.Quasi))                       {
    Quasi     = ::gsl_qrng_clone(source.Quasi    ) ;
  }                                                ;
  return ME                                        ;
}

double N::Random :: Gaussian (double sigma)
{
  if (IsNull(Generator)) return 0                 ;
  return ::gsl_ran_gaussian ( Generator , sigma ) ;
}

double N::Random :: GaussianPDF (double x, double sigma)
{
  return ::gsl_ran_gaussian_pdf ( x , sigma ) ;
}

double N::Random :: GaussianZiggurat (double sigma)
{
  if (IsNull(Generator)) return 0                          ;
  return ::gsl_ran_gaussian_ziggurat ( Generator , sigma ) ;
}

double N::Random :: GaussianRatioMethod (double sigma)
{
  if (IsNull(Generator)) return 0                              ;
  return ::gsl_ran_gaussian_ratio_method ( Generator , sigma ) ;
}

double N::Random :: UnitGaussian (void)
{
  if (IsNull(Generator)) return 0          ;
  return ::gsl_ran_ugaussian ( Generator ) ;
}

double N::Random :: UnitGaussianPDF (double x)
{
  return ::gsl_ran_ugaussian_pdf (x) ;
}

double N::Random :: UnitGaussianRatioMethod (void)
{
  if (IsNull(Generator)) return 0                       ;
  return ::gsl_ran_ugaussian_ratio_method ( Generator ) ;
}

double N::Random :: CdfGaussianP (double x, double sigma)
{
  return ::gsl_cdf_gaussian_P (x,sigma) ;
}

double N::Random :: CdfGaussianQ (double x, double sigma)
{
  return ::gsl_cdf_gaussian_Q (x,sigma) ;
}

double N::Random :: CdfGaussianPinv (double P, double sigma)
{
  return ::gsl_cdf_gaussian_Pinv (P,sigma) ;
}

double N::Random :: CdfGaussianQinv (double Q, double sigma)
{
  return ::gsl_cdf_gaussian_Qinv (Q,sigma) ;
}

double N::Random :: CdfUnitGaussianP (double x)
{
  return ::gsl_cdf_ugaussian_P (x) ;
}

double N::Random :: CdfUnitGaussianQ (double x)
{
  return ::gsl_cdf_ugaussian_Q (x) ;
}

double N::Random :: CdfUnitGaussianPinv (double P)
{
  return ::gsl_cdf_ugaussian_Pinv (P) ;
}

double N::Random :: CdfUnitGaussianQinv (double Q)
{
  return ::gsl_cdf_ugaussian_Qinv (Q) ;
}

double N::Random :: GaussianTail (double a,double sigma)
{
  if (IsNull(Generator)) return 0                         ;
  return ::gsl_ran_gaussian_tail ( Generator , a ,sigma ) ;
}

double N::Random :: GaussianTailPDF (double x,double a,double sigma)
{
  return ::gsl_ran_gaussian_tail_pdf ( x , a , sigma ) ;
}

double N::Random :: UnitGaussianTail (double a)
{
  if (IsNull(Generator)) return 0                   ;
  return ::gsl_ran_ugaussian_tail ( Generator , a ) ;
}

double N::Random :: UnitGaussianTailPDF (double x,double a)
{
  return ::gsl_ran_ugaussian_tail_pdf ( x , a ) ;
}

bool N::Random :: BivariateGaussian (
       double   sigma_x           ,
       double   sigma_y           ,
       double   rho               ,
       double & x                 ,
       double & y                 )
{
  if (IsNull(Generator)) return 0 ;
  ::gsl_ran_bivariate_gaussian    (
      Generator                   ,
      sigma_x                     ,
      sigma_y                     ,
      rho                         ,
      &x                          ,
      &y                        ) ;
  return true                     ;
}

double N::Random :: BivariateGaussianPDF (
         double    x                   ,
         double    y                   ,
         double    sigma_x             ,
         double    sigma_y             ,
         double    rho                 )
{
  return ::gsl_ran_bivariate_gaussian_pdf (x,y,sigma_x,sigma_y,rho) ;
}

double N::Random :: Exponential (double mu)
{
  if (IsNull(Generator)) return 0                 ;
  return ::gsl_ran_exponential ( Generator , mu ) ;
}

double N::Random :: ExponentialPDF (double x, double mu)
{
  return ::gsl_ran_exponential_pdf ( x , mu ) ;
}

double N::Random :: CdfExponentialP (double x, double mu)
{
  return ::gsl_cdf_exponential_P ( x , mu ) ;
}

double N::Random :: CdfExponentialQ (double x, double mu)
{
  return ::gsl_cdf_exponential_Q ( x , mu ) ;
}

double N::Random :: CdfExponentialPinv (double P, double mu)
{
  return ::gsl_cdf_exponential_Pinv ( P , mu ) ;
}

double N::Random :: CdfExponentialQinv (double Q, double mu)
{
  return ::gsl_cdf_exponential_Qinv ( Q , mu ) ;
}

double N::Random :: Laplace (double a)
{
  if (IsNull(Generator)) return 0            ;
  return ::gsl_ran_laplace ( Generator , a ) ;
}

double N::Random :: LaplacePDF (double x, double a)
{
  return ::gsl_ran_laplace_pdf ( x , a ) ;
}

double N::Random :: CdfLaplaceP (double x, double a)
{
  return ::gsl_cdf_laplace_P ( x , a ) ;
}

double N::Random :: CdfLaplaceQ (double x, double a)
{
  return ::gsl_cdf_laplace_Q ( x , a ) ;
}

double N::Random :: CdfLaplacePinv (double P, double a)
{
  return ::gsl_cdf_laplace_Pinv ( P , a ) ;
}

double N::Random :: CdfLaplaceQinv (double Q, double a)
{
  return ::gsl_cdf_laplace_Qinv ( Q , a ) ;
}

double N::Random :: ExpPow (double a,double b)
{
  if (IsNull(Generator)) return 0               ;
  return ::gsl_ran_exppow ( Generator , a , b ) ;
}

double N::Random :: ExpPowPDF (double x,double a,double b)
{
  return ::gsl_ran_exppow_pdf ( x , a , b ) ;
}

double N::Random :: CdfExpPowP (double x,double a,double b)
{
  return ::gsl_cdf_exppow_P ( x , a , b ) ;
}

double N::Random :: CdfExpPowQ (double x,double a,double b)
{
  return ::gsl_cdf_exppow_Q ( x , a , b ) ;
}

double N::Random :: Cauchy (double a)
{
  if (IsNull(Generator)) return 0           ;
  return ::gsl_ran_cauchy ( Generator , a ) ;
}

double N::Random :: CauchyPDF (double x,double a)
{
  return ::gsl_ran_cauchy_pdf ( x , a ) ;
}

double N::Random :: CdfCauchyP (double x,double a)
{
  return ::gsl_cdf_cauchy_P ( x , a ) ;
}

double N::Random :: CdfCauchyQ (double x,double a)
{
  return ::gsl_cdf_cauchy_Q ( x , a ) ;
}

double N::Random :: CdfCauchyPinv (double P,double a)
{
  return ::gsl_cdf_cauchy_Pinv ( P , a ) ;
}

double N::Random :: CdfCauchyQinv (double Q,double a)
{
  return ::gsl_cdf_cauchy_Qinv ( Q , a ) ;
}

double N::Random :: Rayleigh (double sigma)
{
  if (IsNull(Generator)) return 0                 ;
  return ::gsl_ran_rayleigh ( Generator , sigma ) ;
}

double N::Random :: RayleighPDF (double x,double sigma)
{
  return ::gsl_ran_rayleigh_pdf ( x , sigma ) ;
}

double N::Random :: CdfRayleighP (double x,double sigma)
{
  return ::gsl_cdf_rayleigh_P ( x , sigma ) ;
}

double N::Random :: CdfRayleighQ (double x,double sigma)
{
  return ::gsl_cdf_rayleigh_Q ( x , sigma ) ;
}

double N::Random :: CdfRayleighPinv (double P,double sigma)
{
  return ::gsl_cdf_rayleigh_Pinv ( P , sigma ) ;
}

double N::Random :: CdfRayleighQinv (double Q,double sigma)
{
  return ::gsl_cdf_rayleigh_Qinv ( Q , sigma ) ;
}

double N::Random :: RayleighTail (double a,double sigma)
{
  if (IsNull(Generator)) return 0                          ;
  return ::gsl_ran_rayleigh_tail ( Generator , a , sigma ) ;
}

double N::Random :: RayleighTailPDF (double x,double a,double sigma)
{
  return ::gsl_ran_rayleigh_tail_pdf ( x , a , sigma ) ;
}

double N::Random :: Landau (void)
{
  if (IsNull(Generator)) return 0       ;
  return ::gsl_ran_landau ( Generator ) ;
}

double N::Random :: LandauPDF (double x)
{
  return ::gsl_ran_landau_pdf ( x ) ;
}

double N::Random :: Levy (double c,double alpha)
{
  if (IsNull(Generator)) return 0                 ;
  return ::gsl_ran_levy ( Generator , c , alpha ) ;
}

double N::Random :: LevySkew (double c,double alpha,double beta)
{
  if (IsNull(Generator)) return 0                             ;
  return ::gsl_ran_levy_skew ( Generator , c , alpha , beta ) ;
}

double N::Random :: Gamma (double a,double b)
{
  if (IsNull(Generator)) return 0              ;
  return ::gsl_ran_gamma ( Generator , a , b ) ;
}

double N::Random :: GammaKnuth (double a,double b)
{
  if (IsNull(Generator)) return 0                    ;
  return ::gsl_ran_gamma_knuth ( Generator , a , b ) ;
}

double N::Random :: GammaKnuthPDF (double x,double a,double b)
{
  return ::gsl_ran_gamma_pdf ( x , a , b ) ;
}

double N::Random :: CdfGammaP (double x,double a,double b)
{
  return ::gsl_cdf_gamma_P ( x , a , b ) ;
}

double N::Random :: CdfGammaQ (double x,double a,double b)
{
  return ::gsl_cdf_gamma_Q ( x , a , b ) ;
}

double N::Random :: CdfGammaPinv (double P,double a,double b)
{
  return ::gsl_cdf_gamma_Pinv ( P , a , b ) ;
}

double N::Random :: CdfGammaQinv (double Q,double a,double b)
{
  return ::gsl_cdf_gamma_Qinv ( Q , a , b ) ;
}

double N::Random :: Flat (double a,double b)
{
  if (IsNull(Generator)) return 0             ;
  return ::gsl_ran_flat ( Generator , a , b ) ;
}

double N::Random :: FlatPDF (double x,double a,double b)
{
  return ::gsl_ran_flat_pdf ( x , a , b ) ;
}

double N::Random :: CdfFlatP (double x,double a,double b)
{
  return ::gsl_cdf_flat_P ( x , a , b ) ;
}

double N::Random :: CdfFlatQ (double x,double a,double b)
{
  return ::gsl_cdf_flat_Q ( x , a , b ) ;
}

double N::Random :: CdfFlatPinv (double P,double a,double b)
{
  return ::gsl_cdf_flat_Pinv ( P , a , b ) ;
}

double N::Random :: CdfFlatQinv (double Q,double a,double b)
{
  return ::gsl_cdf_flat_Qinv ( Q , a , b ) ;
}

double N::Random :: LogNormal (double a,double b)
{
  if (IsNull(Generator)) return 0                  ;
  return ::gsl_ran_lognormal ( Generator , a , b ) ;
}

double N::Random :: LogNormalPDF (double x,double a,double b)
{
  return ::gsl_ran_lognormal_pdf ( x , a , b ) ;
}

double N::Random :: CdfLogNormalP (double x,double a,double b)
{
  return ::gsl_cdf_lognormal_P ( x , a , b ) ;
}

double N::Random :: CdfLogNormalQ (double x,double a,double b)
{
  return ::gsl_cdf_lognormal_Q ( x , a , b ) ;
}

double N::Random :: CdfLogNormalPinv (double P,double a,double b)
{
  return ::gsl_cdf_lognormal_Pinv ( P , a , b ) ;
}

double N::Random :: CdfLogNormalQinv (double Q,double a,double b)
{
  return ::gsl_cdf_lognormal_Qinv ( Q , a , b ) ;
}

double N::Random :: ChiSquared (double nu)
{
  if (IsNull(Generator)) return 0           ;
  return ::gsl_ran_chisq ( Generator , nu ) ;
}

double N::Random :: ChiSquaredPDF (double x,double nu)
{
  return ::gsl_ran_chisq_pdf ( x , nu ) ;
}

double N::Random :: CdfChiSquaredP (double x,double nu)
{
  return ::gsl_cdf_chisq_P ( x , nu ) ;
}

double N::Random :: CdfChiSquaredQ (double x,double nu)
{
  return ::gsl_cdf_chisq_Q ( x , nu ) ;
}

double N::Random :: CdfChiSquaredPinv (double P,double nu)
{
  return ::gsl_cdf_chisq_Pinv ( P , nu ) ;
}

double N::Random :: CdfChiSquaredQinv (double Q,double nu)
{
  return ::gsl_cdf_chisq_Qinv ( Q , nu ) ;
}

double N::Random :: Fdist (double a,double b)
{
  if (IsNull(Generator)) return 0              ;
  return ::gsl_ran_fdist ( Generator , a , b ) ;
}

double N::Random :: FdistPDF (double x,double a,double b)
{
  return ::gsl_ran_fdist_pdf ( x , a , b ) ;
}

double N::Random :: CdfFdistP (double x,double a,double b)
{
  return ::gsl_cdf_fdist_P ( x , a , b ) ;
}

double N::Random :: CdfFdistQ (double x,double a,double b)
{
  return ::gsl_cdf_fdist_Q ( x , a , b ) ;
}

double N::Random :: CdfFdistPinv (double P,double a,double b)
{
  return ::gsl_cdf_fdist_Pinv ( P , a , b ) ;
}

double N::Random :: CdfFdistQinv (double Q,double a,double b)
{
  return ::gsl_cdf_fdist_Qinv ( Q , a , b ) ;
}

double N::Random :: Tdist (double a)
{
  if (IsNull(Generator)) return 0          ;
  return ::gsl_ran_tdist ( Generator , a ) ;
}

double N::Random :: TdistPDF (double x,double a)
{
  return ::gsl_ran_tdist_pdf ( x , a ) ;
}

double N::Random :: CdfTdistP (double x,double a)
{
  return ::gsl_cdf_tdist_P ( x , a ) ;
}

double N::Random :: CdfTdistQ (double x,double a)
{
  return ::gsl_cdf_tdist_Q ( x , a ) ;
}

double N::Random :: CdfTdistPinv (double P,double a)
{
  return ::gsl_cdf_tdist_Pinv ( P , a ) ;
}

double N::Random :: CdfTdistQinv (double Q,double a)
{
  return ::gsl_cdf_tdist_Qinv ( Q , a ) ;
}

double N::Random :: Beta (double a,double b)
{
  if (IsNull(Generator)) return 0             ;
  return ::gsl_ran_beta ( Generator , a , b ) ;
}

double N::Random :: BetaPDF (double x,double a,double b)
{
  return ::gsl_ran_beta_pdf ( x , a , b ) ;
}

double N::Random :: CdfBetaP (double x,double a,double b)
{
  return ::gsl_cdf_beta_P ( x , a , b ) ;
}

double N::Random :: CdfBetaQ (double x,double a,double b)
{
  return ::gsl_cdf_beta_Q ( x , a , b ) ;
}

double N::Random :: CdfBetaPinv (double P,double a,double b)
{
  return ::gsl_cdf_beta_Pinv ( P , a , b ) ;
}

double N::Random :: CdfBetaQinv (double Q,double a,double b)
{
  return ::gsl_cdf_beta_Qinv ( Q , a , b ) ;
}

double N::Random :: Logistic (double a)
{
  if (IsNull(Generator)) return 0             ;
  return ::gsl_ran_logistic ( Generator , a ) ;
}

double N::Random :: LogisticPDF (double x,double a)
{
  return ::gsl_ran_logistic_pdf ( x , a ) ;
}

double N::Random :: CdfLogisticP (double x,double a)
{
  return ::gsl_cdf_logistic_P ( x , a ) ;
}

double N::Random :: CdfLogisticQ (double x,double a)
{
  return ::gsl_cdf_logistic_Q ( x , a ) ;
}

double N::Random :: CdfLogisticPinv (double P,double a)
{
  return ::gsl_cdf_logistic_Pinv ( P , a ) ;
}

double N::Random :: CdfLogisticQinv (double Q,double a)
{
  return ::gsl_cdf_logistic_Qinv ( Q , a ) ;
}

double N::Random :: Pareto (double a,double b)
{
  if (IsNull(Generator)) return 0               ;
  return ::gsl_ran_pareto ( Generator , a , b ) ;
}

double N::Random :: ParetoPDF (double x,double a,double b)
{
  return ::gsl_ran_pareto_pdf ( x , a , b ) ;
}

double N::Random :: CdfParetoP (double x,double a,double b)
{
  return ::gsl_cdf_pareto_P ( x , a , b ) ;
}

double N::Random :: CdfParetoQ (double x,double a,double b)
{
  return ::gsl_cdf_pareto_Q ( x , a , b ) ;
}

double N::Random :: CdfParetoPinv (double P,double a,double b)
{
  return ::gsl_cdf_pareto_Pinv ( P , a , b ) ;
}

double N::Random :: CdfParetoQinv (double Q,double a,double b)
{
  return ::gsl_cdf_pareto_Qinv ( Q , a , b ) ;
}

double N::Random :: Weibull (double a,double b)
{
  if (IsNull(Generator)) return 0               ;
  return ::gsl_ran_weibull ( Generator , a , b ) ;
}

double N::Random :: WeibullPDF (double x,double a,double b)
{
  return ::gsl_ran_weibull_pdf ( x , a , b ) ;
}

double N::Random :: CdfWeibullP (double x,double a,double b)
{
  return ::gsl_cdf_weibull_P ( x , a , b ) ;
}

double N::Random :: CdfWeibullQ (double x,double a,double b)
{
  return ::gsl_cdf_weibull_Q ( x , a , b ) ;
}

double N::Random :: CdfWeibullPinv (double P,double a,double b)
{
  return ::gsl_cdf_weibull_Pinv ( P , a , b ) ;
}

double N::Random :: CdfWeibullQinv (double Q,double a,double b)
{
  return ::gsl_cdf_weibull_Qinv ( Q , a , b ) ;
}

double N::Random :: Gumbell (double a,double b)
{
  if (IsNull(Generator)) return 0               ;
  return ::gsl_ran_gumbel1 ( Generator , a , b ) ;
}

double N::Random :: GumbellPDF (double x,double a,double b)
{
  return ::gsl_ran_gumbel1_pdf ( x , a , b ) ;
}

double N::Random :: CdfGumbellP (double x,double a,double b)
{
  return ::gsl_cdf_gumbel1_P ( x , a , b ) ;
}

double N::Random :: CdfGumbellQ (double x,double a,double b)
{
  return ::gsl_cdf_gumbel1_Q ( x , a , b ) ;
}

double N::Random :: CdfGumbellPinv (double P,double a,double b)
{
  return ::gsl_cdf_gumbel1_Pinv ( P , a , b ) ;
}

double N::Random :: CdfGumbellQinv (double Q,double a,double b)
{
  return ::gsl_cdf_gumbel1_Qinv ( Q , a , b ) ;
}

double N::Random :: Gumbell2 (double a,double b)
{
  if (IsNull(Generator)) return 0                ;
  return ::gsl_ran_gumbel2 ( Generator , a , b ) ;
}

double N::Random :: Gumbell2PDF (double x,double a,double b)
{
  return ::gsl_ran_gumbel2_pdf ( x , a , b ) ;
}

double N::Random :: CdfGumbell2P (double x,double a,double b)
{
  return ::gsl_cdf_gumbel2_P ( x , a , b ) ;
}

double N::Random :: CdfGumbell2Q (double x,double a,double b)
{
  return ::gsl_cdf_gumbel2_Q ( x , a , b ) ;
}

double N::Random :: CdfGumbell2Pinv (double P,double a,double b)
{
  return ::gsl_cdf_gumbel2_Pinv ( P , a , b ) ;
}

double N::Random :: CdfGumbell2Qinv (double Q,double a,double b)
{
  return ::gsl_cdf_gumbel2_Qinv ( Q , a , b ) ;
}

unsigned int N::Random :: Poisson (double mu)
{
  if (IsNull(Generator)) return 0             ;
  return ::gsl_ran_poisson ( Generator , mu ) ;
}

double N::Random :: PoissonPDF (unsigned int k,double mu)
{
  return ::gsl_ran_poisson_pdf(k,mu) ;
}

double N::Random :: CdfPoissonP (unsigned int k,double mu)
{
  return ::gsl_cdf_poisson_P(k,mu) ;
}

double N::Random :: CdfPoissonQ (unsigned int k,double mu)
{
  return ::gsl_cdf_poisson_Q(k,mu) ;
}

unsigned int N::Random :: Bernoulli (double p)
{
  if (IsNull(Generator)) return 0              ;
  return ::gsl_ran_bernoulli ( Generator , p ) ;
}

double N::Random :: BernoulliPDF (unsigned int k, double p)
{
  return ::gsl_ran_bernoulli_pdf (k,p) ;
}

unsigned int N::Random :: Binomial (double p,unsigned int n)
{
  if (IsNull(Generator)) return 0                 ;
  return ::gsl_ran_binomial ( Generator , p , n ) ;
}

double N::Random :: BinomialPDF (unsigned int k,double p,unsigned int n)
{
  return ::gsl_ran_binomial_pdf (k,p,n) ;
}

double N::Random :: CdfBinomialP (unsigned int k,double p,unsigned int n)
{
  return ::gsl_cdf_binomial_P (k,p,n) ;
}

double N::Random :: CdfBinomialQ (unsigned int k,double p,unsigned int n)
{
  return ::gsl_cdf_binomial_Q (k,p,n) ;
}

void N::Random :: Multinomial (
       size_t       K       ,
       unsigned int N       ,
       const double p[]     ,
       unsigned int n[]     )
{
  if (IsNull(Generator)) return            ;
  ::gsl_ran_multinomial(Generator,K,N,p,n) ;
}

double N::Random :: MultinomialPDF (
         size_t             K     ,
         const double       p[]   ,
         const unsigned int n[]   )
{
  return ::gsl_ran_multinomial_pdf (K,p,n) ;
}

double N::Random :: MultinomialLnPDF (
         size_t             K      ,
         const double       p[]    ,
         const unsigned int n[]    )
{
  return ::gsl_ran_multinomial_lnpdf (K,p,n) ;
}

unsigned int N::Random :: NegativeBinomial (double p,double n)
{
  if (IsNull(Generator)) return 0                   ;
  return ::gsl_ran_negative_binomial(Generator,p,n) ;
}

double N::Random :: NegativeBinomialPDF (unsigned int k,double p,double n)
{
  return ::gsl_ran_negative_binomial_pdf (k,p,n) ;
}

double N::Random :: CdfNegativeBinomialP (unsigned int k,double p,double n)
{
  return ::gsl_cdf_negative_binomial_P (k,p,n) ;
}

double N::Random :: CdfNegativeBinomialQ (unsigned int k,double p,double n)
{
  return ::gsl_cdf_negative_binomial_Q (k,p,n) ;
}

unsigned int N::Random :: Pascal (double p,unsigned int n)
{
  if (IsNull(Generator)) return 0        ;
  return ::gsl_ran_pascal(Generator,p,n) ;
}

double N::Random :: PascalPDF (unsigned int k,double p,unsigned int n)
{
  return ::gsl_ran_pascal_pdf (k,p,n) ;
}

double N::Random :: CdfPascalP (unsigned int k,double p,unsigned int n)
{
  return ::gsl_cdf_pascal_P (k,p,n) ;
}

double N::Random :: CdfPascalQ (unsigned int k,double p,unsigned int n)
{
  return ::gsl_cdf_pascal_Q (k,p,n) ;
}

unsigned int N::Random :: Geometric (double p)
{
  if (IsNull(Generator)) return 0         ;
  return ::gsl_ran_geometric(Generator,p) ;
}

double N::Random :: GeometricPDF (unsigned int k,double p)
{
  return ::gsl_ran_geometric_pdf (k,p) ;
}

double N::Random :: CdfGeometricP (unsigned int k,double p)
{
  return ::gsl_cdf_geometric_P (k,p) ;
}

double N::Random :: CdfGeometricQ (unsigned int k,double p)
{
  return ::gsl_cdf_geometric_Q (k,p) ;
}

unsigned int N::Random :: Hypergeometric (
               unsigned int n1         ,
               unsigned int n2         ,
               unsigned int t          )
{
  if (IsNull(Generator)) return 0                    ;
  return ::gsl_ran_hypergeometric(Generator,n1,n2,t) ;
}

double N::Random :: HypergeometricPDF (
         unsigned int k             ,
         unsigned int n1            ,
         unsigned int n2            ,
         unsigned int t             )
{
  return ::gsl_ran_hypergeometric_pdf (k,n1,n2,t) ;
}

double N::Random :: CdfHypergeometricP         (unsigned int k           ,
                                         unsigned int n1          ,
                                         unsigned int n2          ,
                                         unsigned int t         )
{
  return ::gsl_cdf_hypergeometric_P (k,n1,n2,t) ;
}

double N::Random :: CdfHypergeometricQ (
         unsigned int k              ,
         unsigned int n1             ,
         unsigned int n2             ,
         unsigned int t              )
{
  return ::gsl_cdf_hypergeometric_Q (k,n1,n2,t) ;
}

unsigned int N::Random :: Logarithmic (double p)
{
  if (IsNull(Generator)) return 0           ;
  return ::gsl_ran_logarithmic(Generator,p) ;
}

double N::Random :: LogarithmicPDF (unsigned int k, double p)
{
  return ::gsl_ran_logarithmic_pdf (k,p) ;
}

void N::Random :: Dirichlet (int K,const double alpha[],double theta[])
{
  if (IsNull(Generator)) return                         ;
  ::gsl_ran_dirichlet ( Generator , K , alpha , theta ) ;
}

double N::Random :: DirichletPDF (int K,const double alpha[],const double theta[])
{
  return ::gsl_ran_dirichlet_pdf ( K , alpha , theta ) ;
}

double N::Random :: DirichletLnPDF (int K,const double alpha[],const double theta[])
{
  return ::gsl_ran_dirichlet_lnpdf ( K , alpha , theta ) ;
}

void N::Random :: SphericalDir2D (double & x,double & y)
{
  if (IsNull(Generator)) return     ;
  ::gsl_ran_dir_2d(Generator,&x,&y) ;
}

void N::Random :: SphericalDir2DTrigMethod (double & x,double & y)
{
  if (IsNull(Generator)) return                  ;
  ::gsl_ran_dir_2d_trig_method (Generator,&x,&y) ;
}

void N::Random :: SphericalDir3D (double & x,double & y,double & z)
{
  if (IsNull(Generator)) return         ;
  ::gsl_ran_dir_3d (Generator,&x,&y,&z) ;
}

void N::Random :: SphericalDirN (int n, double * x)
{
  if (IsNull(Generator)) return    ;
  ::gsl_ran_dir_nd (Generator,n,x) ;
}

gsl_ran_discrete_t * N::Random :: PrepareDiscrete (int K,const double * P)
{
  return ::gsl_ran_discrete_preproc(K,P) ;
}

size_t N::Random :: Discrete (const gsl_ran_discrete_t * g)
{
  if (IsNull(Generator)) return 0             ;
  return ::gsl_ran_discrete ( Generator , g ) ;
}

double N::Random :: DiscretePDF (size_t k,const gsl_ran_discrete_t * g)
{
  return ::gsl_ran_discrete_pdf ( k , g ) ;
}

void N::Random :: DiscreteFree (gsl_ran_discrete_t * g)
{
  ::gsl_ran_discrete_free (g) ;
}

void N::Random :: Shuffle (void * base,size_t n,size_t size)
{
  if (IsNull(Generator)) return                    ;
  ::gsl_ran_shuffle ( Generator , base, n , size ) ;
}

void N::Random :: Choose (void * dest,size_t k,void * src,size_t n,size_t size)
{
  if (IsNull(Generator)) return                              ;
  ::gsl_ran_choose ( Generator , dest , k , src , n , size ) ;
}

void N::Random :: Sample (void * dest,size_t k,void * src,size_t n,size_t size)
{
  if (IsNull(Generator)) return                              ;
  ::gsl_ran_sample ( Generator , dest , k , src , n , size ) ;
}
