#pragma once

#include <vector>

#include "Material.h"

namespace OpenglToolKit
{
    class MaterialManager
    {
        private:
            static MaterialManager* m_Instance;

            MaterialManager(){ }
            ~MaterialManager(){
                if (m_Instance){
                    delete m_Instance;
                }
                for(int i = 0; i < m_Materials.size(); ++i) {
                    delete m_Materials[i];
                }
            }

            std::vector<Material*> m_Materials;
            
        public:
            static MaterialManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new MaterialManager();
                }
                return m_Instance;
            }

            Material* CreateMaterial(std::string shaderFileName);
            
    };
    
} // namespace OpenglToolKit
