//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "math.h"
#include <Poligon.h>
#include "EditorV.h"

#include "Controls.hpp"
//---------------------------------------------------------------------------
#include "G2DObjectV.h"
#include "ProgramPropertyV.h"
#include "ParamEnteringV.h"
#include "SeparationAreaView.h"
#include "CreateObjectLines.h"
#include "Select.h"
#include "InfinityLineV.h"
/*#include "AdditionalInfinityLine.h"
#include "AdditionalInfinityVGLine.h"
#include "AdditionalCut.h"
#include "AdditionalInfinityPerLine.h"
#include "AdditionalInfinityParLine.h"
#include "AdditionalDivLine.h"
#include "AdditionalBox.h"
#include "CreateObjectLinesFixidV.h"*/
#include "BaseToolV.h"

#pragma package(smart_init)
#pragma link "VisAttr"
#pragma link "VisCam"
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisComp"
#pragma link "VisMat"
#pragma link "VisObj"
#pragma link "VisPrimitiveObj"
#pragma link "VisShape"
#pragma link "VisView"
#pragma link "VisLight"
#pragma link "VisTex"

#pragma link "VisGeom"
#pragma link "VisCustomObj"

#pragma resource "*.dfm"

TEditor2D *Editor2D;
MBTi PZOOM = 0.01;

__fastcall TEditor2D::TEditor2D(TComponent* Owner)
    :TForm(Owner)
{
    View->DrawValues = TVisDrawValues()<<dvRed<<dvGreen<<dvBlue<<dvAlpha;
    MyControls.Matrix.Add(new TMDelTList<TBaseTool>());
    MyControls.Matrix.Add(new TMDelTList<TBaseTool>());
    MyControls.Matrix.Add(new TMDelTList<TBaseTool>());

    MyControls.Matrix[2].Add(new TSelect);
    MyControls.Matrix[1].Add(new TCreateObjectLines());
//    MyControls.Matrix[2].Add(new TAdditionalBox(false));
//    MyControls.Matrix[2].Add(new TCreateObjectLinesFixid);
/*    MyControls.Matrix[1].Add(new TAdditionalInfinityLine);
    MyControls.Matrix[1].Add(new TAdditionalInfinityVGLine(0,1));
    MyControls.Matrix[1].Add(new TAdditionalInfinityVGLine(1,0));
    MyControls.Matrix[1].Add(new TAdditionalCut);
    MyControls.Matrix[1].Add(new TAdditionalInfinityPerLine);
    MyControls.Matrix[1].Add(new TAdditionalInfinityParLine);
    MyControls.Matrix[1].Add(new TAdditionalDivLine);
    MyControls.Matrix[1].Add(new TAdditionalBox(true));*/
    MyControls.Matrix[0].Add(new TSeparationAreaView);

    MyControls.ActiveIndices.Add(new int(0));
    MyControls.ActiveIndices.Add(new int(0));
    MyControls.ActiveIndices.Add(new int(0));
    MyControls.ActiveList=0;

    for (int i=0;i<MyControls.Matrix.Count;i++)
    {
        TAction* Action = new TAction(AL);
        Action->ActionList = AL;
        Action->OnExecute = ActionExecute;
        Action->Tag = i;

        TToolButton* TB = new TToolButton(this);
        if (MyControls.Matrix[i].Count>1)
        {
            TB->Style = tbsDropDown;
            TPopupMenu* PM = new TPopupMenu(this);
            TB->DropdownMenu = PM;
            PM->Images = ImageList;
            PM->Tag = i;
            for (int j=0;j<MyControls.Matrix[i].Count;j++)
            {
                TMenuItem* MI = new TMenuItem(PM);
                MI->Caption = MyControls.Matrix[i][j].Description;
                MI->ImageIndex = MyControls.Matrix[i][j].ImageId;
                MI->OnClick = PopupMenuItemClick ;
                PM->Items->Add(MI);
                MI->Tag = j;
            }
        }
        else
        {
            TB->Style = tbsButton;
        }
        TB->Action = Action;
        TB->Parent = ToolBar;
    }

    MyCursor.Position.z = 0;//55;

    //-----------------------------------
    //-----------------------------------

/*    if (!MTID(typeid(TMyObject)))
        new TClassNode(NULL,typeid(TMyObject),true,NULL);

    if (!MTID(typeid(TMyRegObject)))
        new TClassNode(MTID(typeid(TMyObject)),typeid(TMyRegObject),true,NULL);

    new TClassNode(MTID(typeid(TMyObject)),typeid(TEditorAttributes),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TGridAttributes),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TMyCursor),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TGrid),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TRedPoint),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TMyFigure),false,NULL);
    new TClassNode(MTID(typeid(TMyFigure)),typeid(TCustomFigure),false,NULL);
    new TClassNode(MTID(typeid(TMyFigure)),typeid(TInfinityLine),false,NULL);
*/
    if (CHECK_FILE_LOAD("Attributes\\Attr.ini"))
    {
        TMemoryStream* MS = new TMemoryStream();
        MS->LoadFromFile("Attributes\\Attr.ini");
        Attributes.ReadData(MS);
        Grid.ReadData(MS);
        MyCursor.ReadData(MS);
        delete MS;
    }
    A = TIntVec(0,0,0);
    PlaneN = TIntVec(0,0,1);
}

