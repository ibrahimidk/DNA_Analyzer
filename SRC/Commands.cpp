#include "Commands.h"
#include <string> 
#include <sstream>
#include <cstdlib> 
#include <cstring>


void newCommand::do_command()
{
	DnaSequence new_dna(m_all_command[1]);
	
	std::string name;
	if( m_all_command.size() == 2  )
	{
		name = DnaList::getInstance()->defualtName();
		DnaList::getInstance()->add(new_dna, name);
	}
	
	else
	{
		name = "";
		if(m_all_command[2][0] != '@')
		{
			std::cout << "must be @ befor the name." << std::endl;
			return;
		}
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			name += m_all_command[2][i];
			
		DnaList::getInstance()->add(new_dna, m_all_command[2]);
	}

	std::cout << '[' << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getid() << "]\t";
	std::cout << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getname() << "\t";
	std::cout << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getdna() << std::endl;

}

void loadCommand::do_command()
{
	if(m_all_command.size() > 3)
	{
		std::cout << "wrong input!!!" << std::endl;
		return;
	}

	const char* file_name = m_all_command[1].c_str();
	
	std::string line;
	std::ifstream myfile (file_name);
	DnaSequence new_dna("");
	if (myfile.is_open())
	{
		myfile >> line ;
		 new_dna = line;
		myfile.close();
	}
	
	else
	{
		std::cout << "error while opening file" << std::endl;
		return;
	}
	
	std::string dna_name = "";
	size_t i;

	if(m_all_command.size() == 3)
	{
		if(m_all_command[2][0] != '@')
		{
			std::cout << "you forget @ !!!" << std::endl;
			return;
		}
		
		for(i = 1; i < m_all_command[2].length(); ++i)
			dna_name += m_all_command[2][i];
	}
	
	else
	{
		for(i = 0; i < strlen(file_name) - 7 ; ++i)
			dna_name += file_name[i];
	}
	DnaList::getInstance()->add(new_dna, dna_name);
	
	std::cout << '[' << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getid() << ']' << "\t";
	std::cout <<  DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getname() << "\t" ;
	if(DnaList::getInstance()->getDna_by_id(DnaList::getInstance()->length() - 1).sequenceLength() >= 40)
	{
		size_t size = DnaList::getInstance()->getDna_by_id(DnaList::getInstance()->length() - 1).sequenceLength();

		for( i = 0; i <= 32; ++i )
		{
			std::cout << new_dna[i];

		}
		
		std::cout << "..." << new_dna[size - 3] << new_dna[size - 2] << new_dna[size-1] <<std::endl;
		
	}
	else
		std::cout << DnaList::getInstance()->getDna_by_id(DnaList::getInstance()->length() - 1) << std::endl;
}


void dupCommand::do_command()
{
	if(m_all_command.size() > 3)
	{
		std::cout << "wrong input!!!" << std::endl;
		return;
	}
	std::stringstream id;
	size_t i;
	for( i = 1; i < m_all_command[1].length(); ++i )
		id << m_all_command[1][i];

	int int_id = 0;
	id >> int_id;

	DnaSequence new_dna = DnaList::getInstance()->getdnalist()[int_id]->getdna();
	
	std::string dna_name = "";	
	if(m_all_command.size() == 3)
	{
		if(m_all_command[2][0] != '@')
		{
			std::cout << "you forget @ !!!" << std::endl;
			return;
		}
		
		for(i = 1; i < m_all_command[2].length(); ++i)
			dna_name += m_all_command[2][i];
	}

	else
	{
		dna_name = DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getname() + "1";
	}
	
	DnaList::getInstance()->add(new_dna, dna_name);

	std::cout << '[' << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getid() << "]\t";
	std::cout << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getname() << "\t";
	std::cout << DnaList::getInstance()->getdnalist()[DnaList::getInstance()->length() - 1]->getdna() << std::endl;

}

void sliceCommand::do_command()
{

}

void replaceCommand::do_command()
{

}

