#pragma once

#include <vector>

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
                for(int i = 0; i < m_Textures.size(); ++i) {
                    delete m_Textures[i];
                }
            }

            std::vector<easyGL::Texture*> m_Textures;
            
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
