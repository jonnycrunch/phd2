#ifndef __altaircam_h__
#define __altaircam_h__

/* Version: 1.5.0 */

#ifndef _INC_WINDOWS
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ALIGNED8
#pragma pack(push, 8)
#ifdef ALTAIRCAM_EXPORTS
#define altaircam_ports(x)    __declspec(dllexport)   x   __stdcall
#elif !defined(ALTAIRCAM_NOIMPORTS)
#define altaircam_ports(x)    __declspec(dllimport)   x   __stdcall
#else
#define altaircam_ports(x)    x   __stdcall
#endif

#ifndef TDIBWIDTHBYTES
#define TDIBWIDTHBYTES(bits)  ((unsigned)(((bits) + 31) & (~31)) / 8)
#endif

	/********************************************************************************/
	/* HRESULT                                                                      */
	/*    |----------------|---------------------------------------|------------|   */
	/*    | S_OK           |   Operation successful                | 0x00000000 |   */
	/*    | S_FALSE        |   Operation successful                | 0x00000001 |   */
	/*    | E_FAIL         |   Unspecified failure                 | 0x80004005 |   */
	/*    | E_INVALIDARG   |   One or more arguments are not valid | 0x80070057 |   */
	/*    | E_NOTIMPL      |   Not supported or not implemented    | 0x80004001 |   */
	/*    | E_NOINTERFACE  |   Interface not supported             | 0x80004002 |   */
	/*    | E_POINTER      |   Pointer that is not valid           | 0x80004003 |   */
	/*    | E_UNEXPECTED   |   Unexpected failure                  | 0x8000FFFF |   */
	/*    | E_OUTOFMEMORY  |   Out of memory                       | 0x8007000E |   */
	/*    | E_WRONG_THREAD |   call function in the wrong thread   | 0x8001010E |   */
	/*    |----------------|---------------------------------------|------------|   */
	/********************************************************************************/

	/* handle */
	typedef struct AltaircamT { int unused; } *HAltairCam;

#define ALTAIRCAM_MAX                     16

#define ALTAIRCAM_FLAG_CMOS               0x00000001  /* cmos sensor */
#define ALTAIRCAM_FLAG_CCD_PROGRESSIVE    0x00000002  /* progressive ccd sensor */
#define ALTAIRCAM_FLAG_CCD_INTERLACED     0x00000004  /* interlaced ccd sensor */
#define ALTAIRCAM_FLAG_ROI_HARDWARE       0x00000008  /* support hardware ROI */
#define ALTAIRCAM_FLAG_MONO               0x00000010  /* monochromatic */
#define ALTAIRCAM_FLAG_BINSKIP_SUPPORTED  0x00000020  /* support bin/skip mode, see Altaircam_put_Mode and Altaircam_get_Mode */
#define ALTAIRCAM_FLAG_USB30              0x00000040  /* USB 3.0 */
#define ALTAIRCAM_FLAG_TEC                0x00000080  /* Thermoelectric Cooler */
#define ALTAIRCAM_FLAG_USB30_OVER_USB20   0x00000100  /* usb3.0 camera connected to usb2.0 port */
#define ALTAIRCAM_FLAG_ST4                0x00000200  /* ST4 */
#define ALTAIRCAM_FLAG_GETTEMPERATURE     0x00000400  /* support to get the temperature of sensor */
#define ALTAIRCAM_FLAG_PUTTEMPERATURE     0x00000800  /* support to put the temperature of sensor */
#define ALTAIRCAM_FLAG_BITDEPTH10         0x00001000  /* Maximum Bit Depth = 10 */
#define ALTAIRCAM_FLAG_BITDEPTH12         0x00002000  /* Maximum Bit Depth = 12 */
#define ALTAIRCAM_FLAG_BITDEPTH14         0x00004000  /* Maximum Bit Depth = 14 */
#define ALTAIRCAM_FLAG_BITDEPTH16         0x00008000  /* Maximum Bit Depth = 16 */
#define ALTAIRCAM_FLAG_FAN                0x00010000  /* cooling fan */
#define ALTAIRCAM_FLAG_TEC_ONOFF          0x00020000  /* Thermoelectric Cooler can be turn on or off */
#define ALTAIRCAM_FLAG_ISP                0x00040000  /* Image Signal Processing supported */
#define ALTAIRCAM_FLAG_TRIGGER_SOFTWARE   0x00080000  /* support software trigger */
#define ALTAIRCAM_FLAG_TRIGGER_EXTERNAL   0x00100000  /* support external trigger */
#define ALTAIRCAM_FLAG_TRIGGER_SINGLE     0x00200000  /* only support trigger single: one trigger, one image */
#define ALTAIRCAM_FLAG_BLACKLEVEL         0x00400000  /* support set and get the black level */
#define ALTAIRCAM_FLAG_AUTO_FOCUS         0x00800000  /* support auto focus */
#define ALTAIRCAM_FLAG_BUFFER             0x01000000  /* frame buffer */
#define ALTAIRCAM_FLAG_DDR                0x02000000  /* use very large capacity DDR (Double Data Rate SDRAM) for frame buffer */
#define ALTAIRCAM_FLAG_CG                 0x04000000  /* Conversion Gain: HCG, LCG */
#define ALTAIRCAM_FLAG_YUV411             0x08000000  /* pixel format, yuv411 */
#define ALTAIRCAM_FLAG_YUV422             0x10000000  /* pixel format, yuv422 */
#define ALTAIRCAM_FLAG_YUV444             0x20000000  /* pixel format, yuv444 */
#define ALTAIRCAM_FLAG_RGB888             0x40000000  /* pixel format, RGB888 */
#define ALTAIRCAM_FLAG_RAW8               0x80000000  /* pixel format, RAW 8 bits */
#define ALTAIRCAM_FLAG_GMCY8      0x0000000100000000  /* pixel format, GMCY, 8bits */
#define ALTAIRCAM_FLAG_GMCY12     0x0000000200000000  /* pixel format, GMCY, 12bits */

