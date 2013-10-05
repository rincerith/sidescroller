#include "BinaryTree.h"


#include <iostream>

template <typename Resource>
BinaryTree<Resource>::BinaryTree(float _x, float _y, float _width, float _height, int _level, int _maxLevel) :
    m_x		(_x),
    m_y		(_y),
    m_width	(_width),
    m_height	(_height),
    m_level	(_level),
    m_maxLevel(_maxLevel)
{
    if (m_level == m_maxLevel) {
        return;
    }

    m_Left = new BinaryTree(m_x, m_y, m_width / 2.0f, m_height, m_level+1, m_maxLevel);
    m_Right = new BinaryTree(m_x + m_width / 2.0f, m_y, m_width / 2.0f, m_height, m_level+1, m_maxLevel);
}

template <typename Resource>
BinaryTree<Resource>::~BinaryTree()
{
    if (m_level == m_maxLevel)
        return;

    delete m_Left;
    delete m_Right;
    std::cout << "Usuwam BinaryTree = level " << m_level << std::endl;
}

template <typename Resource>
void BinaryTree<Resource>::AddObject(Resource object)
{
    if (m_level == m_maxLevel) {
        m_objects.push_back(object);
        return;
    }
    if (contains(m_Left, object)) {
        m_Left->AddObject(object);
        return;
    } else if (contains(m_Right, object)) {
        m_Right->AddObject(object);
        return;
    }
    if (contains(this, object)) {
        m_objects.push_back(object);
    }
}

template <typename Resource>
std::vector<Resource> BinaryTree<Resource>::GetObjectsAt(float x1, float x2)
{
    if (m_level == m_maxLevel) {
        return m_objects;
    }

    std::vector<Resource> returnObjects, childReturnObjects;
    if (!m_objects.empty()) {
        returnObjects = m_objects;
    }
    if(x1 < (m_x + m_width / 2.0f) && x2 > (m_x + m_width / 2.0f)) {
        childReturnObjects = m_Left->GetObjectsAt(x1, x2);
        returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
        childReturnObjects = m_Right->GetObjectsAt(x1, x2);
        returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
        return returnObjects;
    } else {
        if (x1 > m_x + m_width / 2.0f) {
            childReturnObjects = m_Right->GetObjectsAt(x1, x2);
            returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
            return returnObjects;
        } else {
            childReturnObjects = m_Left->GetObjectsAt(x1, x2);
            returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
            return returnObjects;
        }
    }
    return returnObjects;
}

template <typename Resource>
std::vector<Resource> BinaryTree<Resource>::GetAllObjects()
{
    return GetObjectsAt(0, m_width);
}

template <typename Resource>
void BinaryTree<Resource>::Clear() // TODO : poprawic usuwanie, binarytree jest teraz przechowalnikiem, trzeba iterowac po vectorze i usuwac obiekty
{
    if (m_level == m_maxLevel) {
        m_objects.clear();
        return;
    } else {
        m_Left->Clear();
        m_Right->Clear();
    }
    if (!m_objects.empty()) {
        m_objects.clear();
    }
}

template <typename Resource>
bool BinaryTree<Resource>::contains(BinaryTree *child, Resource object)
{
    return	 !(object->getPosition().x < child->m_x ||
               object->getPosition().x > child->m_x + child->m_width  ||
               object->getPosition().x + object->getGlobalBounds().width < child->m_x ||
               object->getPosition().x + object->getGlobalBounds().width > child->m_x + child->m_width);
}
