// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ($DISTANCEALPHAMODE != 0 && $SEAMLESS_MODE != 0)
// ($DISTANCEALPHAMODE >= 8 && ($DETAILTEXTUREMODE == 0 || $BLENDTINTBYBASEALPHA == 1))
// ($DISTANCEALPHAMODE != 0 && $FLASHLIGHTMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $FLASHLIGHTSHADOWS == 1)
// ($DISTANCEALPHAMODE != 0 && $SELFILLUMMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $ENVMAPMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $SRGB_INPUT_ADAPTER == 1)
// ($DISTANCEALPHAMODE != 0 && $WRITEWATERFOGTODESTALPHA == 1)
// ($DISTANCEALPHAMODE != 0 && $WRITE_DEPTH_TO_DESTALPHA == 1)
// ($SEAMLESS_MODE  > 1 && $DETAILTEXTUREMODE == 0)
// ($SEAMLESS_MODE  > 1 && $SELFILLUMMODE == 2)
// ($SEAMLESS_MODE == 1 && $BLENDTINTBYBASEALPHA  == 1)
// ($SEAMLESS_MODE == 3 && $BLENDTINTBYBASEALPHA  == 1)
// ($SEAMLESS_MODE != 0 && $ENVMAPMODE == 3)
// ($SEAMLESS_MODE != 0 && $SRGB_INPUT_ADAPTER == 1)
// ($FLASHLIGHTMODE == 0 && $FLASHLIGHTDEPTHFILTERMODE != 0)
// ($FLASHLIGHTMODE == 0 && $FLASHLIGHTSHADOWS == 1)
// ($FLASHLIGHTMODE != 0 && $SELFILLUMMODE != 0)
// ($FLASHLIGHTMODE != 0 && $ENVMAPMODE != 0)
// ($FLASHLIGHTMODE != 0 && $STATIC_LIGHT_LIGHTMAP != 0)
// ($FLASHLIGHTMODE != 0 && $DIFFUSELIGHTING == 1)
// ($SELFILLUMMODE == 1 && $BLENDTINTBYBASEALPHA != 0)
// ($SELFILLUMMODE == 1 && $ENVMAPMODE == 2)
// ($SELFILLUMMODE == 2 && $ENVMAPMODE != 3)
// ($ENVMAPMODE == 2 && $BLENDTINTBYBASEALPHA != 0)
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA

#pragma once
#include "shaderlib/cshader.h"
class vertexlit_and_unlit_generic_ps20b_Static_Index
{
	unsigned int m_nDISTANCEALPHAMODE : 4;
	unsigned int m_nSEAMLESS_MODE : 3;
	unsigned int m_nDETAILTEXTUREMODE : 4;
	unsigned int m_nBLENDTINTBYBASEALPHA : 2;
	unsigned int m_nFLASHLIGHTMODE : 3;
	unsigned int m_nSELFILLUMMODE : 2;
	unsigned int m_nENVMAPMODE : 3;
	unsigned int m_nDIFFUSELIGHTING : 2;
	unsigned int m_nSRGB_INPUT_ADAPTER : 2;
	unsigned int m_nVERTEXCOLOR : 2;
	unsigned int m_nDEPTHBLEND : 2;
#ifdef _DEBUG
	bool m_bDISTANCEALPHAMODE : 1;
	bool m_bSEAMLESS_MODE : 1;
	bool m_bDETAILTEXTUREMODE : 1;
	bool m_bBLENDTINTBYBASEALPHA : 1;
	bool m_bFLASHLIGHTMODE : 1;
	bool m_bSELFILLUMMODE : 1;
	bool m_bENVMAPMODE : 1;
	bool m_bDIFFUSELIGHTING : 1;
	bool m_bSRGB_INPUT_ADAPTER : 1;
	bool m_bVERTEXCOLOR : 1;
	bool m_bDEPTHBLEND : 1;
#endif	// _DEBUG
public:
	void SetDISTANCEALPHAMODE( int i )
	{
		Assert( i >= 0 && i <= 14 );
		m_nDISTANCEALPHAMODE = i;
#ifdef _DEBUG
		m_bDISTANCEALPHAMODE = true;
#endif	// _DEBUG
	}

