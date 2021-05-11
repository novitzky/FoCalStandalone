//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PrimaryGenerator.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "PrimaryGenerator.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//------------------------------------------------------------------------------
PrimaryGenerator::PrimaryGenerator()
	: fpParticleGun_1(0)//, fpParticleGun_2(0) 
	  //------------------------------------------------------------------------------
{
	// Particle table
	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();

	// 1st gun - setup for fixed parameters 
	fpParticleGun_1  = new G4ParticleGun();
	{ 
		G4String particleName = "e+";
		G4double momentum = 150.0*GeV;
		G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

		fpParticleGun_1->SetParticleDefinition(particle);
		fpParticleGun_1->SetParticleMomentum(momentum);   //kinetic energy define
	}
}

//------------------------------------------------------------------------------
PrimaryGenerator::~PrimaryGenerator()
	//------------------------------------------------------------------------------
{
	delete fpParticleGun_1;
	// delete fpParticleGun_2;
}

//------------------------------------------------------------------------------
void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
	//------------------------------------------------------------------------------
{
	// Gun position - randomization 
	G4double offset1 = 2.0*(G4UniformRand()-0.5);
	G4double offset2 = 2.0*(G4UniformRand()-0.5);
	G4ThreeVector position_1 = G4ThreeVector(offset1, offset2, 0.0);   //粒子の打ち出す位置を指定
	//G4double angle1 = 0.0376*2*(G4UniformRand()-0.5)*deg;//1x1cm^2
	//G4double angle2 = 0.0376*2*(G4UniformRand()-0.5)*deg;//1x1cm^2   //set the degree of particle d
	
	G4ThreeVector momentumDirection = G4ThreeVector(0.0, 0.0, 1.0);//.rotateY(angle1).rotateX(angle2);
	fpParticleGun_1->SetParticleMomentumDirection(momentumDirection);

	fpParticleGun_1->SetParticlePosition(position_1);  // Particle の入射位置を指定する。
	fpParticleGun_1->GeneratePrimaryVertex(anEvent);        //loop in the events

}

