#ifndef CLI_H
#define CLI_H
#include "Commands.h"
#include<vector>
#include<sstream>


class CLI
{
	public:
		CLI() {}
		~CLI() {}
		
		void start();
		
	private:
		std::vector<std::string> parsing(std::string&);
		Command* getCommand(std::string com, std::vector<std::string>& allCommand);
};


inline std::vector<std::string> CLI::parsing(std::string& input)
{
	std::vector<std::string> result;
	
    std::stringstream ss(input);
    std::string token;
    char delim = ' ';
    while (std::getline(ss, token, delim)) {
            result.push_back(token);
    }
    
    return result;
}

inline Command* CLI::getCommand(std::string com, std::vector<std::string>& allCommand)
{
	if(com == "new")
		return new newCommand(allCommand);
	
	if(com == "load")
		return new loadCommand(allCommand);
	
	if(com == "dup")
		return new dupCommand(allCommand);
		
	if(com == "slice")
		return new sliceCommand(allCommand);
		
	if(com == "replace")
		return new replaceCommand(allCommand);
	
	if(com == "concat")
		return new concatCommand(allCommand);
	
	if(com == "pair")
		return new pairCommand(allCommand);
		
	if(com == "del")
		return new delCommand(allCommand);
		
	if(com == "reenum")
		return new reenumCommand(allCommand);
	
	if(com == "save")
		return new saveCommand(allCommand);
	
	if(com == "len")
		return new lenCommand(allCommand);
		
	if(com == "find")
		return new findCommand(allCommand);
	
	if(com == "count")
		return new countCommand(allCommand);
	
	if(com == "findall")
		return new findallCommand(allCommand);
		
	if(com == "help")
		return new helpCommand(allCommand);
		
	if(com == "list")
		return new listCommand(allCommand);
	
	if(com == "show")
		return new showCommand(allCommand);
	
	
	if(com == "quit")
		return new quitCommand(allCommand);
		
	else 
		return NULL;
		
}



#endif /* CLI_H */
