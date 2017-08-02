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
#include "ProgramPropertyV.h"
#include "ParamEnteringV.h"
#include "SeparationAreaView.h"
#include "CreateObjectLines.h"
#include "VESelect.h"
//#include "G2DObjectV.h"
#include "InfinityLineV.h"
#include "G2DPointCutV.h"
#include "G2DApproxCalcV.h"

/*#include "AdditionalInfinityLine.h"
#include "AdditionalInfinityVGLine.h"
#include "AdditionalCut.h"
#include "AdditionalInfinityPerLine.h"
#include "AdditionalInfinityParLine.h"
#include "AdditionalDivLine.h"
#include "AdditionalBox.h"
#include "CreateObjectLinesFixidV.h"*/
#include "BaseToolV.h"

#include "MyViewV.h"
#include "Math.h"
#include "MyGL.h"
#include "G2DAngleLinkV.h"
#include "G2DGeomV.h"

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

                                        
#pragma link "VisCanvasView"
#pragma link "MyViewV"
#pragma resource "*.dfm"

TEditor2D *Editor2D;
MBTi PZOOM = 0.01;
MBTi EPSAngleMAX = M_PI/2.1;
MBTi EPSAngleMIN = M_PI/18;

T2DGObject TestObj1;
T2DGObject TestObj2;

