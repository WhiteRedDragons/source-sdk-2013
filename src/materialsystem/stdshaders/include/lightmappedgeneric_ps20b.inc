// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// ($DISTANCEALPHAMODE != 0 && $SELFILLUM)
// ($DISTANCEALPHAMODE != 0 && $WARPLIGHTING)
// ($DISTANCEALPHAMODE != 0 && $BUMPMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $DETAILTEXTUREMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $SEAMLESS_BUMPMASK != 0)
// ($DISTANCEALPHAMODE != 0 && $BASETEXTURE2_MODE != 0)
// ($DISTANCEALPHAMODE != 0 && $BLENDINGMODE != 0)
// ($DISTANCEALPHAMODE != 0 && $FASTPATH == 0)
// ($SELFILLUM && $ENVMAPMODE == 2)
// ($SELFILLUM && $ENVMAPMODE == 6)
// ($SELFILLUM && $SEAMLESS_BUMPMASK == 2)
// ($ENVMAPMODE == 0 && $BASETEXTURE2_MODE > 1)
// ($ENVMAPMODE == 3 && $BUMPMODE == 0)
// ($ENVMAPMODE == 7 && $BUMPMODE == 0)
// ($WARPLIGHTING && $BUMPMODE == 3)
// ($WARPLIGHTING && $BUMPMODE == 4)
// ($WARPLIGHTING && $BUMPMODE == 7)
// ($WARPLIGHTING && $BUMPMODE == 8)
// ($WARPLIGHTING && $DETAILTEXTUREMODE != 0)
// ($WARPLIGHTING && $SEAMLESS_BUMPMASK == 2)
// ($BUMPMODE == 3 && $SEAMLESS_BUMPMASK == 2)
// ($BUMPMODE == 4 && $SEAMLESS_BUMPMASK == 2)
// ($BUMPMODE == 7 && $SEAMLESS_BUMPMASK == 2)
// ($BUMPMODE == 8 && $SEAMLESS_BUMPMASK == 2)
// ($BUMPMODE == 0 && $DETAILTEXTUREMODE == 3)
// ($BUMPMODE != 0 && $DETAILTEXTUREMODE == 4)
// ($BUMPMODE == 0 && $BASETEXTURE2_MODE == 0 && $BLENDINGMODE != 0)
// ($DETAILTEXTUREMODE != 0 && $SEAMLESS_BUMPMASK != 0)
// ($SEAMLESS_BUMPMASK == 1 && ($BLENDINGMODE == 1 || $BLENDINGMODE == 3))
// ($SEAMLESS_BUMPMASK == 2 && $BASETEXTURE2_MODE != 0)
// defined $HDRTYPE && defined $HDRENABLED && !$HDRTYPE && $HDRENABLED
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA

#pragma once
#include "shaderlib/cshader.h"
class lightmappedgeneric_ps20b_Static_Index
{
	unsigned int m_nDISTANCEALPHAMODE : 3;
	unsigned int m_nSELFILLUM : 2;
	unsigned int m_nENVMAPMODE : 4;
	unsigned int m_nWARPLIGHTING : 2;
	unsigned int m_nBUMPMODE : 4;
	unsigned int m_nDETAILTEXTUREMODE : 3;
	unsigned int m_nSEAMLESS_BUMPMASK : 2;
	unsigned int m_nBASETEXTURE2_MODE : 3;
	unsigned int m_nBLENDINGMODE : 3;
#ifdef _DEBUG
	bool m_bDISTANCEALPHAMODE : 1;
	bool m_bSELFILLUM : 1;
	bool m_bENVMAPMODE : 1;
	bool m_bWARPLIGHTING : 1;
	bool m_bBUMPMODE : 1;
	bool m_bDETAILTEXTUREMODE : 1;
	bool m_bSEAMLESS_BUMPMASK : 1;
	bool m_bBASETEXTURE2_MODE : 1;
	bool m_bBLENDINGMODE : 1;
#endif	// _DEBUG
public:
	void SetDISTANCEALPHAMODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nDISTANCEALPHAMODE = i;
#ifdef _DEBUG
		m_bDISTANCEALPHAMODE = true;
#endif	// _DEBUG
	}

	void SetSELFILLUM( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSELFILLUM = i;
#ifdef _DEBUG
		m_bSELFILLUM = true;
#endif	// _DEBUG
	}

	void SetENVMAPMODE( int i )
	{
		Assert( i >= 0 && i <= 8 );
		m_nENVMAPMODE = i;
#ifdef _DEBUG
		m_bENVMAPMODE = true;
#endif	// _DEBUG
	}

	void SetWARPLIGHTING( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nWARPLIGHTING = i;
#ifdef _DEBUG
		m_bWARPLIGHTING = true;
#endif	// _DEBUG
	}

	void SetBUMPMODE( int i )
	{
		Assert( i >= 0 && i <= 8 );
		m_nBUMPMODE = i;
#ifdef _DEBUG
		m_bBUMPMODE = true;
#endif	// _DEBUG
	}

	void SetDETAILTEXTUREMODE( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nDETAILTEXTUREMODE = i;
#ifdef _DEBUG
		m_bDETAILTEXTUREMODE = true;
#endif	// _DEBUG
	}

	void SetSEAMLESS_BUMPMASK( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nSEAMLESS_BUMPMASK = i;
#ifdef _DEBUG
		m_bSEAMLESS_BUMPMASK = true;
#endif	// _DEBUG
	}

	void SetBASETEXTURE2_MODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nBASETEXTURE2_MODE = i;
