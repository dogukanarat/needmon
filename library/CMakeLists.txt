if (NOT TARGET gtest_main)
    add_subdirectory(osal)
endif() 


if (NOT TARGET gtest_main)
    add_subdirectory(googletest)
endif() 
