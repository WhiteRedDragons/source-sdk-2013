// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ($FLASHLIGHTMODE == 0 && $FLASHLIGHTSHADOWS == 1)
// ($FLASHLIGHTMODE != 0 && $ENVMAPMODE != 0)
// ($FLASHLIGHTMODE != 0 && $DIFFUSELIGHTINGMODE != 0)
// ($FLASHLIGHTMODE != 0 && $SELFILLUMMODE != 0)
// ($FLASHLIGHTMODE != 0 && $NUM_LIGHTS != 0)
// ($FLASHLIGHTMODE != 0 && $WRITEWATERFOGTODESTALPHA != 0)
// ($FLASHLIGHTMODE != 0 && $WRITE_DEPTH_TO_DESTALPHA != 0)
// ($FLASHLIGHTMODE != 0 && $AMBIENT_LIGHT != 0)
// ($SELFILLUMMODE == 1 && $BLENDTINTBYBASEALPHA == 1)
// ($DETAILTEXTUREMODE == 5 && $SELFILLUMMODE == 2)
// ($DETAILTEXTUREMODE == 5 && $BLENDTINTBYBASEALPHA == 1)
// ($DETAILTEXTUREMODE == 6 && $SELFILLUMMODE != 0)
// ($DETAILTEXTUREMODE == 6 && $BLENDTINTBYBASEALPHA == 1)
// ($WRITEWATERFOGTODESTALPHA && $WRITE_DEPTH_TO_DESTALPHA)
// ($PIXELFOGTYPE != 1) && ($WRITEWATERFOGTODESTALPHA == 1)
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA

#pragma once
#include "shaderlib/cshader.h"
class vertexlit_and_unlit_generic_bump_ps30_Static_Index
{
	unsigned int m_nFLASHLIGHTMODE : 3;
	unsigned int m_nENVMAPMODE : 2;
	unsigned int m_nDIFFUSELIGHTINGMODE : 3;
	unsigned int m_nDETAILTEXTUREMODE : 4;
	unsigned int m_nSELFILLUMMODE : 2;
	unsigned int m_nBLENDTINTBYBASEALPHA : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHTMODE : 1;
	bool m_bENVMAPMODE : 1;
	bool m_bDIFFUSELIGHTINGMODE : 1;
	bool m_bDETAILTEXTUREMODE : 1;
	bool m_bSELFILLUMMODE : 1;
	bool m_bBLENDTINTBYBASEALPHA : 1;
#endif	// _DEBUG
public:
	void SetFLASHLIGHTMODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nFLASHLIGHTMODE = i;
#ifdef _DEBUG
		m_bFLASHLIGHTMODE = true;
#endif	// _DEBUG
	}

	void SetENVMAPMODE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nENVMAPMODE = i;
#ifdef _DEBUG
		m_bENVMAPMODE = true;
#endif	// _DEBUG
	}

	void SetDIFFUSELIGHTINGMODE( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nDIFFUSELIGHTINGMODE = i;
#ifdef _DEBUG
		m_bDIFFUSELIGHTINGMODE = true;
#endif	// _DEBUG
	}

	void SetDETAILTEXTUREMODE( int i )
	{
		Assert( i >= 0 && i <= 7 );
		m_nDETAILTEXTUREMODE = i;
#ifdef _DEBUG
		m_bDETAILTEXTUREMODE = true;
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

	void SetBLENDTINTBYBASEALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nBLENDTINTBYBASEALPHA = i;
#ifdef _DEBUG
		m_bBLENDTINTBYBASEALPHA = true;
#endif	// _DEBUG
	}

	vertexlit_and_unlit_generic_bump_ps30_Static_Index(  )
	{
		m_nFLASHLIGHTMODE = 0;
		m_nENVMAPMODE = 0;
		m_nDIFFUSELIGHTINGMODE = 0;
		m_nDETAILTEXTUREMODE = 0;
		m_nSELFILLUMMODE = 0;
		m_nBLENDTINTBYBASEALPHA = 0;
#ifdef _DEBUG
		m_bFLASHLIGHTMODE = false;
		m_bENVMAPMODE = false;
		m_bDIFFUSELIGHTINGMODE = false;
		m_bDETAILTEXTUREMODE = false;
		m_bSELFILLUMMODE = false;
		m_bBLENDTINTBYBASEALPHA = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHTMODE && m_bENVMAPMODE && m_bDIFFUSELIGHTINGMODE && m_bDETAILTEXTUREMODE && m_bSELFILLUMMODE && m_bBLENDTINTBYBASEALPHA );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nENVMAPMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( ENVMAPMODE != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nDIFFUSELIGHTINGMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( DIFFUSELIGHTINGMODE != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nSELFILLUMMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( SELFILLUMMODE != 0 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE == 1 ) && ( m_nBLENDTINTBYBASEALPHA == 1 ) ), "Invalid combo combination ( ( SELFILLUMMODE == 1 ) && ( BLENDTINTBYBASEALPHA == 1 ) )" );
		AssertMsg( !( ( m_nDETAILTEXTUREMODE == 5 ) && ( m_nSELFILLUMMODE == 2 ) ), "Invalid combo combination ( ( DETAILTEXTUREMODE == 5 ) && ( SELFILLUMMODE == 2 ) )" );
		AssertMsg( !( ( m_nDETAILTEXTUREMODE == 5 ) && ( m_nBLENDTINTBYBASEALPHA == 1 ) ), "Invalid combo combination ( ( DETAILTEXTUREMODE == 5 ) && ( BLENDTINTBYBASEALPHA == 1 ) )" );
		AssertMsg( !( ( m_nDETAILTEXTUREMODE == 6 ) && ( m_nSELFILLUMMODE != 0 ) ), "Invalid combo combination ( ( DETAILTEXTUREMODE == 6 ) && ( SELFILLUMMODE != 0 ) )" );
		AssertMsg( !( ( m_nDETAILTEXTUREMODE == 6 ) && ( m_nBLENDTINTBYBASEALPHA == 1 ) ), "Invalid combo combination ( ( DETAILTEXTUREMODE == 6 ) && ( BLENDTINTBYBASEALPHA == 1 ) )" );
		return ( 120 * m_nFLASHLIGHTMODE ) + ( 480 * m_nENVMAPMODE ) + ( 1440 * m_nDIFFUSELIGHTINGMODE ) + ( 7200 * m_nDETAILTEXTUREMODE ) + ( 57600 * m_nSELFILLUMMODE ) + ( 172800 * m_nBLENDTINTBYBASEALPHA ) + 0;
	}
};

