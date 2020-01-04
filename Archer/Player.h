#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Player : public Drawable
{
public:
	Player(float t_X, float t_Y);
	Player() = delete;
	~Player() = default;

	void update();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

private:
	Sprite player;
	Texture texture;
	float playerSizeX{ 80.0f };
	float playerSizeY{ 20.0f };
	float playerVelocity{ 5.0f };
	Vector2f velocity{ 0.0,0.0 };
	void draw(RenderTarget& target, RenderStates state)const override;

};

