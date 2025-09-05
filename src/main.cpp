#define _CRT_SECURE_NO_WARNINGS

//#include <chrono>
#include <cstdlib>
//#include <format>
#include <iostream>
#include <fstream>
#include <filesystem>

int main(void)
{
	//auto now{std::chrono::system_clock::now()};
	//std::string dateString{ std::format("{:%Y%m%dT%H%M%OS}", now) };

	std::filesystem::path homedrive{ std::getenv("HOMEDRIVE") };
	std::filesystem::path homepath{ std::getenv("HOMEPATH") };
	std::filesystem::path userprofile{ std::getenv("USERPROFILE") };
	std::filesystem::path home_dir = homedrive / homepath;

	std::cout << "HOMEDRIVE & HOMEPATH: " << home_dir << "\n";

	std::cout << "USERPROFILE: " << userprofile << "\n";

	return EXIT_SUCCESS;
}
