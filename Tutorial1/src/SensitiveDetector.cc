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

#include "SensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String name)
:G4VSensitiveDetector(name)
{
	// Tutorial1 #12
	// Open the output file. (filename: KE.out")

}

SensitiveDetector::~SensitiveDetector()
{
	// Tutorial1 #12
	// Close the output file.

}

void SensitiveDetector::Initialize(G4HCofThisEvent*)
{

}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
	// Tutorial1 #10
	// Print the kinetic energy at the pre-steppoint.


	// Tutorial1 #11
	// Print the particle name.


	// Tutorial1 #13
	// Save kinetic energy when the particle is 'gamma'.
	// Use first output file for the side scorer and use second output file for rear scorer.


    return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{

}
