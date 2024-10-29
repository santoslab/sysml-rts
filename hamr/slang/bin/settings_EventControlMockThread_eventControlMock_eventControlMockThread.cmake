add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(EventControlMockThread_eventControlMock_eventControlMockThread
                        muslc)
endif()