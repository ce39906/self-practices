/*************************************************************************
    > File Name: test_trie.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-19 19:53:22
 ************************************************************************/
#include "trie.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#define NDEBUG
#include <cassert>

using namespace trie;

void usage(const char* bin)
{
    std::cout << bin << " : Need a filename as a parameter.\n";
    std::exit(EXIT_FAILURE);
}

void readFile2Vector(const std::string& file, std::vector<std::string>& vec)
{
    std::fstream infile(file, std::ios_base::in);
    std::string line;
    while(getline(infile, line, '\n'))
    {
        vec.emplace_back(line);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        usage(argv[0]);
    }
    
    const std::string data_file(argv[1]);
    std::vector<std::string> dict;
    readFile2Vector(data_file, dict);

    Trie trie;
    trie.Init(dict);
    // test trie lookup function
    for (const std::string& word : dict)
    {
        (void) word;
        assert(trie.Lookup(word) == true);
    }
    
    trie.PrintSuggs("美");
    trie.PrintSuggs("be");
    trie.PrintSuggs("中");
    trie.PrintSuggs("苍");
    trie.PrintSuggs("null");
    
    return 0;
}

