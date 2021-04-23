/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/define.h
 *	简要描述:用于为天宇系列程序提供统一的符号定义（C/C++）
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
#ifndef __TIANYUBASEDEF_DEFINE__
#define __TIANYUBASEDEF_DEFINE__

#define __PRE__		// 前向声明标签（用于函数、结构体、类、接口的前向引用声明）

#define __VAR__		// 值类型标签
#define __PTR__ *	// 指针类型标签（C/C++） | 类型转换：指针→引用（C++）

#define __PTV__ *	// 类型转换：指针→值
#define __VTP__ &	// 类型转换：值→指针

#define __OO__      // 用于模拟OO时使用的本地对象传入标签
#define __IN__		// 输入参数标签
#define __OT__		// 输出参数标签
#define __IO__		// 输入输出参数标签

#define __REQ__		// 请求方法标签
#define __RSE__		// 回复方法标签

#define NULL ((void __PTR__)0)

// C++定义部分
#ifdef __cplusplus

constexpr auto null = nullptr;		// 空指针限定符定义

#define _Public		public:			// 重定义：定义用的公有访问控制符
#define _Private	private:		// 重定义：定义用的私有访问控制符
#define _Protected	protected:		// 重定义：定义用的保护访问控制符
#define _THIS		*this			// 本地对象访问关键字

#define _abstruct					// 抽象类型标签
#define _interface _abstruct class  // 接口定义关键字
#define __C__		extern "C"		// C语言模式编译块
#define __TYCORE__	TianyuCore		// 天宇核心命名空间标签

#define __REF__	&	// 引用类型标签
#define __PAR__	*&	// 指针引用类型标签

#define __RTP__	&	// 类型转换：引用→指针
#define __RTV__		// 类型转换：引用→值
#define __VTR__		// 类型转换：值→引用

#define __IF__		// 接口函数标签
#define __RF__		// 接口函数实现标签
#define __OF__		// 函数重载标签

#else

#define true	1	// 布尔真：用于C语言的布尔操作宏定义
#define false	0	// 布尔假：用于C语言的布尔操作定义

#endif // __cplusplus

#endif // !__TIANYUBASEDEF_DEFINE__