TIntVec TEditor2D::AllSnap(TIntVec Point, bool _GridSnap, bool _AdditionalLineSnap, bool TCFSnap, bool _Selected, bool AttributesGlobalForbit)
{
    Attributes.SnapValue = fabs(ScreenToProject(Attributes.SnapValuePix, 0, 0).x - ScreenToProject(0, 0, 0).x);
    if (!(Attributes.Snap && !AttributesGlobalForbit))
        return Point;
/*    if (Attributes.AdditionalFiguresSnap && _AdditionalLineSnap)
    {
        for (int i = 0; i < CustomFigures.Count; i++)
        {
            if (_Selected && Selection.FindFigure(CustomFigures.Items[i]) != -1)
                continue;
            if (typeid(CustomFigures[i]) == typeid(TCustomFigure))
            {
                TCustomFigure* CFi = (TCustomFigure*)CustomFigures.Items[i];
                for (int j = 0; j < CFi->CutsCount; j++)
                    LinesAndCuts.Add(new TLinesAndCuts(CFi->GetCut(j).Src->Point, CFi->GetCut(j).Dst->Point, false, CFi->Additional));
            }
            if (typeid(CustomFigures[i]) == typeid(TInfinityLine))
            {
                TInfinityLine* ILi = (TInfinityLine*)CustomFigures.Items[i];
                for (int j = 0; j < ILi->CutsCount; j++)
                     LinesAndCuts.Add(new TLinesAndCuts(ILi->GetCut(j).Src->Point, ILi->GetCut(j).Dst->Point, true, true));
            }
        }
        for (int i = 0; i < LinesAndCuts.Count-1; i++)
            for (int j = i+1; j < LinesAndCuts.Count; j++)
            {
                  if (!LinesAndCuts[i].Additional && !LinesAndCuts[j].Additional)
                      continue;
                  TIntVec V;
                  int ICC = -1;
                  if (!LinesAndCuts[i].Infinity && !LinesAndCuts[j].Infinity)
                      ICC = IsCutsCrossedExactly(LinesAndCuts[i].Point1,
                                                 LinesAndCuts[i].Point2,
                                                 LinesAndCuts[j].Point1,
                                                 LinesAndCuts[j].Point2,V);
                  if (LinesAndCuts[i].Infinity && !LinesAndCuts[j].Infinity)
                      ICC = IsLineAndCutCrossedExactly(LinesAndCuts[i].Point1,
                                                       LinesAndCuts[i].Point2,
                                                       LinesAndCuts[j].Point1,
                                                       LinesAndCuts[j].Point2,V);
                  if (!LinesAndCuts[i].Infinity && LinesAndCuts[j].Infinity)
                      ICC = IsLineAndCutCrossedExactly(LinesAndCuts[j].Point1,
                                                       LinesAndCuts[j].Point2,
                                                       LinesAndCuts[i].Point1,
                                                       LinesAndCuts[i].Point2,V);
                  if (LinesAndCuts[i].Infinity && LinesAndCuts[j].Infinity)
                      ICC = IsLinesCrossedExactly(LinesAndCuts[i].Point1,
                                                  LinesAndCuts[i].Point2,
                                                  LinesAndCuts[j].Point1,
                                                  LinesAndCuts[j].Point2,V);
                  if (ICC == lcCROSSING || ICC == lcCOMMONPOINT)
                  {
                        MBTi SV = 10;
                        MBTi SVF = fabs(ScreenToProject(SV,0,0).x - ScreenToProject(0,0,0).x);
                        if (V.Equal2D(Point,SVF))
                        {
                            LinesAndCuts.Clear();
                            return V;
                        }
                  }
            }
        LinesAndCuts.Clear();
    }*/
    if ((Attributes.AdditionalFiguresSnap || AttributesGlobalForbit) && _AdditionalLineSnap)
    {
        for (int i = 0; i < CustomFigures.Count-1; i++)
            for (int j = i+1; j < CustomFigures.Count; j++)
                if (CustomFigures[i].Additional || CustomFigures[j].Additional)

                    for (int n = 0; n < CustomFigures[i].CutsCount; n++)
                        for (int m = 0; m < CustomFigures[j].CutsCount; m++)
                        {
                            TIntVec V;
                            int ICC = -1;
                            if (typeid(CustomFigures[i]) != typeid(TInfinityLine) && typeid(CustomFigures[j]) != typeid(TInfinityLine))
                                ICC = IsCutsCrossedExactly(CustomFigures[i].GetCut(n).Src->Point,
                                                           CustomFigures[i].GetCut(n).Dst->Point,
                                                           CustomFigures[j].GetCut(m).Src->Point,
                                                           CustomFigures[j].GetCut(m).Dst->Point, V);
                            if (typeid(CustomFigures[i]) == typeid(TInfinityLine) && typeid(CustomFigures[j]) != typeid(TInfinityLine))
                                ICC = IsLineAndCutCrossedExactly(CustomFigures[i].GetCut(n).Src->Point,
                                                                 CustomFigures[i].GetCut(n).Dst->Point,
                                                                 CustomFigures[j].GetCut(m).Src->Point,
                                                                 CustomFigures[j].GetCut(m).Dst->Point, V);
                            if (typeid(CustomFigures[i]) != typeid(TInfinityLine) && typeid(CustomFigures[j]) == typeid(TInfinityLine))
                                ICC = IsLineAndCutCrossedExactly(CustomFigures[j].GetCut(m).Src->Point,
                                                                 CustomFigures[j].GetCut(m).Dst->Point,
                                                                 CustomFigures[i].GetCut(n).Src->Point,
                                                                 CustomFigures[i].GetCut(n).Dst->Point, V);
                            if (typeid(CustomFigures[i]) == typeid(TInfinityLine) && typeid(CustomFigures[j]) == typeid(TInfinityLine))
                                ICC = IsLinesCrossedExactly(CustomFigures[j].GetCut(m).Src->Point,
                                                            CustomFigures[j].GetCut(m).Dst->Point,
                                                            CustomFigures[i].GetCut(n).Src->Point,
                                                            CustomFigures[i].GetCut(n).Dst->Point, V);
                            if (ICC == lcCROSSING || ICC == lcCOMMONPOINT)
                            {
                                if (V.Equal2D(Point,Attributes.SnapValue))
                                    return V;
                            }
                        }
    }
    TIntVec V;
    int CutIndex;
//    if (Attributes.AdditionalFiguresSnap && _AdditionalLineSnap || )
        for (int i = 0; i < CustomFigures.Count; i++)
            if ((CustomFigures[i].Additional && (Attributes.AdditionalFiguresSnap || AttributesGlobalForbit) && _AdditionalLineSnap) ||  (!CustomFigures[i].Additional && TCFSnap && (Attributes.SnapMyFigures || AttributesGlobalForbit)))
            {
                if (_Selected && Selection.FindFigure(CustomFigures.Items[i]) != -1)
                    continue;
                if (CustomFigures[i].Snap(Point, V, CutIndex, Attributes.SnapValue, typeid(CustomFigures[i]) == typeid(TInfinityLine)))
                        return V;
            }
    if ((Grid.Attr.Snap || AttributesGlobalForbit) && _GridSnap)
        return Grid.Snap(Point);
    return Point;
}

