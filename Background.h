#pragma once
#include "AnimatedGameObject.h"
#include <string>

class Background :
	public AnimatedGameObject
{
public:
	Background(std::string path);

	void update() override;
	
	void drawDebugBox() override;

	~Background();
};

