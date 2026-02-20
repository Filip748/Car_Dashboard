#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Engine.h"
#include "CarPhisics.h"

class Simulator {
private:
    Engine _engine;
    CarPhisics _phisics;
    bool isGasPressed;
public:
    Simulator();

    void turnOnIgnition();
    void terunOffIgnition();
    void pressGas();
    void releaseGas();
    void shiftGearUp();
    void shiftGearDown();

    void update();

    int getSpeed() const { return _phisics.getCurrentSpeed(); }
    int getRpm() const { return _engine.getCurrentRpm(); }
    int getGear() const { return _phisics.getCurrentGear(); }
};

#endif