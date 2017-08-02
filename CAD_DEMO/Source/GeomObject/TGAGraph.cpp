//---------------------------------------------------------------------------


#pragma hdrstop

#include "TGAGraph.h"
#include "TGObject.h"
#include "math.h"

//---------------------------------------------------------------------------
/*MBTi TGAGraph::MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way)
{
    if ( curN == B )
        return WayDepth;
    curN->Flags.Mark = gfTRUE;
    MBTi curMin = 1000000000;
    TGCut* curMinC = NULL;
    TMTList<TGCut> tmpway;
    for ( int i = 0; i < curN->CutsCount; i++ )
    {
        TGPoint* AnP = curN->GetCut(i).GetAnotherPoint(curN);
        if ( AnP->Flags.Mark == gfTRUE )
            continue;
        TMTList<TGCut> pcuts;
        MBTi tmp = MinWayRec(WayDepth+(curN->Point - AnP->Point).Length2D(), AnP, B, pcuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            curMinC = &curN->GetCut(i);
            tmpway.Assign(&pcuts);
        }
    }
    if ( curMinC != NULL )
    {
        way.Add(curMinC);
        for ( int i = 0; i <  tmpway.Count; i++)
            way.Add(tmpway.Items[i]);
        return curMin;
    } else
        return -1;
}*/

MBTi TGAGraph::MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way)
{
    if ( curN == B )
        return WayDepth;
    MBTi curMin = 1000000000;
    TGCut* curMinC = NULL;
    TMTList<TGCut> tmpway;
    for ( int i = 0; i < curN->CutsCount; i++ )
    {
        TGPoint* AnP = curN->GetCut(i).GetAnotherPoint(curN);
        if ( way.IndexOf(&curN->GetCut(i)) != -1 )
            continue;
        TMTList<TGCut> pcuts;
        pcuts.Assign(&way);
        pcuts.Add(&curN->GetCut(i));
        MBTi tmp = MinWayRec(WayDepth+(curN->Point - AnP->Point).Length2D(), AnP, B, pcuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            curMinC = &curN->GetCut(i);
            tmpway.Assign(&pcuts);
        }
    }
    if ( curMinC != NULL )
    {
/*        way.Add(curMinC);
        for ( int i = 0; i <  tmpway.Count; i++)
            way.Add(tmpway.Items[i]);*/
        way.Assign(&tmpway);
        return curMin;
    } else
        return -1;
}

/*MBTi TGAGraph::MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way, TMTList<TGPoint>& notUsed)
{
    if ( curN == B )
        return WayDepth;
    curN->Flags.Mark = gfTRUE;
    MBTi curMin = 1000000000;
    TGCut* curMinC = NULL;
    TMTList<TGCut> tmpway;
    for ( int i = 0; i < curN->CutsCount; i++ )
    {
        TGPoint* AnP = curN->GetCut(i).GetAnotherPoint(curN);
        if ( AnP->Flags.Mark == gfTRUE || notUsed.IndexOf(AnP) != -1 )
            continue;
        TMTList<TGCut> pcuts;
        MBTi tmp = MinWayRec(WayDepth+(curN->Point - AnP->Point).Length2D(), AnP, B, pcuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            curMinC = &curN->GetCut(i);
            tmpway.Assign(&pcuts);
        }
    }
    if ( curMinC != NULL )
    {
        way.Add(curMinC);
        for ( int i = 0; i <  tmpway.Count; i++)
            way.Add(tmpway.Items[i]);
        return curMin;
    } else
        return -1;
}*/

MBTi TGAGraph::MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way, TMTList<TGPoint>& notUsed)
{
    if ( curN == B )
        return WayDepth;
    MBTi curMin = 1000000000;
    TGCut* curMinC = NULL;
    TMTList<TGCut> tmpway;
    for ( int i = 0; i < curN->CutsCount; i++ )
    {
        TGPoint* AnP = curN->GetCut(i).GetAnotherPoint(curN);
        if ( way.IndexOf(&curN->GetCut(i)) != -1 || notUsed.IndexOf(AnP) != -1 )
            continue;
        TMTList<TGCut> pcuts;
        pcuts.Assign(&way);
        pcuts.Add(&curN->GetCut(i));
        MBTi tmp = MinWayRec(WayDepth+(curN->Point - AnP->Point).Length2D(), AnP, B, pcuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            curMinC = &curN->GetCut(i);
            tmpway.Assign(&pcuts);
        }
    }
    if ( curMinC != NULL )
    {
/*        way.Add(curMinC);
        for ( int i = 0; i <  tmpway.Count; i++)
            way.Add(tmpway.Items[i]);*/
        way.Assign(&tmpway);
        return curMin;
    } else
        return -1;
}

