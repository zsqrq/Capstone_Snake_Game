//
// Created by wz on 4/21/20.
//
#ifndef SDL2TEST_SCORE_H
#define SDL2TEST_SCORE_H
#include <fstream>
#include <string>

class Score
{
public:
    Score();
    void WriteToResFile(std::string name, int score, int siz);
    void OpenFile();
    void CloseFile();

private:
    std::fstream log_file;
};
#endif //SDL2TEST_SCORE_H
