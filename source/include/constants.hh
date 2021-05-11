#ifndef constants_h
#define constants_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "Geometry.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SubtractionSolid.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4SDManager.hh"

//=================================================================
//       World parameters and placement of the FoCal
//=================================================================
constexpr G4double World_X = 20.0*m;         // X-full-length of world
constexpr G4double World_Y = 20.0*m;         // Y-full-length of world
constexpr G4double World_Z = 1000.0*m;       // Z-full-length of world
//Starting position of the FoCal detector
constexpr G4double Start_Z = 70.0*mm;//Start from interaction point
constexpr G4double Start_X = 0.0*mm;//Reference for the beam pipe
constexpr G4double Start_Y = 0.0*mm;//Reference for the beam pipe
//=================================================================
//                  Focal-E parameters
//=================================================================
//MiniFoCal block
constexpr G4int NumberOfLayers = 20;
//0-PAD layer, 1-PIX layer
constexpr G4int NumberPIX = 0;
constexpr G4int NumberPAD = 20;
constexpr G4int LayerLayout[NumberOfLayers] = {	
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};
//=================================================================
//PIX detector
constexpr G4int NpixX = 1000;
constexpr G4int NpixY = 1000;
constexpr G4double PIX_X = 1.0*mm;
constexpr G4double PIX_Y = 1.0*mm;
constexpr G4double PIX_Z = 0.10*mm;
	//Thicknesses
	constexpr G4double PIX_Absorber_Z = 3.5*mm;
	constexpr G4double PIX_Glue1_Z 	= 0.11*mm; //between W-Si
	constexpr G4double PIX_Glue2_Z 	= 0.11*mm; //between Si+FPC
	constexpr G4double PIX_FPC_Z 	= 0.28*mm; //Readout
	constexpr G4double PIX_AirGap 	= 1.2*mm;
	constexpr G4double PIX_Layer_Thickness = PIX_Absorber_Z + PIX_Glue1_Z + PIX_Z + PIX_Glue2_Z + PIX_FPC_Z + PIX_AirGap;
	//Plate size
	constexpr G4double PIX_GuardRingThickness = 0.00*mm;
	constexpr G4double PIX_MiniFoCal_X = ( (PIX_X*NpixX)+2*PIX_GuardRingThickness)*mm;
	constexpr G4double PIX_MiniFoCal_Y = ( (PIX_Y*NpixY)+2*PIX_GuardRingThickness)*mm;
//=================================================================
//PAD detector
constexpr G4int NpadX = 9;
constexpr G4int NpadY = 8;
constexpr G4double PAD_X = 10*mm;
constexpr G4double PAD_Y = 10*mm;
constexpr G4double PAD_Z = 0.32*mm;
//Overall materials
	//Thicknesses
	constexpr G4double PAD_Absorber_Z = 3.5*mm;
	constexpr G4double PAD_Glue1_Z 	= 0.11*mm; //between W-Si
	constexpr G4double PAD_Glue2_Z 	= 0.13*mm; //between Si+FPC
	constexpr G4double PAD_FPC_Z 	= 0.28*mm;
	constexpr G4double PAD_AirGap 	= 1.2*mm;
	constexpr G4double PAD_Layer_Thickness = PAD_Absorber_Z + PAD_Glue1_Z + PAD_Z + PAD_Glue2_Z + PAD_FPC_Z + PAD_AirGap;
	//Plate size
	constexpr G4double PAD_GuardRingThickness = 0.00*mm;
	constexpr G4double PAD_MiniFoCal_X = ((PAD_X*NpadX)+2*PAD_GuardRingThickness)*mm;
	constexpr G4double PAD_MiniFoCal_Y = ((PAD_Y*NpadY)+2*PAD_GuardRingThickness)*mm;
//=================================================================
//                  Gap between the E-H
//=================================================================
constexpr G4double AirPad = 0.6*mm;
constexpr G4double BackplaneThickness = 1.0*mm;
constexpr G4double AirGapFromFoCalE = 5.0*mm;
constexpr G4double BoxThickness = 1.0*mm;
constexpr G4double AirGapToFoCalH = 10.0*mm;
//=================================================================
//                  Focal-H parameters
//=================================================================
//Dimentions of the detector
constexpr G4int HCalGeometry = 2; //1- shashlik type, 1- capillary tubes

constexpr G4double HCAL_Z_Absorber = 500.0*mm; //longitudinal dimension of the absorber
constexpr G4double HCAL_Z_Scintilator = 1*mm; //1-longitudinal distance, 2-diameter of the tube
constexpr G4double HCAL_Z_Gap = 0.1*mm; //air-gap 1-longitudinal, 2-around the tube
constexpr G4double HCAL_X_Tower = 2.0*mm; //x-dimension of tower
constexpr G4double HCAL_Y_Tower = 2.0*mm; //y-dimension of tower

constexpr G4double HCal_Layer_Thickness = HCAL_Z_Absorber + HCAL_Z_Scintilator + HCAL_Z_Gap; //longitudinal dimension of sandwich calo
constexpr G4int HCALNumberOfLayers = 1; //number of layers in the sandwich

//how many towers we have
constexpr G4int HCALNumberOfTowersX = 50;//tower in x-direction
constexpr G4int HCALNumberOfTowersY = 40;//tower in y-direction
constexpr G4double HCalSizeX = HCALNumberOfTowersX*HCAL_X_Tower;
constexpr G4double HCalSizeY = HCALNumberOfTowersY*HCAL_Y_Tower;
//=================================================================
//                  ID numbers calculated
//=================================================================
//PADs
constexpr G4int IDnumber_PAD_First				= 1;
//PIXs
constexpr G4int IDnumber_PIX_First = NumberPAD*NpadX*NpadY + 1;
//Material is the same
constexpr G4int IDnumber_PAD_Absorber_First 	= NumberPAD*NpadX*NpadY + NumberPIX*NpixX*NpixY+1;
constexpr G4int IDnumber_PAD_Glue1_First 		= IDnumber_PAD_Absorber_First + NumberOfLayers;
constexpr G4int IDnumber_PAD_Glue2_First 		= IDnumber_PAD_Glue1_First + NumberOfLayers;
constexpr G4int IDnumber_PAD_FPC_First 			= IDnumber_PAD_Glue2_First + NumberOfLayers;
//All material between
constexpr G4int IDnumber_Backplane_First = (IDnumber_PAD_FPC_First+NumberOfLayers) + 1;
constexpr G4int IDnumber_BoxMaterial_First = (IDnumber_Backplane_First) + 1;
//HCal
constexpr G4int IDnumber_HCal_Scintilator_First = IDnumber_BoxMaterial_First + 1;
constexpr G4int IDnumber_HCal_Absorber_First 	= IDnumber_HCal_Scintilator_First + (HCALNumberOfTowersX*HCALNumberOfTowersY*HCALNumberOfLayers)+1;
constexpr G4int IDnumber_HCal_Gap_First 		= IDnumber_HCal_Absorber_First + (HCALNumberOfTowersX*HCALNumberOfTowersY)+1;
//EndCap
constexpr G4int IDnumber_HCal_Leakage_First = IDnumber_HCal_Gap_First+(HCALNumberOfTowersX*HCALNumberOfTowersY)+1000;
	

#endif