#define ALTAIRCAM_TEMP_DEF                6503
#define ALTAIRCAM_TEMP_MIN                2000
#define ALTAIRCAM_TEMP_MAX                15000
#define ALTAIRCAM_TINT_DEF                1000
#define ALTAIRCAM_TINT_MIN                200
#define ALTAIRCAM_TINT_MAX                2500
#define ALTAIRCAM_HUE_DEF                 0
#define ALTAIRCAM_HUE_MIN                 (-180)
#define ALTAIRCAM_HUE_MAX                 180
#define ALTAIRCAM_SATURATION_DEF          128
#define ALTAIRCAM_SATURATION_MIN          0
#define ALTAIRCAM_SATURATION_MAX          255
#define ALTAIRCAM_BRIGHTNESS_DEF          0
#define ALTAIRCAM_BRIGHTNESS_MIN          (-64)
#define ALTAIRCAM_BRIGHTNESS_MAX          64
#define ALTAIRCAM_CONTRAST_DEF            0
#define ALTAIRCAM_CONTRAST_MIN            (-100)
#define ALTAIRCAM_CONTRAST_MAX            100
#define ALTAIRCAM_GAMMA_DEF               100
#define ALTAIRCAM_GAMMA_MIN               20
#define ALTAIRCAM_GAMMA_MAX               180
#define ALTAIRCAM_AETARGET_DEF            120
#define ALTAIRCAM_AETARGET_MIN            16
#define ALTAIRCAM_AETARGET_MAX            220
#define ALTAIRCAM_WBGAIN_DEF              0
#define ALTAIRCAM_WBGAIN_MIN              (-128)
#define ALTAIRCAM_WBGAIN_MAX              128
#define ALTAIRCAM_BLACKLEVEL_MIN          0
#define ALTAIRCAM_BLACKLEVEL8_MAX         31              /* maximum black level for bit depth = 8 */
#define ALTAIRCAM_BLACKLEVEL10_MAX        (31 * 4)        /* maximum black level for bit depth = 10 */
#define ALTAIRCAM_BLACKLEVEL12_MAX        (31 * 16)       /* maximum black level for bit depth = 12 */
#define ALTAIRCAM_BLACKLEVEL14_MAX        (31 * 64)       /* maximum black level for bit depth = 14 */
#define ALTAIRCAM_BLACKLEVEL16_MAX        (31 * 256)      /* maximum black level for bit depth = 16 */

	typedef struct{
		unsigned    width;
		unsigned    height;
	}AltaircamResolution;

	/* In Windows platform, we always use UNICODE wchar_t */
	/* In Linux or macOS, we use char */

	typedef struct {
		const wchar_t*      name;        /* model name, in Windows, we use unicode */
		unsigned long long  flag;        /* ALTAIRCAM_FLAG_xxx, 64 bits */
		unsigned            maxspeed;    /* number of speed level, same as Altaircam_get_MaxSpeed(), the speed range = [0, maxspeed], closed interval */
		unsigned            preview;     /* number of preview resolution, same as Altaircam_get_ResolutionNumber() */
		unsigned            still;       /* number of still resolution, same as Altaircam_get_StillResolutionNumber() */
		unsigned            maxfanspeed; /* maximum fan speed */
		unsigned            ioctrol;     /* number of input/output control */
		float               xpixsz;      /* physical pixel size */
		float               ypixsz;      /* physical pixel size */
		AltaircamResolution   res[ALTAIRCAM_MAX];
	}ALIGNED8 AltaircamModelV2; /* camera model v2 */

	typedef struct {
		wchar_t               displayname[64];    /* display name */
		wchar_t               id[64];             /* unique and opaque id of a connected camera, for Altaircam_Open */
		const AltaircamModelV2* model;
	}AltaircamInstV2; /* camera instance for enumerating */

	/*
	get the version of this dll
	*/
	altaircam_ports(const wchar_t*)   Altaircam_Version();

	/*
	enumerate the cameras connected to the computer, return the number of enumerated.

	AltaircamInstV2 arr[ALTAIRCAM_MAX];
	unsigned cnt = Altaircam_EnumV2(arr);
	for (unsigned i = 0; i < cnt; ++i)
	...

	if pti == NULL, then, only the number is returned.
	*/
	altaircam_ports(unsigned) Altaircam_EnumV2(AltaircamInstV2 pti[ALTAIRCAM_MAX]);

	/* use the id of AltaircamInst, which is enumerated by Altaircam_Enum.
	if id is NULL, Altaircam_Open will open the first camera.
	*/
	altaircam_ports(HAltairCam) Altaircam_Open(const wchar_t* id);

	/*
	the same with Altaircam_Open, but use the index as the parameter. such as:
	index == 0, open the first camera,
	index == 1, open the second camera,
	etc
	*/
	altaircam_ports(HAltairCam) Altaircam_OpenByIndex(unsigned index);

	altaircam_ports(void)     Altaircam_Close(HAltairCam h); /* close the handle */

#define ALTAIRCAM_EVENT_EXPOSURE      0x0001    /* exposure time changed */
#define ALTAIRCAM_EVENT_TEMPTINT      0x0002    /* white balance changed, Temp/Tint mode */
#define ALTAIRCAM_EVENT_IMAGE         0x0004    /* live image arrived, use Altaircam_PullImage to get this image */
#define ALTAIRCAM_EVENT_STILLIMAGE    0x0005    /* snap (still) frame arrived, use Altaircam_PullStillImage to get this frame */
#define ALTAIRCAM_EVENT_WBGAIN        0x0006    /* white balance changed, RGB Gain mode */
#define ALTAIRCAM_EVENT_TRIGGERFAIL   0x0007    /* trigger failed */
#define ALTAIRCAM_EVENT_BLACK         0x0008    /* black balance changed */
#define ALTAIRCAM_EVENT_FFC           0x0009    /* flat field correction status changed */
#define ALTAIRCAM_EVENT_ERROR         0x0080    /* generic error */
#define ALTAIRCAM_EVENT_DISCONNECTED  0x0081    /* camera disconnected */
#define ALTAIRCAM_EVENT_TIMEOUT       0x0082    /* timeout error */

	altaircam_ports(HRESULT)      Altaircam_StartPullModeWithWndMsg(HAltairCam h, HWND hWnd, UINT nMsg);

	typedef void(__stdcall*    PALTAIRCAM_EVENT_CALLBACK)(unsigned nEvent, void* pCallbackCtx);
	altaircam_ports(HRESULT)      Altaircam_StartPullModeWithCallback(HAltairCam h, PALTAIRCAM_EVENT_CALLBACK pEventCallback, void* pCallbackContext);

