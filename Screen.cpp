#pragma once
#include "Screen.h"
#include "ScreenManager.h"
#include "Player.h"
#include "Enemy.h"


Screen::Screen()
{
	m_objects = std::vector<std::vector<GameObject*>>();
	for (int i = static_cast<int>(GameObjectType::VOID) + 1; i < static_cast<int>(GameObjectType::MAX); ++i) {
		std::vector<GameObject*> newVector;
		m_objects.push_back(newVector);
	}
}

void Screen::update()
{
	deleteDisposedObjects();
	for (auto& obj : m_toAdd) {
		if (obj->isDisposed()) {
			delete obj;
		}
		else {
			m_objects[obj->getGameObjectType() - 1].push_back(obj);
		}
	}
	m_toAdd.clear();
}

void Screen::onEnter()
{
	//deletedisposedobjects
	for (auto& obj : m_toAdd) {
		m_objects[obj->getGameObjectType() - 1].push_back(obj);
	}
	m_toAdd.clear();
}

void Screen::onExit()
{
	deleteAllObjects();
}

void Screen::addObject(GameObject * obj)
{
	m_toAdd.push_back(obj);
}

void Screen::updateObjects(GameObjectType type)
{
	for (auto obj : m_objects[type - 1]) {
		obj->update();
	}
}

void Screen::deleteDisposedObjects()
{
	for (int i = static_cast<int>(GameObjectType::VOID) + 1; i < static_cast<int>(GameObjectType::MAX); ++i){
		for (std::vector<GameObject*>::iterator it = m_objects[i-1].begin(); it != m_objects[i-1].end(); ) {
			if ((*it)->isDisposed()) {
				delete(*it);
				it = m_objects[i-1].erase(it);
			}
			else {
				++it;
			}
		}
	}
}

void Screen::deleteAllObjects()
{
	for (int i = static_cast<int>(GameObjectType::VOID) + 1 ; i < static_cast<int>(GameObjectType::MAX); ++i) {
		deleteObjects(GameObjectType(i - 1));
	}
}

void Screen::deleteObjects(GameObjectType type)
{
	for (std::vector<GameObject*>::iterator it = m_objects[type].begin(); it != m_objects[type].end(); ) {
		delete(*it);
		it = m_objects[type].erase(it);
	}
}

void Screen::setScreenManager(ScreenManager * screenManager)
{
	m_screenManager = screenManager;
}

void Screen::setNextScreen(Screen * nextScreen, bool backup)
{
	if (nextScreen == this) return;
	m_screenManager->setNextScreen(nextScreen, backup);
}

std::vector<std::vector<GameObject*>>* Screen::getObjects()
{
	return &m_objects;
}

std::vector<GameObject*>* Screen::getObjectsByType(GameObjectType type)
{
	return &(m_objects[type - 1]);
}


Screen::~Screen()
{
}
