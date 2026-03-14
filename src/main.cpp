/*#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Car_Dashboard", "Main");

    return app.exec();
}
    */

#include <iostream>
#include <thread>
#include <chrono>
#include "Simulator.h" // Nasz genialny backend!

int main() {
    Simulator sim;
    
    std::cout << "Przekrecam kluczyk..." << std::endl;
    sim.turnOnIgnition();
    
    std::cout << "Wciskam gaz do dechy!" << std::endl;
    sim.pressGas();

    // Symulujemy 40 "klatek" jazdy (ok. 4 sekundy)
    for (int i = 0; i < 40; ++i) {
        sim.update(); // Przeliczamy fizykę w tej klatce
        
        // Wypisujemy stan na ekran
        std::cout << "Bieg: " << sim.getGear() 
                  << " | RPM: " << sim.getRpm() 
                  << " | Predkosc: " << sim.getSpeed() << " km/h" << std::endl;
                  
        // Usypiamy program na 100 milisekund, żebyś zdążył to przeczytać
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\nUwaga zakret! Puszczam gaz i hamuje!" << std::endl;
    sim.releaseGas();
    sim.pressBrake();

    // Symulujemy 20 "klatek" hamowania (ok. 2 sekundy)
    for (int i = 0; i < 20; ++i) {
        sim.update();
        std::cout << "Bieg: " << sim.getGear() 
                  << " | RPM: " << sim.getRpm() 
                  << " | Predkosc: " << sim.getSpeed() << " km/h" << std::endl;
                  
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    sim.turnOffIgnition();
    std::cout << "Koniec jazdy." << std::endl;
    
    return 0;
}