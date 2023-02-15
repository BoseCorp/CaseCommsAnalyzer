#ifndef CASECOMMS_SIMULATION_DATA_GENERATOR
#define CASECOMMS_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class CaseCommsAnalyzerSettings;

class CaseCommsSimulationDataGenerator
{
public:
	CaseCommsSimulationDataGenerator();
	~CaseCommsSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, CaseCommsAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	CaseCommsAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //CASECOMMS_SIMULATION_DATA_GENERATOR