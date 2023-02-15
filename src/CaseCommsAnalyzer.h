#ifndef CASECOMMS_ANALYZER_H
#define CASECOMMS_ANALYZER_H

#include <Analyzer.h>
#include "CaseCommsAnalyzerResults.h"
#include "CaseCommsSimulationDataGenerator.h"

class CaseCommsAnalyzerSettings;
class ANALYZER_EXPORT CaseCommsAnalyzer : public Analyzer2
{
public:
	CaseCommsAnalyzer();
	virtual ~CaseCommsAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< CaseCommsAnalyzerSettings > mSettings;
	std::auto_ptr< CaseCommsAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	CaseCommsSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //CASECOMMS_ANALYZER_H
