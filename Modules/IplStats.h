#include <string>

class IplStats
{
	public:
	void start();
	void showStats();
	void fetchFolders(const char* dirLocation);
	void fetchFiles(const char* dirlocation2,std::string);
	void readFile(char FILENAME[95]);
};


