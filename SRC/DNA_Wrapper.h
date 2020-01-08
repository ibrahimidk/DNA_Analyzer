#ifndef DNA_WRAPPER_H
#define DNA_WRAPPER_H

#include"DnaSequence.h"
#include<vector>
#include<map>
#include<sstream>

/*________________________________________ the dna seq wrapper func __________________________________ */
class DNA_Seq
{
	
	public:
		DNA_Seq(const DnaSequence& dna, std::string name, int id): m_name(name), m_id(id), m_dna(dna) {}
		DNA_Seq(const DNA_Seq &other):m_name(other.getname()), m_id(other.getid()), m_dna(other.getdna()) {}
		
		~DNA_Seq() {}
		
		unsigned int getid() const;
		std::string getname()const;
		DnaSequence getdna()const;
		
	
	
	private:
		std::string m_name;
		int m_id;
		DnaSequence m_dna;
};  
/*________________________________________ dna_seq inline func __________________________________ */

inline unsigned int DNA_Seq::getid()const
{
	return m_id;
}

inline std::string DNA_Seq::getname()const
{
	return m_name;
}

inline DnaSequence DNA_Seq::getdna()const
{
	return m_dna;
}

/*________________________________________ dna_seq list __________________________________ */


class DnaList
{
	public: 
		~DnaList() {delete[] m_dnalist;}
		static DnaList* getInstance();
		
		
		
		void add(DnaSequence dna, std::string name = "");
		DnaSequence getDna_by_name(std::string name);
		DnaSequence getDna_by_id(int index);
		int length();
		std::map<int, DNA_Seq*> getdnalist();
		std::string defualtName();
		
	private:
		DnaList();
		static DnaList* m_dnalist;
		

		std::map<int, DNA_Seq*> m_DnaList;
		std::map<std::string, int> m_names;
		unsigned int m_defualtName;
		
};
/*________________________________________ dna_seq list inline func __________________________________ */

inline void DnaList::add(DnaSequence dna, std::string name)
{

	if(name.empty())
	{
		name = defualtName();	
	}
	

	
	int id = (int)(m_DnaList.size());

	if( m_names[name] != id )
	{
		std::cout << "this name is used!! defult name gived" <<std::endl;
		name = defualtName();
	}
	
	DNA_Seq* new_s = new DNA_Seq(dna, name, id);
	
	m_DnaList[id] = new_s;
	
	m_names[name] = id;

}

inline std::map<int, DNA_Seq*> DnaList::getdnalist()
{
	return m_DnaList;
}

inline std::string DnaList::defualtName()
{
	std::stringstream name;
	name << "dna_seq" << m_defualtName;
	++m_defualtName;
	
	return name.str();
}

inline DnaSequence DnaList::getDna_by_name(std::string name)
{
	return m_DnaList[m_names[name]]->getdna();
}

inline DnaSequence DnaList::getDna_by_id(int index)
{
	return m_DnaList[index]->getdna();
}

inline int DnaList::length()
{
	return (int)m_DnaList.size();
}


#endif /* DNA_WRAPPER_H */
















