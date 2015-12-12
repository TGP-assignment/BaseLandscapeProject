#include "fallingObject.h"
#include <CCNode.h>

using namespace cocos2d;

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
	downSpeed = rand() % 3 + 1;
	currentPosition = currentSpite->getPosition();
	Touched = false;
	currentPosition.x = randomX;
	SpiteBoundingBox = currentSpite->getBoundingBox;



}

void fallingObject::update()
{

	currentPosition.y -= downSpeed;
	currentSpite->setPosition(currentPosition);

	if (currentPosition.y <= 30)
	{
		currentPosition.x = rand() % 925 + 35;
		currentPosition.y = 700;
		Touched = true;
		downSpeed = rand() % 3 + 1;

	}
	else
	{
		Touched = false;
	}
}

void fallingObject::ObjClicked()
{
	SpiteBoundingBox.size = currentSpite->getBoundingBox().size;
	SpiteBoundingBox.origin = convertToWorldSpaceAR(currentSpite->getBoundingBox.orgin);
	currentPosition.x = rand() % 925 + 35;
	currentPosition.y = 700;
	downSpeed = rand() % 3 + 1;
	currentSpite->setPosition(currentPosition);
}


