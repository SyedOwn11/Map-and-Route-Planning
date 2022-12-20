#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace System::Windows::Forms;

class map_file
{
    std::string name;
public:
    map_file()
    {
        name = "Pakistan";
        if (!file_exists(csv(name)))
        {
            create_file(csv(name));
        }
        if (!file_exists(relation_csv(name)))
        {
            create_file(relation_csv(name));
        }
    }

    
    void create_city(std::string city_name, int post_code, std::string name = "Pakistan")
    {
        if (city_exist(post_code, name)) {
            MessageBox::Show("Location Already Exist");
            return;
        }
        std::fstream fout;
        fout.open(csv(name), std::ios::out | std::ios::app);
        fout << post_code << "," << city_name << std::endl;
        MessageBox::Show("Location Added in Map Successfully");
        if (name != this->name)
            return;
        if (!file_exists(csv(city_name)))
        {
            create_file(csv(city_name));
        }
        if (!file_exists(relation_csv(city_name)))
        {
            create_file(relation_csv(city_name));
        }
        
    }

    void create_relation(int post_code1, int post_code2, int distance, int time, std::string name = "Pakistan")
    {
        if (!city_exist(post_code1, name) || !city_exist(post_code2, name)) {
            MessageBox::Show("Either one or both of the provided Locations donot exist");
            return;
        }
        if (relationship_exist(post_code1, post_code2, name)) {
            MessageBox::Show("Locations have already been Linked");
            return;
        }
        std::fstream fout;
        fout.open(relation_csv(name), std::ios::out | std::ios::app);
        fout << post_code1 << "," << post_code2 << "," << distance << ", " << time << std::endl;
        MessageBox::Show("Locations Successfully Linked Together");
    }


    city get_city(int post_code)
    {
        std::fstream fin;
        fin.open(csv(name), std::ios::in);
        std::vector<std::string> row;
        std::string line, word, temp;

        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                {
                    if (stoi(row[0]) == post_code)
                    {
                        fin.close();
                        return city(row[1], stoi(row[0]));
                    }
                }
            }
        }
        fin.close();
        return city();
    }

    std::vector<city> get_all_cities(std::string name = "Pakistan")
    {
        std::vector<city> cities;
        std::fstream fin;
        fin.open(csv(name), std::ios::in);
        std::vector<std::string> row;
        std::string line, word, temp;

        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                {

                    cities.push_back(city(row[1], stoi(row[0])));
                }
            }
        }
        fin.close();
        return cities;
    }

    graph make_graph(std::string name = "Pakistan")
    {
        graph g(name, -1);
        std::fstream fin;
        if (!file_exists(csv(name)))
        {
            return g;
        }
        fin.open(csv(name), std::ios::in);
        std::vector<std::string> row;
        std::string line, word, temp;

        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                    g.insert_vertex(row[1], stoi(row[0]));
            }
        }
        fin.close();

        if (!file_exists(relation_csv(name)))
        {
            return g;
        }

        fin.open(relation_csv(name), std::ios::in);
        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                    g.insert_edge(stoi(row[0]), stoi(row[1]), stoi(row[2]), stoi(row[3]));
            }
        }

        fin.close();
        return g;
    }


private:

    std::string csv(std::string name) { return "data/" + name + ".csv"; }
    std::string relation_csv(std::string name) { return "data/" + name + "_relation.csv"; }



    void create_file(std::string name)
    {
        std::ofstream output(name);
    }

    //Bool funcs

    bool relationship_exist(int post_code1, int post_code2, std::string name = "Pakistan")
    {
        std::fstream fin;
        fin.open(relation_csv(name), std::ios::in);
        std::vector<std::string> row;
        std::string line, word, temp;

        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                {
                    if (stoi(row[0]) == post_code1 && stoi(row[1]) == post_code2 || stoi(row[0]) == post_code2 && stoi(row[1]) == post_code1)
                    {
                        fin.close();
                        return true;
                    }
                }
            }
        }
        fin.close();
        return false;
    }

    bool file_exists(std::string name)
    {
        std::ifstream f(name);
        if (f.good())
            return true;
        return false;
    }

    bool city_exist(int post_code, std::string name = "Pakistan")
    {
        std::fstream fin;
        fin.open(csv(name), std::ios::in);
        std::vector<std::string> row;
        std::string line, word, temp;

        while (getline(fin, line)) {
            row.clear();
            std::stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            if (!row.empty())
            {
                if (row[0] != "")
                {
                    if (stoi(row[0]) == post_code)
                    {
                        fin.close();
                        return true;
                    }
                }
            }
        }
        fin.close();
        return false;
    }
};

