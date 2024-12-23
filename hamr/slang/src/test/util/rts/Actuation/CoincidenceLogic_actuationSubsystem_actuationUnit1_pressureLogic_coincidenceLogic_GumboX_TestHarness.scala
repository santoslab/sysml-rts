// #Sireum

package rts.Actuation

import org.sireum._
import rts._
import rts.GumboXUtil.GumboXResult

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_GumboX_TestHarness extends CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_TestApi {
  def verbose: B

  def testComputeCBJ(json: String): GumboXResult.Type = {
    rts.JSON.toActuationCoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_PreState_Container(json) match {
      case Either.Left(o) => return testComputeCBV(o)
      case Either.Right(msg) => halt(msg.string)
    }
  }

  def testComputeCBV(o: CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_PreState_Container): GumboXResult.Type = {
    return testComputeCB(o.api_channel1, o.api_channel2, o.api_channel3, o.api_channel4)
  }

  /** Contract-based test harness for the compute entry point
    * @param api_channel1 incoming data port
    * @param api_channel2 incoming data port
    * @param api_channel3 incoming data port
    * @param api_channel4 incoming data port
    */
  def testComputeCB(
      api_channel1: Base_Types.Boolean,
      api_channel2: Base_Types.Boolean,
      api_channel3: Base_Types.Boolean,
      api_channel4: Base_Types.Boolean): GumboXResult.Type = {

    // [SaveInLocal]: retrieve and save the current (input) values of GUMBO-declared local state variables as retrieved from the component state
    //   coincidenceLogic does not have incoming ports or state variables

    // [CheckPre]: check/filter based on pre-condition.
    //   coincidenceLogic's compute entry point does not have top level assume clauses

    // [PutInPorts]: put values on the input ports
    put_channel1(api_channel1)
    put_channel2(api_channel2)
    put_channel3(api_channel3)
    put_channel4(api_channel4)

    if (verbose) {
      println(st"""Pre State Values:
                  |  api_channel1 = ${api_channel1.string}
                  |  api_channel2 = ${api_channel2.string}
                  |  api_channel3 = ${api_channel3.string}
                  |  api_channel4 = ${api_channel4.string}""".render)
    }

    // [InvokeEntryPoint]: invoke the entry point test method
    testCompute()

    // [RetrieveOutState]: retrieve values of the output ports via get operations and GUMBO declared local state variable
    val api_actuate: Base_Types.Boolean = get_actuate().get

    if (verbose) {
      println(st"""Post State Values:
                  |  api_actuate = ${api_actuate.string}""".render)
    }

    // [CheckPost]: invoke the oracle function
    val postResult = rts.Actuation.CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_GumboX.compute_CEP_Post(api_channel1, api_channel2, api_channel3, api_channel4, api_actuate)
    val result: GumboXResult.Type =
      if (!postResult) GumboXResult.Post_Condition_Fail
      else GumboXResult.Post_Condition_Pass

    return result
  }
}
