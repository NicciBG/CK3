#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>
#include <chrono>


template <typename T>
void LogCon(T message)
{
	std::cout << message << std::endl;
}
//template <typename T>
//void Log(T message)
//{
//	
//	log_file << message << std::endl;
//	log_file.close();
//}

int main()
{





 
	std::ifstream log_file;
	log_file.open("log.txt", std::ios::out);

	std::string file_name = "inout.txt";
	int file_size = std::filesystem::file_size(file_name);
	std::string content(file_size, '\0');
	std::ifstream input_file;
	input_file.open(file_name, std::ios::in);
	// TO-DO: Add check if the file is open
	input_file.read(content.data(), file_size);
	int o = 0;
	int c = 0;
	for (int i = 0; file_size; i++)
	{
		int b_holding = content.find("holding={", i);
		std::smatch match;






		//int b_entry = content.find();
		
	}
	


}





	//std::string provinces;
	//std::string landed_titles;
	//std::string dynasties;
	//std::string living;
	//std::string units;
	//std::string relations;
	//std::string religion;
	//std::string county_manager;
	//std::string culture_manager;
