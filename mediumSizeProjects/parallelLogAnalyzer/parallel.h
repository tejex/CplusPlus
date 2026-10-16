#pragma
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>


namespace fs = std::filesystem;

void countCategories(const fs::path& filePath);
int countAllLines();