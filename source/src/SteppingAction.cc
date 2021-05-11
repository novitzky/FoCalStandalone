

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "Geometry.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "Analysis.hh"

G4int I=0;
G4double NTRACK[10];
G4double COPYNUM[10];


SteppingAction::SteppingAction(EventAction* eventAction)
    : G4UserSteppingAction(),
    fEventAction(eventAction),
    fScoringVol_EMCal1(0),
    fScoringVol_EMCal2(0),
    fScoringVol_HCal(0),
    fScoringVol_PAD(0),
    fScoringVol_PIX(0),
    fScoringVol_SCI(0),
    fScoringVol_Leak(0)
{}


SteppingAction::~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
    if ( 	!fScoringVol_EMCal1 || !fScoringVol_EMCal2 || 
			!fScoringVol_PAD || !fScoringVol_PIX || 
			!fScoringVol_HCal || !fScoringVol_HCal || 
			!fScoringVol_Leak ) {
        const Geometry* geometry
            = static_cast<const Geometry*>
            (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
        
		fScoringVol_EMCal1 = geometry->GetScoringVol_EMCal1();
		fScoringVol_EMCal2 = geometry->GetScoringVol_EMCal2();
		fScoringVol_HCal = geometry->GetScoringVol_HCal();
		
		fScoringVol_PAD = geometry->GetScoringVol_PAD();
        fScoringVol_PIX = geometry->GetScoringVol_PIX();
        fScoringVol_SCI = geometry->GetScoringVol_SCI();
		
        fScoringVol_Leak = geometry->GetScoringVol_Leak();
    }

    // Get PreStepPoint and TouchableHandle objects
    G4StepPoint* preStepPoint=step->GetPreStepPoint();
    G4TouchableHandle theTouchable = preStepPoint->GetTouchableHandle();
    G4LogicalVolume* volume = theTouchable->GetVolume()->GetLogicalVolume();
    G4String volumeName = theTouchable->GetVolume()->GetName();
    G4int copyNo = theTouchable->GetCopyNumber();
	
	auto pos = step->GetPreStepPoint()->GetPosition();

    if (volume != fScoringVol_PAD 
		&& volume != fScoringVol_PIX
		&& volume != fScoringVol_EMCal1
		&& volume != fScoringVol_EMCal2
		&& volume != fScoringVol_HCal
		&& volume != fScoringVol_SCI
		&& volume != fScoringVol_Leak	 ) return;
    //==========================================================================
    G4ThreeVector position_World = preStepPoint->GetPosition();
    G4ThreeVector position_Local = theTouchable->GetHistory()->GetTopTransform().TransformPoint(position_World);
	G4double edepStep = step->GetTotalEnergyDeposit();
    //==========================================================================
	auto analysisManager=G4AnalysisManager::Instance();
	G4int eventID = 0;
    const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
    if(evt) eventID = evt->GetEventID();
	if(edepStep > 0){
	    if (volume == fScoringVol_PAD){
	        fEventAction->AddeDepPAD(copyNo-IDnumber_PAD_First, edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,0);
		    //analysisManager->AddNtupleRow();
	    } else if(volume == fScoringVol_PIX){
			G4int ix = (pos.x()+PIX_MiniFoCal_X/2)/PIX_X;
			G4int iy = (pos.y()+PIX_MiniFoCal_Y/2)/PIX_Y;
			int id = iy + ix*NpixY;			
	        fEventAction->AddeDepPIX(id,edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,0);
		    //analysisManager->AddNtupleRow();
			//G4cout << edepStep << G4endl;
	    } else if(volume == fScoringVol_EMCal1 || volume == fScoringVol_EMCal2){
			fEventAction->AddEMCal(edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,1);
		    //analysisManager->AddNtupleRow();
		} else if(volume == fScoringVol_HCal ){
			fEventAction->AddHCal(edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,2);
		    //analysisManager->AddNtupleRow();
		} else if(volume == fScoringVol_SCI ){
			G4int ix = (pos.x()+HCalSizeX/2)/HCAL_X_Tower;
			G4int iy = (pos.y()+HCalSizeY/2)/HCAL_Y_Tower;
			int id = iy + ix*HCALNumberOfTowersY;
			fEventAction->AddeDepSCI(id, edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,3);
		    //analysisManager->AddNtupleRow();
		} else if(volume == fScoringVol_Leak){
			fEventAction->AddLeak(edepStep);
		    //analysisManager->FillNtupleDColumn(0,eventID);
		    //analysisManager->FillNtupleDColumn(1,edepStep);
		    //analysisManager->FillNtupleDColumn(2,pos.x());
		    //analysisManager->FillNtupleDColumn(3,pos.y());
		    //analysisManager->FillNtupleDColumn(4,pos.z());
			//analysisManager->FillNtupleDColumn(5,4);
		    //analysisManager->AddNtupleRow();
		}
	}

}
