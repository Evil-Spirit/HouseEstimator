//---------------------------------------------------------------------------

#ifndef AllAttributesVH
#define AllAttributesVH
//---------------------------------------------------------------------------
class TGridAttributes : public TMyObject{
public:
    TGridAttributes();
    virtual ~TGridAttributes(){};
    bool Snap;
    MBTi Step;
//    MBTi TolCut;
    MBTi ZoomStep;
    int SwitchEpsilon;
    int Multiplier;
    int SnapStep;
    int ZoomLimit;
    TGridColors Colors;
    TGridLineWidth LinesWidth;
    bool Visible;
    bool ChangeMinToMax, ChangeMaxToMin;
    bool ReBuild;
};
#endif