bool TEditor2D::AllFigureSnap(TIntVec Point, TIntVec& P1, TIntVec& P2, bool _AdditionalLineSnap, bool TCFSnap)
{
    bool BoolCF = false;
    int MFIndex;
    TIntVec P;
    int CutIndex;
    if (Attributes.AdditionalFiguresSnap && _AdditionalLineSnap)
        for (int i = 0; i < CustomFigures.Count && !BoolCF; i++)
            if (CustomFigures[i].Additional || (TCFSnap && Attributes.SnapMyFigures))
            if ( typeid(CustomFigures[i]) == typeid(TInfinityLine) )
            {
                BoolCF = CustomFigures[i].Snap(Point, P, CutIndex, Attributes.SnapValue, true);
                MFIndex = i;
            }else
            {
                BoolCF = CustomFigures[i].Snap(Point, P, CutIndex, Attributes.SnapValue, false);
                MFIndex = i;
            }
    if (BoolCF)
    {
        P1 = CustomFigures[MFIndex].GetCut(CutIndex).Src->Point;
        P2 = CustomFigures[MFIndex].GetCut(CutIndex).Dst->Point;
    }
    return BoolCF;
}

void TEditor2D::TestGrid(const TIntVec &V1,const TIntVec &V2)
{
    TIntVec P1 = ProjectToScreen(TIntVec(0,0,0));
    TIntVec P2 = ProjectToScreen(TIntVec(Grid.Attr.Step,0,0));
    double dist =fabs(P2.x-P1.x);
    if (dist <= Grid.Attr.SwitchEpsilon)
        Grid.Attr.ChangeMinToMax = true;
    else
        if (dist/Grid.Attr.Multiplier > Grid.Attr.Multiplier)
            Grid.Attr.ChangeMaxToMin = true;
}

