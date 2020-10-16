#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "MaterialBase.h"

namespace OpenglToolKit
{
    class GameObject
    {
        private:

        public:
            Transform m_Transform;
            Mesh m_Mesh;
            bool m_Active;
            MaterialBase m_Material;
            
            GameObject();
            ~GameObject();

            void SetActive(bool active);
    };    
} // namespace OpenglToolKit
