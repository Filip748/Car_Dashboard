#ifndef ENGINE_H
#define ENGINE_H

class Engine {
private:
    int _currentRpm;
    int _maxRpm;
    bool _isEngineOn;
    float _temperature;
public:
    Engine();
    
    void start();
    void stop();
    void accelerate();
    void idle();

    int getCurrentRpm() const { return _currentRpm; }
    int getMaxRpm() const { return _maxRpm; }
    bool getIsEngineOn() const { return _isEngineOn; }
    float getTemperature() const { return _temperature; }

};

#endif