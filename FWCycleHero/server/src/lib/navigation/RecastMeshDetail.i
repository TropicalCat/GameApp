


































#pragma once





















































































#pragma once






























































































































































































































































































































































































































































































































































































































































































































#pragma region Input Buffer SAL 1 compatibility macros




































































































































































































































































































































































































































































                                                




                                                

















































































































































































































































































































#pragma endregion Input Buffer SAL 1 compatibility macros



































































































































































































































































































































































































































































































































































































































































































































































































































































































































extern "C" {









































































































































































































































    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    

    
    
























































































































































































































































    
    





















































































}





















#pragma once


extern "C" {











































































































































































































































































































































}











#pragma pack(push,8)














#pragma once














#pragma pack(push,8)


extern "C" {


















typedef __w64 unsigned int   uintptr_t;








typedef char *  va_list;

















































































}


#pragma pack(pop)





extern "C" {














































































































































  








































































































































































































  









  
  










   












  









  





























typedef __w64 unsigned int   size_t;






typedef size_t rsize_t;








typedef __w64 int            intptr_t;

















typedef __w64 int            ptrdiff_t;










typedef unsigned short wint_t;
typedef unsigned short wctype_t;




















typedef int errno_t;



typedef __w64 long __time32_t;   




typedef __int64 __time64_t;     







typedef __time64_t time_t;      






















































  void __cdecl _invalid_parameter(  const wchar_t *,   const wchar_t *,   const wchar_t *, unsigned int, uintptr_t);





 __declspec(noreturn)
void __cdecl _invoke_watson(  const wchar_t *,   const wchar_t *,   const wchar_t *, unsigned int, uintptr_t);



  

















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;
typedef struct threadmbcinfostruct * pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct
{
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;


typedef struct localerefcount {
        char *locale;
        wchar_t *wlocale;
        int *refcount;
        int *wrefcount;
} locrefcount;

typedef struct threadlocaleinfostruct {
        int refcount;
        unsigned int lc_codepage;
        unsigned int lc_collate_cp;
        unsigned int lc_time_cp;
        locrefcount lc_category[6];
        int lc_clike;
        int mb_cur_max;
        int * lconv_intl_refcount;
        int * lconv_num_refcount;
        int * lconv_mon_refcount;
        struct lconv * lconv;
        int * ctype1_refcount;
        unsigned short * ctype1;
        const unsigned short * pctype;
        const unsigned char * pclmap;
        const unsigned char * pcumap;
        struct __lc_time_data * lc_time_curr;
        wchar_t * locale_name[6];
} threadlocinfo;




}































#pragma pack(pop)
















#pragma once












































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































extern "C" {














































































  unsigned int __cdecl _clearfp(void);
#pragma warning(push)
#pragma warning(disable: 4141)
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_controlfp_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  unsigned int __cdecl _controlfp(  unsigned int _NewValue,  unsigned int _Mask);
#pragma warning(pop)
  void __cdecl _set_controlfp(  unsigned int _NewValue,   unsigned int _Mask);
  errno_t __cdecl _controlfp_s(  unsigned int *_CurrentState,   unsigned int _NewValue,   unsigned int _Mask);
  unsigned int __cdecl _statusfp(void);
  void __cdecl _fpreset(void);


  void __cdecl _statusfp2(  unsigned int *_X86_status,   unsigned int *_SSE2_status);









































































  unsigned int __cdecl _control87(  unsigned int _NewValue,  unsigned int _Mask);

  int __cdecl __control87_2(  unsigned int _NewValue,   unsigned int _Mask,
                                    unsigned int* _X86_cw,   unsigned int* _Sse2_cw);




   extern int * __cdecl __fpecode(void);






























   double __cdecl _copysign(  double _Number,   double _Sign);
   double __cdecl _chgsign(  double _X);
   double __cdecl _scalb(  double _X,   long _Y);
   double __cdecl _logb(  double _X);
   double __cdecl _nextafter(  double _X,   double _Y);
   int    __cdecl _finite(  double _X);
   int    __cdecl _isnan(  double _X);
   int    __cdecl _fpclass(  double _X);

























  void __cdecl fpreset(void);
































































}





































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#pragma pack(push,8)


extern "C" {









struct _exception {
        int type;       
        char *name;     
        double arg1;    
        double arg2;    
        double retval;  
        } ;










struct _complex {
        double x,y; 
        } ;










typedef float float_t;
typedef double double_t;





















 extern double _HUGE;





























































































void __cdecl _fperrraise(  int _Except);

short  __cdecl _dclass(  double _X);
short  __cdecl _ldclass(  long double _X);
short  __cdecl _fdclass(  float _X);

int  __cdecl _dsign(  double _X);
int  __cdecl _ldsign(  long double _X);
int  __cdecl _fdsign(  float _X);

int  __cdecl _dpcomp(  double _X,   double _Y);
int  __cdecl _ldpcomp(  long double _X,   long double _Y);
int  __cdecl _fdpcomp(  float _X,   float _Y);

short  __cdecl _dtest(  double *_Px);
short  __cdecl _ldtest(  long double *_Px);
short  __cdecl _fdtest(  float *_Px);

short  __cdecl _d_int(  double *_Px,   short _Xexp);
short  __cdecl _ld_int(  long double *_Px,   short _Xexp);
short  __cdecl _fd_int(  float *_Px,   short _Xexp);

short  __cdecl _dscale(  double *_Px,   long _Lexp);
short  __cdecl _ldscale(  long double *_Px,   long _Lexp);
short  __cdecl _fdscale(  float *_Px,   long _Lexp);

short   __cdecl _dunscale(  short *_Pex,   double *_Px);
short  __cdecl _ldunscale(  short *_Pex,   long double *_Px);
short  __cdecl _fdunscale(  short *_Pex,   float *_Px);

short  __cdecl _dexp(  double *_Px,   double _Y,   long _Eoff);
short  __cdecl _ldexp(  long double *_Px,   long double _Y,   long _Eoff);
short  __cdecl _fdexp(  float *_Px,   float _Y,   long _Eoff);

short  __cdecl _dnorm(  unsigned short *_Ps);
short  __cdecl _fdnorm(  unsigned short *_Ps);

double __cdecl _dpoly(  double _X,   const double *_Tab,   int _N);
long double __cdecl _ldpoly(  long double _X,   const long double *_Tab,   int _N);
float __cdecl _fdpoly(  float _X,   const float *_Tab,   int _N);

double  __cdecl _dlog(  double _X,   int _Baseflag);
long double  __cdecl _ldlog(  long double _X,   int _Baseflag);
float  __cdecl _fdlog(  float _X,   int _Baseflag);

double  __cdecl _dsin(  double _X,   unsigned int _Qoff);
long double  __cdecl _ldsin(  long double _X,   unsigned int _Qoff);
float  __cdecl _fdsin(  float _X,   unsigned int _Qoff);


typedef union
{	
    unsigned short _Sh[8];
    double _Val;
} _double_val;


typedef union
{	
    unsigned short _Sh[8];
    float _Val;
} _float_val;


typedef union
{	
    unsigned short _Sh[8];
    long double _Val;
} _ldouble_val;

typedef union
{	
    unsigned short _Word[8];
    float _Float;
    double _Double;
    long double _Long_double;
} _float_const;

extern const _float_const _Denorm_C,  _Inf_C,  _Nan_C,  _Snan_C, _Hugeval_C;
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C;
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C;

extern const _float_const _Eps_C,  _Rteps_C;
extern const _float_const _FEps_C, _FRteps_C;
extern const _float_const _LEps_C, _LRteps_C;

extern const double _Zero_C, _Xbig_C;
extern const float _FZero_C, _FXbig_C;
extern const long double _LZero_C, _LXbig_C;





























extern "C++" {

inline __declspec(nothrow) int fpclassify(float _X)
{
    return (_fdtest(&_X));
}

inline __declspec(nothrow) int fpclassify(double _X)
{
    return (_dtest(&_X));
}

inline __declspec(nothrow) int fpclassify(long double _X)
{
    return (_ldtest(&_X));
}

inline __declspec(nothrow) bool signbit(float _X)
{
    return (_fdsign(_X) != 0);
}

inline __declspec(nothrow) bool signbit(double _X)
{
    return (_dsign(_X) != 0);
}

inline __declspec(nothrow) bool signbit(long double _X)
{
    return (_ldsign(_X) != 0);
}

inline __declspec(nothrow) int _fpcomp(float _X, float _Y)
{
    return (_fdpcomp(_X, _Y));
}

inline __declspec(nothrow) int _fpcomp(double _X, double _Y)
{
    return (_dpcomp(_X, _Y));
}

inline __declspec(nothrow) int _fpcomp(long double _X, long double _Y)
{
    return (_ldpcomp(_X, _Y));
}

template<class _Trc, class _Tre> struct _Combined_type
{	
    typedef float _Type;	
};

template<> struct _Combined_type<float, double>
{	
    typedef double _Type;
};

template<> struct _Combined_type<float, long double>
{	
    typedef long double _Type;
};

template<class _Ty, class _T2> struct _Real_widened
{	
    typedef long double _Type;	
};

template<> struct _Real_widened<float, float>
{	
    typedef float _Type;
};

template<> struct _Real_widened<float, double>
{	
    typedef double _Type;
};

template<> struct _Real_widened<double, float>
{	
    typedef double _Type;
};

template<> struct _Real_widened<double, double>
{	
    typedef double _Type;
};

template<class _Ty> struct _Real_type
{	
    typedef double _Type;	
};

template<> struct _Real_type<float>
{	
    typedef float _Type;
};

template<> struct _Real_type<long double>
{	
    typedef long double _Type;
};

template<class _T1, class _T2> inline __declspec(nothrow) int _fpcomp(_T1 _X, _T2 _Y)
{	
    typedef typename _Combined_type<float,
        typename _Real_widened<
        typename _Real_type<_T1>::_Type,
        typename _Real_type<_T2>::_Type>::_Type>::_Type _Tw;
    return (_fpcomp((_Tw)_X, (_Tw)_Y));
}

template<class _Ty> inline __declspec(nothrow) bool isfinite(_Ty _X)
{
    return (fpclassify(_X) <= 0);
}

template<class _Ty> inline __declspec(nothrow) bool isinf(_Ty _X)
{
    return (fpclassify(_X) == 1);
}

template<class _Ty> inline __declspec(nothrow) bool isnan(_Ty _X)
{
    return (fpclassify(_X) == 2);
}

template<class _Ty> inline __declspec(nothrow) bool isnormal(_Ty _X)
{
    return (fpclassify(_X) == (-1));
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool isgreater(_Ty1 _X, _Ty2 _Y)
{
    return ((_fpcomp(_X, _Y) & 4) != 0);
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool isgreaterequal(_Ty1 _X, _Ty2 _Y)
{
    return ((_fpcomp(_X, _Y) & (2 | 4)) != 0);
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool isless(_Ty1 _X, _Ty2 _Y)
{
    return ((_fpcomp(_X, _Y) & 1) != 0);
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool islessequal(_Ty1 _X, _Ty2 _Y)
{
    return ((_fpcomp(_X, _Y) & (1 | 2)) != 0);
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool islessgreater(_Ty1 _X, _Ty2 _Y)
{
    return ((_fpcomp(_X, _Y) & (1 | 4)) != 0);
}

template<class _Ty1, class _Ty2> inline __declspec(nothrow) bool isunordered(_Ty1 _X, _Ty2 _Y)
{
    return (_fpcomp(_X, _Y) == 0);
}

}  






int       __cdecl abs(  int _X);
long      __cdecl labs(  long _X);
long long __cdecl llabs(  long long _X);

double  __cdecl acos(  double _X);
 double __cdecl acosh(  double _X);
double  __cdecl asin(  double _X);
 double __cdecl asinh(  double _X);
double  __cdecl atan(  double _X);
 double __cdecl atanh(  double _X);
double  __cdecl atan2(  double _Y,   double _X);

 double __cdecl cbrt(  double _X);
 double __cdecl copysign(  double _X,   double _Y);
double  __cdecl cos(  double _X);
double  __cdecl cosh(  double _X);
 double __cdecl erf(  double _X);
 double __cdecl erfc(  double _X);
double  __cdecl exp(  double _X);
 double __cdecl exp2(  double _X);
 double __cdecl expm1(  double _X);
 double  __cdecl fabs(  double _X);
 double __cdecl fdim(  double _X,   double _Y);
 double __cdecl fma(  double _X,   double _Y,   double _Z);
 double __cdecl fmax(  double _X,   double _Y);
 double __cdecl fmin(  double _X,   double _Y);
double  __cdecl fmod(  double _X,   double _Y);
 int __cdecl ilogb(  double _X);
 double __cdecl lgamma(  double _X);
 long long __cdecl llrint(  double _X);
 long long __cdecl llround(  double _X);
double  __cdecl log(  double _X);
double  __cdecl log10(  double _X);
 double __cdecl log1p(  double _X);
 double __cdecl log2(  double _X);
 double __cdecl logb(  double _X);
 long __cdecl lrint(  double _X);
 long __cdecl lround(  double _X);
 double __cdecl nan(  const char *);
 double __cdecl nearbyint(  double _X);
 double __cdecl nextafter(  double _X,   double _Y);
 double __cdecl nexttoward(  double _X,   long double _Y);
double  __cdecl pow(  double _X,   double _Y);
 double __cdecl remainder(  double _X,   double _Y);
 double __cdecl remquo(  double _X,   double _Y,   int *_Z);
 double __cdecl rint(  double _X);
 double __cdecl round(  double _X);
 double __cdecl scalbln(  double _X,   long _Y);
 double __cdecl scalbn(  double _X,   int _Y);
double  __cdecl sin(  double _X);
double  __cdecl sinh(  double _X);
  double  __cdecl sqrt(  double _X);
double  __cdecl tan(  double _X);
double  __cdecl tanh(  double _X);
 double __cdecl tgamma(  double _X);
 double __cdecl trunc(  double _X);

   double  __cdecl atof(  const char *_String);
   double  __cdecl _atof_l(  const char *_String,   _locale_t _Locale);

 double  __cdecl _cabs(  struct _complex _Complex_value);
 double  __cdecl ceil(  double _X);

   double __cdecl _chgsign (  double _X);
   double __cdecl _copysign (  double _Number,   double _Sign);

 double  __cdecl floor(  double _X);
 double  __cdecl frexp(  double _X,   int * _Y);
 double  __cdecl _hypot(  double _X,   double _Y);
 double  __cdecl _j0(  double _X );
 double  __cdecl _j1(  double _X );
 double  __cdecl _jn(int _X,   double _Y);
 double  __cdecl ldexp(  double _X,   int _Y);




int     __cdecl _matherr(  struct _exception * _Except);


 double  __cdecl modf(  double _X,   double * _Y);
 double  __cdecl _y0(  double _X);
 double  __cdecl _y1(  double _X);
 double  __cdecl _yn(  int _X,   double _Y);

__inline double __cdecl hypot(  double _X,   double _Y)
{
    return _hypot(_X, _Y);
}


 float __cdecl acoshf(  float _X);
 float __cdecl asinhf(  float _X);
 float __cdecl atanhf(  float _X);
 float __cdecl cbrtf(  float _X);
 float  __cdecl _chgsignf(  float _X);
 float __cdecl copysignf(  float _X,   float _Y);
 float  __cdecl _copysignf(  float _Number,   float _Sign);
 float __cdecl erff(  float _X);
 float __cdecl erfcf(  float _X);
 float __cdecl expm1f(  float _X);
 float __cdecl exp2f(  float _X);
 float __cdecl fdimf(  float _X,   float _Y);
 float __cdecl fmaf(  float _X,   float _Y,   float _Z);
 float __cdecl fmaxf(  float _X,   float _Y);
 float __cdecl fminf(  float _X,   float _Y);
 float  __cdecl _hypotf(  float _X,   float _Y);
 int __cdecl ilogbf(  float _X);
 float __cdecl lgammaf(  float _X);
 long long __cdecl llrintf(  float _X);
 long long __cdecl llroundf(  float _X);
 float __cdecl log1pf(  float _X);
 float __cdecl log2f(  float _X);
 float __cdecl logbf(  float _X);
 long __cdecl lrintf(  float _X);
 long __cdecl lroundf(  float _X);
 float __cdecl nanf(  const char *);
 float __cdecl nearbyintf(  float _X);
 float __cdecl nextafterf(  float _X,   float _Y);
 float __cdecl nexttowardf(  float _X,   long double _Y);
 float __cdecl remainderf(  float _X,   float _Y);
 float __cdecl remquof(  float _X,   float _Y,   int *_Z);
 float __cdecl rintf(  float _X);
 float __cdecl roundf(  float _X);
 float __cdecl scalblnf(  float _X,   long _Y);
 float __cdecl scalbnf(  float _X,   int _Y);
 float __cdecl tgammaf(  float _X);
 float __cdecl truncf(  float _X);



 int  __cdecl _set_SSE2_enable(  int _Flag);



































__inline float  __cdecl acosf(  float _X)
{
    return (float)acos(_X);
}

__inline float  __cdecl asinf(  float _X)
{
    return (float)asin(_X);
}

__inline float  __cdecl atan2f(  float _Y,   float _X)
{
    return (float)atan2(_Y, _X);
}

__inline float  __cdecl atanf(  float _X)
{
    return (float)atan(_X);
}

__inline float  __cdecl ceilf(  float _X)
{
    return (float)ceil(_X);
}

__inline float  __cdecl cosf(  float _X)
{
    return (float)cos(_X);
}

__inline float  __cdecl coshf(  float _X)
{
    return (float)cosh(_X);
}

__inline float  __cdecl expf(  float _X)
{
    return (float)exp(_X);
}









__inline float __cdecl fabsf(  float _X)
{
    return (float)fabs(_X);
}










__inline float __cdecl floorf(  float _X)
{
    return (float)floor(_X);
}

__inline float __cdecl fmodf(  float _X,   float _Y)
{
    return (float)fmod(_X, _Y);
}



__inline float __cdecl frexpf(  float _X,   int *_Y)
{
    return (float)frexp(_X, _Y);
}

__inline float __cdecl hypotf(  float _X,   float _Y)
{
    return _hypotf(_X, _Y);
}

__inline float __cdecl ldexpf(  float _X,   int _Y)
{
    return (float)ldexp(_X, _Y);
}















__inline float __cdecl log10f(  float _X)
{
    return (float)log10(_X);
}

__inline float __cdecl logf(  float _X)
{
    return (float)log(_X);
}

__inline float __cdecl modff(  float _X,   float *_Y)
{
    double _F, _I;
    _F = modf(_X, &_I);
    *_Y = (float)_I;
    return (float)_F;
}

__inline float __cdecl powf(  float _X,   float _Y)
{
    return (float)pow(_X, _Y);
}

__inline float __cdecl sinf(  float _X)
{
    return (float)sin(_X);
}

__inline float __cdecl sinhf(  float _X)
{
    return (float)sinh(_X);
}

__inline float __cdecl sqrtf(  float _X)
{
    return (float)sqrt(_X);
}

__inline float __cdecl tanf(  float _X)
{
    return (float)tan(_X);
}

__inline float __cdecl tanhf(  float _X)
{
    return (float)tanh(_X);
}



 long double __cdecl acoshl(  long double _X);

__inline long double __cdecl acosl(  long double _X)
{
    return acos((double)_X);
}

 long double __cdecl asinhl(  long double _X);

__inline long double __cdecl asinl(  long double _X)
{
    return asin((double)_X);
}

__inline long double __cdecl atan2l(  long double _Y,   long double _X)
{
    return atan2((double)_Y, (double)_X);
}

 long double __cdecl atanhl(  long double _X);

__inline long double __cdecl atanl(  long double _X)
{
    return atan((double)_X);
}

 long double __cdecl cbrtl(  long double _X);

__inline long double __cdecl ceill(  long double _X)
{
    return ceil((double)_X);
}

__inline long double __cdecl _chgsignl(  long double _X)
{
    return _chgsign((double)_X);
}

 long double __cdecl copysignl(  long double _X,   long double _Y);

__inline long double __cdecl _copysignl(  long double _X,   long double _Y)
{
    return _copysign((double)_X, (double)_Y);
}

__inline long double __cdecl coshl(  long double _X)
{
    return cosh((double)_X);
}

__inline long double __cdecl cosl(  long double _X)
{
    return cos((double)_X);
}

 long double __cdecl erfl(  long double _X);
 long double __cdecl erfcl(  long double _X);

__inline long double __cdecl expl(  long double _X)
{
    return exp((double)_X);
}

 long double __cdecl exp2l(  long double _X);
 long double __cdecl expm1l(  long double _X);

__inline long double __cdecl fabsl(  long double _X)
{
    return fabs((double)_X);
}

 long double __cdecl fdiml(  long double _X,   long double _Y);

__inline long double __cdecl floorl(  long double _X)
{
    return floor((double)_X);
}

 long double __cdecl fmal(  long double _X,   long double _Y,   long double _Z);
 long double __cdecl fmaxl(  long double _X,   long double _Y);
 long double __cdecl fminl(  long double _X,   long double _Y);

__inline long double __cdecl fmodl(  long double _X,   long double _Y)
{
    return fmod((double)_X, (double)_Y);
}

__inline long double __cdecl frexpl(  long double _X,   int *_Y)
{
    return frexp((double)_X, _Y);
}

 int __cdecl ilogbl(  long double _X);

__inline long double __cdecl _hypotl(  long double _X,   long double _Y)
{
    return _hypot((double)_X, (double)_Y);
}

__inline long double __cdecl hypotl(  long double _X,   long double _Y)
{
    return _hypot((double)_X, (double)_Y);
}

__inline long double __cdecl ldexpl(  long double _X,   int _Y)
{
    return ldexp((double)_X, _Y);
}

 long double __cdecl lgammal(  long double _X);
 long long __cdecl llrintl(  long double _X);
 long long __cdecl llroundl(  long double _X);

__inline long double __cdecl logl(  long double _X)
{
    return log((double)_X);
}

__inline long double __cdecl log10l(  long double _X)
{
    return log10((double)_X);
}

 long double __cdecl log1pl(  long double _X);
 long double __cdecl log2l(  long double _X);
 long double __cdecl logbl(  long double _X);
 long __cdecl lrintl(  long double _X);
 long __cdecl lroundl(  long double _X);

__inline long double __cdecl modfl(  long double _X,   long double *_Y)
{
    double _F, _I;
    _F = modf((double)_X, &_I);
    *_Y = _I;
    return _F;
}
 long double __cdecl nanl(  const char *);
 long double __cdecl nearbyintl(  long double _X);
 long double __cdecl nextafterl(  long double _X,   long double _Y);
 long double __cdecl nexttowardl(  long double _X,   long double _Y);

__inline long double __cdecl powl(  long double _X,   long double _Y)
{
    return pow((double)_X, (double)_Y);
}

 long double __cdecl remainderl(  long double _X,   long double _Y);
 long double __cdecl remquol(  long double _X,   long double _Y,   int *_Z);
 long double __cdecl rintl(  long double _X);
 long double __cdecl roundl(  long double _X);
 long double __cdecl scalblnl(  long double _X,   long _Y);
 long double __cdecl scalbnl(  long double _X,   int _Y);

__inline long double __cdecl sinhl(  long double _X)
{
    return sinh((double)_X);
}

__inline long double __cdecl sinl(  long double _X)
{
    return sin((double)_X);
}

__inline long double __cdecl sqrtl(  long double _X)
{
    return sqrt((double)_X);
}

__inline long double __cdecl tanhl(  long double _X)
{
    return tanh((double)_X);
}

__inline long double __cdecl tanl(  long double _X)
{
    return tan((double)_X);
}

 long double __cdecl tgammal(  long double _X);
 long double __cdecl truncl(  long double _X);






















 extern double HUGE;




__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j0" ". See online help for details."))  double  __cdecl j0(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_j1" ". See online help for details."))  double  __cdecl j1(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_jn" ". See online help for details."))  double  __cdecl jn(  int _X,   double _Y);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y0" ". See online help for details."))  double  __cdecl y0(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_y1" ". See online help for details."))  double  __cdecl y1(  double _X);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_yn" ". See online help for details."))  double  __cdecl yn(  int _X,   double _Y);





}

extern "C++" {

template<class _Ty> inline
        _Ty _Pow_int(_Ty _X, int _Y) throw()
        {unsigned int _N;
        if (_Y >= 0)
                _N = (unsigned int)_Y;
        else
                _N = (unsigned int)(-_Y);
        for (_Ty _Z = _Ty(1); ; _X *= _X)
                {if ((_N & 1) != 0)
                        _Z *= _X;
                if ((_N >>= 1) == 0)
                        return (_Y < 0 ? _Ty(1) / _Z : _Z); }}

inline double __cdecl abs(  double _X) throw()
        {return (fabs(_X)); }
inline double __cdecl pow(  double _X,   int _Y) throw()
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl abs(  float _X) throw()
        {return (fabsf(_X)); }
inline float __cdecl acos(  float _X) throw()
        {return (acosf(_X)); }
inline float __cdecl acosh(  float _X) throw()
        {return (acoshf(_X)); }
inline float __cdecl asin(  float _X) throw()
        {return (asinf(_X)); }
inline float __cdecl asinh(  float _X) throw()
        {return (asinhf(_X)); }
inline float __cdecl atan(  float _X) throw()
        {return (atanf(_X)); }
inline float __cdecl atanh(  float _X) throw()
        {return (atanhf(_X)); }
inline float __cdecl atan2(  float _Y,   float _X) throw()
        {return (atan2f(_Y, _X)); }
inline float __cdecl cbrt(  float _X) throw()
        {return (cbrtf(_X)); }
inline float __cdecl ceil(  float _X) throw()
        {return (ceilf(_X)); }
inline float __cdecl copysign(  float _X,   float _Y) throw()
        {return (copysignf(_X, _Y)); }
inline float __cdecl cos(  float _X) throw()
        {return (cosf(_X)); }
inline float __cdecl cosh(  float _X) throw()
        {return (coshf(_X)); }
inline float __cdecl erf(  float _X) throw()
        {return (erff(_X)); }
inline float __cdecl erfc(  float _X) throw()
        {return (erfcf(_X)); }
inline float __cdecl exp(  float _X) throw()
        {return (expf(_X)); }
inline float __cdecl exp2(  float _X) throw()
        {return (exp2f(_X)); }
inline float __cdecl expm1(  float _X) throw()
        {return (expm1f(_X)); }
inline float __cdecl fabs(  float _X) throw()
        {return (fabsf(_X)); }
inline float __cdecl fdim(  float _X,   float _Y) throw()
        {return (fdimf(_X, _Y)); }
inline float __cdecl floor(  float _X) throw()
        {return (floorf(_X)); }
inline float __cdecl fma(  float _X,   float _Y,   float _Z) throw()
        {return (fmaf(_X, _Y, _Z)); }
inline float __cdecl fmax(  float _X,   float _Y) throw()
        {return (fmaxf(_X, _Y)); }
inline float __cdecl fmin(  float _X,   float _Y) throw()
        {return (fminf(_X, _Y)); }
inline float __cdecl fmod(  float _X,   float _Y) throw()
        {return (fmodf(_X, _Y)); }
inline float __cdecl frexp(  float _X,   int * _Y) throw()
        {return (frexpf(_X, _Y)); }
inline float __cdecl hypot(  float _X,   float _Y) throw()
        {return (hypotf(_X, _Y)); }
inline int __cdecl ilogb(  float _X) throw()
        {return (ilogbf(_X)); }
inline float __cdecl ldexp(  float _X,   int _Y) throw()
        {return (ldexpf(_X, _Y)); }
inline float __cdecl lgamma(  float _X) throw()
        {return (lgammaf(_X)); }
inline long long __cdecl llrint(  float _X) throw()
        {return (llrintf(_X)); }
inline long long __cdecl llround(  float _X) throw()
        {return (llroundf(_X)); }
inline float __cdecl log(  float _X) throw()
        {return (logf(_X)); }
inline float __cdecl log10(  float _X) throw()
        {return (log10f(_X)); }
inline float __cdecl log1p(  float _X) throw()
        {return (log1pf(_X)); }
inline float __cdecl log2(  float _X) throw()
        {return (log2f(_X)); }
inline float __cdecl logb(  float _X) throw()
        {return (logbf(_X)); }
inline long __cdecl lrint(  float _X) throw()
        {return (lrintf(_X)); }
inline long __cdecl lround(  float _X) throw()
        {return (lroundf(_X)); }
inline float __cdecl modf(  float _X,   float * _Y) throw()
        {return (modff(_X, _Y)); }
inline float __cdecl nearbyint(  float _X) throw()
        {return (nearbyintf(_X)); }
inline float __cdecl nextafter(  float _X,   float _Y) throw()
        {return (nextafterf(_X, _Y)); }
inline float __cdecl nexttoward(  float _X,   long double _Y) throw()
        {return (nexttowardf(_X, _Y)); }
inline float __cdecl pow(  float _X,   float _Y) throw()
        {return (powf(_X, _Y)); }
inline float __cdecl pow(  float _X,   int _Y) throw()
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl remainder(  float _X,   float _Y) throw()
        {return (remainderf(_X, _Y)); }
inline float __cdecl remquo(  float _X,   float _Y,   int *_Z) throw()
        {return (remquof(_X, _Y, _Z)); }
inline float __cdecl rint(  float _X) throw()
        {return (rintf(_X)); }
inline float __cdecl round(  float _X) throw()
        {return (roundf(_X)); }
inline float __cdecl scalbln(  float _X,   long _Y) throw()
        {return (scalblnf(_X, _Y)); }
inline float __cdecl scalbn(  float _X,   int _Y) throw()
        {return (scalbnf(_X, _Y)); }
inline float __cdecl sin(  float _X) throw()
        {return (sinf(_X)); }
inline float __cdecl sinh(  float _X) throw()
        {return (sinhf(_X)); }
inline float __cdecl sqrt(  float _X) throw()
        {return (sqrtf(_X)); }
inline float __cdecl tan(  float _X) throw()
        {return (tanf(_X)); }
inline float __cdecl tanh(  float _X) throw()
        {return (tanhf(_X)); }
inline float __cdecl tgamma(  float _X) throw()
        {return (tgammaf(_X)); }
inline float __cdecl trunc(  float _X) throw()
        {return (truncf(_X)); }
inline long double __cdecl abs(  long double _X) throw()
        {return (fabsl(_X)); }
inline long double __cdecl acos(  long double _X) throw()
        {return (acosl(_X)); }
inline long double __cdecl acosh(  long double _X) throw()
        {return (acoshl(_X)); }
inline long double __cdecl asin(  long double _X) throw()
        {return (asinl(_X)); }
inline long double __cdecl asinh(  long double _X) throw()
        {return (asinhl(_X)); }
inline long double __cdecl atan(  long double _X) throw()
        {return (atanl(_X)); }
inline long double __cdecl atanh(  long double _X) throw()
        {return (atanhl(_X)); }
inline long double __cdecl atan2(  long double _Y,   long double _X) throw()
        {return (atan2l(_Y, _X)); }
inline long double __cdecl cbrt(  long double _X) throw()
        {return (cbrtl(_X)); }
inline long double __cdecl ceil(  long double _X) throw()
        {return (ceill(_X)); }
inline long double __cdecl copysign(  long double _X,   long double _Y) throw()
        {return (copysignl(_X, _Y)); }
inline long double __cdecl cos(  long double _X) throw()
        {return (cosl(_X)); }
inline long double __cdecl cosh(  long double _X) throw()
        {return (coshl(_X)); }
inline long double __cdecl erf(  long double _X) throw()
        {return (erfl(_X)); }
inline long double __cdecl erfc(  long double _X) throw()
        {return (erfcl(_X)); }
inline long double __cdecl exp(  long double _X) throw()
        {return (expl(_X)); }
inline long double __cdecl exp2(  long double _X) throw()
        {return (exp2l(_X)); }
inline long double __cdecl expm1(  long double _X) throw()
        {return (expm1l(_X)); }
inline long double __cdecl fabs(  long double _X) throw()
        {return (fabsl(_X)); }
inline long double __cdecl fdim(  long double _X,   long double _Y) throw()
        {return (fdiml(_X, _Y)); }
inline long double __cdecl floor(  long double _X) throw()
        {return (floorl(_X)); }
inline long double __cdecl fma(  long double _X,   long double _Y,   long double _Z) throw()
        {return (fmal(_X, _Y, _Z)); }
inline long double __cdecl fmax(  long double _X,   long double _Y) throw()
        {return (fmaxl(_X, _Y)); }
inline long double __cdecl fmin(  long double _X,   long double _Y) throw()
        {return (fminl(_X, _Y)); }
inline long double __cdecl fmod(  long double _X,   long double _Y) throw()
        {return (fmodl(_X, _Y)); }
inline long double __cdecl frexp(  long double _X,   int * _Y) throw()
        {return (frexpl(_X, _Y)); }
inline long double __cdecl hypot(  long double _X,   long double _Y) throw()
        {return (hypotl(_X, _Y)); }
inline int __cdecl ilogb(  long double _X) throw()
        {return (ilogbl(_X)); }
inline long double __cdecl ldexp(  long double _X,   int _Y) throw()
        {return (ldexpl(_X, _Y)); }
inline long double __cdecl lgamma(  long double _X) throw()
        {return (lgammal(_X)); }
inline long long __cdecl llrint(  long double _X) throw()
        {return (llrintl(_X)); }
inline long long __cdecl llround(  long double _X) throw()
        {return (llroundl(_X)); }
inline long double __cdecl log(  long double _X) throw()
        {return (logl(_X)); }
inline long double __cdecl log10(  long double _X) throw()
        {return (log10l(_X)); }
inline long double __cdecl log1p(  long double _X) throw()
        {return (log1pl(_X)); }
inline long double __cdecl log2(  long double _X) throw()
        {return (log2l(_X)); }
inline long double __cdecl logb(  long double _X) throw()
        {return (logbl(_X)); }
inline long  __cdecl lrint(  long double _X) throw()
        {return (lrintl(_X)); }
inline long  __cdecl lround(  long double _X) throw()
        {return (lroundl(_X)); }
inline long double __cdecl modf(  long double _X,   long double * _Y) throw()
        {return (modfl(_X, _Y)); }
inline long double __cdecl nearbyint(  long double _X) throw()
        {return (nearbyintl(_X)); }
inline long double __cdecl nextafter(  long double _X,   long double _Y) throw()
        {return (nextafterl(_X, _Y)); }
inline long double __cdecl nexttoward(  long double _X,   long double _Y) throw()
        {return (nexttowardl(_X, _Y)); }
inline long double __cdecl pow(  long double _X,   long double _Y) throw()
        {return (powl(_X, _Y)); }
inline long double __cdecl pow(  long double _X,   int _Y) throw()
        {return (_Pow_int(_X, _Y)); }
inline long double __cdecl remainder(  long double _X,   long double _Y) throw()
        {return (remainderl(_X, _Y)); }
inline long double __cdecl remquo(  long double _X,   long double _Y,   int *_Z) throw()
        {return (remquol(_X, _Y, _Z)); }
inline long double __cdecl rint(  long double _X) throw()
        {return (rintl(_X)); }
inline long double __cdecl round(  long double _X) throw()
        {return (roundl(_X)); }
inline long double __cdecl scalbln(  long double _X,   long _Y) throw()
        {return (scalblnl(_X, _Y)); }
inline long double __cdecl scalbn(  long double _X,   int _Y) throw()
        {return (scalbnl(_X, _Y)); }
inline long double __cdecl sin(  long double _X) throw()
        {return (sinl(_X)); }
inline long double __cdecl sinh(  long double _X) throw()
        {return (sinhl(_X)); }
inline long double __cdecl sqrt(  long double _X) throw()
        {return (sqrtl(_X)); }
inline long double __cdecl tan(  long double _X) throw()
        {return (tanl(_X)); }
inline long double __cdecl tanh(  long double _X) throw()
        {return (tanhl(_X)); }
inline long double __cdecl tgamma(  long double _X) throw()
        {return (tgammal(_X)); }
inline long double __cdecl trunc(  long double _X) throw()
        {return (truncl(_X)); }

}


#pragma pack(pop)



























































#pragma once















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































extern "C" {























 void *  __cdecl _memccpy(   void * _Dst,   const void * _Src,   int _Val,   size_t _MaxCount);
   const void *  __cdecl memchr(   const void * _Buf ,   int _Val,   size_t _MaxCount);
   int     __cdecl _memicmp(  const void * _Buf1,   const void * _Buf2,   size_t _Size);
   int     __cdecl _memicmp_l(  const void * _Buf1,   const void * _Buf2,   size_t _Size,   _locale_t _Locale);
  int     __cdecl memcmp(  const void * _Buf1,   const void * _Buf2,   size_t _Size);

 

void *  __cdecl memcpy(  void * _Dst,   const void * _Src,   size_t _Size);

 errno_t  __cdecl memcpy_s(  void * _Dst,   rsize_t _DstSize,   const void * _Src,   rsize_t _MaxCount);


































         
        
        void *  __cdecl memset(  void * _Dst,   int _Val,   size_t _Size);



__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memccpy" ". See online help for details."))  void * __cdecl memccpy(  void * _Dst,   const void * _Src,   int _Val,   size_t _Size);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_memicmp" ". See online help for details."))  int __cdecl memicmp(  const void * _Buf1,   const void * _Buf2,   size_t _Size);





  errno_t __cdecl _strset_s(  char * _Dst,   size_t _DstSize,   int _Value);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strset_s(  char (&_Dest)[_Size],   int _Value) throw() { return _strset_s(_Dest, _Size, _Value); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strset( char *_Dest,  int _Value);

  errno_t __cdecl strcpy_s(  char * _Dst,   rsize_t _SizeInBytes,   const char * _Src);

extern "C++" { template <size_t _Size> inline errno_t __cdecl strcpy_s(  char (&_Dest)[_Size],   const char * _Source) throw() { return strcpy_s(_Dest, _Size, _Source); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "strcpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl strcpy( char *_Dest,  const char * _Source);

  errno_t __cdecl strcat_s(  char * _Dst,   rsize_t _SizeInBytes,   const char * _Src);

extern "C++" { template <size_t _Size> inline errno_t __cdecl strcat_s(char (&_Dest)[_Size],   const char * _Source) throw() { return strcat_s(_Dest, _Size, _Source); } }

__declspec(deprecated("This function or variable may be unsafe. Consider using " "strcat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl strcat( char *_Dest,  const char * _Source);

  int     __cdecl strcmp(  const char * _Str1,   const char * _Str2);
  size_t  __cdecl strlen(  const char * _Str);
  


size_t  __cdecl strnlen(  const char * _Str,   size_t _MaxCount);

  static __inline


size_t  __cdecl strnlen_s(  const char * _Str,   size_t _MaxCount)
{
    return (_Str==0) ? 0 : strnlen(_Str, _MaxCount);
}


  errno_t __cdecl memmove_s(  void * _Dst,   rsize_t _DstSize,   const void * _Src,   rsize_t _MaxCount);


  void *  __cdecl memmove(  void * _Dst,   const void * _Src,   size_t _Size);






   char *  __cdecl _strdup(  const char * _Src);





   const char *  __cdecl strchr(  const char * _Str,   int _Val);
   int     __cdecl _stricmp(   const char * _Str1,    const char * _Str2);
   int     __cdecl _strcmpi(   const char * _Str1,    const char * _Str2);
   int     __cdecl _stricmp_l(   const char * _Str1,    const char * _Str2,   _locale_t _Locale);
   int     __cdecl strcoll(   const char * _Str1,    const  char * _Str2);
   int     __cdecl _strcoll_l(   const char * _Str1,    const char * _Str2,   _locale_t _Locale);
   int     __cdecl _stricoll(   const char * _Str1,    const char * _Str2);
   int     __cdecl _stricoll_l(   const char * _Str1,    const char * _Str2,   _locale_t _Locale);
   int     __cdecl _strncoll  (  const char * _Str1,   const char * _Str2,   size_t _MaxCount);
   int     __cdecl _strncoll_l(  const char * _Str1,   const char * _Str2,   size_t _MaxCount,   _locale_t _Locale);
   int     __cdecl _strnicoll (  const char * _Str1,   const char * _Str2,   size_t _MaxCount);
   int     __cdecl _strnicoll_l(  const char * _Str1,   const char * _Str2,   size_t _MaxCount,   _locale_t _Locale);
   size_t  __cdecl strcspn(   const char * _Str,    const char * _Control);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "_strerror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char *  __cdecl _strerror(  const char * _ErrMsg);
  errno_t __cdecl _strerror_s(  char * _Buf,   size_t _SizeInBytes,   const char * _ErrMsg);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strerror_s(char (&_Buffer)[_Size],   const char * _ErrorMessage) throw() { return _strerror_s(_Buffer, _Size, _ErrorMessage); } }
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char *  __cdecl strerror(  int);

  errno_t __cdecl strerror_s(  char * _Buf,   size_t _SizeInBytes,   int _ErrNum);

extern "C++" { template <size_t _Size> inline errno_t __cdecl strerror_s(char (&_Buffer)[_Size],   int _ErrorMessage) throw() { return strerror_s(_Buffer, _Size, _ErrorMessage); } }
  errno_t __cdecl _strlwr_s(  char * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s(  char (&_String)[_Size]) throw() { return _strlwr_s(_String, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strlwr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strlwr( char *_String);
  errno_t __cdecl _strlwr_s_l(  char * _Str,   size_t _Size,   _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strlwr_s_l(  char (&_String)[_Size],   _locale_t _Locale) throw() { return _strlwr_s_l(_String, _Size, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strlwr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strlwr_l(  char *_String,   _locale_t _Locale);

  errno_t __cdecl strncat_s(  char * _Dst,   rsize_t _SizeInBytes,   const char * _Src,   rsize_t _MaxCount);

extern "C++" { template <size_t _Size> inline errno_t __cdecl strncat_s(  char (&_Dest)[_Size],   const char * _Source,   size_t _Count) throw() { return strncat_s(_Dest, _Size, _Source, _Count); } }
#pragma warning(push)
#pragma warning(disable:6059)

__declspec(deprecated("This function or variable may be unsafe. Consider using " "strncat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl strncat(  char *_Dest,   const char * _Source,   size_t _Count);
#pragma warning(pop)
   int     __cdecl strncmp(  const char * _Str1,   const char * _Str2,   size_t _MaxCount);
   int     __cdecl _strnicmp(  const char * _Str1,   const char * _Str2,   size_t _MaxCount);
   int     __cdecl _strnicmp_l(  const char * _Str1,   const char * _Str2,   size_t _MaxCount,   _locale_t _Locale);

  errno_t __cdecl strncpy_s(  char * _Dst,   rsize_t _SizeInBytes,   const char * _Src,   rsize_t _MaxCount);

extern "C++" { template <size_t _Size> inline errno_t __cdecl strncpy_s(char (&_Dest)[_Size],   const char * _Source,   size_t _Count) throw() { return strncpy_s(_Dest, _Size, _Source, _Count); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "strncpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl strncpy(    char *_Dest,   const char * _Source,   size_t _Count);
  errno_t __cdecl _strnset_s(  char * _Str,   size_t _SizeInBytes,   int _Val,   size_t _MaxCount);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strnset_s(  char (&_Dest)[_Size],   int _Val,   size_t _Count) throw() { return _strnset_s(_Dest, _Size, _Val, _Count); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strnset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strnset(  char *_Dest,   int _Val,   size_t _Count);
   const char *  __cdecl strpbrk(  const char * _Str,   const char * _Control);
   const char *  __cdecl strrchr(  const char * _Str,   int _Ch);
 char *  __cdecl _strrev(  char * _Str);
   size_t  __cdecl strspn(  const char * _Str,   const char * _Control);
     const char *  __cdecl strstr(  const char * _Str,   const char * _SubStr);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "strtok_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char *  __cdecl strtok(  char * _Str,   const char * _Delim);

   char *  __cdecl strtok_s(  char * _Str,   const char * _Delim,     char ** _Context);

  errno_t __cdecl _strupr_s(  char * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s(  char (&_String)[_Size]) throw() { return _strupr_s(_String, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strupr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strupr( char *_String);
  errno_t __cdecl _strupr_s_l(  char * _Str,   size_t _Size, _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _strupr_s_l(  char (&_String)[_Size], _locale_t _Locale) throw() { return _strupr_s_l(_String, _Size, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_strupr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _strupr_l(  char *_String,   _locale_t _Locale);
  size_t  __cdecl strxfrm (    char * _Dst,   const char * _Src,   size_t _MaxCount);
  size_t  __cdecl _strxfrm_l(    char * _Dst,   const char * _Src,   size_t _MaxCount,   _locale_t _Locale);


extern "C++" {


  inline char * __cdecl strchr(  char * _Str,   int _Ch)
        { return (char*)strchr((const char*)_Str, _Ch); }
  inline char * __cdecl strpbrk(  char * _Str,   const char * _Control)
        { return (char*)strpbrk((const char*)_Str, _Control); }
  inline char * __cdecl strrchr(  char * _Str,   int _Ch)
        { return (char*)strrchr((const char*)_Str, _Ch); }
    inline char * __cdecl strstr(  char * _Str,   const char * _SubStr)
        { return (char*)strstr((const char*)_Str, _SubStr); }



  inline void * __cdecl memchr(  void * _Pv,   int _C,   size_t _N)
        { return (void*)memchr((const void*)_Pv, _C, _N); }

}









  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strdup" ". See online help for details."))  char * __cdecl strdup(  const char * _Src);






  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strcmpi" ". See online help for details."))  int __cdecl strcmpi(  const char * _Str1,   const char * _Str2);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_stricmp" ". See online help for details."))  int __cdecl stricmp(  const char * _Str1,   const char * _Str2);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strlwr" ". See online help for details."))  char * __cdecl strlwr(  char * _Str);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnicmp" ". See online help for details."))  int __cdecl strnicmp(  const char * _Str1,   const char * _Str,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strnset" ". See online help for details."))  char * __cdecl strnset(  char * _Str,   int _Val,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strrev" ". See online help for details."))  char * __cdecl strrev(  char * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strset" ". See online help for details."))         char * __cdecl strset(  char * _Str,   int _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_strupr" ". See online help for details."))  char * __cdecl strupr(  char * _Str);













   wchar_t * __cdecl _wcsdup(  const wchar_t * _Str);






  errno_t __cdecl wcscat_s(  wchar_t * _Dst,   rsize_t _SizeInWords,   const wchar_t * _Src);

extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscat_s(wchar_t (&_Dest)[_Size],   const wchar_t * _Source) throw() { return wcscat_s(_Dest, _Size, _Source); } }

__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcscat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl wcscat( wchar_t *_Dest,  const wchar_t * _Source);

 

 const wchar_t * __cdecl wcschr(  const wchar_t * _Str, wchar_t _Ch);
   int __cdecl wcscmp(  const wchar_t * _Str1,   const wchar_t * _Str2);

  errno_t __cdecl wcscpy_s(  wchar_t * _Dst,   rsize_t _SizeInWords,   const wchar_t * _Src);

extern "C++" { template <size_t _Size> inline errno_t __cdecl wcscpy_s(wchar_t (&_Dest)[_Size],   const wchar_t * _Source) throw() { return wcscpy_s(_Dest, _Size, _Source); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcscpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl wcscpy( wchar_t *_Dest,  const wchar_t * _Source);
   size_t __cdecl wcscspn(  const wchar_t * _Str,   const wchar_t * _Control);
   size_t __cdecl wcslen(  const wchar_t * _Str);
  


size_t __cdecl wcsnlen(  const wchar_t * _Src,   size_t _MaxCount);

  static __inline


size_t __cdecl wcsnlen_s(  const wchar_t * _Src,   size_t _MaxCount)
{
    return (_Src == 0) ? 0 : wcsnlen(_Src, _MaxCount);
}


  errno_t __cdecl wcsncat_s(  wchar_t * _Dst,   rsize_t _SizeInWords,   const wchar_t * _Src,   rsize_t _MaxCount);

extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncat_s(  wchar_t (&_Dest)[_Size],   const wchar_t * _Source,   size_t _Count) throw() { return wcsncat_s(_Dest, _Size, _Source, _Count); } }
#pragma warning(push)
#pragma warning(disable:6059)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcsncat_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl wcsncat(  wchar_t *_Dest,   const wchar_t * _Source,   size_t _Count);
#pragma warning(pop)
   int __cdecl wcsncmp(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount);

  errno_t __cdecl wcsncpy_s(  wchar_t * _Dst,   rsize_t _SizeInWords,   const wchar_t * _Src,   rsize_t _MaxCount);

extern "C++" { template <size_t _Size> inline errno_t __cdecl wcsncpy_s(wchar_t (&_Dest)[_Size],   const wchar_t * _Source,   size_t _Count) throw() { return wcsncpy_s(_Dest, _Size, _Source, _Count); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcsncpy_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl wcsncpy(    wchar_t *_Dest,   const wchar_t * _Source,   size_t _Count);
   const wchar_t * __cdecl wcspbrk(  const wchar_t * _Str,   const wchar_t * _Control);
   const wchar_t * __cdecl wcsrchr(  const wchar_t * _Str,   wchar_t _Ch);
   size_t __cdecl wcsspn(  const wchar_t * _Str,   const wchar_t * _Control);
   

 const wchar_t * __cdecl wcsstr(  const wchar_t * _Str,   const wchar_t * _SubStr);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "wcstok_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl wcstok(  wchar_t * _Str,   const wchar_t * _Delim);

   wchar_t * __cdecl wcstok_s(  wchar_t * _Str,   const wchar_t * _Delim,     wchar_t ** _Context);

  __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcserror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcserror(  int _ErrNum);
  errno_t __cdecl _wcserror_s(  wchar_t * _Buf,   size_t _SizeInWords,   int _ErrNum);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcserror_s(wchar_t (&_Buffer)[_Size],   int _Error) throw() { return _wcserror_s(_Buffer, _Size, _Error); } }
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "__wcserror_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl __wcserror(  const wchar_t * _Str);
  errno_t __cdecl __wcserror_s(  wchar_t * _Buffer,   size_t _SizeInWords,   const wchar_t * _ErrMsg);
extern "C++" { template <size_t _Size> inline errno_t __cdecl __wcserror_s(wchar_t (&_Buffer)[_Size],   const wchar_t * _ErrorMessage) throw() { return __wcserror_s(_Buffer, _Size, _ErrorMessage); } }

   int __cdecl _wcsicmp(  const wchar_t * _Str1,   const wchar_t * _Str2);
   int __cdecl _wcsicmp_l(  const wchar_t * _Str1,   const wchar_t * _Str2,   _locale_t _Locale);
   int __cdecl _wcsnicmp(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount);
   int __cdecl _wcsnicmp_l(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount,   _locale_t _Locale);
  errno_t __cdecl _wcsnset_s(  wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Val,   size_t _MaxCount);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsnset_s(  wchar_t (&_Dst)[_Size], wchar_t _Val,   size_t _MaxCount) throw() { return _wcsnset_s(_Dst, _Size, _Val, _MaxCount); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsnset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcsnset(  wchar_t *_Str, wchar_t _Val,   size_t _MaxCount);
 wchar_t * __cdecl _wcsrev(  wchar_t * _Str);
  errno_t __cdecl _wcsset_s(  wchar_t * _Dst,   size_t _SizeInWords,   wchar_t _Value);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsset_s(  wchar_t (&_Str)[_Size], wchar_t _Val) throw() { return _wcsset_s(_Str, _Size, _Val); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsset_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcsset(  wchar_t *_Str, wchar_t _Val);

  errno_t __cdecl _wcslwr_s(  wchar_t * _Str,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s(  wchar_t (&_String)[_Size]) throw() { return _wcslwr_s(_String, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcslwr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcslwr( wchar_t *_String);
  errno_t __cdecl _wcslwr_s_l(  wchar_t * _Str,   size_t _SizeInWords,   _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcslwr_s_l(  wchar_t (&_String)[_Size],   _locale_t _Locale) throw() { return _wcslwr_s_l(_String, _Size, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcslwr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcslwr_l(  wchar_t *_String,   _locale_t _Locale);
  errno_t __cdecl _wcsupr_s(  wchar_t * _Str,   size_t _Size);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s(  wchar_t (&_String)[_Size]) throw() { return _wcsupr_s(_String, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsupr_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcsupr( wchar_t *_String);
  errno_t __cdecl _wcsupr_s_l(  wchar_t * _Str,   size_t _Size,   _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcsupr_s_l(  wchar_t (&_String)[_Size],   _locale_t _Locale) throw() { return _wcsupr_s_l(_String, _Size, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcsupr_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wcsupr_l(  wchar_t *_String,   _locale_t _Locale);
  size_t __cdecl wcsxfrm(    wchar_t * _Dst,   const wchar_t * _Src,   size_t _MaxCount);
  size_t __cdecl _wcsxfrm_l(    wchar_t * _Dst,   const wchar_t *_Src,   size_t _MaxCount,   _locale_t _Locale);
   int __cdecl wcscoll(  const wchar_t * _Str1,   const wchar_t * _Str2);
   int __cdecl _wcscoll_l(  const wchar_t * _Str1,   const wchar_t * _Str2,   _locale_t _Locale);
   int __cdecl _wcsicoll(  const wchar_t * _Str1,   const wchar_t * _Str2);
   int __cdecl _wcsicoll_l(  const wchar_t * _Str1,   const wchar_t *_Str2,   _locale_t _Locale);
   int __cdecl _wcsncoll(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount);
   int __cdecl _wcsncoll_l(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount,   _locale_t _Locale);
   int __cdecl _wcsnicoll(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount);
   int __cdecl _wcsnicoll_l(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount,   _locale_t _Locale);




extern "C++" {
 

        inline wchar_t * __cdecl wcschr(  wchar_t *_Str, wchar_t _Ch)
        {return ((wchar_t *)wcschr((const wchar_t *)_Str, _Ch)); }
  inline wchar_t * __cdecl wcspbrk(  wchar_t *_Str,   const wchar_t *_Control)
        {return ((wchar_t *)wcspbrk((const wchar_t *)_Str, _Control)); }
  inline wchar_t * __cdecl wcsrchr(  wchar_t *_Str,   wchar_t _Ch)
        {return ((wchar_t *)wcsrchr((const wchar_t *)_Str, _Ch)); }
   

        inline wchar_t * __cdecl wcsstr(  wchar_t *_Str,   const wchar_t *_SubStr)
        {return ((wchar_t *)wcsstr((const wchar_t *)_Str, _SubStr)); }
}










  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsdup" ". See online help for details."))  wchar_t * __cdecl wcsdup(  const wchar_t * _Str);









  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicmp" ". See online help for details."))  int __cdecl wcsicmp(  const wchar_t * _Str1,   const wchar_t * _Str2);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnicmp" ". See online help for details."))  int __cdecl wcsnicmp(  const wchar_t * _Str1,   const wchar_t * _Str2,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsnset" ". See online help for details."))  wchar_t * __cdecl wcsnset(  wchar_t * _Str,   wchar_t _Val,   size_t _MaxCount);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsrev" ". See online help for details."))  wchar_t * __cdecl wcsrev(  wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsset" ". See online help for details."))  wchar_t * __cdecl wcsset(  wchar_t * _Str, wchar_t _Val);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcslwr" ". See online help for details."))  wchar_t * __cdecl wcslwr(  wchar_t * _Str);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsupr" ". See online help for details."))  wchar_t * __cdecl wcsupr(  wchar_t * _Str);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_wcsicoll" ". See online help for details."))  int __cdecl wcsicoll(  const wchar_t * _Str1,   const wchar_t * _Str2);













}





















#pragma once




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#pragma once



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#pragma pack(push,8)


extern "C" {




















typedef int (__cdecl * _onexit_t)(void);






















typedef struct _div_t {
        int quot;
        int rem;
} div_t;

typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;

typedef struct _lldiv_t {
        long long quot;
        long long rem;
} lldiv_t;













#pragma pack(4)
typedef struct {
    unsigned char ld[10];
} _LDOUBLE;
#pragma pack()















typedef struct {
        double x;
} _CRT_DOUBLE;

typedef struct {
    float f;
} _CRT_FLOAT;





typedef struct {
        


        long double x;
} _LONGDOUBLE;



#pragma pack(4)
typedef struct {
    unsigned char ld12[12];
} _LDBL12;
#pragma pack()






















 extern int __mb_cur_max;




 int __cdecl ___mb_cur_max_func(void);
 int __cdecl ___mb_cur_max_l_func(_locale_t);






































typedef void (__cdecl *_purecall_handler)(void);


 _purecall_handler __cdecl _set_purecall_handler(  _purecall_handler _Handler);
 _purecall_handler __cdecl _get_purecall_handler(void);



extern "C++"
{





}




typedef void (__cdecl *_invalid_parameter_handler)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);


 _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(  _invalid_parameter_handler _Handler);
 _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);





 extern int * __cdecl _errno(void);


errno_t __cdecl _set_errno(  int _Value);
errno_t __cdecl _get_errno(  int * _Value);


 unsigned long * __cdecl __doserrno(void);


errno_t __cdecl _set_doserrno(  unsigned long _Value);
errno_t __cdecl _get_doserrno(  unsigned long * _Value);


 __declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char ** __cdecl __sys_errlist(void);


 __declspec(deprecated("This function or variable may be unsafe. Consider using " "strerror" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) int * __cdecl __sys_nerr(void);

























 extern int __argc;          
 extern char ** __argv;      
 extern wchar_t ** __wargv;  















 extern char ** _environ;    
 extern wchar_t ** _wenviron;    



__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_pgmptr" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  extern char * _pgmptr;      
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_wpgmptr" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  extern wchar_t * _wpgmptr;  


























errno_t __cdecl _get_pgmptr(  char ** _Value);
errno_t __cdecl _get_wpgmptr(  wchar_t ** _Value);





__declspec(deprecated("This function or variable may be unsafe. Consider using " "_get_fmode" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  extern int _fmode;          






 errno_t __cdecl _set_fmode(  int _Mode);
 errno_t __cdecl _get_fmode(  int * _PMode);






extern "C++"
{
template <typename _CountofType, size_t _SizeOfArray>
char (*__countof_helper( _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

}









 __declspec(noreturn) void __cdecl exit(  int _Code);

 __declspec(noreturn) void __cdecl _exit(  int _Code);
 __declspec(noreturn) void __cdecl abort(void);


 unsigned int __cdecl _set_abort_behavior(  unsigned int _Flags,   unsigned int _Mask);

int       __cdecl abs(  int _X);
long      __cdecl labs(  long _X);
long long __cdecl llabs(  long long _X);

        __int64    __cdecl _abs64(__int64);





































        int    __cdecl atexit(void (__cdecl *)(void));

   double  __cdecl atof(  const char *_String);
   double  __cdecl _atof_l(  const char *_String,   _locale_t _Locale);
    int    __cdecl atoi(  const char *_Str);
   int    __cdecl _atoi_l(  const char *_Str,   _locale_t _Locale);
   long   __cdecl atol(  const char *_Str);
   long   __cdecl _atol_l(  const char *_Str,   _locale_t _Locale);
   long long __cdecl atoll(  const char *_Str);
   long long __cdecl _atoll_l(  const char *_Str,   _locale_t _Locale);



   void * __cdecl bsearch_s(  const void * _Key,   const void * _Base,
          rsize_t _NumOfElements,   rsize_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);

   void * __cdecl bsearch(  const void * _Key,   const void * _Base,
          size_t _NumOfElements,   size_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(const void *, const void *));


 void __cdecl qsort_s(  void * _Base,
          rsize_t _NumOfElements,   rsize_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);

 void __cdecl qsort(  void * _Base,
          size_t _NumOfElements,   size_t _SizeOfElements,
          int (__cdecl * _PtFuncCompare)(const void *, const void *));

          unsigned short __cdecl _byteswap_ushort(  unsigned short _Short);
          unsigned long  __cdecl _byteswap_ulong (  unsigned long _Long);
          unsigned __int64 __cdecl _byteswap_uint64(  unsigned __int64 _Int64);
   div_t  __cdecl div(  int _Numerator,   int _Denominator);


   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_dupenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl getenv(  const char * _VarName);

  errno_t __cdecl getenv_s(  size_t * _ReturnSize,   char * _DstBuf,   rsize_t _DstSize,   const char * _VarName);

extern "C++" { template <size_t _Size> inline errno_t __cdecl getenv_s(  size_t * _ReturnSize, char (&_Dest)[_Size],   const char * _VarName) throw() { return getenv_s(_ReturnSize, _Dest, _Size, _VarName); } }





  errno_t __cdecl _dupenv_s(    char **_PBuffer,   size_t * _PBufferSizeInBytes,   const char * _VarName);






  errno_t __cdecl _itoa_s(  int _Value,   char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _itoa_s(  int _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _itoa_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_itoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _itoa( int _Value,   char *_Dest,  int _Radix);
  errno_t __cdecl _i64toa_s(  __int64 _Val,   char * _DstBuf,   size_t _Size,   int _Radix);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_i64toa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl _i64toa(  __int64 _Val,     char * _DstBuf,   int _Radix);
  errno_t __cdecl _ui64toa_s(  unsigned __int64 _Val,   char * _DstBuf,   size_t _Size,   int _Radix);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ui64toa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl _ui64toa(  unsigned __int64 _Val,     char * _DstBuf,   int _Radix);
   __int64 __cdecl _atoi64(  const char * _String);
   __int64 __cdecl _atoi64_l(  const char * _String,   _locale_t _Locale);
   __int64 __cdecl _strtoi64(  const char * _String,     char ** _EndPtr,   int _Radix);
   __int64 __cdecl _strtoi64_l(  const char * _String,     char ** _EndPtr,   int _Radix,   _locale_t _Locale);
   unsigned __int64 __cdecl _strtoui64(  const char * _String,     char ** _EndPtr,   int _Radix);
   unsigned __int64 __cdecl _strtoui64_l(  const char * _String,     char ** _EndPtr,   int  _Radix,   _locale_t _Locale);
   ldiv_t __cdecl ldiv(  long _Numerator,   long _Denominator);
   lldiv_t __cdecl lldiv(  long long _Numerator,   long long _Denominator);

extern "C++"
{
    inline long abs(long _X) throw()
    {
        return labs(_X);
    }
    inline long long abs(long long _X) throw()
    {
        return llabs(_X);
    }
    inline ldiv_t div(long _A1, long _A2) throw()
    {
        return ldiv(_A1, _A2);
    }
    inline lldiv_t div(long long _A1, long long _A2) throw()
    {
        return lldiv(_A1, _A2);
    }
}

  errno_t __cdecl _ltoa_s(  long _Val,   char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltoa_s(  long _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _ltoa_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _ltoa( long _Value,   char *_Dest,  int _Radix);
   int    __cdecl mblen(    const char * _Ch,   size_t _MaxCount);
   int    __cdecl _mblen_l(    const char * _Ch,   size_t _MaxCount,   _locale_t _Locale);
   size_t __cdecl _mbstrlen(  const char * _Str);
   size_t __cdecl _mbstrlen_l(  const char *_Str,   _locale_t _Locale);
   size_t __cdecl _mbstrnlen(  const char *_Str,   size_t _MaxCount);
   size_t __cdecl _mbstrnlen_l(  const char *_Str,   size_t _MaxCount,   _locale_t _Locale);
 int    __cdecl mbtowc(    wchar_t * _DstCh,     const char * _SrcCh,   size_t _SrcSizeInBytes);
 int    __cdecl _mbtowc_l(    wchar_t * _DstCh,     const char * _SrcCh,   size_t _SrcSizeInBytes,   _locale_t _Locale);
  errno_t __cdecl mbstowcs_s(  size_t * _PtNumOfCharConverted,   wchar_t * _DstBuf,   size_t _SizeInWords,   const char * _SrcBuf,   size_t _MaxCount );
extern "C++" { template <size_t _Size> inline errno_t __cdecl mbstowcs_s(  size_t * _PtNumOfCharConverted,   wchar_t (&_Dest)[_Size],   const char * _Source,   size_t _MaxCount) throw() { return mbstowcs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "mbstowcs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl mbstowcs( wchar_t *_Dest,  const char * _Source,  size_t _MaxCount);

  errno_t __cdecl _mbstowcs_s_l(  size_t * _PtNumOfCharConverted,   wchar_t * _DstBuf,   size_t _SizeInWords,   const char * _SrcBuf,   size_t _MaxCount,   _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _mbstowcs_s_l(  size_t * _PtNumOfCharConverted, wchar_t (&_Dest)[_Size],   const char * _Source,   size_t _MaxCount,   _locale_t _Locale) throw() { return _mbstowcs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_mbstowcs_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _mbstowcs_l(  wchar_t *_Dest,   const char * _Source,   size_t _MaxCount,   _locale_t _Locale);

   int    __cdecl rand(void);




  int    __cdecl _set_error_mode(  int _Mode);

 void   __cdecl srand(  unsigned int _Seed);
   double __cdecl strtod(  const char * _Str,     char ** _EndPtr);
   double __cdecl _strtod_l(  const char * _Str,     char ** _EndPtr,   _locale_t _Locale);
   long   __cdecl strtol(  const char * _Str,     char ** _EndPtr,   int _Radix );
   long   __cdecl _strtol_l(  const char *_Str,     char **_EndPtr,   int _Radix,   _locale_t _Locale);
   long long  __cdecl strtoll(  const char * _Str,     char ** _EndPtr,   int _Radix );
   long long  __cdecl _strtoll_l(  const char * _Str,     char ** _EndPtr,   int _Radix,   _locale_t _Locale );
   unsigned long __cdecl strtoul(  const char * _Str,     char ** _EndPtr,   int _Radix);
   unsigned long __cdecl _strtoul_l(const char * _Str,     char **_EndPtr,   int _Radix,   _locale_t _Locale);
   unsigned long long __cdecl strtoull(  const char * _Str,     char ** _EndPtr,   int _Radix);
   unsigned long long __cdecl _strtoull_l(  const char * _Str,     char ** _EndPtr,   int _Radix,   _locale_t _Locale);
   long double __cdecl strtold(  const char * _Str,     char ** _EndPtr);
   long double __cdecl _strtold_l(  const char * _Str,     char ** _EndPtr,   _locale_t _Locale);
   float __cdecl strtof(  const char * _Str,     char ** _EndPtr);
   float __cdecl _strtof_l(  const char * _Str,     char ** _EndPtr,   _locale_t _Locale);




 int __cdecl system(  const char * _Command);



  errno_t __cdecl _ultoa_s(  unsigned long _Val,   char * _DstBuf,   size_t _Size,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultoa_s(  unsigned long _Value, char (&_Dest)[_Size],   int _Radix) throw() { return _ultoa_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl _ultoa( unsigned long _Value,   char *_Dest,  int _Radix);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "wctomb_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) int    __cdecl wctomb(  char * _MbCh,   wchar_t _WCh);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wctomb_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) int    __cdecl _wctomb_l(    char * _MbCh,   wchar_t _WCh,   _locale_t _Locale);

  errno_t __cdecl wctomb_s(  int * _SizeConverted,   char * _MbCh,   rsize_t _SizeInBytes,   wchar_t _WCh);

  errno_t __cdecl _wctomb_s_l(  int * _SizeConverted,   char * _MbCh,   size_t _SizeInBytes,   wchar_t _WCh,   _locale_t _Locale);
  errno_t __cdecl wcstombs_s(  size_t * _PtNumOfCharConverted,   char * _Dst,   size_t _DstSizeInBytes,   const wchar_t * _Src,   size_t _MaxCountInBytes);
extern "C++" { template <size_t _Size> inline errno_t __cdecl wcstombs_s(  size_t * _PtNumOfCharConverted,   char (&_Dest)[_Size],   const wchar_t * _Source,   size_t _MaxCount) throw() { return wcstombs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "wcstombs_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl wcstombs( char *_Dest,  const wchar_t * _Source,  size_t _MaxCount);
  errno_t __cdecl _wcstombs_s_l(  size_t * _PtNumOfCharConverted,   char * _Dst,   size_t _DstSizeInBytes,   const wchar_t * _Src,   size_t _MaxCountInBytes,   _locale_t _Locale);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wcstombs_s_l(  size_t * _PtNumOfCharConverted,   char (&_Dest)[_Size],   const wchar_t * _Source,   size_t _MaxCount,   _locale_t _Locale) throw() { return _wcstombs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wcstombs_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _wcstombs_l(  char *_Dest,   const wchar_t * _Source,   size_t _MaxCount,   _locale_t _Locale);





























































        __declspec(noalias) __declspec(restrict)    void * __cdecl calloc(   size_t _Count,    size_t _Size);
                     __declspec(noalias)                                                                             void   __cdecl free(    void * _Memory);
        __declspec(noalias) __declspec(restrict)                              void * __cdecl malloc(   size_t _Size);
 
       __declspec(noalias) __declspec(restrict)                           void * __cdecl realloc(    void * _Memory,    size_t _NewSize);
 
       __declspec(noalias) __declspec(restrict)                       void * __cdecl _recalloc(    void * _Memory,    size_t _Count,    size_t _Size);
                     __declspec(noalias)                                                                             void   __cdecl _aligned_free(    void * _Memory);
       __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_malloc(   size_t _Size,   size_t _Alignment);
       __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_malloc(   size_t _Size,   size_t _Alignment,   size_t _Offset);
 
       __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_realloc(    void * _Memory,    size_t _NewSize,   size_t _Alignment);
 
       __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_recalloc(    void * _Memory,    size_t _Count,    size_t _Size,   size_t _Alignment);
 
       __declspec(noalias) __declspec(restrict)                              void * __cdecl _aligned_offset_realloc(    void * _Memory,    size_t _NewSize,   size_t _Alignment,   size_t _Offset);
 
       __declspec(noalias) __declspec(restrict)                       void * __cdecl _aligned_offset_recalloc(    void * _Memory,    size_t _Count,    size_t _Size,   size_t _Alignment,   size_t _Offset);
                                                    size_t __cdecl _aligned_msize(  void * _Memory,   size_t _Alignment,   size_t _Offset);


























  errno_t __cdecl _itow_s (  int _Val,   wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _itow_s(  int _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _itow_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_itow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _itow( int _Value,   wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ltow_s (  long _Val,   wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ltow_s(  long _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _ltow_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _ltow( long _Value,   wchar_t *_Dest,  int _Radix);
  errno_t __cdecl _ultow_s (  unsigned long _Val,   wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ultow_s(  unsigned long _Value, wchar_t (&_Dest)[_Size],   int _Radix) throw() { return _ultow_s(_Value, _Dest, _Size, _Radix); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _ultow( unsigned long _Value,   wchar_t *_Dest,  int _Radix);
   double __cdecl wcstod(  const wchar_t * _Str,     wchar_t ** _EndPtr);
   double __cdecl _wcstod_l(  const wchar_t *_Str,     wchar_t ** _EndPtr,   _locale_t _Locale);
   long   __cdecl wcstol(  const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
   long   __cdecl _wcstol_l(  const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,   _locale_t _Locale);
   long long  __cdecl wcstoll(  const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix);
   long long  __cdecl _wcstoll_l(  const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,   _locale_t _Locale);
   unsigned long __cdecl wcstoul(  const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
   unsigned long __cdecl _wcstoul_l(  const wchar_t *_Str,     wchar_t **_EndPtr, int _Radix,   _locale_t _Locale);
   unsigned long long __cdecl wcstoull(  const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix);
   unsigned long long __cdecl _wcstoull_l(  const wchar_t *_Str,     wchar_t ** _EndPtr, int _Radix,   _locale_t _Locale);
   long double __cdecl wcstold(  const wchar_t * _Str,     wchar_t ** _EndPtr);
   long double __cdecl _wcstold_l(  const wchar_t * _Str,     wchar_t ** _EndPtr,   _locale_t _Locale);
   float __cdecl wcstof(  const wchar_t * _Str,     wchar_t ** _EndPtr);
   float __cdecl _wcstof_l(  const wchar_t * _Str,     wchar_t ** _EndPtr,   _locale_t _Locale);



   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wdupenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) wchar_t * __cdecl _wgetenv(  const wchar_t * _VarName);
  errno_t __cdecl _wgetenv_s(  size_t * _ReturnSize,   wchar_t * _DstBuf,   size_t _DstSizeInWords,   const wchar_t * _VarName);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wgetenv_s(  size_t * _ReturnSize, wchar_t (&_Dest)[_Size],   const wchar_t * _VarName) throw() { return _wgetenv_s(_ReturnSize, _Dest, _Size, _VarName); } }






  errno_t __cdecl _wdupenv_s(    wchar_t **_Buffer,   size_t *_BufferSizeInWords,   const wchar_t *_VarName);







 int __cdecl _wsystem(  const wchar_t * _Command);




   double __cdecl _wtof(  const wchar_t *_Str);
   double __cdecl _wtof_l(  const wchar_t *_Str,   _locale_t _Locale);
   int __cdecl _wtoi(  const wchar_t *_Str);
   int __cdecl _wtoi_l(  const wchar_t *_Str,   _locale_t _Locale);
   long __cdecl _wtol(  const wchar_t *_Str);
   long __cdecl _wtol_l(  const wchar_t *_Str,   _locale_t _Locale);
   long long __cdecl _wtoll(  const wchar_t *_Str);
   long long __cdecl _wtoll_l(  const wchar_t *_Str,   _locale_t _Locale);

  errno_t __cdecl _i64tow_s(  __int64 _Val,   wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_i64tow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) wchar_t * __cdecl _i64tow(  __int64 _Val,     wchar_t * _DstBuf,   int _Radix);
  errno_t __cdecl _ui64tow_s(  unsigned __int64 _Val,   wchar_t * _DstBuf,   size_t _SizeInWords,   int _Radix);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ui64tow_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) wchar_t * __cdecl _ui64tow(  unsigned __int64 _Val,     wchar_t * _DstBuf,   int _Radix);
   __int64   __cdecl _wtoi64(  const wchar_t *_Str);
   __int64   __cdecl _wtoi64_l(  const wchar_t *_Str,   _locale_t _Locale);
   __int64   __cdecl _wcstoi64(  const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
   __int64   __cdecl _wcstoi64_l(  const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix,   _locale_t _Locale);
   unsigned __int64  __cdecl _wcstoui64(  const wchar_t * _Str,     wchar_t ** _EndPtr,   int _Radix);
   unsigned __int64  __cdecl _wcstoui64_l(  const wchar_t *_Str ,     wchar_t ** _EndPtr,   int _Radix,   _locale_t _Locale);


















   char * __cdecl _fullpath(  char * _FullPath,   const char * _Path,   size_t _SizeInBytes);







  errno_t __cdecl _ecvt_s(  char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDights,   int * _PtDec,   int * _PtSign);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _ecvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits,   int * _PtDec,   int * _PtSign) throw() { return _ecvt_s(_Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign); } }
   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ecvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl _ecvt(  double _Val,   int _NumOfDigits,   int * _PtDec,   int * _PtSign);
  errno_t __cdecl _fcvt_s(  char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _fcvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits,   int * _PtDec,   int * _PtSign) throw() { return _fcvt_s(_Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign); } }
   __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl _fcvt(  double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
 errno_t __cdecl _gcvt_s(  char * _DstBuf,   size_t _Size,   double _Val,   int _NumOfDigits);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _gcvt_s(char (&_Dest)[_Size],   double _Value,   int _NumOfDigits) throw() { return _gcvt_s(_Dest, _Size, _Value, _NumOfDigits); } }
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_gcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char * __cdecl _gcvt(  double _Val,   int _NumOfDigits,     char * _DstBuf);

   int __cdecl _atodbl(  _CRT_DOUBLE * _Result,   char * _Str);
   int __cdecl _atoldbl(  _LDOUBLE * _Result,   char * _Str);
   int __cdecl _atoflt(  _CRT_FLOAT * _Result,   const char * _Str);
   int __cdecl _atodbl_l(  _CRT_DOUBLE * _Result,   char * _Str,   _locale_t _Locale);
   int __cdecl _atoldbl_l(  _LDOUBLE * _Result,   char * _Str,   _locale_t _Locale);
   int __cdecl _atoflt_l(  _CRT_FLOAT * _Result,   const char * _Str,   _locale_t _Locale);
          unsigned long __cdecl _lrotl(  unsigned long _Val,   int _Shift);
          unsigned long __cdecl _lrotr(  unsigned long _Val,   int _Shift);
  errno_t   __cdecl _makepath_s(  char * _PathResult,   size_t _SizeInWords,   const char * _Drive,   const char * _Dir,   const char * _Filename,
          const char * _Ext);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _makepath_s(char (&_Path)[_Size],   const char * _Drive,   const char * _Dir,   const char * _Filename,   const char * _Ext) throw() { return _makepath_s(_Path, _Size, _Drive, _Dir, _Filename, _Ext); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_makepath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _makepath(  char *_Path,  const char * _Drive,  const char * _Dir,  const char * _Filename,  const char * _Ext);


























        _onexit_t __cdecl _onexit(  _onexit_t _Func);




 void __cdecl perror(  const char * _ErrMsg);


#pragma warning (push)
#pragma warning (disable:6540) 


   int    __cdecl _putenv(  const char * _EnvString);
  errno_t __cdecl _putenv_s(  const char * _Name,   const char * _Value);


        unsigned int __cdecl _rotl(  unsigned int _Val,   int _Shift);
        unsigned __int64 __cdecl _rotl64(  unsigned __int64 _Val,   int _Shift);
        unsigned int __cdecl _rotr(  unsigned int _Val,   int _Shift);
        unsigned __int64 __cdecl _rotr64(  unsigned __int64 _Val,   int _Shift);
#pragma warning (pop)


 errno_t __cdecl _searchenv_s(  const char * _Filename,   const char * _EnvVar,   char * _ResultPath,   size_t _SizeInBytes);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _searchenv_s(  const char * _Filename,   const char * _EnvVar, char (&_ResultPath)[_Size]) throw() { return _searchenv_s(_Filename, _EnvVar, _ResultPath, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_searchenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _searchenv( const char * _Filename,  const char * _EnvVar,   char *_ResultPath);


__declspec(deprecated("This function or variable may be unsafe. Consider using " "_splitpath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void   __cdecl _splitpath(  const char * _FullPath,     char * _Drive,     char * _Dir,     char * _Filename,     char * _Ext);
  errno_t  __cdecl _splitpath_s(  const char * _FullPath,
                  char * _Drive,   size_t _DriveSize,
                  char * _Dir,   size_t _DirSize,
                  char * _Filename,   size_t _FilenameSize,
                  char * _Ext,   size_t _ExtSize);
extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _splitpath_s(  const char *_Dest,   char (&_Drive)[_DriveSize],   char (&_Dir)[_DirSize],   char (&_Name)[_NameSize],   char (&_Ext)[_ExtSize]) throw() { return _splitpath_s(_Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }

 void   __cdecl _swab(    char * _Buf1,     char * _Buf2, int _SizeInBytes);










   wchar_t * __cdecl _wfullpath(  wchar_t * _FullPath,   const wchar_t * _Path,   size_t _SizeInWords);





  errno_t __cdecl _wmakepath_s(  wchar_t * _PathResult,   size_t _SIZE,   const wchar_t * _Drive,   const wchar_t * _Dir,   const wchar_t * _Filename,
          const wchar_t * _Ext);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wmakepath_s(wchar_t (&_ResultPath)[_Size],   const wchar_t * _Drive,   const wchar_t * _Dir,   const wchar_t * _Filename,   const wchar_t * _Ext) throw() { return _wmakepath_s(_ResultPath, _Size, _Drive, _Dir, _Filename, _Ext); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wmakepath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wmakepath(  wchar_t *_ResultPath,  const wchar_t * _Drive,  const wchar_t * _Dir,  const wchar_t * _Filename,  const wchar_t * _Ext);


 void __cdecl _wperror(  const wchar_t * _ErrMsg);



   int    __cdecl _wputenv(  const wchar_t * _EnvString);
  errno_t __cdecl _wputenv_s(  const wchar_t * _Name,   const wchar_t * _Value);
 errno_t __cdecl _wsearchenv_s(  const wchar_t * _Filename,   const wchar_t * _EnvVar,   wchar_t * _ResultPath,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wsearchenv_s(  const wchar_t * _Filename,   const wchar_t * _EnvVar, wchar_t (&_ResultPath)[_Size]) throw() { return _wsearchenv_s(_Filename, _EnvVar, _ResultPath, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsearchenv_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wsearchenv( const wchar_t * _Filename,  const wchar_t * _EnvVar,   wchar_t *_ResultPath);


__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wsplitpath_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void   __cdecl _wsplitpath(  const wchar_t * _FullPath,     wchar_t * _Drive,     wchar_t * _Dir,     wchar_t * _Filename,     wchar_t * _Ext);
 errno_t __cdecl _wsplitpath_s(  const wchar_t * _FullPath,
                  wchar_t * _Drive,   size_t _DriveSize,
                  wchar_t * _Dir,   size_t _DirSize,
                  wchar_t * _Filename,   size_t _FilenameSize,
                  wchar_t * _Ext,   size_t _ExtSize);
extern "C++" { template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize> inline errno_t __cdecl _wsplitpath_s(  const wchar_t *_Path,   wchar_t (&_Drive)[_DriveSize],   wchar_t (&_Dir)[_DirSize],   wchar_t (&_Name)[_NameSize],   wchar_t (&_Ext)[_ExtSize]) throw() { return _wsplitpath_s(_Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize); } }






__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "SetErrorMode" " instead. See online help for details."))  void __cdecl _seterrormode(  int _Mode);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Beep" " instead. See online help for details."))  void __cdecl _beep(  unsigned _Frequency,   unsigned _Duration);
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using " "Sleep" " instead. See online help for details."))  void __cdecl _sleep(  unsigned long _Duration);




















#pragma warning(push)
#pragma warning(disable: 4141) 
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ecvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ecvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl ecvt(  double _Val,   int _NumOfDigits,   int * _PtDec,   int * _PtSign);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl fcvt(  double _Val,   int _NumOfDec,   int * _PtDec,   int * _PtSign);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_gcvt" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fcvt_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           char * __cdecl gcvt(  double _Val,   int _NumOfDigits,     char * _DstBuf);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_itoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_itoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           char * __cdecl itoa(  int _Val,     char * _DstBuf,   int _Radix);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ltoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ltoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           char * __cdecl ltoa(  long _Val,     char * _DstBuf,   int _Radix);


  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putenv" ". See online help for details."))  int    __cdecl putenv(  const char * _EnvString);


__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_swab" ". See online help for details."))                                                                            void   __cdecl swab(  char * _Buf1,  char * _Buf2,   int _SizeInBytes);
__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_ultoa" ". See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_ultoa_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))         char * __cdecl ultoa(  unsigned long _Val,     char * _Dstbuf,   int _Radix);
#pragma warning(pop)
_onexit_t __cdecl onexit(  _onexit_t _Func);





}



#pragma pack(pop)



















#pragma once


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#pragma pack(push,8)


extern "C" {

































struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;































































 FILE * __cdecl __iob_func(void);






typedef __int64 fpos_t;






























   int __cdecl _filbuf(  FILE * _File );
  int __cdecl _flsbuf(  int _Ch,   FILE * _File);

   FILE * __cdecl _fsopen(  const char * _Filename,   const char * _Mode,   int _ShFlag);

 void __cdecl clearerr(  FILE * _File);

  errno_t __cdecl clearerr_s(  FILE * _File );

  int __cdecl fclose(  FILE * _File);
  int __cdecl _fcloseall(void);

   FILE * __cdecl _fdopen(  int _FileHandle,   const char * _Mode);

   int __cdecl feof(  FILE * _File);
   int __cdecl ferror(  FILE * _File);
  int __cdecl fflush(  FILE * _File);
  int __cdecl fgetc(  FILE * _File);
  int __cdecl _fgetchar(void);
  int __cdecl fgetpos(  FILE * _File ,   fpos_t * _Pos);
  char * __cdecl fgets(  char * _Buf,   int _MaxCount,   FILE * _File);

   int __cdecl _fileno(  FILE * _File);






   char * __cdecl _tempnam(  const char * _DirName,   const char * _FilePrefix);





  int __cdecl _flushall(void);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "fopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  FILE * __cdecl fopen(  const char * _Filename,   const char * _Mode);

  errno_t __cdecl fopen_s(  FILE ** _File,   const char * _Filename,   const char * _Mode);

  int __cdecl fprintf(  FILE * _File,     const char * _Format, ...);

  int __cdecl fprintf_s(  FILE * _File,     const char * _Format, ...);

  int __cdecl fputc(  int _Ch,   FILE * _File);
  int __cdecl _fputchar(  int _Ch);
  int __cdecl fputs(  const char * _Str,   FILE * _File);
  size_t __cdecl fread(  void * _DstBuf,   size_t _ElementSize,   size_t _Count,   FILE * _File);

  size_t __cdecl fread_s(  void * _DstBuf,   size_t _DstSize,   size_t _ElementSize,   size_t _Count,   FILE * _File);

  __declspec(deprecated("This function or variable may be unsafe. Consider using " "freopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  FILE * __cdecl freopen(  const char * _Filename,   const char * _Mode,   FILE * _File);

  errno_t __cdecl freopen_s(  FILE ** _File,   const char * _Filename,   const char * _Mode,   FILE * _OldFile);

  __declspec(deprecated("This function or variable may be unsafe. Consider using " "fscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl fscanf(  FILE * _File,     const char * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _fscanf_l(  FILE * _File,     const char * _Format,   _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl fscanf_s(  FILE * _File,     const char * _Format, ...);

  int __cdecl _fscanf_s_l(  FILE * _File,     const char * _Format,   _locale_t _Locale, ...);
#pragma warning(pop)
  int __cdecl fsetpos(  FILE * _File,   const fpos_t * _Pos);
  int __cdecl fseek(  FILE * _File,   long _Offset,   int _Origin);
   long __cdecl ftell(  FILE * _File);

  int __cdecl _fseeki64(  FILE * _File,   __int64 _Offset,   int _Origin);
   __int64 __cdecl _ftelli64(  FILE * _File);

  size_t __cdecl fwrite(  const void * _Str,   size_t _Size,   size_t _Count,   FILE * _File);
   int __cdecl getc(  FILE * _File);
   int __cdecl getchar(void);
   int __cdecl _getmaxstdio(void);

 char * __cdecl gets_s(  char * _Buf,   rsize_t _Size);

extern "C++" { template <size_t _Size> inline char * __cdecl gets_s(char (&_Buffer)[_Size]) throw() { return gets_s(_Buffer, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "gets_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl gets(  char *_Buffer);
  int __cdecl _getw(  FILE * _File);





  int __cdecl _pclose(  FILE * _File);
   FILE * __cdecl _popen(  const char * _Command,   const char * _Mode);

  int __cdecl printf(    const char * _Format, ...);

  int __cdecl printf_s(    const char * _Format, ...);

  int __cdecl putc(  int _Ch,   FILE * _File);
  int __cdecl putchar(  int _Ch);
  int __cdecl puts(  const char * _Str);
  int __cdecl _putw(  int _Word,   FILE * _File);


 int __cdecl remove(  const char * _Filename);
   int __cdecl rename(  const char * _OldFilename,   const char * _NewFilename);
 int __cdecl _unlink(  const char * _Filename);

__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_unlink" ". See online help for details."))  int __cdecl unlink(  const char * _Filename);


 void __cdecl rewind(  FILE * _File);
  int __cdecl _rmtmp(void);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "scanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl scanf(    const char * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_scanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _scanf_l(    const char * _Format,   _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl scanf_s(    const char * _Format, ...);

  int __cdecl _scanf_s_l(    const char * _Format,   _locale_t _Locale, ...);
#pragma warning(pop)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "setvbuf" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl setbuf(  FILE * _File,     char * _Buffer);
  int __cdecl _setmaxstdio(  int _Max);
  unsigned int __cdecl _set_output_format(  unsigned int _Format);
  unsigned int __cdecl _get_output_format(void);
  int __cdecl setvbuf(  FILE * _File,   char * _Buf,   int _Mode,   size_t _Size);
  int __cdecl _snprintf_s(  char * _DstBuf,   size_t _SizeInBytes,   size_t _MaxCount,     const char * _Format, ...);
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl _snprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return _vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _ArgList); } __pragma(warning(pop)); }

  int __cdecl sprintf_s(  char * _DstBuf,   size_t _SizeInBytes,     const char * _Format, ...);

extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl sprintf_s(  char (&_Dest)[_Size],     const char * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return vsprintf_s(_Dest, _Size, _Format, _ArgList); } __pragma(warning(pop)); }
   int __cdecl _scprintf(    const char * _Format, ...);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "sscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl sscanf(  const char * _Src,     const char * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_sscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _sscanf_l(  const char * _Src,     const char * _Format,   _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl sscanf_s(  const char * _Src,     const char * _Format, ...);

  int __cdecl _sscanf_s_l(  const char * _Src,     const char * _Format,   _locale_t _Locale, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snscanf(    const char * _Src,   size_t _MaxCount,     const char * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snscanf_l(    const char * _Src,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _snscanf_s(    const char * _Src,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _snscanf_s_l(    const char * _Src,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
#pragma warning(pop)
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "tmpfile_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  FILE * __cdecl tmpfile(void);

  errno_t __cdecl tmpfile_s(    FILE ** _File);
  errno_t __cdecl tmpnam_s(  char * _Buf,   rsize_t _Size);

extern "C++" { template <size_t _Size> inline errno_t __cdecl tmpnam_s(  char (&_Buf)[_Size]) throw() { return tmpnam_s(_Buf, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "tmpnam_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char * __cdecl tmpnam(  char *_Buffer);
  int __cdecl ungetc(  int _Ch,   FILE * _File);
  int __cdecl vfprintf(  FILE * _File,     const char * _Format, va_list _ArgList);
  int __cdecl vfscanf(  FILE * _File,     const char * _Format, va_list _ArgList);

  int __cdecl vfprintf_s(  FILE * _File,     const char * _Format, va_list _ArgList);
  int __cdecl vfscanf_s(  FILE * _File,     const char * _Format, va_list _ArgList);

  int __cdecl vprintf(    const char * _Format, va_list _ArgList);
  int __cdecl vscanf(    const char * _Format, va_list _ArgList);

  int __cdecl vprintf_s(    const char * _Format, va_list _ArgList);
  int __cdecl vscanf_s(    const char * _Format, va_list _ArgList);

 __declspec(deprecated("This function or variable may be unsafe. Consider using " "vsnprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl vsnprintf(  char * _DstBuf,   size_t _MaxCount,     const char * _Format, va_list _ArgList);

  int __cdecl vsnprintf_s(  char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl vsnprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, va_list _Args) throw() { return vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _Args); } }

  int __cdecl _vsnprintf_s(  char * _DstBuf,   size_t _SizeInBytes,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl _vsnprintf_s(  char (&_Dest)[_Size],   size_t _MaxCount,     const char * _Format, va_list _Args) throw() { return _vsnprintf_s(_Dest, _Size, _MaxCount, _Format, _Args); } }
#pragma warning(push)
#pragma warning(disable:4793)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snprintf(    char *_Dest,   size_t _Count,     const char * _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _vsnprintf(    char *_Dest,   size_t _Count,     const char * _Format, va_list _Args);
#pragma warning(pop)

 int __cdecl vsprintf_s(  char * _DstBuf,   size_t _SizeInBytes,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl vsprintf_s(  char (&_Dest)[_Size],     const char * _Format, va_list _Args) throw() { return vsprintf_s(_Dest, _Size, _Format, _Args); } }
  int __cdecl vsscanf_s(const char * _Src,     const char * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl vsscanf_s(  const char (&_Src)[_Size],     const char * _Format, va_list _Args) throw() { return vsscanf_s(_Src, _Size, _Format, _Args); } }

#pragma warning(push)
#pragma warning(disable:4793)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "sprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl sprintf(  char *_Dest,  const char * _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "vsprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl vsprintf(  char *_Dest,  const char * _Format, va_list _Args);
  int __cdecl vsscanf(const char * _srcBuf,     const char * _Format, va_list _ArgList);
#pragma warning(pop)
   int __cdecl _vscprintf(    const char * _Format, va_list _ArgList);
  int __cdecl _snprintf_c(  char * _DstBuf,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _vsnprintf_c(  char *_DstBuf,   size_t _MaxCount,     const char * _Format, va_list _ArgList);

  int __cdecl _fprintf_p(  FILE * _File,     const char * _Format, ...);
  int __cdecl _printf_p(    const char * _Format, ...);
  int __cdecl _sprintf_p(  char * _Dst,   size_t _MaxCount,     const char * _Format, ...);
  int __cdecl _vfprintf_p(  FILE * _File,     const char * _Format, va_list _ArgList);
  int __cdecl _vprintf_p(    const char * _Format, va_list _ArgList);
  int __cdecl _vsprintf_p(  char * _Dst,   size_t _MaxCount,     const char * _Format, va_list _ArgList);
   int __cdecl _scprintf_p(    const char * _Format, ...);
   int __cdecl _vscprintf_p(    const char * _Format, va_list _ArgList);
 int __cdecl _set_printf_count_output(  int _Value);
 int __cdecl _get_printf_count_output(void);

  int __cdecl _printf_l(    const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _printf_p_l(    const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _printf_s_l(    const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _vprintf_l(    const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_p_l(    const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vprintf_s_l(    const char * _Format,   _locale_t _Locale, va_list _ArgList);

  int __cdecl _fprintf_l(  FILE * _File,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _fprintf_p_l(  FILE * _File,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _fprintf_s_l(  FILE * _File,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _vfprintf_l(  FILE * _File,   const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_p_l(  FILE * _File,   const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfprintf_s_l(  FILE * _File,   const char * _Format,   _locale_t _Locale, va_list _ArgList);

 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_sprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _sprintf_l(    char * _DstBuf,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _sprintf_p_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _sprintf_s_l(  char * _DstBuf,   size_t _DstSize,     const char * _Format,   _locale_t _Locale, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _vsprintf_l(    char * _DstBuf,   const char * _Format,   _locale_t, va_list _ArgList);
  int __cdecl _vsprintf_p_l(  char * _DstBuf,   size_t _MaxCount,     const char* _Format,   _locale_t _Locale,  va_list _ArgList);
  int __cdecl _vsprintf_s_l(  char * _DstBuf,   size_t _DstSize,     const char * _Format,   _locale_t _Locale, va_list _ArgList);

  int __cdecl _scprintf_l(    const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _scprintf_p_l(    const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _vscprintf_l(    const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vscprintf_p_l(    const char * _Format,   _locale_t _Locale, va_list _ArgList);

 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snprintf_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _snprintf_c_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
  int __cdecl _snprintf_s_l(  char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _vsnprintf_l(  char * _DstBuf,   size_t _MaxCount,     const char * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_c_l(  char * _DstBuf,   size_t _MaxCount, const char *,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnprintf_s_l(  char * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const char* _Format,  _locale_t _Locale, va_list _ArgList);









   FILE * __cdecl _wfsopen(  const wchar_t * _Filename,   const wchar_t * _Mode,   int _ShFlag);

  wint_t __cdecl fgetwc(  FILE * _File);
  wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(  wchar_t _Ch,   FILE * _File);
  wint_t __cdecl _fputwchar(  wchar_t _Ch);
   wint_t __cdecl getwc(  FILE * _File);
   wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(  wchar_t _Ch,   FILE * _File);
  wint_t __cdecl putwchar(  wchar_t _Ch);
  wint_t __cdecl ungetwc(  wint_t _Ch,   FILE * _File);

  wchar_t * __cdecl fgetws(  wchar_t * _Dst,   int _SizeInWords,   FILE * _File);
  int __cdecl fputws(  const wchar_t * _Str,   FILE * _File);
  wchar_t * __cdecl _getws_s(  wchar_t * _Str,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline wchar_t * __cdecl _getws_s(  wchar_t (&_String)[_Size]) throw() { return _getws_s(_String, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_getws_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _getws(  wchar_t *_String);
  int __cdecl _putws(  const wchar_t * _Str);

  int __cdecl fwprintf(  FILE * _File,     const wchar_t * _Format, ...);

  int __cdecl fwprintf_s(  FILE * _File,     const wchar_t * _Format, ...);

  int __cdecl wprintf(    const wchar_t * _Format, ...);

  int __cdecl wprintf_s(    const wchar_t * _Format, ...);

   int __cdecl _scwprintf(    const wchar_t * _Format, ...);
  int __cdecl vfwprintf(  FILE * _File,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl vfwscanf(  FILE * _File,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl vfwprintf_s(  FILE * _File,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl vfwscanf_s(  FILE * _File,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl vwprintf(    const wchar_t * _Format, va_list _ArgList);
  int __cdecl vwscanf(    const wchar_t * _Format, va_list _ArgList);

  int __cdecl vwprintf_s(    const wchar_t * _Format, va_list _ArgList);
  int __cdecl vwscanf_s(    const wchar_t * _Format, va_list _ArgList);



 int __cdecl swprintf_s(  wchar_t * _Dst,   size_t _SizeInWords,     const wchar_t * _Format, ...);

extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl swprintf_s(  wchar_t (&_Dest)[_Size],     const wchar_t * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return vswprintf_s(_Dest, _Size, _Format, _ArgList); } __pragma(warning(pop)); }

 int __cdecl vswprintf_s(  wchar_t * _Dst,   size_t _SizeInWords,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl vswscanf_s(const wchar_t * _Src,     const wchar_t * _Format, va_list _ArgList);

extern "C++" { template <size_t _Size> inline int __cdecl vswprintf_s(  wchar_t (&_Dest)[_Size],     const wchar_t * _Format, va_list _Args) throw() { return vswprintf_s(_Dest, _Size, _Format, _Args); } }
extern "C++" { template <size_t _Size> inline int __cdecl vswscanf_s(  wchar_t (&_Dest)[_Size],     const wchar_t * _Format, va_list _Args) throw() { return vswscanf_s(_Dest, _Size, _Format, _Args); } }
  int __cdecl vswscanf(const wchar_t * _srcBuf,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl _swprintf_c(  wchar_t * _DstBuf,   size_t _SizeInWords,     const wchar_t * _Format, ...);
  int __cdecl _vswprintf_c(  wchar_t * _DstBuf,   size_t _SizeInWords,     const wchar_t * _Format, va_list _ArgList);

  int __cdecl _snwprintf_s(  wchar_t * _DstBuf,   size_t _SizeInWords,   size_t _MaxCount,     const wchar_t * _Format, ...);
extern "C++" { __pragma(warning(push)); __pragma(warning(disable: 4793)); template <size_t _Size> inline int __cdecl _snwprintf_s(  wchar_t (&_Dest)[_Size],   size_t _Count,     const wchar_t * _Format, ...) throw() { va_list _ArgList; ( _ArgList = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) ); return _vsnwprintf_s(_Dest, _Size, _Count, _Format, _ArgList); } __pragma(warning(pop)); }
  int __cdecl _vsnwprintf_s(  wchar_t * _DstBuf,   size_t _SizeInWords,   size_t _MaxCount,     const wchar_t * _Format, va_list _ArgList);
extern "C++" { template <size_t _Size> inline int __cdecl _vsnwprintf_s(  wchar_t (&_Dest)[_Size],   size_t _Count,     const wchar_t * _Format, va_list _Args) throw() { return _vsnwprintf_s(_Dest, _Size, _Count, _Format, _Args); } }
#pragma warning(push)
#pragma warning(disable:4793)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snwprintf(    wchar_t *_Dest,   size_t _Count,     const wchar_t * _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _vsnwprintf(    wchar_t *_Dest,   size_t _Count,     const wchar_t * _Format, va_list _Args);
#pragma warning(pop)

  int __cdecl _fwprintf_p(  FILE * _File,     const wchar_t * _Format, ...);
  int __cdecl _wprintf_p(    const wchar_t * _Format, ...);
  int __cdecl _vfwprintf_p(  FILE * _File,     const wchar_t * _Format, va_list _ArgList);
  int __cdecl _vwprintf_p(    const wchar_t * _Format, va_list _ArgList);
  int __cdecl _swprintf_p(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format, ...);
  int __cdecl _vswprintf_p(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format, va_list _ArgList);
   int __cdecl _scwprintf_p(    const wchar_t * _Format, ...);
   int __cdecl _vscwprintf_p(    const wchar_t * _Format, va_list _ArgList);

  int __cdecl _wprintf_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _wprintf_p_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _wprintf_s_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _vwprintf_l(    const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_p_l(    const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vwprintf_s_l(    const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);

  int __cdecl _fwprintf_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _fwprintf_p_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _fwprintf_s_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _vfwprintf_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_p_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vfwprintf_s_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);

  int __cdecl _swprintf_c_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _swprintf_p_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _swprintf_s_l(  wchar_t * _DstBuf,   size_t _DstSize,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _vswprintf_c_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_p_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vswprintf_s_l(  wchar_t * _DstBuf,   size_t _DstSize,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);

   int __cdecl _scwprintf_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
   int __cdecl _scwprintf_p_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
   int __cdecl _vscwprintf_p_l(    const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);

 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snwprintf_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _snwprintf_s_l(  wchar_t * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vsnwprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _vsnwprintf_l(  wchar_t * _DstBuf,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  int __cdecl _vsnwprintf_s_l(  wchar_t * _DstBuf,   size_t _DstSize,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);













#pragma warning(push)
#pragma warning(disable:4141 4996 4793)
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_swprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _swprintf(    wchar_t *_Dest,     const wchar_t * _Format, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "vswprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl _vswprintf(    wchar_t *_Dest,     const wchar_t * _Format, va_list _Args);
__declspec(deprecated("This function or variable may be unsafe. Consider using " "__swprintf_l_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __swprintf_l(    wchar_t *_Dest,     const wchar_t * _Format, _locale_t _Plocinfo, ...); __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vswprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS."))  int __cdecl __vswprintf_l(    wchar_t *_Dest,     const wchar_t * _Format, _locale_t _Plocinfo, va_list _Args);
#pragma warning(pop)















#pragma once




















#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int swprintf(  wchar_t * _String, size_t _Count,     const wchar_t * _Format, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, 0, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl vswprintf(  wchar_t * _String, size_t _Count,     const wchar_t * _Format, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, 0, _Ap);
}
#pragma warning( pop )




#pragma warning( push )
#pragma warning( disable : 4793 4412 )
static __inline int _swprintf_l(  wchar_t * _String, size_t _Count,     const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
    va_list _Arglist;
    int _Ret;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Plocinfo) ) + ( (sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    _Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
static __inline int __cdecl _vswprintf_l(  wchar_t * _String, size_t _Count,     const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
    return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )


#pragma warning( push )
#pragma warning( disable : 4996 )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "swprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline int swprintf(    wchar_t * _String,     const wchar_t * _Format, ...)
{
    va_list _Arglist;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Format) ) + ( (sizeof(_Format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    int _Ret = _vswprintf(_String, _Format, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "vswprintf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline int __cdecl vswprintf(    wchar_t * _String,     const wchar_t * _Format, va_list _Ap)
{
    return _vswprintf(_String, _Format, _Ap);
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_swprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline int _swprintf_l(    wchar_t * _String,     const wchar_t * _Format, _locale_t _Plocinfo, ...)
{
    va_list _Arglist;
    ( _Arglist = (va_list)( &reinterpret_cast<const char &>(_Plocinfo) ) + ( (sizeof(_Plocinfo) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    int _Ret = __vswprintf_l(_String, _Format, _Plocinfo, _Arglist);
    ( _Arglist = (va_list)0 );
    return _Ret;
}
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
extern "C++" __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using " "_vswprintf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline int __cdecl _vswprintf_l(    wchar_t * _String,     const wchar_t * _Format, _locale_t _Plocinfo, va_list _Ap)
{
    return __vswprintf_l(_String, _Format, _Plocinfo, _Ap);
}
#pragma warning( pop )

#pragma warning( pop )























   wchar_t * __cdecl _wtempnam(  const wchar_t * _Directory,   const wchar_t * _FilePrefix);





   int __cdecl _vscwprintf(    const wchar_t * _Format, va_list _ArgList);
   int __cdecl _vscwprintf_l(    const wchar_t * _Format,   _locale_t _Locale, va_list _ArgList);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "fwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl fwscanf(  FILE * _File,     const wchar_t * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_fwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _fwscanf_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, ...);
#pragma warning(push)
#pragma warning(disable:6530)

  int __cdecl fwscanf_s(  FILE * _File,     const wchar_t * _Format, ...);

  int __cdecl _fwscanf_s_l(  FILE * _File,     const wchar_t * _Format,   _locale_t _Locale, ...);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "swscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl swscanf(  const wchar_t * _Src,     const wchar_t * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_swscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _swscanf_l(  const wchar_t * _Src,     const wchar_t * _Format,   _locale_t _Locale, ...);

  int __cdecl swscanf_s(  const wchar_t *_Src,     const wchar_t * _Format, ...);

  int __cdecl _swscanf_s_l(  const wchar_t * _Src,     const wchar_t * _Format,   _locale_t _Locale, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snwscanf(    const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_snwscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _snwscanf_l(    const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
  int __cdecl _snwscanf_s(    const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format, ...);
  int __cdecl _snwscanf_s_l(    const wchar_t * _Src,   size_t _MaxCount,     const wchar_t * _Format,   _locale_t _Locale, ...);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "wscanf_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl wscanf(    const wchar_t * _Format, ...);
 __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wscanf_s_l" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int __cdecl _wscanf_l(    const wchar_t * _Format,   _locale_t _Locale, ...);

  int __cdecl wscanf_s(    const wchar_t * _Format, ...);

  int __cdecl _wscanf_s_l(    const wchar_t * _Format,   _locale_t _Locale, ...);
#pragma warning(pop)

   FILE * __cdecl _wfdopen(  int _FileHandle ,   const wchar_t * _Mode);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wfopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  FILE * __cdecl _wfopen(  const wchar_t * _Filename,   const wchar_t * _Mode);
  errno_t __cdecl _wfopen_s(  FILE ** _File,   const wchar_t * _Filename,   const wchar_t * _Mode);
  __declspec(deprecated("This function or variable may be unsafe. Consider using " "_wfreopen_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  FILE * __cdecl _wfreopen(  const wchar_t * _Filename,   const wchar_t * _Mode,   FILE * _OldFile);
  errno_t __cdecl _wfreopen_s(  FILE ** _File,   const wchar_t * _Filename,   const wchar_t * _Mode,   FILE * _OldFile);






   FILE * __cdecl _wpopen(  const wchar_t *_Command,   const wchar_t * _Mode);

 int __cdecl _wremove(  const wchar_t * _Filename);
  errno_t __cdecl _wtmpnam_s(  wchar_t * _DstBuf,   size_t _SizeInWords);
extern "C++" { template <size_t _Size> inline errno_t __cdecl _wtmpnam_s(  wchar_t (&_Buffer)[_Size]) throw() { return _wtmpnam_s(_Buffer, _Size); } }
__declspec(deprecated("This function or variable may be unsafe. Consider using " "_wtmpnam_s" " instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t * __cdecl _wtmpnam(  wchar_t *_Buffer);

  wint_t __cdecl _fgetwc_nolock(  FILE * _File);
  wint_t __cdecl _fputwc_nolock(  wchar_t _Ch,   FILE * _File);
  wint_t __cdecl _ungetwc_nolock(  wint_t _Ch,   FILE * _File);











inline   wint_t __cdecl getwchar()
        {return (fgetwc((&__iob_func()[0]))); }   
inline  wint_t __cdecl putwchar(  wchar_t _C)
        {return (fputwc(_C, (&__iob_func()[1]))); }       













































 void __cdecl _lock_file(  FILE * _File);
 void __cdecl _unlock_file(  FILE * _File);

  int __cdecl _fclose_nolock(  FILE * _File);
  int __cdecl _fflush_nolock(  FILE * _File);
  size_t __cdecl _fread_nolock(  void * _DstBuf,   size_t _ElementSize,   size_t _Count,   FILE * _File);
  size_t __cdecl _fread_nolock_s(  void * _DstBuf,   size_t _DstSize,   size_t _ElementSize,   size_t _Count,   FILE * _File);
  int __cdecl _fseek_nolock(  FILE * _File,   long _Offset,   int _Origin);
   long __cdecl _ftell_nolock(  FILE * _File);
  int __cdecl _fseeki64_nolock(  FILE * _File,   __int64 _Offset,   int _Origin);
   __int64 __cdecl _ftelli64_nolock(  FILE * _File);
  size_t __cdecl _fwrite_nolock(  const void * _DstBuf,   size_t _Size,   size_t _Count,   FILE * _File);
  int __cdecl _ungetc_nolock(  int _Ch,   FILE * _File);


























__declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_tempnam" ". See online help for details."))  char * __cdecl tempnam(  const char * _Directory,   const char * _FilePrefix);





 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fcloseall" ". See online help for details."))  int __cdecl fcloseall(void);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fdopen" ". See online help for details."))  FILE * __cdecl fdopen(  int _FileHandle,   const char * _Format);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fgetchar" ". See online help for details."))  int __cdecl fgetchar(void);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fileno" ". See online help for details."))  int __cdecl fileno(  FILE * _File);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_flushall" ". See online help for details."))  int __cdecl flushall(void);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_fputchar" ". See online help for details."))  int __cdecl fputchar(  int _Ch);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_getw" ". See online help for details."))  int __cdecl getw(  FILE * _File);
 __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_putw" ". See online help for details."))  int __cdecl putw(  int _Ch,   FILE * _File);
  __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: " "_rmtmp" ". See online help for details."))  int __cdecl rmtmp(void);




}


#pragma pack(pop)






















 




static const float RC_PI = 3.14159265f;



enum rcLogCategory
{
	RC_LOG_PROGRESS = 1,	
	RC_LOG_WARNING,			
	RC_LOG_ERROR,			
};



enum rcTimerLabel
{
	
	RC_TIMER_TOTAL,
	
	RC_TIMER_TEMP,
	
	RC_TIMER_RASTERIZE_TRIANGLES,
	
	RC_TIMER_BUILD_COMPACTHEIGHTFIELD,
	
	RC_TIMER_BUILD_CONTOURS,
	
	RC_TIMER_BUILD_CONTOURS_TRACE,
	
	RC_TIMER_BUILD_CONTOURS_SIMPLIFY,
	
	RC_TIMER_FILTER_BORDER,
	
	RC_TIMER_FILTER_WALKABLE,
	
	RC_TIMER_MEDIAN_AREA,
	
	RC_TIMER_FILTER_LOW_OBSTACLES,
	
	RC_TIMER_BUILD_POLYMESH,
	
	RC_TIMER_MERGE_POLYMESH,
	
	RC_TIMER_ERODE_AREA,
	
	RC_TIMER_MARK_BOX_AREA,
	
	RC_TIMER_MARK_CYLINDER_AREA,
	
	RC_TIMER_MARK_CONVEXPOLY_AREA,
	
	RC_TIMER_BUILD_DISTANCEFIELD,
	
	RC_TIMER_BUILD_DISTANCEFIELD_DIST,
	
	RC_TIMER_BUILD_DISTANCEFIELD_BLUR,
	
	RC_TIMER_BUILD_REGIONS,
	
	RC_TIMER_BUILD_REGIONS_WATERSHED,
	
	RC_TIMER_BUILD_REGIONS_EXPAND,
	
	RC_TIMER_BUILD_REGIONS_FLOOD,
	
	RC_TIMER_BUILD_REGIONS_FILTER,
	
	RC_TIMER_BUILD_LAYERS, 
	
	RC_TIMER_BUILD_POLYMESHDETAIL,
	
	RC_TIMER_MERGE_POLYMESHDETAIL,
	
	RC_MAX_TIMERS
};




class rcContext
{
public:

	
	
	inline rcContext(bool state = true) : m_logEnabled(state), m_timerEnabled(state) {}
	virtual ~rcContext() {}

	
	
	inline void enableLog(bool state) { m_logEnabled = state; }

	
	inline void resetLog() { if (m_logEnabled) doResetLog(); }

	
	
	
	void log(const rcLogCategory category, const char* format, ...);

	
	
	inline void enableTimer(bool state) { m_timerEnabled = state; }

	
	inline void resetTimers() { if (m_timerEnabled) doResetTimers(); }

	
	
	inline void startTimer(const rcTimerLabel label) { if (m_timerEnabled) doStartTimer(label); }

	
	
	inline void stopTimer(const rcTimerLabel label) { if (m_timerEnabled) doStopTimer(label); }

	
	
	
	inline int getAccumulatedTime(const rcTimerLabel label) const { return m_timerEnabled ? doGetAccumulatedTime(label) : -1; }

protected:

	
	virtual void doResetLog() {}

	
	
	
	
	virtual void doLog(const rcLogCategory , const char* , const int ) {}

	
	virtual void doResetTimers() {}

	
	
	virtual void doStartTimer(const rcTimerLabel ) {}

	
	
	virtual void doStopTimer(const rcTimerLabel ) {}

	
	
	
	virtual int doGetAccumulatedTime(const rcTimerLabel ) const { return -1; }
	
	
	bool m_logEnabled;

	
	bool m_timerEnabled;
};



struct rcConfig
{
	
	int width;

	
	int height;
	
	
	int tileSize;
	
	
	int borderSize;

	
	float cs;

	
	float ch;

	
	float bmin[3]; 

	
	float bmax[3];

	
	float walkableSlopeAngle;

	
	
	int walkableHeight;
	
	
	int walkableClimb;
	
	
	
	int walkableRadius;
	
	
	int maxEdgeLen;
	
	
	
	float maxSimplificationError;
	
	
	int minRegionArea;
	
	
	
	int mergeRegionArea;
	
	
	
	int maxVertsPerPoly;
	
	
	
	float detailSampleDist;
	
	
	
	float detailSampleMaxError;
};


static const int RC_SPAN_HEIGHT_BITS = 13;

static const int RC_SPAN_MAX_HEIGHT = (1<<RC_SPAN_HEIGHT_BITS)-1;



static const int RC_SPANS_PER_POOL = 2048;



struct rcSpan
{
	unsigned int smin : 13;			
	unsigned int smax : 13;			
	unsigned int area : 6;			
	rcSpan* next;					
};



struct rcSpanPool
{
	rcSpanPool* next;					
	rcSpan items[RC_SPANS_PER_POOL];	
};



struct rcHeightfield
{
	int width;			
	int height;			
	float bmin[3];  	
	float bmax[3];		
	float cs;			
	float ch;			
	rcSpan** spans;		
	rcSpanPool* pools;	
	rcSpan* freelist;	
};


struct rcCompactCell
{
	unsigned int index : 24;	
	unsigned int count : 8;		
};


struct rcCompactSpan
{
	unsigned short y;			
	unsigned short reg;			
	unsigned int con : 24;		
	unsigned int h : 8;			
};



struct rcCompactHeightfield
{
	int width;					
	int height;					
	int spanCount;				
	int walkableHeight;			
	int walkableClimb;			
	int borderSize;				
	unsigned short maxDistance;	
	unsigned short maxRegions;	
	float bmin[3];				
	float bmax[3];				
	float cs;					
	float ch;					
	rcCompactCell* cells;		
	rcCompactSpan* spans;		
	unsigned short* dist;		
	unsigned char* areas;		
};



struct rcHeightfieldLayer
{
	float bmin[3];				
	float bmax[3];				
	float cs;					
	float ch;					
	int width;					
	int height;					
	int minx;					
	int maxx;					
	int miny;					
	int maxy;					
	int hmin;					
	int hmax;					
	unsigned char* heights;		
	unsigned char* areas;		
	unsigned char* cons;		
};




struct rcHeightfieldLayerSet
{
	rcHeightfieldLayer* layers;			
	int nlayers;						
};


struct rcContour
{
	int* verts;			
	int nverts;			
	int* rverts;		
	int nrverts;		
	unsigned short reg;	
	unsigned char area;	
};



struct rcContourSet
{
	rcContour* conts;	
	int nconts;			
	float bmin[3];  	
	float bmax[3];		
	float cs;			
	float ch;			
	int width;			
	int height;			
	int borderSize;		
};



struct rcPolyMesh
{
	unsigned short* verts;	
	unsigned short* polys;	
	unsigned short* regs;	
	unsigned short* flags;	
	unsigned char* areas;	
	int nverts;				
	int npolys;				
	int maxpolys;			
	int nvp;				
	float bmin[3];			
	float bmax[3];			
	float cs;				
	float ch;				
	int borderSize;			
};




struct rcPolyMeshDetail
{
	unsigned int* meshes;	
	float* verts;			
	unsigned char* tris;	
	int nmeshes;			
	int nverts;				
	int ntris;				
};










rcHeightfield* rcAllocHeightfield();





void rcFreeHeightField(rcHeightfield* hf);





rcCompactHeightfield* rcAllocCompactHeightfield();





void rcFreeCompactHeightfield(rcCompactHeightfield* chf);





rcHeightfieldLayerSet* rcAllocHeightfieldLayerSet();





void rcFreeHeightfieldLayerSet(rcHeightfieldLayerSet* lset);





rcContourSet* rcAllocContourSet();





void rcFreeContourSet(rcContourSet* cset);





rcPolyMesh* rcAllocPolyMesh();





void rcFreePolyMesh(rcPolyMesh* pmesh);





rcPolyMeshDetail* rcAllocPolyMeshDetail();





void rcFreePolyMeshDetail(rcPolyMeshDetail* dmesh);








static const unsigned short RC_BORDER_REG = 0x8000;








static const int RC_BORDER_VERTEX = 0x10000;






static const int RC_AREA_BORDER = 0x20000;



enum rcBuildContoursFlags
{
	RC_CONTOUR_TESS_WALL_EDGES = 0x01,	
	RC_CONTOUR_TESS_AREA_EDGES = 0x02,	
};





static const int RC_CONTOUR_REG_MASK = 0xffff;




static const unsigned short RC_MESH_NULL_IDX = 0xffff;




static const unsigned char RC_NULL_AREA = 0;




static const unsigned char RC_WALKABLE_AREA = 63;



static const int RC_NOT_CONNECTED = 0x3f;







template<class T> inline void rcSwap(T& a, T& b) { T t = a; a = b; b = t; }





template<class T> inline T rcMin(T a, T b) { return a < b ? a : b; }





template<class T> inline T rcMax(T a, T b) { return a > b ? a : b; }




template<class T> inline T rcAbs(T a) { return a < 0 ? -a : a; }




template<class T> inline T rcSqr(T a) { return a*a; }






template<class T> inline T rcClamp(T v, T mn, T mx) { return v < mn ? mn : (v > mx ? mx : v); }




float rcSqrt(float x);









inline void rcVcross(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[1]*v2[2] - v1[2]*v2[1];
	dest[1] = v1[2]*v2[0] - v1[0]*v2[2];
	dest[2] = v1[0]*v2[1] - v1[1]*v2[0];
}





inline float rcVdot(const float* v1, const float* v2)
{
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}






inline void rcVmad(float* dest, const float* v1, const float* v2, const float s)
{
	dest[0] = v1[0]+v2[0]*s;
	dest[1] = v1[1]+v2[1]*s;
	dest[2] = v1[2]+v2[2]*s;
}





inline void rcVadd(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[0]+v2[0];
	dest[1] = v1[1]+v2[1];
	dest[2] = v1[2]+v2[2];
}





inline void rcVsub(float* dest, const float* v1, const float* v2)
{
	dest[0] = v1[0]-v2[0];
	dest[1] = v1[1]-v2[1];
	dest[2] = v1[2]-v2[2];
}




inline void rcVmin(float* mn, const float* v)
{
	mn[0] = rcMin(mn[0], v[0]);
	mn[1] = rcMin(mn[1], v[1]);
	mn[2] = rcMin(mn[2], v[2]);
}




inline void rcVmax(float* mx, const float* v)
{
	mx[0] = rcMax(mx[0], v[0]);
	mx[1] = rcMax(mx[1], v[1]);
	mx[2] = rcMax(mx[2], v[2]);
}




inline void rcVcopy(float* dest, const float* v)
{
	dest[0] = v[0];
	dest[1] = v[1];
	dest[2] = v[2];
}





inline float rcVdist(const float* v1, const float* v2)
{
	float dx = v2[0] - v1[0];
	float dy = v2[1] - v1[1];
	float dz = v2[2] - v1[2];
	return rcSqrt(dx*dx + dy*dy + dz*dz);
}





inline float rcVdistSqr(const float* v1, const float* v2)
{
	float dx = v2[0] - v1[0];
	float dy = v2[1] - v1[1];
	float dz = v2[2] - v1[2];
	return dx*dx + dy*dy + dz*dz;
}



inline void rcVnormalize(float* v)
{
	float d = 1.0f / rcSqrt(rcSqr(v[0]) + rcSqr(v[1]) + rcSqr(v[2]));
	v[0] *= d;
	v[1] *= d;
	v[2] *= d;
}












void rcCalcBounds(const float* verts, int nv, float* bmin, float* bmax);








void rcCalcGridSize(const float* bmin, const float* bmax, float cs, int* w, int* h);











bool rcCreateHeightfield(rcContext* ctx, rcHeightfield& hf, int width, int height,
						 const float* bmin, const float* bmax,
						 float cs, float ch);












void rcMarkWalkableTriangles(rcContext* ctx, const float walkableSlopeAngle, const float* verts, int nv,
							 const int* tris, int nt, unsigned char* areas); 











void rcClearUnwalkableTriangles(rcContext* ctx, const float walkableSlopeAngle, const float* verts, int nv,
								const int* tris, int nt, unsigned char* areas); 













void rcAddSpan(rcContext* ctx, rcHeightfield& hf, const int x, const int y,
			   const unsigned short smin, const unsigned short smax,
			   const unsigned char area, const int flagMergeThr);











void rcRasterizeTriangle(rcContext* ctx, const float* v0, const float* v1, const float* v2,
						 const unsigned char area, rcHeightfield& solid,
						 const int flagMergeThr = 1);












void rcRasterizeTriangles(rcContext* ctx, const float* verts, const int nv,
						  const int* tris, const unsigned char* areas, const int nt,
						  rcHeightfield& solid, const int flagMergeThr = 1);












void rcRasterizeTriangles(rcContext* ctx, const float* verts, const int nv,
						  const unsigned short* tris, const unsigned char* areas, const int nt,
						  rcHeightfield& solid, const int flagMergeThr = 1);










void rcRasterizeTriangles(rcContext* ctx, const float* verts, const unsigned char* areas, const int nt,
						  rcHeightfield& solid, const int flagMergeThr = 1);







void rcFilterLowHangingWalkableObstacles(rcContext* ctx, const int walkableClimb, rcHeightfield& solid);









void rcFilterLedgeSpans(rcContext* ctx, const int walkableHeight,
						const int walkableClimb, rcHeightfield& solid);







void rcFilterWalkableLowHeightSpans(rcContext* ctx, int walkableHeight, rcHeightfield& solid);






int rcGetHeightFieldSpanCount(rcContext* ctx, rcHeightfield& hf);
















bool rcBuildCompactHeightfield(rcContext* ctx, const int walkableHeight, const int walkableClimb,
							   rcHeightfield& hf, rcCompactHeightfield& chf);







bool rcErodeWalkableArea(rcContext* ctx, int radius, rcCompactHeightfield& chf);






bool rcMedianFilterWalkableArea(rcContext* ctx, rcCompactHeightfield& chf);








void rcMarkBoxArea(rcContext* ctx, const float* bmin, const float* bmax, unsigned char areaId,
				   rcCompactHeightfield& chf);










void rcMarkConvexPolyArea(rcContext* ctx, const float* verts, const int nverts,
						  const float hmin, const float hmax, unsigned char areaId,
						  rcCompactHeightfield& chf);








int rcOffsetPoly(const float* verts, const int nverts, const float offset,
				 float* outVerts, const int maxOutVerts);









void rcMarkCylinderArea(rcContext* ctx, const float* pos,
						const float r, const float h, unsigned char areaId,
						rcCompactHeightfield& chf);






bool rcBuildDistanceField(rcContext* ctx, rcCompactHeightfield& chf);












bool rcBuildRegions(rcContext* ctx, rcCompactHeightfield& chf,
					const int borderSize, const int minRegionArea, const int mergeRegionArea);












bool rcBuildRegionsMonotone(rcContext* ctx, rcCompactHeightfield& chf,
							const int borderSize, const int minRegionArea, const int mergeRegionArea);






inline void rcSetCon(rcCompactSpan& s, int dir, int i)
{
	const unsigned int shift = (unsigned int)dir*6;
	unsigned int con = s.con;
	s.con = (con & ~(0x3f << shift)) | (((unsigned int)i & 0x3f) << shift);
}






inline int rcGetCon(const rcCompactSpan& s, int dir)
{
	const unsigned int shift = (unsigned int)dir*6;
	return (s.con >> shift) & 0x3f;
}





inline int rcGetDirOffsetX(int dir)
{
	const int offset[4] = { -1, 0, 1, 0, };
	return offset[dir&0x03];
}





inline int rcGetDirOffsetY(int dir)
{
	const int offset[4] = { 0, 1, 0, -1 };
	return offset[dir&0x03];
}
















bool rcBuildHeightfieldLayers(rcContext* ctx, rcCompactHeightfield& chf, 
							  const int borderSize, const int walkableHeight,
							  rcHeightfieldLayerSet& lset);












bool rcBuildContours(rcContext* ctx, rcCompactHeightfield& chf,
					 const float maxError, const int maxEdgeLen,
					 rcContourSet& cset, const int flags = RC_CONTOUR_TESS_WALL_EDGES);









bool rcBuildPolyMesh(rcContext* ctx, rcContourSet& cset, const int nvp, rcPolyMesh& mesh);








bool rcMergePolyMeshes(rcContext* ctx, rcPolyMesh** meshes, const int nmeshes, rcPolyMesh& mesh);











bool rcBuildPolyMeshDetail(rcContext* ctx, const rcPolyMesh& mesh, const rcCompactHeightfield& chf,
						   const float sampleDist, const float sampleMaxError,
						   rcPolyMeshDetail& dmesh);







bool rcCopyPolyMesh(rcContext* ctx, const rcPolyMesh& src, rcPolyMesh& dst);








bool rcMergePolyMeshDetails(rcContext* ctx, rcPolyMeshDetail** meshes, const int nmeshes, rcPolyMeshDetail& mesh);




































enum rcAllocHint
{
	RC_ALLOC_PERM,		
	RC_ALLOC_TEMP		
};






typedef void* (rcAllocFunc)(int size, rcAllocHint hint);




typedef void (rcFreeFunc)(void* ptr);




void rcAllocSetCustom(rcAllocFunc *allocFunc, rcFreeFunc *freeFunc);






void* rcAlloc(int size, rcAllocHint hint);




void rcFree(void* ptr);



class rcIntArray
{
	int* m_data;
	int m_size, m_cap;
	inline rcIntArray(const rcIntArray&);
	inline rcIntArray& operator=(const rcIntArray&);
public:

	
	inline rcIntArray() : m_data(0), m_size(0), m_cap(0) {}

	
	
	inline rcIntArray(int n) : m_data(0), m_size(0), m_cap(0) { resize(n); }
	inline ~rcIntArray() { rcFree(m_data); }

	
	
	void resize(int n);

	
	
	inline void push(int item) { resize(m_size+1); m_data[m_size-1] = item; }

	
	
	inline int pop() { if (m_size > 0) m_size--; return m_data[m_size]; }

	
	
	
	inline const int& operator[](int i) const { return m_data[i]; }

	
	
	
	inline int& operator[](int i) { return m_data[i]; }

	
	inline int size() const { return m_size; }
};



template<class T> class rcScopedDelete
{
	T* ptr;
	inline T* operator=(T* p);
public:

	
	inline rcScopedDelete() : ptr(0) {}

	
	
	inline rcScopedDelete(T* p) : ptr(p) {}
	inline ~rcScopedDelete() { rcFree(ptr); }

	
	
	inline operator T*() { return ptr; }
};








































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































extern "C" {


 void __cdecl _wassert(  const wchar_t * _Message,   const wchar_t *_File,   unsigned _Line);


}













static const unsigned RC_UNSET_HEIGHT = 0xffff;

struct rcHeightPatch
{
	inline rcHeightPatch() : data(0), xmin(0), ymin(0), width(0), height(0) {}
	inline ~rcHeightPatch() { rcFree(data); }
	unsigned short* data;
	int xmin, ymin, width, height;
};


inline float vdot2(const float* a, const float* b)
{
	return a[0]*b[0] + a[2]*b[2];
}

inline float vdistSq2(const float* p, const float* q)
{
	const float dx = q[0] - p[0];
	const float dy = q[2] - p[2];
	return dx*dx + dy*dy;
}

inline float vdist2(const float* p, const float* q)
{
	return sqrtf(vdistSq2(p,q));
}

inline float vcross2(const float* p1, const float* p2, const float* p3)
{ 
	const float u1 = p2[0] - p1[0];
	const float v1 = p2[2] - p1[2];
	const float u2 = p3[0] - p1[0];
	const float v2 = p3[2] - p1[2];
	return u1 * v2 - v1 * u2;
}

static bool circumCircle(const float* p1, const float* p2, const float* p3,
						 float* c, float& r)
{
	static const float EPS = 1e-6f;
	
	const float cp = vcross2(p1, p2, p3);
	if (fabsf(cp) > EPS)
	{
		const float p1Sq = vdot2(p1,p1);
		const float p2Sq = vdot2(p2,p2);
		const float p3Sq = vdot2(p3,p3);
		c[0] = (p1Sq*(p2[2]-p3[2]) + p2Sq*(p3[2]-p1[2]) + p3Sq*(p1[2]-p2[2])) / (2*cp);
		c[2] = (p1Sq*(p3[0]-p2[0]) + p2Sq*(p1[0]-p3[0]) + p3Sq*(p2[0]-p1[0])) / (2*cp);
		r = vdist2(c, p1);
		return true;
	}

	c[0] = p1[0];
	c[2] = p1[2];
	r = 0;
	return false;
}

static float distPtTri(const float* p, const float* a, const float* b, const float* c)
{
	float v0[3], v1[3], v2[3];
	rcVsub(v0, c,a);
	rcVsub(v1, b,a);
	rcVsub(v2, p,a);

	const float dot00 = vdot2(v0, v0);
	const float dot01 = vdot2(v0, v1);
	const float dot02 = vdot2(v0, v2);
	const float dot11 = vdot2(v1, v1);
	const float dot12 = vdot2(v1, v2);
	
	
	const float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
	const float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;
	
	
	static const float EPS = 1e-4f;
	if (u >= -EPS && v >= -EPS && (u+v) <= 1+EPS)
	{
		const float y = a[1] + v0[1]*u + v1[1]*v;
		return fabsf(y-p[1]);
	}
	return 3.402823466e+38F;
}

static float distancePtSeg(const float* pt, const float* p, const float* q)
{
	float pqx = q[0] - p[0];
	float pqy = q[1] - p[1];
	float pqz = q[2] - p[2];
	float dx = pt[0] - p[0];
	float dy = pt[1] - p[1];
	float dz = pt[2] - p[2];
	float d = pqx*pqx + pqy*pqy + pqz*pqz;
	float t = pqx*dx + pqy*dy + pqz*dz;
	if (d > 0)
		t /= d;
	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	
	dx = p[0] + t*pqx - pt[0];
	dy = p[1] + t*pqy - pt[1];
	dz = p[2] + t*pqz - pt[2];
	
	return dx*dx + dy*dy + dz*dz;
}

static float distancePtSeg2d(const float* pt, const float* p, const float* q)
{
	float pqx = q[0] - p[0];
	float pqz = q[2] - p[2];
	float dx = pt[0] - p[0];
	float dz = pt[2] - p[2];
	float d = pqx*pqx + pqz*pqz;
	float t = pqx*dx + pqz*dz;
	if (d > 0)
		t /= d;
	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	
	dx = p[0] + t*pqx - pt[0];
	dz = p[2] + t*pqz - pt[2];
	
	return dx*dx + dz*dz;
}

static float distToTriMesh(const float* p, const float* verts, const int , const int* tris, const int ntris)
{
	float dmin = 3.402823466e+38F;
	for (int i = 0; i < ntris; ++i)
	{
		const float* va = &verts[tris[i*4+0]*3];
		const float* vb = &verts[tris[i*4+1]*3];
		const float* vc = &verts[tris[i*4+2]*3];
		float d = distPtTri(p, va,vb,vc);
		if (d < dmin)
			dmin = d;
	}
	if (dmin == 3.402823466e+38F) return -1;
	return dmin;
}

static float distToPoly(int nvert, const float* verts, const float* p)
{

	float dmin = 3.402823466e+38F;
	int i, j, c = 0;
	for (i = 0, j = nvert-1; i < nvert; j = i++)
	{
		const float* vi = &verts[i*3];
		const float* vj = &verts[j*3];
		if (((vi[2] > p[2]) != (vj[2] > p[2])) &&
			(p[0] < (vj[0]-vi[0]) * (p[2]-vi[2]) / (vj[2]-vi[2]) + vi[0]) )
			c = !c;
		dmin = rcMin(dmin, distancePtSeg2d(p, vj, vi));
	}
	return c ? -dmin : dmin;
}


static unsigned short getHeight(const float fx, const float fy, const float fz,
								const float , const float ics, const float ch,
								const rcHeightPatch& hp)
{
	int ix = (int)floorf(fx*ics + 0.01f);
	int iz = (int)floorf(fz*ics + 0.01f);
	ix = rcClamp(ix-hp.xmin, 0, hp.width);
	iz = rcClamp(iz-hp.ymin, 0, hp.height);
	unsigned short h = hp.data[ix+iz*hp.width];
	if (h == RC_UNSET_HEIGHT)
	{
		
		
		const int off[8*2] = { -1,0, -1,-1, 0,-1, 1,-1, 1,0, 1,1, 0,1, -1,1};
		float dmin = 3.402823466e+38F;
		for (int i = 0; i < 8; ++i)
		{
			const int nx = ix+off[i*2+0];
			const int nz = iz+off[i*2+1];
			if (nx < 0 || nz < 0 || nx >= hp.width || nz >= hp.height) continue;
			const unsigned short nh = hp.data[nx+nz*hp.width];
			if (nh == RC_UNSET_HEIGHT) continue;

			const float d = fabsf(nh*ch - fy);
			if (d < dmin)
			{
				h = nh;
				dmin = d;
			}
			








		}
	}
	return h;
}


enum EdgeValues
{
	UNDEF = -1,
	HULL = -2,
};

static int findEdge(const int* edges, int nedges, int s, int t)
{
	for (int i = 0; i < nedges; i++)
	{
		const int* e = &edges[i*4];
		if ((e[0] == s && e[1] == t) || (e[0] == t && e[1] == s))
			return i;
	}
	return UNDEF;
}

static int addEdge(rcContext* ctx, int* edges, int& nedges, const int maxEdges, int s, int t, int l, int r)
{
	if (nedges >= maxEdges)
	{
		ctx->log(RC_LOG_ERROR, "addEdge: Too many edges (%d/%d).", nedges, maxEdges);
		return UNDEF;
	}
	
	
	int e = findEdge(edges, nedges, s, t);
	if (e == UNDEF)
	{
		int* edge = &edges[nedges*4];
		edge[0] = s;
		edge[1] = t;
		edge[2] = l;
		edge[3] = r;
		return nedges++;
	}
	else
	{
		return UNDEF;
	}
}

static void updateLeftFace(int* e, int s, int t, int f)
{
	if (e[0] == s && e[1] == t && e[2] == UNDEF)
		e[2] = f;
	else if (e[1] == s && e[0] == t && e[3] == UNDEF)
		e[3] = f;
}	

static int overlapSegSeg2d(const float* a, const float* b, const float* c, const float* d)
{
	const float a1 = vcross2(a, b, d);
	const float a2 = vcross2(a, b, c);
	if (a1*a2 < 0.0f)
	{
		float a3 = vcross2(c, d, a);
		float a4 = a3 + a2 - a1;
		if (a3 * a4 < 0.0f)
			return 1;
	}	
	return 0;
}

static bool overlapEdges(const float* pts, const int* edges, int nedges, int s1, int t1)
{
	for (int i = 0; i < nedges; ++i)
	{
		const int s0 = edges[i*4+0];
		const int t0 = edges[i*4+1];
		
		if (s0 == s1 || s0 == t1 || t0 == s1 || t0 == t1)
			continue;
		if (overlapSegSeg2d(&pts[s0*3],&pts[t0*3], &pts[s1*3],&pts[t1*3]))
			return true;
	}
	return false;
}

static void completeFacet(rcContext* ctx, const float* pts, int npts, int* edges, int& nedges, const int maxEdges, int& nfaces, int e)
{
	static const float EPS = 1e-5f;

	int* edge = &edges[e*4];
	
	
	int s,t;
	if (edge[2] == UNDEF)
	{
		s = edge[0];
		t = edge[1];
	}
	else if (edge[3] == UNDEF)
	{
		s = edge[1];
		t = edge[0];
	}
	else
	{
	    
	    return;
	}
    
	
	int pt = npts;
	float c[3] = {0,0,0};
	float r = -1;
	for (int u = 0; u < npts; ++u)
	{
		if (u == s || u == t) continue;
		if (vcross2(&pts[s*3], &pts[t*3], &pts[u*3]) > EPS)
		{
			if (r < 0)
			{
				
				pt = u;
				circumCircle(&pts[s*3], &pts[t*3], &pts[u*3], c, r);
				continue;
			}
			const float d = vdist2(c, &pts[u*3]);
			const float tol = 0.001f;
			if (d > r*(1+tol))
			{
				
				continue;
			}
			else if (d < r*(1-tol))
			{
				
				pt = u;
				circumCircle(&pts[s*3], &pts[t*3], &pts[u*3], c, r);
			}
			else
			{
				
				
				if (overlapEdges(pts, edges, nedges, s,u))
					continue;
				if (overlapEdges(pts, edges, nedges, t,u))
					continue;
				
				pt = u;
				circumCircle(&pts[s*3], &pts[t*3], &pts[u*3], c, r);
			}
		}
	}
	
	
	if (pt < npts)
	{
		
		updateLeftFace(&edges[e*4], s, t, nfaces);
		
		
		e = findEdge(edges, nedges, pt, s);
		if (e == UNDEF)
		    addEdge(ctx, edges, nedges, maxEdges, pt, s, nfaces, UNDEF);
		else
		    updateLeftFace(&edges[e*4], pt, s, nfaces);
		
		
		e = findEdge(edges, nedges, t, pt);
		if (e == UNDEF)
		    addEdge(ctx, edges, nedges, maxEdges, t, pt, nfaces, UNDEF);
		else
		    updateLeftFace(&edges[e*4], t, pt, nfaces);
		
		nfaces++;
	}
	else
	{
		updateLeftFace(&edges[e*4], s, t, HULL);
	}
}

static void delaunayHull(rcContext* ctx, const int npts, const float* pts,
						 const int nhull, const int* hull,
						 rcIntArray& tris, rcIntArray& edges)
{
	int nfaces = 0;
	int nedges = 0;
	const int maxEdges = npts*10;
	edges.resize(maxEdges*4);
	
	for (int i = 0, j = nhull-1; i < nhull; j=i++)
		addEdge(ctx, &edges[0], nedges, maxEdges, hull[j],hull[i], HULL, UNDEF);
	
	int currentEdge = 0;
	while (currentEdge < nedges)
	{
		if (edges[currentEdge*4+2] == UNDEF)
			completeFacet(ctx, pts, npts, &edges[0], nedges, maxEdges, nfaces, currentEdge);
		if (edges[currentEdge*4+3] == UNDEF)
			completeFacet(ctx, pts, npts, &edges[0], nedges, maxEdges, nfaces, currentEdge);
		currentEdge++;
	}

	
	tris.resize(nfaces*4);
	for (int i = 0; i < nfaces*4; ++i)
		tris[i] = -1;
	
	for (int i = 0; i < nedges; ++i)
	{
		const int* e = &edges[i*4];
		if (e[3] >= 0)
		{
			
			int* t = &tris[e[3]*4];
			if (t[0] == -1)
			{
				t[0] = e[0];
				t[1] = e[1];
			}
			else if (t[0] == e[1])
				t[2] = e[0];
			else if (t[1] == e[0])
				t[2] = e[1];
		}
		if (e[2] >= 0)
		{
			
			int* t = &tris[e[2]*4];
			if (t[0] == -1)
			{
				t[0] = e[1];
				t[1] = e[0];
			}
			else if (t[0] == e[0])
				t[2] = e[1];
			else if (t[1] == e[1])
				t[2] = e[0];
		}
	}
	
	for (int i = 0; i < tris.size()/4; ++i)
	{
		int* t = &tris[i*4];
		if (t[0] == -1 || t[1] == -1 || t[2] == -1)
		{
			ctx->log(RC_LOG_WARNING, "delaunayHull: Removing dangling face %d [%d,%d,%d].", i, t[0],t[1],t[2]);
			t[0] = tris[tris.size()-4];
			t[1] = tris[tris.size()-3];
			t[2] = tris[tris.size()-2];
			t[3] = tris[tris.size()-1];
			tris.resize(tris.size()-4);
			--i;
		}
	}
}


inline float getJitterX(const int i)
{
	return (((i * 0x8da6b343) & 0xffff) / 65535.0f * 2.0f) - 1.0f;
}

inline float getJitterY(const int i)
{
	return (((i * 0xd8163841) & 0xffff) / 65535.0f * 2.0f) - 1.0f;
}

static bool buildPolyDetail(rcContext* ctx, const float* in, const int nin,
							const float sampleDist, const float sampleMaxError,
							const rcCompactHeightfield& chf, const rcHeightPatch& hp,
							float* verts, int& nverts, rcIntArray& tris,
							rcIntArray& edges, rcIntArray& samples)
{
	static const int MAX_VERTS = 127;
	static const int MAX_TRIS = 255;	
	static const int MAX_VERTS_PER_EDGE = 32;
	float edge[(MAX_VERTS_PER_EDGE+1)*3];
	int hull[MAX_VERTS];
	int nhull = 0;

	nverts = 0;

	for (int i = 0; i < nin; ++i)
		rcVcopy(&verts[i*3], &in[i*3]);
	nverts = nin;
	
	const float cs = chf.cs;
	const float ics = 1.0f/cs;
	
	
	
	
	if (sampleDist > 0)
	{
		for (int i = 0, j = nin-1; i < nin; j=i++)
		{
			const float* vj = &in[j*3];
			const float* vi = &in[i*3];
			bool swapped = false;
			
			
			if (fabsf(vj[0]-vi[0]) < 1e-6f)
			{
				if (vj[2] > vi[2])
				{
					rcSwap(vj,vi);
					swapped = true;
				}
			}
			else
			{
				if (vj[0] > vi[0])
				{
					rcSwap(vj,vi);
					swapped = true;
				}
			}
			
			float dx = vi[0] - vj[0];
			float dy = vi[1] - vj[1];
			float dz = vi[2] - vj[2];
			float d = sqrtf(dx*dx + dz*dz);
			int nn = 1 + (int)floorf(d/sampleDist);
			if (nn >= MAX_VERTS_PER_EDGE) nn = MAX_VERTS_PER_EDGE-1;
			if (nverts+nn >= MAX_VERTS)
				nn = MAX_VERTS-1-nverts;
			
			for (int k = 0; k <= nn; ++k)
			{
				float u = (float)k/(float)nn;
				float* pos = &edge[k*3];
				pos[0] = vj[0] + dx*u;
				pos[1] = vj[1] + dy*u;
				pos[2] = vj[2] + dz*u;
				pos[1] = getHeight(pos[0],pos[1],pos[2], cs, ics, chf.ch, hp)*chf.ch;
			}
			
			int idx[MAX_VERTS_PER_EDGE] = {0,nn};
			int nidx = 2;
			for (int k = 0; k < nidx-1; )
			{
				const int a = idx[k];
				const int b = idx[k+1];
				const float* va = &edge[a*3];
				const float* vb = &edge[b*3];
				
				float maxd = 0;
				int maxi = -1;
				for (int m = a+1; m < b; ++m)
				{
					float dev = distancePtSeg(&edge[m*3],va,vb);
					if (dev > maxd)
					{
						maxd = dev;
						maxi = m;
					}
				}
				
				
				if (maxi != -1 && maxd > rcSqr(sampleMaxError))
				{
					for (int m = nidx; m > k; --m)
						idx[m] = idx[m-1];
					idx[k+1] = maxi;
					nidx++;
				}
				else
				{
					++k;
				}
			}
			
			hull[nhull++] = j;
			
			if (swapped)
			{
				for (int k = nidx-2; k > 0; --k)
				{
					rcVcopy(&verts[nverts*3], &edge[idx[k]*3]);
					hull[nhull++] = nverts;
					nverts++;
				}
			}
			else
			{
				for (int k = 1; k < nidx-1; ++k)
				{
					rcVcopy(&verts[nverts*3], &edge[idx[k]*3]);
					hull[nhull++] = nverts;
					nverts++;
				}
			}
		}
	}
	

	
	edges.resize(0);
	tris.resize(0);

	delaunayHull(ctx, nverts, verts, nhull, hull, tris, edges);
	
	if (tris.size() == 0)
	{
		
		ctx->log(RC_LOG_WARNING, "buildPolyDetail: Could not triangulate polygon, adding default data.");
		for (int i = 2; i < nverts; ++i)
		{
			tris.push(0);
			tris.push(i-1);
			tris.push(i);
			tris.push(0);
		}
		return true;
	}

	if (sampleDist > 0)
	{
		
		float bmin[3], bmax[3];
		rcVcopy(bmin, in);
		rcVcopy(bmax, in);
		for (int i = 1; i < nin; ++i)
		{
			rcVmin(bmin, &in[i*3]);
			rcVmax(bmax, &in[i*3]);
		}
		int x0 = (int)floorf(bmin[0]/sampleDist);
		int x1 = (int)ceilf(bmax[0]/sampleDist);
		int z0 = (int)floorf(bmin[2]/sampleDist);
		int z1 = (int)ceilf(bmax[2]/sampleDist);
		samples.resize(0);
		for (int z = z0; z < z1; ++z)
		{
			for (int x = x0; x < x1; ++x)
			{
				float pt[3];
				pt[0] = x*sampleDist;
				pt[1] = (bmax[1]+bmin[1])*0.5f;
				pt[2] = z*sampleDist;
				
				if (distToPoly(nin,in,pt) > -sampleDist/2) continue;
				samples.push(x);
				samples.push(getHeight(pt[0], pt[1], pt[2], cs, ics, chf.ch, hp));
				samples.push(z);
				samples.push(0); 
			}
		}
				
		
		
		
		const int nsamples = samples.size()/4;
		for (int iter = 0; iter < nsamples; ++iter)
		{
			if (nverts >= MAX_VERTS)
				break;

			
			float bestpt[3] = {0,0,0};
			float bestd = 0;
			int besti = -1;
			for (int i = 0; i < nsamples; ++i)
			{
				const int* s = &samples[i*4];
				if (s[3]) continue; 
				float pt[3];
				
				
				pt[0] = s[0]*sampleDist + getJitterX(i)*cs*0.1f;
				pt[1] = s[1]*chf.ch;
				pt[2] = s[2]*sampleDist + getJitterY(i)*cs*0.1f;
				float d = distToTriMesh(pt, verts, nverts, &tris[0], tris.size()/4);
				if (d < 0) continue; 
				if (d > bestd)
				{
					bestd = d;
					besti = i;
					rcVcopy(bestpt,pt);
				}
			}
			
			if (bestd <= sampleMaxError || besti == -1)
				break;
			
			samples[besti*4+3] = 1;
			
			rcVcopy(&verts[nverts*3],bestpt);
			nverts++;
			
			
			
			edges.resize(0);
			tris.resize(0);
			delaunayHull(ctx, nverts, verts, nhull, hull, tris, edges);
		}		
	}

	const int ntris = tris.size()/4;
	if (ntris > MAX_TRIS)
	{
		tris.resize(MAX_TRIS*4);
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Shrinking triangle count from %d to max %d.", ntris, MAX_TRIS);
	}

	return true;
}

static void getHeightData(const rcCompactHeightfield& chf,
						  const unsigned short* poly, const int npoly,
						  const unsigned short* verts, const int bs,
						  rcHeightPatch& hp, rcIntArray& stack)
{
	
	
	
	
	
	
	memset(hp.data, 0, sizeof(unsigned short)*hp.width*hp.height);
	
	stack.resize(0);
	
	static const int offset[9*2] =
	{
		0,0, -1,-1, 0,-1, 1,-1, 1,0, 1,1, 0,1, -1,1, -1,0,
	};
	
	
	for (int j = 0; j < npoly; ++j)
	{
		int cx = 0, cz = 0, ci =-1;
		int dmin = RC_UNSET_HEIGHT;
		for (int k = 0; k < 9; ++k)
		{
			const int ax = (int)verts[poly[j]*3+0] + offset[k*2+0];
			const int ay = (int)verts[poly[j]*3+1];
			const int az = (int)verts[poly[j]*3+2] + offset[k*2+1];
			if (ax < hp.xmin || ax >= hp.xmin+hp.width ||
				az < hp.ymin || az >= hp.ymin+hp.height)
				continue;
			
			const rcCompactCell& c = chf.cells[(ax+bs)+(az+bs)*chf.width];
			for (int i = (int)c.index, ni = (int)(c.index+c.count); i < ni; ++i)
			{
				const rcCompactSpan& s = chf.spans[i];
				int d = rcAbs(ay - (int)s.y);
				if (d < dmin)
				{
					cx = ax;
					cz = az;
					ci = i;
					dmin = d;
				}
			}
		}
		if (ci != -1)
		{
			stack.push(cx);
			stack.push(cz);
			stack.push(ci);
		}
	}
	
	
	int pcx = 0, pcz = 0;
	for (int j = 0; j < npoly; ++j)
	{
		pcx += (int)verts[poly[j]*3+0];
		pcz += (int)verts[poly[j]*3+2];
	}
	pcx /= npoly;
	pcz /= npoly;
	
	for (int i = 0; i < stack.size(); i += 3)
	{
		int cx = stack[i+0];
		int cy = stack[i+1];
		int idx = cx-hp.xmin+(cy-hp.ymin)*hp.width;
		hp.data[idx] = 1;
	}
	
	while (stack.size() > 0)
	{
		int ci = stack.pop();
		int cy = stack.pop();
		int cx = stack.pop();
		
		
		if (rcAbs(cx-pcx) <= 1 && rcAbs(cy-pcz) <= 1)
		{
			stack.resize(0);
			stack.push(cx);
			stack.push(cy);
			stack.push(ci);
			break;
		}
		
		const rcCompactSpan& cs = chf.spans[ci];
		
		for (int dir = 0; dir < 4; ++dir)
		{
			if (rcGetCon(cs, dir) == RC_NOT_CONNECTED) continue;
			
			const int ax = cx + rcGetDirOffsetX(dir);
			const int ay = cy + rcGetDirOffsetY(dir);
			
			if (ax < hp.xmin || ax >= (hp.xmin+hp.width) ||
				ay < hp.ymin || ay >= (hp.ymin+hp.height))
				continue;
			
			if (hp.data[ax-hp.xmin+(ay-hp.ymin)*hp.width] != 0)
				continue;
			
			const int ai = (int)chf.cells[(ax+bs)+(ay+bs)*chf.width].index + rcGetCon(cs, dir);

			int idx = ax-hp.xmin+(ay-hp.ymin)*hp.width;
			hp.data[idx] = 1;
			
			stack.push(ax);
			stack.push(ay);
			stack.push(ai);
		}
	}

	memset(hp.data, 0xff, sizeof(unsigned short)*hp.width*hp.height);

	
	for (int i = 0; i < stack.size(); i += 3)
	{
		int cx = stack[i+0];
		int cy = stack[i+1];
		int ci = stack[i+2];
		int idx = cx-hp.xmin+(cy-hp.ymin)*hp.width;
		const rcCompactSpan& cs = chf.spans[ci];
		hp.data[idx] = cs.y;
	}
	
	static const int RETRACT_SIZE = 256;
	int head = 0;
	
	while (head*3 < stack.size())
	{
		int cx = stack[head*3+0];
		int cy = stack[head*3+1];
		int ci = stack[head*3+2];
		head++;
		if (head >= RETRACT_SIZE)
		{
			head = 0;
			if (stack.size() > RETRACT_SIZE*3)
				memmove(&stack[0], &stack[RETRACT_SIZE*3], sizeof(int)*(stack.size()-RETRACT_SIZE*3));
			stack.resize(stack.size()-RETRACT_SIZE*3);
		}

		const rcCompactSpan& cs = chf.spans[ci];
		for (int dir = 0; dir < 4; ++dir)
		{
			if (rcGetCon(cs, dir) == RC_NOT_CONNECTED) continue;
			
			const int ax = cx + rcGetDirOffsetX(dir);
			const int ay = cy + rcGetDirOffsetY(dir);
			
			if (ax < hp.xmin || ax >= (hp.xmin+hp.width) ||
				ay < hp.ymin || ay >= (hp.ymin+hp.height))
				continue;
			
			if (hp.data[ax-hp.xmin+(ay-hp.ymin)*hp.width] != RC_UNSET_HEIGHT)
				continue;
			
			const int ai = (int)chf.cells[(ax+bs)+(ay+bs)*chf.width].index + rcGetCon(cs, dir);
			
			const rcCompactSpan& as = chf.spans[ai];
			int idx = ax-hp.xmin+(ay-hp.ymin)*hp.width;
			hp.data[idx] = as.y;

			stack.push(ax);
			stack.push(ay);
			stack.push(ai);
		}
	}
	
}

static unsigned char getEdgeFlags(const float* va, const float* vb,
								  const float* vpoly, const int npoly)
{
	
	static const float thrSqr = rcSqr(0.001f);
	for (int i = 0, j = npoly-1; i < npoly; j=i++)
	{
		if (distancePtSeg2d(va, &vpoly[j*3], &vpoly[i*3]) < thrSqr && 
			distancePtSeg2d(vb, &vpoly[j*3], &vpoly[i*3]) < thrSqr)
			return 1;
	}
	return 0;
}

static unsigned char getTriFlags(const float* va, const float* vb, const float* vc,
								 const float* vpoly, const int npoly)
{
	unsigned char flags = 0;
	flags |= getEdgeFlags(va,vb,vpoly,npoly) << 0;
	flags |= getEdgeFlags(vb,vc,vpoly,npoly) << 2;
	flags |= getEdgeFlags(vc,va,vpoly,npoly) << 4;
	return flags;
}






bool rcBuildPolyMeshDetail(rcContext* ctx, const rcPolyMesh& mesh, const rcCompactHeightfield& chf,
						   const float sampleDist, const float sampleMaxError,
						   rcPolyMeshDetail& dmesh)
{
	(void)( (!!(ctx)) || (_wassert(L"ctx", L"f:\\mygit\\fwcyclehero\\server\\src\\lib\\navigation\\recastmeshdetail.cpp", 953), 0) );
	
	ctx->startTimer(RC_TIMER_BUILD_POLYMESHDETAIL);

	if (mesh.nverts == 0 || mesh.npolys == 0)
		return true;
	
	const int nvp = mesh.nvp;
	const float cs = mesh.cs;
	const float ch = mesh.ch;
	const float* orig = mesh.bmin;
	const int borderSize = mesh.borderSize;
	
	rcIntArray edges(64);
	rcIntArray tris(512);
	rcIntArray stack(512);
	rcIntArray samples(512);
	float verts[256*3];
	rcHeightPatch hp;
	int nPolyVerts = 0;
	int maxhw = 0, maxhh = 0;
	
	rcScopedDelete<int> bounds = (int*)rcAlloc(sizeof(int)*mesh.npolys*4, RC_ALLOC_TEMP);
	if (!bounds)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'bounds' (%d).", mesh.npolys*4);
		return false;
	}
	rcScopedDelete<float> poly = (float*)rcAlloc(sizeof(float)*nvp*3, RC_ALLOC_TEMP);
	if (!poly)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'poly' (%d).", nvp*3);
		return false;
	}
	
	
	for (int i = 0; i < mesh.npolys; ++i)
	{
		const unsigned short* p = &mesh.polys[i*nvp*2];
		int& xmin = bounds[i*4+0];
		int& xmax = bounds[i*4+1];
		int& ymin = bounds[i*4+2];
		int& ymax = bounds[i*4+3];
		xmin = chf.width;
		xmax = 0;
		ymin = chf.height;
		ymax = 0;
		for (int j = 0; j < nvp; ++j)
		{
			if(p[j] == RC_MESH_NULL_IDX) break;
			const unsigned short* v = &mesh.verts[p[j]*3];
			xmin = rcMin(xmin, (int)v[0]);
			xmax = rcMax(xmax, (int)v[0]);
			ymin = rcMin(ymin, (int)v[2]);
			ymax = rcMax(ymax, (int)v[2]);
			nPolyVerts++;
		}
		xmin = rcMax(0,xmin-1);
		xmax = rcMin(chf.width,xmax+1);
		ymin = rcMax(0,ymin-1);
		ymax = rcMin(chf.height,ymax+1);
		if (xmin >= xmax || ymin >= ymax) continue;
		maxhw = rcMax(maxhw, xmax-xmin);
		maxhh = rcMax(maxhh, ymax-ymin);
	}
	
	hp.data = (unsigned short*)rcAlloc(sizeof(unsigned short)*maxhw*maxhh, RC_ALLOC_TEMP);
	if (!hp.data)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'hp.data' (%d).", maxhw*maxhh);
		return false;
	}
	
	dmesh.nmeshes = mesh.npolys;
	dmesh.nverts = 0;
	dmesh.ntris = 0;
	dmesh.meshes = (unsigned int*)rcAlloc(sizeof(unsigned int)*dmesh.nmeshes*4, RC_ALLOC_PERM);
	if (!dmesh.meshes)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'dmesh.meshes' (%d).", dmesh.nmeshes*4);
		return false;
	}

	int vcap = nPolyVerts+nPolyVerts/2;
	int tcap = vcap*2;

	dmesh.nverts = 0;
	dmesh.verts = (float*)rcAlloc(sizeof(float)*vcap*3, RC_ALLOC_PERM);
	if (!dmesh.verts)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'dmesh.verts' (%d).", vcap*3);
		return false;
	}
	dmesh.ntris = 0;
	dmesh.tris = (unsigned char*)rcAlloc(sizeof(unsigned char*)*tcap*4, RC_ALLOC_PERM);
	if (!dmesh.tris)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'dmesh.tris' (%d).", tcap*4);
		return false;
	}
	
	for (int i = 0; i < mesh.npolys; ++i)
	{
		const unsigned short* p = &mesh.polys[i*nvp*2];
		
		
		int npoly = 0;
		for (int j = 0; j < nvp; ++j)
		{
			if(p[j] == RC_MESH_NULL_IDX) break;
			const unsigned short* v = &mesh.verts[p[j]*3];
			poly[j*3+0] = v[0]*cs;
			poly[j*3+1] = v[1]*ch;
			poly[j*3+2] = v[2]*cs;
			npoly++;
		}
		
		
		hp.xmin = bounds[i*4+0];
		hp.ymin = bounds[i*4+2];
		hp.width = bounds[i*4+1]-bounds[i*4+0];
		hp.height = bounds[i*4+3]-bounds[i*4+2];
		getHeightData(chf, p, npoly, mesh.verts, borderSize, hp, stack);
		
		
		int nverts = 0;
		if (!buildPolyDetail(ctx, poly, npoly,
							 sampleDist, sampleMaxError,
							 chf, hp, verts, nverts, tris,
							 edges, samples))
		{
			return false;
		}

		
		for (int j = 0; j < nverts; ++j)
		{
			verts[j*3+0] += orig[0];
			verts[j*3+1] += orig[1] + chf.ch; 
			verts[j*3+2] += orig[2];
		}
		
		for (int j = 0; j < npoly; ++j)
		{
			poly[j*3+0] += orig[0];
			poly[j*3+1] += orig[1];
			poly[j*3+2] += orig[2];
		}
	
		
		const int ntris = tris.size()/4;

		dmesh.meshes[i*4+0] = (unsigned int)dmesh.nverts;
		dmesh.meshes[i*4+1] = (unsigned int)nverts;
		dmesh.meshes[i*4+2] = (unsigned int)dmesh.ntris;
		dmesh.meshes[i*4+3] = (unsigned int)ntris;		
		
		
		if (dmesh.nverts+nverts > vcap)
		{
			while (dmesh.nverts+nverts > vcap)
				vcap += 256;
				
			float* newv = (float*)rcAlloc(sizeof(float)*vcap*3, RC_ALLOC_PERM);
			if (!newv)
			{
				ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'newv' (%d).", vcap*3);
				return false;
			}
			if (dmesh.nverts)
				memcpy(newv, dmesh.verts, sizeof(float)*3*dmesh.nverts);
			rcFree(dmesh.verts);
			dmesh.verts = newv;
		}
		for (int j = 0; j < nverts; ++j)
		{
			dmesh.verts[dmesh.nverts*3+0] = verts[j*3+0];
			dmesh.verts[dmesh.nverts*3+1] = verts[j*3+1];
			dmesh.verts[dmesh.nverts*3+2] = verts[j*3+2];
			dmesh.nverts++;
		}
		
		
		if (dmesh.ntris+ntris > tcap)
		{
			while (dmesh.ntris+ntris > tcap)
				tcap += 256;
			unsigned char* newt = (unsigned char*)rcAlloc(sizeof(unsigned char)*tcap*4, RC_ALLOC_PERM);
			if (!newt)
			{
				ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'newt' (%d).", tcap*4);
				return false;
			}
			if (dmesh.ntris)
				memcpy(newt, dmesh.tris, sizeof(unsigned char)*4*dmesh.ntris);
			rcFree(dmesh.tris);
			dmesh.tris = newt;
		}
		for (int j = 0; j < ntris; ++j)
		{
			const int* t = &tris[j*4];
			dmesh.tris[dmesh.ntris*4+0] = (unsigned char)t[0];
			dmesh.tris[dmesh.ntris*4+1] = (unsigned char)t[1];
			dmesh.tris[dmesh.ntris*4+2] = (unsigned char)t[2];
			dmesh.tris[dmesh.ntris*4+3] = getTriFlags(&verts[t[0]*3], &verts[t[1]*3], &verts[t[2]*3], poly, npoly);
			dmesh.ntris++;
		}
	}
		
	ctx->stopTimer(RC_TIMER_BUILD_POLYMESHDETAIL);

	return true;
}


bool rcMergePolyMeshDetails(rcContext* ctx, rcPolyMeshDetail** meshes, const int nmeshes, rcPolyMeshDetail& mesh)
{
	(void)( (!!(ctx)) || (_wassert(L"ctx", L"f:\\mygit\\fwcyclehero\\server\\src\\lib\\navigation\\recastmeshdetail.cpp", 1170), 0) );
	
	ctx->startTimer(RC_TIMER_MERGE_POLYMESHDETAIL);

	int maxVerts = 0;
	int maxTris = 0;
	int maxMeshes = 0;

	for (int i = 0; i < nmeshes; ++i)
	{
		if (!meshes[i]) continue;
		maxVerts += meshes[i]->nverts;
		maxTris += meshes[i]->ntris;
		maxMeshes += meshes[i]->nmeshes;
	}

	mesh.nmeshes = 0;
	mesh.meshes = (unsigned int*)rcAlloc(sizeof(unsigned int)*maxMeshes*4, RC_ALLOC_PERM);
	if (!mesh.meshes)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'pmdtl.meshes' (%d).", maxMeshes*4);
		return false;
	}

	mesh.ntris = 0;
	mesh.tris = (unsigned char*)rcAlloc(sizeof(unsigned char)*maxTris*4, RC_ALLOC_PERM);
	if (!mesh.tris)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'dmesh.tris' (%d).", maxTris*4);
		return false;
	}

	mesh.nverts = 0;
	mesh.verts = (float*)rcAlloc(sizeof(float)*maxVerts*3, RC_ALLOC_PERM);
	if (!mesh.verts)
	{
		ctx->log(RC_LOG_ERROR, "rcBuildPolyMeshDetail: Out of memory 'dmesh.verts' (%d).", maxVerts*3);
		return false;
	}
	
	
	for (int i = 0; i < nmeshes; ++i)
	{
		rcPolyMeshDetail* dm = meshes[i];
		if (!dm) continue;
		for (int j = 0; j < dm->nmeshes; ++j)
		{
			unsigned int* dst = &mesh.meshes[mesh.nmeshes*4];
			unsigned int* src = &dm->meshes[j*4];
			dst[0] = (unsigned int)mesh.nverts+src[0];
			dst[1] = src[1];
			dst[2] = (unsigned int)mesh.ntris+src[2];
			dst[3] = src[3];
			mesh.nmeshes++;
		}
			
		for (int k = 0; k < dm->nverts; ++k)
		{
			rcVcopy(&mesh.verts[mesh.nverts*3], &dm->verts[k*3]);
			mesh.nverts++;
		}
		for (int k = 0; k < dm->ntris; ++k)
		{
			mesh.tris[mesh.ntris*4+0] = dm->tris[k*4+0];
			mesh.tris[mesh.ntris*4+1] = dm->tris[k*4+1];
			mesh.tris[mesh.ntris*4+2] = dm->tris[k*4+2];
			mesh.tris[mesh.ntris*4+3] = dm->tris[k*4+3];
			mesh.ntris++;
		}
	}

	ctx->stopTimer(RC_TIMER_MERGE_POLYMESHDETAIL);
	
	return true;
}


