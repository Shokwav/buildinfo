#ifndef BUILDINFO_H
#define BUILDINFO_H

#ifdef __cplusplus
extern "C" {
#endif

/* GCC/G++ */
#if defined(__GNUC__) and (not defined(__clang__) and not defined(__INTEL_COMPILER))
	#define BI_PLAT "GNU"
	#define BI_VER (__GNUC__ + (__GNUC_MINOR__ / 10.0) + (__GNUC_PATCHLEVEL__ / 100.0))
	#define BI_VER_STR __VERSION__

/* Microsoft Visual Studio */
#elif defined(_MSC_VER)
	#define BI_PLAT "MVS"
	#define BI_VER _MSC_FULL_VER

/* LLVM */
#elif defined(__clang__)
	#define BI_PLAT "LLVM"
	#define BI_VER (__clang_major__ + (__clang_minor__ / 10.0) + (__clang_patchlevel__ / 100.0))
	#define BI_VER_STR __clang_version__

/* Intel ICC */
#elif defined(__INTEL_COMPILER)
	#define BI_PLAT "ICC"
	#define BI_VER __INTEL_COMPILER
	#define BI_VER_STR __VERSION__

/* IBM */
#elif defined(__IBMC__) or defined(__IBMCPP__)
	#define BI_PLAT "IBM"
	#ifdef __IBMC__
		#define BI_VER __IMBC__
	#else
		#define BI_VER __IMBCPP__
	#endif

	#define BI_VER_STR __xlc__

/* Solaris */
#elif defined(__SUNPRO_C) or defined(__SUNPRO_CC)
	#define BI_PLAT "Solaris"
	#ifdef __SUNPRO_C
		#define BI_VER __SUNPRO_C
	#else
		#define BI_VER __SUNPRO_CC
	#endif

/* Portland Group */
#elif defined(__PGI)
	#define BI_PLAT "PGI"
	#define BI_VER (__PGIC__ + (__PGIC_MINOR / 10.0) + (__PGIC_PATCHLEVEL__ / 100.0))

/* Hewlett-Packard */
#elif defined(__HP_cc) || defined(__HP_aCC)
	#define BI_PLAT "HP"
	#ifdef __HP_cc
		#define BI_VER __HP_cc
	#else
		#define BI_VER __HP_aCC
	#endif

/* SGI */
#elif defined(__sgi)
	#define BI_PLAT "SGI"
	#define BI_VER _SGI_COMPILER_VERSION

/* Default */
#else
	#define BI_PLAT "Unknown"
	#define BI_VER 0.0
#endif

#ifndef BI_VER_STR
	#define BI_VER_STR "0.0"
#endif

#define BI_TIME __TIME__
#define BI_DATE __DATE__

#define BI_INFO BI_PLAT "\n" BI_VER_STR "\n" BI_TIME "\n" BI_DATE

#ifdef __cplusplus
}
#endif

#endif

