#include "Material.h"

#include "Property.h"
#include "WorldManager.h"

#include "easyGL/ShaderManager.h"

namespace OpenglToolKit
{
    Material::Material(std::string shaderFileName)
        :m_MainColor{1.0f, 1.0f, 1.0f, 1.0f}, m_MainTextureOffset{0.0f, 0.0f}, m_MainTextureScale{1.0f, 1.0f}
    {
        m_Shader = easyGL::ShaderManager::Instance()->GetSaher(shaderFileName);
    }

    void Material::SetMainTexture(easyGL::Texture* text)
    {
        m_MainTexture = text;
    }

    void Material::SetMainColor(float v0, float v1, float v2, float v3)
    {
        m_MainColor[0] = v0;
        m_MainColor[1] = v1;
        m_MainColor[2] = v2;
        m_MainColor[3] = v3;
    }

    void Material::SetMainTextureOffset(float v0, float v1)
    {
        m_MainTextureOffset[0] = v0;
        m_MainTextureOffset[1] = v1;
    }

    void Material::SetMainTextureScale(float v0, float v1)
    {
        m_MainTextureScale[0] = v0;
        m_MainTextureScale[1] = v1;
    }

    void Material::AddProperty(std::string name, Property property)
    {
        m_PropertyName.push_back(name);
        m_Property.push_back(property);
    }
    
    void Material::SendProperty(int index)
    {
        switch (m_Property[index].Type)
        {
            case Property::DataType::INT:
                m_Shader->SetUniform1i(m_PropertyName[index], m_Property[index].int_data);
                break;
            case Property::DataType::FLOAT:
                m_Shader->SetUniform1f(m_PropertyName[index], m_Property[index].float_data);
                break;
            case Property::DataType::FLOAT2:
                m_Shader->SetUniform2f(m_PropertyName[index], m_Property[index].float2_data[0], m_Property[index].float2_data[1]);
                break;
            case Property::DataType::FLOAT3:
                m_Shader->SetUniform3f(m_PropertyName[index], m_Property[index].float3_data[0], m_Property[index].float3_data[1],
                                        m_Property[index].float3_data[2]);
                break;
            case Property::DataType::FLOAT4:
                m_Shader->SetUniform4f(m_PropertyName[index], m_Property[index].float4_data[0], m_Property[index].float4_data[1],
                                        m_Property[index].float4_data[2], m_Property[index].float4_data[3]);
                break;
        }
    }
    
    void Material::SendPropertyToShader()
    {
        for (int i = 0; i < m_PropertyName.size(); i++){
            SendProperty(i);
        }
    }

    void Material::Bind()
    {
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", WorldManager::Instance()->m_ProjectionMatrix * WorldManager::Instance()->m_ViewMatrix);

        m_Shader->SetUniform4f("m_MainColor", m_MainColor[0], m_MainColor[1], m_MainColor[2], m_MainColor[3]);
        if (m_MainTexture != nullptr){
            m_MainTexture->Bind();
            m_Shader->SetUniform1i("u_Texture", 0);
        }
        m_Shader->SetUniform2f("m_MainTextureOffset", m_MainTextureOffset[0], m_MainTextureOffset[1]);
        m_Shader->SetUniform2f("m_MainTextureScale", m_MainTextureScale[0], m_MainTextureScale[1]);
        SendPropertyToShader();
    }

    easyGL::Shader* Material::GetShader() const
    {
        return m_Shader;
    }
} // namespace OpenglToolKit
