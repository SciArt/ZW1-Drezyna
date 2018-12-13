#include "Wheel.h"
#include "Mesh.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

Wheel::Wheel()
{
}


Wheel::~Wheel()
{
}

void Wheel::generate()
{
	mesh = new RightRegularPrism(0.7f, 1.35f, 64, glm::vec3(1.0f, 0.0f, 0.0f));

	for (WheelSide& wheelSide : sides)
	{
		addChild(&wheelSide);
		wheelSide.generate();
	}

	sides[0].position = glm::vec3(0.0f, -0.112f, 0.0f);
	sides[1].position = glm::vec3(0.0f, 0.7f, 0.0f);

	for (Screw& screw : screws)
	{
		addChild(&screw);
		screw.generate();
	}

	screws[0].position = glm::vec3(0.45f, 0.7f, 0.0f);
	screws[1].position = glm::vec3(-0.45f, 0.7f, 0.0f);
	screws[2].position = glm::vec3(0.0f, 0.7f, 0.45f);
	screws[3].position = glm::vec3(0.0f, 0.7f, -0.45f);

	mesh->init();
}

void Wheel::update(float delta_time, glm::mat4 trans)
{
	Node::update(delta_time, trans);
}