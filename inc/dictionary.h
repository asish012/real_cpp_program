#include <string>

class Dictionary
{
public:
	Dictionary(const std::string & filename);
	~Dictionary();

	bool check(const std::string & word) const;
};