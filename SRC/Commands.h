#ifndef COMMANDS_H
#define COMMANDS_H
#include<vector>
#include<string>
#include "DNA_Wrapper.h"


class Command {
	public:
		virtual void do_command() = 0;
};




class newCommand:public Command
{
	public:
		newCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();
    	
    private:
    	std::vector<std::string>& m_all_command;
};

class loadCommand:public Command
{
	public:
		loadCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;
};

class dupCommand:public Command
{
	public:
		dupCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class sliceCommand:public Command
{
	public:
		sliceCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class replaceCommand:public Command
{
	public:
		replaceCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class concatCommand:public Command
{
	public:
		concatCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;
    	
};

class pairCommand:public Command
{
	public:
		pairCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class renameCommand:public Command
{
	public:
		renameCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class delCommand:public Command
{
	public:
		delCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class reenumCommand:public Command
{
	public:
		reenumCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class saveCommand:public Command
{
	public:
		saveCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class lenCommand:public Command
{
	public:
		lenCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class findCommand:public Command
{
	public:
		findCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class countCommand:public Command
{
	public:
		countCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class findallCommand:public Command
{
	public:
		findallCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class helpCommand:public Command
{
	public:
		helpCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class listCommand:public Command
{
	public:
		listCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};

class showCommand:public Command
{
	public:
		showCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};


class quitCommand:public Command
{
	public:
		quitCommand(std::vector<std::string>& command):m_all_command(command) {}
    	void do_command();

    private:
    	std::vector<std::string>& m_all_command;

};


#endif /* COMMANDS_H */
