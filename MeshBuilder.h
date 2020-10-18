#pragma once

#include <vector>

#include "Mesh.h"

namespace OpenglToolKit
{
    class MeshBuilder
    {
        private:
            static MeshBuilder* m_Instance;

            MeshBuilder(){ }
            ~MeshBuilder(){
                if (m_Instance){
                    delete m_Instance;
                }
            }
            
        public:
            static MeshBuilder* Instance()
            {
                if (!m_Instance){
                    m_Instance = new MeshBuilder();
                }
                return m_Instance;
            }

            void CreateQuad(Mesh &mesh, float size = 1.0f) const;
            void CreateCube(Mesh &mesh, float size = 1.0f) const;
            
    };
    
} // namespace OpenglToolKit
