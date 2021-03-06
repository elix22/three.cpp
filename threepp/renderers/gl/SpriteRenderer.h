//
// Created by byter on 21.10.17.
//

#ifndef THREEPP_SPRITERENDERER_H
#define THREEPP_SPRITERENDERER_H

#include <QOpenGLFunctions>
#include "State.h"
#include "Textures.h"
#include "Capabilities.h"
#include <threepp/objects/Sprite.h>

namespace three {
namespace gl {

class Renderer_impl;
class SpriteRendererData;

class SpriteRenderer
{
  SpriteRendererData *_data = nullptr;

  Renderer_impl &_r;
  State &_state;
  Textures &_textures;
  Capabilities &_capabilities;

  GLuint _program;
  bool _linked = false;

  GLuint _vertexBuffer;
  GLuint _elementBuffer;

  math::Vector3 _spritePosition;
  math::Quaternion _spriteRotation;
  math::Vector3 _spriteScale;

  ImageTexture::Ptr _texture;

  void init();

public:
  SpriteRenderer(Renderer_impl &r, State &state, Textures &textures, Capabilities &capabilities)
     : _r(r), _state(state), _textures(textures), _capabilities(capabilities) {}

  ~SpriteRenderer();

  void render(std::vector<Sprite::Ptr> &sprites, Scene::Ptr scene, Camera::Ptr camera);
};

}
}

#endif //THREEPP_SPRITERENDERER_H
