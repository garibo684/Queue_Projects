add_executable(linked_queue linked_queue.cc)

target_link_libraries(linked_queue PRIVATE
    LinkedList
    )