void __fastcall TEditor2D::ViewRender(TVisView *aView)
{
    VisAttributes1->Render(aView);
    VisLight1->Render(aView);

    if (Grid.Attr.ReBuild)
    {
        TIntVec V1 = ScreenToProject(0,View->Height,0);
        TIntVec V2 = ScreenToProject(View->Width,0,0);
        TestGrid(V1,V2);
        Grid.Create(V1, V2, DepthLevels.Grid);
        Grid.Attr.ReBuild = false;
    }

    Grid.Render(Editor2D);
    for(int i = 0; i < CustomFigures.Count; i++)
        CustomFigures[i].Render( Editor2D->View );
    MyControls.Render(Editor2D);

    SB->Panels->Items[1]->Text = MyControls.Hint(Editor2D);
}

void TEditor2D::WinFrom3D(const TIntVec& P1,TIntVec& RES)
{
/*    TVisMathVector V;
    gluProject(P1.x,P1.y,P1.z,ModMat,ProjMat,ViewPort,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (ViewPort[3]-ViewPort[1])-V.y;
    RES.z = V.z;  */
}

bool TEditor2D::WinTo3D(int X,int Y,double value,TIntVec& RES)
{
/*    GLdouble  px,py,pz;
    GLint really;
    bool returned=false;
    really = ViewPort[3] - (GLint)Y-1;
    if (gluUnProject((GLdouble)X,(GLdouble)really,value,ModMat,ProjMat,ViewPort,&px,&py,&pz)==GL_TRUE)
        returned=true;
    RES.x = px;
    RES.y = py;
    RES.z = pz;
    return(returned); */
}

