add_definitions(-DCAMKES)

if(TARGET muslc)
  target_link_libraries(CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic
                        muslc)
endif()