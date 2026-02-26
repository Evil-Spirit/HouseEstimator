// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
                
#include "TasksQueueV.h"
#include "AUIV.h"
#include "ElementV.h"

//---------------------------------------------------------------------------
TTaskQueue TaskQueue;

void TTaskQueue::Register(TElement* Element)
{
    if (AddList.Count + ElementList.Count == 0)
        AUI.InvalidateView();
    //ïðîñòåéøàÿ îïòèìèçàöèÿ ò.ê. ÷àùå âñåãî èçìåíåíèÿ îäíîâðåìåííî
    if ( AddList.Count==0 || AddList.Last()->TargetID != Element->IntId )
        Add(Element);
}

void TTaskQueue::ActionCame()
{
		_TRY_
				while(AddList.Count || RemoveList.Count)
				{
						CreateQueue();
						for ( bool OK = ElementList.Start();OK;OK = ElementList.Next() )
								ElementList.GetCurrent()->ADR->ProcessTasks(NULL);
						ElementList.Clear();
				}
		_ENDTRY_(
				AnsiString("<TTaskQueue::ActionCame>: Î÷åðåäü çàäà÷: ñáîé íà <")+ElementList.GetCurrent()->ADR->Name+AnsiString(">"),
				Clear();
	       );
}

