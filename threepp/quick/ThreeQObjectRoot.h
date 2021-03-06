//
// Created by byter on 12/29/17.
//

#ifndef THREEPPQ_THREEQOBJECTROOT_H
#define THREEPPQ_THREEQOBJECTROOT_H

#include <QObject>
#include <threepp/util/osdecl.h>

namespace three {
namespace quick {

class ThreeDItem;

class DLQX ThreeQObjectRoot : public QObject
{
Q_OBJECT

protected:
  explicit ThreeQObjectRoot(QObject *parent=nullptr) : QObject(parent) {}

public:
  virtual ~ThreeQObjectRoot() {}

  virtual void setItem(ThreeDItem * item) {}
};

}
}


#endif //THREEPPQ_THREEQOBJECTROOT_H
