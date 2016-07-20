/*-
 * Copyright (C) 1997 by Andrey A. Chernov, Moscow, Russia.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/lib/libc/locale/setlocale.h,v 1.4 2001/12/20 18:28:52 phantom Exp $
 */

#ifndef _SETLOCALE_H_
#define	_SETLOCALE_H_

#include <_ansi.h>
#include <sys/cdefs.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

__BEGIN_DECLS

#define ENCODING_LEN 31
#define CATEGORY_LEN 11
#define _LC_LAST      7

struct lc_ctype_T {
	const char	*codeset;	 /* codeset for mbtowc conversion */
	const char	*mb_cur_max;
#ifdef __HAVE_LOCALE_INFO_EXTENDED__
	const char	*outdigits[10];
	const wchar_t	*woutdigits[10];
#endif
};
extern const struct lc_ctype_T _C_ctype_locale;

struct lc_monetary_T {
	const char	*int_curr_symbol;
	const char	*currency_symbol;
	const char	*mon_decimal_point;
	const char	*mon_thousands_sep;
	const char	*mon_grouping;
	const char	*positive_sign;
	const char	*negative_sign;
	const char	*int_frac_digits;
	const char	*frac_digits;
	const char	*p_cs_precedes;
	const char	*p_sep_by_space;
	const char	*n_cs_precedes;
	const char	*n_sep_by_space;
	const char	*p_sign_posn;
	const char	*n_sign_posn;
#ifdef __HAVE_LOCALE_INFO_EXTENDED__
	const char	*int_p_cs_precedes;
	const char	*int_p_sep_by_space;
	const char	*int_n_cs_precedes;
	const char	*int_n_sep_by_space;
	const char	*int_p_sign_posn;
	const char	*int_n_sign_posn;
	const char	*codeset;	 /* codeset for mbtowc conversion */
	const wchar_t	*wint_curr_symbol;
	const wchar_t	*wcurrency_symbol;
	const wchar_t	*wmon_decimal_point;
	const wchar_t	*wmon_thousands_sep;
	const wchar_t	*wpositive_sign;
	const wchar_t	*wnegative_sign;
#endif
};
extern const struct lc_monetary_T _C_monetary_locale;

struct lc_numeric_T {
	const char	*decimal_point;
	const char	*thousands_sep;
	const char	*grouping;
#ifdef __HAVE_LOCALE_INFO_EXTENDED__
	const char	*codeset;	 /* codeset for mbtowc conversion */
	const wchar_t	*wdecimal_point;
	const wchar_t	*wthousands_sep;
#endif
};
extern const struct lc_numeric_T _C_numeric_locale;

struct lc_time_T {
	const char	*mon[12];
	const char	*month[12];
	const char	*wday[7];
	const char	*weekday[7];
	const char	*X_fmt;
	const char	*x_fmt;
	const char	*c_fmt;
	const char	*am_pm[2];
	const char	*date_fmt;
	const char	*alt_month[12];	/* unused */
	const char	*md_order;
	const char	*ampm_fmt;
	const char	*era;
	const char	*era_d_fmt;
	const char	*era_d_t_fmt;
	const char	*era_t_fmt;
	const char	*alt_digits;
#ifdef __HAVE_LOCALE_INFO_EXTENDED__
	const char	*codeset;	 /* codeset for mbtowc conversion */
	const wchar_t	*wmon[12];
	const wchar_t	*wmonth[12];
	const wchar_t	*wwday[7];
	const wchar_t	*wweekday[7];
	const wchar_t	*wX_fmt;
	const wchar_t	*wx_fmt;
	const wchar_t	*wc_fmt;
	const wchar_t	*wam_pm[2];
	const wchar_t	*wdate_fmt;
	const wchar_t	*wampm_fmt;
	const wchar_t	*wera;
	const wchar_t	*wera_d_fmt;
	const wchar_t	*wera_d_t_fmt;
	const wchar_t	*wera_t_fmt;
	const wchar_t	*walt_digits;
#endif
};
extern const struct lc_time_T _C_time_locale;

struct	lc_messages_T {
	const char	*yesexpr;
	const char	*noexpr;
	const char	*yesstr;
	const char	*nostr;
#ifdef __HAVE_LOCALE_INFO_EXTENDED__
	const char	*codeset;	 /* codeset for mbtowc conversion */
	const wchar_t	*wyesexpr;
	const wchar_t	*wnoexpr;
	const wchar_t	*wyesstr;
	const wchar_t	*wnostr;
#endif
};
extern const struct lc_messages_T _C_messages_locale;

#ifdef __CYGWIN__
typedef __uint32_t LCID;

