#pragma once
#include <SimpleIni.h>

class Settings
{
public:
	[[nodiscard]] static Settings* GetSingleton()
	{
		static Settings singleton;
		return std::addressof(singleton);
	}

	void Load()
	{
		CSimpleIniA ini;
		ini.SetUnicode();
		ini.LoadFile(L"Data\\SKSE\\Plugins\\poisonChargesUI.ini");

		maxPoisonCharges = (int)ini.GetDoubleValue("settings", "iMaxPoisonCharges", 99);

		widgetRight_xpos = (float)ini.GetDoubleValue("settings", "fRightWidgetXpos", 50);
		widgetRight_ypos = (float)ini.GetDoubleValue("settings", "fRightWidgetYpos", 50);
		widgetRight_rotation = (float)ini.GetDoubleValue("settings", "fRightWidgetRot", 0);
		widgetRight_xscale = (float)ini.GetDoubleValue("settings", "fRightWidgetXscale", 1);
		widgetRight_yscale = (float)ini.GetDoubleValue("settings", "fRightWidgetYscale", 1);
		widgetRight_barGrowth = ini.GetBoolValue("settings", "bRightWidgetInvertBar", false);

		widgetLeft_xpos = (float)ini.GetDoubleValue("settings", "fLeftWidgetXpos", 50);
		widgetLeft_ypos = (float)ini.GetDoubleValue("settings", "fLeftWidgetYpos", 50);
		widgetLeft_rotation = (float)ini.GetDoubleValue("settings", "fLeftWidgetRot", 0);
		widgetLeft_xscale = (float)ini.GetDoubleValue("settings", "fLeftWidgetXscale", 1);
		widgetLeft_yscale = (float)ini.GetDoubleValue("settings", "fLeftWidgetYscale", 1);
		widgetLeft_barGrowth = ini.GetBoolValue("settings", "bLeftWidgetInvertBar", false);

		widget_barColor = (int)ini.GetDoubleValue("settings", "iWidgetBarColor", 0x9966ff);
		widget_borderColor = (int)ini.GetDoubleValue("settings", "iWidgetBorderColor", 0xDCDCDC);
		widget_bgColor = (int)ini.GetDoubleValue("settings", "iWidgetBGColor", 0x0A0A0A);
		bReposition = ini.GetBoolValue("debug", "bReposition", true);
	}
	
	std::uint32_t maxPoisonCharges = 99;
	bool          bReposition = true;

	float widgetRight_xpos{ 10.0f };
	float widgetRight_ypos{ 10.0f };
	float widgetRight_rotation{ 0.0f };
	float widgetRight_xscale{ 75.0f };
	float widgetRight_yscale{ 75.0f };
	float widgetLeft_xpos{ 50.0f };
	float widgetLeft_ypos{ 96.3f };
	float widgetLeft_rotation{ 0.0f };
	float widgetLeft_xscale{ 75.0f };
	float widgetLeft_yscale{ 75.0f };
	
	bool widgetRight_barGrowth = false;
	bool widgetLeft_barGrowth = false;

	std::uint32_t widget_barColor{ 0x9966ff };
	std::uint32_t widget_borderColor{ 0xDCDCDC };
	std::uint32_t widget_bgColor{ 0x0A0A0A };

private:
};
