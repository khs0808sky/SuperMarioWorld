#pragma once
class GroundBackground : public Transform
{
public:
	enum class BACKGROUND_TYPE
	{
		UP, DOWN
	} background_type;

private:

	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;

public:
	GroundBackground(BACKGROUND_TYPE type);
	~GroundBackground();

	void Update();
	void Render();

	ColourBuffer* GetColourBuffer()
	{
		return CB;
	}

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}
};