struct lc_collate_T
{
  LCID  lcid;
  int (*mbtowc) (struct _reent *, wchar_t *, const char *, size_t, mbstate_t *);
  char codeset[ENCODING_LEN + 1];
};
extern const struct lc_collate_T _C_collate_locale;
#endif

struct _thr_locale_t
{
  char				 categories[_LC_LAST][ENCODING_LEN + 1];
  int				(*wctomb) (struct _reent *, char *, wchar_t,
					   mbstate_t *);
  int				(*mbtowc) (struct _reent *, wchar_t *,
					   const char *, size_t, mbstate_t *);
  int				 cjk_lang;
  char				*ctype_ptr; /* Unused in __global_locale */
#ifndef __HAVE_LOCALE_INFO__
  char				 mb_cur_max[2];
  char				 ctype_codeset[ENCODING_LEN + 1];
  char				 message_codeset[ENCODING_LEN + 1];
#else
  const struct lc_ctype_T	*ctype;
  char				*ctype_buf;
  const struct lc_monetary_T	*monetary;
  char				*monetary_buf;
  const struct lc_numeric_T	*numeric;
  char				*numeric_buf;
  const struct lc_time_T	*time;
  char				*time_buf;
  const struct lc_messages_T	*messages;
  char				*messages_buf;
#ifdef __CYGWIN__
  const struct lc_collate_T	*collate;
  char				*collate_buf;
#endif
  /* Append more categories here. */
#endif
};

extern struct _thr_locale_t __global_locale;

/* In POSIX terms the global locale is the process-wide locale.  Use this
   function to always refer to the global locale. */
_ELIDABLE_INLINE struct _thr_locale_t *
__get_global_locale ()
{
  return &__global_locale;
}

/* Per REENT locale.  This is newlib-internal. */
_ELIDABLE_INLINE struct _thr_locale_t *
__get_locale_r (struct _reent *r)
{
  return r->_locale;
}

/* In POSIX terms the current locale is the locale used by all functions
   using locale info without providing a locale as parameter (*_l functions).
   The current locale is either the locale of the current thread, if the
   thread called uselocale, or the global locale if not. */
_ELIDABLE_INLINE struct _thr_locale_t *
__get_current_locale ()
{
  return _REENT->_locale ?: &__global_locale;
}

_ELIDABLE_INLINE const struct lc_ctype_T *
__get_current_ctype_locale (void)
{
  return __get_current_locale ()->ctype;
}

_ELIDABLE_INLINE const struct lc_monetary_T *
__get_current_monetary_locale (void)
{
  return __get_current_locale ()->monetary;
}

_ELIDABLE_INLINE const struct lc_time_T *
__get_current_time_locale (void)
{
  return __get_current_locale ()->time;
}

_ELIDABLE_INLINE const struct lc_numeric_T *
__get_current_numeric_locale (void)
{
  return __get_current_locale ()->numeric;
}

_ELIDABLE_INLINE const struct lc_messages_T *
__get_current_messages_locale (void)
{
  return __get_current_locale ()->messages;
}

#ifdef __CYGWIN__
_ELIDABLE_INLINE const struct lc_collate_T *
__get_current_collate_locale (void)
{
  return __get_current_locale ()->collate;
}
#endif

_ELIDABLE_INLINE const char *
__locale_charset (void)
{
#ifdef __HAVE_LOCALE_INFO__
  return __get_current_ctype_locale ()->codeset;
#else
  return __global_locale.ctype_codeset;
#endif
}

_ELIDABLE_INLINE const char *
__locale_msgcharset (void)
{
#ifdef __HAVE_LOCALE_INFO__
  return (char *) __get_current_messages_locale ()->codeset;
#else
  return (char *) __global_locale.message_codeset;
#endif
}

_ELIDABLE_INLINE int
__locale_cjk_lang (void)
{
#ifdef __HAVE_LOCALE_INFO__
  return __get_current_locale ()->cjk_lang;
#else
  return __global_locale.cjk_lang;
#endif
}

int __ctype_load_locale (struct _thr_locale_t *, const char *, void *,
			 const char *, int);
int __monetary_load_locale (struct _thr_locale_t *, const char *, void *,
			    const char *);
int __numeric_load_locale (struct _thr_locale_t *, const char *, void *,
			   const char *);
int __time_load_locale (struct _thr_locale_t *, const char *, void *,
			const char *);
int __messages_load_locale (struct _thr_locale_t *, const char *, void *,
			    const char *);
#ifdef __CYGWIN__
int __collate_load_locale (struct _thr_locale_t *, const char *, void *,
			   const char *);

extern void __set_charset_from_locale (const char *locale, char *charset);
extern char *__set_locale_from_locale_alias (const char *, char *);
#endif

extern char *_PathLocale;

__END_DECLS

#endif /* !_SETLOCALE_H_ */
