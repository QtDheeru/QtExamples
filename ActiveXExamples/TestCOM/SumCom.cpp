#include "SumCom.h"

SumCom::SumCom() {}

HRESULT STDMETHODCALLTYPE SumCom::QueryInterface(REFIID riid,void  **ppv) {
    HRESULT rc = S_OK;
    *ppv = NULL;

    if (riid == IID_IUnknown)
        *ppv = (ISum*)this;
    else
        if (riid == IID_ISUM)
                *ppv = (ISum*)this;
    if (rc == S_OK) this->AddRef();

    return rc;
}

ULONG SumCom::AddRef()
{
    InterlockedIncrement(&m_lRef);
    return this->m_lRef;
}

ULONG SumCom::Release()
{
    return this->m_lRef;
}

HRESULT SumCom::Add(const double x, const double y, double &z)
{

    return S_OK;
}

HRESULT SumCom::Sub(const double x, const double y, double &z)
{

    return S_OK;
}
