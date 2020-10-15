#pragma once

#include <vector>
#include "Light.h"

namespace OpenglToolKit
{
    class LightsManager
    {
    private:
        static std::vector<Light> m_Lights;

        LightsManager(){ }

    public:

    };    
} // namespace OpenglToolKit
