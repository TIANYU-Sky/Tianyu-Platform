/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/util/cstring.h
 *	简要描述:用于为天宇系列程序提供统一的字符串结构体操作（C/C++）
 *
 *	创建日期:	2021-03-10
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#pragma once
#ifndef __TIANYUBASEDEF_UTIL_CSTRING__
#define __TIANYUBASEDEF_UTIL_CSTRING__

#include"../define.h"
#include"../bdt.h"
#include"../constvalue.h"
#include"carray.h"

#define __STRING_EMPTY__ ""

__PRE__ struct c_struct_string;

typedef int32   __VAR__ (__PTR__ c_struct_string_getlength)
(
    __IN__ struct c_struct_string __PTR__ cstring
);
typedef string  __VAR__ (__PTR__ c_struct_string_getstring)
(
    __IN__ struct c_struct_string __PTR__ cstring
);
typedef bool    __VAR__ (__PTR__ c_struct_string_setstring)
(
    __IN__ struct c_struct_string __PTR__ str,
    __IN__                 string __VAR__ cstr,
    __IN__                  int32 __VAR__ length
);
typedef bool    __VAR__ (__PTR__ c_struct_string_isnull)
(
    __IN__ struct c_struct_string __PTR__ str
);
typedef object  __VAR__ (__PTR__ c_struct_string_clone)();
typedef int32   __VAR__ (__PTR__ c_struct_string_comparetostring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ obj
);
typedef bool    __VAR__ (__PTR__ c_struct_string_containsstring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ obj
);
typedef bool    __VAR__ (__PTR__ c_stuct_string_containschar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ obj
);
typedef void    __VAR__ (__PTR__ c_struct_string_copyto)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                  int32 __VAR__ source_index,
    __IN__ struct c_struct_string __PTR__ target,
    __IN__                  int32 __VAR__ target_index,
    __IN__                  int32 __VAR__ count
);
typedef bool    __VAR__ (__PTR__ c_struct_string_endswithchar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ end_char
);
typedef bool    __VAR__ (__PTR__ c_struct_string_endswithstring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ end_char
);
typedef string  __VAR__ (__PTR__ c_struct_string_index)
(
    __IN__ struct c_struct_string __PTR__ cstring
);
typedef int32   __VAR__ (__PTR__ c_struct_string_gethashcode)
(
    __IN__ struct c_struct_string __PTR__ cstring
);
typedef int32   __VAR__ (__PTR__ c_struct_string_indexofstring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ obj
);
typedef int32   __VAR__ (__PTR__ c_struct_string_indexofchar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ obj
);
typedef void    __VAR__ (__PTR__ c_struct_string_insertchar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ insert_char
);
typedef void    __VAR__ (__PTR__ c_struct_string_insertstring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ insert_string
);
typedef void    __VAR__ (__PTR__ c_struct_string_replacestrtostr)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ src_string,
    __IN__ struct c_struct_string __PTR__ tar_string
);
typedef void    __VAR__ (__PTR__ c_struct_string_replacechartochar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ src_char,
    __IN__                   char __VAR__ tar_char
);
typedef void    __VAR__ (__PTR__ c_struct_string_replacechartostr)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ src_char,
    __IN__ struct c_struct_string __PTR__ tar_string
);
typedef void    __VAR__ (__PTR__ c_struct_string_replacestrtochar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ src_string,
    __IN__                   char __VAR__ tar_char
);
typedef void    __VAR__ (__PTR__ c_struct_string_removechar)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__                   char __VAR__ remove_char
);
typedef void    __VAR__ (__PTR__ c_struct_string_removestring)
(
    __IN__ struct c_struct_string __PTR__ cstring,
    __IN__ struct c_struct_string __PTR__ remove_string
);
typedef string  __PTR__ (__PTR__ c_struct_string_splitwithchar)
(
    __IN__ struct c_struct_string __PTR__ cstring
);

typedef struct c_struct_string
{
    c_struct_string_getlength           __VAR__ Length;
    c_struct_string_getstring           __VAR__ String;
    c_struct_string_setstring           __VAR__ Set;
    c_struct_string_isnull              __VAR__ IsNull;
    c_struct_string_clone               __VAR__ Clone;
    c_struct_string_comparetostring     __VAR__ CompareToString;
    c_struct_string_containsstring      __VAR__ ContainsString;
    c_stuct_string_containschar         __VAR__ ContainsChar;
    c_struct_string_copyto              __VAR__ CopyTo;
    c_struct_string_endswithchar        __VAR__ EndsWithChar;
    c_struct_string_endswithstring      __VAR__ EndsWithString;
    c_struct_string_index               __VAR__ Index;
    c_struct_string_gethashcode         __VAR__ GetHashcode;
    c_struct_string_indexofstring       __VAR__ IndexOfString;
    c_struct_string_indexofchar         __VAR__ IndexOfChar;
    c_struct_string_insertchar          __VAR__ InsertChar;
    c_struct_string_insertstring        __VAR__ InsertString;
    c_struct_string_replacestrtostr     __VAR__ ReplaceStringToString;
    c_struct_string_replacechartochar   __VAR__ ReplaceCharToChar;
    c_struct_string_replacechartostr    __VAR__ ReplaceCharToString;
    c_struct_string_replacestrtochar    __VAR__ ReplaceStringToChar;
    c_struct_string_removechar          __VAR__ RemoveChar;
    c_struct_string_removestring        __VAR__ RemoveString;

}CStructString;


struct c_struct_string __VAR__ CStringFormat
(
    __IN__ string __VAR__ str,
    __IN__ ...
);

#endif // !__TIANYUBASEDEF_UTIL_CSTRING__