#ifndef SGM_COMMON_H_INCLUDED
#define SGM_COMMON_H_INCLUDED

#include "sgm_shaders_config.h"//sgm configuration file

//////////////////////////////////////////////////////////////////////////////////////////
//structs
struct		combine_aa		{//combine anti-aliasing struct
	float2		tc0		:		TEXCOORD0;
	float2		tc1		:		TEXCOORD1;
	float2		tc2		:		TEXCOORD2;
	float2		tc3		:		TEXCOORD3;
	float2		tc4		:		TEXCOORD4;
	float4		tc5		:		TEXCOORD5;
	float4		tc6		:		TEXCOORD6;
};

struct		clear_position_out		{
	float4		position		:		COLOR0;
	float4		normal		:		COLOR1;
};

//////////////////////////////////////////////////////////////////////////////////////////
//defines
	#define		cFARPLANE		float(100)//COP standart
	
//////////////////////////////////////////////////////////////////////////////////////////	
//uniforms
	uniform		float2			sunshafts_params0;//x-radius,y-length
	uniform		float2			sunshafts_params1;//x-weather control,y-debug intensity
	uniform 	float2 			rain_drops_params0;//x-weather control,y-debug intensity
	uniform		float4			screen_params0;//x-RDEVICE.dwWidth,y-RDEVICE.dwHeigh,z-1.f/x,w-1.f/y
	
//////////////////////////////////////////////////////////////////////////////////////////	
//samplers
	uniform		sampler2D		s_sunshafts0;//sunshafts occlusion mask
	uniform		sampler2D		s_sunshafts1;//mask blurring
	uniform		sampler2D		s_sunshafts2;//calculate sunshafts
	uniform		sampler2D		s_rain_drops0;//rain drops du/dv map
	
//////////////////////////////////////////////////////////////////////////////////////////
//functions
float4	convert_to_screen_space(float4 projective)
{//convert projective to screen space function
	float4 screen;
	screen.x = (projective.x + projective.w)*0.5;
	screen.y = (projective.w - projective.y)*0.5;
	screen.z = projective.z;
	screen.w = projective.w;
	return screen;
}

float	normalize_depth(float depth)
{//normalize depth function
	return saturate(depth/cFARPLANE);
}	

#endif//SGM_COMMON_H_INCLUDED