#pragma once

#include "easyGL/Shader.h"

namespace OpenglToolKit
{
    class MaterialBase
    {
        private:
            easyGL::Shader* m_Shader;

        public:
            MaterialBase():MaterialBase("shaders/ShaderBase.shader"){}
            MaterialBase(std::string shaderFileName);
            ~MaterialBase() { }

            virtual void SendToShader();
    };    
} // namespace OpenglToolKit