__fastcall TEditor2D::TEditor2D(TComponent* Owner)
    :TForm(Owner)
{
    FInvalidated = false;
    MyView = new TMyView(Owner);
    MyView->Parent = this;
    MyView->Editor2D = this;
    MyView->Show();
    MyView->Align = alClient;
    for (int i = 0; i < 3; i++)
    {
        MyControls.Matrix.Add(new TMDelTList<TBaseTool>());
        MyControls.ActiveIndices.Add(new int(0));
    }

    MyControls.Matrix[2].Add(new TSelect);
    MyControls.Matrix[1].Add(new TCreateObjectLines());
/*    MyControls.Matrix[2].Add(new TAdditionalBox(false));
    MyControls.Matrix[2].Add(new TCreateObjectLinesFixid);
    MyControls.Matrix[1].Add(new TAdditionalInfinityLine);
    MyControls.Matrix[1].Add(new TAdditionalInfinityVGLine(0,1));
    MyControls.Matrix[1].Add(new TAdditionalInfinityVGLine(1,0));
    MyControls.Matrix[1].Add(new TAdditionalCut);
    MyControls.Matrix[1].Add(new TAdditionalInfinityPerLine);
    MyControls.Matrix[1].Add(new TAdditionalInfinityParLine);
    MyControls.Matrix[1].Add(new TAdditionalDivLine);
    MyControls.Matrix[1].Add(new TAdditionalBox(true));*/
    MyControls.Matrix[0].Add(new TSeparationAreaView);

    MyControls.ActiveList=0;

    for (int i=0;i<MyControls.Matrix.Count;i++)
    {
        TAction* Action = new TAction(AL);
        Action->ActionList = AL;
        Action->OnExecute = ActionExecute;
        Action->Tag = i;
        Action->AutoCheck = true;

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

    MyCursor.Position.z = DepthLevels.Selected;

/*    if (!MTID(typeid(TMyObject)))
        new TClassNode(NULL,typeid(TMyObject),true,NULL);

    if (!MTID(typeid(TMyRegObject)))
        new TClassNode(MTID(typeid(TMyObject)),typeid(TMyRegObject),true,NULL);

    new TClassNode(MTID(typeid(TMyObject)),typeid(TEditorAttributes),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TGridAttributes),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TMyCursor),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TGrid),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(TRedPoint),false,NULL);
    new TClassNode(MTID(typeid(TMyObject)),typeid(T2DGObject),false,NULL);
    new TClassNode(MTID(typeid(T2DGObject)),typeid(T2DGObject),false,NULL);
    new TClassNode(MTID(typeid(T2DGObject)),typeid(TInfinityLine),false,NULL);
*/
    T2DGObject();
    TInfinityLine();
    if (CHECK_FILE_LOAD("Attributes\\Attr.ini"))
    {
        TMemoryStream* MS = new TMemoryStream();
        MS->LoadFromFile("Attributes\\Attr.ini");
        Attributes.ReadData(MS);
        Grid.ReadData(MS);
        MyCursor.ReadData(MS);
        delete MS;
    }
    MyView->View->Color = Attributes.Colors.BackGround;
    MyView->View->BackgroundColor = Attributes.Colors.BackGround;
/*    MyView->CameraAction = 0;
    TBIdle->Action = MyView->IdleAction;
    TBMove->Action = MyView->MoveAction;
    TBRotate->Action = MyView->RotateAction;
    ToolBarV->Images = MyView->ImageListV;*/
//    MyView->EditorControls = &MyControls;
}

TIntVec TEditor2D::AllSnap(TIntVec Point, bool _GridSnap, bool _AdditionalLineSnap, bool TCFSnap, bool _Selected, bool AttributesGlobalForbit)
{
    Attributes.SnapValue = MyView->Factor(Attributes.SnapValuePix);
    if (!(Attributes.Snap && !AttributesGlobalForbit))
        return Point;
/*    if (Attributes.AdditionalFiguresSnap && _AdditionalLineSnap)
    {
        for (int i = 0; i < CustomFigures.Count; i++)
        {
            if (_Selected && Selection.FindFigure(CustomFigures.Items[i]) != -1)
                continue;
            if (typeid(CustomFigures[i]) == typeid(T2DGObject))
            {
                T2DGObject* CFi = (T2DGObject*)CustomFigures.Items[i];
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

MBTi TEditor2D::TestGrid()
{
    TIntVec CenterObj = TIntVec(MyView->Width/2,MyView->Height/2,0);
    TIntVec V = MyView->ScreenToProject(CenterObj);
    TIntVec P2 = MyView->ProjectToScreen(TIntVec(V.x+Grid.Attr.Step,V.y,V.z));
    TIntVec P3 = MyView->ProjectToScreen(TIntVec(V.x,V.y+Grid.Attr.Step,V.z));
    return MIN(MAX(fabs(P2.x-CenterObj.x), fabs(P3.x-CenterObj.x)),MAX(fabs(P2.y-CenterObj.y), fabs(P3.y-CenterObj.y)));
}

/*TIntVec TEditor2D::ScreenToProject(MBTi x, MBTi y, MBTi z)
{
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
}*/

void __fastcall TEditor2D::FormShow(TObject *Sender)
{
    if (MyView == NULL)
        return;
    ::SetFocus(MyView->Handle);
}

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
    MyControls.Exit(this);
    MyControls.ActiveList = Action->Tag ;
    ((TAction*)Action)->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::TBPropertyClick(TObject *Sender)
{
    ProgramProperty->ShowModal();
}
//---------------------------------------------------------------------------



void TEditor2D::EditorRender(TVisView *aView)
{
        glDepthMask(false);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
    if (Grid.Attr.ReBuild)
    {
        TIntVec CP1, CP2;
        if (PlaneCrossPoint(MyView->A, MyView->PlaneN, *MyView->View->Camera->LA_Position, TIntVec(*MyView->View->Camera->LA_Position)-MyView->PlaneN, CP1) &&
            PlaneCrossPoint(MyView->A, MyView->PlaneN, *MyView->View->Camera->LA_Position, *MyView->View->Camera->LA_LookAt, CP2))
        {
//            MBTi Angle = AngleRad(*View->Camera->LA_Position, CP, *View->Camera->LA_LookAt);
            MBTi Angle = asinDC((TIntVec(*MyView->View->Camera->LA_Position)-CP1).Length()/(TIntVec(*MyView->View->Camera->LA_Position)-CP2).Length());
            TIntVec BB[2];
            BB[0] = TIntVec(1<<20,1<<20,1<<20);
            BB[1] = BB[0]*(-1);
            if (Angle > EPSAngleMAX)
            {
                TIntVec V[4];
                V[0] = MyView->ScreenToProject(0,0,0);
                V[1] = MyView->ScreenToProject(0,MyView->Height,0);
                V[2] = MyView->ScreenToProject(MyView->Width,0,0);
                V[3] = MyView->ScreenToProject(MyView->Width, MyView->Height,0);
                for (int i = 0; i < 4; i++)
                {
                    UpdateMaxVector(BB[1],V[i]);
                    UpdateMinVector(BB[0],V[i]);
                }
                Grid.Attr.Minimal = false;
            } else
            {
                if (CustomFigures.Count < 1)
                {
                    BB[0] = BB[1] = ZEROINTVEC;
                }else
                    for ( int i = 0; i < CustomFigures.Count; i++)
                        for ( int j = 0; j < CustomFigures[i].VertexCount; j++)
                        {
                            UpdateMaxVector(BB[1],CustomFigures[i].GetVertex(j).Point);
                            UpdateMinVector(BB[0],CustomFigures[i].GetVertex(j).Point);
                        }
                BB[0] -= TIntVec(10,10,0);
                BB[1] += TIntVec(10,10,0);
                if (Angle < EPSAngleMIN)
                    Grid.Attr.Minimal = true;
                else
                    Grid.Attr.Minimal = false;
            }
            MBTi dist = TestGrid();
            Grid.Create(BB[0], BB[1], dist, DepthLevels.Grid);
            Grid.Attr.ReBuild = false;
        }
    }

    Grid.Render(MyView);

    //--------------
    TestObj1.Render(aView);
    TestObj2.Render(aView);
    //--------------
    for(int i = 0; i < CustomFigures.Count; i++)
        CustomFigures[i].Render(aView);

    if (MyView->CameraAction == 0)
        MyControls.Render(this);

    SB->Panels->Items[1]->Text = MyControls.Hint(this);
    FInvalidated = true;
}

void TEditor2D::EditorMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (MyView->CameraAction == 0)
        Grid.Attr.ReBuild = true;
}

void TEditor2D::EditorMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    MyCursor.Position = MyView->ScreenToProject(TIntVec(X, Y, DepthLevels.Selected));
    if (Shift.Contains(ssAlt))
    {
        ParamEntering->Param = MyCursor.Position;
        if ( ParamEntering->ShowModal() != mrOk )
            return;
        MyCursor.Position = ParamEntering->Param;
    }
    if (TBMove->Down)
    {
        
    }
    if (MyView->CameraAction == 0)
        MyControls.MouseDown(this, Button, Shift, MyCursor.Position);
}

