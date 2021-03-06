/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSCFGPROVIDER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSCFGPROVIDER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "vsshell.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsCfgProviderNotImpl :
	public IVsCfgProvider
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsCfgProviderNotImpl)

public:

	typedef IVsCfgProvider Interface;

	STDMETHOD(GetCfgs)(
		/*[in]*/ ULONG /*celt*/,
		/*[in,out,size_is(celt)]*/ IVsCfg*[] /*rgpcfg*/,
		/*[out,optional]*/ ULONG* /*pcActual*/,
		/*[out,optional]*/ VSCFGFLAGS* /*prgfFlags*/)VSL_STDMETHOD_NOTIMPL
};

class IVsCfgProviderMockImpl :
	public IVsCfgProvider,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsCfgProviderMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsCfgProviderMockImpl)

	typedef IVsCfgProvider Interface;
	struct GetCfgsValidValues
	{
		/*[in]*/ ULONG celt;
		/*[in,out,size_is(celt)]*/ IVsCfg** rgpcfg;
		/*[out,optional]*/ ULONG* pcActual;
		/*[out,optional]*/ VSCFGFLAGS* prgfFlags;
		HRESULT retValue;
	};

	STDMETHOD(GetCfgs)(
		/*[in]*/ ULONG celt,
		/*[in,out,size_is(celt)]*/ IVsCfg* rgpcfg[],
		/*[out,optional]*/ ULONG* pcActual,
		/*[out,optional]*/ VSCFGFLAGS* prgfFlags)
	{
		VSL_DEFINE_MOCK_METHOD(GetCfgs)

		VSL_CHECK_VALIDVALUE(celt);

		VSL_SET_VALIDVALUE_INTERFACEARRAY(rgpcfg, celt, validValues.celt);

		VSL_SET_VALIDVALUE(pcActual);

		VSL_SET_VALIDVALUE(prgfFlags);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSCFGPROVIDER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
