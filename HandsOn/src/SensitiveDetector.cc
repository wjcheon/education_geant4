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
	// HandsOn 3-2 #10
	// Open the output file.

}

SensitiveDetector::~SensitiveDetector()
{
	// HandsOn 3-2 #10
	// Close the output file.

}

void SensitiveDetector::Initialize(G4HCofThisEvent*){
	// HandsOn 3-2 #2
	// Print the event ID and check in the verbose output.

}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*){
	// HandsOn 3-2 #3
	// Print 'Check!'.


	// HandsOn 3-2 #4
	// Print the track ID and parent ID.


	// HandsOn 3-2 #5
	// Print the position of PreStepPoint and PostStepPoint.


	// HandsOn 3-2 #6
	// Print kinetic energy and deposited energy.


	// HandsOn 3-2 #7
	// Print step length and cumulative track length.


	// HandsOn 3-2 #8
	// Print the geometry information.


	// HandsOn 3-2 #9
	// Print the process name.


	// HandsOn 3-2 #10
	// Save cumulative track length when the process name is 'compt'.


    return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*){
	// HandsOn 3-2 #2
	// Print the event ID and check in the verbose output.

}
