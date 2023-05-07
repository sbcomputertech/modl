#pragma once
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream>

// trim from start (in place)
static void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// trim from start (copying)
static std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static std::string trim_copy(std::string s) {
    trim(s);
    return s;
}

static std::string replace_all(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

template<typename Delim>
static std::string get_word(std::istream& ss, Delim d)
{
    std::string word;
    for (char ch; ss.get(ch); )    // skip delimiters
        if (!d(ch)) {
            word.push_back(ch);
            break;
        }
    for (char ch; ss.get(ch); )    // collect word
        if (!d(ch))
            word.push_back(ch);
        else
            break;
    return word;
}

static std::vector<std::string> split(const std::string& s, const std::string& delim)
{
    std::stringstream ss(s);
    auto del = [&](char ch) { for (auto x : delim) if (x == ch) return true; return false; };

    std::vector<std::string> words;
    for (std::string w; !(w = get_word(ss, del)).empty(); ) words.push_back(w);
    return words;
}
