#include "DnaSequence.h"






std::string DnaSequence::getSequence(){
	std::stringstream os ;
	for (size_t i=0 ; i < m_length ; i++ ){
		os << m_nuclear[i]->get_char();
	}
	os << "\0";
	return os.str();
}

DnaSequence::DnaSequence(const DnaSequence &other){ // copy CTOR 
	
	char* temp = new char[other.m_length]; 
	for ( size_t i=0 ; i < other.m_length ; i++ ){ // copying other nuclear 
		temp[i] = other.m_nuclear[i]->get_char();
	}
	allocate_memory(temp,other.m_length);
	delete [] temp;
	//std::cout << *this << std::endl;
}

DnaSequence& DnaSequence::operator=(const DnaSequence& other){ // copy assingment 	
	if ( this == &other || other.m_length == 0 )
		return *this;
	freeNuclear();
	char* temp = new char[other.m_length]; 
	for ( size_t i=0 ; i < other.m_length ; i++ ){ // copying other nuclear 
		temp[i] = other.m_nuclear[i]->get_char();
	}
	allocate_memory(temp,other.m_length);
	delete [] temp;
	return *this;
}

DnaSequence& DnaSequence::operator=(const char* newData){  // copy assignment from c-string 
	freeNuclear();
	allocate_memory(newData,strlen(newData));
	return *this;
} 

std::ostream& operator<<(std::ostream &os, const DnaSequence &dna)
{ 
	for ( size_t i=0 ; i < dna.m_length ; i++ ){
		os << dna.m_nuclear[i]->get_char();
	}
	os << std::endl;
	return os;
}

bool DnaSequence::operator==(const DnaSequence &other)
{
	if (m_length != other.m_length)
		return false;
		
	for (size_t i = 0 ; i < m_length ; i++){
		if ( m_nuclear[i] != other.m_nuclear[i])
			return false;
	}
	return true;
}

void DnaSequence::read_from(char* file_name)
{
	std::string line;
	std::ifstream myfile (file_name);
	if (myfile.is_open())
	{
		myfile >> line ;
		*this = line;
		myfile.close();
	}
	else
		throw "cant open file";
}
void DnaSequence::write_to(char* file_name)
{
	 std::ofstream myfile (file_name);
	  if (myfile.is_open())
	  {
	    myfile << *this << std::endl;
	    myfile.close();
	  }
	  else 
	  	throw "cant open file";
		
} 

DnaSequence DnaSequence::getSlice(size_t from, size_t to) const 
{

	if ( (from > to)  || from < 1  || to > m_length )
 		throw std::invalid_argument("index out of range ");
	char* temp = new char[(to-from)+1] ;
	size_t j =0;
	for ( size_t i= from ; i < to-1 ; i++ ){ 
		temp[j++]= m_nuclear[i]->get_char();
	}
	temp[j] = '\0';
	DnaSequence res(temp);
	delete [] temp;
	return (res);
}

DnaSequence** DnaSequence::getPairedStrand() const 
{
	std::string temp ;
	DnaSequence** result = new DnaSequence*[2];
	size_t i = 0;
	for ( ;i < m_length; ){ 
		temp += m_nuclear[i++]->pair();
	}
	result[0] = new DnaSequence(temp);
	temp="";
	i = m_length-1;
	while ( i != 0 ){ 
		temp += m_nuclear[i--]->pair();
	}
	temp+= m_nuclear[i]->pair();
	result[1] = new DnaSequence(temp);
	return (result);
}

long DnaSequence::findSub(DnaSequence* other)const
{
	if ( other->m_length > m_length )
		return -1;
	size_t i;
    for (i = 0 ; i <= (m_length)-(other->m_length); ++i)
    {
    	size_t j;
        for ( j = 0; j < (other->m_length) ; ++j){
            if ( m_nuclear[i + j]->get_char() != other->m_nuclear[j]->get_char() )
                break;
        }
        if (j == other->m_length){

            return (long)(i+1);}
    }
    return -1;
}

std::list<int> DnaSequence::findAllSub(DnaSequence* other) const 
{
	if ( other->m_length > m_length )
		return std::list<int>();
 
    std::list<int> allSub;
    for (size_t i = 0; i <= (m_length)-(other->m_length); i++) 
    {   
        size_t j; 
        for (j = 0; j < (other->m_length); j++) 
            if ( m_nuclear[i + j]->get_char() != other->m_nuclear[j]->get_char() )
                break; 
   
        if (j == other->m_length)   
        { 
           allSub.push_back(int(i));
           j = 0;
        } 
    } 
    return allSub;
}

std::list<DnaSequence> DnaSequence::FindConsensusSequences()const 
{ 
	DnaSequence startSeq("ATG");
	DnaSequence ds[] = {DnaSequence((char*)"TAG"),DnaSequence((char*)"TAA"),DnaSequence((char*)"TGA")};
	std::list<DnaSequence> result;
	
	long position = findSub(&startSeq);
	while ( position != -1 ){
		long min_end_pos = -1 ;
		for(long i =0 ; i<3;i++){	
			long end_pos = findSub(&ds[i]);
			if (min_end_pos == -1 || ( end_pos!=-1 && end_pos < min_end_pos))
				min_end_pos = end_pos;
		}
		if (min_end_pos != -1){
			result.push_back(getSlice(position,min_end_pos+3));
		    position = getSlice(position,sequenceLength()).findSub(&startSeq);
		
		}else
			break;	
	}
	return result;
}

void DnaSequence::allocate_memory(const char* data,size_t length){
	m_nuclear = new Nucleartide*[length];
	for (size_t i=0 ; i< length ;i++){
		m_nuclear[i] = new Nucleartide(data[i]);
	}
	m_length = length;
}

void DnaSequence::freeNuclear(){
	for (size_t i= 0 ; i < m_length ;i++){
		delete m_nuclear[i];
	}
	
	delete [] m_nuclear;
}


