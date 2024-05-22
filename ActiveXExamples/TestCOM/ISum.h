#ifndef ISUM_H
#define ISUM_H
#include <ObjBase.h>

// {26032682-E09F-4bd2-B4CA-511FEF6F40FE}
// {26032682-E09F-4bd2-B4CA-511FEF6F40FE}
static const GUID IID_ISUM =
    { 0x26032682, 0xe09f, 0x4bd2, { 0xb4, 0xca, 0x51, 0x1f, 0xef, 0x6f, 0x40, 0xfe } };


interface ISum:IUnknown {
    virtual HRESULT  __stdcall Add(
        const double x,   // [in] x
        const double y,   // [in] y
        double& z         // [out] z = x+y
        ) = 0;
    virtual HRESULT  __stdcall Sub(
        const double x,   // [in]
        const double y,   // [in]
        double& z        // [out] z = x-y
        ) = 0;
};

#endif // ISUM_H
