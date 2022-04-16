//
// Created by Ivan Hedz on 16.04.2022.
//
#include "Engine.h"

#ifndef OOP_JETENGINE_H
#define OOP_JETENGINE_H

namespace DOM {

    class JetEngine : public Engine {
    private:
        double _impulse{};
        int _effective_exhaust_velocity{};
        int _mass_kg{};
        double _trust_to_weight_ratio{};
    public:
        JetEngine();

        JetEngine(double emissions, double volume, double speed, double horsepower, int rotationFrequency,
                  double impulse, int effectiveExhaustVelocity, int massKg, double trustToWeightRatio);

        [[nodiscard]] double getImpulse() const;

        void setImpulse(double impulse);

        [[nodiscard]] int getEffectiveExhaustVelocity() const;

        void setEffectiveExhaustVelocity(int effectiveExhaustVelocity);

        [[nodiscard]] int getMassKg() const;

        void setMassKg(int massKg);

        [[nodiscard]] double getTrustToWeightRatio() const;

        void setTrustToWeightRatio(double trustToWeightRatio);
        void show() const override;
    };

} // DOM

#endif //OOP_JETENGINE_H
