#ifndef CONFIGNAMES_H
#define CONFIGNAMES_H

#include <cstdint>

namespace CONFIGS {

    enum class configsNames : uint8_t{
        speed,                  //speed
        acceleration,           //acceleration
        microStepsInMM,         //step in mm
        mmInRotation,           //how much mm in one rotation
        microStepsInRotation,   //how many steps in one rotation
        N,                      //driver multiplication
        distanceToZero,         //distance to zero point
        steps,                  //steps to do
    };

}

#endif // CONFIGNAMES_H
