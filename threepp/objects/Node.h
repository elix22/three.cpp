//
// Created by byter on 1/7/18.
//

#ifndef THREEPP_NODE_H
#define THREEPP_NODE_H

#include <threepp/core/Object3D.h>

namespace three {

/**
 * a non-renderable scenegraph node
 */
class Node : public Object3D
{
protected:
  Node(std::string name) : Object3D() {
    _name = name;
  }

  Node(std::vector<Object3D::Ptr> children) : Object3D()
  {
    _children.insert(_children.begin(), children.begin(), children.end());
  }

  Node(const Node &node) : Object3D(node)
  {}

public:
  using Ptr = std::shared_ptr<Node>;
  static Ptr make(std::string name="") {
    return Ptr(new Node(name));
  }
  static Ptr make(std::vector<Object3D::Ptr> children) {
    return Ptr(new Node(children));
  }

  bool isEmpty() {return _children.empty();}

  Node *cloned() const override {
    return new Node(*this);
  }
};

}

#endif //THREEPP_NODE_H
