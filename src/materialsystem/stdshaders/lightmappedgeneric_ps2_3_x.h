#define USE_32BIT_LIGHTMAPS_ON_360 //uncomment to use 32bit lightmaps, be sure to keep this in sync with the same #define in materialsystem/cmatlightmaps.cpp

#include "common_ps_fxc.h"
// #include "common_flashlight_fxc.h"
#include "common_lightmappedgeneric_fxc.h"

#if SEAMLESS
#define USE_FAST_PATH 1
#else
#define USE_FAST_PATH FASTPATH
#endif

const float4 g_EnvmapTint : register( c0 );

#if (DISTANCEALPHAMODE != 0 && USE_FAST_PATH)
	#if OUTLINE
		const float4 g_OutlineParams : register( c2 );
		#define OUTLINE_MIN_VALUE0 g_OutlineParams.x
		#define OUTLINE_MIN_VALUE1 g_OutlineParams.y
		#define OUTLINE_MAX_VALUE0 g_OutlineParams.z
		#define OUTLINE_MAX_VALUE1 g_OutlineParams.w
		
		const float4 g_OutlineColor : register( c3 );
		#define OUTLINE_COLOR g_OutlineColor
	#endif

	#if SOFTEDGES
		const float4 g_EdgeSoftnessParms : register( c4 );
		#define SOFT_MASK_MIN g_EdgeSoftnessParms.x
		#define SOFT_MASK_MAX g_EdgeSoftnessParms.y
	#endif
#else

const float3 g_EnvmapContrast				: register( c2 );
const float3 g_EnvmapSaturation				: register( c3 );
const float4 g_FresnelReflectionReg			: register( c4 );
#define g_FresnelReflection g_FresnelReflectionReg.a
#define g_OneMinusFresnelReflection g_FresnelReflectionReg.b
const float4 g_SelfIllumTint					: register( c7 );
#endif

const float4 g_DetailTint_and_BlendFactor	: register( c8 );
#define g_DetailTint (g_DetailTint_and_BlendFactor.rgb)
#define g_DetailBlendFactor (g_DetailTint_and_BlendFactor.w)

const float3 g_EyePos						: register( c10 );
const float4 g_FogParams						: register( c11 );
const float4 g_TintValuesAndLightmapScale	: register( c12 );

#define g_flAlpha2 g_TintValuesAndLightmapScale.w

/*
const float4 g_FlashlightAttenuationFactors	: register( c13 );
const float3 g_FlashlightPos				: register( c14 );
const float4x4 g_FlashlightWorldToTexture	: register( c15 ); // through c18
const float4 g_ShadowTweaks					: register( c19 );
*/

// Parallax cubemaps
#if PARALLAXCORRECT
const float4 cubemapPos : register( c21 );
const float4x4 obbMatrix : register( c22 ); //through c25
#endif

sampler BaseTextureSampler		: register( s0 );
sampler LightmapSampler			: register( s1 );
sampler EnvmapSampler			: register( s2 );
#if FANCY_BLENDING
sampler BlendModulationSampler	: register( s3 );
#endif

#if DETAILTEXTURE
sampler DetailSampler			: register( s12 );
#endif

sampler BumpmapSampler			: register( s4 );
#if NORMAL_DECODE_MODE == NORM_DECODE_ATI2N_ALPHA
sampler AlphaMapSampler		: register( s9 );	// alpha
#else
#define AlphaMapSampler		BumpmapSampler
#endif

#if BUMPMAP2 == 1
sampler BumpmapSampler2			: register( s5 );
#if NORMAL_DECODE_MODE == NORM_DECODE_ATI2N_ALPHA
sampler AlphaMapSampler2		: register( s10 );	// alpha
#else
#define AlphaMapSampler2		BumpmapSampler2
#endif
#else
sampler EnvmapMaskSampler		: register( s5 );
#endif


#if WARPLIGHTING
sampler WarpLightingSampler		: register( s6 );
#endif
sampler BaseTextureSampler2		: register( s7 );

#if BUMPMASK == 1
sampler BumpMaskSampler			: register( s8 );
#if NORMALMASK_DECODE_MODE == NORM_DECODE_ATI2N_ALPHA
sampler AlphaMaskSampler		: register( s11 );	// alpha
#else
#define AlphaMaskSampler		BumpMaskSampler
#endif
#endif