void TEditor2D::EditorMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    MyCursor.Position = MyView->ScreenToProject(TIntVec(X, Y, DepthLevels.Selected));
    if (MyView->CameraAction == 0)
        MyControls.MouseUp(this, Button, Shift, MyCursor.Position);
}

void TEditor2D::EditorKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F2)
   {
        if (CHECK_FILE_SAVE("Attributes\\Figures.tsg"))
            CustomFigures.Save("Attributes\\Figures.tsg");
    }
    if (Key == VK_F3)
    {
        if (CHECK_FILE_LOAD("Attributes\\Figures.tsg"))
        {
            CustomFigures.Load("Attributes\\Figures.tsg");
            CustomFigures.RecurrentCheck();
        }
    }
    if (Key == VK_F2 && Shift.Contains(ssCtrl) )
    {
        if ( CHECK_FILE_SAVE("Attributes\\Export.gob") && CustomFigures.Count )
        {
            TGeomObject Obj;
            CustomFigures[0].ToGeomObject(&Obj);
            Obj.Write("Attributes\\Export.gob");
        }
    }
    if (Key == VK_F3 && Shift.Contains(ssCtrl) )
    {
        if (CHECK_FILE_LOAD("Attributes\\Import.gob"))
        {
            CustomFigures.Clear();
            TGeomObject Obj;
            Obj.Read("Attributes\\Import.gob");
            CustomFigures.Add(new T2DGObject());
            CustomFigures.Last()->FromGeomObject(&Obj);
        }
    }
    if (Key == VK_ADD || Key == VK_SUBTRACT)
    {
        Grid.Attr.ReBuild = true;
    }
    if (MyView->CameraAction == 0)
        MyControls.KeyDown(this, Key, Shift);
}

void TEditor2D::EditorKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (MyView->CameraAction == 0)
        MyControls.KeyUp(this, Key, Shift);
}

TIntVec RandomVec( MBTi XMin,MBTi XMax,MBTi YMin,MBTi YMax )
{
    return TIntVec( RandomRange(XMin*10000,XMax*10000)/10000.0,
                    RandomRange(YMin*10000,YMax*10000)/10000.0,0 );
}

void TEditor2D::PostRePaint()
{
    MyView->View->InvalidateGL();
    FInvalidated = false;
}