TIntVec TEditor2D::ScreenToProject(MBTi x, MBTi y, MBTi z)
{
/*    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec P1, P2;
    WinTo3D( floor(x), floor(y), 0, P1);
    WinTo3D( floor(x), floor(y), 10, P2);
    TIntVec Res;
    PlaneCrossPoint( A, PlaneN, P1, P2, Res);
    return Res;   */
    MBTi k;
    if(View->Height < View->Width)
        k = VisOrtCam->ViewHeight / View->Height;
    else
        k = VisOrtCam->ViewWidth / View->Width;
    TIntVec V;
    V.x = (x - View->Width / 2) * k;
    V.y = ((View->Height - y) - View->Height / 2) * k;
    V.z = z;

    return  V - TIntVec(VisOrtCam->Transformation->Translation->X,VisOrtCam->Transformation->Translation->Y,z);
}

TIntVec TEditor2D::ScreenToProject(const TIntVec& V)
{
    return  ScreenToProject(V.x, V.y, V.z);
}

TIntVec TEditor2D::ProjectToScreen(const TIntVec& Vv)
{
/*    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec Res;
    WinFrom3D(Vv, Res);
    return Res;     */
    MBTi k;
    if(View->Height < View->Width)
        k = View->Height / VisOrtCam->ViewHeight;
    else
        k = View->Width / VisOrtCam->ViewWidth;
    TIntVec P;
    TIntVec V = Vv + TIntVec(VisOrtCam->Transformation->Translation->X,VisOrtCam->Transformation->Translation->Y,10);
    P.x = V.x * k + View->Width / 2;
    P.y = View->Height-(V.y * k + View->Height / 2);
    P.z = Vv.z;
    return  P;
}

void __fastcall TEditor2D::ViewClick(TObject *Sender)
{
//    MainCF.AddCut(ScreenToProject(random(View->Width),random(View->Height)),ScreenToProject(random(View->Width),random(View->Height)));
////    TPoint P = ScreenToClient(Mouse->CursorPos);
////    MainCF.AddPoint(ScreenToProject(P));
//    View->InvalidateGL();
}
//---------------------------------------------------------------------------
void __fastcall TEditor2D::ViewMouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (Grid.Attr.Step > Grid.Attr.ZoomLimit && WheelDelta<0)
        return;
    if (Grid.Attr.Step < (MBTi)1/Grid.Attr.ZoomLimit && WheelDelta>0)
        return;
    TIntVec V = ScreenToProject( TIntVec(View->ScreenToClient(MousePos).x,View->ScreenToClient(MousePos).y,0) );

    MBTi wd = MBTi(WheelDelta);
    VisOrtCam->ViewWidth -= wd*Grid.Attr.ZoomStep*VisOrtCam->ViewWidth;
    VisOrtCam->ViewHeight -= wd*Grid.Attr.ZoomStep*VisOrtCam->ViewHeight;

    TIntVec V1 = ScreenToProject( TIntVec(View->ScreenToClient(MousePos).x,View->ScreenToClient(MousePos).y,0)) - V;


    VisOrtCam->Transformation->Translation->incX(V1.x);
    VisOrtCam->Transformation->Translation->incY(V1.y);
    Grid.Attr.ReBuild = true;
}



//---------------------------------------------------------------------------

