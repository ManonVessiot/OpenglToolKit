#pragma once

#include <vector>
#include <unordered_map>

#include "easyGL/Texture.h"

namespace OpenglToolKit
{
    class TextureManager
    {
        private:
            static TextureManager* m_Instance;

            TextureManager(){ }
            ~TextureManager(){
                if (m_Instance){
                    delete m_Instance;
                }
                for ( auto it = m_Textures.begin(); it != m_Textures.end(); ++it ) {
                    delete it->second;
                }
            }

            std::unordered_map<std::string, easyGL::Texture*> m_Textures;
            
        public:
            static TextureManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new TextureManager();
                }
                return m_Instance;
            }

            easyGL::Texture* CreateTexture(std::string textureFileName);
            
    };
    
} // namespace OpenglToolKit
