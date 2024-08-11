#include "rectangle.hpp"

/*this function validates the file =, mainly from its extension*/
bool isFileValid(const std::string& filename) {
    // Find the position of the last dot in the filename
    std::uint32_t dotPos = filename.rfind('.');
    
    // If a dot was found and it's not the first character
    if (dotPos != std::string::npos && dotPos != 0) {
        // Extract the extension
        std::string extension = filename.substr(dotPos + 1);
        
        // Compare it with the expected extension (case-sensitive)
        if (extension == "json") {
            return true;
        }
    }
    return false;
}

int32_t main (int32_t argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Invalid arguments passed to file: " << argv[0]<<" <filename>" << std::endl;
	return 0;
    }

    std::string filename = argv[1];

    if(!isFileValid(filename)){
	    std::cerr<<"Invalid file, not a json file"<<std::endl;
	    return 0;
    }

    std::ifstream myfile(filename);

    if (!myfile.is_open()) {
        std::cerr << "Couldn't open " << filename << std::endl;
        return 0;
    }

    std::string line;
    std::string jsonstr;
    std::vector<Rectangle> recVec;
    nlohmann::json jsonObj;

    while (getline(myfile, line))
	jsonstr += line;   
        
    try {
	jsonObj = nlohmann::json::parse(jsonstr);
    }catch(nlohmann::json::parse_error& e) {
	    std::cerr<<"Invalid json string format"<<std::endl;
	    std::cerr<<e.what()<<std::endl;
	return 0;
    }
    uint32_t recCount = 0;
    for (auto& item : jsonObj["rects"]) {
        Rectangle rec;
        rec.setRecData(item["x"].get<int32_t>(), item["y"].get<int32_t>(), item["w"].get<uint32_t>(), item["h"].get<uint32_t>());
        recVec.push_back(rec);
	recCount++;
	if(recCount >= 10) /*According to the assessment requirements it should process maximum 10 rectangles*/
		break;
    }


    int32_t i = 0;
    for (const auto& rec : recVec) {
        std::cout << (i + 1) << ": Rectangle at (" << rec.getULeft_point().getXcord() << "," << rec.getULeft_point().getYcord() << ")"
                  << ", w=" << rec.getWidth() << ", h=" << rec.getHeight() << std::endl;
        i++;
    }
	
    std::vector <IntersectionPairs> newRecInfo;
    std::cout << std::endl << "Intersections" << std::endl;
    for (uint32_t index = 0; index < recVec.size(); index++) {
        for (uint32_t j = index + 1; j < recVec.size(); j++) {
            if (recVec[index] & recVec[j]) {
                Rectangle shadedRec = getShadedRec(recVec[index], recVec[j]);
                int32_t x = shadedRec.getULeft_point().getXcord();
                int32_t y = shadedRec.getULeft_point().getYcord();
                uint32_t w = shadedRec.getWidth();
                uint32_t h = shadedRec.getHeight();
                std::cout << "Between Rectangle " << index + 1 << " and " << j + 1 << " at (" << x << "," << y << "), w=" << w << ", h=" << h << "." << std::endl;
		IntersectionPairs tmp;
		tmp.newrec = shadedRec ;
		tmp.first_rec = index + 1;
		tmp.sec_rec = j + 1;
		newRecInfo.push_back(tmp);
            }
        }
    }
   for (uint32_t index1 = 0; index1 < newRecInfo.size(); index1++) {
        for (uint32_t index2 = index1; index2 < recVec.size(); index2++) {
            // Make sure we're not comparing with the original rectangles used to form the intersection
            if (index2 + 1 == newRecInfo[index1].first_rec || index2 + 1 == newRecInfo[index1].sec_rec) {
                continue;
            }

            if (newRecInfo[index1].newrec & recVec[index2]) {
                Rectangle shadedRec = getShadedRec(newRecInfo[index1].newrec, recVec[index2]);

                int32_t x = shadedRec.getLLeft_point().getXcord();
                int32_t y = shadedRec.getLLeft_point().getYcord();
                uint32_t w = shadedRec.getWidth();
                uint32_t h = shadedRec.getHeight();

                std::cout << "Between Rectangle " << newRecInfo[index1].first_rec << ", " 
                          << newRecInfo[index1].sec_rec << " and " << index2 + 1
                          << " at (" << x << "," << y << "), w=" << w << ", h=" << h << "." << std::endl;
            }
        }
    }

    return 0;
}

