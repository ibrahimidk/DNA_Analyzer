#ifndef __DNA_SEQUENCE_H__
#define __DNA_SEQUENCE_H__

#include "nucleotides.h"
#include <string.h>
#include <stdlib.h>
#include <sstream> 
#include <list>
#include "fstream"

class DnaSequence
{
	public:
		DnaSequence(const char * data);
		DnaSequence(const std::string&);
		DnaSequence(const DnaSequence &); // copy CTOR 
		DnaSequence& operator =(const DnaSequence&); // copy assingment 	
		~DnaSequence();
		
		DnaSequence& operator =(const char*); 
		DnaSequence& operator =(const std::string&);
		friend std::ostream& operator<<(std::ostream &os, const DnaSequence  &);
		const char& operator[] (size_t) const;
		bool operator==(const DnaSequence &);
		bool operator!=(const DnaSequence &);
		
		size_t sequenceLength() const;
		
		void read_from(char* );	
		void write_to(char* ); 	
			
		DnaSequence getSlice(size_t , size_t ) const ;	    
		DnaSequence** getPairedStrand() const ;		
		long findSub(DnaSequence*) const ;		
		size_t countOccurrences(DnaSequence*) const ; 
		std::list<int> findAllSub(DnaSequence*) const ;		
		std::list<DnaSequence> FindConsensusSequences() const;		
		std::string getSequence();
		
	private:
		Nucleartide** m_nuclear;
		size_t m_length;
		
		void allocate_memory(const char* data,size_t length);
		void freeNuclear();
};



inline size_t DnaSequence::sequenceLength() const
{
	return m_length;
}

inline bool DnaSequence::operator!=(const DnaSequence &other)
{ 
	return !(*this == other);
}

inline const char& DnaSequence::operator[](size_t index) const
{
	if (index > m_length)
		throw std::invalid_argument("bad index");
		
	return m_nuclear[index]->get_char();
}

inline DnaSequence::~DnaSequence(){ 
	freeNuclear();
}

inline size_t DnaSequence::countOccurrences(DnaSequence* other) const
{
	return findAllSub(other).size();
} 

inline DnaSequence& DnaSequence::operator=(const std::string& newData)
{ 
	return (*this = newData.c_str() ) ; 
}

inline DnaSequence::DnaSequence(const char* data)
{
	allocate_memory(data,strlen(data));
}

inline DnaSequence::DnaSequence(const std::string& data)
{
	allocate_memory(data.c_str(),data.length());
}


#endif /* __DNA_SEQUENCE_H__ */










