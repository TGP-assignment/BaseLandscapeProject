#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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


	gameLive = true;
	downSpeed = 0;

	
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

	Candies = CCArray::createWithCapacity(18);
	Candies->retain();
	Candies->addObject(bean_1);
	Candies->addObject(bean_2);
	Candies->addObject(bean_3);
	Candies->addObject(bean_4);
	Candies->addObject(cane);
	Candies->addObject(corn);
	Candies->addObject(heart_1);
	Candies->addObject(heart_2);
	Candies->addObject(heart_3);
	Candies->addObject(heart_4);
	Candies->addObject(jelly_1);
	Candies->addObject(jelly_2);
	Candies->addObject(jelly_3);
	Candies->addObject(jelly_4);
	Candies->addObject(wrapped_1);
	Candies->addObject(wrapped_2);
	Candies->addObject(wrapped_3);
	Candies->addObject(wrapped_4);
	
	downSpeed = 2;

	this->scheduleUpdate();
	randX = random() % 925 + 35;
    return true;
}
void HelloWorld::update(float delta)
{
	
	auto FallObj = Candies->randomObject();
	Vec2 CurrPos = bean_1->getPosition();
	CurrPos.x = randX;
	CurrPos.y -= downSpeed;
	bean_1->setPosition(CurrPos); 
	if (CurrPos.y < 50)
	{
		randX = random() % 925 + 35;
		bean_1->setPosition(randX, 600);
		
	}

}