/*
	bits: 24 (RGB24), 32 (RGB32), 8 (Gray) or 16 (Gray). In RAW mode, this parameter is ignored.
	pnWidth, pnHeight: OUT parameter
	rowPitch: The distance from one row of to the next row. rowPitch = 0 means using the default row pitch.
*/
	altaircam_ports(HRESULT)      Altaircam_PullImage(HAltairCam h, void* pImageData, int bits, unsigned* pnWidth, unsigned* pnHeight);
	altaircam_ports(HRESULT)      Altaircam_PullStillImage(HAltairCam h, void* pImageData, int bits, unsigned* pnWidth, unsigned* pnHeight);
	altaircam_ports(HRESULT)      Altaircam_PullImageWithRowPitch(HAltairCam h, void* pImageData, int bits, int rowPitch, unsigned* pnWidth, unsigned* pnHeight);
	altaircam_ports(HRESULT)      Altaircam_PullStillImageWithRowPitch(HAltairCam h, void* pImageData, int bits, int rowPitch, unsigned* pnWidth, unsigned* pnHeight);
/*
	(NULL == pData) means that something is error
	pCallbackCtx is the callback context which is passed by Altaircam_Start
	bSnap: TRUE if Altaircam_Snap

	pDataCallback is callbacked by an internal thread of altaircam.dll, so please pay attention to multithread problem
*/
	typedef void(__stdcall*    PALTAIRCAM_DATA_CALLBACK)(const void* pData, const BITMAPINFOHEADER* pHeader, BOOL bSnap, void* pCallbackCtx);
	altaircam_ports(HRESULT)  Altaircam_StartPushMode(HAltairCam h, PALTAIRCAM_DATA_CALLBACK pDataCallback, void* pCallbackCtx);

	altaircam_ports(HRESULT)  Altaircam_Stop(HAltairCam h);
	altaircam_ports(HRESULT)  Altaircam_Pause(HAltairCam h, BOOL bPause);

/*  for pull mode: ALTAIRCAM_EVENT_STILLIMAGE, and then Altaircam_PullStillImage
	for push mode: the snapped image will be return by PALTAIRCAM_DATA_CALLBACK, with the parameter 'bSnap' set to 'TRUE'
*/
	altaircam_ports(HRESULT)  Altaircam_Snap(HAltairCam h, unsigned nResolutionIndex);  /* still image snap */

/*
	soft trigger:
	nNumber:    0xffff:     trigger continuously
	0:          cancel trigger
	others:     number of images to be triggered
*/
	altaircam_ports(HRESULT)  Altaircam_Trigger(HAltairCam h, unsigned short nNumber);

/*
	put_Size, put_eSize, can be used to set the video output resolution BEFORE AltairCam_Start.
	put_Size use width and height parameters, put_eSize use the index parameter.
	for example, UCMOS03100KPA support the following resolutions:
	index 0:    2048,   1536
	index 1:    1024,   768
	index 2:    680,    510
	so, we can use put_Size(h, 1024, 768) or put_eSize(h, 1). Both have the same effect.
*/
	altaircam_ports(HRESULT)  Altaircam_put_Size(HAltairCam h, int nWidth, int nHeight);
	altaircam_ports(HRESULT)  Altaircam_get_Size(HAltairCam h, int* pWidth, int* pHeight);
	altaircam_ports(HRESULT)  Altaircam_put_eSize(HAltairCam h, unsigned nResolutionIndex);
	altaircam_ports(HRESULT)  Altaircam_get_eSize(HAltairCam h, unsigned* pnResolutionIndex);

	altaircam_ports(HRESULT)  Altaircam_get_ResolutionNumber(HAltairCam h);
	altaircam_ports(HRESULT)  Altaircam_get_Resolution(HAltairCam h, unsigned nResolutionIndex, int* pWidth, int* pHeight);
	altaircam_ports(HRESULT)  Altaircam_get_ResolutionRatio(HAltairCam h, unsigned nResolutionIndex, int* pNumerator, int* pDenominator);
	altaircam_ports(HRESULT)  Altaircam_get_Field(HAltairCam h);

	/*
	FourCC:
	MAKEFOURCC('G', 'B', 'R', 'G')
	MAKEFOURCC('R', 'G', 'G', 'B')
	MAKEFOURCC('B', 'G', 'G', 'R')
	MAKEFOURCC('G', 'R', 'B', 'G')
	MAKEFOURCC('Y', 'U', 'Y', 'V')
	MAKEFOURCC('Y', 'Y', 'Y', 'Y')
	*/
#ifndef MAKEFOURCC
#define MAKEFOURCC(a, b, c, d) ((unsigned)(unsigned char)(a) | ((unsigned)(unsigned char)(b) << 8) | ((unsigned)(unsigned char)(c) << 16) | ((unsigned)(unsigned char)(d) << 24))
#endif
	altaircam_ports(HRESULT)  Altaircam_get_RawFormat(HAltairCam h, unsigned* nFourCC, unsigned* bitdepth);

	/*
	------------------------------------------------------------------|
	| Parameter               |   Range       |   Default             |
	|-----------------------------------------------------------------|
	| Auto Exposure Target    |   10~230      |   120                 |
	| Temp                    |   2000~15000  |   6503                |
	| Tint                    |   200~2500    |   1000                |
	| LevelRange              |   0~255       |   Low = 0, High = 255 |
	| Contrast                |   -100~100    |   0                   |
	| Hue                     |   -180~180    |   0                   |
	| Saturation              |   0~255       |   128                 |
	| Brightness              |   -64~64      |   0                   |
	| Gamma                   |   20~180      |   100                 |
	| WBGain                  |   -128~128    |   0                   |
	------------------------------------------------------------------|
	*/

#ifndef __ALTAIRCAM_CALLBACK_DEFINED__
#define __ALTAIRCAM_CALLBACK_DEFINED__
	typedef void(__stdcall* PIALTAIRCAM_EXPOSURE_CALLBACK)(void* pCtx);
	typedef void(__stdcall* PIALTAIRCAM_WHITEBALANCE_CALLBACK)(const int aGain[3], void* pCtx);
	typedef void(__stdcall* PIALTAIRCAM_BLACKBALANCE_CALLBACK)(const unsigned short aSub[3], void* pCtx);   /* one push black balance */
	typedef void(__stdcall* PIALTAIRCAM_TEMPTINT_CALLBACK)(const int nTemp, const int nTint, void* pCtx);
	typedef void(__stdcall* PIALTAIRCAM_HISTOGRAM_CALLBACK)(const float aHistY[256], const float aHistR[256], const float aHistG[256], const float aHistB[256], void* pCtx);
	typedef void(__stdcall* PIALTAIRCAM_CHROME_CALLBACK)(void* pCtx);
