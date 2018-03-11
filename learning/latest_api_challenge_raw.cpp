#include <latest_api_challenge_raw.h>
#include <iostream>

std::vector<CSVData> Read(const std::string& input)
{
	std::vector<CSVData> objects;

	std::istringstream iss(input);
	std::string line;
	while (std::getline(iss, line))
	{
		CSVData object;

		std::istringstream liness(line);
		std::string token;
		int i = 0;
		while (std::getline(liness, token, ','))
		{
			object.tokens[i] = token;
			++i;
		}
		objects.push_back(object);
	}

	return objects;
}


int latest_api_challenge_raw_run()
{
    std::vector<CSVData> objs = Read("Mail App, Authentication API, v6 \nVideo Call App, Authentication API, v7 \nMail App, Data Storage API, v10 \nChat App, Data Storage API, v11 \nMail App, Search API, v6 \nChat App, Authentication API, v8 \nChat App, Presence API, v2 \nVideo Call App, Data Storage API, v11 \nVideo Call App, Video Compression API, v3");
    
    /*for(auto o : objs)
    {
        cout << o.tokens[0] + " " + o.tokens[1] + " " + o.tokens[2] + "\n";
    }*/
    
    std::sort(objs.begin(), objs.end(), sort_key());
    
    //load all unique api
    std::vector<CSVData> output;
    for(auto o : objs)
    {
        std::vector<CSVData>::iterator it;
        it = std::find(output.begin(), output.end(), o);
        if(it == output.end()) {
            output.push_back(o);
        }
    }
    
    //Erase common
    for(auto o : output)
    {
        std::vector<CSVData>::iterator it;
        it = std::find(objs.begin(), objs.end(), o);
        if(it != objs.end()) {
            objs.erase(it);
        }
    }
    
    //Get latest
    std::vector<CSVData> latest;
    for(auto o : output)
    {
        std::vector<CSVData>::iterator it;
        it = std::find_if(objs.begin(), objs.end(), [&o](CSVData const& obj){
		    return obj.tokens[0] == o.tokens[0];
	    } );

        if(it == objs.end()) {
            latest.push_back(o);
        }
    }
    
    /*std::cout << output.size();
    for(auto o : output)
    {
        std::cout << o.tokens[0] << o.tokens[1] << o.tokens[2] << std::endl;
    }
    
    std::cout << "\n\n\n";
    for(auto o : objs)
    {
        std::cout << o.tokens[0] << o.tokens[1] << o.tokens[2] << std::endl;
    }
    
    std::cout << "\n\n\n";*/
    
    for(auto o : latest)
    {
        std::cout << o.tokens[0] << o.tokens[1] << o.tokens[2] << std::endl;
    }
    
    return 0;
}
