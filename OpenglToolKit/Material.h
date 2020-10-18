#pragma once

#include "../easyGL/Shader.h"
#include "../easyGL/Texture.h"

#include "Property.h"

#include <vector>

namespace OpenglToolKit
{
    class Material
    {
        private:
            easyGL::Shader* m_Shader;

            float m_MainColor[4];
            easyGL::Texture* m_MainTexture = nullptr;
            float m_MainTextureOffset[2];
            float m_MainTextureScale[2];

            float m_transparencyEnable;

            std::vector<std::string> m_PropertyName;
            std::vector<Property> m_Property;

            void SendProperty(int index);
            void SendPropertyToShader();

        public:
            Material():Material("shaders/ShaderBase.shader"){}
            Material(std::string shaderFileName);
            ~Material() { }

            void SetMainTexture(easyGL::Texture* text);
            void SetMainColor(float v0, float v1, float v2, float v3);
            void SetMainTextureOffset(float v0, float v1);
            void SetMainTextureScale(float v0, float v1);

            void EnableTransparency(bool enable){ m_transparencyEnable = enable; }
            bool IsTransparent(){ return m_transparencyEnable; }

            void AddProperty(std::string name, Property property);

            void Bind();
            easyGL::Shader* GetShader() const;
    };    
} // namespace OpenglToolKit
