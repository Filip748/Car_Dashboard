#ifndef CARPSHISICS_H
#define CARPHISICS_H

class CarPhisics {
private:
    int _currentSpeed;
    int _currentGear;
public:
    CarPhisics();

    void update(int engineRpm); // przeliczanie obrotow na predkosc i biegi 

    void shiftUp();
    void shiftDown();

    int getCurrentSpeed() const { return _currentSpeed; }
    int getCurrentGear() const { return _currentGear; }

};


#endif