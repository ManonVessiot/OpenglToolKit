#include "GameObject.h"

#include "GameObjectManager.h"

namespace OpenglToolKit
{
    GameObject::GameObject()
    {
        m_Active = true;
        GameObjectManager::Instance()->AddGameObject(this);
    }
    
    GameObject::~GameObject()
    {
        GameObjectManager::Instance()->RemoveGameObject(this);
    }

    void GameObject::SetActive(bool active){
        m_Active = active;
    }

    glm::mat4 GameObject::GetTransformMatrix() const
    {
        return m_Transform.GetTransformMatrix();
    }
} // namespace OpenglToolKit
