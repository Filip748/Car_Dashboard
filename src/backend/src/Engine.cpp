#include "Engine.h"

Engine::Engine() 
    : _currentRpm(800), _maxRpm(7000), _isEngineOn(false), _temperature(20.0f) {}

void Engine::start() { // do poprawy
    _isEngineOn = true;
}

void Engine::stop() { // do poprawy
    _isEngineOn = false;
}

void Engine::accelerate() {
 // dodac
}

// zmienic cmake