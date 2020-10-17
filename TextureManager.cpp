#include "TextureManager.h"

namespace OpenglToolKit
{
    TextureManager* TextureManager::m_Instance = nullptr;

    easyGL::Texture* TextureManager::CreateTexture(std::string textureFileName){
        if (m_Textures.find(textureFileName) == m_Textures.end()){
            m_Textures[textureFileName] = new easyGL::Texture(textureFileName);
        }
        return m_Textures[textureFileName];
    }

} // namespace OpenglToolKit