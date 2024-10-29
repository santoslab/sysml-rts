add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator
                        muslc)
endif()