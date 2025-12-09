#pragma once

#include "poisonMeterMenu.h"
#include "Events.h"

bool isOnFavorites = true;

std::uint32_t poisonCharges = 0;

void Init()
{
	Settings::GetSingleton()->Load();
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);

	Init();

	auto g_message = SKSE::GetMessagingInterface();
	g_message->RegisterListener([](SKSE::MessagingInterface::Message* msg) -> void
		{

			switch (msg->type) {
			case SKSE::MessagingInterface::kDataLoaded:
				MenuOpenCloseEventHandler::Register();
				
				logs::info("Registering poison meter menu.");
				poisonMeterMenu::Register();
				break;
			}
		});


	return true;
}
