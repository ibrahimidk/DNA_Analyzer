#include "DNA_Wrapper.h"

DnaList* DnaList::m_dnalist=NULL;

DnaList* DnaList::getInstance()
{
	if(!m_dnalist)
	{
		m_dnalist = new DnaList();
	}
	
	return m_dnalist;
}

DnaList::DnaList()
{
	m_defualtName = 0;	
}
