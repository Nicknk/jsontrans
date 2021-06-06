#include <string>
#include <fstream>
#include <iomanip>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/json.hpp>
#include <boost/filesystem.hpp>

#include "structs.h"

using namespace std;
using namespace boost::property_tree;

sData DataTransform(ptree json)
{
    sData d = sData();
    d.fromJSON(json);
    d.transform();
    return d;
}

bool JSONperLinetransform(string input)
{
    ifstream jf (input);

    string str = "";

    string output = input.substr(input.find_last_of(".")+1) + "_out" + ".json";

    ofstream ojf(output, ios_base::out | ios_base::trunc);

    while(getline(jf, str))
    {
        std::stringstream jsonData(str);
        ptree json;
        read_json(jsonData, json);
        sData d = DataTransform(json);
        stringstream ss;
        write_json(ss, d.toJSON(), false);
        ojf << ss.rdbuf();
    }

    ojf.close();

    return false;
}