#endif

	altaircam_ports(HRESULT)  Altaircam_get_AutoExpoEnable(HAltairCam h, BOOL* bAutoExposure);
	altaircam_ports(HRESULT)  Altaircam_put_AutoExpoEnable(HAltairCam h, BOOL bAutoExposure);
	altaircam_ports(HRESULT)  Altaircam_get_AutoExpoTarget(HAltairCam h, unsigned short* Target);
	altaircam_ports(HRESULT)  Altaircam_put_AutoExpoTarget(HAltairCam h, unsigned short Target);

	/*set the maximum auto exposure time and analog agin. The default maximum auto exposure time is 350ms */
	altaircam_ports(HRESULT)  Altaircam_put_MaxAutoExpoTimeAGain(HAltairCam h, unsigned maxTime, unsigned short maxAGain);

	altaircam_ports(HRESULT)  Altaircam_get_ExpoTime(HAltairCam h, unsigned* Time); /* in microseconds */
	altaircam_ports(HRESULT)  Altaircam_put_ExpoTime(HAltairCam h, unsigned Time); /* in microseconds */
	altaircam_ports(HRESULT)  Altaircam_get_ExpTimeRange(HAltairCam h, unsigned* nMin, unsigned* nMax, unsigned* nDef);

	altaircam_ports(HRESULT)  Altaircam_get_ExpoAGain(HAltairCam h, unsigned short* AGain); /* percent, such as 300 */
	altaircam_ports(HRESULT)  Altaircam_put_ExpoAGain(HAltairCam h, unsigned short AGain); /* percent */
	altaircam_ports(HRESULT)  Altaircam_get_ExpoAGainRange(HAltairCam h, unsigned short* nMin, unsigned short* nMax, unsigned short* nDef);

	/* Auto White Balance, Temp/Tint Mode */
	altaircam_ports(HRESULT)  Altaircam_AwbOnePush(HAltairCam h, PIALTAIRCAM_TEMPTINT_CALLBACK fnTTProc, void* pTTCtx); /* auto white balance "one push". The function must be called AFTER Altaircam_StartXXXX */

	/* Auto White Balance, RGB Gain Mode */
	altaircam_ports(HRESULT)  Altaircam_AwbInit(HAltairCam h, PIALTAIRCAM_WHITEBALANCE_CALLBACK fnWBProc, void* pWBCtx);

	/* White Balance, Temp/Tint mode */
	altaircam_ports(HRESULT)  Altaircam_put_TempTint(HAltairCam h, int nTemp, int nTint);
	altaircam_ports(HRESULT)  Altaircam_get_TempTint(HAltairCam h, int* nTemp, int* nTint);

	/* White Balance, RGB Gain mode */
	altaircam_ports(HRESULT)  Altaircam_put_WhiteBalanceGain(HAltairCam h, int aGain[3]);
	altaircam_ports(HRESULT)  Altaircam_get_WhiteBalanceGain(HAltairCam h, int aGain[3]);

	/* Black Balance */
	altaircam_ports(HRESULT)  Altaircam_AbbOnePush(HAltairCam h, PIALTAIRCAM_BLACKBALANCE_CALLBACK fnBBProc, void* pBBCtx); /* auto black balance "one push". This function must be called AFTER Altaircam_StartXXXX */
	altaircam_ports(HRESULT)  Altaircam_put_BlackBalance(HAltairCam h, unsigned short aSub[3]);
	altaircam_ports(HRESULT)  Altaircam_get_BlackBalance(HAltairCam h, unsigned short aSub[3]);

	/* Flat Field Correction */
	altaircam_ports(HRESULT)  Altaircam_FfcOnePush(HAltairCam h);

	altaircam_ports(HRESULT)  Altaircam_put_Hue(HAltairCam h, int Hue);
	altaircam_ports(HRESULT)  Altaircam_get_Hue(HAltairCam h, int* Hue);
	altaircam_ports(HRESULT)  Altaircam_put_Saturation(HAltairCam h, int Saturation);
	altaircam_ports(HRESULT)  Altaircam_get_Saturation(HAltairCam h, int* Saturation);
	altaircam_ports(HRESULT)  Altaircam_put_Brightness(HAltairCam h, int Brightness);
	altaircam_ports(HRESULT)  Altaircam_get_Brightness(HAltairCam h, int* Brightness);
	altaircam_ports(HRESULT)  Altaircam_get_Contrast(HAltairCam h, int* Contrast);
	altaircam_ports(HRESULT)  Altaircam_put_Contrast(HAltairCam h, int Contrast);
	altaircam_ports(HRESULT)  Altaircam_get_Gamma(HAltairCam h, int* Gamma); /* percent */
	altaircam_ports(HRESULT)  Altaircam_put_Gamma(HAltairCam h, int Gamma);  /* percent */

	altaircam_ports(HRESULT)  Altaircam_get_Chrome(HAltairCam h, BOOL* bChrome);  /* monochromatic mode */
	altaircam_ports(HRESULT)  Altaircam_put_Chrome(HAltairCam h, BOOL bChrome);

	altaircam_ports(HRESULT)  Altaircam_get_VFlip(HAltairCam h, BOOL* bVFlip);  /* vertical flip */
	altaircam_ports(HRESULT)  Altaircam_put_VFlip(HAltairCam h, BOOL bVFlip);
	altaircam_ports(HRESULT)  Altaircam_get_HFlip(HAltairCam h, BOOL* bHFlip);
	altaircam_ports(HRESULT)  Altaircam_put_HFlip(HAltairCam h, BOOL bHFlip); /* horizontal flip */

	altaircam_ports(HRESULT)  Altaircam_get_Negative(HAltairCam h, BOOL* bNegative);  /* negative film */
	altaircam_ports(HRESULT)  Altaircam_put_Negative(HAltairCam h, BOOL bNegative);

	altaircam_ports(HRESULT)  Altaircam_put_Speed(HAltairCam h, unsigned short nSpeed);
	altaircam_ports(HRESULT)  Altaircam_get_Speed(HAltairCam h, unsigned short* pSpeed);
	altaircam_ports(HRESULT)  Altaircam_get_MaxSpeed(HAltairCam h); /* get the maximum speed, see "Frame Speed Level", the speed range = [0, max], closed interval */

	altaircam_ports(HRESULT)  Altaircam_get_FanMaxSpeed(HAltairCam h); /* get the maximum fan speed, the fan speed range = [0, max], closed interval */

	altaircam_ports(HRESULT)  Altaircam_get_MaxBitDepth(HAltairCam h); /* get the max bit depth of this camera, such as 8, 10, 12, 14, 16 */

	/* power supply:
	0 -> 60HZ AC
	1 -> 50Hz AC
	2 -> DC
	*/
	altaircam_ports(HRESULT)  Altaircam_put_HZ(HAltairCam h, int nHZ);
	altaircam_ports(HRESULT)  Altaircam_get_HZ(HAltairCam h, int* nHZ);

	altaircam_ports(HRESULT)  Altaircam_put_Mode(HAltairCam h, BOOL bSkip); /* skip or bin */
	altaircam_ports(HRESULT)  Altaircam_get_Mode(HAltairCam h, BOOL* bSkip); /* If the model don't support bin/skip mode, return E_NOTIMPL */

	altaircam_ports(HRESULT)  Altaircam_put_AWBAuxRect(HAltairCam h, const RECT* pAuxRect); /* auto white balance ROI */
	altaircam_ports(HRESULT)  Altaircam_get_AWBAuxRect(HAltairCam h, RECT* pAuxRect);
	altaircam_ports(HRESULT)  Altaircam_put_AEAuxRect(HAltairCam h, const RECT* pAuxRect);  /* auto exposure ROI */
	altaircam_ports(HRESULT)  Altaircam_get_AEAuxRect(HAltairCam h, RECT* pAuxRect);

	altaircam_ports(HRESULT)  Altaircam_put_ABBAuxRect(HAltairCam h, const RECT* pAuxRect); /* auto black balance ROI */
	altaircam_ports(HRESULT)  Altaircam_get_ABBAuxRect(HAltairCam h, RECT* pAuxRect);

	/*
	S_FALSE:    color mode
	S_OK:       mono mode, such as EXCCD00300KMA and UHCCD01400KMA
	*/
	altaircam_ports(HRESULT)  Altaircam_get_MonoMode(HAltairCam h);

	altaircam_ports(HRESULT)  Altaircam_get_StillResolutionNumber(HAltairCam h);
	altaircam_ports(HRESULT)  Altaircam_get_StillResolution(HAltairCam h, unsigned nResolutionIndex, int* pWidth, int* pHeight);

	/* default: FALSE */
	altaircam_ports(HRESULT)  Altaircam_put_RealTime(HAltairCam h, BOOL bEnable);
	altaircam_ports(HRESULT)  Altaircam_get_RealTime(HAltairCam h, BOOL* bEnable);

	altaircam_ports(HRESULT)  Altaircam_Flush(HAltairCam h);  /* discard the current internal frame cache */

	/* get the temperature of sensor, in 0.1 degrees Celsius (32 means 3.2 degrees Celsius)
	return E_NOTIMPL if not supported
	*/
	altaircam_ports(HRESULT)  Altaircam_get_Temperature(HAltairCam h, short* pTemperature);

	/* set the temperature of sensor, in 0.1 degrees Celsius (32 means 3.2 degrees Celsius)
	return E_NOTIMPL if not supported
	*/
	altaircam_ports(HRESULT)  Altaircam_put_Temperature(HAltairCam h, short nTemperature);

	/*
	get the revision
	*/
	altaircam_ports(HRESULT)  Altaircam_get_Revision(HAltairCam h, unsigned short* pRevision);

	/*
	get the serial number which is always 32 chars which is zero-terminated such as "TP110826145730ABCD1234FEDC56787"
	*/
	altaircam_ports(HRESULT)  Altaircam_get_SerialNumber(HAltairCam h, char sn[32]);

	/*
	get the camera firmware version, such as: 3.2.1.20140922
	*/
	altaircam_ports(HRESULT)  Altaircam_get_FwVersion(HAltairCam h, char fwver[16]);

	/*
	get the camera hardware version, such as: 3.2.1.20140922
	*/
	altaircam_ports(HRESULT)  Altaircam_get_HwVersion(HAltairCam h, char hwver[16]);

	/*
	get the production date, such as: 20150327
	*/
	altaircam_ports(HRESULT)  Altaircam_get_ProductionDate(HAltairCam h, char pdate[10]);

	/*
	get the FPGA version, such as: 1.3
	*/
	altaircam_ports(HRESULT)  Altaircam_get_FpgaVersion(HAltairCam h, char fpgaver[16]);

	/*
	get the sensor pixel size, such as: 2.4um
	*/
	altaircam_ports(HRESULT)  Altaircam_get_PixelSize(HAltairCam h, unsigned nResolutionIndex, float* x, float* y);

	altaircam_ports(HRESULT)  Altaircam_put_LevelRange(HAltairCam h, unsigned short aLow[4], unsigned short aHigh[4]);
	altaircam_ports(HRESULT)  Altaircam_get_LevelRange(HAltairCam h, unsigned short aLow[4], unsigned short aHigh[4]);

	altaircam_ports(HRESULT)  Altaircam_put_ExpoCallback(HAltairCam h, PIALTAIRCAM_EXPOSURE_CALLBACK fnExpoProc, void* pExpoCtx);
	altaircam_ports(HRESULT)  Altaircam_put_ChromeCallback(HAltairCam h, PIALTAIRCAM_CHROME_CALLBACK fnChromeProc, void* pChromeCtx);

	/*
	The following functions must be called AFTER Altaircam_StartPushMode or Altaircam_StartPullModeWithWndMsg or Altaircam_StartPullModeWithCallback
	*/
	altaircam_ports(HRESULT)  Altaircam_LevelRangeAuto(HAltairCam h);
	altaircam_ports(HRESULT)  Altaircam_GetHistogram(HAltairCam h, PIALTAIRCAM_HISTOGRAM_CALLBACK fnHistogramProc, void* pHistogramCtx);

	/* led state:
	iLed: Led index, (0, 1, 2, ...)
	iState: 1 -> Ever bright; 2 -> Flashing; other -> Off
	iPeriod: Flashing Period (>= 500ms)
	*/
	altaircam_ports(HRESULT)  Altaircam_put_LEDState(HAltairCam h, unsigned short iLed, unsigned short iState, unsigned short iPeriod);

	altaircam_ports(HRESULT)  Altaircam_write_EEPROM(HAltairCam h, unsigned addr, const unsigned char* pBuffer, unsigned nBufferLen);
	altaircam_ports(HRESULT)  Altaircam_read_EEPROM(HAltairCam h, unsigned addr, unsigned char* pBuffer, unsigned nBufferLen);

