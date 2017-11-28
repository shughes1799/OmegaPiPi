

void CrossSection()
{

  Double_t AtomicM = 1.00794/;   //g/mol
  Double_t Density = 0.7177;  //g/cm^3
  Double_t Length = 40;   //cm
  Double_t Avog = 6.02214e23;  //mol^-1
  Double_t Yield = 240000;
  //Double_t Flux = 507*10e6;  //events not photons
  Double_t Flux = 4.2e8*16;  //Photon flux for 1 batch

  Double_t Acc = 82363;
  Double_t Raw = 8435831;
  Double_t Acceptance = Acc/Raw;

  Double_t CrossSec;

  CrossSec = (AtomicM/(Density*Length*Avog))*(Yield/(Flux*Acceptance));

  cout << "Cross Section " << CrossSec << endl;
  

}
