#ifndef SUMCOM_H
#define SUMCOM_H

#include "ISum.h"
// {74593114-91A0-4272-979B-CD6617AE51D9}
static const GUID CLSID_SUM =
    { 0x74593114, 0x91a0, 0x4272, { 0x97, 0x9b, 0xcd, 0x66, 0x17, 0xae, 0x51, 0xd9 } };


class SumCom : public ISum
{
public:
    SumCom();
    //IUnknown
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,void  **ppv);
    virtual ULONG   STDMETHODCALLTYPE AddRef(void);
    virtual ULONG   STDMETHODCALLTYPE Release(void);

    //ISUM
    virtual HRESULT STDMETHODCALLTYPE Add(const double x, const double y, double& z);
    virtual HRESULT STDMETHODCALLTYPE Sub(const double x, const double y, double& z);

protected:
    volatile long m_lRef;
};

#endif // SUMCOM_H
