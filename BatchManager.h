#pragma once

namespace OpenglToolKit
{
    class BatchManager
    {
        private:
            static BatchManager* m_Instance;

            BatchManager(){ }
            ~BatchManager(){
                if (m_Instance){
                    delete m_Instance;
                }
            }
            
        public:
            static BatchManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new BatchManager();
                }
                return m_Instance;
            }
            
    };    
} // namespace OpenglToolKit
