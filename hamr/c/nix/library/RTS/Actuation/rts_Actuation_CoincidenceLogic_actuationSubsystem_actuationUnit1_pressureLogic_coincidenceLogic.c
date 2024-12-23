#include <all.h>

Unit rts_Actuation_CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_initialise(STACK_FRAME rts_Actuation_CoincidenceLogic_Initialization_Api api) {
  DeclNewStackFrame(caller, "CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic.scala", "rts.Actuation.CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic", "initialise", 0);

  sfUpdateLoc(23);
  {
    rts_Actuation_CoincidenceLogic_Initialization_Api_put_actuate_(SF api, F);
  }
}

Unit rts_Actuation_CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_timeTriggered(STACK_FRAME rts_Actuation_CoincidenceLogic_Operational_Api api) {
  DeclNewStackFrame(caller, "CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic.scala", "rts.Actuation.CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic", "timeTriggered", 0);

  sfUpdateLoc(59);
  B a;
  {
    DeclNewOption_8F4D4C(t_0);
    rts_Actuation_CoincidenceLogic_Operational_Api_get_channel1_(SF (Option_8F4D4C) &t_0, api);
    B t_1 = Option_8F4D4C_get_(SF ((Option_8F4D4C) &t_0));
    a = t_1;
  }

  sfUpdateLoc(60);
  B b;
  {
    DeclNewOption_8F4D4C(t_2);
    rts_Actuation_CoincidenceLogic_Operational_Api_get_channel2_(SF (Option_8F4D4C) &t_2, api);
    B t_3 = Option_8F4D4C_get_(SF ((Option_8F4D4C) &t_2));
    b = t_3;
  }

  sfUpdateLoc(61);
  B c;
  {
    DeclNewOption_8F4D4C(t_4);
    rts_Actuation_CoincidenceLogic_Operational_Api_get_channel3_(SF (Option_8F4D4C) &t_4, api);
    B t_5 = Option_8F4D4C_get_(SF ((Option_8F4D4C) &t_4));
    c = t_5;
  }

  sfUpdateLoc(62);
  B d;
  {
    DeclNewOption_8F4D4C(t_6);
    rts_Actuation_CoincidenceLogic_Operational_Api_get_channel4_(SF (Option_8F4D4C) &t_6, api);
    B t_7 = Option_8F4D4C_get_(SF ((Option_8F4D4C) &t_6));
    d = t_7;
  }

  sfUpdateLoc(84);
  B result;
  {
    result = B__or(B__or(B__and(a, b), B__and(B__or(a, b), B__or(c, d))), B__and(c, d));
  }

  sfUpdateLoc(87);
  {
    rts_Actuation_CoincidenceLogic_Operational_Api_put_actuate_(SF api, result);
  }
}

Unit rts_Actuation_CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_finalise(STACK_FRAME rts_Actuation_CoincidenceLogic_Operational_Api api) {
  DeclNewStackFrame(caller, "CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic.scala", "rts.Actuation.CoincidenceLogic_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic", "finalise", 0);
}