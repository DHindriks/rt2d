/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/spaceship.tga");
	this->sprite()->color = BLUE;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{

}
