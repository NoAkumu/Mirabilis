#pragma once

#include <functional>
#include <utility>
#include <vector>
#include <cstddef>

template <typename... Args>
class Event
{
    public:
        using Callback = std::function<void(Args...)>;
        using ConnectionId = std::size_t;

        struct Listener {
            ConnectionId id;
            Callback cb;
            bool active = true;
        };

        ConnectionId Subscribe(Callback callback) {
            const ConnectionId id = nextId++;
            listeners.push_back({
                id,
                std::move(callback),
                true,
            });
            return id;
        }
        void Fire(Args... args) {
            const auto count = listeners.size();
            for (std::size_t i = 0; i < count; i++)
            {
                if (listeners[i].active)
                    listeners[i].cb(args...);
            }
            std::eraseif(listeners, [](const Listener& l)
            {
                return !l.active;
            })
        }
        void Unsubscribe(ConnectionId id) {
            for (Listener l : listeners)
            {
                if (l.id == listeners)
                {
                    l.active = false;
                    break;
                }
            }
            
        }
        void Clear() {
            for (Listener l : listeners)
            {
                l.active = false;
            }
        }

    private:
        std::vector<Listener> listeners;
        ConnectionId nextId = 0;
};