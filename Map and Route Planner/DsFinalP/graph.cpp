#include "graph.h"

bool operator==(list_node p, list_node q)
{
    if (p.post_code == q.post_code)
        return true;
    return false;
}

bool operator==(node p, int q)
{
    if (p.city.post_code == q)
        return true;
    return false;
}