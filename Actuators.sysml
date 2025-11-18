package Actuators {
	
	private import AADL::*;
	private import AADL_Project::*;
	private import SI::*;
	
	part def ActuatorsMockProcess :> Process {
		part actuatorsMockThread : ActuatorsMockThread;
		
        in port tempPressureActuate : DataPort { in :> type : Base_Types::Data_Boolean; }
		in port saturationActuate : DataPort { in :> type : Base_Types::Data_Boolean; }
		
		connection tPA : PortConnection connect tempPressureActuate to actuatorsMockThread.tempPressureActuate;
		connection sA : PortConnection connect saturationActuate to actuatorsMockThread.saturationActuate;
	}
	
	part def ActuatorsMockThread :> Thread {
		in port tempPressureActuate : DataPort { in :> type : Base_Types::Data_Boolean; }
		in port saturationActuate : DataPort { in :> type : Base_Types::Data_Boolean; }

		attribute :>> Dispatch_Protocol = Supported_Dispatch_Protocols::Periodic;
		attribute :>> Period = 1 [s];
		
		//@Properties {
		//	Dispatch_Protocol = Periodic;
		//	Period = 1000;
		//}
	}
	
}