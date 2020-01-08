#include "CLI.h"
#include<vector>




void CLI::start()
{
	while(true)
	{
	
		std::cout << "cmd>>> ";
		std::vector<std::string> newcommand ;

		std::string input;
		getline(std::cin, input);
		newcommand = CLI::parsing(input);
		Command* command = CLI::getCommand(newcommand[0], newcommand);
		if( command == NULL)
		{
			std::cout << "wrong command !!!!!" << std::endl; 	
		}
		else
			command->do_command();
				
		if(newcommand[0] == "quit")
		{
			break;
		}		
	}
}

