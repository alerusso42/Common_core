/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_method_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:17:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/21 17:21:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_METHOD_LIST_H
# define STRING_METHOD_LIST_H

# include <stdint.h>

typedef struct s_str			t_str;
typedef struct s_str_methods	t_str_methods;
typedef enum e_str_error		t_str_error;
typedef int32_t					err;

// Nome, ritorno, argomenti, overload_tag
// overload_tag serve a generare i _char, _str, _chr etc.

/* get_len / get_i / set_i */
X_METHOD(get_len,        int32_t, (t_str *),                          NONE)
X_METHOD(get_i,          int32_t, (t_str *),                          NONE)
X_METHOD(set_i,          void,    (t_str *, int32_t),                 NONE)

/* cmp */
X_METHOD(str_cmp,        int32_t, (t_str *, char *),                  CHAR)
X_METHOD(str_cmp,        int32_t, (t_str *, t_str *),                 STR)

/* cut */
X_METHOD(str_cut,        t_str*,  (t_str *, int32_t, int32_t),        NONE)

/* diff */
X_METHOD(str_diff,       t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_diff,       t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_diff,       t_str*,  (t_str *, t_str *),                 STR)

/* find */
X_METHOD(str_find,       t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_find,       t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_find,       t_str*,  (t_str *, t_str *),                 STR)

/* first */
X_METHOD(str_first,      t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_first,      t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_first,      t_str*,  (t_str *, t_str *),                 STR)

/* itoa */
X_METHOD(str_itoa,       t_str*,  (t_str *, int32_t),                 NONE)

/* join */
X_METHOD(str_join,       t_str*,  (t_str *, const char *, int32_t),   CHARP_N)
X_METHOD(str_join,       t_str*,  (t_str *, t_str *, int32_t),        STR_N)

/* last */
X_METHOD(str_last,       t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_last,       t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_last,       t_str*,  (t_str *, t_str *),                 STR)

/* lower / upper / reverse / sort */
X_METHOD(str_lower,      t_str*,  (t_str *),                          NONE)
X_METHOD(str_upper,      t_str*,  (t_str *),                          NONE)
X_METHOD(str_reverse,    t_str*,  (t_str *),                          NONE)
X_METHOD(str_sort,       t_str*,  (t_str *),                          NONE)

/* ncmp */
X_METHOD(str_ncmp,       int32_t, (t_str *, char *, int32_t),         CHAR_N)
X_METHOD(str_ncmp,       int32_t, (t_str *, t_str *, int32_t),        STR_N)

/* rdiff */
X_METHOD(str_rdiff,      t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_rdiff,      t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_rdiff,      t_str*,  (t_str *, t_str *),                 STR)

/* rfind */
X_METHOD(str_rfind,      t_str*,  (t_str *, char),                    CHR)
X_METHOD(str_rfind,      t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_rfind,      t_str*,  (t_str *, t_str *),                 STR)

/* satoi */
X_METHOD(str_satoi,      err,     (t_str *, int *),                   NONE)

/* sdup */
X_METHOD(str_sdup,       t_str*,  (t_str *, const char *),            CHARP)
X_METHOD(str_sdup,       t_str*,  (t_str *, t_str *),                 STR)



#endif