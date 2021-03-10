/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/bdt.h
 *	简要描述:用于为天宇系列程序提供统一的基本数据类型定义（C/C++）
 *
 *	创建日期:	2020-11-27
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#pragma once
#ifndef __TIANYUBASEDEF_BASEDATATYPE__
#define __TIANYUBASEDEF_BASEDATATYPE__

#include"define.h"

typedef       unsigned char uchar;      // 重定义：无符号字符
typedef         signed char sbyte;      // 重定义：有符号字节（8位整数）
typedef       unsigned char byte;       // 重定义：无符号字节（8位整数）
typedef         signed char int8;       // 重定义：有符号8位整数
typedef       unsigned char uint8;      // 重定义：无符号8位整数
typedef               short int16;      // 重定义：有符号16位整数
typedef      unsigned short uint16;     // 重定义：无符号16位整数
typedef                 int int32;      // 重定义：有符号32位整数
typedef        unsigned int uint32;     // 重定义：无符号32位整数
typedef           long long int64;      // 重定义：有符号64位整数
typedef  unsigned long long uint64;     // 重定义：无符号64位整数
typedef        void __PTR__ object;     // 重定义：任意类型
typedef        char __PTR__ string;     // 重定义：字符串类型
typedef                char error;      // 重定义：错误定义类型（8位整数）

#ifndef __cplusplus
typedef unsigned char bool;     // 用于C语言的布尔类型结构定义
#endif // !__cplusplus

#endif // !__TIANYUBASEDEF_BASEDATATYPE__
