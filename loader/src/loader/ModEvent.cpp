#include <Geode/loader/ModEvent.hpp>

using namespace geode::prelude;

ModStateEvent::ModStateEvent(Mod* mod, ModEventType type) : m_mod(mod), m_type(type) {}

ModEventType ModStateEvent::getType() const {
    return m_type;
}

Mod* ModStateEvent::getMod() const {
    return m_mod;
}

ListenerResult ModStateFilter::handle(utils::MiniFunction<Callback> fn, ModStateEvent* event) {
    if (!m_mod || (event->getMod() == m_mod && event->getType() == m_type)) {
        fn(event);
    }
    return ListenerResult::Propagate;
}

ModStateFilter::ModStateFilter(Mod* mod, ModEventType type) : m_mod(mod), m_type(type) {}
