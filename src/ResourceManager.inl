template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::ResourceManager()
{

};

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::~ResourceManager()
{
    for(typename std::map<Identifier, Resource*>::iterator it=m_resourcemap.begin(); it!=m_resourcemap.end(); it++) {
        delete it->second;
    }
    std::cout << "Usuwam Resource Manager" << std::endl;
};

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::loadResource(std::string str, Identifier id)
{
    Resource* res = new Resource;
    if(!res->loadFromFile(str)) {
        std::string error = "Nie mozna bylo zaladowac pliku - ";
        error+=str;
        throw error;
    }
    m_resourcemap.insert(ResourcePair(id, res));
};

template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::getResource(Identifier id)
{
    if(m_resourcemap.find(id) == m_resourcemap.end()) {
        std::string error = "Bledny indetyfikator zasobu - ";
        error += typeid(Identifier).name();
        throw error;
    }
    return m_resourcemap[id];
};
