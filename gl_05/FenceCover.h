#pragma once
#include "Node.h"
#include "Cylinder.h"
#include "Light.h"

class FenceCover : public engine::Node
{
public:
	FenceCover();
	~FenceCover();

	void generate();
	virtual void update(float delta_time, glm::mat4 trans);
private:
	engine::Light light;
};
