#include "Background.h"

Background::Background(std::string path)
{
	setGameObjectType(GameObjectType::_Background);
	setTexture(path);
}

void Background::update()
{
}

void Background::drawDebugBox()
{
}

Background::~Background()
{
}