#ifdef _DEBUG
		m_bBASETEXTURE2_MODE = true;
#endif	// _DEBUG
	}

	void SetBLENDINGMODE( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nBLENDINGMODE = i;
#ifdef _DEBUG
		m_bBLENDINGMODE = true;
#endif	// _DEBUG
	}

	lightmappedgeneric_ps20b_Static_Index(  )
	{
		m_nDISTANCEALPHAMODE = 0;
		m_nSELFILLUM = 0;
		m_nENVMAPMODE = 0;
		m_nWARPLIGHTING = 0;
		m_nBUMPMODE = 0;
		m_nDETAILTEXTUREMODE = 0;
		m_nSEAMLESS_BUMPMASK = 0;
		m_nBASETEXTURE2_MODE = 0;
		m_nBLENDINGMODE = 0;
#ifdef _DEBUG
		m_bDISTANCEALPHAMODE = false;
		m_bSELFILLUM = false;
		m_bENVMAPMODE = false;
		m_bWARPLIGHTING = false;
		m_bBUMPMODE = false;
		m_bDETAILTEXTUREMODE = false;
		m_bSEAMLESS_BUMPMASK = false;
		m_bBASETEXTURE2_MODE = false;
		m_bBLENDINGMODE = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bDISTANCEALPHAMODE && m_bSELFILLUM && m_bENVMAPMODE && m_bWARPLIGHTING && m_bBUMPMODE && m_bDETAILTEXTUREMODE && m_bSEAMLESS_BUMPMASK && m_bBASETEXTURE2_MODE && m_bBLENDINGMODE );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && m_nSELFILLUM ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && SELFILLUM )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && m_nWARPLIGHTING ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && WARPLIGHTING )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nBUMPMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( BUMPMODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nDETAILTEXTUREMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( DETAILTEXTUREMODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nSEAMLESS_BUMPMASK != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( SEAMLESS_BUMPMASK != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nBASETEXTURE2_MODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( BASETEXTURE2_MODE != 0 ) )" );
		AssertMsg( !( ( m_nDISTANCEALPHAMODE != 0 ) && ( m_nBLENDINGMODE != 0 ) ), "Invalid combo combination ( ( DISTANCEALPHAMODE != 0 ) && ( BLENDINGMODE != 0 ) )" );
		AssertMsg( !( m_nSELFILLUM && ( m_nENVMAPMODE == 2 ) ), "Invalid combo combination ( SELFILLUM && ( ENVMAPMODE == 2 ) )" );
		AssertMsg( !( m_nSELFILLUM && ( m_nENVMAPMODE == 6 ) ), "Invalid combo combination ( SELFILLUM && ( ENVMAPMODE == 6 ) )" );
		AssertMsg( !( m_nSELFILLUM && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( SELFILLUM && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nENVMAPMODE == 0 ) && ( m_nBASETEXTURE2_MODE > 1 ) ), "Invalid combo combination ( ( ENVMAPMODE == 0 ) && ( BASETEXTURE2_MODE > 1 ) )" );
		AssertMsg( !( ( m_nENVMAPMODE == 3 ) && ( m_nBUMPMODE == 0 ) ), "Invalid combo combination ( ( ENVMAPMODE == 3 ) && ( BUMPMODE == 0 ) )" );
		AssertMsg( !( ( m_nENVMAPMODE == 7 ) && ( m_nBUMPMODE == 0 ) ), "Invalid combo combination ( ( ENVMAPMODE == 7 ) && ( BUMPMODE == 0 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nBUMPMODE == 3 ) ), "Invalid combo combination ( WARPLIGHTING && ( BUMPMODE == 3 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nBUMPMODE == 4 ) ), "Invalid combo combination ( WARPLIGHTING && ( BUMPMODE == 4 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nBUMPMODE == 7 ) ), "Invalid combo combination ( WARPLIGHTING && ( BUMPMODE == 7 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nBUMPMODE == 8 ) ), "Invalid combo combination ( WARPLIGHTING && ( BUMPMODE == 8 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nDETAILTEXTUREMODE != 0 ) ), "Invalid combo combination ( WARPLIGHTING && ( DETAILTEXTUREMODE != 0 ) )" );
		AssertMsg( !( m_nWARPLIGHTING && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( WARPLIGHTING && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 3 ) && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( ( BUMPMODE == 3 ) && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 4 ) && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( ( BUMPMODE == 4 ) && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 7 ) && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( ( BUMPMODE == 7 ) && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 8 ) && ( m_nSEAMLESS_BUMPMASK == 2 ) ), "Invalid combo combination ( ( BUMPMODE == 8 ) && ( SEAMLESS_BUMPMASK == 2 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 0 ) && ( m_nDETAILTEXTUREMODE == 3 ) ), "Invalid combo combination ( ( BUMPMODE == 0 ) && ( DETAILTEXTUREMODE == 3 ) )" );
		AssertMsg( !( ( m_nBUMPMODE != 0 ) && ( m_nDETAILTEXTUREMODE == 4 ) ), "Invalid combo combination ( ( BUMPMODE != 0 ) && ( DETAILTEXTUREMODE == 4 ) )" );
		AssertMsg( !( ( m_nBUMPMODE == 0 ) && ( ( m_nBASETEXTURE2_MODE == 0 ) && ( m_nBLENDINGMODE != 0 ) ) ), "Invalid combo combination ( ( BUMPMODE == 0 ) && ( ( BASETEXTURE2_MODE == 0 ) && ( BLENDINGMODE != 0 ) ) )" );
		AssertMsg( !( ( m_nDETAILTEXTUREMODE != 0 ) && ( m_nSEAMLESS_BUMPMASK != 0 ) ), "Invalid combo combination ( ( DETAILTEXTUREMODE != 0 ) && ( SEAMLESS_BUMPMASK != 0 ) )" );
		AssertMsg( !( ( m_nSEAMLESS_BUMPMASK == 1 ) && ( ( m_nBLENDINGMODE == 1 ) || ( m_nBLENDINGMODE == 3 ) ) ), "Invalid combo combination ( ( SEAMLESS_BUMPMASK == 1 ) && ( ( BLENDINGMODE == 1 ) || ( BLENDINGMODE == 3 ) ) )" );
		AssertMsg( !( ( m_nSEAMLESS_BUMPMASK == 2 ) && ( m_nBASETEXTURE2_MODE != 0 ) ), "Invalid combo combination ( ( SEAMLESS_BUMPMASK == 2 ) && ( BASETEXTURE2_MODE != 0 ) )" );
		return ( 72 * m_nDISTANCEALPHAMODE ) + ( 288 * m_nSELFILLUM ) + ( 576 * m_nENVMAPMODE ) + ( 5184 * m_nWARPLIGHTING ) + ( 10368 * m_nBUMPMODE ) + ( 93312 * m_nDETAILTEXTUREMODE ) + ( 466560 * m_nSEAMLESS_BUMPMASK ) + ( 1399680 * m_nBASETEXTURE2_MODE ) + ( 5598720 * m_nBLENDINGMODE ) + 0;
	}
};

#define shaderStaticTest_lightmappedgeneric_ps20b psh_forgot_to_set_static_DISTANCEALPHAMODE + psh_forgot_to_set_static_SELFILLUM + psh_forgot_to_set_static_ENVMAPMODE + psh_forgot_to_set_static_WARPLIGHTING + psh_forgot_to_set_static_BUMPMODE + psh_forgot_to_set_static_DETAILTEXTUREMODE + psh_forgot_to_set_static_SEAMLESS_BUMPMASK + psh_forgot_to_set_static_BASETEXTURE2_MODE + psh_forgot_to_set_static_BLENDINGMODE


class lightmappedgeneric_ps20b_Dynamic_Index
{
	unsigned int m_nFASTPATH : 2;
	unsigned int m_nWRITEWATERFOGTODESTALPHA : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
	unsigned int m_nWRITE_DEPTH_TO_DESTALPHA : 2;
	unsigned int m_nBICUBIC_LIGHTMAP : 2;
#ifdef _DEBUG
	bool m_bFASTPATH : 1;
	bool m_bWRITEWATERFOGTODESTALPHA : 1;
	bool m_bPIXELFOGTYPE : 1;
	bool m_bWRITE_DEPTH_TO_DESTALPHA : 1;
	bool m_bBICUBIC_LIGHTMAP : 1;
#endif	// _DEBUG
public:
	void SetFASTPATH( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nFASTPATH = i;
#ifdef _DEBUG
		m_bFASTPATH = true;
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

	void SetPIXELFOGTYPE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nPIXELFOGTYPE = i;
#ifdef _DEBUG
		m_bPIXELFOGTYPE = true;
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

	void SetBICUBIC_LIGHTMAP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nBICUBIC_LIGHTMAP = i;
#ifdef _DEBUG
		m_bBICUBIC_LIGHTMAP = true;
#endif	// _DEBUG
	}

	lightmappedgeneric_ps20b_Dynamic_Index(  )
	{
		m_nFASTPATH = 0;
		m_nWRITEWATERFOGTODESTALPHA = 0;
		m_nPIXELFOGTYPE = 0;
		m_nWRITE_DEPTH_TO_DESTALPHA = 0;
		m_nBICUBIC_LIGHTMAP = 0;
#ifdef _DEBUG
		m_bFASTPATH = false;
		m_bWRITEWATERFOGTODESTALPHA = false;
		m_bPIXELFOGTYPE = false;
		m_bWRITE_DEPTH_TO_DESTALPHA = false;
		m_bBICUBIC_LIGHTMAP = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bFASTPATH && m_bWRITEWATERFOGTODESTALPHA && m_bPIXELFOGTYPE && m_bWRITE_DEPTH_TO_DESTALPHA && m_bBICUBIC_LIGHTMAP );
		AssertMsg( !( 1 && ( 1 && ( ( m_nPIXELFOGTYPE != 1 ) && m_nWRITEWATERFOGTODESTALPHA ) ) ), "Invalid combo combination ( 1 && ( 1 && ( ( PIXELFOGTYPE != 1 ) && WRITEWATERFOGTODESTALPHA ) ) )" );
		return ( 1 * m_nFASTPATH ) + ( 3 * m_nWRITEWATERFOGTODESTALPHA ) + ( 6 * m_nPIXELFOGTYPE ) + ( 18 * m_nWRITE_DEPTH_TO_DESTALPHA ) + ( 36 * m_nBICUBIC_LIGHTMAP ) + 0;
	}
};

#define shaderDynamicTest_lightmappedgeneric_ps20b psh_forgot_to_set_dynamic_FASTPATH + psh_forgot_to_set_dynamic_WRITEWATERFOGTODESTALPHA + psh_forgot_to_set_dynamic_PIXELFOGTYPE + psh_forgot_to_set_dynamic_WRITE_DEPTH_TO_DESTALPHA + psh_forgot_to_set_dynamic_BICUBIC_LIGHTMAP