bool ExistList(TMTList<TGCut>& List, TMDelTList< TMTList<TGCut> >& Lists)
{
    for ( int i = 0; i < Lists.Count; i++ )
    {
        if ( Lists[i].Count != List.Count )
            continue;
        int j;
        for ( j = 0; j < List.Count; j++ )
        {
            int ggg = 0;
            if ( List.Items[j] && Lists.Items[i] && Lists[i].Items[j] )
            {
                ggg = Lists.Count;
            }
            if ( List.Items[j] != Lists[i].Items[j] )
                break;
        }
        if ( j == List.Count )
            return true;
    }
    return false;
}

MBTi TGAGraph::NextMinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way, TMDelTList< TMTList<TGCut> >& NUWays, TMTList<TGPoint>& notUsed)
{
    if ( curN == B )
        return WayDepth;
    MBTi curMin = 1000000000;
    TGCut* curMinC = NULL;
    TMTList<TGCut> tmpway;
    for ( int i = 0; i < curN->CutsCount; i++ )
    {
        TGPoint* AnP = curN->GetCut(i).GetAnotherPoint(curN);
        if ( way.IndexOf(&curN->GetCut(i)) != -1 || ( notUsed.IndexOf(AnP) != -1 && AnP != B) )
            continue;
        TMTList<TGCut> pcuts;
        pcuts.Assign(&way);
        pcuts.Add(&curN->GetCut(i));
        MBTi tmp = NextMinWayRec(WayDepth+(curN->Point - AnP->Point).Length2D(), AnP, B, pcuts, NUWays, notUsed);
        if ( tmp != -1 && tmp < curMin && !ExistList(pcuts, NUWays) )
        {
            curMin = tmp;
            curMinC = &curN->GetCut(i);
            tmpway.Assign(&pcuts);
        }
    }
    if ( curMinC != NULL )
    {
/*        way.Add(curMinC);
        for ( int i = 0; i <  tmpway.Count; i++)
            way.Add(tmpway.Items[i]);*/
        way.Assign(&tmpway);
        return curMin;
    } else
        return -1;
}

MBTi TGAGraph::MinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way, TMTList<TGPoint>& notUsed)
{
    go.FillPointsFlags(flMARK, gfFALSE);
    return MinWayRec(0, A, B, way, notUsed);
}

MBTi TGAGraph::MinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way)
{
    go.FillPointsFlags(flMARK, gfFALSE);
    return MinWayRec(0, A, B, way);
}

MBTi TGAGraph::NextMinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way, TMDelTList< TMTList<TGCut> >& NUWays, TMTList<TGPoint>& notUsed)
{
    go.FillPointsFlags(flMARK, gfFALSE);
    return NextMinWayRec(0, A, B, way, NUWays, notUsed);
}

MBTi TGAGraph::LenghtWay(TMTList<TGCut>& way)
{
    MBTi res = 0;
    for ( int i = 0; i < way.Count; i++ )
        res += (way[i].Src->Point - way[i].Dst->Point).Length2D();
    return res;
}

MBTi TGAGraph::LenghtWay(TMTList<TGCut>& way, TMTList<MBTi>& weights)
{
    MBTi res = 0;
    for ( int i = 0; i < way.Count; i++ )
        res += weights[go.FCuts.IndexOf(way.Items[i])];
    return res;
}

bool TGAGraph::NodeExistWay(TGPoint* Node, TMTList<TGCut>& way)
{
    for ( int i = 0; i < way.Count; i++ )
        if ( way[i].Src == Node || way[i].Dst == Node )
            return true;
    return false;
}

void TGAGraph::GetBool(unsigned long int n, int CountBit, TMTList<int>& way)
{
    way.Clear();
    unsigned long int t = 1;
    for ( int i = 0; i < CountBit; i++ )
    {
        if ( t & n )
            way.Add(new int(1));
        else
            way.Add(new int(0));
        t = t<<1;
    }
}

