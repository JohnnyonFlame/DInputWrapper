#pragma once

class HOOKDirectInput : public IDirectInput8
{
private:
	IDirectInput8 *actual;

public:
	HRESULT	WINAPI QueryInterface(REFIID iid, void ** ppvObject);
	ULONG	WINAPI AddRef(void);
	ULONG	WINAPI Release(void);
	HRESULT	WINAPI ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);
	HRESULT	WINAPI CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8 *lpDirectInputDevice, LPUNKNOWN pUnkOuter);
	HRESULT	WINAPI EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT WINAPI EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT	WINAPI FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance);
	HRESULT	WINAPI GetDeviceStatus(REFGUID rguidInstance);
	HRESULT	WINAPI Initialize(HINSTANCE hinst, DWORD dwVersion);
	HRESULT	WINAPI RunControlPanel(HWND hwndOwner, DWORD dwFlags);

	HOOKDirectInput(IDirectInput8 *actualDirectInput);
	virtual ~HOOKDirectInput(void);
};