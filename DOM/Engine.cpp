//
// Created by Ivan Hedz on 16.04.2022.
//

#include "Engine.h"
#include "iostream"
#include <atomic>

namespace DOM {
    std::atomic_uint32_t Engine::current_id;
    Engine::Engine() :
            _id(current_id++), _speed(0),
            _rotation_frequency(0), _horsepower(0),
            _volume(0), _emissions(0) {
    }

    Engine::Engine(double emissions, double volume, double speed, double horsepower, int rotationFrequency)
            : _id(current_id++), _emissions(emissions), _volume(volume), _speed(speed), _horsepower(horsepower),
              _rotation_frequency(rotationFrequency) {}

    Engine::~Engine() = default;

    void Engine::show() const {
        std::cout << "ID: " << _id << std::endl;
        std::cout << "Fuel tank volumes: " << _volume << " liters;" << std::endl;
        std::cout << "Speed: " << _speed << " km/h;" << std::endl;
        std::cout << "CO₂ emissions: " << _emissions << " kg;" << std::endl;
        std::cout << "Horsepower: " << _horsepower << " 🐴;" << std::endl;
        std::cout << "Rotation frequency: " << _rotation_frequency << " RPM;" << std::endl;

    }

    [[maybe_unused]] int Engine::getID() const {
        return _id;
    }

    double Engine::getEmissions() const {
        return _emissions;
    }

    void Engine::setEmissions(double kg) {
        Engine::_emissions = kg;
    }

    double Engine::getVolume() const {
        return _volume;
    }

    void Engine::setVolume(double volume) {
        _volume = volume;
    }

    double Engine::getSpeed() const {
        return _speed;
    }

    void Engine::setSpeed(double speed) {
        _speed = speed;
    }

    double Engine::getHorsepower() const {
        return _horsepower;
    }

    void Engine::setHorsepower(double horsepower) {
        _horsepower = horsepower;
    }

    int Engine::getRotationFrequency() const {
        return _rotation_frequency;
    }

    void Engine::setRotationFrequency(int rotationFrequency) {
        _rotation_frequency = rotationFrequency;
    }

    Engine::Engine(Engine &&other) noexcept:
    _id(other._id),  _emissions(other._emissions),
    _horsepower(other._horsepower), _volume(other._volume),
    _rotation_frequency(other._rotation_frequency), _speed(other._speed){
        other._id = 0;
        other._speed = 0;
        other._rotation_frequency = 0;
        other._volume = 0;
        other._horsepower = 0;
        other._emissions = 0;
    }
} // DOM