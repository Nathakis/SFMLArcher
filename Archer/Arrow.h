#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Arrow : public Drawable
{
public:
	Arrow(float t_X, float t_Y);
	Arrow() = delete;
	~Arrow() = default;

	void update();
	void destroy();
	
	Vector2f getPosition();
	
	float right();
	bool isDestroyed();

private:
	Sprite arrow;
	Texture texture;
	float arrowSizeX{ 20.0f };
	float arrowSizeY{ 5.0f };
	float arrowVelocity{ 2.0f };
	Vector2f velocity{ arrowVelocity,0 };
	void draw(RenderTarget & target, RenderStates state)const override;
	bool isDestroy = false;
};

