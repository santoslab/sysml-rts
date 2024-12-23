// #Sireum

package rts.Actuation

import org.sireum._
import rts._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
object CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_GumboX {
  /** Compute Entrypoint Contract
    *
    * guarantee coincidenceOutput
    *   "from actuationUnit.cry
    *   Coincidence_2_4 : [4]TripPort -> Bit
    *   Coincidence_2_4 x =
    *       (a&&b) || ((a||b) && (c||d)) || (c&&d)
    *   For specification redundancy, provide an alternate but equivalent specification
    *   of the concept 'at least two of the input channels are true.'"
    * @param api_channel1 incoming data port
    * @param api_channel2 incoming data port
    * @param api_channel3 incoming data port
    * @param api_channel4 incoming data port
    * @param api_actuate outgoing data port
    */
  @strictpure def compute_spec_coincidenceOutput_guarantee(
      api_channel1: Base_Types.Boolean,
      api_channel2: Base_Types.Boolean,
      api_channel3: Base_Types.Boolean,
      api_channel4: Base_Types.Boolean,
      api_actuate: Base_Types.Boolean): B =
    api_actuate == (api_channel1 & api_channel2 |
       (api_channel1 & api_channel3 |
         (api_channel1 & api_channel4 |
           (api_channel2 & api_channel3 |
             (api_channel2 & api_channel4 |
               api_channel3 & api_channel4)))))

  /** CEP-T-Guar: Top-level guarantee contracts for coincidenceLogic's compute entrypoint
    *
    * @param api_channel1 incoming data port
    * @param api_channel2 incoming data port
    * @param api_channel3 incoming data port
    * @param api_channel4 incoming data port
    * @param api_actuate outgoing data port
    */
  @strictpure def compute_CEP_T_Guar (
      api_channel1: Base_Types.Boolean,
      api_channel2: Base_Types.Boolean,
      api_channel3: Base_Types.Boolean,
      api_channel4: Base_Types.Boolean,
      api_actuate: Base_Types.Boolean): B =
    compute_spec_coincidenceOutput_guarantee(api_channel1, api_channel2, api_channel3, api_channel4, api_actuate)

  /** CEP-Post: Compute Entrypoint Post-Condition for coincidenceLogic
    *
    * @param api_channel1 incoming data port
    * @param api_channel2 incoming data port
    * @param api_channel3 incoming data port
    * @param api_channel4 incoming data port
    * @param api_actuate outgoing data port
    */
  @strictpure def compute_CEP_Post (
      api_channel1: Base_Types.Boolean,
      api_channel2: Base_Types.Boolean,
      api_channel3: Base_Types.Boolean,
      api_channel4: Base_Types.Boolean,
      api_actuate: Base_Types.Boolean): B =
    (// CEP-Guar: guarantee clauses of coincidenceLogic's compute entrypoint
     compute_CEP_T_Guar (api_channel1, api_channel2, api_channel3, api_channel4, api_actuate))

  /** CEP-Post: Compute Entrypoint Post-Condition for coincidenceLogic via containers
    *
    * @param pre Container holding the values of incoming ports and the pre-state values of state variables
    * @param post Container holding the values of outgoing ports and the post-state values of state variables
    */
  @strictpure def compute_CEP_Post_Container(
      pre: CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_PreState_Container_PS,
      post: CoincidenceLogic_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_PostState_Container_PS): B =
    compute_CEP_Post(
      api_channel1 = pre.api_channel1,
      api_channel2 = pre.api_channel2,
      api_channel3 = pre.api_channel3,
      api_channel4 = pre.api_channel4,
      api_actuate = post.api_actuate)
}
