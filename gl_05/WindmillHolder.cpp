#include "WindmillHolder.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace engine;

WindmillHolder::WindmillHolder()
{
}

WindmillHolder::~WindmillHolder()
{
}

void WindmillHolder::generate()
{
	mesh = new RightRegularPrism(0.72f, 0.2f, 64, glm::vec3(0.325f, 1.0f, 0.63f));

	for (Vane& v : vanes)
	{
		addChild(&v);
		v.generate();
	}

	generateVanes();

	mesh->init();
}

void WindmillHolder::update(float delta_time, glm::mat4 trans)
{
	this->rotation.z = 90.0f;
	Node::update(delta_time, trans);
}

void WindmillHolder::generateVanes()
{
	for (int i=0; i<5; i++)
		vanes.push_back(Vane());

	glm::mat4 rotation(1.0f);
	rotation = glm::rotate(rotation, glm::radians(360.0f / 5.0f), glm::vec3(0, 1, 0));

	vanes[0].position = glm::vec3(0.72f, 0.6f, -0.06f);
	glm::vec4 temp = glm::vec4(vanes[0].position, 1.0f);

	for (int i=1; i<5; i++)
	{
		temp = temp * rotation;
		vanes[i].position = glm::vec3(temp);
		vanes[i].rotation.y = -72.0f * i;
	}

	for (int i=0; i<5; i++)
	{
		addChild(&vanes[i]);
		vanes[i].generate();
	}
}