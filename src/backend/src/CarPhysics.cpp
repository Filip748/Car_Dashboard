#include "CarPhysics.h"

CarPhysics::CarPhysics() 
    : _currentGear(0), _currentSpeed(0) {}

void CarPhysics::update(int engineRpm) {
    if (_currentGear == 0) {
        if(_currentSpeed > 0) {
            _currentSpeed -= 1;
        }
    }
    else if (_currentGear > 0) {
        int gearFactor = 120 - (_currentGear * 15);

        if(gearFactor == 0) {
            gearFactor = 1;
        }

        _currentSpeed = engineRpm / gearFactor;
    }

    if(_currentSpeed < 0) {
        _currentSpeed = 0;
    }
}

void CarPhysics::shiftUp() {
    if(_currentGear < 6) {
        _currentGear++;
    }
}

void CarPhysics::shiftDown() {
    if(_currentGear > 0) {
        _currentGear--;
    }
}