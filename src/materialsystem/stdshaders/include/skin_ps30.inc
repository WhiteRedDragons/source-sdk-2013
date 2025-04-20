// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ($FLASHLIGHTMODE == 0 && $FLASHLIGHTSHADOWS != 0)
// ($FLASHLIGHTMODE != 0 && $NUM_LIGHTS != 0)
// ($FLASHLIGHTMODE != 0 && $CUBEMAP != 0)
// ($FLASHLIGHTMODE != 0 && $LIGHTWARPTEXTURE != 0)
// ($FLASHLIGHTMODE != 0 && $RIMLIGHT != 0)
// ($FLASHLIGHTMODE != 0 && $SELFILLUMMODE != 0)
// ($RIMLIGHT != 0 && $FASTPATH_NOBUMP != 0)
// ($SELFILLUMMODE != 0 && $FASTPATH_NOBUMP != 0)
// ($SELFILLUMMODE != 0 && $BLENDTINTBYBASEALPHA != 0)
// ($BLENDTINTBYBASEALPHA != 0 && $FASTPATH_NOBUMP != 0)
// ($FASTPATH_NOBUMP != 0 && $PHONG_USE_EXPONENT_FACTOR == 1)
// ($FASTPATH_NOBUMP != 0 && $DETAILTEXTUREMODE != 0)
// ($FASTPATH_NOBUMP != 0 && $PHONGWARPTEXTURE != 0)
// ($WRITEWATERFOGTODESTALPHA && $WRITE_DEPTH_TO_DESTALPHA)
// ($PIXELFOGTYPE != 1 && $WRITEWATERFOGTODESTALPHA == 1)
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA

#pragma once
#include "shaderlib/cshader.h"
class skin_ps30_Static_Index
{
	unsigned int m_nFLASHLIGHTMODE : 3;
	unsigned int m_nCUBEMAP : 2;
	unsigned int m_nLIGHTWARPTEXTURE : 2;
	unsigned int m_nRIMLIGHT : 2;
	unsigned int m_nSELFILLUMMODE : 2;
	unsigned int m_nBLENDTINTBYBASEALPHA : 2;
	unsigned int m_nFASTPATH_NOBUMP : 2;
	unsigned int m_nDETAILTEXTUREMODE : 4;
	unsigned int m_nPHONGWARPTEXTURE : 2;
	unsigned int m_nWRINKLEMAP : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHTMODE : 1;
	bool m_bCUBEMAP : 1;
	bool m_bLIGHTWARPTEXTURE : 1;
	bool m_bRIMLIGHT : 1;
	bool m_bSELFILLUMMODE : 1;
	bool m_bBLENDTINTBYBASEALPHA : 1;
	bool m_bFASTPATH_NOBUMP : 1;
	bool m_bDETAILTEXTUREMODE : 1;
	bool m_bPHONGWARPTEXTURE : 1;
	bool m_bWRINKLEMAP : 1;
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

	void SetCUBEMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCUBEMAP = i;
#ifdef _DEBUG
		m_bCUBEMAP = true;
#endif	// _DEBUG
	}

	void SetLIGHTWARPTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nLIGHTWARPTEXTURE = i;
#ifdef _DEBUG
		m_bLIGHTWARPTEXTURE = true;
#endif	// _DEBUG
	}

	void SetRIMLIGHT( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nRIMLIGHT = i;
#ifdef _DEBUG
		m_bRIMLIGHT = true;
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

	void SetFASTPATH_NOBUMP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nFASTPATH_NOBUMP = i;
#ifdef _DEBUG
		m_bFASTPATH_NOBUMP = true;
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

	void SetPHONGWARPTEXTURE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPHONGWARPTEXTURE = i;
#ifdef _DEBUG
		m_bPHONGWARPTEXTURE = true;
#endif	// _DEBUG
	}

	void SetWRINKLEMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWRINKLEMAP = i;
#ifdef _DEBUG
		m_bWRINKLEMAP = true;
