#include "Player.h"

Player::Player(float t_X, float t_Y)
{
	texture.loadFromFile("stickman.png");
	player.setPosition(t_X, t_Y);
	player.setTexture(texture);
	player.setScale(0.1f,0.1f);
	player.setOrigin(this->playerSizeX / 2, this->playerSizeY / 2);
}

void Player::draw(RenderTarget& target, RenderStates state)const
{
	target.draw(this->player, state);
}

void Player::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)&& this->left() > 0)
	{
		velocity.x = -playerVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right)&&this->right()<600)
	{
		velocity.x = playerVelocity;
	}
	else if(Keyboard::isKeyPressed(Keyboard::Key::Up)&&this->top()>0)
	{
		velocity.y = -playerVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down)&&this->bottom()<800)
	{
		velocity.y = playerVelocity;
	}
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	player.move(this->velocity);
}

float Player::left()
{
	return this->player.getPosition().x - playerSizeX / 2;
}
float Player::right()
{
	return this->player.getPosition().x + playerSizeX / 2;
}
float Player::top()
{
	return this->player.getPosition().y - playerSizeY / 2;
}
float Player::bottom()
{
	return this->player.getPosition().y + playerSizeY / 2;
}

void Player::moveLeft()
{
	this->velocity.x = -playerVelocity;
}
void Player::moveRight()
{
	this->velocity.x = playerVelocity;
}
void Player::moveUp()
{
	this->velocity.y = -playerVelocity;
}
void Player::moveDown()
{
	this->velocity.y = playerVelocity;
}
Vector2f Player::getPosition()
{
	return this->player.getPosition();
}
