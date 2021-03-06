#pragma once

#include "chronotext/utils/TexturedTriangleStrip.h"
#include "chronotext/texture/Texture.h"

typedef boost::shared_ptr<class FlashShape> FlashShapeRef;

class FlashShape
{
public:
    std::vector<ci::Vec2f> vertices;
    std::vector<uint16_t> indices;
    
    TexturedTriangleStrip strip;
    
    void appendVertices(const ci::Vec2f *vertices, size_t num);
    void appendIndices(uint32_t *indices, size_t num);
    
    void draw(Texture *strokeTexture);
};
