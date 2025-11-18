package EventControl {
	
	private import AADL::*;
	private import AADL_Project::*;
	private import SI::*;
	
	part def EventControlMockProcess :> Process {
		part eventControlMockThread : EventControlMockThread;
		
		out port manualActuatorInput1 : DataPort { out :> type : Base_Types::Data_Boolean; }
		out port manualActuatorInput2 : DataPort { out :> type : Base_Types::Data_Boolean; }
		
		connection mAI1 : PortConnection connect eventControlMockThread.manualActuatorInput1 to manualActuatorInput1;
		connection mAI2 : PortConnection connect eventControlMockThread.manualActuatorInput2 to manualActuatorInput2;
	}
	
	part def EventControlMockThread :> Thread {
		out port manualActuatorInput1 : DataPort { out :> type : Base_Types::Data_Boolean; }
		out port manualActuatorInput2 : DataPort { out :> type : Base_Types::Data_Boolean; }
		
		attribute :>> Dispatch_Protocol = Supported_Dispatch_Protocols::Periodic;
		attribute :>> Period = 1 [s];
		//@Properties {
		//	Dispatch_Protocol = Periodic;
		//	Period = 1000;
		//}
	}
	
}