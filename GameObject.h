#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "Material.h"

#include <glm/glm.hpp>

namespace OpenglToolKit
{
    class GameObject
    {
        private:

        public:
            Transform m_Transform;
            Mesh m_Mesh;
            bool m_Active;
            Material* m_Material;
            
            GameObject();
            ~GameObject();

            void SetActive(bool active);
            glm::mat4 GetTransformMatrix() const;
    };    
} // namespace OpenglToolKit
