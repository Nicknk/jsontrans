#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

#include <boost/json/src.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "transform.h"

using namespace std;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

int main(int argc, char* argv[]) {

    setlocale(0, "");

    if(argc == 2)
    {
        string input = argv[1];//file name for json per line
        JSONperLinetransform(input);
    }
    else
    {
        cout << "Wrong arguments" << endl;
    }
    
    return 0;
}