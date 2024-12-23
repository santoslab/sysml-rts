// #Sireum

package rts.Actuation

import org.sireum._
import art._
import rts._
import rts.Actuation.{Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator => component}

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

@datatype class Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[ISZ[Art.PortId]],

  input: Port[Base_Types.Boolean],
  manualActuatorInput: Port[Base_Types.Boolean],
  output: Port[Base_Types.Boolean]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    dataIns = ISZ[art.UPort](input,
                             manualActuatorInput),

    dataOuts = ISZ[art.UPort](output),

    eventIns = ISZ[art.UPort](),

    eventOuts = ISZ[art.UPort]()
  )

  val initialization_api : Actuator_Initialization_Api = {
    val api = Actuator_Initialization_Api(
      id,
      input.id,
      manualActuatorInput.id,
      output.id
    )
    Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Actuator_Operational_Api = {
    val api = Actuator_Operational_Api(
      id,
      input.id,
      manualActuatorInput.id,
      output.id
    )
    Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Bridge.EntryPoints(
      id,

      input.id,
      manualActuatorInput.id,
      output.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Bridge {

  var c_initialization_api: Option[Actuator_Initialization_Api] = None()
  var c_operational_api: Option[Actuator_Operational_Api] = None()

  @datatype class EntryPoints(
    Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_BridgeId : Art.BridgeId,
    input_Id : Art.PortId,
    manualActuatorInput_Id : Art.PortId,
    output_Id : Art.PortId,
    dispatchTriggers : Option[ISZ[Art.PortId]],
    initialization_api: Actuator_Initialization_Api,
    operational_api: Actuator_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: ISZ[Art.PortId] = IS(input_Id,
                                            manualActuatorInput_Id)

    val eventInPortIds: ISZ[Art.PortId] = IS()

    val dataOutPortIds: ISZ[Art.PortId] = IS(output_Id)

    val eventOutPortIds: ISZ[Art.PortId] = IS()

    def initialise(): Unit = {
      Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_EntryPoint_Companion.pre_initialise()

      // implement the following method in 'component':  def initialise(api: Actuator_Initialization_Api): Unit = {}
      component.initialise(initialization_api)

      Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_EntryPoint_Companion.post_initialise()

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def compute(): Unit = {
      Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_Injection_Service.pre_receiveInput()

      Art.receiveInput(eventInPortIds, dataInPortIds)

      Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_EntryPoint_Companion.pre_compute()

      // implement the following in 'component':  def timeTriggered(api: Actuator_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Actuator_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_EntryPoint_Companion.post_compute()

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: Actuator_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    override
    def testInitialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Actuator_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }

    override
    def testCompute(): Unit = {
      Art.receiveInput(eventInPortIds, dataInPortIds)

      // implement the following in 'component':  def timeTriggered(api: Actuator_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}