// DInputWrapper.cpp : Defines the exported functions for the DLL application.
//

#include <windows.h>
#include "stdafx.h"

#include "HOOKDirectInput.h"

typedef HRESULT(WINAPI *dICreate_t)(HINSTANCE, DWORD, REFIID, LPVOID, LPUNKNOWN);
typedef HRESULT(*cDevice_t)(REFGUID rguid, LPDIRECTINPUTDEVICE * lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

dICreate_t old_DirectInput8Create = NULL;

int init_wrapper()
{
	WCHAR dllpath[320];
	if (!GetSystemDirectory(dllpath, sizeof(dllpath)))
		return 0;

	wcsncat_s(dllpath, 320, L"\\dinput8.dll", _TRUNCATE);

	HMODULE mod = LoadLibrary(dllpath);
	if (!mod)
		return 0;

	old_DirectInput8Create = (dICreate_t)GetProcAddress(mod, "DirectInput8Create");
	return (old_DirectInput8Create) ? 1 : 0;
}

HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID *ppvOut, LPUNKNOWN punkOuter) {
	if (!old_DirectInput8Create)
		if (!init_wrapper())
			return E_FAIL;

	HRESULT res = old_DirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
	if (FAILED(res))
		return res;

	IDirectInput8 *dinput = new HOOKDirectInput((IDirectInput8*)*ppvOut);
	*ppvOut = dinput;

	return res;
}