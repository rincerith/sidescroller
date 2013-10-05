#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <vector>

template <typename Resource>

class BinaryTree {
public:
    BinaryTree(float x, float y, float width, float height, int level, int maxLevel);

    ~BinaryTree();

    void AddObject(Resource object);

    std::vector<Resource> GetObjectsAt(float x1, float x2);

    std::vector<Resource> GetAllObjects();

    void Clear();

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    int m_level;
    int	m_maxLevel;
    std::vector<Resource> m_objects;

    BinaryTree *m_parent;
    BinaryTree *m_Left;
    BinaryTree *m_Right;

    bool contains(BinaryTree *child, Resource object);
};

#include "BinaryTree.inl"
#endif // BINARYTREE_H_INCLUDED
