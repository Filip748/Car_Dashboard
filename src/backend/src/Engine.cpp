#include "Engine.h"

Engine::Engine() 
    : _currentRpm(0), _maxRpm(7000), _isEngineOn(false), _temperature(20.0f) {}

void Engine::start() { // do poprawy
    if(_isEngineOn == false) {
        _isEngineOn = true;
        _currentRpm = 800;
    }
}

void Engine::stop() { // do poprawy
    if(_isEngineOn == true) {
        _isEngineOn = false;
        _currentRpm = 0;
    }
}

void Engine::accelerate() {
 // dodac
}

// zmienic cmake idk czy dobrze jest