#include "ShaderManager.h"

namespace OpenglToolKit
{
    ShaderManager* ShaderManager::m_Instance = nullptr;

    easyGL::Shader* ShaderManager::GetSaher(std::string fileName){
        if (m_Shaders.find(fileName) == m_Shaders.end())
        {
            m_Shaders[fileName] = new easyGL::Shader(fileName);
        }
        return m_Shaders[fileName];
    }

} // namespace OpenglToolKit