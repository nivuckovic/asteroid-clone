#include "Projectile.h"

#include "Enemy.h"

Projectile::Projectile(Point position, Point direction, float rotation, int damage)
{
	//uzasno handlanje stvari al sam preljen
	m_damage = damage;
	if (m_damage == 1) {
		setTexture("Sprite/PNG/Lasers/laserBlue06.png");
	}
	else {
		setTexture("Sprite/PNG/Lasers/laserGreen12.png");
	}

	setPosition(position);
	setSize(getTexture()->getWidth(), getTexture()->getHeight());
	setRadius(5);
	setRotation(rotation);
	setDirection(direction);
	setGameObjectType(GameObjectType::_Projectile);
	setMaxVelocity(8);
	setAcceleration(30);

}

void Projectile::update()
{
	MovableGameObject::update();

	checkCollision();
}

void Projectile::render()
{
	MovableGameObject::render();
}

void Projectile::checkCollision()
{
	Point position = getPosition();
	if (position.x < -100 || position.y < -100 || position.x > LWindow::SCREEN_WIDTH + 100 || position.y > LWindow::SCREEN_HEIGHT + 100) {
		setDisposed();
	}

	GameObject * obj = nullptr;
	if (obj = checkCollisionByType(GameObjectType::_Enemy)) {
		Enemy * enemy = dynamic_cast<Enemy *>(obj);
		enemy->addDamage(m_damage);
		setDisposed();
	}
}

void Projectile::startTimers()
{
}

void Projectile::pauseTimers()
{
}

Projectile::~Projectile()
{
}
