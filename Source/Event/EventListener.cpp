#include "ToyUtility/Event/EventListener.h"
#include "ToyUtility/Event/EventHub.h"


namespace ToyUtility
{


void EventListener::RegisterEvent(EventId eventId, EventHandlerType handler)
{
    m_EventHub->RegisterEvent(eventId, this);

    m_HandlerByEventId[eventId] = handler;
}


} // end of namespace ToyUtility