#endif	// _DEBUG
	}

	skin_ps30_Static_Index(  )
	{
		m_nFLASHLIGHTMODE = 0;
		m_nCUBEMAP = 0;
		m_nLIGHTWARPTEXTURE = 0;
		m_nRIMLIGHT = 0;
		m_nSELFILLUMMODE = 0;
		m_nBLENDTINTBYBASEALPHA = 0;
		m_nFASTPATH_NOBUMP = 0;
		m_nDETAILTEXTUREMODE = 0;
		m_nPHONGWARPTEXTURE = 0;
		m_nWRINKLEMAP = 0;
#ifdef _DEBUG
		m_bFLASHLIGHTMODE = false;
		m_bCUBEMAP = false;
		m_bLIGHTWARPTEXTURE = false;
		m_bRIMLIGHT = false;
		m_bSELFILLUMMODE = false;
		m_bBLENDTINTBYBASEALPHA = false;
		m_bFASTPATH_NOBUMP = false;
		m_bDETAILTEXTUREMODE = false;
		m_bPHONGWARPTEXTURE = false;
		m_bWRINKLEMAP = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHTMODE && m_bCUBEMAP && m_bLIGHTWARPTEXTURE && m_bRIMLIGHT && m_bSELFILLUMMODE && m_bBLENDTINTBYBASEALPHA && m_bFASTPATH_NOBUMP && m_bDETAILTEXTUREMODE && m_bPHONGWARPTEXTURE && m_bWRINKLEMAP );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nCUBEMAP != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( CUBEMAP != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nLIGHTWARPTEXTURE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( LIGHTWARPTEXTURE != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nRIMLIGHT != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( RIMLIGHT != 0 ) )" );
		AssertMsg( !( ( m_nFLASHLIGHTMODE != 0 ) && ( m_nSELFILLUMMODE != 0 ) ), "Invalid combo combination ( ( FLASHLIGHTMODE != 0 ) && ( SELFILLUMMODE != 0 ) )" );
		AssertMsg( !( ( m_nRIMLIGHT != 0 ) && ( m_nFASTPATH_NOBUMP != 0 ) ), "Invalid combo combination ( ( RIMLIGHT != 0 ) && ( FASTPATH_NOBUMP != 0 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE != 0 ) && ( m_nFASTPATH_NOBUMP != 0 ) ), "Invalid combo combination ( ( SELFILLUMMODE != 0 ) && ( FASTPATH_NOBUMP != 0 ) )" );
		AssertMsg( !( ( m_nSELFILLUMMODE != 0 ) && ( m_nBLENDTINTBYBASEALPHA != 0 ) ), "Invalid combo combination ( ( SELFILLUMMODE != 0 ) && ( BLENDTINTBYBASEALPHA != 0 ) )" );
		AssertMsg( !( ( m_nBLENDTINTBYBASEALPHA != 0 ) && ( m_nFASTPATH_NOBUMP != 0 ) ), "Invalid combo combination ( ( BLENDTINTBYBASEALPHA != 0 ) && ( FASTPATH_NOBUMP != 0 ) )" );
		AssertMsg( !( ( m_nFASTPATH_NOBUMP != 0 ) && ( m_nDETAILTEXTUREMODE != 0 ) ), "Invalid combo combination ( ( FASTPATH_NOBUMP != 0 ) && ( DETAILTEXTUREMODE != 0 ) )" );
		AssertMsg( !( ( m_nFASTPATH_NOBUMP != 0 ) && ( m_nPHONGWARPTEXTURE != 0 ) ), "Invalid combo combination ( ( FASTPATH_NOBUMP != 0 ) && ( PHONGWARPTEXTURE != 0 ) )" );
		return ( 240 * m_nFLASHLIGHTMODE ) + ( 960 * m_nCUBEMAP ) + ( 1920 * m_nLIGHTWARPTEXTURE ) + ( 3840 * m_nRIMLIGHT ) + ( 7680 * m_nSELFILLUMMODE ) + ( 23040 * m_nBLENDTINTBYBASEALPHA ) + ( 46080 * m_nFASTPATH_NOBUMP ) + ( 92160 * m_nDETAILTEXTUREMODE ) + ( 737280 * m_nPHONGWARPTEXTURE ) + ( 1474560 * m_nWRINKLEMAP ) + 0;
	}
};

