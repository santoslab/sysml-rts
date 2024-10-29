// #Sireum
package rts.Actuation

import org.sireum._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

@msig trait CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_Injection_Provider {
  def pre_receiveInput(): Unit
}

object CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_Injection_Service {

  var providers: MSZ[CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_Injection_Provider] = MSZ()

  def register(provider: CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_Injection_Provider): Unit = {
    providers = providers :+ provider
  }

  def pre_receiveInput(): Unit = {
    for (provider <- providers) {
      provider.pre_receiveInput()
    }
  }
}