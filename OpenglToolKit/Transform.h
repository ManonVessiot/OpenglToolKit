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

            glm::mat4 GetTranslationMatrix() const;
            glm::mat4 GetRotationMatrix() const;
            glm::mat4 GetScaleMatrix() const;
            glm::mat4 GetTransformMatrix() const;
    };    
} // namespace OpenglToolKit
