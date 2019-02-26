/*************************************************************************
    > File Name: test_words_filter.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-25 16:36:46
 ************************************************************************/
#include <iostream>
#include "words_filter.hpp"
using namespace std;

int main()
{
    vector<string> sensitive_words = {
        "全部",
        "手机",
        "追逐",
        "haha",
        "Indian",
        "Force"
    };

    string text = "如果流浪是你的天赋，那么你一定是我最美的追逐，"
                  "如果爱情是你的游牧拥有过是不是该满足，谁带我踏"
                  "上孤独的丝路，追逐你的脚步，谁带我离开孤独的丝"
                  "路感受你的温度，我将眼泪流成天山上的湖，羌笛声"
                  "胡旋舞为你笑为你哭，爱上你的全部放弃我的全部，"
                  "爱上了你之后我开始领悟，陪你走了一段最唯美的国"
                  "度.Pakistan Armed Forces spokesperson, Major G"
                  "eneral Asif Ghafoor, on Twitter claimed Indian"
                  " Air Force violated the Line of Control. Pakis"
                  "tan Air Force immediately scrambled. Indian aircraf";
    
    WordsFilterTree words_filter(sensitive_words);
    cout << "Init sensitive words are :" << endl;
    for (const string& sensitive_word : sensitive_words)
    {
        cout << kBoldRedANSIColorCodePrefix << sensitive_word
             << kBoldRedANSIColorCodeSuffix << " ";
    }
    cout << endl;

    string word = "温度";
    cout << "Add new sensitive word :" << endl;
    cout << kBoldRedANSIColorCodePrefix << word << kBoldRedANSIColorCodeSuffix;
    words_filter.addSensitiveWord(word);
    cout << endl;
    
    set<string> matched_words = words_filter.findAllSensitiveWords(text, 1);
    cout << "Matched sensitvie words are :" << endl;
    for (const string& matched_word : matched_words) 
    {
        cout << kBoldRedANSIColorCodePrefix << matched_word
             << kBoldRedANSIColorCodeSuffix << " ";
    }
    cout << endl;
    
    cout << "Origin text is :" << endl;
    cout << text << endl;
    string replaced_text = words_filter.replaceAllSensitiveWords(text);
    cout << "Replaced text is :" << endl;
    cout << replaced_text << endl;

    return 0;
}