	void SetSEAMLESS_MODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nSEAMLESS_MODE = i;
#ifdef _DEBUG
		m_bSEAMLESS_MODE = true;
#endif	// _DEBUG
	}

	void SetDETAILTEXTUREMODE( int i )
	{
		Assert( i >= 0 && i <= 10 );
		m_nDETAILTEXTUREMODE = i;
#ifdef _DEBUG
		m_bDETAILTEXTUREMODE = true;
#endif	// _DEBUG
	}

	void SetBLENDTINTBYBASEALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nBLENDTINTBYBASEALPHA = i;
#ifdef _DEBUG
		m_bBLENDTINTBYBASEALPHA = true;
#endif	// _DEBUG
	}

	void SetFLASHLIGHTMODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nFLASHLIGHTMODE = i;
#ifdef _DEBUG
		m_bFLASHLIGHTMODE = true;
#endif	// _DEBUG
	}

	void SetSELFILLUMMODE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nSELFILLUMMODE = i;
#ifdef _DEBUG
		m_bSELFILLUMMODE = true;
#endif	// _DEBUG
	}

	void SetENVMAPMODE( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nENVMAPMODE = i;
#ifdef _DEBUG
		m_bENVMAPMODE = true;
#endif	// _DEBUG
	}

	void SetDIFFUSELIGHTING( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDIFFUSELIGHTING = i;
#ifdef _DEBUG
		m_bDIFFUSELIGHTING = true;
#endif	// _DEBUG
	}

	void SetSRGB_INPUT_ADAPTER( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSRGB_INPUT_ADAPTER = i;
#ifdef _DEBUG
		m_bSRGB_INPUT_ADAPTER = true;
#endif	// _DEBUG
	}

	void SetVERTEXCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVERTEXCOLOR = i;
#ifdef _DEBUG
		m_bVERTEXCOLOR = true;
