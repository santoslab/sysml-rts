// #Sireum

package rts.Actuation

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

import org.sireum._
import rts.GumboXUtil.GumboXResult
import rts.util.{Container, Profile, UnitTestConfigurationBatch}
import rts.RandomLib
import org.sireum.Random.Impl.Xoshiro256

object OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_UnitTestConfiguration_Util {

  def freshRandomLib: RandomLib = {
    return RandomLib(Random.Gen64Impl(Xoshiro256.create))
  }

  val tq: String = "\"\"\""

  type DefaultComputeProfile = OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Profile_P

  def defaultComputeConfig: OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Compute_UnitTestConfiguration = {
    return (OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Compute_UnitTestConfiguration (
      verbose = F,
      name = "Default_Compute_Config",
      description = "Default Compute Configuration",
      numTests = 100,
      numTestVectorGenRetries = 100,
      failOnUnsatPreconditions = F,
      profile = OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Profile_P (
        name = "Compute_Default_Profile",
        api_channel1 = freshRandomLib,
        api_channel2 = freshRandomLib
      ),
      genReplay = (c: Container, testName: String, r: GumboXResult.Type) => Some(
       st"""Replay Unit Test:
            |  test("Replay: $testName") {
            |    val results = rts.GumboXUtil.GumboXResult.$r
            |    val json = st${tq}${rts.JSON.fromutilContainer(c, T)}${tq}.render
            |    val testVector = rts.JSON.toActuationOrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PreState_Container_P(json).left
            |    assert (testComputeCBV(testVector) == results)
            |  }""".render))
    )
  }
}

@record class OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Compute_UnitTestConfiguration (
  var verbose: B,
  var name: String,
  var description: String,
  var numTests: Z,
  var numTestVectorGenRetries: Z,
  var failOnUnsatPreconditions: B,
  var profile: OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_Profile_P_Trait,
  var genReplay: (Container, String, GumboXResult.Type) => Option[String])
  extends UnitTestConfigurationBatch with OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_GumboX_TestHarness {

  override def test(c: Container): GumboXResult.Type = {
    return testComputeCBV(c.asInstanceOf[OrLogic_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_PreState_Container])
  }
}
