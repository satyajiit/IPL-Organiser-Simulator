#include <string>

class AnalyzePlayers
{
	public:
		void start();
		void showTeamsAndPlayers();
		void fetchFiles(const char* dirlocation2,std::string);
		void fetchFolders(const char* dirlocation);
		void readFile(char FILENAME[95]);
	
};


