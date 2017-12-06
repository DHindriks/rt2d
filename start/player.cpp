/**
* This class describes MyEntity behavior.
*
* Copyright 2015 Your Name <you@yourhost.com>
*/

#include "player.h"

Player::Player() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->sprite()->color = BLUE;
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up)) {
		this->sprite()->color = RED;
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	else
	{
		this->sprite()->color = BLUE;
	}
	if (input()->getKey(KeyCode::Right)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::Left)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	this->rotation.z = polar.angle;
	velocity / 2;
	this->position += velocity * deltaTime;
	

	if (this->position.x < 0) 
	{
		this->position.x = 0;
		velocity = Vector2(0, velocity.y);
	}
	
	if (this->position.x > SWIDTH) 
	{ 
		this->position.x = SWIDTH;
		velocity = Vector2(0, velocity.y);
	}
	
	if (this->position.y < 0) 
	{
		this->position.y = 0;
		velocity = Vector2(velocity.x, 0);
	}
	
	if (this->position.y > SHEIGHT) 
	{ 
		this->position.y = SHEIGHT;
		velocity = Vector2(velocity.x, 0);
	}

}
