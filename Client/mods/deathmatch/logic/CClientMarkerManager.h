/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *               (Shared logic for modifications)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/shared_logic/CClientMarkerManager.h
 *  PURPOSE:     Marker entity manager class
 *
 *****************************************************************************/

#ifndef __CCLIENTMARKERMANAGER_H
#define __CCLIENTMARKERMANAGER_H

#include "CClientMarker.h"
#include <list>

class CClientMarkerManager
{
    friend class CClientManager;
    friend class CClientMarker;
    friend class CClientGame;

public:
    unsigned int          Count(void) { return static_cast<unsigned int>(m_Markers.size()); };
    static CClientMarker* Get(ElementID ID);
    bool                  Exists(CClientMarker* pMarker);

    void Delete(int ID);
    void DeleteAll(void);

    CFastList<CClientMarker*>::const_iterator IterBegin(void) { return m_Markers.begin(); };
    CFastList<CClientMarker*>::const_iterator IterEnd(void) { return m_Markers.end(); };

private:
    CClientMarkerManager(class CClientManager* pManager);
    ~CClientMarkerManager(void);

    void DoPulse(void);

    void AddToList(CClientMarker* pCheckpoint) { m_Markers.push_back(pCheckpoint); };
    void RemoveFromList(CClientMarker* pCheckpoint)
    {
        if (m_bCanRemoveFromList)
            m_Markers.remove(pCheckpoint);
    };

    class CClientManager*     m_pManager;
    CFastList<CClientMarker*> m_Markers;
    bool                      m_bCanRemoveFromList;
};

#endif
