/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/util/pointer.c
 *	简要描述:天宇指针类型的实现（C/C++）
 *
 *	创建日期:	2021-03-16
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#include"pointer.h"

typedef struct csp_relization
{
    PTR     __VAR__ _Base;      // 指针接口

    object  __VAR__ _Pointer;   // 无类型指针
    int32   __VAR__ _Size;      // 指针空间大小
}PTRRelization;

object  __VAR__ csp_getptr
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
)
{
    if (NULL == ptr)    // 访问指针为空指针
    {
        // TODO: 此处引发异常操作
        return NULL;
    }

    return ((PTRRelization __PTR__)ptr)->_Pointer;
}
bool    __VAR__ csp_isnull
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
)
{
    
    if (NULL == ptr)    // 访问指针为空指针
    {
        // TODO: 此处引发异常操作
        return true;
    }

    return NULL == ((PTRRelization __PTR__)ptr)->_Pointer;
}
uint64  __VAR__ csp_getlocation
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
)
{
    if (NULL == ptr)    // 访问指针为空指针
    {
        // TODO: 此处引发异常操作
        return -1;
    }

    return (uint64)(((PTRRelization __PTR__)ptr)->_Pointer);
}
size_t  __VAR__ csp_getsize
(
    __OO__ struct c_struct_pointer  __PTR__ ptr 
)
{
    if (NULL == ptr)    // 访问指针为空指针
    {
        // TODO: 此处引发异常操作
        return -1;
    }

    return (size_t)(((PTRRelization __PTR__)ptr)->_Size);
}
object  __VAR__ csp_index
(
    __OO__ struct c_struct_pointer  __PTR__ ptr,
    __IN__                   int32  __VAR__ index 
)
{
    if (NULL == ptr)    // 访问指针为空指针
    {
        // TODO: 此处引发异常操作
        return NULL;
    }

    if (0 > index)  // 尝试访问指针地址之前的空间
    {
        // TODO: 此处引发异常操作
        return NULL;
    }

    PTRRelization __PTR__ ptrrel = (PTRRelization __PTR__)ptr;  // 将接口转换为实现类

    if (index > ptrrel->_Size)  // 尝试访问指针地址之后的空间
    {
        // TODO: 此处引发异常操作
        return NULL;
    }

    return (object)((uint64)(ptrrel->_Pointer) + index);
}

PTR     __PTR__ New
(
    __IN__ size_t   __VAR__ mem_size
)
{
    PTRRelization __PTR__ ptr = (PTRRelization __PTR__)malloc(sizeof(PTRRelization));
    
    if (NULL == ptr)
        return NULL;
    
    ptr->_Base.GetPTR = csp_getptr;
    ptr->_Base.IsNull = csp_isnull;
    ptr->_Base.GetSize = csp_getsize;
    ptr->_Base.GetLocation = csp_getlocation;
    ptr->_Base.Index = csp_index;

    ptr->_Size = mem_size;
    
#ifdef _WIN32 || _WIN64
    ptr->_Pointer = malloc(mem_size);
#else
    ptr->_Pointer = malloc(mem_size);
#endif

    if (NULL == ptr->_Pointer)
    {
        // TODO: 此处引发异常操作
    }

    return (PTR __PTR__)ptr;
}
PTR     __PTR__ New_With_PTR
(
    __IN__ object   __VAR__ obj,
    __IN__ size_t   __VAR__ mem_size
)
{
    if (NULL == obj)
        return NULL;
    
    PTRRelization __PTR__ ptr = (PTRRelization __PTR__)malloc(sizeof(PTRRelization));
    
    ptr->_Pointer = obj;

    ptr->_Base.GetPTR = csp_getptr;
    ptr->_Base.IsNull = csp_isnull;
    ptr->_Base.GetSize = csp_getsize;
    ptr->_Base.GetLocation = csp_getlocation;
    ptr->_Base.Index = csp_index;

    ptr->_Size = mem_size;
    
    return (PTR __PTR__)ptr;
}
void    __VAR__ Delete
(
    __IN__ PTR      __PTR__ pointer
)
{
    if (NULL == pointer)
        return;
    
    free(((PTRRelization __PTR__)pointer)->_Pointer);
    free(pointer);
}