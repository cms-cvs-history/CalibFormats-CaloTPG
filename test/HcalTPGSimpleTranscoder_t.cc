#include "CalibFormats/CaloTPG/interface/HcalTPGSimpleTranscoder.h"
#include <iostream>

int main() {
  int hcal=250;
  int egamma=500;
  int jet=1000;
  
  HcalTPGSimpleTranscoder tc(hcal,egamma,jet);

  IntegerCaloSamples in, eg, jcs;
  
  in=IntegerCaloSamples(HcalTrigTowerDetId(1,1),10);
  const int values[10]={0,1,10,50,100,250,500,1000,5000,10000};
  for (int i=0; i<10; i++) in[i]=values[i];

  HcalTriggerPrimitiveDigi digi;
  std::vector<bool> fg(10,false);
  tc.htrCompress(in,fg,digi);
  tc.rctEGammaUncompress(digi,eg);
  tc.rctJetUncompress(digi,jcs);

  std::cout << "Tables:\n";
  tc.printTable();

  std::cout << "\nInput:\n" << in;
  std::cout << "\nDigi:\n" << digi;  
  std::cout << "\nE/Gamma:\n" << eg;  
  std::cout << "\nJet:\n" << jcs;  


}
