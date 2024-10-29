add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(Actuator_actuationSubsystem_saturationActuatorUnit_saturationActuator_actuator
                        muslc)
endif()