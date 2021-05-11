
#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "constants.hh"

/// Event action class
class EventAction : public G4UserEventAction
{
public:
  EventAction();
  virtual ~EventAction();

  virtual void    BeginOfEventAction(const G4Event* event);
  virtual void    EndOfEventAction(const G4Event* event);
    
	inline void AddeDepPAD(G4int i, G4double de) {
        sum_eDep_PAD[i] += de;
    }
    inline G4double GetSumPAD(G4int i){
        return sum_eDep_PAD[i];
    }

    inline void AddeDepPIX(G4int i, G4double de) { 
        sum_eDep_PIX[i] += de;
    }
    inline G4double GetSumPIX(G4int i){ 
        return sum_eDep_PIX[i];
    }

    inline void AddeDepSCI(G4int i, G4double de) { 
        sum_eDep_SCI[i] += de;
    }
    inline G4double GetSumSCI(G4int i){ 
        return sum_eDep_SCI[i];
    }

    inline void AddEMCal(G4double de) { 
        sum_eDep_EMCAL += de;
    }
    inline G4double GetEMCal(){ 
        return sum_eDep_EMCAL;
    }
	
    inline void AddHCal(G4double de) { 
        sum_eDep_HCAL += de;
    }
    inline G4double GetHCal(){ 
        return sum_eDep_HCAL;
    }
    
	inline void AddGap(G4double de) { 
        sum_eDep_Gap += de;
    }
    inline G4double GetGap(){ 
        return sum_eDep_Gap;
    }
	
    inline void AddLeak(G4double de) { 
        sum_eDep_LEAK += de;
    }
    inline G4double GetLeak(){ 
        return sum_eDep_LEAK;
    }
	
private:
  G4double  sum_eDep_PAD[NpadX*NpadY*NumberPAD];
  G4double  sum_eDep_PIX[NpixX*NpixY*NumberPIX];
  G4double  sum_eDep_SCI[HCALNumberOfLayers*HCALNumberOfTowersX*HCALNumberOfTowersX];

  G4double  sum_eDep_EMCAL;
  G4double  sum_eDep_HCAL;
  G4double  sum_eDep_LEAK;
  G4double  sum_eDep_Gap;
  G4double  num_photon;

};

#endif