/*
#if defined( _X360 ) && FLASHLIGHT
sampler FlashlightSampler		: register( s13 );
sampler ShadowDepthSampler		: register( s14 );
sampler RandRotSampler			: register( s15 );
#endif
*/

struct PS_INPUT
{
#if SEAMLESS
	float3 SeamlessTexCoord						: TEXCOORD0; // zy xz
	float4 detailOrBumpAndEnvmapMaskTexCoord	: TEXCOORD1; // envmap mask
#else
	float2 baseTexCoord				: TEXCOORD0;

	// detail textures and bumpmaps are mutually exclusive so that we have enough texcoords.
//	#if ( RELIEF_MAPPING == 0 )
		float4 detailOrBumpAndEnvmapMaskTexCoord	: TEXCOORD1;
//	#endif
#endif

	float4 lightmapTexCoord1And2	: TEXCOORD2;
	float4 lightmapTexCoord3		: TEXCOORD3;
	float4 worldPos_projPosZ		: TEXCOORD4;
	float3x3 tangentSpaceTranspose	: TEXCOORD5;
	// tangentSpaceTranspose		: TEXCOORD6
	// tangentSpaceTranspose		: TEXCOORD7
	float4 vertexColor				: COLOR;
	float4 vertexBlendX_fogFactorW	: COLOR1;

	// Extra iterators on 360, used in flashlight combo
	/*
#if defined( _X360 ) && FLASHLIGHT
	float4 flashlightSpacePos		: TEXCOORD8;
	float4 vProjPos					: TEXCOORD9;
#endif
	*/
};

