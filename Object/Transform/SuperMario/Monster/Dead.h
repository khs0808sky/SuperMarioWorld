#pragma once
class Dead : public Transform
{
private:
	VertexShader* VS;
	PixelShader* PS;
	ColourBuffer* CB;

	vector<Clip*> clips;


public:
	Dead();
	~Dead();

	void Update();
	void Render();

	void SetColor(Float4 color)
	{
		CB->data.colour = color;
	}
};
