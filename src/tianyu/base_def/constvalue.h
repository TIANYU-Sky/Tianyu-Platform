/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/constvalue.h
 *	简要描述:用于为天宇系列程序提供统一的静态值定义（C/C++）
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
#ifndef __TIANYUBASEDEF_CONSTVALUE__
#define __TIANYUBASEDEF_CONSTVALUE__

#define __SCHAR_MIN__	(-128)	// 有符号字符类型最小值
#define __SCHAR_MAX__	127		// 有符号字符类型最大值
#define __UCHAR_MIN__	0		// 无符号字符类型最小值
#define __UCHAR_MAX__	0xFF	// 服务号字符类型最大值

#define __SINT8_MIN__	(-128)	// 8位有符号整数最小值
#define __SINT8_MAX__	127		// 8位有符号整数最大值
#define __UINT8_MIN__	0		// 8位无符号整数最小值
#define __UINT8_MAX__	0xFF	// 8位无符号整数最大值

#define __SINT16_MIN__	(-32768)	// 16位有符号整数最小值
#define __SINT16_MAX__	32767		// 16位有符号整数最大值
#define __UINT16_MIN__	0			// 16位无符号整数最小值
#define __UINT16_MAX__	0xFFFF		// 16位无符号整数最大值

#define __SINT32_MIN__	(-2147483648)	// 32位有符号整数最小值
#define __SINT32_MAX__	2147483647		// 32位有符号整数最大值
#define __UINT32_MIN__	0				// 32位无符号整数最小值
#define __UINT32_MAX__	0xFFFFFFFF		// 32位无符号整数最大值

#define __SINT64_MIN__	(-9223372036854775808)	// 64位有符号整数最小值
#define __SINT64_MAX__	9223372036854775807		// 64位有符号整数最大值
#define __UINT64_MIN__	0						// 64位无符号整数最小值
#define __UINT64_MAX__	0xFFFFFFFFFFFFFFFF		// 64位无符号整数最大值

#endif // !__TIANYUBASEDEF_CONSTVALUE__
