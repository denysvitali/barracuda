#include <glm/vec4.hpp>
#include <GL/glew.h>
#include "Material.h"
#include "../program/Program.h"

using namespace tunage;

Material::~Material() {
}

void Material::render() {
	//	Render texture
	if (texture != nullptr) {
		texture->render();
	} else {
		//TODO: blank texture render
	}

	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,
	//			 glm::value_ptr(glm::vec4(ambient, alpha)));
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,
	//			 glm::value_ptr(glm::vec4(diffuse, alpha)));
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,
	//			 glm::value_ptr(glm::vec4(specular, alpha)));
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,
	//			 glm::value_ptr(glm::vec4(emission, alpha)));
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,
	//			shininess);

	Program::getCurrent()->setMaterial(this);
}

void Material::setAmbient(glm::vec3 light) {
	ambient = glm::vec3(light[0], light[1], light[2]);
}

void Material::setDiffuse(glm::vec3 light) {
	diffuse = glm::vec3(light[0], light[1], light[2]);
}

void Material::setSpecular(glm::vec3 light) {
	specular = glm::vec3(light[0], light[1], light[2]);
}

void Material::setEmissive(glm::vec3 light) {
	emission = glm::vec3(light[0], light[1], light[2]);
}

void Material::setShininess(int intensity) {
	shininess = intensity;
}

void Material::setAlpha(float alpha) {
	this->alpha = alpha;
}

glm::vec3 Material::getAmbient() const {
	return this->ambient;
}


glm::vec3 Material::getDiffuse() const {
	return this->diffuse;
}


glm::vec3 Material::getEmissive() const {
	return this->emission;
}


glm::vec3 Material::getSpecular() const {
	return this->specular;
}

int Material::getShininess() const {
	return this->shininess;
}

void Material::setTexture(Texture* texture) {
	this->texture = texture;
}

Texture* Material::getTexture() const {
	return texture;
}

bool Material::isTransparent() {
	return alpha < 1.0f;
}

float Material::getAlpha() {
	return alpha;
}

