add_executable(lock_free_test
    lock_free_test.cc
    )

target_link_libraries(lock_free_test PRIVATE
    GTest::GTest
    LockFreeQueue
    )

add_test(
    NAME lock_free_test
    COMMAND lock_free_test
    )