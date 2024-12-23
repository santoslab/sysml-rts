// #Sireum

package rts.Actuation

import org.sireum._
import rts.util.Profile
import rts.util.EmptyContainer
import rts.RandomLib

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Profile for initialise entrypoint
@msig trait CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_Trait extends Profile

@record class CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile (
  val name: String,
) extends CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_Trait {

  override def next: EmptyContainer = {
    return EmptyContainer()
  }
}

// Profile with generators for incoming ports
@msig trait CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P_Trait extends Profile {
  def api_channel1: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel2: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel3: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel4: RandomLib // random lib for generating Base_Types.Boolean
}

@record class CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P(
  val name: String,
  var api_channel1: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel2: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel3: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel4: RandomLib // random lib for generating Base_Types.Boolean
  ) extends CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P_Trait {

  override def next: CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container_P = {
    return (CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container_P (
      api_channel1 = api_channel1.nextB(),
      api_channel2 = api_channel2.nextB(),
      api_channel3 = api_channel3.nextB(),
      api_channel4 = api_channel4.nextB()))
  }
}

// Profile with generators for state variables and incoming ports
@msig trait CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_PS_Trait extends CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P_Trait {
  def api_channel1: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel2: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel3: RandomLib // random lib for generating Base_Types.Boolean
  def api_channel4: RandomLib // random lib for generating Base_Types.Boolean
}

@record class CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_PS(
  val name: String,
  var api_channel1: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel2: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel3: RandomLib, // random lib for generating Base_Types.Boolean
  var api_channel4: RandomLib // random lib for generating Base_Types.Boolean
  ) extends CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_PS_Trait {

  override def next: CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container_PS = {
    return (CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container_PS (
      api_channel1 = api_channel1.nextB(),
      api_channel2 = api_channel2.nextB(),
      api_channel3 = api_channel3.nextB(),
      api_channel4 = api_channel4.nextB()))
  }
}
