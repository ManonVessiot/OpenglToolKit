#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace OpenglToolKit
{
    class Transform
    {
        private:
        
        public:
            glm::vec3 m_Position;
            glm::quat m_Rotation;
            glm::vec3 m_Scale;

            Transform();
            ~Transform();

            glm::mat4 GetTranslationMatrix();
            glm::mat4 GetRotationMatrix();
            glm::mat4 GetScaleMatrix();
            glm::mat4 GetTransformMatrix();
    };    
} // namespace OpenglToolKit
