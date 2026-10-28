#pragma once

#include <functional>
#include <utility>
#include <unordered_map>
#include <cstddef>

template <typename... Args>
class Event
{
    public:
        using Listener = std::function<void(Args...)>;
        using ConnectionId = std::size_t;

        ConnectionId Subscribe(Listener listener) {
            const ConnectionId id = nextId++;
            listeners.emplace(id, std::move(listener));
            return id;
        }
        void Fire(Args... args) {
            for (const auto& [id, listener] : listeners) {
                listener(args...);
            }
        }
        void Unsubscribe(ConnectionId id) {
            listeners.erase(id);
        }
        void Clear() {
            listeners.clear();
        }
    private:
        std::unordered_map<ConnectionId, Listener> listeners;
        ConnectionId nextId = 0;
};