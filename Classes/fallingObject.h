#include "HelloWorldScene.h"
#include "cocos2d.h"


class fallingObject
{
public:

	fallingObject();
	~fallingObject();
	cocos2d::Sprite* currentSpite;
	void initObject(cocos2d::Sprite*);
	void update();
	float randomX;
	int		downSpeed;
	cocos2d::Vec2 currentPosition;
	int currentX;
	int currentY;
	bool Touched;
};

