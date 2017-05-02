// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// 	Author: yskim
//

#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"

// HandsOn 2-4 #5
// Include the header to use the Randomize class.


// HandsOn 2-4 #7
// Include the header to use the G4RandomDirection class.


PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction()
{
	// HandsOn 2-4 #8
	// Change the type of fPrimary into G4GeneralParticleSource.
	fPrimary = new G4ParticleGun();

	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();

	// HandsOn 2-4 #8
	// Add comment from 2-4 #3 to #7

	// HandsOn 2-4 #3
	// Change the particle into electron (e-).
	G4ParticleDefinition* MyParticle = particleTable->FindParticle("gamma");
	fPrimary->SetParticleDefinition(MyParticle);

	// HandsOn 2-4 #4
	// Change the particle energy and position into 50.0 MeV and 0.0, 5.0 cm, 0.0, respectively.
	fPrimary->SetParticleEnergy(6.0*MeV);
	fPrimary->SetParticlePosition(G4ThreeVector(0.0, 0.0, 0.0));

	fPrimary->SetParticleMomentumDirection(G4ThreeVector(0.0, 0.0, 1.0));

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete fPrimary;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

	// HandsOn 2-4 #5
	// Generate the particle as a line.
	// HandsOn 2-4 #6
	// Generate the particle as a plane.


	// HandsOn 2-4 #7
	// Generate the particle isotropically.


	fPrimary->GeneratePrimaryVertex(anEvent);
}
