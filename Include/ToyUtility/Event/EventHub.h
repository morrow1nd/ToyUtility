#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Event/EventListener.h"
#include "ToyUtility/Container/Map.h"
#include "ToyUtility/Container/List.h"

#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


class Event;
class EventListener;


class EventHub
{
public:
    void SendEvent(Event& e)
    {
        const auto& listeners = m_ListenersByEventId[e.GetId()];
        for (List<EventListener*>::const_iterator i = listeners.cbegin(), end = listeners.cend();
            i != end;
            ++i)
        {
            if (*i != nullptr)
            {
                (*i)->EmitEvent(e);
            }
        }
    }

    void RegisterListener(EventListener* listener)
    {
        listener->SetEventHub(this);
    }

    void RegisterEvent(EventId eventId, EventListener* listener)
    {
        auto& res = m_ListenersByEventId.find(eventId);
        if (res == m_ListenersByEventId.end())
        {
            m_ListenersByEventId[eventId] = List<EventListener*>({listener});
        }
        else
        {
            res->second.push_back(listener);
        }
    }


private:
    Map<EventId, List<EventListener*>> m_ListenersByEventId;
    // Map<EventListenerType, List<EventId>> m_EventIdsByListener;
};


} // end of namespace ToyUtility