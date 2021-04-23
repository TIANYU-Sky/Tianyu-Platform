/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/util/carray.h
 *	简要描述:用于为天宇系列程序提供统一的数组类型定义（C/C++）
 *
 *	创建日期:	2021-03-12
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#pragma once
#ifndef __TIANYUBASEDEF_UTIL_CARRAY__
#define __TIANYUBASEDEF_UTIL_CARRAY__

#include"../define.h"
#include"../bdt.h"
#include"../constvalue.h"

#define __LARRAY_NEW__(length, type) NewLinearArray(length, sizeof(type))
#define __LARRAY__(larray, type) ((type __PTR__)(larray->Array(larray))) 
#define __LARRAY_INDEX__(larray, index, type) ((type __PTR__)(larray->Index(larray, index)))
#define __LARRAY_LENGTH__(larray) (larray->Length(larray))
#define __LARRAY_TYPESIZE__(larray) (larray->TypeSize(larray))

#define __DARRAY_NEW__(len_1, len_2, type) NewDoubleArray(len_1, len_2, sizeof(type))
#define __DARRAY__(darray, type) ((type __PTR__)(darray->Array(darray)))
#define __DARRAY_INDEX__(darray, index_1, index_2, type) ((type __PTR__)(darray->Index(darray, index_1, index_2)))

#define __TARRAY_NEW__(len_1, len_2, len_3, type) NewThirdArray(len_1, len_2, len_3, sizeof(type))
#define __DARRAY__(tarray, type) ((type __PTR__)(tarray->Array(tarray))) 
#define __DARRAY_INDEX__(tarray, index_1, index_2, index_3, type) ((type __PTR__)(tarray->Index(tarray, index_1, index_2, index_3)))

#ifdef __cplusplus
__C__  // 取消用于C++的类型重载
{
#endif
/**
 * 本部分主要定义三种基本的数组类型定义
*/

// 一维数组的基本定义
__PRE__ struct c_struct_linear_array;

typedef int32   __VAR__ (__PTR__ c_struct_linear_array_getlength)
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
);
typedef object  __VAR__ (__PTR__ c_struct_linear_array_getarray)
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
);
typedef object  __VAR__ (__PTR__ c_struct_linear_array_index)
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array,
    __IN__                        int32 __VAR__ index
);
typedef int32   __VAR__ (__PTR__ c_struct_linear_array_typesize)
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
);

typedef struct c_struct_linear_array
{
    c_struct_linear_array_getlength __VAR__ Length;
    c_struct_linear_array_index     __VAR__ Index;
    c_struct_linear_array_typesize  __VAR__ TypeSize;
    c_struct_linear_array_getarray  __VAR__ Array;
}CLinearArray;

CLinearArray    __PTR__ NewLinearArray
(
    __IN__ int32 __VAR__ array_len,
    __IN__ int32 __VAR__ type_size
);
void            __VAR__ DeleteLinearArray
(
    __IN__ CLinearArray __PTR__ linear_array
);

// 二维数组的基本定义
/**
 * 二维数组由一维数组组成，二维数组内部采用一维数组作为元素
 * 除了提供与一维数组相同的接口外，还提供二维数组特定的读取方式
*/
__PRE__ struct c_struct_double_array;

typedef int32           __VAR__ (__PTR__ c_struct_double_array_getlength)
(
    __OO__ struct c_struct_double_array __PTR__ double_array
);
typedef object          __VAR__ (__PTR__ c_struct_double_array_getarray)
(
    __OO__ struct c_struct_double_array __PTR__ double_array
);
typedef object          __VAR__ (__PTR__ c_struct_double_array_index)
(
    __OO__ struct c_struct_double_array __PTR__ double_array,
    __IN__                        int32 __VAR__ index_1,
    __IN__                        int32 __VAR__ index_2
);
typedef CLinearArray    __PTR__ (__PTR__ c_struct_double_array_getlinear)
(
    __OO__ struct c_struct_double_array __PTR__ double_array,
    __IN__                        int32 __VAR__ index
);
typedef int32           __VAR__ (__PTR__ c_struct_double_array_typesize)
(
    __OO__ struct c_struct_double_array __PTR__ double_array
);

typedef struct c_struct_double_array
{
    c_struct_double_array_getlength __VAR__ Length;
    c_struct_double_array_index     __VAR__ Index;
    c_struct_double_array_getlinear __VAR__ LowOrder;
    c_struct_double_array_typesize  __VAR__ TypeSize;
    c_struct_double_array_getarray  __VAR__ Array;
}CDoubleArray;

CDoubleArray    __PTR__ NewDoubleArray
(
    __IN__ int32 __VAR__ array_len_1,
    __IN__ int32 __VAR__ array_len_2,
    __IN__ int32 __VAR__ type_size
);
void            __VAR__ DeleteDoubleArray
(
    __IN__ CDoubleArray __PTR__ double_array
);


// 三维数组的基本定义
__PRE__ struct c_struct_third_array;

typedef int32           __VAR__(__PTR__ c_struct_third_array_getlength)
(
    __OO__ struct c_struct_third_array __PTR__ third_array
);
typedef object          __VAR__(__PTR__ c_struct_third_array_getarray)
(
    __OO__ struct c_struct_third_array __PTR__ third_array
);
typedef object          __VAR__(__PTR__ c_struct_third_array_index)
(
    __OO__ struct c_struct_third_array __PTR__ third_array,
    __IN__                        int32 __VAR__ index_1,
    __IN__                        int32 __VAR__ index_2,
    __IN__                        int32 __VAR__ index_3
);
typedef CDoubleArray    __PTR__(__PTR__ c_struct_third_array_getdouble)
(
    __OO__ struct c_struct_third_array __PTR__ third_array,
    __IN__                        int32 __VAR__ index
);
typedef int32           __VAR__(__PTR__ c_struct_third_array_typesize)
(
    __OO__ struct c_struct_third_array __PTR__ third_array
);

typedef struct c_struct_third_array
{
    c_struct_third_array_getlength __VAR__ Length;
    c_struct_third_array_index     __VAR__ Index;
    c_struct_third_array_getdouble __VAR__ LowOrder;
    c_struct_third_array_typesize  __VAR__ TypeSize;
    c_struct_third_array_getarray  __VAR__ Array;
}CThirdArray;

CThirdArray    __PTR__ NewThirdArray
(
    __IN__ int32 __VAR__ array_len_1,
    __IN__ int32 __VAR__ array_len_2,
    __IN__ int32 __VAR__ array_len_3,
    __IN__ int32 __VAR__ type_size
);
void            __VAR__ DeleteThirdArray
(
    __IN__ CThirdArray __PTR__ third_array
);