#define ALTAIRCAM_TEC_TARGET_MIN      -300 /* -30.0 degrees Celsius */
#define ALTAIRCAM_TEC_TARGET_DEF      -100 /* -10.0 degrees Celsius */
#define ALTAIRCAM_TEC_TARGET_MAX      300  /* 30.0 degrees Celsius */

#define ALTAIRCAM_OPTION_NOFRAME_TIMEOUT      0x01    /* iValue: 1 = enable; 0 = disable. default: enable */
#define ALTAIRCAM_OPTION_THREAD_PRIORITY      0x02    /* set the priority of the internal thread which grab data from the usb device. iValue: 0 = THREAD_PRIORITY_NORMAL; 1 = THREAD_PRIORITY_ABOVE_NORMAL; 2 = THREAD_PRIORITY_HIGHEST; default: 0; see: msdn SetThreadPriority */
#define ALTAIRCAM_OPTION_PROCESSMODE          0x03    /*  0 = better image quality, more cpu usage. this is the default value
	1 = lower image quality, less cpu usage */
#define ALTAIRCAM_OPTION_RAW                  0x04    /* raw mode, read the sensor data. This can be set only BEFORE Altaircam_StartXXX() */
#define ALTAIRCAM_OPTION_HISTOGRAM            0x05    /* 0 = only one, 1 = continue mode */
#define ALTAIRCAM_OPTION_BITDEPTH             0x06    /* 0 = 8 bits mode, 1 = 16 bits mode */
#define ALTAIRCAM_OPTION_FAN                  0x07    /* 0 = turn off the cooling fan, [1, max] = fan speed */
#define ALTAIRCAM_OPTION_TEC                  0x08    /* 0 = turn off the thermoelectric cooler, 1 = turn on the thermoelectric cooler */
#define ALTAIRCAM_OPTION_LINEAR               0x09    /* 0 = turn off the builtin linear tone mapping, 1 = turn on the builtin linear tone mapping, default value: 1 */
#define ALTAIRCAM_OPTION_CURVE                0x0a    /* 0 = turn off the builtin curve tone mapping, 1 = turn on the builtin curve tone mapping, default value: 1 */
#define ALTAIRCAM_OPTION_TRIGGER              0x0b    /* 0 = video mode, 1 = software or simulated trigger mode, 2 = external trigger mode, default value =  0 */
#define ALTAIRCAM_OPTION_RGB48                0x0c    /* enable RGB48 format when bitdepth > 8 */
#define ALTAIRCAM_OPTION_COLORMATIX           0x0d    /* enable or disable the builtin color matrix, default value: 1 */
#define ALTAIRCAM_OPTION_WBGAIN               0x0e    /* enable or disable the builtin white balance gain, default value: 1 */
#define ALTAIRCAM_OPTION_TECTARGET            0x0f    /* get or set the target temperature of the thermoelectric cooler, in 0.1 degree Celsius. For example, 125 means 12.5 degree Celsius */
#define ALTAIRCAM_OPTION_AGAIN                0x10    /* enable or disable adjusting the analog gain when auto exposure is enabled. default value: enable */
#define ALTAIRCAM_OPTION_FRAMERATE            0x11    /* limit the frame rate, range=[0, 63], the default value 0 means no limit */
#define ALTAIRCAM_OPTION_DEMOSAIC             0x12    /* demosaic method: BILINEAR = 0, VNG(Variable Number of Gradients interpolation) = 1, PPG(Patterned Pixel Grouping interpolation) = 2, AHD(Adaptive Homogeneity-Directed interpolation) = 3, see https://en.wikipedia.org/wiki/Demosaicing, default value: 0 */
#define ALTAIRCAM_OPTION_BLACKLEVEL           0x15    /* black level */
#define ALTAIRCAM_OPTION_MULTITHREAD          0x16    /* multithread image processing */
#define ALTAIRCAM_OPTION_BINNING              0x17    /* binning, 0x01 (no binning), 0x02 (add, 2*2), 0x03 (add, 3*3), 0x04 (add, 4*4), 0x82 (average, 2*2), 0x83 (average, 3*3), 0x84 (average, 4*4) */
#define ALTAIRCAM_OPTION_ROTATE               0x18    /* rotate clockwise: 0, 90, 180, 270 */
#define ALTAIRCAM_OPTION_CG                   0x19    /* Conversion Gain: 0 = HCG, 1 = LCG, default: 0 */
#define ALTAIRCAM_OPTION_PIXEL_FORMAT         0x1a    /* pixel format, ALTAIRCAM_PIXELFORMAT_xxxx */
#define ALTAIRCAM_OPTION_FFC                  0x1b    /* flat field correction
														 set:
														 0: disable
														 1: enable
														 (0xff000000 | n): set the average number to n
														 get:
														 (val & 0xff): 0 -> disable, 1 -> enable, 2 -> inited
														 ((val & 0xff00) >> 8): sequence
														 ((val & 0xff0000) >> 8): average number
													   */

