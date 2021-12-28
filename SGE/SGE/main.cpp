#include "headers.h"

template <typename T>
void Log(T message)
{
	std::cout << message << std::endl;
}


struct section
{
	std::string s[48];
	int p[48];
};

int main()
{
	std::string save = "3.ck3";
	const int size = std::filesystem::file_size(save);

	std::string save_content(size, '\0');
	std::ifstream save_file;

	save_file.open(save, std::ios::in);
	save_file.read(save_content.data(), size);

	std::string log_file = "log.txt";
	std::ofstream dest;
	std::ofstream log;
	log.open(log_file, std::ios::out);

	section some;
	some.s[0] = "meta_data";
	some.s[1] = "ironman_manager";
	some.s[2] = "date";
	some.s[3] = "bookmark_date";
	some.s[4] = "first_start";
	some.s[5] = "speed";
	some.s[6] = "random_seed";
	some.s[7] = "random_count";
	some.s[8] = "variables";
	some.s[9] = "game_rules";
	some.s[10] = "provinces";
	some.s[11] = "landed_titles";
	some.s[12] = "dynasties";
	some.s[13] = "deleted_characters";
	some.s[14] = "living";
	some.s[15] = "dead_unprunable";
	some.s[16] = "characters";
	some.s[17] = "character_lookup";
	some.s[18] = "units";
	some.s[19] = "activities";
	some.s[20] = "opinions";
	some.s[21] = "relations";
	some.s[22] = "schemes";
	some.s[23] = "stories";
	some.s[24] = "pending_character_interactions";
	some.s[25] = "secrets";
	some.s[26] = "armies";
	some.s[27] = "combats";
	some.s[28] = "religion";
	some.s[29] = "wars";
	some.s[30] = "sieges";
	some.s[31] = "raid";
	some.s[32] = "succession";
	some.s[33] = "holdings";
	some.s[34] = "ai";
	some.s[35] = "county_manager";
	some.s[36] = "fleet_manager";
	some.s[37] = "council_task_manager";
	some.s[38] = "important_action_manager";
	some.s[39] = "faction_manager";
	some.s[40] = "culture_manager";
	some.s[41] = "mercenary_company_manager";
	some.s[42] = "holy_orders";
	some.s[43] = "coat_of_arms";
	some.s[44] = "triggered_event";
	some.s[45] = "next_player_event_id";
	some.s[46] = "played_character";
	some.s[47] = "currently_played_characters";

	for(int i = 0; i < 48; i++)
	{
		if (i < 1)
		{
			some.p[i] = save_content.find(some.s[i], 0);
		}
		else
		{
			int j = 0;
			j = i - 1;
			some.p[i] = save_content.find(some.s[i], some.p[j]);

		}
	}
	for (int i = 0; i < 48; i++)
		{
		if (i <47)
		{
		dest.open("D:\\source\\SGE\\SGE\\temp\\" + some.s[i] + ".txt", std::ios::out);
		dest << save_content.substr(some.p[i], some.p[i+1] - some.p[i]);
		dest.close();
		}
		else
		{
			dest.open("D:\\source\\SGE\\SGE\\temp\\" + some.s[i] + ".txt", std::ios::out);
			dest << save_content.substr(some.p[i], size - some.p[i]);
			dest.close();
		}
		std::cout << some.p[i] << ", " << some.s[i] << std::endl;
		log << some.p[i] << ", " << some.s[i] << std::endl;
	}
	
	//Log(save_content);
	//Log(save_content);
}