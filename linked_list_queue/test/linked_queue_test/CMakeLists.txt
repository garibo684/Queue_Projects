add_executable(linked_queue_test
    linked_queue_test.cc
    )

target_link_libraries(linked_queue_test PRIVATE
    GTest::GTest
    LinkedList
    )

add_test(
    NAME linked_queue_test
    COMMAND linked_queue_test)