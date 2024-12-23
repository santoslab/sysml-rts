// #Sireum

package rts.Actuators

import org.sireum._
import art._
import rts._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

object ActuatorsMockThread_actuatorsMock_actuatorsMockThread_EntryPoint_Companion {

  var preStateContainer_wL: Option[ActuatorsMockThread_actuatorsMock_actuatorsMockThread_PreState_Container_PS] = None()

  def pre_initialise(): Unit = {
    // assume/require contracts cannot refer to incoming ports or
    // state variables so nothing to do here
  }

  def post_initialise(): Unit = {
    // block the component while its post-state values are retrieved
    val postStateContainer_wL =
      ActuatorsMockThread_actuatorsMock_actuatorsMockThread_PostState_Container_PS()

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeInitialisePostState(Arch.RTS_Instance_actuatorsMock_actuatorsMockThread.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuatorsMock_actuatorsMockThread_postInit, postStateContainer_wL)
  }

  def pre_compute(): Unit = {
    // block the component while its pre-state values are retrieved
    preStateContainer_wL = Some(
      ActuatorsMockThread_actuatorsMock_actuatorsMockThread_PreState_Container_PS(
        api_saturationActuate = Art.observeInPortVariable(Arch.RTS_Instance_actuatorsMock_actuatorsMockThread.operational_api.saturationActuate_Id).get.asInstanceOf[Base_Types.Boolean_Payload].value, 
        api_tempPressureActuate = Art.observeInPortVariable(Arch.RTS_Instance_actuatorsMock_actuatorsMockThread.operational_api.tempPressureActuate_Id).get.asInstanceOf[Base_Types.Boolean_Payload].value))

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeComputePreState(Arch.RTS_Instance_actuatorsMock_actuatorsMockThread.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuatorsMock_actuatorsMockThread_preCompute, preStateContainer_wL.asInstanceOf[Option[art.DataContent]])
  }

  def post_compute(): Unit = {
    // block the component while its post-state values are retrieved
    val postStateContainer_wL =
      ActuatorsMockThread_actuatorsMock_actuatorsMockThread_PostState_Container_PS()

    // the rest can now be performed via a different thread
    rts.runtimemonitor.RuntimeMonitor.observeComputePrePostState(Arch.RTS_Instance_actuatorsMock_actuatorsMockThread.id, rts.runtimemonitor.ObservationKind.RTS_Instance_actuatorsMock_actuatorsMockThread_postCompute, preStateContainer_wL.asInstanceOf[Option[art.DataContent]], postStateContainer_wL)
  }
}