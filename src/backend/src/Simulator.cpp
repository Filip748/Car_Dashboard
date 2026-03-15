#include "Simulator.h"

Simulator::Simulator() {
    isGasPressed = false;
    isBrakePressed = false;
}

void Simulator::turnOnIgnition() { _engine.start(); }
void Simulator::turnOffIgnition() { _engine.stop(); }

void Simulator::pressGas() { isGasPressed = true; }
void Simulator::releaseGas() { isGasPressed = false; }
void Simulator::pressBrake() { isBrakePressed = true; }
void Simulator::releaseBrake() { isBrakePressed = false; }

void Simulator::handleAutomaticTransmission() {
    int currentRpm = getRpm();
    int currentGear = getGear();

    if(isGasPressed && currentGear == 0) {
        _physics.shiftUp();
    }

    if (currentGear > 0) {
        if (currentRpm > 5500 && currentGear < 6) {
            _physics.shiftUp();
            _engine.setCurrentRpm(currentRpm - 1500);
        }
        else if (currentRpm < 2000 && currentGear > 1) {
            _physics.shiftDown();
            _engine.setCurrentRpm(currentRpm + 1000); 
        }
        
        if (!isGasPressed && currentRpm <= 800 && currentGear == 1) {
            _physics.shiftDown(); 
        }
    }
}

void Simulator::update() {

    if(!_engine.getIsEngineOn()) {
        int currentRpm = _engine.getCurrentRpm();
        if(currentRpm > 0) {
            _engine.setCurrentRpm(currentRpm - 150);
            if(_engine.getCurrentRpm() < 0) {
                _engine.setCurrentRpm(0);
            }
        }

        while(_physics.getCurrentGear() > 0) {
            _physics.shiftDown();
        }

        _physics.update(_engine.getCurrentRpm());

        return;

    }

    if(isGasPressed) {
        _engine.accelerate();
    } else if(isBrakePressed) {
        _engine.brake();
    } else {
        _engine.idle();
    }
    
    handleAutomaticTransmission();

    _physics.update(_engine.getCurrentRpm());
}