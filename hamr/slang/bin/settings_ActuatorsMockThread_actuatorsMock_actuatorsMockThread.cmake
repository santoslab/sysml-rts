add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(ActuatorsMockThread_actuatorsMock_actuatorsMockThread
                        muslc)
endif()