//---------------------------------------------------------------------------

#ifndef SelectH
#define SelectH
//---------------------------------------------------------------------------

#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "QueueRoutineV.h"

#define NO_HIT			0
#define	ROTATION_TOOL	1
#define	UPDOWN_TOOL		2

class COMMONAL_API TSelection : public TElementQueue{
private:
	TMTList<TVisPrimitiveObj> FObjects;
	virtual void OnChange();
	bool NeedToCreateSelView;
	bool NeedToPositionSelView;
	static TVisPrimitiveObj *RotationTool;
	static TVisPrimitiveObj *UpDownTool;
	static int UpDownToolPrimitives;
	static int RotationToolPrimitives;
	static TVisMaterial *Red;
	static TVisMaterial *Green;
	static TVisMaterial *Blue;
public:
	int Test(TObject *Object, int PrimitiveID);
	virtual void Add(TElement* Element);
	virtual void Changed(TElement* Element);
	virtual void Remove(TElement* Element);
	virtual void Delete(int i);
	virtual void Clear();
	TSelection();
	~TSelection();
	TVisMaterial *Material;
	void Render(TVisView* aView);
	void RegisterCreateSelView();
	void UnRegisterCreateSelView();
	void RegisterPositionSelView();
	void CreateSelView();
	void PositionSelView();
};

extern COMMONAL_API TElementQueueCollection* FSelectionCollection;
extern COMMONAL_API TSelection* FSelection;

COMMONAL_API TElementQueueCollection& GetSelectionCollection();
COMMONAL_API TSelection& GetSelection();
#define SelectionCollection GetSelectionCollection()
#define MySelection GetSelection()

#endif
