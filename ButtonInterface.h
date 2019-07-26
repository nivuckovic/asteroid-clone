#pragma once
#include "GameObject.h"

class ButtonInterface : public virtual GameObject
{
public:
	ButtonInterface();

	virtual void click() = 0;

	~ButtonInterface();

protected:

};

