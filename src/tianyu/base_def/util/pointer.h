/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/util/pointer.h
 *	简要描述:用于为天宇系列程序提供较为安全的指针类型定义与操作（C/C++）
 *
 *	创建日期:	2021-03-16
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#pragma once
#ifndef __TIANYUBASEDEF_UTIL_POINTER__
#define __TIANYUBASEDEF_UTIL_POINTER__

#include"../define.h"
#include"../bdt.h"
#include"../constvalue.h"
#include<stdlib.h>

#define __NEW_PTR__(type) New(sizeof(type))
#define __NEW_PTR_T__(obj, size) New_With_PTR(obj, size)
// 类型索引值计算宏定义（内部使用）
#define __PTR_CAL_INDEX__(index, type) (index * sizeof(type))
// 获取指针并完成类型转换
#define __PTR_GET__(ptr, type) ((type __PTR__)(ptr->GetPTR(ptr)))
// 根据指针索引获取指定类型的对象
#define __PTR_INDEX__(ptr, index, type) ((type __PTR__)(ptr->Index(ptr, __PTR_CAL_INDEX__(index, type))))
// 获取指针是否为空
#define __PTR_ISNULL__(ptr) (ptr->IsNull(ptr))
// 获取指针地址
#define __PTR_LOCATE__(ptr) (ptr->GetLocation(ptr))
// 获取指针分配内存大小
#define __PTR_SIZE__(ptr) (ptr->GetSize(ptr))

// 解除计算值宏定义
#undef __PTR_CAL_INDEX__(index, type)

#ifdef __cplusplus
__C__  // 取消用于C++的类型重载
{
#endif

// 预定义：C语言结构体指针类型
__PRE__ struct c_struct_pointer;

// C语言结构体指针类型函数接口：获取指针
typedef object  __VAR__ (__PTR__ c_struct_pointer_getptr)
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
);
// C语言结构体指针类型函数接口：获取是否为空指针
// 进行指针操作前应进行判断
typedef bool    __VAR__ (__PTR__ c_struct_pointer_isnull)
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
);
// C语言结构体指针类型函数接口：获取指针地址
typedef uint64  __VAR__ (__PTR__ c_struct_pointer_getlocation)
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
);
// C语言结构体指针类型函数接口：获取指针空间大小
typedef size_t  __VAR__ (__PTR__ c_struct_pointer_getsize)
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
);
// C语言结构体指针类型函数接口：指针索引（内部实现越界保护）
typedef object  __VAR__ (__PTR__ c_struct_pointer_index)
(
    __OO__ struct c_struct_pointer  __PTR__ ptr,
    __IN__                   int32  __VAR__ index 
);

// C语言结构体指针接口
typedef struct c_struct_pointer
{
    c_struct_pointer_getptr         __VAR__ GetPTR;
    c_struct_pointer_isnull         __VAR__ IsNull;
    c_struct_pointer_getlocation    __VAR__ GetLocation;
    c_struct_pointer_getsize        __VAR__ GetSize;
    c_struct_pointer_index          __VAR__ Index;
}PTR;

// 创建指针对象并指向指定大小的空间
PTR     __PTR__ New
(
    __IN__ size_t   __VAR__ mem_size
);
PTR     __PTR__ New_With_PTR
(
    __IN__ object   __VAR__ obj,
    __IN__ size_t   __VAR__ mem_size
);
// 将指定的指针对象删除
void    __VAR__ Delete
(
    __IN__ PTR      __PTR__ pointer
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUBASEDEF_UTIL_POINTER__