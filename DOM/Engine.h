//
// Created by Ivan Hedz on 16.04.2022.
//
#include <atomic>
#ifndef OOP_ENGINE_H
#define OOP_ENGINE_H
namespace DOM {

    class Engine {
        static std::atomic_uint32_t current_id;//Static ID for generating unique one
    protected:
        int _id{};
        double _emissions{};
        double _volume{};
        double _speed{};
        double _horsepower{};
        int _rotation_frequency{};

        Engine();
        Engine(Engine&& other) noexcept;
        Engine(double emissions, double volume, double speed, double horsepower, int rotationFrequency);

    public:
        [[nodiscard]] double getHorsepower() const;

        void setHorsepower(double horsepower);

        [[nodiscard]] int getRotationFrequency() const;

        void setRotationFrequency(int rotationFrequency);

        [[nodiscard]] double getSpeed() const;

        void setSpeed(double speed);

        [[nodiscard]] double getVolume() const;

        void setVolume(double volume);

        [[nodiscard]] double getEmissions() const;

        void setEmissions(double kg);

        [[maybe_unused]] [[nodiscard]] int getID() const;

        virtual void show() const;

        virtual ~Engine();
    };
} // DOM

#endif //OOP_ENGINE_H