void __fastcall TEditor2D::FormShow(TObject *Sender)
{
    ::SetFocus(View->Handle);
}

void __fastcall TEditor2D::ViewMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MyCursor.Position = ScreenToProject(TIntVec(X,Y,MyCursor.Position.z));
    if (Shift.Contains(ssAlt))
    {
        ParamEntering->Param = MyCursor.Position;
        if ( ParamEntering->ShowModal() != mrOk )
            return;
        MyCursor.Position = ParamEntering->Param;
    }
    MyControls.MouseDown(Editor2D, Button, Shift,MyCursor.Position);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ViewMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MyCursor.Position.x = ScreenToProject(TIntVec(X,Y,0)).x;
    MyCursor.Position.y = ScreenToProject(TIntVec(X,Y,0)).y;
    MyControls.MouseUp(Editor2D, Button, Shift,MyCursor.Position);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F2)
   {
        if (CHECK_FILE_SAVE("Attributes\\Figures.dat"))
        {
            TMemoryStream* MS = new TMemoryStream();
            CustomFigures.WriteData(MS);
            MS->SaveToFile("Attributes\\Figures.dat");
            delete MS;

/*            TMDelTList<TCustomFigure> RealCustomFigures;
            TMDelTList<TInfinityLine> RealInfinityLines;
            for ( int i = 0; i < CustomFigures.Count; i++)
                if (typeid(CustomFigures[i]) == typeid(TCustomFigure))
                {
                    TCustomFigure* CF = (TCustomFigure*)CustomFigures.Items[i];
                    RealCustomFigures.Add(CF);
                }else if (typeid(CustomFigures[i]) == typeid(TInfinityLine))
                {
                    TInfinityLine* IL = (TInfinityLine*)CustomFigures.Items[i];
                    RealInfinityLines.Add(IL);
                }

//            RealCustomFigures.Save("Attributes\\Figures.dat");
// //            RealInfinityLines.Save("Attributes\\Figures.dat");
            TMemoryStream* MS = new TMemoryStream();
            RealCustomFigures.WriteData(MS);
            RealInfinityLines.WriteData(MS);
            MS->SaveToFile("Attributes\\Figures.dat");
            delete MS;

            RealCustomFigures.NoDelClear();
            RealInfinityLines.NoDelClear();
//            CustomFigures.Save("Attributes\\Figures.dat");  */
        }
    }
    if (Key == VK_F3)
    {
        if (CHECK_FILE_LOAD("Attributes\\Figures.dat"))
        {
            CustomFigures.Clear();
            TMemoryStream* MS = new TMemoryStream();
            MS->LoadFromFile("Attributes\\Figures.dat");
            CustomFigures.ReadData(MS);
            View->InvalidateGL();
            delete MS;

/*            TMDelTList<TCustomFigure> RealCustomFigures;
            TMDelTList<TInfinityLine> RealInfinityLines;
//            RealCustomFigures.Load("Attributes\\Figures.dat");
////            RealInfinityLines.Load("Attributes\\Figures.dat");
            MS->LoadFromFile("Attributes\\Figures.dat");
            RealCustomFigures.ReadData(MS);
            RealInfinityLines.ReadData(MS);

            for (int i=0; i < RealCustomFigures.Count; i++)
                CustomFigures.Add(RealCustomFigures.Items[i]);

            for (int i=0; i < RealInfinityLines.Count; i++)
                CustomFigures.Add(RealInfinityLines.Items[i]);

            for ( int i = 0; i < CustomFigures.Count; i++)
                CustomFigures[i].CreateView();
            RealCustomFigures.NoDelClear();
            RealInfinityLines.NoDelClear();
            delete MS; */
//            CustomFigures.Load("Attributes\\Figures.dat");
/*            TMemoryStream* MS = new TMemoryStream();
            MS->LoadFromFile("Attributes\\Figures.dat");
            CustomFigures.ReadData(MS);
            delete MS;*/
        }
    }
    if (Key == VK_F4)
        if ( CHECK_FILE_LOAD("Attributes\\Figures.imp") )
        {
            CustomFigures.Clear();
            TGeomObject GO;
            TMemoryStream* MS = new TMemoryStream();
            MS->LoadFromFile("Attributes\\Figures.imp");
            GO.ReadData(MS);
            GO.CheckFields();
            T2DGObject* G2D = new T2DGObject();
            G2D->ImportGO(&GO);
            CustomFigures.Add( G2D );
            G2D->CreateView();
            View->InvalidateGL();
            delete MS;
        }
    MyControls.KeyDown(Editor2D, Key, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ViewKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    MyControls.KeyUp(Editor2D, Key, Shift);
}
//---------------------------------------------------------------------------





