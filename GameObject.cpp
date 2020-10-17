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
} // namespace OpenglToolKit