#define shaderStaticTest_skin_ps30 psh_forgot_to_set_static_FLASHLIGHTMODE + psh_forgot_to_set_static_CUBEMAP + psh_forgot_to_set_static_LIGHTWARPTEXTURE + psh_forgot_to_set_static_RIMLIGHT + psh_forgot_to_set_static_SELFILLUMMODE + psh_forgot_to_set_static_BLENDTINTBYBASEALPHA + psh_forgot_to_set_static_FASTPATH_NOBUMP + psh_forgot_to_set_static_DETAILTEXTUREMODE + psh_forgot_to_set_static_PHONGWARPTEXTURE + psh_forgot_to_set_static_WRINKLEMAP


class skin_ps30_Dynamic_Index
{
	unsigned int m_nFLASHLIGHTSHADOWS : 2;
	unsigned int m_nNUM_LIGHTS : 3;
	unsigned int m_nPHONG_USE_EXPONENT_FACTOR : 2;
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nWRITE_DEPTH_TO_DESTALPHA : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
#ifdef _DEBUG
	bool m_bFLASHLIGHTSHADOWS : 1;
	bool m_bNUM_LIGHTS : 1;
	bool m_bPHONG_USE_EXPONENT_FACTOR : 1;
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

	void SetNUM_LIGHTS( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nNUM_LIGHTS = i;
#ifdef _DEBUG
		m_bNUM_LIGHTS = true;
#endif	// _DEBUG
	}

	void SetPHONG_USE_EXPONENT_FACTOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPHONG_USE_EXPONENT_FACTOR = i;
#ifdef _DEBUG
		m_bPHONG_USE_EXPONENT_FACTOR = true;
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

	skin_ps30_Dynamic_Index(  )
	{
		m_nFLASHLIGHTSHADOWS = 0;
		m_nNUM_LIGHTS = 0;
		m_nPHONG_USE_EXPONENT_FACTOR = 0;
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nWRITE_DEPTH_TO_DESTALPHA = 0;
		m_nPIXELFOGTYPE = 0;
#ifdef _DEBUG
		m_bFLASHLIGHTSHADOWS = false;
		m_bNUM_LIGHTS = false;
		m_bPHONG_USE_EXPONENT_FACTOR = false;
		m_bWRITEWATERFOGTODESTALPHA = false;
		m_bWRITE_DEPTH_TO_DESTALPHA = false;
		m_bPIXELFOGTYPE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFLASHLIGHTSHADOWS && m_bNUM_LIGHTS && m_bPHONG_USE_EXPONENT_FACTOR && m_bWRITEWATERFOGTODESTALPHA && m_bWRITE_DEPTH_TO_DESTALPHA && m_bPIXELFOGTYPE );
		AssertMsg( !( m_nWRITEWATERFOGTODESTALPHA && m_nWRITE_DEPTH_TO_DESTALPHA ), "Invalid combo combination ( WRITEWATERFOGTODESTALPHA && WRITE_DEPTH_TO_DESTALPHA )" );
		AssertMsg( !( ( m_nPIXELFOGTYPE != 1 ) && ( m_nWRITEWATERFOGTODESTALPHA == 1 ) ), "Invalid combo combination ( ( PIXELFOGTYPE != 1 ) && ( WRITEWATERFOGTODESTALPHA == 1 ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nFLASHLIGHTSHADOWS ) + ( 2 * m_nNUM_LIGHTS ) + ( 10 * m_nPHONG_USE_EXPONENT_FACTOR ) + ( 20 * m_nWRITEWATERFOGTODESTALPHA ) + ( 40 * m_nWRITE_DEPTH_TO_DESTALPHA ) + ( 80 * m_nPIXELFOGTYPE ) + 0;
	}
};

#define shaderDynamicTest_skin_ps30 psh_forgot_to_set_dynamic_FLASHLIGHTSHADOWS + psh_forgot_to_set_dynamic_NUM_LIGHTS + psh_forgot_to_set_dynamic_PHONG_USE_EXPONENT_FACTOR + psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA + psh_forgot_to_set_dynamic_WRITE_DEPTH_TO_DESTALPHA + psh_forgot_to_set_dynamic_PIXELFOGTYPE

