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

#include "DetectorConstruction.hh"

#include "G4Box.hh"
// Tutorial1 #3
// Include the header to use G4Tubs.


#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"

#include "G4PVPlacement.hh"

#include "G4VisAttributes.hh"

// Tutorial1 #9
// Include the header of user sensitive detector class.


DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction()
{

}

DetectorConstruction::~DetectorConstruction()
{

}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	// World
	G4VSolid* sol_World = new G4Box("World", 0.5*m, 0.5*m, 0.5*m);
	G4Material* VACCUM = G4NistManager::Instance()->FindOrBuildMaterial("G4_Galactic");
	G4LogicalVolume* lv_World = new G4LogicalVolume(sol_World, VACCUM, "World");
	G4VPhysicalVolume* pv_World =
			new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), lv_World, "World", 0, false, 0);

	// User geometry
	// Tutorial1 #3
	// Make a water cylinder (R: 3 cm, H(z): 6 cm) at (0, 0, 6 cm).


	// Tutorial1 #5
	// Make a vaccum box (x: 0.1 cm, y: 6 cm, z: 6 cm)  at (4 cm, 0, 6 cm).


	// Visualization
	G4VisAttributes* va_World = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
	va_World->SetForceWireframe(true);
	lv_World->SetVisAttributes(va_World);

	// Tutorial1 #4
	// Make the visualization option for the water cylinder (blue wireframe).


	// Tutorial1 #6
	// Make the visualization option for the vaccum boxes (red wireframe).


	return pv_World;
}

void DetectorConstruction::ConstructSDandField()
{
	// Tutorial1 #9
	// Construct user SensitiveDetector on the logical volume of 'KEScorer'.

}
