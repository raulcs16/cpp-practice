//use case: unbind for base class, and avoid redudant nested subclasses,
//make both abstractions and implementations extensible by subclassing

#include <iostream>
//Implementor
class Renderer {
public:
    virtual void renderEntity(const std::string &name) = 0;
    virtual ~Renderer() {}
};
//concrete Implementors
class OpenGLRenderer : public Renderer {
public:
    void renderEntity(const std::string &name) override;
};
class DirectXRenderer : public Renderer {
public:
    void renderEntity(const std::string &name) override;
};

//Abstraction
class RenderClient {
protected:
    Renderer *renderer;

public:
    RenderClient(Renderer *renderer);
    virtual void render() = 0;
    virtual ~RenderClient() {}
};

class UIOverlay : public RenderClient {
public:
    UIOverlay(Renderer *r) : RenderClient(r) {}
    void render() override {}
};

class SceneObj : public RenderClient {
public:
    SceneObj(RenderClient *r, const std::string &mesh) : RenderClient(r) {}
    void render() override {}
};