void TEditor2D::EditorMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if (!Invalidated)
        return;
	/*
    //--------------------------------------------------------------------------
    TestObj1.Clear();
    TestObj2.Clear();

    TestObj1.SnapPoints = false;
    TestObj1.PointPen.Color = clYellow;
    TestObj1.RibPen.Color = clYellow;
    TestObj2.SnapPoints = false;
    TestObj2.PointPen.Color = clRed;
    TestObj2.RibPen.Color = clRed;

    //база
    TIntVec Point1 = TIntVec(-1,0,0);
    TIntVec Point2 = TIntVec(1,0,0);
    MBTi Angl1 = 112.5;
    MBTi Angl2 = 112.5;
    TIntVec PositionPoint = TIntVec(0,3,0);//MyView->ScreenToProject(TIntVec(X, Y, 0));
//    MBTi LineBetweenPoints = 0.5;
    //--------------------------------------------------------------------------
    MBTi Angle_Of_Circle_Point = 180 - (180-Angl1) - (180-Angl2);

    TGPoint* GP1 = TestObj1.AddPoint( Point1 );
    TGPoint* GP2 = TestObj1.AddPoint( Point2 );
    TGPoint* GP = TestObj1.AddPoint( RandomVec( -2,2,-2,2 ) );

    TGCut* Cut1 = TestObj1.AddCut((TG2DPoint*)GP,GP1);
    TGCut* Cut2 = TestObj1.AddCut((TG2DPoint*)GP,GP2);
    TAngleLink* Link = (TAngleLink*)TestObj1.MakeAngleLink((TG2DCut*)Cut1,(TG2DCut*)Cut2,alsFirst);
    Link->Angle = Angle_Of_Circle_Point;

    TIntVec Just_Point = MyView->ScreenToProject(TIntVec(X, Y, 0));

    //Limacon
    TPascalLimacon PscLmcn;
    PscLmcn.Initialize(Point1,Point2,Angle_Of_Circle_Point,PositionPoint);
    PscLmcn.y = 90;
    PscLmcn.OffSet = Just_Point;
    //PscLmcn.OffSet = TIntVec(-0.01329429, -0.09465683, 0); //TIntVec(0,0,0);//
    PscLmcn.ToGeomObject_All(&TestObj1,360);

//    PscLmcn.Index = 0;
//    PscLmcn.ToGeomObject(&TestObj1,0,360,180);

//    PscLmcn.Index = 1;
//    PscLmcn.ToGeomObject(&TestObj1,0,360,360);

//    PscLmcn.Index = 2;
//    PscLmcn.ToGeomObject(&TestObj1,0,360,180);
//    PscLmcn.Index = 3;
//    PscLmcn.ToGeomObject(&TestObj2,0,360,180);
    //PscLmcn.y=0;

    //Simple Limacon
    TPascalLimacon SimpleLmcn;
    SimpleLmcn.a = 3;
    SimpleLmcn.l = 1.5;
    SimpleLmcn.y = 0;
    SimpleLmcn.ToGeomObject_All(&TestObj1,360);


    //DefinitionInterval
    MBTf Ar1 = 0;
    MBTf Ar2 = 360;
    //SimpleLmcn.Index = 1;
//    if ( SimpleLmcn.FindDefinitionInterval(Ar1,Ar2,MaxDivisionCount,MBTf_EPS) )
    {
//        TestObj2.AddPoint( SimpleLmcn.CalcPolarValue(Ar1) );
//        TestObj2.AddPoint( SimpleLmcn.CalcPolarValue(Ar2) );
  //      SimpleLmcn.ToGeomObject(&TestObj1,Ar1,Ar2,120);
    }


//    TFunctionCrossing FC;
//    FC.Initialize(PscLmcn,4,SimpleLmcn,4);
//    FC.ToGeomObject(&TestObj2,90,270,0,180);

    //Limacons Crossing
    TMDelTList<TIntVec> Roots;
    PscLmcn.CrossingWithLimacon(SimpleLmcn,Roots,MBTi_EPS);
    ListToGeomObject(&TestObj2,Roots,false);

    //ClosestPoint
    TIntVec Center = Just_Point;
    //TestObj2.AddPoint( PscLmcn.FindClosestPoint(Center) );

    //Circle
//  TPolarCircle PC;
//  PC.Radius = 2;
//  PC.Center = Center;
//  PC.ToGeomObject(&TestObj1,0,360,360);
//  TMDelTList<TIntVec> Roots;
//  PscLmcn.CrossingWithCircle(PC.Center,PC.Radius,Roots,MBTi_EPS);
//  ListToGeomObject(&TestObj2,Roots,false);
//    Center = TIntVec(1.831238, 1.595164, 0);
    //Line
//    TPolarLine PL;
//    PL.Initialize(Center,Center+TIntVec(0,1,0));
//    PL.ToGeomObject(&TestObj1,0,360,360);
//    TMDelTList<TIntVec> Roots;
//    PscLmcn.CrossingWithLine(Center,Center+TIntVec(0,1,0),Roots,MBTi_EPS);
//    ListToGeomObject(&TestObj2,Roots,false);



    //TestObj1.AddPoint( GP->Point );
    //TIntVec Sk1 =   PointOfLineOnCut(GP->Point,GP1->Point,-c1);
    //TestObj1.AddPoint( Sk1 );
    //Sk1 = PointOfLineOnCut(GP->Point,GP1->Point,c1);
    //TestObj1.AddPoint( Sk1 );
    //---------------------------------------------------------------
    //генерация петли
    TestObj1.Delete(Link);
    TestObj1.Delete(Cut1);
    TestObj1.Delete(Cut2);
    TestObj1.Delete(GP);
    TestObj1.Delete(GP1);
    TestObj1.Delete(GP2);
    PostRePaint();
    return;
    */
    //---------------------------------------------------------------
    //---------------------------------------------------------------
    //---------------------------------------------------------------
