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
// HandsOn 2-3 #2
// Include the header to use the G4Tubs class.


#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"

#include "G4PVPlacement.hh"
// HandsOn 2-3 #6
// Include the header to use the G4PVReplica class.


#include "G4VisAttributes.hh"

// HandsOn 3-2 #1
// Include the header to use user's SensitiveDetector class.


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
	G4Material* AIR = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");
	G4LogicalVolume* lv_World =	new G4LogicalVolume(sol_World, AIR, "World");
	G4VPhysicalVolume* pv_World =
			new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), lv_World, "World", 0, false, 0);

	// User geometry

	// HandsOn 2-3 #1
	// Change the size of 'sol_MyGeom'.
	// HandsOn 2-3 #2
	// Change the shape of 'sol_MyGeom' into a cylinder.
	G4VSolid* sol_MyGeom = new G4Box("Geom", 5.0*cm, 5.0*cm, 5.0*cm);

	// HandsOn 2-3 #3
	// Change the material into G4_Al
	G4Material* MyMat = G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER");
	G4LogicalVolume* lv_MyGeom = new G4LogicalVolume(sol_MyGeom, MyMat, "Geom");

	// HandsOn 2-3 #4
	// Change the location
	G4VPhysicalVolume* pv_MyGeom =
			new G4PVPlacement(0, G4ThreeVector(0.0, 0.0, 0.0), lv_MyGeom, "Geom", lv_World, false, 100);

	// HandsOn 2-3 #5
	// Define a solid and logical volume for replica


	// HandsOn 2-3 #6
	// Replicate the 10 MyRep geometry in the MyGeom geometry.


	// Visualization
	G4VisAttributes* va_World = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
	va_World->SetForceWireframe(true);
	lv_World->SetVisAttributes(va_World);

	// HandsOn 2-3 #7
	// Change the visualization option into blue wireframe.
	G4VisAttributes* va_MyGeom = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));
	va_MyGeom->SetForceSolid(true);
	lv_MyGeom->SetVisAttributes(va_MyGeom);

	// HandsOn 2-3 #8
	// Make the visualization option for MyRep as green solid with transparency.


	return pv_World;
}

void DetectorConstruction::ConstructSDandField()
{
	// HandsOn 3-2 #1
	// Construct user SensitiveDetector on the logical volume of 'RepGeom'.

}
