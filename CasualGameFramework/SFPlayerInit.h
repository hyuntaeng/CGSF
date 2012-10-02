#pragma once
#include "SFPlayerState.h"

class SFPlayerInit : public SFPlayerState
{
public:
	SFPlayerInit(SFPlayer* pOwner, ePlayerState State);
	~SFPlayerInit(void);

protected:
	virtual BOOL OnEnter() override;
	virtual BOOL OnLeave() override;
	virtual BOOL ProcessPacket(SFPacket* pPacket) override;
	virtual BOOL ProcessDBResult(SFMessage* pMessage) override;

private: //Packet Recv
	BOOL OnLogin(SFPacket* pPacket);

private: //DB Result
	BOOL OnDBLogin(SFMessage* pMessage);
};