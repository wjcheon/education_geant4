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

#include "DetectorConstruction.hh"
#include "PolygonDataImport.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4TessellatedSolid.hh"
#include "G4LogicalVolume.hh"

#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"


DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }


DetectorConstruction::~DetectorConstruction()
{ }



G4VPhysicalVolume* DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  //     
  // World
  //
  G4double world_sizeXY = 1 * m;
  G4double world_sizeZ  = 1 * m;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0);                    //copy number
                     

  //     
  // Polygon
  //

  G4Material* polyMat = nist->FindOrBuildMaterial("G4_WATER");

  // HandsOn 4-1 #1
  // Define Polygon Geometery
  PolygonDataImport* polyData = new PolygonDataImport("./polygon/CenterLeaf_ply.ply");
  G4int numFacet = polyData->GetNumFacet();
  G4TessellatedSolid* polySolid = new G4TessellatedSolid("CenterLeaf");
  for(G4int i=0; i < numFacet ; i++){
	  polySolid->AddFacet(polyData->GetFacet(i));
  }
  polySolid->SetSolidClosed(true);
  G4LogicalVolume *polyLogic = new G4LogicalVolume(polySolid,polyMat,"CenterLeaf");
  G4VPhysicalVolume *polyPhys = new G4PVPlacement(0,G4ThreeVector(0,0,0),polyLogic,"CenterLeaf",logicWorld,false,0);
  //
  //always return the physical World
  //
  return physWorld;
}


