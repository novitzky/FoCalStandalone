
//mini-FoCal at SPS setup
//with trigger Scintillators at 0X0 & 20X0

//edited i 20190805  Isshiki
//This code was modified the the length of materialals
//include the 2 Scintirator front of the 1layer and

//LGL Layers
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
//#include "SensitiveVolume.hh"
#include "G4SDManager.hh"
#include "constants.hh"

//------------------------------------------------------------------------------
Geometry::Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Geometry::~Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
G4VPhysicalVolume* Geometry::Construct()
	//------------------------------------------------------------------------------
{
	G4NistManager* material_Man = G4NistManager::Instance();  //NistManager: start element destruction


	G4Box* solid_World =
		new G4Box("Solid_World", World_X/2.0, World_Y/2.0, World_Z/2.0);

	G4Material* material_World = material_Man->FindOrBuildMaterial("G4_AIR");
	G4Material* material_air = material_Man->FindOrBuildMaterial("G4_AIR");
	G4LogicalVolume* logVol_World = new G4LogicalVolume(solid_World, material_World, "LogVol_World");
	logVol_World->SetVisAttributes (G4VisAttributes::Invisible);

	G4PVPlacement* physVol_World  =
		new G4PVPlacement(G4Transform3D(), "PhysVol_World", logVol_World, 0,
				false, 0);
	//*****************************************************************************************
	//G4box is the material
	//PAD layer
	G4Box* PAD_W 		= new G4Box("PPAD_W",		PAD_MiniFoCal_X/2.0, PAD_MiniFoCal_Y/2.0, PAD_Absorber_Z/2.0);
	G4Box* PAD_Glue1 	= new G4Box("PPAD_Glue1",	PAD_MiniFoCal_X/2.0, PAD_MiniFoCal_Y/2.0, PAD_Glue1_Z/2.0);
	G4Box* PAD_Silicon 	= new G4Box("PPAD_Silicon",	PAD_X/2.0, 			 PAD_Y/2.0, 		  PAD_Z/2.0); 
	G4Box* PAD_Glue2 	= new G4Box("PPAD_Glue2",	PAD_MiniFoCal_X/2.0, PAD_MiniFoCal_Y/2.0, PAD_Glue2_Z/2.0);
	G4Box* PAD_FPC 		= new G4Box("PPAD_FPC",		PAD_MiniFoCal_X/2.0, PAD_MiniFoCal_Y/2.0, PAD_FPC_Z/2.0);
	//PIX layer
	G4Box* PIX_W 		= new G4Box("PPIX_W",		PIX_MiniFoCal_X/2.0, PIX_MiniFoCal_Y/2.0, PIX_Absorber_Z/2.0);
	G4Box* PIX_Glue1 	= new G4Box("PPIX_Glue1",	PIX_MiniFoCal_X/2.0, PIX_MiniFoCal_Y/2.0, PIX_Glue1_Z/2.0);
	G4Box* PIX_Silicon 	= new G4Box("PPIX_Silicon",	PIX_X/2.0, 			 PIX_Y/2.0, 		  PIX_Z/2.0); 
	G4Box* PIX_Glue2 	= new G4Box("PPIX_Glue2",	PIX_MiniFoCal_X/2.0, PIX_MiniFoCal_Y/2.0, PIX_Glue2_Z/2.0);
	G4Box* PIX_FPC 		= new G4Box("PPIX_FPC",		PIX_MiniFoCal_X/2.0, PIX_MiniFoCal_Y/2.0, PIX_FPC_Z/2.0);
	//Al boxes
	G4Box* BackPlane 		= new G4Box("BackPlane", 	10, 10, BackplaneThickness/2.0);
	G4Box* BoxMaterial 		= new G4Box("BoxMaterial", 	10, 10, BoxThickness/2.0);
	//HCal Capillary Tube
	G4Box* HCalBox 		= new G4Box("HCalBox", 	HCalSizeX/2.0, HCAL_Y_Tower/2.0, HCAL_Z_Absorber/2.0);
 	//A large box after the HCal to study the leakage from the HCal
	G4Box* HCal_Leakage  	= new G4Box("HCal_Leakage",	1300*mm, 1300*mm, 2000.00*mm);
	//*****************************************************************************************
	//Unique materials
	//*****************************************************************************************
	//The definition of the W alloy
	G4Material* material_tungsten = new G4Material("tungsten",18.73 *g/cm3,3);
	G4Element* W  = material_Man->FindOrBuildElement(74);//density: 19.3  I:727
	G4Element* Ni = material_Man->FindOrBuildElement(28);//density: 8.902   I:311
	G4Element* Cu = material_Man->FindOrBuildElement(29);//G4_Cu  8.96   I:322
	material_tungsten->AddElement(W,94*perCent);    //the percentage of materialal
	material_tungsten->AddElement(Ni,4*perCent);
	material_tungsten->AddElement(Cu,2*perCent);

	//Definition of the Epoxy Glue
	G4Material* material_PET = new G4Material("PET",1.38*g/cm3,3);
	G4Element* O = material_Man->FindOrBuildElement(8);
	G4Element* elH = new G4Element("Hydrogen","H", 1, 1.00794 *g/mole);
	G4Element* elC = new G4Element("Carbon","C", 6, 12.011 *g/mole);
	material_PET->AddElement(elC,10);
	material_PET->AddElement(elH,8);
	material_PET->AddElement(O,4);
	
	//Definition of the scintillator
	G4double density= 1.032 *g/cm3;       //to define the dencity on my own
	G4Material* material_Scintilator = new G4Material("Scintilator",density,2);   //
	material_Scintilator->AddElement(elC,8);
	material_Scintilator->AddElement(elH,8);

	//Other materials
	G4Material* material_Si = material_Man->FindOrBuildMaterial("G4_Si");
	G4Material* material_Pb = material_Man->FindOrBuildMaterial("G4_Pb");
	G4Material* material_Cu = material_Man->FindOrBuildMaterial("G4_Cu");
	G4Material* material_Fe = material_Man->FindOrBuildMaterial("G4_Fe");
	G4Material* material_Al = material_Man->FindOrBuildMaterial("G4_Al");
	//*****************************************************************************************
	//   Logical volumes
	//*****************************************************************************************
	//PAD
	G4LogicalVolume* logVol_PAD_W 		= new G4LogicalVolume( PAD_W, 		material_tungsten, "LogVol_PAD_W", 0, 0, 0 );
	G4LogicalVolume* logVol_PAD_Glue1 	= new G4LogicalVolume( PAD_Glue1, 	material_PET, "LogVol_PAD_Glue1", 0, 0, 0 );
	G4LogicalVolume* logVol_PAD_Silicon	= new G4LogicalVolume( PAD_Silicon, material_Si, "LogVol_PAD_Silicon", 0, 0, 0 );
	G4LogicalVolume* logVol_PAD_Glue2 	= new G4LogicalVolume( PAD_Glue2, 	material_PET, "LogVol_PAD_Glue2", 0, 0, 0 );
	G4LogicalVolume* logVol_PAD_FPC 	= new G4LogicalVolume( PAD_FPC, 	material_PET, "LogVol_PAD_FPC", 0, 0, 0 );
	fScoringVol_PAD = logVol_PAD_Silicon;
	fScoringVol_EMCal2 = logVol_PAD_W;            												  
	//PIX
	G4LogicalVolume* logVol_PIX_W 		= new G4LogicalVolume( PIX_W, 		material_tungsten, "LogVol_PIX_W", 0, 0, 0 );
	G4LogicalVolume* logVol_PIX_Glue1 	= new G4LogicalVolume( PIX_Glue1, 	material_PET, "LogVol_PIX_Glue1", 0, 0, 0 );
	G4LogicalVolume* logVol_PIX_Silicon	= new G4LogicalVolume( PIX_Silicon, material_Si, "LogVol_PIX_Silicon", 0, 0, 0 );
	G4LogicalVolume* logVol_PIX_Glue2 	= new G4LogicalVolume( PIX_Glue2, 	material_PET, "LogVol_PIX_Glue2", 0, 0, 0 );
	G4LogicalVolume* logVol_PIX_FPC 	= new G4LogicalVolume( PIX_FPC, 	material_PET, "LogVol_PIX_FPC", 0, 0, 0 );
	fScoringVol_PIX = logVol_PIX_Silicon;
	fScoringVol_EMCal1 = logVol_PIX_W;
	//Material between E-H cal
	G4LogicalVolume* logVol_BackPlane 		= new G4LogicalVolume( BackPlane, 	material_Al, "LogVol_BackPlane", 0, 0, 0 );
	G4LogicalVolume* logVol_BoxMaterial		= new G4LogicalVolume( BoxMaterial, material_Al, "LogVol_BoxMaterial", 0, 0, 0 );							  
	fScoringVol_Gap1 = logVol_BackPlane;
	fScoringVol_Gap2 = logVol_BoxMaterial;
	//EndCap
	G4LogicalVolume* logVol_HCal_Leakage 	= new G4LogicalVolume( HCal_Leakage, 	material_tungsten, "logVol_HCal_Leakage",0,0,0);
	fScoringVol_Leak = logVol_HCal_Leakage;
	//*****************************************************************************************
	//							 Construct E-Cal detector
	//*****************************************************************************************
	G4int IPADlayer = 0;
	G4int IPIXlayer = 0;
	//The PAD and PIX layer thicknesses can be different - this variable remembers the previous layer thickness either PIX or PAD
	//It is changed at the end of the loops
	G4double TotalLayerThickness = 0;
	G4cout << PAD_Layer_Thickness << "  " << PIX_Layer_Thickness << G4endl;
	//No layers will turn off the E-Cal part
	if(NumberOfLayers > 0){
		for(G4int ilayer=0; ilayer<NumberOfLayers; ilayer++){
			//This is the PAD layer
			if(LayerLayout[ilayer] == 0){
				G4double position_Z_PAD_Absorber	= Start_Z + PAD_Absorber_Z/2 + TotalLayerThickness + PAD_Layer_Thickness;
				G4double position_Z_PAD_Glue1		= Start_Z + PAD_Absorber_Z + PAD_Glue1_Z/2 + TotalLayerThickness + PAD_Layer_Thickness;
				G4double position_Z_PAD_Silicon		= Start_Z + PAD_Absorber_Z + PAD_Glue1_Z + PAD_Z/2 + TotalLayerThickness + PAD_Layer_Thickness;
				G4cout << ilayer << " PAD " << position_Z_PAD_Silicon << "  " << TotalLayerThickness << G4endl;
				for(int iy = 0; iy < NpadY; iy++){
					for(int ix = 0; ix < NpadX; ix++){
						G4double position_X_PAD_Silicon = (Start_X - PAD_MiniFoCal_X/2 + ix*PAD_X + PAD_X/2)*mm;
						G4double position_Y_PAD_Silicon = (Start_Y - PAD_MiniFoCal_Y/2 + iy*PAD_Y + PAD_Y/2)*mm;
						G4ThreeVector    threeVect_PAD_Silicon	= G4ThreeVector(position_X_PAD_Silicon, position_Y_PAD_Silicon, position_Z_PAD_Silicon);
						G4RotationMatrix rotMtrx_PAD_Silicon	= G4RotationMatrix();
						G4Transform3D    trans3D_PAD_W			= G4Transform3D(rotMtrx_PAD_Silicon, threeVect_PAD_Silicon);
					
						G4int IDnumber_PAD = IDnumber_PAD_First + ix + NpadX*iy + NpadX*NpadY*IPADlayer;
						//G4cout << "PAD " << IDnumber_PAD << "  " << ix << "  " << iy << "  " << IPADlayer << G4endl;
						new G4PVPlacement(trans3D_PAD_W, 
											"PhysVol_Si", 
											logVol_PAD_Silicon, 
											physVol_World,
											false, 
											IDnumber_PAD);
					}
				}
				G4double position_Z_PAD_Glue2	= Start_Z + PAD_Absorber_Z + PAD_Glue1_Z + PAD_Z + PAD_Glue2_Z/2 + TotalLayerThickness + PAD_Layer_Thickness;
				G4double position_Z_PAD_FPC		= Start_Z + PAD_Absorber_Z + PAD_Glue1_Z + PAD_Z + PAD_Glue2_Z + PAD_FPC_Z/2 + TotalLayerThickness + PAD_Layer_Thickness;
			
				G4ThreeVector threeVect_PAD_W 		= G4ThreeVector(Start_X, Start_Y, position_Z_PAD_Absorber);
				G4ThreeVector threeVect_PAD_Glue1 	= G4ThreeVector(Start_X, Start_Y, position_Z_PAD_Glue1);
				G4ThreeVector threeVect_PAD_Glue2 	= G4ThreeVector(Start_X, Start_Y, position_Z_PAD_Glue2);
				G4ThreeVector threeVect_PAD_FPC 	= G4ThreeVector(Start_X, Start_Y, position_Z_PAD_FPC);

				G4RotationMatrix rotMtrx_PAD_W 		= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PAD_Glue1 	= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PAD_Glue2 	= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PAD_FPC 	= G4RotationMatrix();

				G4Transform3D trans3D_PAD_W 	= G4Transform3D(rotMtrx_PAD_W, 		threeVect_PAD_W);
				G4Transform3D trans3D_PAD_Glue1 = G4Transform3D(rotMtrx_PAD_Glue1, 	threeVect_PAD_Glue1);
				G4Transform3D trans3D_PAD_Glue2 = G4Transform3D(rotMtrx_PAD_Glue2, 	threeVect_PAD_Glue2);
				G4Transform3D trans3D_PAD_FPC 	= G4Transform3D(rotMtrx_PAD_FPC, 	threeVect_PAD_FPC);

				G4int IDnumber_PAD_Absorber 	= IDnumber_PAD_Absorber_First	+ilayer;
				G4int IDnumber_PAD_Glue1 		= IDnumber_PAD_Glue1_First		+ilayer;
				G4int IDnumber_PAD_Glue2 		= IDnumber_PAD_Glue2_First		+ilayer;
				G4int IDnumber_PAD_FPC 			= IDnumber_PAD_FPC_First		+ilayer;
			
				//G4cout << "PAD_ABS " << IDnumber_PAD_Absorber << "  " << ilayer << G4endl;
				//G4cout << "PAD_GLU1 " << IDnumber_PAD_Glue1 << "  " << ilayer << G4endl;
				//G4cout << "PAD_GLU2 " << IDnumber_PAD_Glue2 << "  " << ilayer << G4endl;
				//G4cout << "PAD_FPC " << IDnumber_PAD_FPC << "  " << ilayer << G4endl;
			
				new G4PVPlacement(trans3D_PAD_W, 		"PhysVol_Absorber", logVol_PAD_W,  		physVol_World, false, IDnumber_PAD_Absorber);
				new G4PVPlacement(trans3D_PAD_Glue1, 	"PhysVol_Glue1", 	logVol_PAD_Glue1, 	physVol_World, false, IDnumber_PAD_Glue1);
				new G4PVPlacement(trans3D_PAD_Glue2, 	"PhysVol_Glue2", 	logVol_PAD_Glue2, 	physVol_World, false, IDnumber_PAD_Glue2);
				new G4PVPlacement(trans3D_PAD_FPC, 		"PhysVol_FPC", 		logVol_PAD_FPC,     physVol_World, false, IDnumber_PAD_FPC);
			
				G4cout << position_Z_PAD_Absorber << G4endl;
				IPADlayer++;
				//Which layer thickness
				TotalLayerThickness += PAD_Layer_Thickness;
			}
			else if(LayerLayout[ilayer] == 1){
				G4double position_Z_PIX_Absorber	= Start_Z + PIX_Absorber_Z/2 + TotalLayerThickness;
				G4double position_Z_PIX_Glue1		= Start_Z + PIX_Absorber_Z + PIX_Glue1_Z/2 + TotalLayerThickness;
				//Just create one large continuous silicon
				G4double position_Z_PIX_Silicon		= Start_Z + PIX_Absorber_Z + PIX_Glue1_Z + PIX_Z/2 + TotalLayerThickness;
				G4double position_Z_PIX_Glue2	= Start_Z + PIX_Absorber_Z + PIX_Glue1_Z + PIX_Z + PIX_Glue2_Z/2 + TotalLayerThickness;
				G4double position_Z_PIX_FPC		= Start_Z + PIX_Absorber_Z + PIX_Glue1_Z + PIX_Z + PIX_Glue2_Z + PIX_FPC_Z/2 + TotalLayerThickness;
			
				G4ThreeVector threeVect_PIX_W 		= G4ThreeVector(Start_X, Start_Y, position_Z_PIX_Absorber);
				G4ThreeVector threeVect_PIX_Si 		= G4ThreeVector(Start_X, Start_Y, position_Z_PIX_Silicon);
				G4ThreeVector threeVect_PIX_Glue1 	= G4ThreeVector(Start_X, Start_Y, position_Z_PIX_Glue1);
				G4ThreeVector threeVect_PIX_Glue2 	= G4ThreeVector(Start_X, Start_Y, position_Z_PIX_Glue2);
				G4ThreeVector threeVect_PIX_FPC 	= G4ThreeVector(Start_X, Start_Y, position_Z_PIX_FPC);

				G4RotationMatrix rotMtrx_PIX_W 		= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PIX_Si		= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PIX_Glue1 	= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PIX_Glue2 	= G4RotationMatrix();
				G4RotationMatrix rotMtrx_PIX_FPC 	= G4RotationMatrix();

				G4Transform3D trans3D_PIX_W 	= G4Transform3D(rotMtrx_PIX_W, 		threeVect_PIX_W);
				G4Transform3D trans3D_PIX_Si 	= G4Transform3D(rotMtrx_PIX_Si, 	threeVect_PIX_Si);
				G4Transform3D trans3D_PIX_Glue1 = G4Transform3D(rotMtrx_PIX_Glue1, 	threeVect_PIX_Glue1);
				G4Transform3D trans3D_PIX_Glue2 = G4Transform3D(rotMtrx_PIX_Glue2, 	threeVect_PIX_Glue2);
				G4Transform3D trans3D_PIX_FPC 	= G4Transform3D(rotMtrx_PIX_FPC, 	threeVect_PIX_FPC);

				G4int IDnumber_PIX_Absorber 	= IDnumber_PAD_Absorber_First + ilayer;
				G4int IDnumber_PIX				= IDnumber_PIX_First + ilayer;
				G4int IDnumber_PIX_Glue1 		= IDnumber_PAD_Glue1_First	  + ilayer;
				G4int IDnumber_PIX_Glue2 		= IDnumber_PAD_Glue2_First	  + ilayer;
				G4int IDnumber_PIX_FPC 			= IDnumber_PAD_FPC_First	  + ilayer;
			
				new G4PVPlacement(trans3D_PIX_W, 		"PhysVol_Absorber", logVol_PIX_W,  		physVol_World, false, IDnumber_PIX_Absorber);
				new G4PVPlacement(trans3D_PIX_Glue1, 	"PhysVol_Glue1", 	logVol_PIX_Glue1, 	physVol_World, false, IDnumber_PIX_Glue1);
				new G4PVPlacement(trans3D_PIX_W, 
									"PhysVol_Si", 
									logVol_PIX_Silicon, 
									physVol_World,
									false, 
									IDnumber_PIX);
				new G4PVPlacement(trans3D_PIX_Glue2, 	"PhysVol_Glue2", 	logVol_PIX_Glue2, 	physVol_World, false, IDnumber_PIX_Glue2);
				new G4PVPlacement(trans3D_PIX_FPC, 		"PhysVol_FPC", 		logVol_PIX_FPC,     physVol_World, false, IDnumber_PIX_FPC);
				IPIXlayer++;
				//Which layer thickness
				TotalLayerThickness += PIX_Layer_Thickness;
			}
		}
		TotalLayerThickness += PAD_Layer_Thickness;		
	}
	//*****************************************************************************************
	//				Material between the FoCal-E and FoCal-H detectors
	//*****************************************************************************************
	G4double Backplane_startZ = Start_Z + TotalLayerThickness + AirPad + BackplaneThickness/2;
	G4ThreeVector threeVect_LogV_Backplane 		= G4ThreeVector(Start_X, Start_Y, Backplane_startZ);
	G4RotationMatrix rotMtrx_LogV_Backplane		= G4RotationMatrix();
	G4Transform3D trans3D_LogV_Backplane 		= G4Transform3D(rotMtrx_LogV_Backplane, 	threeVect_LogV_Backplane);
	G4int IDnumber_Backplane = IDnumber_Backplane_First;
	G4cout << "Backplane " << Backplane_startZ << G4endl;
	new G4PVPlacement(trans3D_LogV_Backplane, 	 "PhysVol_Backplane", 	 logVol_BackPlane, 		physVol_World,false, IDnumber_Backplane);
	
	G4double BoxMaterial_startZ = Start_Z + TotalLayerThickness + AirPad + BackplaneThickness + AirGapFromFoCalE + BoxThickness/2;
	G4ThreeVector threeVect_LogV_BoxMaterial 	= G4ThreeVector(Start_X, Start_Y, BoxMaterial_startZ);
	G4RotationMatrix rotMtrx_LogV_BoxMaterial	= G4RotationMatrix();
	G4Transform3D trans3D_LogV_BoxMaterial 		= G4Transform3D(rotMtrx_LogV_BoxMaterial, 	threeVect_LogV_BoxMaterial);
	G4int IDnumber_BoxMaterial = IDnumber_BoxMaterial_First;
	G4cout << "BoxMaterial " << BoxMaterial_startZ << G4endl;
	new G4PVPlacement(trans3D_LogV_BoxMaterial, 	"PhysVol_BoxMaterial", 	 logVol_BoxMaterial, 		physVol_World,false, IDnumber_BoxMaterial);
	//*****************************************************************************************
	//							 Construct H-Cal detector
	//*****************************************************************************************
	G4double HCal_startZ = Start_Z + TotalLayerThickness + AirPad + BackplaneThickness + AirGapFromFoCalE + BoxThickness + AirGapToFoCalH;
	G4double HCal_X = (HCALNumberOfTowersX*HCAL_X_Tower)/2;
	G4double HCal_Y = (HCALNumberOfTowersY*HCAL_Y_Tower)/2;
	G4cout << Start_Z << "  " << Backplane_startZ << "  " << BoxMaterial_startZ << "  " << HCal_startZ << G4endl;
	//Construct one H-Cal tower
	G4LogicalVolume* singletower = ConstructTower();
	for(G4int TowerY = 0; TowerY < HCALNumberOfTowersY; TowerY++){
		G4LogicalVolume* HadCalRowLogical  = new G4LogicalVolume(HCalBox,material_air,"HCalBoxLogic");
	    new G4PVReplica("HadCalRowLogical", singletower, HadCalRowLogical, kXAxis, HCALNumberOfTowersX, HCAL_X_Tower);
	    new G4PVPlacement(0, G4ThreeVector( 0, -HCalSizeY/2 + TowerY*HCAL_Y_Tower, HCal_startZ + HCAL_Z_Absorber/2),
	                  "HCalDetector", HadCalRowLogical, physVol_World, 0, 0, 0);		
	}
	
	//This endcap is to study the particles which penetrate through all the detectors
	G4double HCal_Z_Leakage = HCal_startZ + HCal_Layer_Thickness*HCALNumberOfLayers + 3000.0;
	G4ThreeVector threeVect_LogV_HCal_Leakage 		= G4ThreeVector(Start_X, Start_Y, HCal_Z_Leakage);
	G4RotationMatrix rotMtrx_LogV_HCal_Leakage		= G4RotationMatrix();
	G4Transform3D trans3D_LogV_HCal_Leakage 		= G4Transform3D(rotMtrx_LogV_HCal_Leakage, 	threeVect_LogV_HCal_Leakage);
	G4int IDnumber_HCal_Leakage = IDnumber_HCal_Leakage_First;
	G4cout << "LEAK " << IDnumber_HCal_Leakage << G4endl;
	//new G4PVPlacement(trans3D_LogV_HCal_Leakage, 	 "PhysVol_HCal_Leakage", 	 logVol_HCal_Leakage, 		physVol_World,false, IDnumber_HCal_Leakage);
	
	return physVol_World;
}

