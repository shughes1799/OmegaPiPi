
void rootlogon(){

   
    
    //gROOT->SetStyle("Plain");
    //gStyle->SetStatX(0.7);
    //gStyle->SetStatW(0.2);
    //gStyle->SetLabelOffset(1.2);
    //gStyle->SetLabelFont(72);

    ////Manage Palette Contours//////
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
    /////////////////////
    
    
    gStyle->SetOptFit(1111111);
    gStyle->SetOptStat(00000);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetStatY(0.50);
    gStyle->SetStatX(0.95);
    gStyle->SetStatW(0.25);
    gStyle->SetStatH(0.2);
    gStyle->SetLabelSize(0.05,"X");
    gStyle->SetTitleSize(0.06,"X");
    gStyle->SetTitleOffset(0.90,"X");

    gStyle->SetNdivisions(505,"Y");
    gStyle->SetNdivisions(505,"X");

    gStyle->SetLabelSize(0.05,"Y");
    gStyle->SetTitleSize(0.06,"Y");
    gStyle->SetTitleOffset(0.85,"Y");
    // Show functions in red...
    gStyle->SetFuncColor(2);


    gStyle->SetCanvasDefH(500);
    gStyle->SetCanvasDefW(750);
    gStyle->SetCanvasDefX(10);
    gStyle->SetCanvasDefY(10);
    
    
    int style_label_font=42;
    gStyle->SetLabelFont(style_label_font,"xyz");
    //gStyle->SetLabelSize(0.045,"xyz");
    //gStyle->SetLabelOffset(0.015,"xyz");
    gStyle->SetStatFont(style_label_font);
    gStyle->SetTitleFont(style_label_font,"xyz"); // axis titles
    gStyle->SetTitleFont(style_label_font,"h"); // histogram title
    //gStyle->SetTitleSize(0.05,"xyz"); // axis titles
    //gStyle->SetTitleSize(0.05,"h"); // histogram title
    //gStyle->SetTitleOffset(1.1,"x");
    //gStyle->SetTitleOffset(1.2,"y");
    
    //gStyle->SetStripDecimals(kFALSE); // if we have 1.5 do not set 1.0 -> 1
    TGaxis::SetMaxDigits(3); // restrict the number of digits in labels

    //gStyle->SetTitleX(0.12); // spot where histogram title goes
    gStyle->SetTitleW(0.78); // width computed so that title is centered
    gStyle->SetFrameLineWidth(1);
    gStyle->SetFuncWidth(2);
    gStyle->SetHistLineWidth(1);
    gStyle->SetPadTopMargin(0.08);
    gStyle->SetPadBottomMargin(0.13);
    gStyle->SetPadLeftMargin(0.12);
    gStyle->SetPadRightMargin(0.12);
    
    /*// Set Data/Stat/... and other options
    gStyle->SetOptDate(0);
    gStyle->SetDateX(0.01);
    gStyle->SetDateY(0.01);
    gStyle->SetOptFile(0);
    gStyle->SetOptFit(111);
    gStyle->SetOptLogx(0);
    gStyle->SetOptLogy(0);
    gStyle->SetOptLogz(0);
    gStyle->SetOptStat(1110);// no histogram title
    gStyle->SetStatFormat("6.4f");
    gStyle->SetFitFormat("6.4f");
    gStyle->SetStatStyle(0); // hollow
    //gStyle->SetStatStyle(1001); // filled
    gStyle->SetStatBorderSize(0);
    gStyle->SetStatW(0.25);
    gStyle->SetStatH(0.125);
    //gStyle->SetStatX(0.90);
    //gStyle->SetStatY(0.90);
    gStyle->SetStatX(1.0-gStyle->GetPadRightMargin()-0.02);
    gStyle->SetStatY(1.0-gStyle->GetPadTopMargin()-0.02);
    gStyle->SetOptTitle(1);
    // Set tick marks and turn off grids
    //gStyle->SetNdivisions(1005,"xyz");
    gStyle->SetNdivisions(510,"xyz");
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetTickLength(0.02,"xyz");
    gStyle->SetPadGridX(0);
    gStyle->SetPadGridY(0);
*/
    
    gROOT->ForceStyle();
    //gStyle->SetFillStyle(1001);
    // gStyle->SetFillColor(kYellow);

}
