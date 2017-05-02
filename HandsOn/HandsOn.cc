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

// HandsOn 2-1 #1
// Include the header to use the G4RunManager class.


// HandsOn 2-1 #2
// Include the header for the mandatory initialization classes.
// (DetectorConstruction, PhysicsList, ActionInitialization)


// HandsOn 2-2 #1
// Include the header to use the G4UImanager class.


// HandsOn 2-2 #3
// Include the header to use the G4UIExecutive class.


// HandsOn 2-2 #5
// Include the header to use the G4VisExecutive class.


// HandsOn 2-4 #1
// Include the header to use the FTFP_BERT physics bundle.


// HandsOn 2-4 #2
// Include the header to use the B3PhysicsList class.


int main(int argc, char** argv)
{
	// HandsOn 2-1 #1
	// Construct the default run manager.


	// HandsOn 2-1 #2
	// Set mandatory initialization classes.
	// Detector construction, Physics list, Action initialization
	// HandsOn 2-4 #1
	// Change the user PhysicsList class into FTFP_BERT.
	// HandsOn 2-4 #2
	// Change the FTFP_BERT class into B3PhysicsList class.


	// HandsOn 2-1 #2
	// Initialize G4 kernel.


	// HandsOn 2-2 #1
	// Construct the ui (user interface) manager.


	// HandsOn 2-2 #5
	// Construct the visualization manager.


	// HandsOn 2-2 #2
	// User interface for batch mode


	// HandsOn 2-2 #3
	// User interface for interactive mode using qt


	// HandsOn 2-2 #4
	// Combine #2 and #3
	// (argc==1? true: interactive mode, false: batch mode)
	// HandsOn 2-2 #7
	// Insert "ApplyCommand" function to use vis.mac file.


	// HandsOn 2-1 #1
	// Free the run manager.


	return 0;
}
