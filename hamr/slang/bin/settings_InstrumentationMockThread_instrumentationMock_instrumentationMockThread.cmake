add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(InstrumentationMockThread_instrumentationMock_instrumentationMockThread
                        muslc)
endif()