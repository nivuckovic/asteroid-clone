#include "Enemy.h"

#include <math.h>
#include "tinyxml2\tinyxml2.h"

Enemy::Enemy(Spawner * spawner, int m_type)
{
	setSpawner(spawner);
	getConfig(m_type);

	float radius = randomFloat(0, 100);
	float angle = randomFloat(0, 2 * M_PI);
	Point center(LWindow::SCREEN_WIDTH / 2 + radius + cos(angle), LWindow::SCREEN_HEIGHT / 2 + radius + sin(angle));
	setDirection(center.x - getPosition().x, center.y - getPosition().y);
}

void Enemy::update()
{
	MovableGameObject::update();
	checkCollision();
}

void Enemy::render()
{
	MovableGameObject::render();
	
}

void Enemy::checkCollision()
{
	Point position = getPosition();
	if (position.x < - 400 || position.y < - 400 || position.x > LWindow::SCREEN_WIDTH + 400 || position.y > LWindow::SCREEN_HEIGHT + 400) {
		setDisposed();
	}
}

void Enemy::setLife(int life)
{
	m_life = life;
}

void Enemy::addDamage(int damage)
{
	m_life -= damage;

	if (m_life <= 0) {
		setDead();
	}
}

void Enemy::setDamage(int damage)
{
	m_damage = damage;
}

int Enemy::getDamage()
{
	return m_damage;
}

void Enemy::split()
{
	if (m_type != 2) {
		m_spawner->splitEnemy(m_type + 1, getPosition(), getDirection());
		for (int i = 0; i < 2 - m_type; ++i) {
			m_spawner->splitEnemy(m_type + 1, getPosition(), rotateVector(getDirection(), randomFloat(0, 2 * M_PI)));
		}
	}
}

void Enemy::startTimers()
{
}

void Enemy::pauseTimers()
{
}

void Enemy::setSpawner(Spawner * spawner)
{
	m_spawner = spawner;
}


void Enemy::setDead()
{
	split();
	setDisposed();
}

Enemy::~Enemy()
{

}

void Enemy::getConfig(int type)
{
	int typeCount = 3;
	if (type == 0) {
		m_type = rand() % typeCount;
	}
	else {
		m_type = type % typeCount;
	}

	//ovo kasnije pretvoriti u neku klasu loader
	tinyxml2::XMLDocument xmlDoc;
	std::string fileName = "enemyConfig.xml";
	tinyxml2::XMLError result = xmlDoc.LoadFile(fileName.c_str());
	
	if (result != tinyxml2::XML_SUCCESS) {
		printf("Nemogu otvoriti XML\n");
	}

	tinyxml2::XMLElement* property = xmlDoc.FirstChildElement( ("enemy" + std::to_string(m_type)).c_str() )->FirstChildElement("properties")->FirstChildElement("property");
	
	std::string texturePath = property->Attribute("path");
	
	int count; 
	property->QueryIntAttribute("count", &count);

	setTexture(texturePath + std::to_string(rand() % count + 1) + ".png");
	
	setSize(getTexture()->getWidth(), getTexture()->getHeight());
	
	float radius;
	property->QueryFloatAttribute("radius", &radius);
	setRadius(radius);

	setGameObjectType(GameObjectType::_Enemy);

	int life;
	property->QueryIntAttribute("life", &life);
	setLife(life);

	int deltaVelocity;
	float baseVelocity;
	property->QueryFloatAttribute("basespeed", &baseVelocity);
	property->QueryIntAttribute("deltaspeed", &deltaVelocity);
	setMaxVelocity(baseVelocity + rand() % deltaVelocity);

	float acceleration;
	property->QueryFloatAttribute("acceleration", &acceleration);
	setAcceleration(acceleration);

	int damage;
	property->QueryIntAttribute("damage", &damage);
	setDamage(damage);

	Point center = { (float)LWindow::SCREEN_WIDTH / 2, (float)LWindow::SCREEN_HEIGHT / 2 };
	setSpawnPosition(center, std::fmax(LWindow::SCREEN_HEIGHT, LWindow::SCREEN_WIDTH));
}

void Enemy::setSpawnPosition(Point center, float radius)
{
	int numberOfPoints = 15;
	float arcAngle = 2 * M_PI / numberOfPoints;
	float angle = arcAngle * (rand() % numberOfPoints);
	setPosition(center.x + radius * cos(angle), center.y / 2 + radius * sin(angle));
}