// Dead Feature
/*
#if LIGHTING_PREVIEW == 2
LPREVIEW_PS_OUT main( PS_INPUT i ) : COLOR
#else
float4 main( PS_INPUT i ) : COLOR
#endif
*/
float4 main(PS_INPUT i) : COLOR
{
	float4 baseColor = 0.0f;
	float4 baseColor2 = 0.0f;
	float4 vNormal = float4(0, 0, 1, 1);
	float3 baseTexCoords = float3(0,0,0);

#if SEAMLESS
	baseTexCoords = i.SeamlessTexCoord.xyz;
#else
	baseTexCoords.xy = i.baseTexCoord.xy;
#endif

	GetBaseTextureAndNormal( BaseTextureSampler, BaseTextureSampler2, BumpmapSampler, BASETEXTURE2, (BUMPMAP || NORMALMAPALPHAENVMAPMASK),
		baseTexCoords, i.vertexColor.rgb, baseColor, baseColor2, vNormal );

#if BUMPMAP == 1	// not ssbump
	vNormal.xyz = vNormal.xyz * 2.0f - 1.0f;					// make signed if we're not ssbump
#endif

	float3 lightmapColor1 = float3( 1.0f, 1.0f, 1.0f );
	float3 lightmapColor2 = float3( 1.0f, 1.0f, 1.0f );
	float3 lightmapColor3 = float3( 1.0f, 1.0f, 1.0f );

// Dead Feature ( Not used by H++ )
// #if LIGHTING_PREVIEW == 0
	#if BUMPMAP && DIFFUSEBUMPMAP
		float2 bumpCoord1;
		float2 bumpCoord2;
		float2 bumpCoord3;
		ComputeBumpedLightmapCoordinates( i.lightmapTexCoord1And2, i.lightmapTexCoord3.xy,
			bumpCoord1, bumpCoord2, bumpCoord3 );
		
		lightmapColor1 = LightMapSample( LightmapSampler, bumpCoord1 );
		lightmapColor2 = LightMapSample( LightmapSampler, bumpCoord2 );
		lightmapColor3 = LightMapSample( LightmapSampler, bumpCoord3 );
	#else
		float2 bumpCoord1 = ComputeLightmapCoordinates( i.lightmapTexCoord1And2, i.lightmapTexCoord3.xy );
		lightmapColor1 = LightMapSample( LightmapSampler, bumpCoord1 );
	#endif
// #endif // LIGHTING_PREVIEW == 0

// Dead Feature:
/*
#if RELIEF_MAPPING
	// in the parallax case, all texcoords must be the same in order to free
    // up an iterator for the tangent space view vector
	float2 detailTexCoord = i.baseTexCoord.xy;
	float2 bumpmapTexCoord = i.baseTexCoord.xy;
	float2 envmapMaskTexCoord = i.baseTexCoord.xy;
#else
*/
	#if DETAILTEXTURE
		float2 detailTexCoord = i.detailOrBumpAndEnvmapMaskTexCoord.xy;
		float2 bumpmapTexCoord = i.baseTexCoord.xy;
	#elif ( BUMPMASK == 1 )
		float2 detailTexCoord = 0.0f;
		float2 bumpmapTexCoord = i.detailOrBumpAndEnvmapMaskTexCoord.xy;
		float2 bumpmap2TexCoord = i.detailOrBumpAndEnvmapMaskTexCoord.wz;
	#else
		float2 detailTexCoord = 0.0f;
		float2 bumpmapTexCoord = i.detailOrBumpAndEnvmapMaskTexCoord.xy;
	#endif

	float2 envmapMaskTexCoord = i.detailOrBumpAndEnvmapMaskTexCoord.wz;
// #endif // !RELIEF_MAPPING

	float4 detailColor = float4( 1.0f, 1.0f, 1.0f, 1.0f );
#if DETAILTEXTURE
	// Dead Shadermodel
/*
	#if SHADER_MODEL_PS_2_0
		detailColor = tex2D( DetailSampler, detailTexCoord );
	#else
*/
		detailColor = float4( g_DetailTint, 1.0f ) * tex2D( DetailSampler, detailTexCoord );
//	#endif
#endif

#if (DISTANCEALPHAMODE != 0)
	float distAlphaMask = baseColor.a;

	#if OUTLINE
		if ( ( distAlphaMask >= OUTLINE_MIN_VALUE0 ) &&
			 ( distAlphaMask <= OUTLINE_MAX_VALUE1 ) )
		{
			float oFactor=1.0;
			if ( distAlphaMask <= OUTLINE_MIN_VALUE1 )
			{
				oFactor=smoothstep( OUTLINE_MIN_VALUE0, OUTLINE_MIN_VALUE1, distAlphaMask );
			}
			else
			{
				oFactor=smoothstep( OUTLINE_MAX_VALUE1, OUTLINE_MAX_VALUE0, distAlphaMask );
			}
			baseColor = lerp( baseColor, OUTLINE_COLOR, oFactor );
		}
	#endif

	#if SOFTEDGES
		baseColor.a *= smoothstep( SOFT_MASK_MAX, SOFT_MASK_MIN, distAlphaMask );
	#else
		baseColor.a *= distAlphaMask >= 0.5;
	#endif
#endif

/*
#if LIGHTING_PREVIEW == 2
	baseColor.xyz=GammaToLinear(baseColor.xyz);
#endif
*/

	float blendedAlpha = baseColor.a;

#if MASKEDBLENDING
	float blendfactor=0.5;
#else
	float blendfactor=i.vertexBlendX_fogFactorW.r;
#endif

#if BASETEXTURE2
	// ShiroDkxtro2:
	// Why $Selfillum == 0 and no height fog?
	// Surfaces below the water still need blending!!!
	// And I fail to see why SelfIllum Surfaces shouldn't be allowed to Blend.
	// This seems more like a method to minimise instruction count than some bug somewhere
	#if (SELFILLUM == 0) && (PIXELFOGTYPE != PIXEL_FOG_TYPE_HEIGHT) && (FANCY_BLENDING)
		float4 modt=tex2D(BlendModulationSampler,i.lightmapTexCoord3.zw);
		#if MASKEDBLENDING
			// FXC is unable to optimize this, despite blendfactor=0.5 above
			//float minb=modt.g-modt.r;
			//float maxb=modt.g+modt.r;
			//blendfactor=smoothstep(minb,maxb,blendfactor);
			blendfactor=modt.g;
		#else
			float minb=saturate(modt.g-modt.r);
			float maxb=saturate(modt.g+modt.r);
			blendfactor=smoothstep(minb,maxb,blendfactor);
		#endif
	#endif
		baseColor.rgb = lerp( baseColor, baseColor2.rgb, blendfactor );
		blendedAlpha = lerp( baseColor.a, baseColor2.a, blendfactor );
#endif

	float3 specularFactor = 1.0f;
	float4 vNormalMask = float4(0, 0, 1, 1);
#if BUMPMAP
	#if BASETEXTURENOENVMAP
		vNormal.a = 0.0f;
	#endif
	
	#if BUMPMAP2
		#if BUMPMASK
			float2 b2TexCoord = bumpmap2TexCoord;
		#else
			float2 b2TexCoord = bumpmapTexCoord;
		#endif
	
		float4 vNormal2;
		/*
		#if (BUMPMAP == 2)
					vNormal2 = tex2D( BumpmapSampler2, b2TexCoord );
		#else
		*/
		vNormal2 = DecompressNormal( BumpmapSampler2, b2TexCoord, NORMAL_DECODE_MODE, AlphaMapSampler2 );		// Bump 2 coords
		// #endif // BUMPMAP == 2
		#if BASETEXTURE2NOENVMAP
			vNormal2.a = 0.0f;
		#endif

		#if BUMPMASK
			float3 vNormal1 = DecompressNormal( BumpmapSampler, i.detailOrBumpAndEnvmapMaskTexCoord.xy, NORMALMASK_DECODE_MODE, AlphaMapSampler );
	
			vNormal.xyz = normalize( vNormal1.xyz + vNormal2.xyz );
	
			// Third normal map...same coords as base
			vNormalMask = DecompressNormal( BumpMaskSampler, i.baseTexCoord.xy, NORMALMASK_DECODE_MODE, AlphaMaskSampler );
	
			vNormal.xyz = lerp( vNormalMask.xyz, vNormal.xyz, vNormalMask.a );		// Mask out normals from vNormal
			specularFactor = vNormalMask.a;
		#else // BUMPMASK == 0
			// && NORMALMAPALPHAENVMAPMASK
			#if FANCY_BLENDING
				vNormal = lerp( vNormal, vNormal2, blendfactor);
			#else
				vNormal.xyz = lerp( vNormal.xyz, vNormal2.xyz, blendfactor);
			#endif
		#endif
	#endif // BUMPMAP2 == 1

		// This doesn't make any sense, just always check for it
		/*
		if( bNormalMapAlphaEnvmapMask )
		{
			specularFactor *= vNormal.a;
		}
#else // !BUMPMAP
	// How the hell does this make sense?
	else if ( bNormalMapAlphaEnvmapMask )
	{
		specularFactor *= vNormal.a;
	}
*/
#endif

	float4 albedo = baseColor;
	float alpha = 1.0f; // Setting this later

#if DETAILTEXTURE
	albedo = TextureCombine( albedo, detailColor, DETAIL_BLEND_MODE, g_DetailBlendFactor );
#endif

	// The vertex color contains the modulation color + vertex color combined
#if !SEAMLESS
	albedo.xyz *= i.vertexColor;
#endif
	alpha *= i.vertexColor.a * g_flAlpha2; // not sure about this one

	// Save this off for single-pass flashlight, since we'll still need the SSBump vector, not a real normal
	float3 vSSBumpVector = vNormal.xyz;

	float3 diffuseLighting;
#if BUMPMAP && DIFFUSEBUMPMAP
	// ssbump
	#if (BUMPMAP == 2)
			diffuseLighting = vNormal.x * lightmapColor1 +
							  vNormal.y * lightmapColor2 +
							  vNormal.z * lightmapColor3;
			diffuseLighting *= g_TintValuesAndLightmapScale.rgb;
	
			// now, calculate vNormal for reflection purposes. if vNormal isn't needed, hopefully
			// the compiler will eliminate these calculations
			vNormal.xyz = normalize( bumpBasis[0]*vNormal.x + bumpBasis[1]*vNormal.y + bumpBasis[2]*vNormal.z);
	#else
			float3 dp;
			dp.x = saturate( dot( vNormal, bumpBasis[0] ) );
			dp.y = saturate( dot( vNormal, bumpBasis[1] ) );
			dp.z = saturate( dot( vNormal, bumpBasis[2] ) );
			dp *= dp;
			
			#if (DETAIL_BLEND_MODE == TCOMBINE_SSBUMP_BUMP)
				dp *= 2*detailColor;
			#endif
			diffuseLighting = dp.x * lightmapColor1 +
							  dp.y * lightmapColor2 +
							  dp.z * lightmapColor3;
			float sum = dot( dp, float3( 1.0f, 1.0f, 1.0f ) );
			diffuseLighting *= g_TintValuesAndLightmapScale.rgb / sum;
	#endif
#else // No Bumpmap
		diffuseLighting = lightmapColor1 * g_TintValuesAndLightmapScale.rgb;
#endif

#if WARPLIGHTING && !SEAMLESS
	float len=0.5*length(diffuseLighting);
	// FIXME: 8-bit lookup textures like this need a "nice filtering" VTF option, which converts
	//        them to 16-bit on load or does filtering in the shader (since most hardware - 360
	//        included - interpolates 8-bit textures at 8-bit precision, which causes banding)
	// ShiroDkxtro2: I assume tex2D was used for older Shadermodels, I changed it to a tex1D
	diffuseLighting *= 2.0*tex1D(WarpLightingSampler, len);
#endif

// No longer necessary :  || LIGHTING_PREVIEW || ( defined( _X360 ) && FLASHLIGHT )
#if CUBEMAP
	float3 worldSpaceNormal = mul( vNormal, i.tangentSpaceTranspose );
#endif

	float3 diffuseComponent = albedo.xyz * diffuseLighting;

/*
#if defined( _X360 ) && FLASHLIGHT

	// ssbump doesn't pass a normal to the flashlight...it computes shadowing a different way
	#if ( BUMPMAP == 2 )
		bool bHasNormal = false;
	
		float3 worldPosToLightVector = g_FlashlightPos - i.worldPos_projPosZ.xyz;
	
		float3 tangentPosToLightVector;
		tangentPosToLightVector.x = dot( worldPosToLightVector, i.tangentSpaceTranspose[0] );
		tangentPosToLightVector.y = dot( worldPosToLightVector, i.tangentSpaceTranspose[1] );
		tangentPosToLightVector.z = dot( worldPosToLightVector, i.tangentSpaceTranspose[2] );
	
		tangentPosToLightVector = normalize( tangentPosToLightVector );
	
		float nDotL = saturate( vSSBumpVector.x*dot( tangentPosToLightVector, bumpBasis[0]) +
								vSSBumpVector.y*dot( tangentPosToLightVector, bumpBasis[1]) +
								vSSBumpVector.z*dot( tangentPosToLightVector, bumpBasis[2]) );
	#else
		bool bHasNormal = true;
		float nDotL = 1.0f;
	#endif

	float fFlashlight = DoFlashlight( g_FlashlightPos, i.worldPos_projPosZ.xyz, i.flashlightSpacePos,
		worldSpaceNormal, g_FlashlightAttenuationFactors.xyz, 
		g_FlashlightAttenuationFactors.w, FlashlightSampler, ShadowDepthSampler,
		RandRotSampler, 0, true, false, i.vProjPos.xy / i.vProjPos.w, false, g_ShadowTweaks, bHasNormal );

	diffuseComponent = albedo.xyz * ( diffuseLighting + ( fFlashlight * nDotL ) );
#endif
*/

#if SELFILLUM
	float3 selfIllumComponent = albedo.xyz;

	#if !USE_FAST_PATH
		selfIllumComponent *= g_SelfIllumTint;
	#endif

	diffuseComponent = lerp( diffuseComponent, selfIllumComponent, baseColor.a );
#elif BASEALPHAENVMAPMASK
	specularFactor = 1.0 - blendedAlpha; // Reversing alpha blows!
#else // !BASEALPHAENVMAPMASK && !SELFILLUM
	// Can only use Alpha for Transparency if not using $BaseAlphaEnvMapMask and $SelfIllum
	alpha = baseColor.a;
#endif

#if NORMALMAPALPHAENVMAPMASK
	specularFactor = vNormal.a;
#elif (!BUMPMAP2 && ENVMAPMASK)
	specularFactor = tex2D(EnvmapMaskSampler, envmapMaskTexCoord).xyz;
#endif

	float3 specularLighting = float3( 0.0f, 0.0f, 0.0f );
#if CUBEMAP
	float3 worldVertToEyeVector = g_EyePos - i.worldPos_projPosZ.xyz;
	float3 reflectVect = CalcReflectionVectorUnnormalized( worldSpaceNormal, worldVertToEyeVector );
	
	// Calc Fresnel factor
	#if !USE_FAST_PATH
		float3 eyeVect = normalize(worldVertToEyeVector);
		float fresnel = 1.0 - dot( worldSpaceNormal, eyeVect );
		fresnel = pow( fresnel, 5.0 );
		fresnel = fresnel * g_OneMinusFresnelReflection + g_FresnelReflection;
	#endif

	#if PARALLAXCORRECT
		//Parallax correction (2_0b and beyond)
		//Adapted from http://seblagarde.wordpress.com/2012/09/29/image-based-lighting-approaches-and-parallax-corrected-cubemap/
		float3 worldPos = i.worldPos_projPosZ.xyz;
		float3 positionLS = mul( float4( worldPos, 1 ), obbMatrix );
		float3 rayLS = mul( reflectVect, (float3x3)obbMatrix );
	
		float3 firstPlaneIntersect = ( float3( 1.0f, 1.0f, 1.0f ) - positionLS ) / rayLS;
		float3 secondPlaneIntersect = ( -positionLS ) / rayLS;
		float3 furthestPlane = max( firstPlaneIntersect, secondPlaneIntersect );
		float distance = min( furthestPlane.x, min( furthestPlane.y, furthestPlane.z ) );
	
		// Use distance in WS directly to recover intersection
		float3 intersectPositionWS = worldPos + reflectVect * distance;
		reflectVect = intersectPositionWS - cubemapPos;
	#endif
	
	specularLighting = ENV_MAP_SCALE * texCUBE( EnvmapSampler, reflectVect );
	specularLighting *= specularFactor;
	
	#if !USE_FAST_PATH
		specularLighting *= g_EnvmapTint;
	#endif

	#if !FANCY_BLENDING
		float3 specularLightingSquared = specularLighting * specularLighting;
		
		// During Fast-Path, no EnvMapSaturation and only full EnvMapContrast
		// Otherwise both
		#if !USE_FAST_PATH
			specularLighting = lerp(specularLighting, specularLightingSquared, g_EnvmapContrast);
			float3 greyScale = dot( specularLighting, float3( 0.299f, 0.587f, 0.114f ) );
			specularLighting = lerp( greyScale, specularLighting, g_EnvmapSaturation );
		#else
			#if FASTPATHENVMAPCONTRAST
					specularLighting = specularLightingSquared;
			#endif
		#endif
	#endif
	
	#if !USE_FAST_PATH
		specularLighting *= fresnel;
	#endif
#endif // CUBEMAP

	float3 result = diffuseComponent + specularLighting;
	
/*
#if LIGHTING_PREVIEW
	worldSpaceNormal = mul( vNormal, i.tangentSpaceTranspose );
#	if LIGHTING_PREVIEW == 1
	float dotprod = 0.7+0.25 * dot( worldSpaceNormal, normalize( float3( 1, 2, -.5 ) ) );
	return FinalOutput( float4( dotprod*albedo.xyz, alpha ), 0, PIXEL_FOG_TYPE_NONE, TONEMAP_SCALE_NONE );
#	else
	LPREVIEW_PS_OUT ret;
	ret.color = float4( albedo.xyz,alpha );
	ret.normal = float4( worldSpaceNormal,alpha );
	ret.position = float4( i.worldPos_projPosZ.xyz, alpha );
	ret.flags = float4( 1, 1, 1, alpha );

	return FinalOutput( ret, 0, PIXEL_FOG_TYPE_NONE, TONEMAP_SCALE_NONE );	
#	endif
#else
*/

	bool bWriteDepthToAlpha = false;

	// ps_2_b and beyond
// #if !(defined(SHADER_MODEL_PS_1_1) || defined(SHADER_MODEL_PS_1_4) || defined(SHADER_MODEL_PS_2_0))
	bWriteDepthToAlpha = ( WRITE_DEPTH_TO_DESTALPHA != 0 ) && ( WRITEWATERFOGTODESTALPHA == 0 );
// #endif

	float fogFactor = CalcPixelFogFactor( PIXELFOGTYPE, g_FogParams, g_EyePos.xyz, i.worldPos_projPosZ.xyz, i.worldPos_projPosZ.w );

#if WRITEWATERFOGTODESTALPHA && (PIXELFOGTYPE == PIXEL_FOG_TYPE_HEIGHT)
	alpha = fogFactor;
#endif

	return FinalOutput( float4( result.rgb, alpha ), fogFactor, PIXELFOGTYPE, TONEMAP_SCALE_LINEAR, bWriteDepthToAlpha, i.worldPos_projPosZ.w );

// #endif // else !LIGHTING PREVIEW
}
 
