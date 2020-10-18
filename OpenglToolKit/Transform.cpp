#include "Transform.h"

#include <glm/gtx/euler_angles.hpp>

namespace OpenglToolKit
{
    Transform::Transform(/* args */)
        :m_Position(0.0f, 0.0f, 0.0f), m_Rotation(1.0f, 0.0f, 0.0f, 0.0f), m_Scale(1.0f, 1.0f, 1.0f)
    {
    }
    
    Transform::~Transform()
    {
    }

    glm::mat4 Transform::GetTranslationMatrix() const
    {
        return glm::translate(glm::mat4(1.0f), m_Position);
    }

    glm::mat4 Transform::GetRotationMatrix() const
    {
        glm::vec3 eulerG = glm::eulerAngles(m_Rotation);
        return glm::eulerAngleXYZ(eulerG.x, eulerG.y, eulerG.z);
    }

    glm::mat4 Transform::GetScaleMatrix() const
    {
        return glm::scale(glm::mat4(1.0f), m_Scale);
    }

    glm::mat4 Transform::GetTransformMatrix() const
    {
        return GetTranslationMatrix() * GetRotationMatrix() * GetScaleMatrix();
    }

} // namespace OpenglToolKit
