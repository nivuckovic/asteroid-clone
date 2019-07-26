#pragma once
#include <vector>
#include "GameObject.h"
#include "MovableGameObject.h"
#include "GameObjectType.h"

class ScreenManager;

class Screen
{
public:
	Screen();

	virtual void update();
	virtual void render() = 0;

	virtual void onEnter();
	void onExit();

	void addObject(GameObject* obj);
	void updateObjects(GameObjectType type);
	void deleteDisposedObjects();

	void deleteAllObjects();
	void deleteObjects(GameObjectType type);

	void setScreenManager(ScreenManager* screenManager);
	void setNextScreen(Screen* nextScreen, bool backup);

	std::vector<std::vector<GameObject*>>* getObjects();
	std::vector<GameObject*>* getObjectsByType(GameObjectType type);

	~Screen();

protected:
	ScreenManager * m_screenManager;

private:
	std::vector<std::vector<GameObject*>> m_objects;

	std::vector<GameObject*> m_toAdd;
};