void __fastcall TEditor2D::PopupMenuItemClick(TObject *Sender)
{
    if ( Sender->ClassType() == __classid(TMenuItem) )
    {
        TMenuItem* MI = (TMenuItem*)Sender;
        TMenu* Menu = MI->GetParentMenu();
        MyControls.ActiveList = Menu->Tag;
        MyControls.ActiveIndices[Menu->Tag] = MI->Tag;
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ApplicationEventsActionUpdate(
      TBasicAction *_Action, bool &Handled)
{
    //без проверки
    TAction* Action = (TAction*)_Action;
    int ind = Action->Tag;
        Action->ImageIndex =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].ImageId;
        Action->Caption =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].Description;
        Action->Hint =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].Description;
    Action->Checked = (ind == MyControls.ActiveList);
    Action->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ActionExecute(TObject *Sender)
{
    //Без этого action not enabled
    int i = 0;
    //Без этого появляется ворнинг
    if (i) i++;
}
//---------------------------------------------------------------------------


void __fastcall TEditor2D::ALExecute(TBasicAction *Action, bool &Handled)
{
    MyControls.Exit(Editor2D);
    MyControls.ActiveList = Action->Tag ;
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ViewResize(TObject *Sender)
{
    Grid.Attr.ReBuild = true;
    View->InvalidateGL();
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ViewMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    TPoint P(X,Y);
    TIntVec ObjectP = ScreenToProject(TIntVec(P.x,P.y,0));
    TIntVec V = ObjectP - ScreenToProject(TIntVec(OldPoint.x, OldPoint.y, 0));
    //---------------------------------------------------------------
//    TIntVec SnapMousePos = llSnap(ObjectP, true, true, false, false);
    TIntVec SMPS = MyCursor.Position;
    TVarRec args[2] = {SMPS.x,SMPS.y};
    SB->Panels->Items[0]->Text = Format("X: %4.2f Y: %4.2f", args, 1);
    //---------------------------------------------------------------
    if (Shift.Contains(ssMiddle) && (VisOrtCam->Transformation->Translation->X <= 1000000 || V.x<=0)
                                 && (VisOrtCam->Transformation->Translation->X >= -1000000 || V.x>0)
                                 && (VisOrtCam->Transformation->Translation->Y <= 1000000 || V.y<=0)
                                 && (VisOrtCam->Transformation->Translation->Y >= -1000000 || V.y>0))
    {
        VisOrtCam->Transformation->Translation->incX(V.x);
        VisOrtCam->Transformation->Translation->incY(V.y);
        View->InvalidateGL();
        Grid.Attr.ReBuild = true;
    }
    OldPoint.x = X;
    OldPoint.y = Y;

    MyCursor.Position.x = ScreenToProject(TIntVec(X,Y,0)).x;
    MyCursor.Position.y = ScreenToProject(TIntVec(X,Y,0)).y;
    MyControls.MouseMove(Editor2D, Shift,MyCursor.Position);

}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::ToolButton1Click(TObject *Sender)
{
    ProgramProperty->ShowModal();
}
//---------------------------------------------------------------------------


