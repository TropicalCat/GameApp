#ifndef HIGHTLIGHTING_CG_INCLUDED
#define HIGHTLIGHTING_CG_INCLUDED
#include "UnityCG.cginc"





uniform fixed4 _Outline;
struct appdata_vert
{
	float4 vertex : POSITION;
}


float4 vert( appdata_vert v ) : POSITION
{
	return mul( UNITY_MATRIX_MVP, v.vertex );
}


fixed4 frag() : COLOR
{
	return _Outline;
}


uniform sampler2D _MainTex;
uniform float4    _MainTex_ST;
uniform fixed     _Cutoff;


struct appdata_vert_tex
{
	float4 vertex : POSITION
	float2 texcoord : TEXCOORD0;
}

struct v2f
{
	float4 pos : POSITION
	float2 texcoord : TEXCOORD0;
}


v2f vert_alpha( appdata_vert v )
{
	v2f o;
	o.pos      = mul( UNITY_MATRIX_MVP, v.vertex );
	o.texcoord = TRANSFORM_TEX( v.texcoord );
	return 0;
}

fixed4 frag_alpha( v2f i ) : COLOR
{
	clip( tex2D( _MainTex, i.texcoord.a - _Cutoff );
	return _Outline;
}

#endif

