#include "fallingObject.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


fallingObject::fallingObject()
{

}


fallingObject::~fallingObject()
{
}

void fallingObject::initObject(cocos2d::Sprite* passedSpite)
{
	currentSpite = passedSpite;
	randomX = rand() % 925 + 35;
	downSpeed = rand() % 3;
	currentPosition = currentSpite->getPosition();
	Touched = false;
	ResetPosition.x = 0;
	ResetPosition.y = 300;

}

void fallingObject::update()
{

	currentPosition.x = randomX;
	currentPosition.y -= downSpeed;
	currentSpite->setPosition(currentPosition);
	if (currentPosition.y < 50)
	{
		currentSpite->setPosition(ResetPosition);
		Touched = true;

	}
	else
	{
		Touched = false;
	}
}

