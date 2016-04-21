#pragma once

class HOOKDirectInputDevice : public IDirectInputDevice8
{
private:
	IDirectInputDevice8 *actualDirectInputDevice;
	LPCDIDATAFORMAT dformat;

public:
	HRESULT	WINAPI QueryInterface(REFIID iid, void ** ppvObject);
	ULONG   WINAPI AddRef(void);
	ULONG   WINAPI Release(void);
	HRESULT	WINAPI Acquire();
	HRESULT	WINAPI BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags);
	HRESULT	WINAPI CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT *ppdeff, LPUNKNOWN punkOuter);
	HRESULT	WINAPI EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
	HRESULT	WINAPI EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType);
	HRESULT	WINAPI EnumEffectsInFile(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags);
	HRESULT	WINAPI EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);
	HRESULT	WINAPI Escape(LPDIEFFESCAPE pesc);
	HRESULT	WINAPI GetCapabilities(LPDIDEVCAPS lpDIDevCaps);
	HRESULT	WINAPI GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
	HRESULT	WINAPI GetDeviceInfo(LPDIDEVICEINSTANCE pdidi);
	HRESULT	WINAPI GetDeviceState(DWORD cbData, LPVOID lpvData);
	HRESULT	WINAPI GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid);
	HRESULT	WINAPI GetForceFeedbackState(LPDWORD pdwOut);
	HRESULT	WINAPI GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader);
	HRESULT	WINAPI GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow);
	HRESULT	WINAPI GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph);
	HRESULT	WINAPI Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
	HRESULT	WINAPI Poll();
	HRESULT	WINAPI RunControlPanel(HWND hwndOwner, DWORD dwFlags);
	HRESULT	WINAPI SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);
	HRESULT	WINAPI SendForceFeedbackCommand(DWORD dwFlags);
	HRESULT	WINAPI SetActionMap(LPDIACTIONFORMAT lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags);
	HRESULT	WINAPI SetCooperativeLevel(HWND hwnd, DWORD dwFlags);
	HRESULT	WINAPI SetDataFormat(LPCDIDATAFORMAT lpdf);
	HRESULT	WINAPI SetEventNotification(HANDLE hEvent);
	HRESULT	WINAPI SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph);
	HRESULT	WINAPI Unacquire();
	HRESULT	WINAPI WriteEffectToFile(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags);

	HOOKDirectInputDevice(IDirectInputDevice8 *actual);
	virtual ~HOOKDirectInputDevice(void);
};