MBTi TGAGraph::MinPassByNodesRec(TGPoint* A, TMTList<TGCut>& way)
{
    int i;
    for ( i = 0; i < go.FVertex.Count; i++ )
    {
        int j;
        for ( j = 0; j < way.Count; j++ )
            if ( way[j].Src == go.FVertex.Items[i] || way[j].Dst == go.FVertex.Items[i] )
                break;
        if ( j == way.Count )
            break;
    }
    if ( i == go.FVertex.Count )
        return LenghtWay(way);
//------------------------------------------------------------------------------
    MBTi curMin = 1000000000;
    TMTList<TGCut> MWay;
    TMTList<TGCut> pcuts;
    for ( int i = 0; i < A->CutsCount; i++ )
    {
        TGPoint* AnP = A->GetCut(i).GetAnotherPoint(A);
        if ( NodeExistWay(AnP, way) )
            continue;
        pcuts.Add(&A->GetCut(i));

/*        TMTList<TGCut> tmpway;
        tmpway.Assign(&way);
        tmpway.Add(&A->GetCut(i));
        MBTi tmp = MinPassByNodesRec(AnP, tmpway);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            MWay.Assign(&tmpway);
        }*/
    }
/*    for ( int i = 0; i < pow(2,pcuts.Count); i++ )
    {
        TMTList<int> Bits;
        GetBool(i, pcuts.Count, Bits);
        TMTList<TGCut> tmpCuts;
        for ( int j = 0; j < pcuts.Count; j++ )
            if ( Bits[j] )
                tmpCuts.Add(pcuts.Items[j]);
        MBTi tmp = MinPassByNodesRec(AnP, tmpCuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            MWay.Assign(&tmpCuts);
        }
    }*/
//------------------------------------------------------------------------------
    if ( curMin != 1000000000 )
    {
        way.Assign(&MWay);
        return curMin;
    } else
        return -1;
}

bool TGAGraph::TrueWayRec(TGPoint* Node, TGPoint* cur, TMTList<TGCut>& way)
{
    if ( cur == Node )
        return true;
    for ( int i = 0; i < cur->CutsCount; i++ )
    {
        if ( cur->GetCut(i).Flags.Mark == gfFALSE && way.IndexOf(&cur->GetCut(i)) != -1 )
        {
            TGPoint* AnP = cur->GetCut(i).GetAnotherPoint(cur);
            cur->GetCut(i).Flags.Mark = gfTRUE;
            if ( TrueWayRec(Node, AnP, way) )
                return true;
        }
    }
    return false;
}

MBTi TGAGraph::MinPassByNodesRec1(TGPoint* A, TMTList<TGCut>& way)
{
    MBTi curMin = 1000000000;
    TMTList<TGCut> MWay;
    for ( int i = 0; i < pow(2,go.FCuts.Count); i++ )
    {
        TMTList<int> Bits;
        GetBool(i, go.FCuts.Count, Bits);
        TMTList<TGCut> tmpCuts;
        for ( int j = 0; j < go.FCuts.Count; j++ )
            if ( Bits[j] )
                tmpCuts.Add(go.FCuts.Items[j]);
        //----------------------------------------
        int j;
        for ( j = 0; j < go.FVertex.Count; j++ )
        {
            int k;
            for ( k = 0; k < tmpCuts.Count; k++ )
                if ( tmpCuts[k].Src == go.FVertex.Items[j] || tmpCuts[k].Dst == go.FVertex.Items[j] )
                    break;
            if ( k == tmpCuts.Count )
                break;
        }
        if ( j < go.FVertex.Count )
            continue;
        for ( j = 0; j < tmpCuts.Count; j++ )
        {
            go.FillCutsFlags(tmpCuts, flMARK, gfFALSE);
            if ( !TrueWayRec(A, tmpCuts[j].Src, tmpCuts) )
                break;
        }
        if ( j < tmpCuts.Count )
            continue;
        //----------------------------------------
        MBTi tmp = LenghtWay(tmpCuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            MWay.Assign(&tmpCuts);
        }
    }
    way.Assign(&MWay);
    return curMin;
}

MBTi TGAGraph::MinPassByMainsNodesRec(TGPoint* A, TMTList<TGCut>& way, TMTList<TGPoint>& Mains)
{
    MBTi curMin = 1000000000;
    TMTList<TGCut> MWay;
    for ( int i = 0; i < pow(2,go.FCuts.Count); i++ )
    {
        TMTList<int> Bits;
        GetBool(i, go.FCuts.Count, Bits);
        TMTList<TGCut> tmpCuts;
        for ( int j = 0; j < go.FCuts.Count; j++ )
            if ( Bits[j] )
                tmpCuts.Add(go.FCuts.Items[j]);
        //----------------------------------------
        if ( tmpCuts.Count < Mains.Count - 1 )
            continue;
        int j;
        for ( j = 0; j < Mains.Count; j++ )
        {
            int k;
            for ( k = 0; k < tmpCuts.Count; k++ )
                if ( tmpCuts[k].Src == Mains.Items[j] || tmpCuts[k].Dst == Mains.Items[j] )
                    break;
            if ( k == tmpCuts.Count )
                break;
        }
        if ( j < Mains.Count )
            continue;
        for ( j = 0; j < tmpCuts.Count; j++ )
        {
            go.FillCutsFlags(tmpCuts, flMARK, gfFALSE);
            if ( !TrueWayRec(A, tmpCuts[j].Src, tmpCuts) )
                break;
        }
        if ( j < tmpCuts.Count )
            continue;
        //----------------------------------------
        MBTi tmp = LenghtWay(tmpCuts);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            MWay.Assign(&tmpCuts);
        }
    }
    way.Assign(&MWay);
    return curMin;
}

