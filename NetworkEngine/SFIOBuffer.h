#pragma once

class SFIOBuffer
{
	#define MAX_IO_SIZE 16384

public:
	SFIOBuffer();
	virtual ~SFIOBuffer();

	VOID	InitIOBuf();
	BOOL	AllocIOBuf(int iBufSize);
	BOOL	FreeIOBuf();

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

	int		AppendData(const char* pBuffer, int iSize);
	int		GetData(char* pBuffer, int iSize);
	
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

	inline char* GetBuffer() { return	m_pBuffer; }
	inline int	GetBufSize() { return m_iBufSize; }

	inline int GetUsedBufferSize() { return m_iUsedBufferSize; }
	inline int GetEmptyBufferSize() { return m_iBufSize - m_iUsedBufferSize; }

	void	CalcUsedBufferSize();
	

private:
	int		m_iHead;
	INT		m_iTail;

	int		m_iBufSize;
	
	CHAR*	m_pBuffer;

	int		m_iUsedBufferSize;
};