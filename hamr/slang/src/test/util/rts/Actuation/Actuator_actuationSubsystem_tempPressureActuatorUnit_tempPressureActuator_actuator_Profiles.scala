// #Sireum

package rts.Actuation

import org.sireum._
import rts.util.Profile
import rts.util.EmptyContainer
import rts.RandomLib

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Profile for initialise entrypoint
@msig trait Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_Trait extends Profile

@record class Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile (
  val name: String,
) extends Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_Trait {

  override def next: EmptyContainer = {
    return EmptyContainer()
  }
}

// Profile with generators for incoming ports
@msig trait Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_P_Trait extends Profile {
  def api_input: RandomLib // random lib for generating Base_Types.Boolean
  def api_manualActuatorInput: RandomLib // random lib for generating Base_Types.Boolean
}

@record class Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_P(
  val name: String,
  var api_input: RandomLib, // random lib for generating Base_Types.Boolean
  var api_manualActuatorInput: RandomLib // random lib for generating Base_Types.Boolean
  ) extends Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_P_Trait {

  override def next: Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_PreState_Container_P = {
    return (Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_PreState_Container_P (
      api_input = api_input.nextB(),
      api_manualActuatorInput = api_manualActuatorInput.nextB()))
  }
}

// Profile with generators for state variables and incoming ports
@msig trait Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_PS_Trait extends Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_P_Trait {
  def api_input: RandomLib // random lib for generating Base_Types.Boolean
  def api_manualActuatorInput: RandomLib // random lib for generating Base_Types.Boolean
}

@record class Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_PS(
  val name: String,
  var api_input: RandomLib, // random lib for generating Base_Types.Boolean
  var api_manualActuatorInput: RandomLib // random lib for generating Base_Types.Boolean
  ) extends Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Profile_PS_Trait {

  override def next: Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_PreState_Container_PS = {
    return (Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_PreState_Container_PS (
      api_input = api_input.nextB(),
      api_manualActuatorInput = api_manualActuatorInput.nextB()))
  }
}
