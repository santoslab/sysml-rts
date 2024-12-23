// #Sireum

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

package rts.Actuation

import org.sireum._
import art._

@ext object OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_seL4Nix {
  // returns T if seL4's channel1 port is empty, F otherwise 
  def channel1_IsEmpty(): B = $

  // returns result of dequeuing seL4's channel1 port 
  def channel1_Receive(): Option[DataContent] = $

  // returns T if seL4's channel2 port is empty, F otherwise 
  def channel2_IsEmpty(): B = $

  // returns result of dequeuing seL4's channel2 port 
  def channel2_Receive(): Option[DataContent] = $

  // send payload 'd' to components connected to seL4's actuate port
  def actuate_Send(d: DataContent): Unit = $
}
