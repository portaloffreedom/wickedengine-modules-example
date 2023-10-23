module;

//#include <string>
//#include <sstream>
//#include <fstream>
//#include <thread>
//#include <WickedEngine/WickedEngine.h>
import wicked_engine;

export module hiraeth_prelude;



export class WickedEngineModuleExampleRenderer : public wi::RenderPath3D
{
    wi::ecs::Entity asteroid = wi::ecs::INVALID_ENTITY;
    wi::ecs::Entity player_spaceship = wi::ecs::INVALID_ENTITY;
    wi::gui::Label label;

public:
    void Load() override
    {
        setSSREnabled(false);
        setReflectionsEnabled(true);
        setFXAAEnabled(false);

        label.Create("Label1");
        label.SetText("Hiraeth Prelude");
        label.font.params.h_align = wi::font::WIFALIGN_CENTER;
        label.SetSize(wi::XMFLOAT2(240,20));
        GetGUI().AddWidget(&label);

        static wi::audio::Sound sound;
        static wi::audio::SoundInstance soundinstance;
    }

    void Start() override
    {
        // Reset all state that tests might have modified:
        wi::eventhandler::SetVSync(true);
        wi::renderer::SetToDrawGridHelper(false);
        wi::renderer::SetTemporalAAEnabled(false);
        wi::scene::GetScene().weather = wi::scene::WeatherComponent();

        // Reset camera position:
        wi::scene::TransformComponent transform;
        transform.Translate(wi::XMFLOAT3(0, 2.f, -4.5f));
        transform.UpdateTransform();
        wi::scene::GetCamera().TransformCamera(transform);

        float screenW = GetLogicalWidth();
        float screenH = GetLogicalHeight();

        wi::ecs::Entity asteroids = wi::scene::LoadModel("../Assets/AsteroidTestScene.wiscene");
        wi::ecs::Entity spaceship = wi::scene::LoadModel("../Assets/spaceship2.wiscene");
        //wi::scene::LoadModel("/usr/lib/WickedEngine/Content/models/teapot.wiscene");
        asteroid = wi::scene::GetScene().Entity_FindByName("Asteroid_no_3");
        player_spaceship = wi::scene::GetScene().Entity_FindByName("spaceship");

        RenderPath3D::Load();

        //wi::renderer::SetWireRender(true);
    }

    void Update(float dt) override
    {
        wi::scene::TransformComponent *asteroid_transform = wi::scene::GetScene().transforms.GetComponent(asteroid);
        asteroid_transform->Rotate(wi::XMVECTOR {dt * 5.0f, 0, 0});

        wi::scene::TransformComponent *player_transform = wi::scene::GetScene().transforms.GetComponent(player_spaceship);
        player_transform->Rotate(wi::XMVectorSet(0,dt,0,1));

        RenderPath3D::Update(dt);
    }

};

export class WickedEngineModuleExample : public wi::Application
{
    WickedEngineModuleExampleRenderer renderer;
public:
    void Initialize() override
    {
        wi::renderer::SetShaderSourcePath(WickedEngine_SHADER_DIR);
        wi::Application::Initialize();

        infoDisplay.active = true;
        infoDisplay.watermark = true;
        infoDisplay.fpsinfo = true;
        infoDisplay.resolution = true;
        infoDisplay.heap_allocation_counter = true;


        renderer.init(canvas);
        renderer.Load();

        ActivatePath(&renderer);
    }
};

