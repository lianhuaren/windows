/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSTEXTMARKERCLIENTADVANCED_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSTEXTMARKERCLIENTADVANCED_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "textmgr2.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsTextMarkerClientAdvancedNotImpl :
	public IVsTextMarkerClientAdvanced
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsTextMarkerClientAdvancedNotImpl)

public:

	typedef IVsTextMarkerClientAdvanced Interface;

	STDMETHOD(OnMarkerTextChanged)(
		/*[in]*/ IVsTextMarker* /*pMarker*/)VSL_STDMETHOD_NOTIMPL
};

class IVsTextMarkerClientAdvancedMockImpl :
	public IVsTextMarkerClientAdvanced,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsTextMarkerClientAdvancedMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsTextMarkerClientAdvancedMockImpl)

	typedef IVsTextMarkerClientAdvanced Interface;
	struct OnMarkerTextChangedValidValues
	{
		/*[in]*/ IVsTextMarker* pMarker;
		HRESULT retValue;
	};

	STDMETHOD(OnMarkerTextChanged)(
		/*[in]*/ IVsTextMarker* pMarker)
	{
		VSL_DEFINE_MOCK_METHOD(OnMarkerTextChanged)

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pMarker);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSTEXTMARKERCLIENTADVANCED_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
