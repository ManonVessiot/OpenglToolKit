#include "MaterialManager.h"

namespace OpenglToolKit
{
    MaterialManager* MaterialManager::m_Instance = nullptr;

    Material* MaterialManager::CreateMaterial(std::string shaderFileName){
        m_Materials.push_back(new Material(shaderFileName));
        return m_Materials[m_Materials.size()-1];
    }

} // namespace OpenglToolKit