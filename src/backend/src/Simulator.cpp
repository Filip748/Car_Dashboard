#include "Simulator.h"

Simulator::Simulator() {
    isGasPressed = false;
    isBrakePressed = false;
}

void Simulator::turnOnIgnition() { _engine.start(); }
void Simulator::terunOffIgnition() { _engine.stop(); }

void Simulator::pressGas() { isGasPressed = true; }
void Simulator::releaseGas() { isGasPressed = false; }
void Simulator::pressBrake() { isBrakePressed = true; }
void Simulator::releaseBrake() { isBrakePressed = false; }

void Simulator::update() {
    if(isGasPressed) {
        _engine.accelerate();
    } else if(isBrakePressed) {
        _engine.brake();
    } else {
        _engine.idle();
    }
    /*
    tu potrzeba logiki automatycznej skrzyni biegow
    */
    _physics.update(_engine.getCurrentRpm());
}