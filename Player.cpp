#include "Player.h"
#include <math.h>
#include "LevelScreen.h"
#include "Projectile.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "PowerUp.h"

Player::Player()
{
	m_inputController = InputController::getInstance();

	setTexture("Sprite/PNG/playerShip1_blue.png");
	for (int i = 0; i < 3; ++i) {
		m_damageTexture[i].loadFromFile("Sprite/PNG/Damage/playerShip1_damage" + std::to_string(i+1) + ".png");
	}

	setPosition(200, 200);
	setSize(getTexture()->getWidth(), getTexture()->getHeight());
	setRadius(45);
	setRotation(0);
	setMaxVelocity(5);
	setMaxAcceleration(0.5);
	setAcceleration(0);
	setDirection(0, -1);
	setGameObjectType(GameObjectType::_Player);
	setLife(100);

	//cooldowns
	m_timers.push_back(&m_fireCooldownTimer);
	m_timers.push_back(&m_invulnerableTimer);
	m_timers.push_back(&m_firePowerUpTimer);

	m_firePowerUpCooldown = 6000;
	m_fireCooldown = 200;
	m_invulnerableCooldown = 2000;

	startTimers();

	HealthBar * healthBar = new HealthBar();
	setHealthBar(healthBar);
	healthBar->setCurrentHP(m_life);
	healthBar->setmaxHP(m_life);
}

void Player::update()
{
	updateTimers();
	handleInput();
	fireProjectile();
	Point oldPosition = getPosition();
	MovableGameObject::update();
	AnimatedGameObject::update();

	checkCollision(oldPosition);
}

void Player::render()
{
	MovableGameObject::render();
	for (int i = 0; i < 3; ++i) {
		if (getLife() >= (2 - i) * 25 && getLife() < (3 - i) * 25) {
			m_damageTexture[i].setAlpha(getAlpha());
			m_damageTexture[i].render(getPosition().x - getSize().x / 2, getPosition().y - getSize().y / 2, nullptr, getAngle());
		}
	}
}

void Player::handleInput()
{
	if (m_inputController->isKeyActive(Key::Move_Forward)) {
		setVelocity(getDirection().x * 5, getDirection().y * 5);
	}

	if (m_inputController->isKeyActive(Key::Move_Backward)) {
		setVelocity(-getDirection().x * 5, -getDirection().y * 5);
	}

	if (m_inputController->isKeyActive(Key::Rotate_Left)) {
		rotate(-3);
		rotateDirection(-3);
	}
	if (m_inputController->isKeyActive(Key::Rotate_Right)) {
		rotate(3);
		rotateDirection(3);
	}
	if (m_inputController->isKeyActive(Key::Fire)) {

	}
}

void Player::checkCollision(Point oldPosition)
{
	if (getPosition().x < 0 || getPosition().y < 0 || getPosition().x > LWindow::SCREEN_WIDTH || getPosition().y > LWindow::SCREEN_HEIGHT) {
		setPosition(oldPosition);
		setVelocity(0, 0);
		setAcceleration(0);
	}

	GameObject* obj;
	if ((obj = checkCollisionByType(GameObjectType::_Enemy)) && !isInvulnerable()) {
		Enemy * _obj = dynamic_cast<Enemy*>(obj);
		_obj->setDead();
		addDamage(_obj->getDamage());
		setPosition(oldPosition);
		setVelocity(0, 0);
		setAcceleration(0);
	}

	if ((obj = checkCollisionByType(GameObjectType::_PowerUp)) ) {
		PowerUp * _obj = dynamic_cast<PowerUp*>(obj);
		_obj->onPickUp(this);
	}
}

void Player::fireProjectile()
{
	if (m_fireCooldownTimer.getTicks() > m_fireCooldown || (m_firePowerUpBool && (m_fireCooldownTimer.getTicks() > m_fireCooldown / 2) ) ) {
		Projectile * projectile = new Projectile(getPosition() + getDirection() * 50, getDirection(), getRotation(), 1 + 1 * (int)m_firePowerUpBool);
		projectile->setScreen(getScreen());
		m_screen->addObject(projectile);

		m_fireCooldownTimer.restart();
	}
}

void Player::startTimers()
{
	m_fireCooldownTimer.start();
}

void Player::pauseTimers()
{
	for (int i = 0; i < m_timers.size(); ++i) {
		m_timers[i]->pause();
	}
}

void Player::updateTimers()
{
	if (m_firePowerUpTimer.getTicks() > m_firePowerUpCooldown) {
		m_firePowerUpBool = false;
		m_firePowerUpTimer.stop();
	}

	isInvulnerable();
}

void Player::addDamage(int damage)
{
	if (!isInvulnerable()) {
		m_life -= damage;
		if (m_life <= 0) {
			dynamic_cast<LevelScreen *>(getScreen())->setGameOver(true);
		}
		setInvulnerable();
	}

	m_healthBar->setCurrentHP(m_life);
}

void Player::setLife(int life)
{
	m_life = life;
}

int Player::getLife()
{
	return m_life;
}

void Player::addLife(int life)
{
	m_life += life;

	if (m_life > 100) {
		m_life = 100;
	}
	m_healthBar->setCurrentHP(m_life);
}

void Player::setScreen(Screen * screen)
{
	GameObject::setScreen(screen);
	
	screen->addObject(m_healthBar);
}

void Player::setInvulnerable()
{
	m_invulnerableTimer.start();
	startBlinking();
}

bool Player::getInvulnerable()
{
	return isInvulnerable();
}

bool Player::isInvulnerable()
{
	if (m_invulnerableTimer.getTicks() >= m_invulnerableCooldown || !m_invulnerableTimer.isStarted()) {
		m_invulnerableTimer.stop();
		stopBlinking();
		
		return false;
	}
	
	return true;
}

void Player::setHealthBar(HealthBar * healthBar)
{
	m_healthBar = healthBar;
}

void Player::powerUpAttack()
{
	m_firePowerUpTimer.restart();
	m_firePowerUpBool = true;
}

Player::~Player()
{
}
