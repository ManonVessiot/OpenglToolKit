#pragma once

#include <unordered_map>

#include "easyGL/Shader.h"

namespace OpenglToolKit
{
    class ShaderManager
    {
        private:
            static ShaderManager* m_Instance;

            ShaderManager(){ }
            ~ShaderManager(){
                if (m_Instance){
                    delete m_Instance;
                }
                for(std::unordered_map<std::string, easyGL::Shader*>::iterator i = m_Shaders.begin(); i!=m_Shaders.end(); ++i) {
                    delete i->second;
                }
            }

            std::unordered_map<std::string, easyGL::Shader*> m_Shaders;
            
        public:
            static ShaderManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new ShaderManager();
                }
                return m_Instance;
            }

            easyGL::Shader* GetSaher(std::string fileName);
            
    };
    
} // namespace OpenglToolKit
