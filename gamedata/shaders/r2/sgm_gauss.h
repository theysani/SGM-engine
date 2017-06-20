#ifndef SGM_GAUSS_H_INCLUDED
#define SGM_GAUSS_H_INCLUDED

float4 gauss(sampler2D input, float2 texcoord, int factor, bool performance)
{
	float4 out_color = float4(0,0,0,0);
	if (!performance)
	{
		float dx = factor * .5f/1024.f;
		float dy = factor * .5f/768.f;
		
		out_color = 
		(
		1.f * tex2Dlod(input,float4(texcoord,0,0)) +
		1.f * tex2Dlod(input,float4(texcoord+float2(dx,0),0,0)) +
		1.f * tex2Dlod(input,float4(texcoord+float2(dy,0),0,0)) +
		1.f * tex2Dlod(input,float4(texcoord+float2(-dx,0),0,0)) +
		1.f * tex2Dlod(input,float4(texcoord+float2(-dx,-dy),0,0)) +
		1.f * tex2Dlod(input,float4(texcoord+float2(dx,-dy),0,0))
		)/6.f;
	}
	else
	{
		const float delta = factor * (.5f/1024.f);
		
		out_color = 
		(
		tex2Dlod(input,float4(texcoord+delta,0,0)) +
		tex2Dlod(input,float4(texcoord-delta,0,0))
		)*(1.f/2.f);
	}
	
	return out_color;
}

#endif//SGM_GAUSS_H_INCLUDED