#include "Sketch.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Sketch::setup(bool renew)
{
    /*
     * UPON DEPLOYMENT ON MSW: PLACE THE FILE IN A resources FOLDER, ALONGSIDE THE EXECUTABLE
     * MORE DETAILS IN chronotext/InputSource.h
     */
    texture = TextureHelper::loadTexture("Louis_XIV_of_France.jpg"); // BY Hyacinthe Rigaud, 1701 @MuseeLouvre
    
    position = getWindowSize() / 2;
    
    // ---

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
}

void Sketch::shutdown()
{
    delete texture;
}

void Sketch::resize(ResizeEvent event)
{
    gl::setMatricesWindow(event.getSize(), true);
}

void Sketch::draw()
{
    gl::clear(ColorA::black(), false);
    glLoadIdentity();
    
    // ---

    gl::color(ColorA::white());
    gl::translate(position);

    TextureHelper::beginTexture(texture);
    TextureHelper::drawTextureFromCenter(texture);
    TextureHelper::endTexture();
}

void Sketch::addTouch(int index, float x, float y)
{
    dragOrigin = Vec2f(x, y) - position;
}

void Sketch::updateTouch(int index, float x, float y)
{
    position = Vec2f(x, y) - dragOrigin;
}
