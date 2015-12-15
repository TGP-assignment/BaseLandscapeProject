#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "fallingObject.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	
	bean_1 = (Sprite*)rootNode->getChildByName("bean_1");
	bean_2 = (Sprite*)rootNode->getChildByName("bean_2");
	bean_3 = (Sprite*)rootNode->getChildByName("bean_3");
	bean_4 = (Sprite*)rootNode->getChildByName("bean_4");
	cane = (Sprite*)rootNode->getChildByName("cane");
	corn = (Sprite*)rootNode->getChildByName("corn");
	heart_1 = (Sprite*)rootNode->getChildByName("heart_1");
	heart_2 = (Sprite*)rootNode->getChildByName("heart_2");
	heart_3 = (Sprite*)rootNode->getChildByName("heart_3");
	heart_4 = (Sprite*)rootNode->getChildByName("heart_4");
	jelly_1 = (Sprite*)rootNode->getChildByName("jelly_1");
	jelly_2 = (Sprite*)rootNode->getChildByName("jelly_2");
	jelly_3 = (Sprite*)rootNode->getChildByName("jelly_3");
	jelly_4 = (Sprite*)rootNode->getChildByName("jelly_4");
	wrapped_1 = (Sprite*)rootNode->getChildByName("wrapped_1");
	wrapped_2 = (Sprite*)rootNode->getChildByName("wrapped_2");
	wrapped_3 = (Sprite*)rootNode->getChildByName("wrapped_3");
	wrapped_4 = (Sprite*)rootNode->getChildByName("wrapped_4");
	Life_1 = (Sprite*)rootNode->getChildByName("Life_1");
	Life_2 = (Sprite*)rootNode->getChildByName("Life_2");
	Life_3 = (Sprite*)rootNode->getChildByName("Life_3");
	Lives = 3;

	//-----------------------------------------------------------------------------------------
	//TOUCHES
	//Set up a touch listener.
	auto touchListener = EventListenerTouchOneByOne::create();

	//Set callbacks for our touch functions.
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	//Add our touch listener to event listener list.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	//-----------------------------------------------------------------------------------------

	currentSprite = bean_1;
	currentSprite = randomSprite();
	Object1 = new fallingObject();
	Object1->initObject(currentSprite);
	currentSprite = randomSprite();
	Object2 = new fallingObject();
	Object2->initObject(currentSprite);
	currentSprite = randomSprite();
	Object3 = new fallingObject();
	Object3->initObject(currentSprite);
	currentSprite = randomSprite();
	Object4 = new fallingObject();
	Object4->initObject(currentSprite);

	this->scheduleUpdate();
    return true;

}
void HelloWorld::update(float delta)
{
	Object1->update();
	Object2->update();
	Object3->update();
	Object4->update();

	if(Object1->Touched)
	{
		Object1->Touched = false;
		LooseLife();
	}
	if (Object2->Touched)
	{
		Object2->Touched = false;
		LooseLife();
	}
	if (Object3->Touched)
	{
		Object3->Touched = false;
		LooseLife();
	}
	if (Object4->Touched)
	{
		Object4->Touched = false;
		LooseLife();
	}

}
cocos2d::Sprite* HelloWorld::randomSprite()
{
	int RandS = 0;
	RandS = random() % 18;
	if (RandS == 0)
	{
		return bean_1;
	}
	if (RandS == 1)
	{
		return bean_2;
	}
	if (RandS == 2)
	{
		return bean_3;
	}
	if (RandS == 3)
	{
		return bean_4;
	}
	if (RandS == 4)
	{
		return cane;
	}
	if (RandS ==5)
	{
		return corn;
	}
	if (RandS == 6)
	{
		return heart_1;
	}
	if (RandS == 7)
	{
		return heart_2;
	}
	if (RandS == 8)
	{
		return heart_3;
	}
	if (RandS == 9)
	{
		return heart_4;
	}
	if (RandS == 10)
	{
		return jelly_1;
	}
	if (RandS == 11)
	{
		return jelly_2;
	}
	if (RandS == 12)
	{
		return jelly_3;
	}
	if (RandS == 13)
	{
		return jelly_4;
	}
	if (RandS == 14)
	{
		return wrapped_1;
	}
	if (RandS == 15)
	{
		return wrapped_2;
	}
	if (RandS == 16)
	{
		return wrapped_3;
	}
	if (RandS == 17)
	{
		return wrapped_4;
	}
	else
	{
		return bean_1;
	}


}
void HelloWorld::LooseLife()
{

		Lives--;
		if (Lives == 2)
		{
			Life_1->setPosition(-100, -100);

		}
		if (Lives == 1)
		{
			Life_2->setPosition(-100, -100);

		}
		if (Lives == 0)
		{
			Life_3->setPosition(-100, -100);
			//Call end screen
			//ExitProcess(0); // remove once we have end screen

		}
		
}


bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	cocos2d::log("touch began");

	TouchRect = touch->getLocation();

	if (Object1->currentSpite->boundingBox().containsPoint(TouchRect))
	{
		cocos2d::log("clicked");
		Object1->ObjClicked();
		//score +1
		currentSprite = randomSprite();
		Object1->currentSpite = currentSprite;
		
	}

	if (Object2->currentSpite->boundingBox().containsPoint(TouchRect))
	{
		cocos2d::log("clicked");
		Object2->ObjClicked();

		currentSprite = randomSprite();
		Object2->currentSpite = currentSprite;
	}
	if (Object3->currentSpite->boundingBox().containsPoint(TouchRect))
	{
		cocos2d::log("clicked");
		Object3->ObjClicked();

		currentSprite = randomSprite();
		Object3->currentSpite = currentSprite;
	}
	if (Object4->currentSpite->boundingBox().containsPoint(TouchRect))
	{
		cocos2d::log("clicked");
		Object4->ObjClicked();

		currentSprite = randomSprite();
		Object4->currentSpite = currentSprite;
	}

	return true;

}

//-------------------------------------------------------------------------

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{

	cocos2d::log("touch ended");
}

//-------------------------------------------------------------------------

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("touch moved");
}

//-------------------------------------------------------------------------

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}
