#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Engine.h"
#include "CarPhysics.h"

class Simulator {
private:
    Engine _engine;
    CarPhysics _physics;
    bool isGasPressed;
    bool isBrakePressed;
public:
    Simulator();

    void turnOnIgnition();
    void terunOffIgnition();

    void pressGas();
    void releaseGas();
    void pressBrake();
    void releaseBrake();

    void update();

    int getSpeed() const { return _physics.getCurrentSpeed(); }
    int getRpm() const { return _engine.getCurrentRpm(); }
    int getGear() const { return _physics.getCurrentGear(); }
};

#endif