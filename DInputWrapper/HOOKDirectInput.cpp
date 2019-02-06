#include <windows.h>
#include "stdafx.h"

#include "dinput.h"
#include "HOOKDirectInput.h"
#include "HOOKDirectInputDevice.h"

HRESULT	WINAPI HOOKDirectInput::QueryInterface(REFIID iid, void ** ppvObject)
{
	return actual->QueryInterface(iid, ppvObject);
}

ULONG	WINAPI HOOKDirectInput::AddRef(void)
{
	return actual->AddRef();
}

ULONG	WINAPI HOOKDirectInput::Release(void)
{
	return actual->Release();
}

HRESULT	WINAPI HOOKDirectInput::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
	return actual->ConfigureDevices(lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

HRESULT	WINAPI HOOKDirectInput::CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8 *lpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	HRESULT res = actual->CreateDevice(rguid, lpDirectInputDevice, pUnkOuter);
	if (rguid != GUID_SysMouse || FAILED(res))
		return res;

	IDirectInputDevice8 *dev = new HOOKDirectInputDevice(*lpDirectInputDevice);
	*lpDirectInputDevice = dev;

	return res;
}

HRESULT	WINAPI HOOKDirectInput::EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return actual->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT WINAPI HOOKDirectInput::EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return actual->EnumDevicesBySemantics(ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT	WINAPI HOOKDirectInput::FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance)
{
	return actual->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT	WINAPI HOOKDirectInput::GetDeviceStatus(REFGUID rguidInstance)
{
	return actual->GetDeviceStatus(rguidInstance);
}

HRESULT	WINAPI HOOKDirectInput::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	return actual->Initialize(hinst, dwVersion);
}

HRESULT	WINAPI HOOKDirectInput::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return actual->RunControlPanel(hwndOwner, dwFlags);
}

HOOKDirectInput::HOOKDirectInput(IDirectInput8 *actualDirectInput)
{
	actual = actualDirectInput;
}

HOOKDirectInput::~HOOKDirectInput()
{
	//????
}