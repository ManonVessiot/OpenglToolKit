#pragma once

#include "Mesh.h"
#include "Transform.h"

namespace OpenglToolKit
{
    class GameObject
    {
        private:

        public:
            Transform m_Transform;
            Mesh m_Mesh;
            
            GameObject();
            ~GameObject();
    };    
} // namespace OpenglToolKit
