#pragma once

#include <functional>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Event/Event.h"
#include "ToyUtility/Container/UnorderedMap.h"


namespace ToyUtility
{


enum class EventListenerType
{
    BEGIN,
    END,
};


class EventHub;
class Event;


class EventListener
{
public:
    using EventHandlerType = std::function<void(Event&)>;

    virtual EventListenerType GetListenerType() const = 0;

    void SetEventHub(EventHub* hub)
    {
        m_EventHub = hub;
    }

    void EmitEvent(Event& e)
    {
        auto handler = m_HandlerByEventId[e.GetId()];
        if (handler != nullptr) // TODO: check this usage
        {
            handler(e);
        }
    }


protected:
    void RegisterEvent(EventId eventId, EventHandlerType handler);


private:
    EventHub* m_EventHub;
    UnorderedMap<EventId, EventHandlerType> m_HandlerByEventId;
};


} // end of namespace ToyUtility