#define ALTAIRCAM_PIXELFORMAT_RAW8            0x00
#define ALTAIRCAM_PIXELFORMAT_RAW10           0x01
#define ALTAIRCAM_PIXELFORMAT_RAW12           0x02
#define ALTAIRCAM_PIXELFORMAT_RAW14           0x03
#define ALTAIRCAM_PIXELFORMAT_RAW16           0x04
#define ALTAIRCAM_PIXELFORMAT_YUV411          0x05
#define ALTAIRCAM_PIXELFORMAT_YUV422          0x06
#define ALTAIRCAM_PIXELFORMAT_YUV444          0x07
#define ALTAIRCAM_PIXELFORMAT_RGB888          0x08
#define ALTAIRCAM_PIXELFORMAT_GMCY8           0x09      /* map to raw8 */
#define ALTAIRCAM_PIXELFORMAT_GMCY12          0x0a      /* map to raw12 */

	altaircam_ports(HRESULT)  Altaircam_put_Option(HAltairCam h, unsigned iOption, int iValue);
	altaircam_ports(HRESULT)  Altaircam_get_Option(HAltairCam h, unsigned iOption, int* piValue);

	altaircam_ports(HRESULT)  Altaircam_put_Roi(HAltairCam h, unsigned xOffset, unsigned yOffset, unsigned xWidth, unsigned yHeight);
	altaircam_ports(HRESULT)  Altaircam_get_Roi(HAltairCam h, unsigned* pxOffset, unsigned* pyOffset, unsigned* pxWidth, unsigned* pyHeight);