void concatCommand::do_command()
{

}

void pairCommand::do_command()
{

}

void delCommand::do_command()
{

}

void reenumCommand::do_command()
{

}

void saveCommand::do_command()
{

}

void lenCommand::do_command()
{	
	std::stringstream id;
	
	for(size_t i = 1; i < m_all_command[2].length(); ++i )
		id << m_all_command[1][i];
	if(m_all_command[1][0] == '#')
	{
		int int_id = 0;
		id >> int_id;
		std::cout << DnaList::getInstance()->getdnalist()[int_id]->getdna().sequenceLength() << std::endl;
	}
	
	
	if(m_all_command.size() < 2)
	{
		std::cout << "bad input" << std::endl;
		return;	
	}


	
}

void findCommand::do_command()
{
	if(m_all_command.size() < 2)
	{
		std::cout << "wrong command!!" << std::endl;
		return;
	}
	DnaSequence dna("T"), sub_dna("T"); 
	
	if(m_all_command[1][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			id << m_all_command[1][i];
		id >> int_id;
		dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	
	else if(m_all_command[1][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			name += m_all_command[1][i];
		dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	if(m_all_command[2][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			id << m_all_command[2][i];
		id >> int_id;
		sub_dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	else if(m_all_command[2][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			name += m_all_command[2][i];
		sub_dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	else
		sub_dna = m_all_command[2];
		
	std::cout << dna.findSub(&sub_dna) - 1 << std::endl;
	
		
}

void countCommand::do_command()
{
	if(m_all_command.size() < 2)
	{
		std::cout << "wrong command!!" << std::endl;
		return;
	}
	DnaSequence dna("T"), sub_dna("T"); 
	
	if(m_all_command[1][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			id << m_all_command[1][i];
		id >> int_id;
		dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	
	else if(m_all_command[1][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			name += m_all_command[1][i];
		dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	if(m_all_command[2][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			id << m_all_command[2][i];
		id >> int_id;
		sub_dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	else if(m_all_command[2][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			name += m_all_command[2][i];
		sub_dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	else
		sub_dna = m_all_command[2];
	
	
	std::cout << dna.countOccurrences(&sub_dna) << std::endl;
}

void findallCommand::do_command()
{
	if(m_all_command.size() < 2)
	{
		std::cout << "wrong command!!" << std::endl;
		return;
	}
	DnaSequence dna("T"), sub_dna("T"); 
	
	if(m_all_command[1][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			id << m_all_command[1][i];
		id >> int_id;
		dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	
	else if(m_all_command[1][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[1].length(); ++i )
			name += m_all_command[1][i];
		dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	if(m_all_command[2][0] == '#')
	{
		std::stringstream id;
		int int_id = 0;
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			id << m_all_command[2][i];
		id >> int_id;
		sub_dna = DnaList::getInstance()->getDna_by_id(int_id);
	}
	else if(m_all_command[2][0] == '@')
	{
		std::string name = "";
		
		for(size_t i = 1; i < m_all_command[2].length(); ++i )
			name += m_all_command[2][i];
		sub_dna = DnaList::getInstance()->getDna_by_name(name);
	}
	
	else
		sub_dna = m_all_command[2];
	
	std::list<int> f = dna.findAllSub(&sub_dna);
	for(std::list<int>::iterator it = f.begin(); it != f.end(); ++it )
		std::cout << *it << std::endl;

}

void helpCommand::do_command()
{

}

void listCommand::do_command()
{

}

void showCommand::do_command()
{
	
	for(int i = 0; i < DnaList::getInstance()->length() ; ++i)
	{
		std::cout << '[' << DnaList::getInstance()->getdnalist()[i]->getid() << "]\t";
		std::cout << DnaList::getInstance()->getdnalist()[i]->getname() << "\t";
		std::cout << DnaList::getInstance()->getdnalist()[i]->getdna() << std::endl;
		
	}
}

void quitCommand::do_command()
{
	std::cout << "bye bye" << std::endl;

}

