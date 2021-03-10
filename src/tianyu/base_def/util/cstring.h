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
    __IN__ struct c_struct_string  __PTR__ str,
    __IN__ string                  __VAR__ cstr,
    __IN__ int32                   __VAR__ length
);
typedef bool   __VAR__ (__PTR__ c_struct_string_isnull)
(
    __IN__ struct c_struct_string  __PTR__ str
);

typedef struct c_struct_string
{
    c_struct_string_getlength   __VAR__ Length;
    c_struct_string_getstring   __VAR__ String;
    c_struct_string_setstring   __VAR__ Set;
    c_struct_string_isnull      __VAR__ IsNull;
}CStructString;

#endif // !__TIANYUBASEDEF_UTIL_CSTRING__