//    TIntVec SnapMousePos = llSnap(ObjectP, true, true, false, false);
    MyCursor.Position = MyView->ScreenToProject(TIntVec(X, Y, DepthLevels.Selected));
    TIntVec SMPS = MyCursor.Position;
//    TVarRec args[2] = {SMPS.x,SMPS.y};
    TVarRec args[3] = {SMPS.x, SMPS.y, SMPS.z};
    SB->Panels->Items[0]->Text = Format("X: %4.0f Y: %4.0f Z: %4.0f", args, 2);
    //---------------------------------------------------------------

    if (MyView->CameraAction == 0)
    {
        if (Shift.Contains(ssMiddle))
            Grid.Attr.ReBuild = true;
        MyControls.MouseMove(this, Shift, MyCursor.Position);
    }else
        if (Shift.Contains(ssLeft))
            Grid.Attr.ReBuild = true;
}






void __fastcall TEditor2D::TBViewAllClick(TObject *Sender)
{
    TIntVec AllBB[2];
    AllBB[0] = TIntVec(1<<20,1<<20,1<<20);
    AllBB[1] = AllBB[0]*(-1);
    for (int i = 0; i < CustomFigures.Count; i++)
        for (int j = 0; j < CustomFigures[i].VertexCount; j++)
        {
            UpdateMaxVector(AllBB[1],MyView->ProjectToScreen(CustomFigures[i].GetVertex(j).Point));
            UpdateMinVector(AllBB[0],MyView->ProjectToScreen(CustomFigures[i].GetVertex(j).Point));
        }
    TSeparationAreaView* SAV = (TSeparationAreaView*)MyControls.Matrix[0].IndexOf(0);
    SAV->Area(this, MyView, TIntVec(AllBB[0].x-10, AllBB[0].y-10, AllBB[0].z-10), TIntVec(AllBB[1].x+10, AllBB[1].y+10, AllBB[1].z+10), true);
    MyView->View->InvalidateGL();
}
//---------------------------------------------------------------------------




void __fastcall TEditor2D::ALUpdate(TBasicAction *_Action, bool &Handled)
{
    //без проверки
    TAction* Action = (TAction*)_Action;
//    Action->AutoCheck = true;
    int ind = Action->Tag;
        Action->ImageIndex =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].ImageId;
        Action->Caption =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].Description;
        Action->Hint =
            MyControls.Matrix[ind][MyControls.ActiveIndices[ind]].Description;
    Action->Checked = (ind == MyControls.ActiveList);
    Handled = true;
//    Action->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::TBZoomAddClick(TObject *Sender)
{
    MyView->A = TIntVec(*MyView->View->Camera->LA_LookAt);
    MyView->PlaneN = ( MyView->A - TIntVec(*MyView->View->Camera->LA_Position) ).Normalize();
    MBTi WheelDelta = 10;
    MyView->CameraEngine.Operation(MyView,coLA_DEPTH_TRANSLATION,MyView->ScreenToProject(MyView->Width/2, MyView->Height/2, 0),-MBTi(WheelDelta));
    MyView->View->InvalidateGL();
    MyView->A = ZEROINTVEC;
    MyView->PlaneN = TIntVec(0,0,-1);
    Grid.Attr.ReBuild = true;
}
//---------------------------------------------------------------------------

void __fastcall TEditor2D::TBZoomSubClick(TObject *Sender)
{
    MyView->A = TIntVec(*MyView->View->Camera->LA_LookAt);
    MyView->PlaneN = ( MyView->A - TIntVec(*MyView->View->Camera->LA_Position) ).Normalize();
    MBTi WheelDelta = -10;
    MyView->CameraEngine.Operation(MyView,coLA_DEPTH_TRANSLATION,MyView->ScreenToProject(MyView->Width/2, MyView->Height/2, 0),-MBTi(WheelDelta));
    MyView->View->InvalidateGL();
    MyView->A = ZEROINTVEC;
    MyView->PlaneN = TIntVec(0,0,-1);
    Grid.Attr.ReBuild = true;
}
//---------------------------------------------------------------------------


void __fastcall TEditor2D::FormResize(TObject *Sender)
{
    Grid.Attr.ReBuild = true;
}
//---------------------------------------------------------------------------




