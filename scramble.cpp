#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

int main() {

    std::string word;
    std::string sign;
    std::string reversed_word;
    std::string sentence = "";

    std::vector<std::string> vec;
    vec.push_back("a");
    vec.push_back("ab");
    vec.push_back("abc");
    vec.push_back("abcd.");
    vec.push_back("abcde,");
    vec.push_back("abcdef?");
    vec.push_back("abcd, efgh; ijkl?");
    vec.push_back("To simplify the problem of scrambling it would not use random order, but just reverse the inner letters of the word, while keeping the first and last ones in place.");

    std::vector<std::string> controll_vec;
    controll_vec.push_back("a");
    controll_vec.push_back("ab");
    controll_vec.push_back("abc");
    controll_vec.push_back("acbd.");
    controll_vec.push_back("adcbe,");
    controll_vec.push_back("aedcbf?");
    controll_vec.push_back("acbd, egfh; ikjl?");
    controll_vec.push_back("To sfilpmiy the pelborm of snilbmarcg it wluod not use rodnam oedrr, but jsut rsrevee the iennr lrettes of the wrod, wlihe knipeeg the fsrit and lsat oens in pcale.");

    for(int i = 0; i < vec.size(); i++)
    {

    sentence = "";

    std::stringstream buf(vec.at(i));
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end);


    for(int j = 0; j < tokens.size(); j++)
    {
        word = tokens.at(j);
        sign = "";
        reversed_word = "";

        if (   '.' == word[word.size()-1]
            || ',' == word[word.size()-1]
            || '!' == word[word.size()-1]
            || '?' == word[word.size()-1]
            || '-' == word[word.size()-1]
            || ':' == word[word.size()-1]
            || ';' == word[word.size()-1]
        )
        {
            sign = word[word.size()-1];
            word = word.substr(0, word.size()-1);
        }

        reversed_word += word[0];

        if(word.size()>1)
        {
            for(std::string::iterator i = word.end()-2; i != word.begin(); i--)
            {
                reversed_word += *i;
            }

            reversed_word += word[word.size()-1];
            reversed_word += sign;
        }
        if(j<tokens.size()-1) sentence += reversed_word + " ";
        else sentence += reversed_word;
        }
    std::cout << sentence;
    if(controll_vec.at(i) == sentence) std::cout << " (CORRECT)";
    std::cout << std::endl;
    }
}
