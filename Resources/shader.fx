struct VertexInput
{
	float4 Position   : POSITION;
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

	output.Position = input.Position;
	output.Color = input.Color;
	
	return output;
}

float4 PixelMain(VertexOutput input) : COLOR0	
{
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