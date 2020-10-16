#include "MaterialBase.h"

#include "ShaderManager.h"

namespace OpenglToolKit
{
    MaterialBase::MaterialBase(std::string shaderFileName)
    {
        m_Shader = ShaderManager::Instance()->GetSaher(shaderFileName);
    }
    
    void MaterialBase::SendToShader(){
        
    }
} // namespace OpenglToolKit
