//
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
/// \file persistency/P01/include/RootIO.hh
/// \brief Definition of the RootIO class
//
#ifndef INCLUDE_ROOTIO_HH 
#define INCLUDE_ROOTIO_HH 1

// Include files
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"
#include "TSystem.h"

#include "EventAction.hh"
#include "constants.hh"

/** @class RootIO
 *   
 *
 *  
 */

/// Root IO implementation for the persistency example

class RootIO 
{
public: 
  virtual ~RootIO();
  
  static RootIO* GetInstance();
  void WriteEvent(int e);
  void WritePad(int i, double a);
  void WritePix(int i, double a);
  void WriteSci(int i, double a);
  void WriteEMCal(double a);
  void WriteHCal(double a);
  void WriteLeak(double a);
  void WriteGap(double a);
  void WriteParticleKinematics(double px, double py, double pz, double en);
  void WriteVertex(double x, double y, double z);
  void Fill();
  void Clear();
  void Close();

protected:
  RootIO(); 
  
private:
	
  int event;
  double data_pad[NpadX*NpadY*NumberPAD];
  double data_pix[NpixX*NpixY*NumberPIX];
  double data_sci[HCALNumberOfLayers*HCALNumberOfTowersX*HCALNumberOfTowersX];
  double emcal;
  double hcal;
  double leakage;
  double gap;
  double particle_px;
  double particle_py;
  double particle_pz;
  double particle_en;
  double vertex_x;
  double vertex_y;
  double vertex_z;
  TFile* fFile;
  TTree * fHitTree;
  int fNevents;
  
};
#endif // INCLUDE_ROOTIO_HH
