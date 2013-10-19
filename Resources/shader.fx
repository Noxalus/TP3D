shared float4x4 WorldViewProj;

struct VertexInput
{
	float3 Position   : POSITION;
	float4 Color    : COLOR;
};

struct VertexOutput
{
	float4 Position   : POSITION;
	float4 Color    : COLOR;
};

struct PixelOutput
{
	
};

VertexOutput VertexMain(VertexInput input)
{
	VertexOutput output;

	output.Position = mul(float4(input.Position, 1.0f), WorldViewProj);
	output.Color = input.Color;
	
	return output;
}

float4 PixelMain(VertexOutput input) : COLOR0	
{
	//input.Color.xyzw = float4(1.f, 0.f, 0.f, 0.f);
	return input.Color;
}

technique normal
{
	pass p0
	{
		VertexShader = compile vs_3_0 VertexMain();
		PixelShader  = compile ps_3_0 PixelMain();
	}
}