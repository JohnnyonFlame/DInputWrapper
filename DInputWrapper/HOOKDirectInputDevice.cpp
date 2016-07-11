#include <windows.h>
#include "stdafx.h"

#include <Strsafe.h>

#include "dinput.h"
#include "HOOKDirectInputDevice.h"

static int   isConfigLoaded = 0;
static float aspect         = 1.77777777777777;

HRESULT WINAPI HOOKDirectInputDevice::QueryInterface(REFIID iid, void ** ppvObject)
{
	return actualDirectInputDevice->QueryInterface(iid, ppvObject);
}

ULONG WINAPI HOOKDirectInputDevice::AddRef(void)
{
	return actualDirectInputDevice->AddRef();
}

ULONG WINAPI HOOKDirectInputDevice::Release(void)
{
	return actualDirectInputDevice->Release();
}

HRESULT WINAPI HOOKDirectInputDevice::Acquire()
{
	return actualDirectInputDevice->Acquire();
}

HRESULT WINAPI HOOKDirectInputDevice::BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags)
{
	return actualDirectInputDevice->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter)
{
	return actualDirectInputDevice->CreateEffect(rguid, lpeff, ppdeff, punkOuter);
}

HRESULT WINAPI HOOKDirectInputDevice::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	return actualDirectInputDevice->EnumCreatedEffectObjects(lpCallback, pvRef, fl);
}

HRESULT WINAPI HOOKDirectInputDevice::EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return actualDirectInputDevice->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT WINAPI HOOKDirectInputDevice::EnumEffectsInFile(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return actualDirectInputDevice->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return actualDirectInputDevice->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::Escape(LPDIEFFESCAPE pesc)
{
	return actualDirectInputDevice->Escape(pesc);
}

HRESULT WINAPI HOOKDirectInputDevice::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return actualDirectInputDevice->GetCapabilities(lpDIDevCaps);
}

HRESULT WINAPI HOOKDirectInputDevice::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	HRESULT res = actualDirectInputDevice->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
	if (FAILED(res))
		return res;

	DWORD i;
	for (i = 0; i < *pdwInOut; i++)
	{
		if (rgdod[i].dwOfs == DIMOFS_Y)
		{
			/*
				Microsoft decided it would be funny to store signed values as DWORD here,
				which means that we'll be doing some ugly casting hacks to work around it.
				I'm sorry if you had to read this code. Blame 'Gates.
			*/

			int value = *(int*)&rgdod[i].dwData;
			rgdod[i].dwData = value * aspect;
		}
	}

	return res;
}

HRESULT WINAPI HOOKDirectInputDevice::GetDeviceInfo(LPDIDEVICEINSTANCE pdidi)
{
	return actualDirectInputDevice->GetDeviceInfo(pdidi);
}

HRESULT WINAPI HOOKDirectInputDevice::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
#if 0
	HRESULT res = actualDirectInputDevice->GetDeviceState(cbData, lpvData);
	if (FAILED(res))
		return res;

	LPDIOBJECTDATAFORMAT obj_dfmt = dformat->rgodf;

	int i, n = dformat->dwNumObjs;
	for (i=0; i<n; i++)
	{
		LPVOID ptr = (char*)lpvData + obj_dfmt[i].dwOfs;
		if (DIDFT_GETTYPE(obj_dfmt[i].dwType) == DIDFT_AXIS)
		{
			if (*obj_dfmt[i].pguid == GUID_YAxis)
				*(LPLONG)ptr *= 3;
		}
	}

	return res;
#endif

	return actualDirectInputDevice->GetDeviceState(cbData, lpvData);
}

HRESULT WINAPI HOOKDirectInputDevice::GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid)
{
	return actualDirectInputDevice->GetEffectInfo(pdei, rguid);
}

HRESULT WINAPI HOOKDirectInputDevice::GetForceFeedbackState(LPDWORD pdwOut)
{
	return actualDirectInputDevice->GetForceFeedbackState(pdwOut);
}

HRESULT WINAPI HOOKDirectInputDevice::GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader)
{
	return actualDirectInputDevice->GetImageInfo(lpdiDevImageInfoHeader);
}

HRESULT WINAPI HOOKDirectInputDevice::GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow)
{
	return actualDirectInputDevice->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT WINAPI HOOKDirectInputDevice::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return actualDirectInputDevice->GetProperty(rguidProp, pdiph);
}

HRESULT WINAPI HOOKDirectInputDevice::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return actualDirectInputDevice->Initialize(hinst, dwVersion, rguid);
}

HRESULT WINAPI HOOKDirectInputDevice::Poll()
{
	return actualDirectInputDevice->Poll();
}

HRESULT WINAPI HOOKDirectInputDevice::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return actualDirectInputDevice->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return actualDirectInputDevice->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT WINAPI HOOKDirectInputDevice::SendForceFeedbackCommand(DWORD dwFlags)
{
	return actualDirectInputDevice->SendForceFeedbackCommand(dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::SetActionMap(LPDIACTIONFORMAT lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags)
{
	return actualDirectInputDevice->SetActionMap(lpdiActionFormat, lptszUserName, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return actualDirectInputDevice->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT WINAPI HOOKDirectInputDevice::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	dformat = lpdf;
	return actualDirectInputDevice->SetDataFormat(lpdf);
}

HRESULT WINAPI HOOKDirectInputDevice::SetEventNotification(HANDLE hEvent)
{
	return actualDirectInputDevice->SetEventNotification(hEvent);
}

HRESULT WINAPI HOOKDirectInputDevice::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return actualDirectInputDevice->SetProperty(rguidProp, pdiph);
}

HRESULT WINAPI HOOKDirectInputDevice::Unacquire()
{
	return actualDirectInputDevice->Unacquire();
}

HRESULT WINAPI HOOKDirectInputDevice::WriteEffectToFile(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return actualDirectInputDevice->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}

HOOKDirectInputDevice::HOOKDirectInputDevice(IDirectInputDevice8 *actual)
{
	if (!isConfigLoaded)
	{
		FILE *f = NULL;
		errno_t err = fopen_s(&f, "sensitivity.txt", "r");

		if (!err)
		{
			fscanf_s(f, "%f", &aspect);
			fclose(f);
		}

		isConfigLoaded = 1;

	}

	actualDirectInputDevice = actual;
	dformat = 0;
}

HOOKDirectInputDevice::~HOOKDirectInputDevice()
{
	//???
}