#include "DataManager.h"
#include "GameManager.h"


#include <map>

DataManager::DataManager()
{

}


DataManager::DataManager(GameManager* gm)
{
    this->gm = gm;
}


DataManager::~DataManager()
{

}


void DataManager::readManifest()
{
    FILE *pFile = fopen ("data/manifest.json" , "r");

    if (pFile == NULL)
        std::cout <<"Error opening the manifest file";

    rapidjson::FileStream fs = rapidjson::FileStream(pFile);
    rapidjson::Document doc;
    doc.ParseStream<0>(fs);

    if (!doc.IsObject())
        std::cout <<"Error with your manifest. Please check your syntax!";

    rapidjson::Value& files = doc["files"];

    std::vector<std::string> allFiles;

    for (rapidjson::SizeType i = 0; i < files.Size(); i++)
    {
        rapidjson::Value& file = files[i];

        allFiles.push_back(file["path"].GetString());
    }

    readFiles(allFiles);

    fclose(pFile);
}



void DataManager::readFile(const char* path)
{
    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        std::cout <<"Could not find or open file " << path;
        return;
    }


    rapidjson::FileStream fs = rapidjson::FileStream(pFile);
    rapidjson::Document doc;
    doc.ParseStream<0>(fs);

    if (!doc.IsObject())
    {
        std::cout <<"Error with " << path << ". Please check your syntax!";
        return;
    }


    if ((std::string)doc["type"].GetString() == "team")
    {
        int id = doc["id"].GetInt();
        std::string name = doc["name"].GetString();
        int transferBudget = doc["transfer_budget"].GetInt();
        std::string fString = doc["formation"].GetString();
        std::vector<short> formations = util::splitToShort(fString, '-');
        short formation = (formations[0] << 12) | (formations[0] << 9) | (formations[0] << 6) | (formations[0] << 3) | formations[0];


        Team nTeam(id, name, transferBudget, formation);

        gm->registerTeam(nTeam);


        rapidjson::Value& players = doc["players"];

        for (rapidjson::SizeType i = 0; i < players.Size(); i++)
        {
            rapidjson::Value& player = players[i];
            std::string name = player["name"].GetString();
            int age = player["age"].GetInt();
            std::string pos = player["position"].GetString();
            int teamID = player["teamID"].GetInt();
            std::string positions = player["position"].GetString();

            // Have to slit the positions string here!

            std::map<std::string, int> s;

            for (rapidjson::SizeType i = 0; i < player["stats"].Size(); i++)
            {
                rapidjson::Value& stat = player["stats"][i];

                std::pair<std::string, int> p;
                p.first = (std::string)stat["name"].GetString();;
                p.second = stat["value"].GetInt();


                s.insert(p);
            }

            Player pl(name, age, teamID, Player::stringToPosition(positions), s);
            gm->registerPlayer(pl);
        }
    }
    else if ((std::string)doc["type"].GetString() == "league")
    {
        rapidjson::Value& leagues = doc["leagues"];

        for (rapidjson::SizeType i = 0; i < leagues.Size(); i++)
        {
            rapidjson::Value& leag = leagues[i];

            std::string name = leag["name"].GetString();
            rapidjson::Value& date = leag["startingDate"];

            rapidjson::SizeType t = 0;
            int day = date[t++].GetInt();
            int month = date[t++].GetInt();
            int year = date[t].GetInt();

            Date d(day, month, year);

            League league(name, d);


            rapidjson::Value& teams = leag["teams"];

            for (rapidjson::SizeType i = 0; i < teams.Size(); i++)
            {
                league.addTeam(gm->getTeam((std::string)teams[i].GetString()));
            }


            gm->registerLeague(league);
        }

    }
    else
    {
        std::cout <<"Invalid type of file: " << doc["type"].GetString() << std::endl;
    }
}



void DataManager::readFiles(const std::vector<std::string>& paths)
{
    for (int i = 0; i < paths.size(); i++)
    {
        readFile(paths[i].c_str());
    }

    gm->addPlayersToTeams();
}
