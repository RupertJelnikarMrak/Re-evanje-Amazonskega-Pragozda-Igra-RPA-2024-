#pragma once

#include <map>
#include <functional>

#define EVENT_PRIORITY_HIGHEST 0
#define EVENT_PRIORITY_HIGH 1
#define EVENT_PRIORITY_NORMAL 2
#define EVENT_PRIORITY_LOW 3
#define EVENT_PRIORITY_LOWEST 4

namespace EventBus
{
    template <typename EventType>
    using Listener = std::function<void(const EventType &)>;

    template <typename EventType>
    void addListener(const Listener<EventType> &pListener, int pPriority)
    {
        getListeners<EventType>().insert({pPriority, pListener});
    }

    template <typename EventType>
    void addListener(const Listener<EventType> &pListener)
    {
        getListeners<EventType>().insert({EVENT_PRIORITY_NORMAL, pListener});
    }

    template <typename EventType>
    void raiseEvent(const EventType &pEvent)
    {
        auto &listeners = getListeners<EventType>();
        for (const auto &pair : listeners)
            pair.second(pEvent);
    }

    namespace {
        template <typename EventType>
        static std::multimap<int, Listener<EventType>> &getListeners()
        {
            static std::multimap<int, Listener<EventType>> listeners;
            return listeners;
        }
    }
};