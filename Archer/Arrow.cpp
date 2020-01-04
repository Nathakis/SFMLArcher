#include "Arrow.h"

Arrow::Arrow(float t_X, float t_Y)
{
	texture.loadFromFile("arrow.png");
	arrow.setPosition(t_X, t_Y);
	arrow.setTexture(texture);
	arrow.setScale(0.3f, 0.1f);
	arrow.setOrigin(this->arrowSizeX / 2, this->arrowSizeY / 2);
}

void Arrow::draw(RenderTarget& target, RenderStates state)const
{
	target.draw(this->arrow, state);
}

void Arrow::update()
{
	arrow.move(this->velocity);
}

float Arrow::right()
{
	return this->arrow.getPosition().x + arrowSizeX / 2;
}

Vector2f Arrow::getPosition()
{
	return this->arrow.getPosition();
}

void Arrow::destroy()
{
	this->isDestroy = true;
}

bool Arrow::isDestroyed()
{
	return this->isDestroy;
}
