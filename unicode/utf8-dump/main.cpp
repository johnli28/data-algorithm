#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using std::string;

typedef std::basic_string<unsigned char> ustring;

string String2Hex(const string& s, bool upper_case = true)
{
	std::stringstream ss(s);

	ss << std::hex << std::setw(2);

	for (int i = 0; i<s.size(); ++i)
	{
		ss << "0x";
		
		//Convert char to unsigned char to get unicode byte values, because char might be minus
		unsigned char uc = s[i];

		//Convert unsigned char to unsigned int and input to stream for dumping purpose
		uint16_t intByte = (uint16_t)(uc);
		
		if (intByte < 16)
		{
			ss << 0;
		}

		//Implicit conversion from int to char
		ss << intByte;
		ss << ' ';
	}

	return ss.str();
}


void ReadAndDumpAnsiFile(const string& fileName)
{
	std::ifstream ifs;
	ifs.open(fileName, std::ifstream::in);

	if (!ifs.good())
	{
		std::cout << "Failed to open file: " << fileName << std::endl;
		return;
	}

	std::cout << "***************Starting dump file contents: " << fileName << "***************" << std::endl;

	for (std::string line; std::getline(ifs, line); )
	{
		std::cout << line << std::endl;
	}

	std::cout << "***************End of file: " << fileName << "***************" << std::endl;
}

void ReadAndDumpUtf8File(const string& fileName)
{
	std::ifstream ifs;
	ifs.open(fileName, std::ifstream::in);

	if (!ifs.good())
	{
		std::cout << "Failed to open file: " << fileName << std::endl;
		return;
	}

	std::cout << "***************Starting dump file contents: " << fileName << "***************" << std::endl;

	for (std::string line; std::getline(ifs, line); )
	{
		std::cout << String2Hex(line) << std::endl;
	}

	std::cout << "***************End of file: " << fileName << "***************" << std::endl;
}

int main()
{
	ReadAndDumpAnsiFile("test.txt");

	ReadAndDumpUtf8File("utf8-file.txt");

	ReadAndDumpUtf8File("utf8-bom.txt");

	getchar();
}