G4LogicalVolume* Geometry::ConstructTower(){
	
	G4NistManager* material_Man = G4NistManager::Instance();  //NistManager: start element destruction
	G4Material* material_air = G4Material::GetMaterial("G4_AIR");
 	G4Material* material_Cu = material_Man->FindOrBuildMaterial("G4_Cu");
	//Definition of the scintillator
	G4double density= 1.032 *g/cm3;       //to define the dencity on my own
	G4Element* elH = new G4Element("Hydrogen","H", 1, 1.00794 *g/mole);
	G4Element* elC = new G4Element("Carbon","C", 6, 12.011 *g/mole);
	G4Material* material_Scintilator = new G4Material("Scintilator",density,2);   //
	material_Scintilator->AddElement(elC,8);
	material_Scintilator->AddElement(elH,8);

    G4VSolid* HCalTower = new G4Box(G4String("HCalTower"),
                                    HCAL_X_Tower / 2.0,
                                    HCAL_Y_Tower / 2.0,
                                    HCAL_Z_Absorber / 2.0);

    G4LogicalVolume* HCalTowerLogic = new G4LogicalVolume(HCalTower,
                                                          material_air,
                                                          "HCalTowerLogic",
                                                          0, 0, 0);		  
	G4VSolid* HCalTubeCutout  = new G4Tubs(G4String("HCalTubeCutout"),
  											0,
  											(HCAL_Z_Scintilator+HCAL_Z_Gap)/2.0, //Small airgap around the scintillator tube
  											1.03*HCAL_Z_Absorber, //make it 1.03 times longer to ensure full cutout
  											0.,2*M_PI*rad);
											
	G4VSolid* HCalAbsorber = new G4SubtractionSolid(G4String("HCalAbsorber"), 
  											HCalTower, 
  										    HCalTubeCutout, 
 										    0,
											G4ThreeVector( 0, 0, 0.));
  	//scintillator in the absorber
    G4VSolid* HCalTube  = new G4Tubs(G4String("HCalTube"),
                                            0,
											HCAL_Z_Scintilator / 2.0,
											HCAL_Z_Absorber / 2.0,
											0.,2*M_PI*rad);

	G4LogicalVolume* logVol_HCalAbsorber	= new G4LogicalVolume( HCalAbsorber, 	material_Cu, "LogVol_HCalAbsorber", 0, 0, 0 );
	G4LogicalVolume* logVol_HCalTube 		= new G4LogicalVolume( HCalTube, 	material_Scintilator, "LogVol_HCalTube", 0, 0, 0 );

	fScoringVol_HCal = logVol_HCalAbsorber;
	fScoringVol_SCI  = logVol_HCalTube;

    new G4PVPlacement(0, G4ThreeVector( 0,  0 , 0),
                      logVol_HCalAbsorber,
                      "PhysVol_HCalBox",
                      HCalTowerLogic,
                      0, 0, 0);
	new G4PVPlacement(0, G4ThreeVector( 0,  0 , 0),
				      logVol_HCalTube,
                      "PhysVol_HCalTube",
                      HCalTowerLogic,
                      0, 0, 0);
					  
	return HCalTowerLogic;
}
G4LogicalVolume* Geometry::ConstructShashlikTower(){
	
	G4NistManager* material_Man = G4NistManager::Instance();  //NistManager: start element destruction
	G4Material* material_air = G4Material::GetMaterial("G4_AIR");
 	G4Material* material_Cu = material_Man->FindOrBuildMaterial("G4_Cu");
	//Definition of the scintillator
	G4double density= 1.032 *g/cm3;       //to define the dencity on my own
	G4Element* elH = new G4Element("Hydrogen","H", 1, 1.00794 *g/mole);
	G4Element* elC = new G4Element("Carbon","C", 6, 12.011 *g/mole);
	G4Material* material_Scintilator = new G4Material("Scintilator",density,2);   //
	material_Scintilator->AddElement(elC,8);
	material_Scintilator->AddElement(elH,8);

    G4VSolid* HCalTower = new G4Box(G4String("HCalTower"),
                                    HCAL_X_Tower / 2.0,
                                    HCAL_Y_Tower / 2.0,
                                    HCAL_Z_Absorber / 2.0);

    G4LogicalVolume* HCalTowerLogic = new G4LogicalVolume(HCalTower,
                                                          material_air,
                                                          "HCalTowerLogic",
                                                          0, 0, 0);		  

  	//HCal Shashlik
  	G4Box* HCal_Absorber	= new G4Box("HCal_Absorber",	HCAL_X_Tower/2.0, HCAL_Y_Tower/2.0, HCAL_Z_Absorber/2.0);
  	G4Box* HCal_Scintilator	= new G4Box("HCal_Scintilator",	HCAL_X_Tower/2.0, HCAL_Y_Tower/2.0, HCAL_Z_Scintilator/2.0);
  	G4Box* HCal_Gap			= new G4Box("HCal_Gap",			HCAL_X_Tower/2.0, HCAL_Y_Tower/2.0, HCAL_Z_Gap/2.0);
	
  	G4LogicalVolume* logVol_HCal_Absorber	= new G4LogicalVolume( HCal_Absorber, 	 material_Cu, "logVol_HCal_Absorber",0,0,0);
  	G4LogicalVolume* logVol_HCal_Scintilator= new G4LogicalVolume( HCal_Scintilator, material_Scintilator,"logVol_HCal_Scintilator",0,0,0);
  	G4LogicalVolume* logVol_HCal_Gap		= new G4LogicalVolume( HCal_Gap, 		 material_air,	"logVol_HCal_Gap",0,0,0);

	fScoringVol_HCal = logVol_HCal_Absorber;
	fScoringVol_SCI  = logVol_HCal_Scintilator;

	for(G4int iHcalLayer = 0; iHcalLayer < HCALNumberOfLayers; iHcalLayer++){
		G4double position_Z_HCal_Absorber    = HCAL_Z_Absorber/2 + iHcalLayer*HCal_Layer_Thickness;
		G4double position_Z_HCal_Scintilator = HCAL_Z_Absorber + HCAL_Z_Scintilator/2 + iHcalLayer*HCal_Layer_Thickness;
		G4double position_Z_HCal_Gap     	 = HCAL_Z_Absorber + HCAL_Z_Scintilator + HCAL_Z_Gap/2 + iHcalLayer*HCal_Layer_Thickness;														  

		new G4PVPlacement(0, G4ThreeVector( 0,  0 , position_Z_HCal_Absorber),
						logVol_HCal_Absorber, 		
				 		"PhysVol_HCal_Absorber", 	 
						HCalTowerLogic, false, 0);
		new G4PVPlacement(0, G4ThreeVector( 0,  0 , position_Z_HCal_Scintilator), 
						logVol_HCal_Scintilator, 	
						"PhysVol_HCal_Scintilator", 
						HCalTowerLogic,false, 0);
		new G4PVPlacement(0, G4ThreeVector( 0,  0 , position_Z_HCal_Gap), 		 
						logVol_HCal_Gap, 			
						"PhysVol_HCal_Gap", 		 
						HCalTowerLogic, false, 0);
	}
			  
	return HCalTowerLogic;
}