#define shaderStaticTest_vertexlit_and_unlit_generic_bump_ps30 psh_forgot_to_set_static_FLASHLIGHTMODE + psh_forgot_to_set_static_ENVMAPMODE + psh_forgot_to_set_static_DIFFUSELIGHTINGMODE + psh_forgot_to_set_static_DETAILTEXTUREMODE + psh_forgot_to_set_static_SELFILLUMMODE + psh_forgot_to_set_static_BLENDTINTBYBASEALPHA


class vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index
{
	unsigned int m_nFLASHLIGHTSHADOWS : 2;
	unsigned int m_nNUM_LIGHTS : 3;
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nWRITE_DEPTH_TO_DESTALPHA : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHTSHADOWS : 1;
	bool m_bNUM_LIGHTS : 1;
	bool m_bPIXELFOGTYPE : 1;
	bool m_bWRITEWATERFOGTODESTALPHA : 1;
	bool m_bWRITE_DEPTH_TO_DESTALPHA : 1;
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

	void SetNUM_LIGHTS( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nNUM_LIGHTS = i;
#ifdef _DEBUG
		m_bNUM_LIGHTS = true;
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

	vertexlit_and_unlit_generic_bump_ps30_Dynamic_Index(  )
	{
		m_nFLASHLIGHTSHADOWS = 0;
		m_nNUM_LIGHTS = 0;
		m_nPIXELFOGTYPE = 0;
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nWRITE_DEPTH_TO_DESTALPHA = 0;
#ifdef _DEBUG
		m_bFLASHLIGHTSHADOWS = false;
		m_bNUM_LIGHTS = false;
		m_bPIXELFOGTYPE = false;
		m_bWRITEWATERFOGTODESTALPHA = false;
		m_bWRITE_DEPTH_TO_DESTALPHA = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHTSHADOWS && m_bNUM_LIGHTS && m_bPIXELFOGTYPE && m_bWRITEWATERFOGTODESTALPHA && m_bWRITE_DEPTH_TO_DESTALPHA );
		AssertMsg( !( m_nWRITEWATERFOGTODESTALPHA && m_nWRITE_DEPTH_TO_DESTALPHA ), "Invalid combo combination ( WRITEWATERFOGTODESTALPHA && WRITE_DEPTH_TO_DESTALPHA )" );
		AssertMsg( !( ( m_nPIXELFOGTYPE != 1 ) && ( m_nWRITEWATERFOGTODESTALPHA == 1 ) ), "Invalid combo combination ( ( PIXELFOGTYPE != 1 ) && ( WRITEWATERFOGTODESTALPHA == 1 ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nFLASHLIGHTSHADOWS ) + ( 2 * m_nNUM_LIGHTS ) + ( 10 * m_nPIXELFOGTYPE ) + ( 30 * m_nWRITEWATERFOGTODESTALPHA ) + ( 60 * m_nWRITE_DEPTH_TO_DESTALPHA ) + 0;
	}
};

#define shaderDynamicTest_vertexlit_and_unlit_generic_bump_ps30 psh_forgot_to_set_dynamic_FLASHLIGHTSHADOWS + psh_forgot_to_set_dynamic_NUM_LIGHTS + psh_forgot_to_set_dynamic_PIXELFOGTYPE + psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA + psh_forgot_to_set_dynamic_WRITE_DEPTH_TO_DESTALPHA