#define ALTAIRCAM_IOCONTROLTYPE_GET_SUPPORTEDMODE           0x01 /* 0x01->Input, 0x02->Output, (0x01 | 0x02)->support both Input and Output */
#define ALTAIRCAM_IOCONTROLTYPE_GET_ALLSTATUS               0x02 /* A single bit field indicating the current logical state of all available line signals at time of polling */
#define ALTAIRCAM_IOCONTROLTYPE_GET_MODE                    0x03 /* 0x01->Input, 0x02->Output */
#define ALTAIRCAM_IOCONTROLTYPE_SET_MODE                    0x04
#define ALTAIRCAM_IOCONTROLTYPE_GET_FORMAT                  0x05 /*
	                                                                0x00-> not connected
	                                                                0x01-> Tri-state: Tri-state mode (Not driven)
	                                                                0x02-> TTL: TTL level signals
	                                                                0x03-> LVDS: LVDS level signals
	                                                                0x04-> RS422: RS422 level signals
	                                                                0x05-> Opto-coupled
	                                                             */
#define ALTAIRCAM_IOCONTROLTYPE_SET_FORMAT                  0x06
#define ALTAIRCAM_IOCONTROLTYPE_GET_INVERTER                0x07 /* boolean */
#define ALTAIRCAM_IOCONTROLTYPE_SET_INVERTER                0x08
#define ALTAIRCAM_IOCONTROLTYPE_GET_LOGIC                   0x09 /* 0x01->Positive, 0x02->Negative */
#define ALTAIRCAM_IOCONTROLTYPE_SET_LOGIC                   0x0a
#define ALTAIRCAM_IOCONTROLTYPE_GET_MINIMUMOUTPUTPULSEWIDTH 0x0b /* minimum signal width of an output signal (in microseconds) */
#define ALTAIRCAM_IOCONTROLTYPE_SET_MINIMUMOUTPUTPULSEWIDTH 0x0c
#define ALTAIRCAM_IOCONTROLTYPE_GET_OVERLOADSTATUS          0x0d /* boolean */
#define ALTAIRCAM_IOCONTROLTYPE_SET_OVERLOADSTATUS          0x0e
#define ALTAIRCAM_IOCONTROLTYPE_GET_PITCH                   0x0f /* Number of bytes separating the starting pixels of two consecutive lines */
#define ALTAIRCAM_IOCONTROLTYPE_SET_PITCH                   0x10
#define ALTAIRCAM_IOCONTROLTYPE_GET_PITCHENABLE             0x11 /* boolean */
#define ALTAIRCAM_IOCONTROLTYPE_SET_PITCHENABLE             0x12
#define ALTAIRCAM_IOCONTROLTYPE_GET_SOURCE                  0x13 /* 
	                                                                0->ExposureActive
	                                                                1->TimerActive
	                                                                2->UserOutput
	                                                                3->TriggerReady
	                                                                4->SerialTx
	                                                                5->AcquisitionTriggerReady
	                                                             */
