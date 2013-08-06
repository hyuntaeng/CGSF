#include "stdafx.h"
#include "ChatLogicJsonEntry.h"
#include "ChatUser.h"
#include "PacketID.h"
#include "SFSinglton.h"
#include <iostream>
#include "SFEngine.h"
#include "SFJsonPacket.h"

extern SFEngine* g_pEngine;

ChatLogicJsonEntry::ChatLogicJsonEntry(void)
{
}


ChatLogicJsonEntry::~ChatLogicJsonEntry(void)
{
}

BOOL ChatLogicJsonEntry::ProcessPacket(BasePacket* pPacket )
{
	switch (pPacket->GetPacketType())
	{
	case SFPacket_Connect:
		{	
			OnConnectPlayer(pPacket->GetOwnerSerial());
		}
		break;

	case SFPacket_Data:
		{	
			OnPlayerData(pPacket);
		}
		break;

	case SFPacket_Disconnect:
		{	
			OnDisconnectPlayer(pPacket->GetOwnerSerial());
		}
		break;

	case SFPacket_Timer:
		{	
			//OnTimer(pCommand->GetOwnerSerial());
		}
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

BOOL ChatLogicJsonEntry::OnConnectPlayer( int Serial )
{
	ChatUser* pUser = new ChatUser();
	pUser->SetSerial(Serial);

	m_ChatUserMap.insert(ChatUserMap::value_type(Serial, pUser));

	return TRUE;
}

BOOL ChatLogicJsonEntry::OnDisconnectPlayer( int Serial )
{
	ChatUserMap::iterator iter = m_ChatUserMap.find(Serial);

	if(iter == m_ChatUserMap.end())
	{
		SFASSERT(0);
		return FALSE;
	}

	ChatUser* pUser = iter->second;

	delete pUser;

	m_ChatUserMap.erase(iter);

	return TRUE;
}

BOOL ChatLogicJsonEntry::OnPlayerData( BasePacket* pPacket )
{
	SFJsonPacket* pJsonPacket = (SFJsonPacket*)pPacket;
	int PacketID = pJsonPacket->GetData().GetValue<int>("PacketId");

	if(PacketID == 1234)
	{
		std::cout << pJsonPacket->GetData().GetValue<tstring>("chat") << std::endl;

		
		SFJsonPacket JsonPacket;
		JsonObjectNode& ObjectNode = JsonPacket.GetData();
		ObjectNode.Add("PacketId", 1234);
		ObjectNode.Add("chat", pJsonPacket->GetData().GetValue<tstring>("chat"));

		Broadcast(&JsonPacket);

		return TRUE;
	}

	return FALSE;
}

BOOL ChatLogicJsonEntry::SendRequest(BasePacket* pPacket)
{
	g_pEngine->SendRequest(pPacket);

	return TRUE;
}

BOOL ChatLogicJsonEntry::Broadcast( BasePacket* pPacket)
{
	ChatUserMap::iterator iter = m_ChatUserMap.begin();

	for(;iter != m_ChatUserMap.end(); iter++)
	{
		//if(pPacket->GetOwnerSerial() != iter->first)
		pPacket->SetOwnerSerial(iter->first);	
		SendRequest(pPacket);
	}

	return TRUE;
}