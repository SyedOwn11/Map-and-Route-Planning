#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <iterator>




// Enumerables

enum class do_by
{
    distance,
    time
};


//Structures

struct city
{
    std::string name;
    int post_code;
    city(std::string n, int p)
    {
        name = n;
        post_code = p;
    }
    city()
    {
        name = "";
        post_code = 0;
    }

    bool operator==(city c)
    {
        if (post_code == c.post_code)
            return true;
        return false;
    }
};

struct list_node
{
    int post_code;
    int distance;
    int time;
    list_node(int p, int d, int t)
    {
        post_code = p;
        distance = d;
        time = t;
    }
    list_node(int p)
    {
        post_code = p;
        distance = 0;
        time = 0;
    }
};

struct node
{
    city city;
    std::list<list_node> edge;
    bool operator==(node t)
    {
        if (city == t.city)
            return true;
        return false;
    }
};

struct dijkstra_node
{
    int vertex;
    int shortest_path;
    int prev_vertex;
    int other_path;
};

struct dijkstra_return
{
    std::vector<int> path;
    int shortest_path;
    int other_path;
    dijkstra_return(std::vector<int> p, int sp, int op)
    {
        path = p;
        shortest_path = sp;
        other_path = op;
    }
};

//Operator Overloads
bool operator==(list_node p, list_node q);
bool operator==(node p, int q);
//Class

class graph
{
    std::string name;
    int post_code;
    std::vector<node> vec;
public:
    graph() {
        name = "";
        post_code = 0;
    }


    graph(std::string name, int post_code)
    {
        this->name = name;
        this->post_code = post_code;
    }



    int search_vertex(std::string name)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].city.name == name)
                return i;
        }
        return -1;
    }

    int search_vertex(int post_code)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].city.post_code == post_code)
                return i;
        }
        return -1;
    }

    void insert_vertex(std::string name, int post_code)
    {
        if (search_vertex(post_code) != -1)
        {
            return;
        }
        node temp;
        temp.city = city(name, post_code);
        vec.push_back(temp);
    }

    void insert_edge(int a, int b, int distance, int time)
    {
        if (edge_exist(a, b))
        {
            return;
        }
        int vertexa = search_vertex(a);
        int vertexb = search_vertex(b);
        if (vertexa == -1 || vertexb == -1)
        {
            return;
        }
        vec[vertexa].edge.push_back(list_node(b, distance, time));
        vec[vertexb].edge.push_back(list_node(a, distance, time));
    }

    void delete_vertex(int post_code)
    {
        auto in = vec.begin();
        vec.erase(in + search_vertex(post_code));
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i].edge.remove(list_node(post_code));
        }
    }

    void delete_edge(int a, int b)
    {
        if (!edge_exist(a, b))
        {
            return;
        }
        int vertexa = search_vertex(a);
        int vertexb = search_vertex(b);
        if (vertexa == -1 || vertexb == -1)
        {
            return;
        }
        vec[vertexa].edge.remove(list_node(b));
        vec[vertexb].edge.remove(list_node(a));
    }


    bool edge_exist(int a, int b)
    {
        int vertexa = search_vertex(a);
        int vertexb = search_vertex(b);
        if (vertexa != -1 && vertexb != -1)
        {
            for (const list_node& i : vec[vertexa].edge)
            {
                if (i.post_code == b)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int edges_count()
    {
        int sum = 0;
        for (node n : vec)
        {
            sum += n.edge.size();
        }
        return sum / 2;
    }

    int vertices_count()
    {
        return vec.size();
    }

    bool isEmpty()
    {
        return (vec.empty());
    }

    std::vector<city> search_locations(std::string name)
    {
        std::vector<city> dat;
        for (auto t : vec)
        {
            if (strings_match(name, t.city.name))
            {
                dat.push_back(city(t.city.name, t.city.post_code));
            }
        }
        return dat;
    }

    city search_locations(int post_code)
    {
        for (auto t : vec)
        {
            if (t.city.post_code == post_code)
                return city(t.city.name, t.city.post_code);
        }
        return city();
    }

    dijkstra_return dijkstra(int from, int to, do_by db = do_by::distance)
    {

        std::vector<dijkstra_node> v;
        std::vector<int> visited;
        for (node t : vec)
        {
            dijkstra_node n;
            n.vertex = t.city.post_code;
            n.shortest_path = 2147483647;
            if (t.city.post_code == from)
                n.shortest_path = 0;
            n.other_path = 0;
            n.prev_vertex = -1;
            v.push_back(n);
        }
        int index = search_vertex(from);
        dijkstra_recurse(index, visited, v, db);
        int temp = to;
        std::stack<int> _path;
        while (temp != -1)
        {
            _path.push(temp);
            temp = v[search_vertex(temp)].prev_vertex;
        }
        std::vector<int> path;
        while (!_path.empty())
        {
            path.push_back(_path.top());
            _path.pop();
        }
        path.reserve(path.size());
        return dijkstra_return(path, v[search_vertex(to)].shortest_path, v[search_vertex(to)].other_path);
    }

    void dijkstra_recurse(int index, std::vector<int>& visited, std::vector<dijkstra_node>& v, do_by db)
    {
        auto visit_node = [&](int node)
        {
            visited.push_back(node);
        };
        auto place_short_value = [&](int distance, int other, int _from, int _to)
        {
            int new_shortest_path = v[_from].shortest_path + distance;
            if (new_shortest_path < v[_to].shortest_path)
            {
                int new_other_path = v[_from].other_path + other;
                v[_to].other_path = new_other_path;
                v[_to].shortest_path = new_shortest_path;
                v[_to].prev_vertex = vec[_from].city.post_code;
            }
        };
        visit_node(vec[index].city.post_code);
        for (const list_node& i : vec[index].edge)
        {
            int _to = search_vertex(i.post_code);
            if (db == do_by::distance)
            {
                place_short_value(i.distance, i.time, index, _to);
            }
            else
            {
                place_short_value(i.time, i.distance, index, _to);
            }
        }
        for (const list_node& i : vec[index].edge)
        {
            if (!in_vector<int>(i.post_code, visited))
                dijkstra_recurse(search_vertex(i.post_code), visited, v, db);
        }
    }

    std::vector<std::string> split_string(std::string a)
    {
        std::string space_delimiter = " ";
        std::vector<std::string> words;

        size_t pos = 0;
        while ((pos = a.find(space_delimiter)) != std::string::npos) {
            words.push_back(a.substr(0, pos));
            a.erase(0, pos + space_delimiter.length());
        }
        return words;
    }

    bool strings_match(std::string a, std::string b)
    {
        for (std::string n : split_string(a))
        {
            if (b.find(n) != std::string::npos)
                return true;
        }
        return false;
    }

    template <class T> bool in_vector(T data, std::vector<T> v)
    {
        for (T i : v)
        {
            if (i == data)
            {
                return true;
            }
        }
        return false;
    }

};