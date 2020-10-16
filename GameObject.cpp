#include "GameObject.h"

#include "BatchManager.h"

namespace OpenglToolKit
{
    GameObject::GameObject()
    {
        m_Active = true;
        SetActive(m_Active);
    }
    
    GameObject::~GameObject()
    {
        BatchManager::Instance()->DetroyGameObject(this);
    }

    void GameObject::SetActive(bool active){
        m_Active = active;
        BatchManager::Instance()->SetGameObjectActive(this, m_Active);
    }
} // namespace OpenglToolKit