#define ALTAIRCAM_IOCONTROLTYPE_SET_SOURCE                  0x14
#define ALTAIRCAM_IOCONTROLTYPE_GET_STATUS                  0x15 /* boolean */
#define ALTAIRCAM_IOCONTROLTYPE_SET_STATUS                  0x16
#define ALTAIRCAM_IOCONTROLTYPE_GET_DEBOUNCERTIME           0x17 /* debouncer time in microseconds */
#define ALTAIRCAM_IOCONTROLTYPE_SET_DEBOUNCERTIME           0x18

	altaircam_ports(HRESULT)  Altaircam_IoControl(HAltairCam h, unsigned index, unsigned nType, int outVal, int* inVal);

	altaircam_ports(HRESULT)  Altaircam_write_UART(HAltairCam h, const unsigned char* pData, unsigned nDataLen);
	altaircam_ports(HRESULT)  Altaircam_read_UART(HAltairCam h, unsigned char* pBuffer, unsigned nBufferLen);

	altaircam_ports(HRESULT)  Altaircam_put_Linear(HAltairCam h, const unsigned char* v8, const unsigned short* v16);
	altaircam_ports(HRESULT)  Altaircam_put_Curve(HAltairCam h, const unsigned char* v8, const unsigned short* v16);
	altaircam_ports(HRESULT)  Altaircam_put_ColorMatrix(HAltairCam h, const double v[9]);
	altaircam_ports(HRESULT)  Altaircam_put_InitWBGain(HAltairCam h, const unsigned short v[3]);

	/*
	get the frame rate: framerate (fps) = Frame * 1000.0 / nTime
	*/
	altaircam_ports(HRESULT)  Altaircam_get_FrameRate(HAltairCam h, unsigned* nFrame, unsigned* nTime, unsigned* nTotalFrame);

	/* astronomy: for ST4 guide, please see: ASCOM Platform Help ICameraV2.
	nDirect: 0 = North, 1 = South, 2 = East, 3 = West, 4 = Stop
	nDuration: in milliseconds
	*/
	altaircam_ports(HRESULT)  Altaircam_ST4PlusGuide(HAltairCam h, unsigned nDirect, unsigned nDuration);

	/* S_OK: pulse guiding
	S_FALSE: not pulse guiding
	*/
	altaircam_ports(HRESULT)  Altaircam_ST4PlusGuideState(HAltairCam h);

	altaircam_ports(HRESULT)  Altaircam_InitOcl();

	/* https://software.intel.com/en-us/articles/sharing-surfaces-between-opencl-and-directx-11-on-intel-processor-graphics */
	/* https://software.intel.com/en-us/articles/opencl-and-opengl-interoperability-tutorial */
	typedef struct {
		void*       d3d11_device;           /* ID3D11Device */
		void*       d3d11_texture;          /* ID3D11Texture2D shared by opencl and d3d11, DXGI_FORMAT_R8G8B8A8_UINT */
	}AltaircamOclWithSharedTexture;
	altaircam_ports(HRESULT)  Altaircam_StartOclWithSharedTexture(HAltairCam h, const AltaircamOclWithSharedTexture* pocl, PALTAIRCAM_EVENT_CALLBACK pEventCallback, void* pCallbackContext);

	/*
	calculate the clarity factor:
	pImageData: pointer to the image data
	bits: 8(Grey), 24 (RGB24), 32(RGB32)
	nImgWidth, nImgHeight: the image width and height
	*/
	altaircam_ports(double)   Altaircam_calc_ClarityFactor(const void* pImageData, int bits, unsigned nImgWidth, unsigned nImgHeight);

	altaircam_ports(void)     Altaircam_deBayer(unsigned nBayer, int nW, int nH, const void* input, void* output, unsigned char nBitDepth);

	typedef void(__stdcall*    PALTAIRCAM_DEMOSAIC_CALLBACK)(unsigned nBayer, int nW, int nH, const void* input, void* output, unsigned char nBitDepth, void* pCallbackCtx);
	altaircam_ports(HRESULT)  Altaircam_put_Demosaic(HAltairCam h, PALTAIRCAM_DEMOSAIC_CALLBACK pCallback, void* pCallbackCtx);

	/*
	obsolete, please use AltaircamModelV2
	*/
	typedef struct{
		const wchar_t*      name;       /* model name, in Windows, we use unicode */
		unsigned            flag;       /* ALTAIRCAM_FLAG_xxx */
		unsigned            maxspeed;   /* number of speed level, same as Altaircam_get_MaxSpeed(), the speed range = [0, maxspeed], closed interval */
		unsigned            preview;    /* number of preview resolution, same as Altaircam_get_ResolutionNumber() */
		unsigned            still;      /* number of still resolution, same as Altaircam_get_StillResolutionNumber() */
		AltaircamResolution   res[ALTAIRCAM_MAX];
	}AltaircamModel;

	typedef struct{
		wchar_t             displayname[64];    /* display name */
		wchar_t             id[64];             /* unique and opaque id of a connected camera, for Altaircam_Open */
		const AltaircamModel* model;
	}AltaircamInst;

	/*
	obsolete, please use Altaircam_EnumV2
	*/
	altaircam_ports(unsigned) Altaircam_Enum(AltaircamInst pti[ALTAIRCAM_MAX]);

	/* Altaircam_Start is obsolete, it's a synonyms for Altaircam_StartPushMode. */
	altaircam_ports(HRESULT)  Altaircam_Start(HAltairCam h, PALTAIRCAM_DATA_CALLBACK pDataCallback, void* pCallbackCtx);

	/* Altaircam_put_TempTintInit is obsolete, it's a synonyms for Altaircam_AwbOnePush. */
	altaircam_ports(HRESULT)  Altaircam_put_TempTintInit(HAltairCam h, PIALTAIRCAM_TEMPTINT_CALLBACK fnTTProc, void* pTTCtx);

	/*
	obsolete, please use Altaircam_put_Option or Altaircam_get_Option to set or get the process mode: ALTAIRCAM_PROCESSMODE_FULL or ALTAIRCAM_PROCESSMODE_FAST.
	default is ALTAIRCAM_PROCESSMODE_FULL.
	*/
#ifndef __ALTAIRCAM_PROCESSMODE_DEFINED__
#define __ALTAIRCAM_PROCESSMODE_DEFINED__
#define ALTAIRCAM_PROCESSMODE_FULL        0x00    /* better image quality, more cpu usage. this is the default value */
#define ALTAIRCAM_PROCESSMODE_FAST        0x01    /* lower image quality, less cpu usage */
#endif

	altaircam_ports(HRESULT)  Altaircam_put_ProcessMode(HAltairCam h, unsigned nProcessMode);
	altaircam_ports(HRESULT)  Altaircam_get_ProcessMode(HAltairCam h, unsigned* pnProcessMode);

	/* obsolete, please use Altaircam_put_Roi and Altaircam_get_Roi */
	altaircam_ports(HRESULT)  Altaircam_put_RoiMode(HAltairCam h, BOOL bRoiMode, int xOffset, int yOffset);
	altaircam_ports(HRESULT)  Altaircam_get_RoiMode(HAltairCam h, BOOL* pbRoiMode, int* pxOffset, int* pyOffset);

	/* obsolete:
	------------------------------------------------------------|
	| Parameter         |   Range       |   Default             |
	|-----------------------------------------------------------|
	| VidgetAmount      |   -100~100    |   0                   |
	| VignetMidPoint    |   0~100       |   50                  |
	-------------------------------------------------------------
	*/
	altaircam_ports(HRESULT)  Altaircam_put_VignetEnable(HAltairCam h, BOOL bEnable);
	altaircam_ports(HRESULT)  Altaircam_get_VignetEnable(HAltairCam h, BOOL* bEnable);
	altaircam_ports(HRESULT)  Altaircam_put_VignetAmountInt(HAltairCam h, int nAmount);
	altaircam_ports(HRESULT)  Altaircam_get_VignetAmountInt(HAltairCam h, int* nAmount);
	altaircam_ports(HRESULT)  Altaircam_put_VignetMidPointInt(HAltairCam h, int nMidPoint);
	altaircam_ports(HRESULT)  Altaircam_get_VignetMidPointInt(HAltairCam h, int* nMidPoint);

/* obsolete flags */
//#define ALTAIRCAM_FLAG_BITDEPTH10    ALTAIRCAM_FLAG_RAW10  /* pixel format, RAW 10bits */
//#define ALTAIRCAM_FLAG_BITDEPTH12    ALTAIRCAM_FLAG_RAW12  /* pixel format, RAW 12bits */
//#define ALTAIRCAM_FLAG_BITDEPTH14    ALTAIRCAM_FLAG_RAW14  /* pixel format, RAW 14bits */
//#define ALTAIRCAM_FLAG_BITDEPTH16    ALTAIRCAM_FLAG_RAW16  /* pixel format, RAW 16bits */

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif
