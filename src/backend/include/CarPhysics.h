#ifndef CARPHISICS_H
#define CARPHISICS_H

class CarPhysics {
private:
    int _currentSpeed;
    int _currentGear;
public:
    CarPhysics();

    void update(int engineRpm); 

    void shiftUp();
    void shiftDown();

    int getCurrentSpeed() const { return _currentSpeed; }
    int getCurrentGear() const { return _currentGear; }

};


#endif
