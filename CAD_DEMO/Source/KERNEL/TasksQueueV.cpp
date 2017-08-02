//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
                
#include "TasksQueueV.h"
#include "AUIV.h"
#include "ElementV.h"

//---------------------------------------------------------------------------
TTaskQueue TaskQueue;

void TTaskQueue::Register(TElement* Element)
{
    if (AddList.Count + ElementList.Count == 0)
        AUI.InvalidateView();
    //простейшая оптимизация т.к. чаще всего изменения одновременно
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
				AnsiString("<TTaskQueue::ActionCame>: Очередь задач: сбой на <")+ElementList.GetCurrent()->ADR->Name+AnsiString(">"),
				Clear();
	       );
}

#pragma package(smart_init)