#endif	// _DEBUG
	}

	void SetDEPTHBLEND( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDEPTHBLEND = i;
#ifdef _DEBUG
		m_bDEPTHBLEND = true;
#endif	// _DEBUG
	}

	vertexlit_and_unlit_generic_ps20b_Static_Index(  )
	{
		m_nDISTANCEALPHAMODE = 0;
		m_nSEAMLESS_MODE = 0;
		m_nDETAILTEXTUREMODE = 0;
		m_nBLENDTINTBYBASEALPHA = 0;
		m_nFLASHLIGHTMODE = 0;
		m_nSELFILLUMMODE = 0;
		m_nENVMAPMODE = 0;
		m_nDIFFUSELIGHTING = 0;
		m_nSRGB_INPUT_ADAPTER = 0;
		m_nVERTEXCOLOR = 0;
		m_nDEPTHBLEND = 0;
#ifdef _DEBUG
		m_bDISTANCEALPHAMODE = false;
		m_bSEAMLESS_MODE = false;
		m_bDETAILTEXTUREMODE = false;
		m_bBLENDTINTBYBASEALPHA = false;
		m_bFLASHLIGHTMODE = false;
		m_bSELFILLUMMODE = false;
		m_bENVMAPMODE = false;
		m_bDIFFUSELIGHTING = false;
		m_bSRGB_INPUT_ADAPTER = false;
		m_bVERTEXCOLOR = false;
		m_bDEPTHBLEND = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bDISTANCEALPHAMODE && m_bSEAMLESS_MODE && m_bDETAILTEXTUREMODE && m_bBLENDTINTBYBASEALPHA && m_bFLASHLIGHTMODE && m_bSELFILLUMMODE && m_bENVMAPMODE && m_bDIFFUSELIGHTING && m_bSRGB_INPUT_ADAPTER && m_bVERTEXCOLOR && m_bDEPTHBLEND );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nSEAMLESS_MODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( SEAMLESS_MODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE >= 8 ) && ( ( m_nDETAILTEXTUREMODE == 0 ) || ( m_nBLENDTINTBYBASEALPHA == 1 ) ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE >= 8 ) && ( ( DETAILTEXTUREMODE == 0 ) || ( BLENDTINTBYBASEALPHA == 1 ) ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nFLASHLIGHTMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( FLASHLIGHTMODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nSELFILLUMMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( SELFILLUMMODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nENVMAPMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( ENVMAPMODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nSRGB_INPUT_ADAPTER == 1 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( SRGB_INPUT_ADAPTER == 1 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE > 1 ) && ( m_nDETAILTEXTUREMODE == 0 ) ), "Invalid combo combination ( ( SEAMLESS_MODE > 1 ) && ( DETAILTEXTUREMODE == 0 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE > 1 ) && ( m_nSELFILLUMMODE == 2 ) ), "Invalid combo combination ( ( SEAMLESS_MODE > 1 ) && ( SELFILLUMMODE == 2 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE == 1 ) && ( m_nBLENDTINTBYBASEALPHA == 1 ) ), "Invalid combo combination ( ( SEAMLESS_MODE == 1 ) && ( BLENDTINTBYBASEALPHA == 1 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE == 3 ) && ( m_nBLENDTINTBYBASEALPHA == 1 ) ), "Invalid combo combination ( ( SEAMLESS_MODE == 3 ) && ( BLENDTINTBYBASEALPHA == 1 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE != 0 ) && ( m_nENVMAPMODE == 3 ) ), "Invalid combo combination ( ( SEAMLESS_MODE != 0 ) && ( ENVMAPMODE == 3 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_MODE != 0 ) && ( m_nSRGB_INPUT_ADAPTER == 1 ) ), "Invalid combo combination ( ( SEAMLESS_MODE != 0 ) && ( SRGB_INPUT_ADAPTER == 1 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nSELFILLUMMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( SELFILLUMMODE != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nENVMAPMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( ENVMAPMODE != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nDIFFUSELIGHTING == 1 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( DIFFUSELIGHTING == 1 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE == 1 ) && ( m_nBLENDTINTBYBASEALPHA != 0 ) ), "Invalid combo combination ( ( SELFILLUMMODE == 1 ) && ( BLENDTINTBYBASEALPHA != 0 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE == 1 ) && ( m_nENVMAPMODE == 2 ) ), "Invalid combo combination ( ( SELFILLUMMODE == 1 ) && ( ENVMAPMODE == 2 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE == 2 ) && ( m_nENVMAPMODE != 3 ) ), "Invalid combo combination ( ( SELFILLUMMODE == 2 ) && ( ENVMAPMODE != 3 ) )" );
		AssertMsg( !( ( m_nENVMAPMODE == 2 ) && ( m_nBLENDTINTBYBASEALPHA != 0 ) ), "Invalid combo combination ( ( ENVMAPMODE == 2 ) && ( BLENDTINTBYBASEALPHA != 0 ) )" );
		return ( 72 * m_nDISTANCEALPHAMODE ) + ( 1080 * m_nSEAMLESS_MODE ) + ( 4320 * m_nDETAILTEXTUREMODE ) + ( 47520 * m_nBLENDTINTBYBASEALPHA ) + ( 95040 * m_nFLASHLIGHTMODE ) + ( 380160 * m_nSELFILLUMMODE ) + ( 1140480 * m_nENVMAPMODE ) + ( 5702400 * m_nDIFFUSELIGHTING ) + ( 11404800 * m_nSRGB_INPUT_ADAPTER ) + ( 22809600 * m_nVERTEXCOLOR ) + ( 45619200 * m_nDEPTHBLEND ) + 0;
	}
};

#define shaderStaticTest_vertexlit_and_unlit_generic_ps20b psh_forgot_to_set_static_DISTANCEALPHAMODE + psh_forgot_to_set_static_SEAMLESS_MODE + psh_forgot_to_set_static_DETAILTEXTUREMODE + psh_forgot_to_set_static_BLENDTINTBYBASEALPHA + psh_forgot_to_set_static_FLASHLIGHTMODE + psh_forgot_to_set_static_SELFILLUMMODE + psh_forgot_to_set_static_ENVMAPMODE + psh_forgot_to_set_static_DIFFUSELIGHTING + psh_forgot_to_set_static_SRGB_INPUT_ADAPTER + psh_forgot_to_set_static_VERTEXCOLOR + psh_forgot_to_set_static_DEPTHBLEND


class vertexlit_and_unlit_generic_ps20b_Dynamic_Index
{
	unsigned int m_nFLASHLIGHTSHADOWS : 2;
	unsigned int m_nSTATIC_LIGHT_LIGHTMAP : 2;
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nWRITE_DEPTH_TO_DESTALPHA : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHTSHADOWS : 1;
	bool m_bSTATIC_LIGHT_LIGHTMAP : 1;
	bool m_bWRITEWATERFOGTODESTALPHA : 1;
	bool m_bWRITE_DEPTH_TO_DESTALPHA : 1;
	bool m_bPIXELFOGTYPE : 1;
#endif	// _DEBUG
public:
	void SetFLASHLIGHTSHADOWS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nFLASHLIGHTSHADOWS = i;
#ifdef _DEBUG
		m_bFLASHLIGHTSHADOWS = true;
#endif	// _DEBUG
	}

	void SetSTATIC_LIGHT_LIGHTMAP( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nSTATIC_LIGHT_LIGHTMAP = i;
#ifdef _DEBUG
		m_bSTATIC_LIGHT_LIGHTMAP = true;
#endif	// _DEBUG
	}

	void SetWRITEWATERFOGTODESTALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWRITEWATERFOGTODESTALPHA = i;
#ifdef _DEBUG
		m_bWRITEWATERFOGTODESTALPHA = true;
#endif	// _DEBUG
	}

	void SetWRITE_DEPTH_TO_DESTALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWRITE_DEPTH_TO_DESTALPHA = i;
#ifdef _DEBUG
		m_bWRITE_DEPTH_TO_DESTALPHA = true;
#endif	// _DEBUG
	}

	void SetPIXELFOGTYPE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nPIXELFOGTYPE = i;
#ifdef _DEBUG
		m_bPIXELFOGTYPE = true;
#endif	// _DEBUG
	}

	vertexlit_and_unlit_generic_ps20b_Dynamic_Index(  )
	{
		m_nFLASHLIGHTSHADOWS = 0;
		m_nSTATIC_LIGHT_LIGHTMAP = 0;
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nWRITE_DEPTH_TO_DESTALPHA = 0;
		m_nPIXELFOGTYPE = 0;
#ifdef _DEBUG
		m_bFLASHLIGHTSHADOWS = false;
		m_bSTATIC_LIGHT_LIGHTMAP = false;
		m_bWRITEWATERFOGTODESTALPHA = false;
		m_bWRITE_DEPTH_TO_DESTALPHA = false;
		m_bPIXELFOGTYPE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHTSHADOWS && m_bSTATIC_LIGHT_LIGHTMAP && m_bWRITEWATERFOGTODESTALPHA && m_bWRITE_DEPTH_TO_DESTALPHA && m_bPIXELFOGTYPE );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nFLASHLIGHTSHADOWS ) + ( 2 * m_nSTATIC_LIGHT_LIGHTMAP ) + ( 6 * m_nWRITEWATERFOGTODESTALPHA ) + ( 12 * m_nWRITE_DEPTH_TO_DESTALPHA ) + ( 24 * m_nPIXELFOGTYPE ) + 0;
	}
};

#define shaderDynamicTest_vertexlit_and_unlit_generic_ps20b psh_forgot_to_set_dynamic_FLASHLIGHTSHADOWS + psh_forgot_to_set_dynamic_STATIC_LIGHT_LIGHTMAP + psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA + psh_forgot_to_set_dynamic_WRITE_DEPTH_TO_DESTALPHA + psh_forgot_to_set_dynamic_PIXELFOGTYPE

