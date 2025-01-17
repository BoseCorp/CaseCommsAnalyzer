#ifndef CASECOMMS_ANALYZER_SETTINGS
#define CASECOMMS_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

class CaseCommsAnalyzerSettings : public AnalyzerSettings
{
public:
	CaseCommsAnalyzerSettings();
	virtual ~CaseCommsAnalyzerSettings();

	virtual bool SetSettingsFromInterfaces();
	void UpdateInterfacesFromSettings();
	virtual void LoadSettings( const char* settings );
	virtual const char* SaveSettings();

	
	Channel mInputChannel;
	U32 mBitRate;

protected:
	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mInputChannelInterface;
	std::auto_ptr< AnalyzerSettingInterfaceInteger >	mBitRateInterface;
};

#endif //CASECOMMS_ANALYZER_SETTINGS
