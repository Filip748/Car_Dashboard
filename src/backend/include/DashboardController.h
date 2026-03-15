#pragma once

#include <QObject>
#include <thread>
#include <mutex>
#include <atomic>
#include "Simulator.h"

class DashboardController : public QObject {
    Q_OBJECT
    Q_PROPERTY(int speed READ getSpeed NOTIFY speedChanged)
    Q_PROPERTY(int rpm READ getRpm NOTIFY rpmChanged)
    Q_PROPERTY(int gear READ getGear NOTIFY gearChanged)

public:
    explicit DashboardController(QObject *parent = nullptr);
    ~DashboardController();

    int getSpeed() const;
    int getRpm() const;
    int getGear() const;

    Q_INVOKABLE void pressGas();
    Q_INVOKABLE void releaseGas();
    Q_INVOKABLE void pressBrake();
    Q_INVOKABLE void releaseBrake();
    Q_INVOKABLE void turnOnIgnition();
    Q_INVOKABLE void turnOffIgnition();

signals:
    void speedChanged();
    void rpmChanged();
    void gearChanged();

private:
    Simulator m_simulator;

    int m_speed;
    int m_rpm;
    int m_gear;

    std::thread m_workerThread;
    std::mutex m_mutex;
    std::atomic<bool> m_isRunning;

    void simulationLoop();
};
