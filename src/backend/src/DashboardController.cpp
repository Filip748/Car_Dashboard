#include "DashboardController.h"
#include <chrono>

DashboardController::DashboardController(QObject *parent)
    : QObject(parent), m_speed(0), m_rpm(0), m_gear(0), m_isRunning(true) 
{
    m_workerThread = std::thread(&DashboardController::simulationLoop, this);
}

DashboardController::~DashboardController() {
    m_isRunning = false;

    if(m_workerThread.joinable()) {
        m_workerThread.join();
    }
}

int DashboardController::getSpeed() const {
    std::lock_guard<std::mutex> lock(const_cast<std::mutex&>(m_mutex));
    return m_speed; 
}

int DashboardController::getRpm() const {
    std::lock_guard<std::mutex> lock(const_cast<std::mutex&>(m_mutex));
    return m_rpm; 
}

int DashboardController::getGear() const {
    std::lock_guard<std::mutex> lock(const_cast<std::mutex&>(m_mutex));
    return m_gear; 
}

void DashboardController::pressGas() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.pressGas();
}

void DashboardController::releaseGas() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.releaseGas();
}

void DashboardController::pressBrake() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.pressBrake();
}

void DashboardController::releaseBrake() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.releaseBrake();
}

void DashboardController::turnOnIgnition() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.turnOnIgnition();
}

void DashboardController::turnOffIgnition() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_simulator.turnOffIgnition();
}

void DashboardController::simulationLoop() {
    while(m_isRunning) {
        int currentSpeed, currentRpm, currentGear;

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_simulator.update();
            currentSpeed = m_simulator.getSpeed();
            currentRpm = m_simulator.getRpm();
            currentGear = m_simulator.getGear();
        }

        if(m_speed != currentSpeed) {
            m_speed = currentSpeed;
            emit speedChanged();
        }

        if (m_rpm != currentRpm) {
            m_rpm = currentRpm;
            emit rpmChanged();
        }
        if (m_gear != currentGear) {
            m_gear = currentGear;
            emit gearChanged();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));

    }
}