bool TGAGraph::ExistCycle(TMTList<TGCut>& way)
{
    TMDelTList< TMTList<TGCut> > tmp;
    go.Polygonize2d(way, tmp);
    if ( tmp.Count == 0 )
        return false;
    else
        return true;
}

/*MBTi TGAGraph::MinPassByMainsNodesRec(TGPoint* A, TMTList<TGCut>& way, TMTList<TGPoint>& Mains)
{
    if ( way.Count >= Mains.Count - 1 )
    {
        int j;
        for ( j = 0; j < Mains.Count; j++ )
            if ( !NodeExistWay(Mains.Items[j], way) )
                break;
        if ( j == Mains.Count )
        {
            for ( j = 0; j < way.Count; j++ )
            {
                go.FillCutsFlags(way, flMARK, gfFALSE);
                if ( !TrueWayRec(Mains.Items[0], way[j].Src, way) )
                    break;
            }
            if ( j == way.Count )
                return LenghtWay(way);
        }
    }
//------------------------------------------------------------------------------
    MBTi curMin = 1000000000;
    TMTList<TGCut> MWay;
    TMTList<TGCut> pcuts;
    for ( int i = 0; i < A->CutsCount; i++ )
    {
        TGPoint* AnP = A->GetCut(i).GetAnotherPoint(A);
        if ( NodeExistWay(AnP, way) )
            continue;
        pcuts.Add(&A->GetCut(i));
    }
    for ( int i = 0; i < pow(2,pcuts.Count); i++ )
    {
        TMTList<int> Bits;
        GetBool(i, pcuts.Count, Bits);
        TMTList<TGCut> tmpCuts;
        tmpCuts.Assign(&way);
        for ( int j = 0; j < pcuts.Count; j++ )
            if ( Bits[j] )
                tmpCuts.Add(pcuts.Items[j]);
        for ( int j = 0; j < tmpCuts.Count; j++ )
        {
            TGPoint* AnP = tmpCuts[j].GetAnotherPoint(A);
            MBTi tmp = MinPassByMainsNodesRec(AnP, tmpCuts, Mains);
            if ( tmp != -1 && tmp < curMin )
            {
                curMin = tmp;
                MWay.Assign(&tmpCuts);
            }
        }
    }
//------------------------------------------------------------------------------
    if ( curMin != 1000000000 )
    {
        way.Assign(&MWay);
        return curMin;
    } else
        return -1;
}*/
MBTi TGAGraph::MinPassByNodesRec1(TGPoint* A, TMTList<TGCut>& way, TMTList<MBTi>& weights)
{
    MBTi curMin = 1000000000;
    TMTList<TGCut> MWay;
    for ( int i = 0; i < pow(2,go.FCuts.Count); i++ )
    {
        TMTList<int> Bits;
        GetBool(i, go.FCuts.Count, Bits);
        TMTList<TGCut> tmpCuts;
        for ( int j = 0; j < go.FCuts.Count; j++ )
            if ( Bits[j] )
                tmpCuts.Add(go.FCuts.Items[j]);
        //----------------------------------------
        int j;
        for ( j = 0; j < go.FVertex.Count; j++ )
        {
            int k;
            for ( k = 0; k < tmpCuts.Count; k++ )
                if ( tmpCuts[k].Src == go.FVertex.Items[j] || tmpCuts[k].Dst == go.FVertex.Items[j] )
                    break;
            if ( k == tmpCuts.Count )
                break;
        }
        if ( j < go.FVertex.Count )
            continue;
        for ( j = 0; j < tmpCuts.Count; j++ )
        {
            go.FillCutsFlags(tmpCuts, flMARK, gfFALSE);
            if ( !TrueWayRec(A, tmpCuts[j].Src, tmpCuts) )
                break;
        }
        if ( j < tmpCuts.Count )
            continue;
        //----------------------------------------
        MBTi tmp = LenghtWay(tmpCuts, weights);
        if ( tmp != -1 && tmp < curMin )
        {
            curMin = tmp;
            MWay.Assign(&tmpCuts);
        }
    }
    way.Assign(&MWay);
    return curMin;
}

void TGAGraph::MinPassByNodes(TGPoint* A, TMTList<TGCut>& way)
{
    MinPassByNodesRec1(A, way);
}

void TGAGraph::MinPassByNodes(TGPoint* A, TMTList<TGCut>& way, TMTList<MBTi>& weights)
{
    MinPassByNodesRec1(A, way, weights);
}

void TGAGraph::MinPassByMainsNodes(TGPoint* A, TMTList<TGCut>& way, TMTList<TGPoint>& Mains)
{
    MinPassByMainsNodesRec(A, way, Mains);
}

#pragma package(smart_init)
