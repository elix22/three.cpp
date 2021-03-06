//
// Created by byter on 11/4/17.
//

#ifndef THREEPP_MESHSTANDARDMATERIAL_H
#define THREEPP_MESHSTANDARDMATERIAL_H

#include "Material.h"
#include <threepp/core/Color.h>

namespace three {

/**
 * @author WestLangley / http://github.com/WestLangley
 *
 * parameters = {
 *  color: <hex>,
 *  roughness: <float>,
 *  metalness: <float>,
 *  opacity: <float>,
 *
 *  map: new THREE.Texture( <Image> ),
 *
 *  lightMap: new THREE.Texture( <Image> ),
 *  lightMapIntensity: <float>
 *
 *  aoMap: new THREE.Texture( <Image> ),
 *  aoMapIntensity: <float>
 *
 *  emissive: <hex>,
 *  emissiveIntensity: <float>
 *  emissiveMap: new THREE.Texture( <Image> ),
 *
 *  bumpMap: new THREE.Texture( <Image> ),
 *  bumpScale: <float>,
 *
 *  normalMap: new THREE.Texture( <Image> ),
 *  normalScale: <Vector2>,
 *
 *  displacementMap: new THREE.Texture( <Image> ),
 *  displacementScale: <float>,
 *  displacementBias: <float>,
 *
 *  roughnessMap: new THREE.Texture( <Image> ),
 *
 *  metalnessMap: new THREE.Texture( <Image> ),
 *
 *  alphaMap: new THREE.Texture( <Image> ),
 *
 *  envMap: new THREE.CubeTexture( [posx, negx, posy, negy, posz, negz] ),
 *  envMapIntensity: <float>
 *
 *  refractionRatio: <float>,
 *
 *  wireframe: <boolean>,
 *  wireframeLinewidth: <float>,
 *
 *  skinning: <bool>,
 *  morphTargets: <bool>,
 *  morphNormals: <bool>
 * }
 */

struct DLX MeshStandardMaterial : public MaterialT<
   material::Diffuse,
   material::LightMap,
   material::AoMap,
   material::Emissive,
   material::BumpMap,
   material::NormalMap,
   material::DisplacementMap,
   material::AlphaMap,
   material::EnvMap,
   material::RoughnessMap,
   material::MetalnessMap>
{
  std::unordered_map<std::string, std::string> defines {{ "STANDARD", "" }};

protected:
  MeshStandardMaterial(const material::Info &info, const material::Typer &typer)
     : MaterialT(info, typer)
  {
    this->typer.allow<MeshStandardMaterial>();
  }

  MeshStandardMaterial() : MaterialT(material::InfoT<MeshStandardMaterial>(), material::Typer(this)) {}

  MeshStandardMaterial(const MeshStandardMaterial &material)
     : MaterialT(material, material::InfoT<MeshStandardMaterial>(), material::Typer(this)) {}

  MeshStandardMaterial(const MeshStandardMaterial &material, const material::Info &info, const material::Typer &typer)
     : MaterialT(material, info, typer) {
    this->typer.allow<MeshStandardMaterial>();
  }

public:
  using Ptr = std::shared_ptr<MeshStandardMaterial>;
  static Ptr make() {
    return Ptr(new MeshStandardMaterial());
  }

  MeshStandardMaterial *cloned() const override {
    return new MeshStandardMaterial(*this);
  }

  bool transparent() const override {return opacity < 1.0f;}
};

}

#endif //THREEPP_MESHSTANDARDMATERIAL_H
