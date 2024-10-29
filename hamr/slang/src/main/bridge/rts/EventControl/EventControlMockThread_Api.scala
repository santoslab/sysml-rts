// #Sireum

package rts.EventControl

import org.sireum._
import art._
import rts._

@sig trait EventControlMockThread_Api {
  def id: Art.BridgeId
  def manualActuatorInput1_Id : Art.PortId
  def manualActuatorInput2_Id : Art.PortId

  // Logika spec var representing port state for outgoing data port
  @spec var manualActuatorInput1: Base_Types.Boolean = $

  def put_manualActuatorInput1(value : Base_Types.Boolean) : Unit = {
    Contract(
      Modifies(manualActuatorInput1),
      Ensures(
        manualActuatorInput1 == value
      )
    )
    Spec {
      manualActuatorInput1 = value
    }

    Art.putValue(manualActuatorInput1_Id, Base_Types.Boolean_Payload(value))
  }

  // Logika spec var representing port state for outgoing data port
  @spec var manualActuatorInput2: Base_Types.Boolean = $

  def put_manualActuatorInput2(value : Base_Types.Boolean) : Unit = {
    Contract(
      Modifies(manualActuatorInput2),
      Ensures(
        manualActuatorInput2 == value
      )
    )
    Spec {
      manualActuatorInput2 = value
    }

    Art.putValue(manualActuatorInput2_Id, Base_Types.Boolean_Payload(value))
  }

  def logInfo(msg: String): Unit = {
    Art.logInfo(id, msg)
  }

  def logDebug(msg: String): Unit = {
    Art.logDebug(id, msg)
  }

  def logError(msg: String): Unit = {
    Art.logError(id, msg)
  }
}

@datatype class EventControlMockThread_Initialization_Api (
  val id: Art.BridgeId,
  val manualActuatorInput1_Id : Art.PortId,
  val manualActuatorInput2_Id : Art.PortId) extends EventControlMockThread_Api

@datatype class EventControlMockThread_Operational_Api (
  val id: Art.BridgeId,
  val manualActuatorInput1_Id : Art.PortId,
  val manualActuatorInput2_Id : Art.PortId) extends EventControlMockThread_Api {

}
