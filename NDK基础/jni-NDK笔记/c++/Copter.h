#pragma once

#include "Plane.h"

//普通飞机
class Copter : public Plane{
public:
	virtual void fly();
	virtual void land();
};