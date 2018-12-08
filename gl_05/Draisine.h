#pragma once

#include "Node.h"
#include "RightRegularPrism.h"
#include "Wheel.h"

class Draisine : public engine::Node
{
public:
	Draisine();
	~Draisine();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
private:
	Wheel wheels[4];
};