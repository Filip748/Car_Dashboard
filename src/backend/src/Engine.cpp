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
    if(_isEngineOn == true) {
        _currentRpm += 15;

        if(_currentRpm > _maxRpm) {
            _currentRpm = _maxRpm;
        }

        if(_temperature < 90.0f) {
            _temperature += 0.5f;
        }
    }
}

void Engine::brake() {
    if(_isEngineOn) {
        _currentRpm -= 40;
        if(_currentRpm < 800) {
            _currentRpm = 800;
        }
    }
}

void Engine::idle() {
    if(_isEngineOn == true) {
        if(_currentRpm > 800) {
            _currentRpm -= 5;
        }
        else {
            _currentRpm = 800;
        }
    }
}

// zmienic cmake idk czy dobrze jest
