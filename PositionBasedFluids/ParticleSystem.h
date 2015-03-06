#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "common.h"
#include "Cell.hpp"
#include "CellGrid.h"
#include "FoamParticle.hpp"

class ParticleSystem {
public:
	ParticleSystem();
	~ParticleSystem();

	void update();
	std::vector<glm::vec3>& getFluidPositions();
	std::vector<glm::vec4>& getFoamPositions();

private:
	std::vector<Particle> particles;
	std::vector<FoamParticle> foam;
	std::vector<glm::vec3> fluidPositions;
	std::vector<glm::vec4> foamPositions;
	CellGrid grid;

	void applyGravity(Particle &p);
	float WPoly6(glm::vec3 &pi, glm::vec3 &pj);
	glm::vec3 gradWPoly6(glm::vec3 &pi, glm::vec3 &pj);
	glm::vec3 WSpiky(glm::vec3 &pi, glm::vec3 &pj);
	glm::vec3 WViscosity(glm::vec3 &pi, glm::vec3 &pj);
	float WAirPotential(glm::vec3 &pi, glm::vec3 &pj);
	float lambda(Particle &p, std::vector<Particle*> &neighbors);
	float calcDensityConstraint(Particle &p, std::vector<Particle*> &neighbors);
	glm::vec3 eta(Particle &p, float &vorticityMag);
	glm::vec3 vorticityForce(Particle &p);
	void imposeConstraints(Particle &p);
	void imposeConstraints(FoamParticle &p);
	float clampedConstraint(float x, float max);
	float sCorrCalc(Particle &pi, Particle* &pj);
	glm::vec3 xsphViscosity(Particle &p);
	bool outOfRange(float x, float y, float z);
	void updatePositions();
	glm::vec3 getWeightedPosition(Particle &p);
	void calcDensities();
};

#endif
