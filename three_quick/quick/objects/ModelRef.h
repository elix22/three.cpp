//
// Created by byter on 1/12/18.
//

#ifndef THREEPP_MESH_H
#define THREEPP_MESH_H

#include <QMetaObject>
#include <objects/Node.h>
#include "quick/scene/Model.h"
#include "quick/scene/Scene.h"
#include "quick/objects/ThreeQObject.h"

namespace three {
namespace quick {

class ModelRef : public ThreeQObject
{
Q_OBJECT
  Q_PROPERTY(Model *model READ model WRITE setModel NOTIFY modelChanged)
  Q_PROPERTY(QString selector READ selector WRITE setSelector)
  Q_PROPERTY(Type type READ type WRITE setType)
  Q_PROPERTY(QObject *object READ modelObject NOTIFY modelObjectChanged)
  Q_PROPERTY(float rotateX READ rotateX WRITE setRotateX NOTIFY rotateChanged)
  Q_PROPERTY(float rotateY READ rotateY WRITE setRotateY NOTIFY rotateChanged)
  Q_PROPERTY(float rotateZ READ rotateZ WRITE setRotateZ NOTIFY rotateChanged)

public:
  enum Type {Node, Mesh, Light, Camera};
  Q_ENUM(Type)

private:
  Model *_model = nullptr;
  QString _selector;
  Type _type = Mesh;

  QMetaObject::Connection _loadedConnection;
  QMetaObject::Connection _fileConnection;

  Scene *_scene = nullptr;

  three::Node::Ptr _node;

  float _rotateX, _rotateY, _rotateZ;

  ThreeQObject *_object = nullptr;
  std::vector<ThreeQObject *> _objects;

protected:
  Object3D::Ptr _create(Scene *scene) override
  {
    _scene = scene;
    return nullptr;
  }

  void matchType(Object3D::Ptr parent, Object3D::Ptr obj, bool setObject);

  enum class Eval {name, skipLevel, skipLevels, collectLevel, collectLevels};
  bool evaluateSelector(QStringList::iterator &iter,
                        QStringList::iterator &end,
                        Object3D::Ptr parent,
                        const std::vector<Object3D::Ptr> &children,
                        Eval wildcard=Eval::name);

public:
  ModelRef(QObject *parent=nullptr) : ThreeQObject(parent) {}

  Model *model() const {return _model;}

  void setModel(Model *model);

  QObject *modelObject() const {return _object;}

  const QString &selector() const {return _selector;}

  void setSelector(const QString &selector) {_selector = selector;}

  Type type() const {return _type;}

  void setType(Type type) {_type = type;}

  float rotateX() const {return _rotation.x();}
  void setRotateX(float angle);
  float rotateY() const {return _rotation.y();}
  void setRotateY(float angle);
  float rotateZ() const {return _rotation.z();}
  void setRotateZ(float angle);

signals:
  void modelChanged();
  void modelObjectChanged();
  void rotateChanged();

private slots:
  void cleanupMesh();
  void updateMesh();
};

}
}

#endif //THREEPP_MESH_H
