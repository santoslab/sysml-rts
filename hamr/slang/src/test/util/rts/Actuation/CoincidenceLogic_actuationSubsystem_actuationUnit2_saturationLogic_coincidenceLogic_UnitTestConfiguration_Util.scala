// #Sireum

package rts.Actuation

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

import org.sireum._
import rts.GumboXUtil.GumboXResult
import rts.util.{Container, Profile, UnitTestConfigurationBatch}
import rts.RandomLib
import org.sireum.Random.Impl.Xoshiro256

object CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_UnitTestConfiguration_Util {

  def freshRandomLib: RandomLib = {
    return RandomLib(Random.Gen64Impl(Xoshiro256.create))
  }

  val tq: String = "\"\"\""

  type DefaultComputeProfile = CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P

  def defaultComputeConfig: CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Compute_UnitTestConfiguration = {
    return (CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Compute_UnitTestConfiguration (
      verbose = F,
      name = "Default_Compute_Config",
      description = "Default Compute Configuration",
      numTests = 100,
      numTestVectorGenRetries = 100,
      failOnUnsatPreconditions = F,
      profile = CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P (
        name = "Compute_Default_Profile",
        api_channel1 = freshRandomLib,
        api_channel2 = freshRandomLib,
        api_channel3 = freshRandomLib,
        api_channel4 = freshRandomLib
      ),
      genReplay = (c: Container, testName: String, r: GumboXResult.Type) => Some(
       st"""Replay Unit Test:
            |  test("Replay: $testName") {
            |    val results = rts.GumboXUtil.GumboXResult.$r
            |    val json = st${tq}${rts.JSON.fromutilContainer(c, T)}${tq}.render
            |    val testVector = rts.JSON.toActuationCoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container_P(json).left
            |    assert (testComputeCBV(testVector) == results)
            |  }""".render))
    )
  }
}

@record class CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Compute_UnitTestConfiguration (
  var verbose: B,
  var name: String,
  var description: String,
  var numTests: Z,
  var numTestVectorGenRetries: Z,
  var failOnUnsatPreconditions: B,
  var profile: CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_Profile_P_Trait,
  var genReplay: (Container, String, GumboXResult.Type) => Option[String])
  extends UnitTestConfigurationBatch with CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_GumboX_TestHarness {

  override def test(c: Container): GumboXResult.Type = {
    return testComputeCBV(c.asInstanceOf[CoincidenceLogic_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_PreState_Container])
  }
}
