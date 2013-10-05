#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <map>
#include <string>
#include <iostream>
#include <typeinfo>

template <typename Resource, typename Identifier>
class ResourceManager {

    typedef std::map<Identifier, Resource*> ResourceMap;
    typedef std::pair<Identifier, Resource*> ResourcePair;

public:
    ResourceManager();

    ~ResourceManager();

    void loadResource(std::string str, Identifier id);

    Resource* getResource(Identifier id);

private:
    ResourceMap m_resourcemap;
};

#include "ResourceManager.inl"

#endif // RESOURCEMANAGER_H_INCLUDED
