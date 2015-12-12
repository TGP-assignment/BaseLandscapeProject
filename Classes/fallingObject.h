#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


class fallingObject
{
public:

	fallingObject();
	~fallingObject();
	cocos2d::Sprite* currentSpite;
	void initObject(cocos2d::Sprite*);
	void update();
	float randomX;
	float		downSpeed;
	cocos2d::Vec2 currentPosition;
	bool Touched;
	void ObjClicked();
	cocos2d::Rect	SpiteBoundingBox;
};

