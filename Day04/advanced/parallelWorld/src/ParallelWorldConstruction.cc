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
// 	Author: mchan
//

#include "ParallelWorldConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

ParallelWorldConstruction::ParallelWorldConstruction(G4String& parallelWorldName)
:G4VUserParallelWorld(parallelWorldName),fConstructed(false)
{ }



ParallelWorldConstruction::~ParallelWorldConstruction()
{ }


void ParallelWorldConstruction::Construct()
{  
	if(fConstructed) return;
	fConstructed = true;

	G4NistManager* nist = G4NistManager::Instance();

	//
	// World
	//
	G4VPhysicalVolume* ghostWorld = GetWorld();
	G4LogicalVolume* worldLogical = ghostWorld->GetLogicalVolume();

	//
	// Sphere
	//

	G4Material* sphere_mat = nist->FindOrBuildMaterial("G4_W");
	G4Sphere* solidSphere =
			new G4Sphere("Sphere",  	//its name
				0,			//its Rmin
				5. * cm,		//its Rmax
				0,			//its SPhi
				360*deg, 		//its DPhi
				0,			//its STheta
				360*deg); 		//its DTheta

	G4LogicalVolume* logicSphere =
	new G4LogicalVolume(solidSphere,             	//its solid
			sphere_mat,              	//its material
			"Sphere");               	//its name

	new G4PVPlacement(0,                         	//no rotation
			G4ThreeVector(0,0,0),        	//at (0,0,0)
			logicSphere,                 	//its logical volume
			"Sphere",                    	//its name
			worldLogical,                	//its mother  volume
			false,                       	//no boolean operation
			0);                          	//copy number

}


