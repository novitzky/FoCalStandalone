
#include "EventAction.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "Analysis.hh"
#include "Randomize.hh"
#include <iomanip>
#include "RootIO.hh"
#include "constants.hh"

EventAction::EventAction()
    : G4UserEventAction()
{}


EventAction::~EventAction()
{
    RootIO::GetInstance()->Close();
}

G4int eventNum=0;
void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
    eventNum++;
    G4cout << "Event = " << eventNum <<G4endl;
	
	//Zero out all the deposit in teh beginning of the event
    for(G4int i = 0; i < NpixX*NpixY*NumberPIX; i++){
		sum_eDep_PIX[i]=0;
	}
	for(G4int i = 0; i < NpadX*NpadY*NumberPAD; i++){
		sum_eDep_PAD[i] = 0;
	}	
	for(G4int i = 0; i < HCALNumberOfLayers*HCALNumberOfTowersX*HCALNumberOfTowersX; i++){
		sum_eDep_SCI[i] = 0;
	}
	sum_eDep_EMCAL=0;
	sum_eDep_HCAL=0;
	sum_eDep_LEAK=0;
	sum_eDep_Gap=0;
	
	RootIO::GetInstance()->Clear();
}

void EventAction::EndOfEventAction(const G4Event* event)
    //************************************
{
	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
	RootIO::GetInstance()->WriteEvent(eventNum);
	
    for(G4int ilayer = 0; ilayer < NumberPIX; ilayer++){
		for(int iy = 0; iy < NpixY; iy++){
			for(int ix = 0; ix < NpixX; ix++){
				G4int i = ix + NpixX*iy + NpixX*NpixY*ilayer;
		        GetSumPIX(i);
				analysisManager->FillH1(0,i,GetSumPIX(i));
				if(GetSumPIX(i)){	
					//if(ilayer == 0) G4cout << i << "  " << ilayer << "  " << ix << "  " << iy << "   " << GetSumPIX(i) << G4endl;
			        RootIO::GetInstance()->WritePix(i, GetSumPIX(i));
				}
			}
		}
	}
	for(G4int ilayer = 0; ilayer < NumberPAD; ilayer++){
		for(int iy = 0; iy < NpadY; iy++){
			for(int ix = 0; ix < NpadX; ix++){
				G4int i = ix + NpadX*iy + NpadX*NpadY*ilayer;
		        GetSumPAD(i);
				//if(ilayer == 7) G4cout << i << "  " << ilayer << "  " << ix << "  " << iy << "   " << GetSumPAD(i) << G4endl;
				if(GetSumPAD(i)){
					//if(ilayer==0) G4cout << i << "  " << ilayer << "  " << ix << "  " << iy << "   " << GetSum(i) << G4endl;
			        RootIO::GetInstance()->WritePad(i, GetSumPAD(i));					
				}
			}
		}		
    }
	for(G4int iHcalLayer = 0; iHcalLayer < HCALNumberOfLayers; iHcalLayer++){
		for(G4int TowerX = 0; TowerX < HCALNumberOfTowersX; TowerX++){
			for(G4int TowerY = 0; TowerY < HCALNumberOfTowersY; TowerY++){
				G4int i = iHcalLayer + TowerX*HCALNumberOfLayers + TowerY*HCALNumberOfTowersX*HCALNumberOfLayers;
				GetSumSCI(i);
				//if(GetSumSCI(i)>0) G4cout << iHcalLayer << "   " << GetSumSCI(i) << G4endl;
				RootIO::GetInstance()->WriteSci(i, GetSumSCI(i));	
			}
		}
	}

	//G4cout << GetEMCal() << "  " << GetHCal() << "  " << GetLeak() << G4endl;
	RootIO::GetInstance()->WriteEMCal( GetEMCal() );
	RootIO::GetInstance()->WriteHCal( GetHCal() );
	RootIO::GetInstance()->WriteLeak( GetLeak() );
	RootIO::GetInstance()->WriteLeak( GetGap() );

    G4PrimaryVertex* primaryVertex = event->GetPrimaryVertex();
	G4cout << primaryVertex->GetX0() << " " << primaryVertex->GetY0() << "  " << primaryVertex->GetZ0() << G4endl;
    G4PrimaryParticle* primaryParticle = primaryVertex->GetPrimary();
    G4double ke = primaryParticle->GetKineticEnergy();
	G4double x = primaryVertex->GetX0();
	G4double y = primaryVertex->GetY0();
	G4double z = primaryVertex->GetZ0();
    G4double px = primaryParticle->GetPx();
    G4double py = primaryParticle->GetPy();
    G4double pz = primaryParticle->GetPz();
    G4double en = primaryParticle->GetTotalEnergy();
	RootIO::GetInstance()->WriteParticleKinematics(px, py, pz, en);
	RootIO::GetInstance()->WriteVertex(x, y, z);
    RootIO::GetInstance()->Fill();
    //*****************************************
}
