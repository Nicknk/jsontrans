#include <string>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/locale.hpp>

#include "utils.h"

using namespace std;
using namespace boost::property_tree;

struct sData {

    sData()
    {
        iValue = 0;
        dtValue = "01-01-1970";
        strValue1 = "";
        strValue2 = "";
        strValue3 = "";
    }

    sData(int a_iValue, string a_dtValue, string a_strValue1, string a_strValue2, string a_strValue3)
    {
        iValue = a_iValue;
        dtValue = a_dtValue;
        strValue1 = a_strValue1;
        strValue2 = a_strValue2;
        strValue3 = a_strValue3;
    }

    int iValue;
    string dtValue;
    string strValue1;
    string strValue2;
    string strValue3;

    ptree toJSON()
    {
        ptree pt;
        pt.put<int>("iValue", iValue);
        pt.put<string>("dtValue", dtValue);
        pt.put<string>("sValue1", strValue1);
        pt.put<string>("sValue2", strValue2);
        pt.put<string>("sValue3", strValue3);
        return pt;
    };

    bool fromJSON(ptree a_json)
    {
        iValue = a_json.get<int>("iValue", -1);
        dtValue = a_json.get<string>("dtValue");
        strValue1 = boost::locale::conv::utf_to_utf<char>(a_json.get<string>("sValue1"));
        strValue2 = boost::locale::conv::utf_to_utf<char>(a_json.get<string>("sValue2"));
        strValue3 = boost::locale::conv::utf_to_utf<char>(a_json.get<string>("sValue3"));
        return true;
    };

    void transform()
    {
        //transform int
        if (iValue<5)
        {
            iValue = 0;
        }
        else if (5<=iValue && iValue<50)
        {
            iValue = 5;
        }
        else
        {
            iValue = 50;
        }

        //transform date, exp of date "31.12.1999"
        dtValue = dtValue.substr(dtValue.find_last_of(".")+1);


        //generate hash string
        md5 hash;
        md5::digest_type digest;
        hash.process_bytes(strValue1.data(), strValue1.size());
        hash.get_digest(digest);
        strValue1 = toString(digest);

        //add some prefix
        string strPrefix = "PREFIX_";
        strValue2.insert(0, strPrefix);


        for (unsigned int i = 0; i < strValue3.size(); ++i) 
        {
            strValue3[i] = toupper(strValue3[i]);
        }
    }
};