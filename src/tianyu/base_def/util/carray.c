/*******************************************************************
 *	Copyright(c) 2020-2030 Mi Rabbit
 *  All rights reserved.
 *
 *	文件名称:Tianyu/base_def/util/carray.h
 *	简要描述:天宇系列程序通用数组类型的实现（C/C++）
 *
 *	创建日期:	2021-03-17
 *	作者:	Mi Rabbit
 *	说明:	创建文档
 *
 *	修改日期:
 *	作者:
 *	说明:
 ******************************************************************/

#include"carray.h"
#include"pointer.h"

/**
 * 本部分主要定义三种基本的数组类型的实现
*/

// 一维数组的包装定义与实现

#pragma region 一维数组实现

typedef struct clarelization
{
    CLinearArray    __VAR__ _Base;

    PTR             __PTR__ _Elements;
    int32           __VAR__ _Length;
    int32           __VAR__ _TypeSize;
    bool            __VAR__ _Freeable;
}CLARelization;

int32   __VAR__ linear_array_getlength
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
)
{
    if (NULL == linear_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return ((CLARelization __PTR__)linear_array)->_Length;
}
object  __VAR__ linear_array_array
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
)
{
    if (NULL == linear_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    return ((CLARelization __PTR__)linear_array)->_Elements->GetPTR(((CLARelization __PTR__)linear_array)->_Elements);
}
object  __VAR__ linear_array_index
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array,
    __IN__                        int32 __VAR__ index
)
{
    if (NULL == linear_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    CLARelization __PTR__ larray = (CLARelization __PTR__)linear_array;
    // 检查索引状态
    if (0 > index || index >= larray->_Length)
    {
        // TODO: 异常处理
        return NULL;
    }

    return larray->_Elements->Index(larray->_Elements, index * larray->_TypeSize);
}
int32   __VAR__ linear_array_typesize
(
    __OO__ struct c_struct_linear_array __PTR__ linear_array
)
{
    if (NULL == linear_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return ((CLARelization __PTR__)linear_array)->_TypeSize;
}

CLinearArray    __PTR__ NewLinearArray
(
    __IN__ int32 __VAR__ array_len,
    __IN__ int32 __VAR__ type_size
)
{
    CLARelization __PTR__ clar = (CLARelization __PTR__)malloc(sizeof(CLARelization));

    if (NULL == clar)
    {
        // TODO: 异常处理
        return NULL;
    }

    clar->_Elements = New(array_len * type_size);
    if (NULL == clar->_Elements)
    {
        // TODO: 异常处理
        free(clar); // 释放CLARelization实例
        return NULL;
    }

    clar->_Length = array_len;
    clar->_TypeSize = type_size;
    clar->_Freeable = true;
    clar->_Base.Index = linear_array_index;
    clar->_Base.Length = linear_array_getlength;
    clar->_Base.TypeSize = linear_array_typesize;
    clar->_Base.Array = linear_array_array;

    return (CLinearArray __PTR__)clar;
}
void            __VAR__ DeleteLinearArray
(
    __IN__ CLinearArray __PTR__ linear_array
)
{
    if (NULL == linear_array)
        return;
    
    if (((CLARelization __PTR__)linear_array)->_Freeable)
        Delete(((CLARelization __PTR__)linear_array)->_Elements);
    free(linear_array);
}

#pragma endregion

#pragma region 二维数组实现

// 二维数组的包装定义与实现
typedef struct cdarelization
{
    CDoubleArray    __VAR__ _Base;

    PTR             __PTR__ _Elements;
    int32           __VAR__ _LengthFirst;
    int32           __VAR__ _LengthSecond;
    int32           __VAR__ _TypeSize;
    bool            __VAR__ _Freeable;
}CDARelization;

int32           __VAR__ double_array_getlength
(
    __OO__ struct c_struct_double_array __PTR__ double_array
)
{
    if (NULL == double_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return  ((CDARelization __PTR__)double_array)->_LengthFirst;
}
object          __VAR__ double_array_getarray
(
    __OO__ struct c_struct_double_array __PTR__ double_array
)
{
    if (NULL == double_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    return  ((CDARelization __PTR__)double_array)->_Elements->GetPTR(((CDARelization __PTR__)double_array)->_Elements);
}
object          __VAR__ double_array_index
(
    __OO__ struct c_struct_double_array __PTR__ double_array,
    __IN__                        int32 __VAR__ index_1,
    __IN__                        int32 __VAR__ index_2
)
{
    if (NULL == double_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    CDARelization __PTR__ darray = (CDARelization __PTR__)double_array;

    if 
    (
        0 > index_1 || 0 > index_2
        || darray->_LengthFirst <= index_1
        || darray->_LengthSecond <= index_2
    )
    {
        // TODO: 异常处理
        return NULL;
    }

    return (object __VAR__)
    (
            ((uint64)(((CDARelization __PTR__)double_array)->_Elements->GetPTR(((CDARelization __PTR__)double_array)->_Elements))) 
            + 
            index_1 * darray->_LengthSecond + index_2
    );
}
CLinearArray    __PTR__ double_array_getlinear
(
    __OO__ struct c_struct_double_array __PTR__ double_array,
    __IN__                        int32 __VAR__ index
)
{
    if (NULL == double_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    CDARelization __PTR__ darray = (CDARelization __PTR__)double_array;

    if (0 > index || darray->_LengthFirst <= index)
    {
        // TODO: 异常处理
        return NULL;
    }

    CLARelization __PTR__ clar = (CLARelization __PTR__)malloc(sizeof(CLARelization));

    if (NULL == clar)
    {
        // TODO: 异常处理
        return NULL;
    }

    clar->_Elements = 
    __NEW_PTR_T__
    (
        (
            (object __VAR__)
            (
                ((uint64)(((CDARelization __PTR__)double_array)->_Elements->GetPTR(((CDARelization __PTR__)double_array)->_Elements))) 
                +
                darray->_LengthSecond * index
            )
        ),
        (
            darray->_LengthSecond * darray->_TypeSize
        )
    );

    clar->_Length = darray->_LengthSecond;
    clar->_TypeSize = darray->_TypeSize;
    clar->_Freeable = false;
    clar->_Base.Index = linear_array_index;
    clar->_Base.Length = linear_array_getlength;
    clar->_Base.TypeSize = linear_array_typesize;
    clar->_Base.Array = linear_array_array;

    return (CLinearArray __PTR__)clar;
}
int32           __VAR__ double_array_typesize
(
    __OO__ struct c_struct_double_array __PTR__ double_array
)
{
    if (NULL == double_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return  ((CDARelization __PTR__)double_array)->_TypeSize;
}

CDoubleArray    __PTR__ NewDoubleArray
(
    __IN__ int32 __VAR__ array_len_1,
    __IN__ int32 __VAR__ array_len_2,
    __IN__ int32 __VAR__ type_size
)
{
    CDARelization __PTR__ cdar = (CDARelization __PTR__)malloc(sizeof(CDARelization));

    if (NULL == cdar)
    {
        // TODO: 异常处理
        return NULL;
    }

    cdar->_Elements = New(array_len_1 * array_len_2 * type_size);
    if (NULL == cdar->_Elements)
    {
        // TODO: 异常处理
        free(clar); // 释放CLARelization实例
        return NULL;
    }

    cdar->_LengthFirst = array_len_1;
    cdar->_LengthSecond = array_len_2;
    cdar->_TypeSize = type_size;
    cdar->_Freeable = true;
    cdar->_Base.Index = double_array_index;
    cdar->_Base.Length = double_array_getlength;
    cdar->_Base.TypeSize = double_array_typesize;
    cdar->_Base.Array = double_array_getarray;
    cdar->_Base.LowOrder = double_array_getlinear;

    return (CLinearArray __PTR__)clar;
}
void            __VAR__ DeleteDoubleArray
(
    __IN__ CDoubleArray __PTR__ double_array
)
{
    if (NULL == double_array)
        return;

    if (((CDARelization __PTR__)double_array)->_Freeable)
        Delete(((CDARelization __PTR__)double_array)->_Elements);
    free(double_array);
}

#pragma endregion

#pragma region 三维数组实现

typedef struct cta_relization
{
    CThirdArray __VAR__ _Base;

    PTR         __PTR__ _Elements;
    int32       __VAR__ _LengthFirst;
    int32       __VAR__ _LengthSecond;
    int32       __VAR__ _LengthThird;
    int32       __VAR__ _TypeSize;
    bool        __VAR__ _Freeable;
}CTARelization;

int32           __VAR__ third_array_getlength
(
    __OO__ struct c_struct_third_array __PTR__ third_array
)
{
    if (NULL == third_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return  ((CTARelization __PTR__)third_array)->_LengthFirst;
}
int32           __VAR__ third_array_typesize
(
    __OO__ struct c_struct_third_array __PTR__ third_array
)
{
    if (NULL == third_array)
    {
        // TODO: 异常处理
        return -1;
    }

    return  ((CTARelization __PTR__)third_array)->_TypeSize;
}
object          __VAR__ third_array_getarray
(
    __OO__ struct c_struct_third_array __PTR__ third_array
)
{
    if (NULL == third_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    return  ((CTARelization __PTR__)third_array)->_Elements->GetPTR(((CTARelization __PTR__)third_array)->_Elements);
}
object          __VAR__ third_array_index
(
    __OO__ struct c_struct_third_array __PTR__ third_array,
    __IN__                       int32 __VAR__ index_1,
    __IN__                       int32 __VAR__ index_2,
    __IN__                       int32 __VAR__ index_3
)
{
    if (NULL == third_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    CTARelization __PTR__ tarray = (CTARelization __PTR__)third_array;

    if
        (
            0 > index_1 || 0 > index_2 || 0 > index_3
            || tarray->_LengthFirst <= index_1
            || tarray->_LengthSecond <= index_2
            || tarray->_LengthThird <= index_3
            )
    {
        // TODO: 异常处理
        return NULL;
    }

    return (object __VAR__)
        (
            ((uint64)(((CTARelization __PTR__)third_array)->_Elements->GetPTR(((CTARelization __PTR__)third_array)->_Elements)))
            +
            index_1 * (tarray->_LengthSecond + tarray->_LengthThird)
            +
            index_2 * tarray->_LengthThird
            +
            index_3
            );
}
CDoubleArray    __PTR__ third_array_loworder
(
    __OO__ struct c_struct_third_array __PTR__ third_array,
    __IN__                       int32 __VAR__ index
)
{
    if (NULL == third_array)
    {
        // TODO: 异常处理
        return NULL;
    }

    CTARelization __PTR__ tarray = (CTARelization __PTR__)third_array;

    if (0 > index || tarray->_LengthFirst <= index)
    {
        // TODO: 异常处理
        return NULL;
    }

    CDARelization __PTR__ cdar = (CDARelization __PTR__)malloc(sizeof(CDARelization));

    if (NULL == cdar)
    {
        // TODO: 异常处理
        return NULL;
    }

    cdar->_Elements =
        __NEW_PTR_T__
        (
            (
                (object __VAR__)
                (
                    ((uint64)(((CTARelization __PTR__)third_array)->_Elements->GetPTR(((CTARelization __PTR__)third_array)->_Elements)))
                    +
                    (tarray->_LengthSecond + tarray->_LengthThird) * index
                    )
                ),
            (
                tarray->_LengthSecond * tarray->_LengthThird * tarray->_TypeSize
                )
        );

    cdar->_Length = tarray->_LengthSecond * tarray->_LengthThird;
    cdar->_TypeSize = tarray->_TypeSize;
    cdar->_Freeable = false;
    cdar->_Base.Index = double_array_index;
    cdar->_Base.Length = double_array_getlength;
    cdar->_Base.TypeSize = double_array_typesize;
    cdar->_Base.Array = double_array_getarray;
    cdar->_Base.LowOrder = double_array_getlinear;

    return (CDoubleArray __PTR__)cdar;
}

CThirdArray    __PTR__ NewThirdArray
(
    __IN__ int32 __VAR__ array_len_1,
    __IN__ int32 __VAR__ array_len_2,
    __IN__ int32 __VAR__ array_len_3,
    __IN__ int32 __VAR__ type_size
)
{
    CTARelization __PTR__ ctar = (CTARelization __PTR__)malloc(sizeof(CTARelization));

    if (NULL == cdar)
    {
        // TODO: 异常处理
        return NULL;
    }

    ctar->_Elements = New(array_len_1 * array_len_2 * array_len_3 * type_size);
    if (NULL == ctar->_Elements)
    {
        // TODO: 异常处理
        free(ctar); // 释放CLARelization实例
        return NULL;
    }

    ctar->_LengthFirst = array_len_1;
    ctar->_LengthSecond = array_len_2;
    ctar->_LengthThird = array_len_3;
    ctar->_TypeSize = type_size;
    ctar->_Freeable = true;
    ctar->_Base.Index = third_array_index;
    ctar->_Base.Length = third_array_getlength;
    ctar->_Base.TypeSize = third_array_typesize;
    ctar->_Base.Array = third_array_getarray;
    ctar->_Base.LowOrder = third_array_loworder;

    return (CThirdArray __PTR__)clar;
}
void            __VAR__ DeleteThirdArray
(
    __IN__ CThirdArray __PTR__ third_array
)
{
    if (NULL == third_array)
        return;

    if (((CTARelization __PTR__)third_array)->_Freeable)
        Delete(((CTARelization __PTR__)third_array)->_Elements);
    free(third_array);
}

#pragma endregion
