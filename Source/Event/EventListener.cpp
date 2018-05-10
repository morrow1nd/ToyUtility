#include "ToyUtility/Event/EventListener.h"
#include "ToyUtility/Event/EventHub.h"
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


void EventListener::RegisterEvent(EventId eventId, EventHandlerType handler)
{
    if (m_EventHub == nullptr)
    {
        TOY_RAW_LOG_ERR << "This event listener hasn't been registered!\n";
        return;
    }

    m_EventHub->RegisterEvent(eventId, this);

    m_HandlerByEventId[eventId] = handler;
}


} // end of namespace ToyUtility