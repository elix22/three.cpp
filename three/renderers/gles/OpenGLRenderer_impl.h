//
// Created by byter on 05.08.17.
//

#ifndef THREE_QT_OPENGLRENDERER_H
#define THREE_QT_OPENGLRENDERER_H

#include <renderers/OpenGLRenderer.h>
#include <light/Light.h>
#include <QOpenGLShaderProgram>
#include "OpenGLRenderTarget.h"
#include "GLState.h"

namespace three {

class OpenGLRenderer_impl : public OpenGLRenderer
{
  std::vector<Light::Ptr> lightsArray;
  std::vector<Light::Ptr> shadowsArray;

  //var currentRenderList = null;

  //var spritesArray = [];
  //var flaresArray = [];

  // clearing
  bool _autoClear = true;
  bool _autoClearColor = true;
  bool _autoClearDepth = true;
  bool _autoClearStencil = true;

  // scene graph
  bool _sortObjects = true;

  // user-defined clipping
  //this.clippingPlanes = [];
  //bool _localClippingEnabled = false;

  // physically based shading
  float _gammaFactor = 2.0;	// for backwards compatibility
  bool _gammaInput = false;
  bool _gammaOutput = false;

  // physical lights
  bool _physicallyCorrectLights = false;

  // tone mapping
  ToneMapping _toneMapping = ToneMapping::Linear;
  float _toneMappingExposure = 1.0;
  float _toneMappingWhitePoint = 1.0;

  // morphs
  unsigned _maxMorphTargets = 8;
  unsigned _maxMorphNormals = 4;

  bool _isContextLost = false;

  // internal state cache
  OpenGLRenderTarget::Ptr _currentRenderTarget = nullptr;
  //_currentFramebuffer = null,
  int _currentMaterialId = -1;
  QOpenGLShaderProgram *_currentGeometryProgram = nullptr;

  //_currentCamera = null,
  //_currentArrayCamera = null,

  QVector4D _currentViewport;
  QVector4D _currentScissor;
  //_currentScissorTest = null,

  //

  unsigned _usedTextureUnits = 0;

  unsigned _width;
  unsigned _height;

  float _pixelRatio = 1;

  QVector4D _viewport;// = new Vector4( 0, 0, _width, _height ),
  QVector4D _scissor; // = new Vector4( 0, 0, _width, _height ),
  bool _scissorTest = false;

  // frustum
  //Frustum _frustum = new Frustum(),

  // clipping
  //_clipping = new WebGLClipping(),
  bool _clippingEnabled = false;
  bool _localClippingEnabled = false;

  // camera matrices cache
  QMatrix4x4 _projScreenMatrix;

  QVector3D _vector3;

  float getTargetPixelRatio()
  {
    return _currentRenderTarget ? _pixelRatio : 1;
  }

  gles::GLState state;

public:

  //OpenGLRenderer_impl(QOpenGLContext *context, Options options=Options());
  OpenGLRenderer_impl(QOpenGLContext *context, unsigned width, unsigned height);
};

}
#endif //THREE_QT_OPENGLRENDERER_H
