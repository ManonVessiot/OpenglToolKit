#include "TextureManager.h"

namespace OpenglToolKit
{
    TextureManager* TextureManager::m_Instance = nullptr;

    easyGL::Texture* TextureManager::CreateTexture(std::string textureFileName){
        m_Textures.push_back(new easyGL::Texture(textureFileName));
        return m_Textures[m_Textures.size()-1];
    }

} // namespace OpenglToolKit