// #Sireum

package rts.Actuation

import org.sireum._
import art._
import rts._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

object OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_EntryPoint_Companion {

  var last_api_actuate: Option[Base_Types.Boolean] = None()

  /** get the value of outgoing data port actuate.  If a 'fresh' value wasn't sent
    * during the last dispatch then return last_api_actuate.get.
    * Note: this requires outgoing data ports to be initialized during the
    * initialization phase or prior to system testing.
    */
  def get_api_actuate: Base_Types.Boolean = {
    Art.observeOutPortVariable(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.operational_api.actuate_Id) match {
      case Some(Base_Types.Boolean_Payload(value)) =>
        last_api_actuate = Some(value)
        return value
      case _ if last_api_actuate.isEmpty =>
        assert(F, "No value found on outgoing data port actuate.\n                  Note: values placed during the initialization phase will persist across dispatches")
        halt("No value found on outgoing data port actuate.\n                  Note: values placed during the initialization phase will persist across dispatches")
      case _ => return last_api_actuate.get
    }
  }
  var preStateContainer_wL: Option[OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PreState_Container_PS] = None()

  def pre_initialise(): Unit = {
    // assume/require contracts cannot refer to incoming ports or
    // state variables so nothing to do here
  }

  def post_initialise(): Unit = {
    // block the component while its post-state values are retrieved
    val postStateContainer_wL =
      OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PostState_Container_PS(
        api_actuate = get_api_actuate)

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeInitialisePostState(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_postInit, postStateContainer_wL)
  }

  def pre_compute(): Unit = {
    // block the component while its pre-state values are retrieved
    preStateContainer_wL = Some(
      OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PreState_Container_PS(
        api_channel1 = Art.observeInPortVariable(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.operational_api.channel1_Id).get.asInstanceOf[Base_Types.Boolean_Payload].value, 
        api_channel2 = Art.observeInPortVariable(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.operational_api.channel2_Id).get.asInstanceOf[Base_Types.Boolean_Payload].value))

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeComputePreState(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_preCompute, preStateContainer_wL.asInstanceOf[Option[art.DataContent]])
  }

  def post_compute(): Unit = {
    // block the component while its post-state values are retrieved
    val postStateContainer_wL =
      OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PostState_Container_PS(
        api_actuate = get_api_actuate)

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeComputePrePostState(Arch.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_postCompute, preStateContainer_wL.asInstanceOf[Option[art.DataContent]], postStateContainer_wL)
  }
}