#include <iostream>
#include <memory>
#include <string>

//subject
class GameAsset {
public:
    virtual void display() = 0;
    virtual void ~GameAsset() = default;
};

//real subject
class MeshModel : public GameAsset {
public:
    MeshModel(std::string file_path);
    void display() override;

private:
    void loadMesh();
    //data
};

//proxy
class Model : public GameAsset {
public:
    Model(std::string file_path);
    void display() {
        if (!mesh_model) {
            mesh_model = std::make_unique<MeshModel>(filename);
        }
        mesh_model->display();
    }

private:
    std::string filename;
    std::unique_ptr<MeshModel> mesh_model;
}
