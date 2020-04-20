//
// Created by wz on 4/21/20.
//
#include "Score.h"
#include <iostream>
#include <sstream>


//cstr, create the file and write first line
Score::Score()
{
    //Open or create the file
    OpenFile();

    //Go the end of the file
    log_file.seekg(0, std::ios::end);

    //Dump the first line
    if (log_file.tellg() == 0)
    {
        log_file << "Player-Score-Size" << std::endl;
    }

    // Close
    CloseFile();
}

void Score::WriteToResFile(std::string name, int score, int siz)
{
    OpenFile();

    log_file << "Player name: " << name << ", Player score: " << score << " and snake size: " << siz << std::endl;

    CloseFile();
}

void Score::OpenFile()
{
    log_file.open("../RES_FILE.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}

void Score::CloseFile()
{
    log_file.close();
}

