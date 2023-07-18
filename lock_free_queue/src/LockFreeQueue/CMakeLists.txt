add_library(LockFreeQueue 
    LockFreeQueue.cc)
    
target_include_directories(LockFreeQueue PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
    )

    