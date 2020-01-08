#ifndef __Nucleartide_H__
#define __Nucleartide_H__
#include <stdexcept>
#include <iostream>

class Nucleartide
{

	public:
		Nucleartide(const char& sub);
		~Nucleartide() {}
		const char& get_char() const;
		const char pair() const;
		
	private:
		char m_nuc;
		bool check_data_validation(const char& dna) const;
		
};


inline Nucleartide::Nucleartide(const char& sub):m_nuc(sub)
{
	if ( !check_data_validation(sub) )
		throw std::invalid_argument( "received invalid nucleotides!!!" );
}

inline const char& Nucleartide::get_char() const 
{ 
	return m_nuc;
}

inline bool Nucleartide::check_data_validation(const char& m_nuc) const 
{
    if(m_nuc == 'A' || m_nuc == 'T' || m_nuc == 'C' || m_nuc == 'G')
    {
        return true;
	}
	return false;
}

inline const char Nucleartide::pair() const
{
    if (m_nuc == 'A')
        return 'T';
    else if (m_nuc =='T')
    	return 'A';
	else if (m_nuc == 'C')
		return 'G';
	else 
		return 'C';
}

#endif // __Nucleartide_H__


