// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef TasksQueueVH
#define TasksQueueVH
//---------------------------------------------------------------------------
#include "QueueRoutineV.h"
class COMMONAL_API TTaskQueue : public TElementQueue {
public:
    TTaskQueue(){};
    virtual ~TTaskQueue(){};
    void Register(TElement* Element);
    void ActionCame();
};

extern COMMONAL_API TTaskQueue TaskQueue;
#endif
